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

#include <algorithm>
#include <array>
#include <type_traits>
#include <wtf/EnumTraits.h>
#include <wtf/text/ASCIILiteral.h>

namespace IPC {

enum class ReceiverName : uint8_t {
    AuthenticationManager = 1
    , AuxiliaryProcess = 2
    , DigitalCredentialsCoordinator = 3
    , DownloadProxy = 4
    , DrawingArea = 5
    , DrawingAreaProxy = 6
    , EventDispatcher = 7
    , GPUConnectionToWebProcess = 8
    , GPUProcess = 9
    , GPUProcessConnection = 10
    , GPUProcessProxy = 11
    , IPCConnectionTester = 12
    , IPCStreamTester = 13
    , IPCStreamTesterProxy = 14
    , IPCTester = 15
    , IPCTesterReceiver = 16
    , LibWebRTCCodecs = 17
    , LibWebRTCCodecsProxy = 18
    , LibWebRTCNetwork = 19
    , MediaPlayerPrivateRemote = 20
    , MediaSourcePrivateRemoteMessageReceiver = 21
    , ModelConnectionToWebProcess = 22
    , ModelProcess = 23
    , ModelProcessConnection = 24
    , ModelProcessModelPlayer = 25
    , ModelProcessModelPlayerManagerProxy = 26
    , ModelProcessProxy = 27
    , NetworkBroadcastChannelRegistry = 28
    , NetworkConnectionToWebProcess = 29
    , NetworkContentRuleListManager = 30
    , NetworkMDNSRegister = 31
    , NetworkProcess = 32
    , NetworkProcessConnection = 33
    , NetworkProcessProxy = 34
    , NetworkRTCMonitor = 35
    , NetworkRTCProvider = 36
    , NetworkResourceLoader = 37
    , NetworkSocketChannel = 38
    , NetworkStorageManager = 39
    , NetworkTransportSession = 40
    , NotificationManagerMessageHandler = 41
    , PlatformXRSystem = 42
    , PlatformXRSystemProxy = 43
    , PushClientConnection = 44
    , RTCDataChannelRemoteManager = 45
    , RTCDataChannelRemoteManagerProxy = 46
    , RemoteAdapter = 47
    , RemoteAudioDestinationManager = 48
    , RemoteAudioHardwareListener = 49
    , RemoteAudioMediaStreamTrackRendererInternalUnitManager = 50
    , RemoteAudioSession = 51
    , RemoteAudioSessionProxy = 52
    , RemoteAudioSourceProviderManager = 53
    , RemoteBarcodeDetector = 54
    , RemoteBindGroup = 55
    , RemoteBindGroupLayout = 56
    , RemoteBuffer = 57
    , RemoteCDMFactoryProxy = 58
    , RemoteCDMInstance = 59
    , RemoteCDMInstanceProxy = 60
    , RemoteCDMInstanceSession = 61
    , RemoteCDMInstanceSessionProxy = 62
    , RemoteCDMProxy = 63
    , RemoteCommandBuffer = 64
    , RemoteCommandEncoder = 65
    , RemoteCompositorIntegration = 66
    , RemoteComputePassEncoder = 67
    , RemoteComputePipeline = 68
    , RemoteDevice = 69
    , RemoteDisplayListRecorder = 70
    , RemoteExternalTexture = 71
    , RemoteFaceDetector = 72
    , RemoteGPU = 73
    , RemoteGPUProxy = 74
    , RemoteGraphicsContextGL = 75
    , RemoteGraphicsContextGLProxy = 76
    , RemoteImageBuffer = 77
    , RemoteImageBufferProxy = 78
    , RemoteImageBufferSet = 79
    , RemoteImageBufferSetProxy = 80
    , RemoteLegacyCDMFactoryProxy = 81
    , RemoteLegacyCDMProxy = 82
    , RemoteLegacyCDMSession = 83
    , RemoteLegacyCDMSessionProxy = 84
    , RemoteMediaEngineConfigurationFactoryProxy = 85
    , RemoteMediaPlayerManagerProxy = 86
    , RemoteMediaPlayerProxy = 87
    , RemoteMediaResourceManager = 88
    , RemoteMediaSessionCoordinator = 89
    , RemoteMediaSessionCoordinatorProxy = 90
    , RemoteMediaSourceProxy = 91
    , RemotePipelineLayout = 92
    , RemotePresentationContext = 93
    , RemoteQuerySet = 94
    , RemoteQueue = 95
    , RemoteRemoteCommandListener = 96
    , RemoteRemoteCommandListenerProxy = 97
    , RemoteRenderBundle = 98
    , RemoteRenderBundleEncoder = 99
    , RemoteRenderPassEncoder = 100
    , RemoteRenderPipeline = 101
    , RemoteRenderingBackend = 102
    , RemoteRenderingBackendProxy = 103
    , RemoteSampleBufferDisplayLayer = 104
    , RemoteSampleBufferDisplayLayerManager = 105
    , RemoteSampler = 106
    , RemoteShaderModule = 107
    , RemoteSharedResourceCache = 108
    , RemoteSourceBufferProxy = 109
    , RemoteTextDetector = 110
    , RemoteTexture = 111
    , RemoteTextureView = 112
    , RemoteVideoFrameObjectHeap = 113
    , RemoteVideoFrameObjectHeapProxyProcessor = 114
    , RemoteWCLayerTreeHost = 115
    , RemoteWebInspectorUI = 116
    , RemoteWebInspectorUIProxy = 117
    , RemoteWebLockRegistry = 118
    , RemoteXRBinding = 119
    , RemoteXRProjectionLayer = 120
    , RemoteXRSubImage = 121
    , RemoteXRView = 122
    , SampleBufferDisplayLayer = 123
    , ServiceWorkerDownloadTask = 124
    , ServiceWorkerFetchTask = 125
    , SourceBufferPrivateRemoteMessageReceiver = 126
    , SpeechRecognitionRealtimeMediaSourceManager = 127
    , SpeechRecognitionRemoteRealtimeMediaSourceManager = 128
    , SpeechRecognitionServer = 129
    , StorageAreaMap = 130
    , VisitedLinkStore = 131
    , VisitedLinkTableController = 132
    , WebAutomationSession = 133
    , WebAutomationSessionProxy = 134
    , WebBroadcastChannelRegistry = 135
    , WebCookieManager = 136
    , WebExtensionContext = 137
    , WebExtensionContextProxy = 138
    , WebExtensionController = 139
    , WebExtensionControllerProxy = 140
    , WebFileSystemStorageConnection = 141
    , WebFrame = 142
    , WebFrameProxy = 143
    , WebFullScreenManager = 144
    , WebFullScreenManagerProxy = 145
    , WebGeolocationManager = 146
    , WebGeolocationManagerProxy = 147
    , WebIDBConnectionToServer = 148
    , WebInspector = 149
    , WebInspectorBackendProxy = 150
    , WebInspectorInterruptDispatcher = 151
    , WebInspectorUI = 152
    , WebInspectorUIProxy = 153
    , WebLockRegistryProxy = 154
    , WebNotificationManager = 155
    , WebPage = 156
    , WebPageProxy = 157
    , WebPageTesting = 158
    , WebPasteboardProxy = 159
    , WebPermissionController = 160
    , WebPermissionControllerProxy = 161
    , WebProcess = 162
    , WebProcessPool = 163
    , WebProcessProxy = 164
    , WebRTCMonitor = 165
    , WebRTCResolver = 166
    , WebResourceLoader = 167
    , WebSWClientConnection = 168
    , WebSWContextManagerConnection = 169
    , WebSWServerConnection = 170
    , WebSWServerToContextConnection = 171
    , WebScreenOrientationManager = 172
    , WebScreenOrientationManagerProxy = 173
    , WebSharedWorkerContextManagerConnection = 174
    , WebSharedWorkerObjectConnection = 175
    , WebSharedWorkerServerConnection = 176
    , WebSharedWorkerServerToContextConnection = 177
    , WebSocketChannel = 178
    , WebSpeechRecognitionConnection = 179
    , WebTransportSession = 180
    , WebUserContentController = 181
    , WebUserContentControllerProxy = 182
    , IPC = 183
    , AsyncReply = 184
    , Invalid = 185
};

enum class MessageName : uint16_t {
    AuthenticationManager_CompleteAuthenticationChallenge,
#if OS(LINUX)
    AuxiliaryProcess_DidReceiveMemoryPressureEvent,
#endif
    AuxiliaryProcess_MainThreadPing,
#if ENABLE(CFPREFS_DIRECT_MODE)
    AuxiliaryProcess_PreferenceDidUpdate,
#endif
    AuxiliaryProcess_SetProcessSuppressionEnabled,
    AuxiliaryProcess_ShutDown,
    DigitalCredentialsCoordinator_ProvideRawDigitalCredentialRequests,
    DownloadProxy_DecideDestinationWithSuggestedFilename,
    DownloadProxy_DidCreateDestination,
    DownloadProxy_DidFail,
    DownloadProxy_DidFinish,
    DownloadProxy_DidReceiveAuthenticationChallenge,
    DownloadProxy_DidReceiveData,
#if HAVE(MODERN_DOWNLOADPROGRESS)
    DownloadProxy_DidReceiveFinalURL,
    DownloadProxy_DidReceivePlaceholderURL,
#endif
    DownloadProxy_DidStart,
#if HAVE(MODERN_DOWNLOADPROGRESS)
    DownloadProxy_DidStartUpdatingProgress,
#endif
    DownloadProxy_WillSendRequest,
    DrawingAreaProxy_DidFirstLayerFlush,
    DrawingAreaProxy_DispatchPresentationCallbacksAfterFlushingLayers,
    DrawingAreaProxy_EnterAcceleratedCompositingMode,
#if USE(COORDINATED_GRAPHICS) || USE(TEXTURE_MAPPER)
    DrawingAreaProxy_ExitAcceleratedCompositingMode,
    DrawingAreaProxy_Update,
#endif
    DrawingAreaProxy_UpdateAcceleratedCompositingMode,
#if PLATFORM(COCOA)
    DrawingArea_AcceleratedAnimationDidEnd,
    DrawingArea_AcceleratedAnimationDidStart,
#endif
#if PLATFORM(COCOA) || PLATFORM(GTK)
    DrawingArea_AdjustTransientZoom,
    DrawingArea_CommitTransientZoom,
#endif
#if USE(COORDINATED_GRAPHICS) || USE(TEXTURE_MAPPER)
    DrawingArea_DidDiscardBackingStore,
#endif
#if PLATFORM(COCOA) || PLATFORM(GTK) || PLATFORM(WPE)
    DrawingArea_DispatchAfterEnsuringDrawing,
#endif
    DrawingArea_DisplayDidRefresh,
#if USE(COORDINATED_GRAPHICS) || USE(TEXTURE_MAPPER)
    DrawingArea_ForceUpdate,
#endif
#if PLATFORM(COCOA)
    DrawingArea_SetColorSpace,
#endif
    DrawingArea_SetDeviceScaleFactor,
#if PLATFORM(COCOA)
    DrawingArea_SetViewExposedRect,
#endif
#if USE(COORDINATED_GRAPHICS) || USE(TEXTURE_MAPPER) || PLATFORM(COCOA)
    DrawingArea_UpdateGeometry,
#endif
#if USE(GRAPHICS_LAYER_WC)
    DrawingArea_UpdateGeometryWC,
#endif
#if HAVE(DISPLAY_LINK)
    EventDispatcher_DisplayDidRefresh,
#endif
#if ENABLE(MAC_GESTURE_EVENTS)
    EventDispatcher_GestureEvent,
#endif
    EventDispatcher_PageScreenDidChange,
#if ENABLE(MOMENTUM_EVENT_DISPATCHER)
    EventDispatcher_SetScrollingAccelerationCurve,
#endif
#if ENABLE(IOS_TOUCH_EVENTS)
    EventDispatcher_TouchEvent,
#endif
    EventDispatcher_WheelEvent,
    GPUConnectionToWebProcess_ClearNowPlayingInfo,
    GPUConnectionToWebProcess_ConfigureLoggingChannel,
    GPUConnectionToWebProcess_CreateAudioHardwareListener,
    GPUConnectionToWebProcess_CreateGPU,
#if ENABLE(WEBGL)
    GPUConnectionToWebProcess_CreateGraphicsContextGL,
#endif
    GPUConnectionToWebProcess_CreateRemoteCommandListener,
    GPUConnectionToWebProcess_CreateRenderingBackend,
#if HAVE(VISIBILITY_PROPAGATION_VIEW)
    GPUConnectionToWebProcess_CreateVisibilityPropagationContextForPage,
#endif
#if USE(GRAPHICS_LAYER_WC)
    GPUConnectionToWebProcess_CreateWCLayerTreeHost,
#endif
#if HAVE(VISIBILITY_PROPAGATION_VIEW)
    GPUConnectionToWebProcess_DestroyVisibilityPropagationContextForPage,
#endif
#if ENABLE(MEDIA_SOURCE)
    GPUConnectionToWebProcess_EnableMockMediaSource,
#endif
#if PLATFORM(IOS_FAMILY)
    GPUConnectionToWebProcess_EnsureMediaSessionHelper,
#endif
    GPUConnectionToWebProcess_ReleaseAudioHardwareListener,
    GPUConnectionToWebProcess_ReleaseGPU,
#if ENABLE(WEBGL)
    GPUConnectionToWebProcess_ReleaseGraphicsContextGL,
#endif
    GPUConnectionToWebProcess_ReleaseRemoteCommandListener,
    GPUConnectionToWebProcess_ReleaseRenderingBackend,
#if USE(GRAPHICS_LAYER_WC)
    GPUConnectionToWebProcess_ReleaseWCLayerTreeHost,
#endif
#if ENABLE(EXTENSION_CAPABILITIES)
    GPUConnectionToWebProcess_SetMediaEnvironment,
#endif
    GPUConnectionToWebProcess_SetMediaOverridesForTesting,
    GPUConnectionToWebProcess_SetNowPlayingInfo,
#if PLATFORM(COCOA) && ENABLE(MEDIA_STREAM)
    GPUConnectionToWebProcess_UpdateSampleBufferDisplayLayerBoundsAndPosition,
#endif
#if ENABLE(ROUTING_ARBITRATION)
    GPUProcessConnection_BeginRoutingArbitrationWithCategory,
#endif
    GPUProcessConnection_DidInitialize,
    GPUProcessConnection_DidReceiveRemoteCommand,
#if ENABLE(ROUTING_ARBITRATION)
    GPUProcessConnection_EndRoutingArbitration,
#endif
#if ENABLE(MEDIA_STREAM) && PLATFORM(COCOA)
    GPUProcessConnection_ResetAudioMediaStreamTrackRendererInternalUnit,
#endif
#if HAVE(VISIBILITY_PROPAGATION_VIEW)
    GPUProcessProxy_DidCreateContextForVisibilityPropagation,
#endif
#if PLATFORM(COCOA)
    GPUProcessProxy_DidDrawRemoteToPDF,
#endif
#if ENABLE(MEDIA_STREAM)
    GPUProcessProxy_MicrophoneMuteStatusChanged,
#endif
    GPUProcessProxy_ProcessIsReadyToExit,
#if ENABLE(AV1)
    GPUProcessProxy_SetHasAV1HardwareDecoder,
#endif
#if ENABLE(VP9)
    GPUProcessProxy_SetHasVP9HardwareDecoder,
#endif
#if ENABLE(MEDIA_STREAM)
    GPUProcessProxy_StartMonitoringCaptureDeviceRotation,
#endif
#if (ENABLE(MEDIA_STREAM) && PLATFORM(IOS_FAMILY))
    GPUProcessProxy_StatusBarWasTapped,
#endif
#if ENABLE(MEDIA_STREAM)
    GPUProcessProxy_StopMonitoringCaptureDeviceRotation,
#endif
    GPUProcessProxy_TerminateWebProcess,
#if ENABLE(MEDIA_STREAM)
    GPUProcessProxy_VoiceActivityDetected,
    GPUProcess_AddMockMediaDevice,
#endif
    GPUProcess_AddSession,
#if HAVE(SCREEN_CAPTURE_KIT)
    GPUProcess_CancelGetDisplayMediaPrompt,
#endif
#if ENABLE(MEDIA_STREAM)
    GPUProcess_ClearMockMediaDevices,
#endif
#if HAVE(AUDIO_COMPONENT_SERVER_REGISTRATIONS)
    GPUProcess_ConsumeAudioComponentRegistrations,
#endif
    GPUProcess_CreateGPUConnectionToWebProcess,
#if ((PLATFORM(VISION) && ENABLE(MODEL_PROCESS)) && HAVE(TASK_IDENTITY_TOKEN))
    GPUProcess_CreateMemoryAttributionIDForTask,
#endif
#if ENABLE(MEDIA_STREAM)
    GPUProcess_EnableMicrophoneMuteStatusAPI,
#endif
#if HAVE(POWERLOG_TASK_MODE_QUERY)
    GPUProcess_EnablePowerLogging,
#endif
    GPUProcess_InitializeGPUProcess,
#if PLATFORM(MAC)
    GPUProcess_OpenDirectoryCacheInvalidated,
#endif
#if PLATFORM(COCOA)
    GPUProcess_PostWillTakeSnapshotNotification,
#endif
    GPUProcess_PrepareToSuspend,
    GPUProcess_ProcessDidResume,
#if HAVE(SCREEN_CAPTURE_KIT)
    GPUProcess_PromptForGetDisplayMedia,
#endif
#if PLATFORM(COCOA)
    GPUProcess_RegisterFonts,
#endif
#if ENABLE(MEDIA_STREAM)
    GPUProcess_RemoveMockMediaDevice,
#endif
    GPUProcess_RemoveSession,
#if ENABLE(VIDEO)
    GPUProcess_RequestBitmapImageForCurrentTime,
#endif
#if PLATFORM(VISION) && ENABLE(MODEL_PROCESS)
    GPUProcess_RequestSharedSimulationConnection,
#endif
#if ENABLE(MEDIA_STREAM)
    GPUProcess_ResetMockMediaDevices,
#endif
#if USE(EXTENSIONKIT)
    GPUProcess_ResolveBookmarkDataForCacheDirectory,
#endif
#if ENABLE(MEDIA_STREAM)
    GPUProcess_RotationAngleForCaptureDeviceChanged,
    GPUProcess_SetMockCaptureDevicesEnabled,
    GPUProcess_SetMockCaptureDevicesInterrupted,
    GPUProcess_SetMockMediaDeviceIsEphemeral,
    GPUProcess_SetOrientationForMediaCapture,
#endif
#if HAVE(AUDIT_TOKEN)
    GPUProcess_SetPresentingApplicationAuditToken,
#endif
#if PLATFORM(MAC)
    GPUProcess_SetScreenProperties,
#endif
#if ENABLE(MEDIA_STREAM)
    GPUProcess_SetShouldListenToVoiceActivity,
#endif
    GPUProcess_SharedPreferencesForWebProcessDidChange,
#if ENABLE(MEDIA_STREAM)
    GPUProcess_TriggerMockCaptureConfigurationChange,
#endif
#if ((PLATFORM(VISION) && ENABLE(MODEL_PROCESS)) && HAVE(TASK_IDENTITY_TOKEN))
    GPUProcess_UnregisterMemoryAttributionID,
#endif
#if ENABLE(MEDIA_STREAM)
    GPUProcess_UpdateCaptureAccess,
    GPUProcess_UpdateCaptureOrigin,
#endif
    GPUProcess_UpdateGPUProcessPreferences,
    GPUProcess_UpdateSandboxAccess,
    GPUProcess_UserPreferredLanguagesChanged,
    GPUProcess_WebProcessConnectionCountForTesting,
#if ENABLE(WEBXR)
    GPUProcess_WebXRPromptAccepted,
#endif
    IPCConnectionTester_AsyncMessage,
    IPCStreamTesterProxy_WasCreated,
    IPCStreamTester_AsyncPing,
    IPCStreamTester_EmptyMessage,
    IPCTesterReceiver_AsyncMessage,
    IPCTester_AsyncOptionalExceptionData,
    IPCTester_AsyncPing,
    IPCTester_CreateConnectionTester,
    IPCTester_CreateConnectionTesterAndSendAsyncMessages,
    IPCTester_CreateStreamTester,
    IPCTester_SendAsyncMessageToReceiver,
    IPCTester_SendSameSemaphoreBack,
    IPCTester_SendSemaphoreBackAndSignalProtocol,
    IPCTester_StartMessageTesting,
    LibWebRTCCodecsProxy_CreateDecoder,
    LibWebRTCCodecsProxy_CreateEncoder,
    LibWebRTCCodecsProxy_DecodeFrame,
    LibWebRTCCodecsProxy_EncodeFrame,
    LibWebRTCCodecsProxy_FlushDecoder,
    LibWebRTCCodecsProxy_FlushEncoder,
    LibWebRTCCodecsProxy_InitializeEncoder,
    LibWebRTCCodecsProxy_ReleaseDecoder,
    LibWebRTCCodecsProxy_ReleaseEncoder,
    LibWebRTCCodecsProxy_SetDecoderFormatDescription,
    LibWebRTCCodecsProxy_SetEncodeRates,
    LibWebRTCCodecsProxy_SetFrameSize,
    LibWebRTCCodecsProxy_SetRTCLoggingLevel,
    LibWebRTCCodecsProxy_SetSharedVideoFrameMemory,
    LibWebRTCCodecsProxy_SetSharedVideoFrameSemaphore,
    LibWebRTCCodecs_CompletedDecoding,
    LibWebRTCCodecs_CompletedDecodingCV,
    LibWebRTCCodecs_CompletedEncoding,
    LibWebRTCCodecs_FailedDecoding,
    LibWebRTCCodecs_SetEncodingConfiguration,
    LibWebRTCNetwork_SignalAddressReady,
    LibWebRTCNetwork_SignalClose,
    LibWebRTCNetwork_SignalConnect,
    LibWebRTCNetwork_SignalReadPacket,
    LibWebRTCNetwork_SignalSentPacket,
    LibWebRTCNetwork_SignalUsedInterface,
    MediaPlayerPrivateRemote_ActiveSourceBuffersChanged,
    MediaPlayerPrivateRemote_AddDataCue,
#if ENABLE(DATACUE_VALUE)
    MediaPlayerPrivateRemote_AddDataCueWithType,
#endif
    MediaPlayerPrivateRemote_AddGenericCue,
    MediaPlayerPrivateRemote_AddRemoteAudioTrack,
    MediaPlayerPrivateRemote_AddRemoteTextTrack,
    MediaPlayerPrivateRemote_AddRemoteVideoTrack,
    MediaPlayerPrivateRemote_CharacteristicChanged,
    MediaPlayerPrivateRemote_CommitAllTransactions,
#if ENABLE(WIRELESS_PLAYBACK_TARGET)
    MediaPlayerPrivateRemote_CurrentPlaybackTargetIsWirelessChanged,
#endif
    MediaPlayerPrivateRemote_CurrentTimeChanged,
    MediaPlayerPrivateRemote_DurationChanged,
    MediaPlayerPrivateRemote_EngineFailedToLoad,
    MediaPlayerPrivateRemote_FirstVideoFrameAvailable,
#if PLATFORM(IOS_FAMILY)
    MediaPlayerPrivateRemote_GetRawCookies,
#endif
#if ENABLE(ENCRYPTED_MEDIA)
    MediaPlayerPrivateRemote_InitializationDataEncountered,
#endif
#if PLATFORM(COCOA)
    MediaPlayerPrivateRemote_LayerHostingContextChanged,
#endif
#if ENABLE(LEGACY_ENCRYPTED_MEDIA)
    MediaPlayerPrivateRemote_MediaPlayerKeyNeeded,
#endif
    MediaPlayerPrivateRemote_MuteChanged,
    MediaPlayerPrivateRemote_NetworkStateChanged,
    MediaPlayerPrivateRemote_ParseWebVTTCueData,
    MediaPlayerPrivateRemote_ParseWebVTTCueDataStruct,
    MediaPlayerPrivateRemote_ParseWebVTTFileHeader,
    MediaPlayerPrivateRemote_PlaybackStateChanged,
#if PLATFORM(COCOA)
    MediaPlayerPrivateRemote_PushVideoFrameMetadata,
#endif
    MediaPlayerPrivateRemote_RateChanged,
    MediaPlayerPrivateRemote_ReadyStateChanged,
    MediaPlayerPrivateRemote_RemoteAudioTrackConfigurationChanged,
    MediaPlayerPrivateRemote_RemoteTextTrackConfigurationChanged,
    MediaPlayerPrivateRemote_RemoteVideoTrackConfigurationChanged,
#if ENABLE(DATACUE_VALUE)
    MediaPlayerPrivateRemote_RemoveDataCue,
#endif
    MediaPlayerPrivateRemote_RemoveGenericCue,
    MediaPlayerPrivateRemote_RemoveRemoteAudioTrack,
    MediaPlayerPrivateRemote_RemoveRemoteTextTrack,
    MediaPlayerPrivateRemote_RemoveRemoteVideoTrack,
    MediaPlayerPrivateRemote_RemoveResource,
    MediaPlayerPrivateRemote_RenderingModeChanged,
    MediaPlayerPrivateRemote_ReportGPUMemoryFootprint,
    MediaPlayerPrivateRemote_RequestResource,
    MediaPlayerPrivateRemote_ResourceNotSupported,
    MediaPlayerPrivateRemote_Seeked,
    MediaPlayerPrivateRemote_SendH2Ping,
    MediaPlayerPrivateRemote_SendInternalMessage,
    MediaPlayerPrivateRemote_SizeChanged,
    MediaPlayerPrivateRemote_TimeChanged,
    MediaPlayerPrivateRemote_UpdateCachedState,
#if ENABLE(DATACUE_VALUE)
    MediaPlayerPrivateRemote_UpdateDataCue,
#endif
    MediaPlayerPrivateRemote_UpdateGenericCue,
    MediaPlayerPrivateRemote_UpdatePlaybackQualityMetrics,
    MediaPlayerPrivateRemote_VolumeChanged,
#if ENABLE(ENCRYPTED_MEDIA)
    MediaPlayerPrivateRemote_WaitingForKeyChanged,
#endif
    MediaSourcePrivateRemoteMessageReceiver_ProxySeekToTime,
    MediaSourcePrivateRemoteMessageReceiver_ProxyWaitForTarget,
    ModelConnectionToWebProcess_ConfigureLoggingChannel,
#if HAVE(VISIBILITY_PROPAGATION_VIEW)
    ModelConnectionToWebProcess_CreateVisibilityPropagationContextForPage,
    ModelConnectionToWebProcess_DestroyVisibilityPropagationContextForPage,
#endif
    ModelProcessConnection_DidInitialize,
    ModelProcessConnection_DidUnloadModelPlayer,
    ModelProcessModelPlayerManagerProxy_CreateModelPlayer,
    ModelProcessModelPlayerManagerProxy_DeleteModelPlayer,
    ModelProcessModelPlayer_DidCreateLayer,
    ModelProcessModelPlayer_DidFailLoading,
    ModelProcessModelPlayer_DidFinishEnvironmentMapLoading,
    ModelProcessModelPlayer_DidFinishLoading,
    ModelProcessModelPlayer_DidUnload,
    ModelProcessModelPlayer_DidUpdateAnimationPlaybackState,
    ModelProcessModelPlayer_DidUpdateEntityTransform,
#if HAVE(VISIBILITY_PROPAGATION_VIEW)
    ModelProcessProxy_DidCreateContextForVisibilityPropagation,
#endif
    ModelProcessProxy_ProcessIsReadyToExit,
#if PLATFORM(VISION) && ENABLE(GPU_PROCESS)
    ModelProcessProxy_RequestSharedSimulationConnection,
#endif
    ModelProcessProxy_TerminateWebProcess,
    ModelProcess_AddSession,
    ModelProcess_CreateModelConnectionToWebProcess,
    ModelProcess_InitializeModelProcess,
    ModelProcess_ModelPlayerCountForTesting,
    ModelProcess_PrepareToSuspend,
    ModelProcess_ProcessDidResume,
    ModelProcess_RemoveSession,
    ModelProcess_SharedPreferencesForWebProcessDidChange,
    ModelProcess_WebProcessConnectionCountForTesting,
    NetworkBroadcastChannelRegistry_PostMessage,
    NetworkBroadcastChannelRegistry_RegisterChannel,
    NetworkBroadcastChannelRegistry_UnregisterChannel,
    NetworkConnectionToWebProcess_AddOriginAccessAllowListEntry,
    NetworkConnectionToWebProcess_BrowsingContextRemoved,
#if (PLATFORM(MAC) && ENABLE(LAUNCHSERVICES_SANDBOX_EXTENSION_BLOCKING))
    NetworkConnectionToWebProcess_CheckInWebProcess,
#endif
    NetworkConnectionToWebProcess_ClearFrameLoadRecordsForStorageAccess,
    NetworkConnectionToWebProcess_ClearPageSpecificData,
    NetworkConnectionToWebProcess_CloseSWContextConnection,
    NetworkConnectionToWebProcess_CloseSharedWorkerContextConnection,
#if ENABLE(WEB_RTC)
    NetworkConnectionToWebProcess_ConnectToRTCDataChannelRemoteSource,
#endif
    NetworkConnectionToWebProcess_ConvertMainResourceLoadToDownload,
    NetworkConnectionToWebProcess_CookiesEnabled,
    NetworkConnectionToWebProcess_CookiesForDOMAsync,
    NetworkConnectionToWebProcess_CreateNewMessagePortChannel,
    NetworkConnectionToWebProcess_CreateRTCProvider,
    NetworkConnectionToWebProcess_CreateSocketChannel,
    NetworkConnectionToWebProcess_DeleteCookie,
    NetworkConnectionToWebProcess_DestroyWebTransportSession,
    NetworkConnectionToWebProcess_DidDeliverMessagePortMessages,
    NetworkConnectionToWebProcess_EntangleLocalPortInThisProcessToRemote,
    NetworkConnectionToWebProcess_EstablishSWContextConnection,
    NetworkConnectionToWebProcess_EstablishSharedWorkerContextConnection,
#if PLATFORM(MAC)
    NetworkConnectionToWebProcess_GetProcessDisplayName,
#endif
    NetworkConnectionToWebProcess_HasStorageAccess,
    NetworkConnectionToWebProcess_InitializeWebTransportSession,
#if ENABLE(CONTENT_FILTERING)
    NetworkConnectionToWebProcess_InstallMockContentFilter,
#endif
    NetworkConnectionToWebProcess_IsLoggedIn,
    NetworkConnectionToWebProcess_IsResourceLoadFinished,
    NetworkConnectionToWebProcess_LoadImageForDecoding,
    NetworkConnectionToWebProcess_LoadPing,
    NetworkConnectionToWebProcess_LogUserInteraction,
    NetworkConnectionToWebProcess_MessagePortClosed,
    NetworkConnectionToWebProcess_MessagePortDisentangled,
#if ENABLE(DECLARATIVE_WEB_PUSH)
    NetworkConnectionToWebProcess_NavigatorGetPushPermissionState,
    NetworkConnectionToWebProcess_NavigatorGetPushSubscription,
    NetworkConnectionToWebProcess_NavigatorSubscribeToPushService,
    NetworkConnectionToWebProcess_NavigatorUnsubscribeFromPushService,
#endif
    NetworkConnectionToWebProcess_PageLoadCompleted,
    NetworkConnectionToWebProcess_PingPongForServiceWorkers,
    NetworkConnectionToWebProcess_PostMessageToRemote,
    NetworkConnectionToWebProcess_PreconnectTo,
    NetworkConnectionToWebProcess_PrefetchDNS,
    NetworkConnectionToWebProcess_PrioritizeResourceLoads,
    NetworkConnectionToWebProcess_RegisterBlobPathForTesting,
    NetworkConnectionToWebProcess_RegisterBlobURL,
    NetworkConnectionToWebProcess_RegisterBlobURLHandle,
    NetworkConnectionToWebProcess_RegisterInternalBlobURL,
    NetworkConnectionToWebProcess_RegisterInternalBlobURLForSlice,
    NetworkConnectionToWebProcess_RegisterInternalBlobURLOptionallyFileBacked,
    NetworkConnectionToWebProcess_RegisterInternalFileBlobURL,
    NetworkConnectionToWebProcess_RegisterURLSchemesAsCORSEnabled,
    NetworkConnectionToWebProcess_RemoveLoadIdentifier,
    NetworkConnectionToWebProcess_RemoveOriginAccessAllowListEntry,
    NetworkConnectionToWebProcess_RemoveStorageAccessForFrame,
    NetworkConnectionToWebProcess_RequestStorageAccess,
    NetworkConnectionToWebProcess_RequestStorageAccessUnderOpener,
    NetworkConnectionToWebProcess_ResetOriginAccessAllowLists,
    NetworkConnectionToWebProcess_ResourceLoadStatisticsUpdated,
    NetworkConnectionToWebProcess_ScheduleResourceLoad,
    NetworkConnectionToWebProcess_SendH2Ping,
    NetworkConnectionToWebProcess_SetCORSDisablingPatterns,
    NetworkConnectionToWebProcess_SetCaptureExtraNetworkLoadMetricsEnabled,
    NetworkConnectionToWebProcess_SetCookieFromDOMAsync,
    NetworkConnectionToWebProcess_SetCookiesFromDOM,
    NetworkConnectionToWebProcess_SetLoginStatus,
    NetworkConnectionToWebProcess_SetRawCookie,
    NetworkConnectionToWebProcess_SetResourceLoadSchedulingMode,
#if ENABLE(CONTENT_EXTENSIONS)
    NetworkConnectionToWebProcess_ShouldOffloadIFrameForHost,
#endif
    NetworkConnectionToWebProcess_StartDownload,
    NetworkConnectionToWebProcess_StorageAccessQuirkForTopFrameDomain,
#if HAVE(COOKIE_CHANGE_LISTENER_API)
    NetworkConnectionToWebProcess_SubscribeToCookieChangeNotifications,
#endif
    NetworkConnectionToWebProcess_TakeAllMessagesForPort,
    NetworkConnectionToWebProcess_UnregisterBlobURL,
    NetworkConnectionToWebProcess_UnregisterBlobURLHandle,
#if HAVE(COOKIE_CHANGE_LISTENER_API)
    NetworkConnectionToWebProcess_UnsubscribeFromCookieChangeNotifications,
#endif
#if PLATFORM(MAC)
    NetworkConnectionToWebProcess_UpdateActivePages,
#endif
    NetworkConnectionToWebProcess_UseRedirectionForCurrentNavigation,
    NetworkConnectionToWebProcess_WriteBlobsToTemporaryFilesForIndexedDB,
    NetworkContentRuleListManager_AddContentRuleLists,
    NetworkContentRuleListManager_Remove,
    NetworkContentRuleListManager_RemoveAllContentRuleLists,
    NetworkContentRuleListManager_RemoveContentRuleList,
    NetworkMDNSRegister_RegisterMDNSName,
    NetworkMDNSRegister_UnregisterMDNSNames,
#if HAVE(COOKIE_CHANGE_LISTENER_API)
    NetworkProcessConnection_AllCookiesDeleted,
#endif
    NetworkProcessConnection_BroadcastConsoleMessage,
#if ENABLE(WEB_RTC)
    NetworkProcessConnection_ConnectToRTCDataChannelRemoteSource,
#endif
    NetworkProcessConnection_CookieAcceptPolicyChanged,
#if HAVE(COOKIE_CHANGE_LISTENER_API)
    NetworkProcessConnection_CookiesAdded,
    NetworkProcessConnection_CookiesDeleted,
#endif
#if ENABLE(SHAREABLE_RESOURCE)
    NetworkProcessConnection_DidCacheResource,
#endif
    NetworkProcessConnection_DidFinishPingLoad,
    NetworkProcessConnection_DidFinishPreconnection,
    NetworkProcessConnection_LoadCancelledDownloadRedirectRequestInFrame,
    NetworkProcessConnection_MessagesAvailableForPort,
    NetworkProcessConnection_SetOnLineState,
    NetworkProcessConnection_UpdateCachedCookiesEnabled,
#if ENABLE(CONTENT_EXTENSIONS)
    NetworkProcessProxy_ContentExtensionRules,
#endif
    NetworkProcessProxy_CookiesDidChange,
    NetworkProcessProxy_DataTaskDidCompleteWithError,
    NetworkProcessProxy_DataTaskDidReceiveData,
    NetworkProcessProxy_DataTaskDidReceiveResponse,
    NetworkProcessProxy_DataTaskReceivedChallenge,
    NetworkProcessProxy_DataTaskWillPerformHTTPRedirection,
    NetworkProcessProxy_DeleteWebsiteDataInUIProcessForRegistrableDomains,
    NetworkProcessProxy_DeleteWebsiteDataInWebProcessesForOrigin,
    NetworkProcessProxy_DidAllowPrivateTokenUsageByThirdPartyForTesting,
    NetworkProcessProxy_DidBlockLoadToKnownTracker,
    NetworkProcessProxy_DidCommitCrossSiteLoadWithDataTransferFromPrevalentResource,
#if USE(SOUP)
    NetworkProcessProxy_DidExceedMemoryLimit,
#endif
    NetworkProcessProxy_DidNegotiateModernTLS,
    NetworkProcessProxy_DidReceiveAuthenticationChallenge,
    NetworkProcessProxy_EndServiceWorkerBackgroundProcessing,
    NetworkProcessProxy_EstablishRemoteWorkerContextConnectionToNetworkProcess,
#if ENABLE(APP_BOUND_DOMAINS)
    NetworkProcessProxy_GetAppBoundDomains,
#endif
#if ENABLE(APPLE_PAY_REMOTE_UI)
    NetworkProcessProxy_GetPaymentCoordinatorEmbeddingUserAgent,
#endif
#if ENABLE(APPLE_PAY_REMOTE_UI_USES_SCENE)
    NetworkProcessProxy_GetWindowSceneAndBundleIdentifierForPaymentPresentation,
#endif
    NetworkProcessProxy_IncreaseQuota,
    NetworkProcessProxy_LogDiagnosticMessage,
    NetworkProcessProxy_LogDiagnosticMessageWithResult,
    NetworkProcessProxy_LogDiagnosticMessageWithValue,
    NetworkProcessProxy_LogTestingEvent,
    NetworkProcessProxy_NavigateServiceWorkerClient,
    NetworkProcessProxy_NegotiatedLegacyTLS,
    NetworkProcessProxy_NotifyBackgroundFetchChange,
    NetworkProcessProxy_OpenWindowFromServiceWorker,
    NetworkProcessProxy_ProcessHasUnresponseServiceWorker,
    NetworkProcessProxy_RegisterRemoteWorkerClientProcess,
    NetworkProcessProxy_ReloadExecutionContextsForOrigin,
    NetworkProcessProxy_RemoteWorkerContextConnectionNoLongerNeeded,
    NetworkProcessProxy_ReportConsoleMessage,
#if ENABLE(NETWORK_ISSUE_REPORTING)
    NetworkProcessProxy_ReportNetworkIssue,
#endif
    NetworkProcessProxy_RequestBackgroundFetchPermission,
    NetworkProcessProxy_RequestStorageAccessConfirm,
    NetworkProcessProxy_ResourceLoadDidCompleteWithError,
    NetworkProcessProxy_ResourceLoadDidPerformHTTPRedirection,
    NetworkProcessProxy_ResourceLoadDidReceiveChallenge,
    NetworkProcessProxy_ResourceLoadDidReceiveResponse,
    NetworkProcessProxy_ResourceLoadDidSendRequest,
    NetworkProcessProxy_SetDomainsWithCrossPageStorageAccess,
    NetworkProcessProxy_SetDomainsWithUserInteraction,
    NetworkProcessProxy_SetWebProcessHasUploads,
    NetworkProcessProxy_StartServiceWorkerBackgroundProcessing,
    NetworkProcessProxy_TerminateWebProcess,
    NetworkProcessProxy_TriggerBrowsingContextGroupSwitchForNavigation,
    NetworkProcessProxy_UnregisterRemoteWorkerClientProcess,
#if USE(RUNNINGBOARD)
    NetworkProcessProxy_WakeUpWebProcessForIPC,
#endif
    NetworkProcess_AbortBackgroundFetch,
    NetworkProcess_AddAllowedFirstPartyForCookies,
    NetworkProcess_AddWebPageNetworkParameters,
    NetworkProcess_AddWebsiteDataStore,
    NetworkProcess_AllowFileAccessFromWebProcess,
    NetworkProcess_AllowFilesAccessFromWebProcess,
#if !PLATFORM(COCOA)
    NetworkProcess_AllowSpecificHTTPSCertificateForHost,
#endif
    NetworkProcess_AllowTLSCertificateChainForLocalPCMTesting,
#if PLATFORM(COCOA)
    NetworkProcess_AppPrivacyReportTestingData,
#endif
    NetworkProcess_ApplicationDidEnterBackground,
    NetworkProcess_ApplicationWillEnterForeground,
    NetworkProcess_CancelDataTask,
    NetworkProcess_CancelDownload,
#if ENABLE(APP_BOUND_DOMAINS)
    NetworkProcess_ClearAppBoundSession,
#endif
#if PLATFORM(COCOA)
    NetworkProcess_ClearAppPrivacyReportTestingData,
#endif
    NetworkProcess_ClearBundleIdentifier,
    NetworkProcess_ClearPrevalentResource,
    NetworkProcess_ClearPrivateClickMeasurement,
#if HAVE(NW_PROXY_CONFIG)
    NetworkProcess_ClearProxyConfigData,
#endif
#if PLATFORM(IOS_FAMILY) && !PLATFORM(MACCATALYST)
    NetworkProcess_ClearServiceWorkerEntitlementOverride,
#endif
    NetworkProcess_ClearUserInteraction,
    NetworkProcess_ClickBackgroundFetch,
    NetworkProcess_CloneSessionStorageForWebPage,
    NetworkProcess_CloseITPDatabase,
    NetworkProcess_ClosePCMDatabase,
    NetworkProcess_CountNonDefaultSessionSets,
    NetworkProcess_CreateNetworkConnectionToWebProcess,
    NetworkProcess_DataTaskWithRequest,
    NetworkProcess_DeleteCookiesForTesting,
    NetworkProcess_DeleteWebsiteData,
    NetworkProcess_DeleteWebsiteDataForOrigins,
    NetworkProcess_DestroySession,
    NetworkProcess_DidCommitCrossSiteLoadWithDataTransfer,
    NetworkProcess_DidIncreaseQuota,
#if PLATFORM(IOS_FAMILY) && !PLATFORM(MACCATALYST)
    NetworkProcess_DisableServiceWorkerEntitlement,
#endif
    NetworkProcess_DomainIDExistsInDatabase,
    NetworkProcess_DownloadRequest,
    NetworkProcess_DumpPrivateClickMeasurement,
    NetworkProcess_DumpResourceLoadStatistics,
    NetworkProcess_EnsureSessionWithDataStoreIdentifierRemoved,
    NetworkProcess_FetchLocalStorage,
    NetworkProcess_FetchSessionStorage,
    NetworkProcess_FetchWebsiteData,
    NetworkProcess_FlushCookies,
    NetworkProcess_GetAllBackgroundFetchIdentifiers,
    NetworkProcess_GetAllStorageAccessEntries,
    NetworkProcess_GetAppBadgeForTesting,
    NetworkProcess_GetBackgroundFetchState,
    NetworkProcess_GetPendingPushMessage,
    NetworkProcess_GetPendingPushMessages,
    NetworkProcess_GetResourceLoadStatisticsDataSummary,
    NetworkProcess_GrantStorageAccessForTesting,
    NetworkProcess_HadUserInteraction,
#if ENABLE(APP_BOUND_DOMAINS)
    NetworkProcess_HasAppBoundSession,
#endif
    NetworkProcess_HasIsolatedSession,
    NetworkProcess_HasLocalStorage,
    NetworkProcess_HasPushSubscriptionForTesting,
    NetworkProcess_InitializeNetworkProcess,
    NetworkProcess_InsertExpiredStatisticForTesting,
    NetworkProcess_IsGrandfathered,
    NetworkProcess_IsPrevalentResource,
    NetworkProcess_IsRegisteredAsRedirectingTo,
    NetworkProcess_IsRegisteredAsSubFrameUnder,
    NetworkProcess_IsRegisteredAsSubresourceUnder,
    NetworkProcess_IsRelationshipOnlyInDatabaseOnce,
    NetworkProcess_IsResourceLoadStatisticsEphemeral,
    NetworkProcess_IsVeryPrevalentResource,
    NetworkProcess_LogFrameNavigation,
    NetworkProcess_LogUserInteraction,
    NetworkProcess_MarkAttributedPrivateClickMeasurementsAsExpiredForTesting,
    NetworkProcess_MarkPrivateClickMeasurementsAsExpiredForTesting,
    NetworkProcess_MergeStatisticForTesting,
    NetworkProcess_NotifyMediaStreamingActivity,
    NetworkProcess_PauseBackgroundFetch,
    NetworkProcess_PreconnectTo,
#if USE(SOUP)
    NetworkProcess_PrefetchDNS,
#endif
    NetworkProcess_PrepareToSuspend,
    NetworkProcess_ProcessDidResume,
    NetworkProcess_ProcessNotificationEvent,
    NetworkProcess_ProcessPushMessage,
#if (PLATFORM(COCOA) && HAVE(MODERN_DOWNLOADPROGRESS)) || (PLATFORM(COCOA) && !HAVE(MODERN_DOWNLOADPROGRESS))
    NetworkProcess_PublishDownloadProgress,
#endif
    NetworkProcess_RegisterURLSchemeAsBypassingContentSecurityPolicy,
    NetworkProcess_RegisterURLSchemeAsLocal,
#if ENABLE(ALL_LEGACY_REGISTERED_SPECIAL_URL_SCHEMES)
    NetworkProcess_RegisterURLSchemeAsNoAccess,
#endif
    NetworkProcess_RegisterURLSchemeAsSecure,
    NetworkProcess_RemovePushSubscriptionsForOrigin,
    NetworkProcess_RemoveWebPageNetworkParameters,
    NetworkProcess_RenameOriginInWebsiteData,
    NetworkProcess_ResetCacheMaxAgeCapForPrevalentResources,
    NetworkProcess_ResetCrossSiteLoadsWithLinkDecorationForTesting,
    NetworkProcess_ResetParametersToDefaultValues,
    NetworkProcess_ResetQuota,
#if ENABLE(CONTENT_EXTENSIONS)
    NetworkProcess_ResetResourceMonitorThrottlerForTesting,
#endif
    NetworkProcess_ResetStoragePersistedState,
    NetworkProcess_RestoreLocalStorage,
    NetworkProcess_RestoreSessionStorage,
    NetworkProcess_ResumeBackgroundFetch,
    NetworkProcess_ResumeDownload,
    NetworkProcess_RunningOrTerminatingServiceWorkerCountForTesting,
    NetworkProcess_ScheduleClearInMemoryAndPersistent,
    NetworkProcess_ScheduleCookieBlockingUpdate,
    NetworkProcess_ScheduleStatisticsAndDataRecordsProcessing,
#if ENABLE(APP_BOUND_DOMAINS)
    NetworkProcess_SetAppBoundDomainsForResourceLoadStatistics,
#endif
#if PLATFORM(IOS_FAMILY)
    NetworkProcess_SetBackupExclusionPeriodForTesting,
#endif
    NetworkProcess_SetCacheMaxAgeCapForPrevalentResources,
    NetworkProcess_SetCacheModel,
    NetworkProcess_SetCrossSiteLoadWithLinkDecorationForTesting,
    NetworkProcess_SetDefaultRequestTimeoutInterval,
#if ENABLE(INSPECTOR_NETWORK_THROTTLING)
    NetworkProcess_SetEmulatedConditions,
#endif
    NetworkProcess_SetFirstPartyHostCNAMEDomainForTesting,
    NetworkProcess_SetFirstPartyWebsiteDataRemovalModeForTesting,
    NetworkProcess_SetGrandfathered,
    NetworkProcess_SetGrandfatheringTime,
#if USE(SOUP)
    NetworkProcess_SetIgnoreTLSErrors,
#endif
    NetworkProcess_SetInspectionForServiceWorkersAllowed,
    NetworkProcess_SetIsRunningResourceLoadStatisticsTest,
    NetworkProcess_SetLastSeen,
#if ENABLE(MANAGED_DOMAINS)
    NetworkProcess_SetManagedDomainsForResourceLoadStatistics,
#endif
    NetworkProcess_SetMaxStatisticsEntries,
    NetworkProcess_SetMinimumTimeBetweenDataRecordsRemoval,
#if USE(SOUP) || USE(CURL)
    NetworkProcess_SetNetworkProxySettings,
#endif
#if HAVE(ALLOW_ONLY_PARTITIONED_COOKIES)
    NetworkProcess_SetOptInCookiePartitioningEnabled,
#endif
    NetworkProcess_SetOriginQuotaRatioEnabledForTesting,
    NetworkProcess_SetPCMFraudPreventionValuesForTesting,
    NetworkProcess_SetPersistedDomains,
#if USE(SOUP)
    NetworkProcess_SetPersistentCredentialStorageEnabled,
#endif
    NetworkProcess_SetPrevalentResource,
    NetworkProcess_SetPrevalentResourceForDebugMode,
    NetworkProcess_SetPrivateClickMeasurementAppBundleIDForTesting,
    NetworkProcess_SetPrivateClickMeasurementAttributionReportURLsForTesting,
    NetworkProcess_SetPrivateClickMeasurementDebugMode,
    NetworkProcess_SetPrivateClickMeasurementEphemeralMeasurementForTesting,
    NetworkProcess_SetPrivateClickMeasurementOverrideTimerForTesting,
    NetworkProcess_SetPrivateClickMeasurementTokenPublicKeyURLForTesting,
    NetworkProcess_SetPrivateClickMeasurementTokenSignatureURLForTesting,
#if HAVE(NW_PROXY_CONFIG)
    NetworkProcess_SetProxyConfigData,
#endif
    NetworkProcess_SetPruneEntriesDownTo,
    NetworkProcess_SetPushAndNotificationsEnabledForOrigin,
    NetworkProcess_SetResourceLoadStatisticsDebugMode,
    NetworkProcess_SetResourceLoadStatisticsLogTestingEvent,
    NetworkProcess_SetResourceLoadStatisticsTimeAdvanceForTesting,
    NetworkProcess_SetSessionIsControlledByAutomation,
    NetworkProcess_SetShouldClassifyResourcesBeforeDataRecordsRemoval,
    NetworkProcess_SetShouldDowngradeReferrerForTesting,
    NetworkProcess_SetShouldEnbleSameSiteStrictEnforcementForTesting,
    NetworkProcess_SetShouldRelaxThirdPartyCookieBlockingForPage,
    NetworkProcess_SetShouldSendPrivateTokenIPCForTesting,
    NetworkProcess_SetStorageSiteValidationEnabled,
    NetworkProcess_SetSubframeUnderTopFrameDomain,
    NetworkProcess_SetSubresourceUnderTopFrameDomain,
    NetworkProcess_SetSubresourceUniqueRedirectFrom,
    NetworkProcess_SetSubresourceUniqueRedirectTo,
    NetworkProcess_SetThirdPartyCNAMEDomainForTesting,
    NetworkProcess_SetThirdPartyCookieBlockingMode,
    NetworkProcess_SetTimeToLiveUserInteraction,
    NetworkProcess_SetToSameSiteStrictCookiesForTesting,
    NetworkProcess_SetTopFrameUniqueRedirectFrom,
    NetworkProcess_SetTopFrameUniqueRedirectTo,
    NetworkProcess_SetTrackingPreventionEnabled,
    NetworkProcess_SetVeryPrevalentResource,
    NetworkProcess_SharedPreferencesForWebProcessDidChange,
    NetworkProcess_SimulatePrivateClickMeasurementSessionRestart,
    NetworkProcess_StatisticsDatabaseHasAllTables,
    NetworkProcess_StorePrivateClickMeasurement,
    NetworkProcess_StoreServiceWorkerRegistrations,
    NetworkProcess_SyncLocalStorage,
    NetworkProcess_TerminateIdleServiceWorkers,
    NetworkProcess_TerminateRemoteWorkerContextConnectionWhenPossible,
    NetworkProcess_UpdateBundleIdentifier,
    NetworkProcess_UpdatePrevalentDomainsToBlockCookiesFor,
    NetworkProcess_UpdateStorageAccessPromptQuirks,
#if USE(SOUP)
    NetworkProcess_UserPreferredLanguagesChanged,
#endif
    NetworkProcess_WebsiteDataOriginDirectoryForTesting,
    NetworkRTCMonitor_StartUpdatingIfNeeded,
    NetworkRTCMonitor_StopUpdating,
    NetworkRTCProvider_CloseSocket,
    NetworkRTCProvider_CreateClientTCPSocket,
    NetworkRTCProvider_CreateResolver,
    NetworkRTCProvider_CreateUDPSocket,
#if PLATFORM(COCOA)
    NetworkRTCProvider_GetInterfaceName,
#endif
    NetworkRTCProvider_SendToSocket,
    NetworkRTCProvider_SetSocketOption,
    NetworkRTCProvider_StopResolver,
    NetworkResourceLoader_ContinueDidReceiveResponse,
    NetworkSocketChannel_Close,
    NetworkSocketChannel_SendData,
    NetworkSocketChannel_SendString,
    NetworkStorageManager_AbortOpenAndUpgradeNeeded,
    NetworkStorageManager_AbortTransaction,
    NetworkStorageManager_CacheStorageAllCaches,
    NetworkStorageManager_CacheStorageClearMemoryRepresentation,
    NetworkStorageManager_CacheStorageDereference,
    NetworkStorageManager_CacheStorageOpenCache,
    NetworkStorageManager_CacheStoragePutRecords,
    NetworkStorageManager_CacheStorageReference,
    NetworkStorageManager_CacheStorageRemoveCache,
    NetworkStorageManager_CacheStorageRemoveRecords,
    NetworkStorageManager_CacheStorageRepresentation,
    NetworkStorageManager_CacheStorageRetrieveRecords,
    NetworkStorageManager_CancelConnectToStorageArea,
    NetworkStorageManager_Clear,
    NetworkStorageManager_ClearObjectStore,
    NetworkStorageManager_CloseHandle,
    NetworkStorageManager_CloseSyncAccessHandle,
    NetworkStorageManager_CloseWritable,
    NetworkStorageManager_CommitTransaction,
    NetworkStorageManager_ConnectToStorageArea,
    NetworkStorageManager_CreateIndex,
    NetworkStorageManager_CreateObjectStore,
    NetworkStorageManager_CreateSyncAccessHandle,
    NetworkStorageManager_CreateWritable,
    NetworkStorageManager_DatabaseConnectionClosed,
    NetworkStorageManager_DatabaseConnectionPendingClose,
    NetworkStorageManager_DeleteDatabase,
    NetworkStorageManager_DeleteIndex,
    NetworkStorageManager_DeleteObjectStore,
    NetworkStorageManager_DeleteRecord,
    NetworkStorageManager_DidFinishHandlingVersionChangeTransaction,
    NetworkStorageManager_DidFireVersionChangeEvent,
    NetworkStorageManager_DidGenerateIndexKeyForRecord,
    NetworkStorageManager_DisconnectFromStorageArea,
    NetworkStorageManager_EstablishTransaction,
    NetworkStorageManager_Estimate,
    NetworkStorageManager_ExecuteCommandForWritable,
    NetworkStorageManager_FileSystemGetDirectory,
    NetworkStorageManager_GetAllDatabaseNamesAndVersions,
    NetworkStorageManager_GetAllRecords,
    NetworkStorageManager_GetCount,
    NetworkStorageManager_GetDirectoryHandle,
    NetworkStorageManager_GetFile,
    NetworkStorageManager_GetFileHandle,
    NetworkStorageManager_GetHandle,
    NetworkStorageManager_GetHandleNames,
    NetworkStorageManager_GetRecord,
    NetworkStorageManager_IsSameEntry,
    NetworkStorageManager_IterateCursor,
    NetworkStorageManager_LockCacheStorage,
    NetworkStorageManager_Move,
    NetworkStorageManager_OpenCursor,
    NetworkStorageManager_OpenDBRequestCancelled,
    NetworkStorageManager_OpenDatabase,
    NetworkStorageManager_Persist,
    NetworkStorageManager_Persisted,
    NetworkStorageManager_PutOrAdd,
    NetworkStorageManager_RemoveEntry,
    NetworkStorageManager_RemoveItem,
    NetworkStorageManager_RenameIndex,
    NetworkStorageManager_RenameObjectStore,
    NetworkStorageManager_RequestNewCapacityForSyncAccessHandle,
    NetworkStorageManager_ResetQuotaUpdatedBasedOnUsageForTesting,
    NetworkStorageManager_Resolve,
    NetworkStorageManager_SetItem,
    NetworkStorageManager_UnlockCacheStorage,
    NetworkTransportSession_CancelReceiveStream,
    NetworkTransportSession_CancelSendStream,
    NetworkTransportSession_CreateBidirectionalStream,
    NetworkTransportSession_CreateOutgoingUnidirectionalStream,
    NetworkTransportSession_DestroyStream,
    NetworkTransportSession_SendDatagram,
    NetworkTransportSession_StreamSendBytes,
    NetworkTransportSession_Terminate,
#if ENABLE(NOTIFICATIONS)
    NotificationManagerMessageHandler_CancelNotification,
    NotificationManagerMessageHandler_ClearNotifications,
    NotificationManagerMessageHandler_DidDestroyNotification,
#endif
#if ENABLE(WEB_PUSH_NOTIFICATIONS)
    NotificationManagerMessageHandler_GetPermissionState,
#endif
#if ENABLE(NOTIFICATIONS)
    NotificationManagerMessageHandler_PageWasNotifiedOfNotificationPermission,
    NotificationManagerMessageHandler_RequestPermission,
#endif
#if ENABLE(WEB_PUSH_NOTIFICATIONS)
    NotificationManagerMessageHandler_SetAppBadge,
#endif
#if ENABLE(NOTIFICATIONS)
    NotificationManagerMessageHandler_ShowNotification,
#endif
    PlatformXRSystemProxy_SessionDidEnd,
    PlatformXRSystemProxy_SessionDidUpdateVisibilityState,
#if USE(OPENXR)
    PlatformXRSystem_CreateLayerProjection,
#endif
    PlatformXRSystem_DidCompleteShutdownTriggeredBySystem,
    PlatformXRSystem_EnumerateImmersiveXRDevices,
    PlatformXRSystem_InitializeTrackingAndRendering,
    PlatformXRSystem_RequestFrame,
    PlatformXRSystem_RequestPermissionOnSessionFeatures,
    PlatformXRSystem_ShutDownTrackingAndRendering,
#if USE(OPENXR) || !USE(OPENXR)
    PlatformXRSystem_SubmitFrame,
#endif
    PushClientConnection_CancelNotification,
    PushClientConnection_GetAppBadgeForTesting,
    PushClientConnection_GetNotifications,
    PushClientConnection_GetPendingPushMessage,
    PushClientConnection_GetPendingPushMessages,
    PushClientConnection_GetPushPermissionState,
    PushClientConnection_GetPushSubscription,
    PushClientConnection_GetPushTopicsForTesting,
    PushClientConnection_IncrementSilentPushCount,
    PushClientConnection_InitializeConnection,
    PushClientConnection_InjectEncryptedPushMessageForTesting,
    PushClientConnection_InjectPushMessageForTesting,
    PushClientConnection_RemoveAllPushSubscriptions,
    PushClientConnection_RemovePushSubscriptionsForOrigin,
    PushClientConnection_RequestPushPermission,
    PushClientConnection_SetAppBadge,
    PushClientConnection_SetProtocolVersionForTesting,
    PushClientConnection_SetPublicTokenForTesting,
    PushClientConnection_SetPushAndNotificationsEnabledForOrigin,
    PushClientConnection_SetServiceWorkerIsBeingInspected,
    PushClientConnection_ShowNotification,
    PushClientConnection_SubscribeToPushService,
    PushClientConnection_UnsubscribeFromPushService,
    RTCDataChannelRemoteManagerProxy_BufferedAmountIsDecreasing,
    RTCDataChannelRemoteManagerProxy_ChangeReadyState,
    RTCDataChannelRemoteManagerProxy_Close,
    RTCDataChannelRemoteManagerProxy_DetectError,
    RTCDataChannelRemoteManagerProxy_ReceiveData,
    RTCDataChannelRemoteManagerProxy_SendData,
    RTCDataChannelRemoteManager_BufferedAmountIsDecreasing,
    RTCDataChannelRemoteManager_ChangeReadyState,
    RTCDataChannelRemoteManager_Close,
    RTCDataChannelRemoteManager_DetectError,
    RTCDataChannelRemoteManager_ReceiveData,
    RTCDataChannelRemoteManager_SendData,
    RemoteAdapter_Destruct,
#if PLATFORM(COCOA)
    RemoteAudioDestinationManager_AudioSamplesStorageChanged,
#endif
    RemoteAudioDestinationManager_CreateAudioDestination,
    RemoteAudioDestinationManager_DeleteAudioDestination,
#if PLATFORM(IOS_FAMILY)
    RemoteAudioDestinationManager_SetSceneIdentifier,
#endif
    RemoteAudioDestinationManager_StartAudioDestination,
    RemoteAudioDestinationManager_StopAudioDestination,
    RemoteAudioHardwareListener_AudioHardwareDidBecomeActive,
    RemoteAudioHardwareListener_AudioHardwareDidBecomeInactive,
    RemoteAudioHardwareListener_AudioOutputDeviceChanged,
    RemoteAudioMediaStreamTrackRendererInternalUnitManager_CreateUnit,
    RemoteAudioMediaStreamTrackRendererInternalUnitManager_DeleteUnit,
    RemoteAudioMediaStreamTrackRendererInternalUnitManager_SetLastDeviceUsed,
    RemoteAudioMediaStreamTrackRendererInternalUnitManager_StartUnit,
    RemoteAudioMediaStreamTrackRendererInternalUnitManager_StopUnit,
    RemoteAudioSessionProxy_BeginInterruptionRemote,
    RemoteAudioSessionProxy_EndInterruptionRemote,
    RemoteAudioSessionProxy_SetCategory,
    RemoteAudioSessionProxy_SetIsPlayingToBluetoothOverride,
    RemoteAudioSessionProxy_SetPreferredBufferSize,
    RemoteAudioSessionProxy_SetSceneIdentifier,
    RemoteAudioSessionProxy_SetSoundStageSize,
    RemoteAudioSessionProxy_TriggerBeginInterruptionForTesting,
    RemoteAudioSessionProxy_TriggerEndInterruptionForTesting,
    RemoteAudioSession_BeginInterruptionRemote,
    RemoteAudioSession_ConfigurationChanged,
    RemoteAudioSession_EndInterruptionRemote,
    RemoteAudioSourceProviderManager_AudioSamplesAvailable,
    RemoteAudioSourceProviderManager_AudioStorageChanged,
    RemoteBarcodeDetector_Detect,
    RemoteBindGroupLayout_Destruct,
    RemoteBindGroupLayout_SetLabel,
    RemoteBindGroup_Destruct,
    RemoteBindGroup_SetLabel,
    RemoteBuffer_Copy,
    RemoteBuffer_CopyWithCopy,
    RemoteBuffer_Destroy,
    RemoteBuffer_Destruct,
    RemoteBuffer_MapAsync,
    RemoteBuffer_SetLabel,
    RemoteBuffer_Unmap,
    RemoteCDMFactoryProxy_RemoveInstance,
    RemoteCDMFactoryProxy_RemoveSession,
    RemoteCDMInstanceProxy_InitializeWithConfiguration,
    RemoteCDMInstanceProxy_SetServerCertificate,
    RemoteCDMInstanceProxy_SetStorageDirectory,
    RemoteCDMInstanceSessionProxy_CloseSession,
    RemoteCDMInstanceSessionProxy_LoadSession,
    RemoteCDMInstanceSessionProxy_RemoveSessionData,
    RemoteCDMInstanceSessionProxy_RequestLicense,
    RemoteCDMInstanceSessionProxy_SetLogIdentifier,
    RemoteCDMInstanceSessionProxy_StoreRecordOfKeyUsage,
    RemoteCDMInstanceSessionProxy_UpdateLicense,
    RemoteCDMInstanceSession_SendMessage,
    RemoteCDMInstanceSession_SessionIdChanged,
    RemoteCDMInstanceSession_UpdateKeyStatuses,
    RemoteCDMInstance_UnrequestedInitializationDataReceived,
    RemoteCDMProxy_GetSupportedConfiguration,
    RemoteCDMProxy_LoadAndInitialize,
    RemoteCDMProxy_SetLogIdentifier,
    RemoteCommandBuffer_Destruct,
    RemoteCommandBuffer_SetLabel,
    RemoteCommandEncoder_BeginComputePass,
    RemoteCommandEncoder_BeginRenderPass,
    RemoteCommandEncoder_ClearBuffer,
    RemoteCommandEncoder_CopyBufferToBuffer,
    RemoteCommandEncoder_CopyBufferToTexture,
    RemoteCommandEncoder_CopyTextureToBuffer,
    RemoteCommandEncoder_CopyTextureToTexture,
    RemoteCommandEncoder_Destruct,
    RemoteCommandEncoder_Finish,
    RemoteCommandEncoder_InsertDebugMarker,
    RemoteCommandEncoder_PopDebugGroup,
    RemoteCommandEncoder_PushDebugGroup,
    RemoteCommandEncoder_ResolveQuerySet,
    RemoteCommandEncoder_SetLabel,
    RemoteCommandEncoder_WriteTimestamp,
    RemoteCompositorIntegration_Destruct,
    RemoteCompositorIntegration_UpdateContentsHeadroom,
    RemoteComputePassEncoder_Destruct,
    RemoteComputePassEncoder_Dispatch,
    RemoteComputePassEncoder_DispatchIndirect,
    RemoteComputePassEncoder_End,
    RemoteComputePassEncoder_InsertDebugMarker,
    RemoteComputePassEncoder_PopDebugGroup,
    RemoteComputePassEncoder_PushDebugGroup,
    RemoteComputePassEncoder_SetBindGroup,
    RemoteComputePassEncoder_SetLabel,
    RemoteComputePassEncoder_SetPipeline,
    RemoteComputePipeline_Destruct,
    RemoteComputePipeline_GetBindGroupLayout,
    RemoteComputePipeline_SetLabel,
    RemoteDevice_CreateBindGroup,
    RemoteDevice_CreateBindGroupLayout,
    RemoteDevice_CreateBuffer,
    RemoteDevice_CreateCommandEncoder,
    RemoteDevice_CreateComputePipeline,
    RemoteDevice_CreateComputePipelineAsync,
    RemoteDevice_CreatePipelineLayout,
    RemoteDevice_CreateQuerySet,
    RemoteDevice_CreateRenderBundleEncoder,
    RemoteDevice_CreateRenderPipeline,
    RemoteDevice_CreateRenderPipelineAsync,
    RemoteDevice_CreateSampler,
    RemoteDevice_CreateShaderModule,
    RemoteDevice_CreateTexture,
    RemoteDevice_CreateXRBinding,
    RemoteDevice_Destroy,
    RemoteDevice_Destruct,
#if PLATFORM(COCOA) && ENABLE(VIDEO)
    RemoteDevice_ImportExternalTextureFromVideoFrame,
#endif
    RemoteDevice_PauseAllErrorReporting,
    RemoteDevice_PopErrorScope,
    RemoteDevice_PushErrorScope,
    RemoteDevice_ResolveDeviceLostPromise,
    RemoteDevice_ResolveUncapturedErrorEvent,
    RemoteDevice_SetLabel,
#if PLATFORM(COCOA) && ENABLE(VIDEO)
    RemoteDevice_SetSharedVideoFrameMemory,
    RemoteDevice_SetSharedVideoFrameSemaphore,
    RemoteDevice_UpdateExternalTexture,
#endif
    RemoteDisplayListRecorder_ApplyDeviceScaleFactor,
#if USE(CG)
    RemoteDisplayListRecorder_ApplyFillPattern,
    RemoteDisplayListRecorder_ApplyStrokePattern,
#endif
    RemoteDisplayListRecorder_BeginPage,
    RemoteDisplayListRecorder_BeginTransparencyLayer,
    RemoteDisplayListRecorder_BeginTransparencyLayerWithCompositeMode,
    RemoteDisplayListRecorder_ClearRect,
    RemoteDisplayListRecorder_Clip,
    RemoteDisplayListRecorder_ClipOut,
    RemoteDisplayListRecorder_ClipOutRoundedRect,
    RemoteDisplayListRecorder_ClipOutToPath,
    RemoteDisplayListRecorder_ClipPath,
    RemoteDisplayListRecorder_ClipRoundedRect,
    RemoteDisplayListRecorder_ClipToImageBuffer,
    RemoteDisplayListRecorder_ConcatCTM,
    RemoteDisplayListRecorder_DrawControlPart,
    RemoteDisplayListRecorder_DrawDecomposedGlyphs,
    RemoteDisplayListRecorder_DrawDotsForDocumentMarker,
    RemoteDisplayListRecorder_DrawEllipse,
    RemoteDisplayListRecorder_DrawFilteredImageBuffer,
    RemoteDisplayListRecorder_DrawFocusRingPath,
    RemoteDisplayListRecorder_DrawFocusRingRects,
    RemoteDisplayListRecorder_DrawGlyphs,
    RemoteDisplayListRecorder_DrawImageBuffer,
    RemoteDisplayListRecorder_DrawLine,
    RemoteDisplayListRecorder_DrawLinesForText,
    RemoteDisplayListRecorder_DrawNativeImage,
    RemoteDisplayListRecorder_DrawPath,
    RemoteDisplayListRecorder_DrawPatternImageBuffer,
    RemoteDisplayListRecorder_DrawPatternNativeImage,
    RemoteDisplayListRecorder_DrawRect,
    RemoteDisplayListRecorder_DrawSystemImage,
#if PLATFORM(COCOA) && ENABLE(VIDEO)
    RemoteDisplayListRecorder_DrawVideoFrame,
#endif
    RemoteDisplayListRecorder_EndPage,
    RemoteDisplayListRecorder_EndTransparencyLayer,
#if ENABLE(INLINE_PATH_DATA)
    RemoteDisplayListRecorder_FillArc,
    RemoteDisplayListRecorder_FillBezierCurve,
    RemoteDisplayListRecorder_FillClosedArc,
#endif
    RemoteDisplayListRecorder_FillCompositedRect,
    RemoteDisplayListRecorder_FillEllipse,
#if ENABLE(INLINE_PATH_DATA)
    RemoteDisplayListRecorder_FillLine,
#endif
    RemoteDisplayListRecorder_FillPath,
    RemoteDisplayListRecorder_FillPathSegment,
#if ENABLE(INLINE_PATH_DATA)
    RemoteDisplayListRecorder_FillQuadCurve,
#endif
    RemoteDisplayListRecorder_FillRect,
    RemoteDisplayListRecorder_FillRectWithColor,
    RemoteDisplayListRecorder_FillRectWithGradient,
    RemoteDisplayListRecorder_FillRectWithGradientAndSpaceTransform,
    RemoteDisplayListRecorder_FillRectWithRoundedHole,
    RemoteDisplayListRecorder_FillRoundedRect,
    RemoteDisplayListRecorder_ResetClip,
    RemoteDisplayListRecorder_Restore,
    RemoteDisplayListRecorder_Rotate,
    RemoteDisplayListRecorder_Save,
    RemoteDisplayListRecorder_Scale,
    RemoteDisplayListRecorder_SetAlpha,
    RemoteDisplayListRecorder_SetCTM,
    RemoteDisplayListRecorder_SetCompositeMode,
    RemoteDisplayListRecorder_SetDrawLuminanceMask,
    RemoteDisplayListRecorder_SetDropShadow,
    RemoteDisplayListRecorder_SetFillCachedGradient,
    RemoteDisplayListRecorder_SetFillColor,
    RemoteDisplayListRecorder_SetFillGradient,
    RemoteDisplayListRecorder_SetFillPackedColor,
    RemoteDisplayListRecorder_SetFillPattern,
    RemoteDisplayListRecorder_SetFillRule,
    RemoteDisplayListRecorder_SetImageInterpolationQuality,
    RemoteDisplayListRecorder_SetLineCap,
    RemoteDisplayListRecorder_SetLineDash,
    RemoteDisplayListRecorder_SetLineJoin,
    RemoteDisplayListRecorder_SetMiterLimit,
    RemoteDisplayListRecorder_SetShadowsIgnoreTransforms,
#if PLATFORM(COCOA) && ENABLE(VIDEO)
    RemoteDisplayListRecorder_SetSharedVideoFrameMemory,
    RemoteDisplayListRecorder_SetSharedVideoFrameSemaphore,
#endif
    RemoteDisplayListRecorder_SetShouldAntialias,
    RemoteDisplayListRecorder_SetShouldSmoothFonts,
    RemoteDisplayListRecorder_SetShouldSubpixelQuantizeFonts,
    RemoteDisplayListRecorder_SetStrokeCachedGradient,
    RemoteDisplayListRecorder_SetStrokeColor,
    RemoteDisplayListRecorder_SetStrokeGradient,
    RemoteDisplayListRecorder_SetStrokePackedColor,
    RemoteDisplayListRecorder_SetStrokePackedColorAndThickness,
    RemoteDisplayListRecorder_SetStrokePattern,
    RemoteDisplayListRecorder_SetStrokeStyle,
    RemoteDisplayListRecorder_SetStrokeThickness,
    RemoteDisplayListRecorder_SetStyle,
    RemoteDisplayListRecorder_SetTextDrawingMode,
    RemoteDisplayListRecorder_SetURLForRect,
#if ENABLE(INLINE_PATH_DATA)
    RemoteDisplayListRecorder_StrokeArc,
    RemoteDisplayListRecorder_StrokeBezierCurve,
    RemoteDisplayListRecorder_StrokeClosedArc,
#endif
    RemoteDisplayListRecorder_StrokeEllipse,
#if ENABLE(INLINE_PATH_DATA)
    RemoteDisplayListRecorder_StrokeLine,
    RemoteDisplayListRecorder_StrokeLineWithColorAndThickness,
#endif
    RemoteDisplayListRecorder_StrokePath,
    RemoteDisplayListRecorder_StrokePathSegment,
#if ENABLE(INLINE_PATH_DATA)
    RemoteDisplayListRecorder_StrokeQuadCurve,
#endif
    RemoteDisplayListRecorder_StrokeRect,
    RemoteDisplayListRecorder_Translate,
    RemoteExternalTexture_Destroy,
    RemoteExternalTexture_Destruct,
    RemoteExternalTexture_SetLabel,
    RemoteExternalTexture_Undestroy,
    RemoteFaceDetector_Detect,
    RemoteGPUProxy_WasCreated,
    RemoteGPU_CreateCompositorIntegration,
    RemoteGPU_CreatePresentationContext,
    RemoteGraphicsContextGLProxy_WasCreated,
    RemoteGraphicsContextGLProxy_WasLost,
    RemoteGraphicsContextGLProxy_addDebugMessage,
    RemoteGraphicsContextGL_ActiveTexture,
    RemoteGraphicsContextGL_AttachShader,
    RemoteGraphicsContextGL_BeginQuery,
    RemoteGraphicsContextGL_BeginQueryEXT,
    RemoteGraphicsContextGL_BeginTransformFeedback,
    RemoteGraphicsContextGL_BindAttribLocation,
    RemoteGraphicsContextGL_BindBuffer,
    RemoteGraphicsContextGL_BindBufferBase,
    RemoteGraphicsContextGL_BindBufferRange,
#if ENABLE(WEBXR)
    RemoteGraphicsContextGL_BindExternalImage,
#endif
    RemoteGraphicsContextGL_BindFramebuffer,
    RemoteGraphicsContextGL_BindRenderbuffer,
    RemoteGraphicsContextGL_BindSampler,
    RemoteGraphicsContextGL_BindTexture,
    RemoteGraphicsContextGL_BindTransformFeedback,
    RemoteGraphicsContextGL_BindVertexArray,
    RemoteGraphicsContextGL_BlendColor,
    RemoteGraphicsContextGL_BlendEquation,
    RemoteGraphicsContextGL_BlendEquationSeparate,
    RemoteGraphicsContextGL_BlendEquationSeparateiOES,
    RemoteGraphicsContextGL_BlendEquationiOES,
    RemoteGraphicsContextGL_BlendFunc,
    RemoteGraphicsContextGL_BlendFuncSeparate,
    RemoteGraphicsContextGL_BlendFuncSeparateiOES,
    RemoteGraphicsContextGL_BlendFunciOES,
    RemoteGraphicsContextGL_BlitFramebuffer,
    RemoteGraphicsContextGL_BufferData0,
    RemoteGraphicsContextGL_BufferData1,
    RemoteGraphicsContextGL_BufferSubData,
    RemoteGraphicsContextGL_Clear,
    RemoteGraphicsContextGL_ClearBufferfi,
    RemoteGraphicsContextGL_ClearBufferfv,
    RemoteGraphicsContextGL_ClearBufferiv,
    RemoteGraphicsContextGL_ClearBufferuiv,
    RemoteGraphicsContextGL_ClearColor,
    RemoteGraphicsContextGL_ClearDepth,
    RemoteGraphicsContextGL_ClearStencil,
    RemoteGraphicsContextGL_ClipControlEXT,
    RemoteGraphicsContextGL_ColorMask,
    RemoteGraphicsContextGL_ColorMaskiOES,
    RemoteGraphicsContextGL_CompileShader,
    RemoteGraphicsContextGL_CompressedTexImage2D0,
    RemoteGraphicsContextGL_CompressedTexImage2D1,
    RemoteGraphicsContextGL_CompressedTexImage3D0,
    RemoteGraphicsContextGL_CompressedTexImage3D1,
    RemoteGraphicsContextGL_CompressedTexSubImage2D0,
    RemoteGraphicsContextGL_CompressedTexSubImage2D1,
    RemoteGraphicsContextGL_CompressedTexSubImage3D0,
    RemoteGraphicsContextGL_CompressedTexSubImage3D1,
    RemoteGraphicsContextGL_CopyBufferSubData,
    RemoteGraphicsContextGL_CopyTexImage2D,
    RemoteGraphicsContextGL_CopyTexSubImage2D,
    RemoteGraphicsContextGL_CopyTexSubImage3D,
    RemoteGraphicsContextGL_CreateBuffer,
#if ENABLE(WEBXR)
    RemoteGraphicsContextGL_CreateExternalImage,
    RemoteGraphicsContextGL_CreateExternalSync,
#endif
    RemoteGraphicsContextGL_CreateFramebuffer,
    RemoteGraphicsContextGL_CreateProgram,
    RemoteGraphicsContextGL_CreateQuery,
    RemoteGraphicsContextGL_CreateQueryEXT,
    RemoteGraphicsContextGL_CreateRenderbuffer,
    RemoteGraphicsContextGL_CreateSampler,
    RemoteGraphicsContextGL_CreateShader,
    RemoteGraphicsContextGL_CreateTexture,
    RemoteGraphicsContextGL_CreateTransformFeedback,
    RemoteGraphicsContextGL_CreateVertexArray,
    RemoteGraphicsContextGL_CullFace,
    RemoteGraphicsContextGL_DeleteBuffer,
#if ENABLE(WEBXR)
    RemoteGraphicsContextGL_DeleteExternalImage,
#endif
    RemoteGraphicsContextGL_DeleteExternalSync,
    RemoteGraphicsContextGL_DeleteFramebuffer,
    RemoteGraphicsContextGL_DeleteProgram,
    RemoteGraphicsContextGL_DeleteQuery,
    RemoteGraphicsContextGL_DeleteQueryEXT,
    RemoteGraphicsContextGL_DeleteRenderbuffer,
    RemoteGraphicsContextGL_DeleteSampler,
    RemoteGraphicsContextGL_DeleteShader,
    RemoteGraphicsContextGL_DeleteSync,
    RemoteGraphicsContextGL_DeleteTexture,
    RemoteGraphicsContextGL_DeleteTransformFeedback,
    RemoteGraphicsContextGL_DeleteVertexArray,
    RemoteGraphicsContextGL_DepthFunc,
    RemoteGraphicsContextGL_DepthMask,
    RemoteGraphicsContextGL_DepthRange,
    RemoteGraphicsContextGL_DetachShader,
    RemoteGraphicsContextGL_Disable,
#if ENABLE(WEBXR)
    RemoteGraphicsContextGL_DisableFoveation,
#endif
    RemoteGraphicsContextGL_DisableVertexAttribArray,
    RemoteGraphicsContextGL_DisableiOES,
    RemoteGraphicsContextGL_DrawArrays,
    RemoteGraphicsContextGL_DrawArraysInstanced,
    RemoteGraphicsContextGL_DrawArraysInstancedBaseInstanceANGLE,
    RemoteGraphicsContextGL_DrawBuffers,
    RemoteGraphicsContextGL_DrawBuffersEXT,
    RemoteGraphicsContextGL_DrawElements,
    RemoteGraphicsContextGL_DrawElementsInstanced,
    RemoteGraphicsContextGL_DrawElementsInstancedBaseVertexBaseInstanceANGLE,
    RemoteGraphicsContextGL_DrawRangeElements,
    RemoteGraphicsContextGL_Enable,
#if ENABLE(WEBXR)
    RemoteGraphicsContextGL_EnableFoveation,
#endif
    RemoteGraphicsContextGL_EnableVertexAttribArray,
    RemoteGraphicsContextGL_EnableiOES,
    RemoteGraphicsContextGL_EndQuery,
    RemoteGraphicsContextGL_EndQueryEXT,
    RemoteGraphicsContextGL_EndTransformFeedback,
    RemoteGraphicsContextGL_EnsureExtensionEnabled,
    RemoteGraphicsContextGL_Finish,
    RemoteGraphicsContextGL_Flush,
#if ENABLE(WEBXR)
    RemoteGraphicsContextGL_FramebufferDiscard,
#endif
    RemoteGraphicsContextGL_FramebufferRenderbuffer,
#if ENABLE(WEBXR)
    RemoteGraphicsContextGL_FramebufferResolveRenderbuffer,
#endif
    RemoteGraphicsContextGL_FramebufferTexture2D,
    RemoteGraphicsContextGL_FramebufferTextureLayer,
    RemoteGraphicsContextGL_FrontFace,
    RemoteGraphicsContextGL_GenerateMipmap,
    RemoteGraphicsContextGL_Hint,
    RemoteGraphicsContextGL_InvalidateFramebuffer,
    RemoteGraphicsContextGL_InvalidateSubFramebuffer,
    RemoteGraphicsContextGL_LineWidth,
    RemoteGraphicsContextGL_LinkProgram,
    RemoteGraphicsContextGL_MultiDrawArraysANGLE,
    RemoteGraphicsContextGL_MultiDrawArraysInstancedANGLE,
    RemoteGraphicsContextGL_MultiDrawArraysInstancedBaseInstanceANGLE,
    RemoteGraphicsContextGL_MultiDrawElementsANGLE,
    RemoteGraphicsContextGL_MultiDrawElementsInstancedANGLE,
    RemoteGraphicsContextGL_MultiDrawElementsInstancedBaseVertexBaseInstanceANGLE,
    RemoteGraphicsContextGL_PauseTransformFeedback,
    RemoteGraphicsContextGL_PixelStorei,
    RemoteGraphicsContextGL_PolygonModeANGLE,
    RemoteGraphicsContextGL_PolygonOffset,
    RemoteGraphicsContextGL_PolygonOffsetClampEXT,
    RemoteGraphicsContextGL_ProvokingVertexANGLE,
    RemoteGraphicsContextGL_QueryCounterEXT,
    RemoteGraphicsContextGL_ReadBuffer,
    RemoteGraphicsContextGL_ReadPixelsBufferObject,
    RemoteGraphicsContextGL_RenderbufferStorage,
    RemoteGraphicsContextGL_RenderbufferStorageMultisample,
    RemoteGraphicsContextGL_RenderbufferStorageMultisampleANGLE,
    RemoteGraphicsContextGL_Reshape,
    RemoteGraphicsContextGL_ResumeTransformFeedback,
    RemoteGraphicsContextGL_SampleCoverage,
    RemoteGraphicsContextGL_SamplerParameterf,
    RemoteGraphicsContextGL_SamplerParameteri,
    RemoteGraphicsContextGL_Scissor,
    RemoteGraphicsContextGL_SetDrawingBufferColorSpace,
#if ENABLE(VIDEO) && PLATFORM(COCOA)
    RemoteGraphicsContextGL_SetSharedVideoFrameMemory,
    RemoteGraphicsContextGL_SetSharedVideoFrameSemaphore,
#endif
    RemoteGraphicsContextGL_ShaderSource,
    RemoteGraphicsContextGL_SimulateEventForTesting,
    RemoteGraphicsContextGL_StencilFunc,
    RemoteGraphicsContextGL_StencilFuncSeparate,
    RemoteGraphicsContextGL_StencilMask,
    RemoteGraphicsContextGL_StencilMaskSeparate,
    RemoteGraphicsContextGL_StencilOp,
    RemoteGraphicsContextGL_StencilOpSeparate,
    RemoteGraphicsContextGL_TexImage2D0,
    RemoteGraphicsContextGL_TexImage2D1,
    RemoteGraphicsContextGL_TexImage3D0,
    RemoteGraphicsContextGL_TexImage3D1,
    RemoteGraphicsContextGL_TexParameterf,
    RemoteGraphicsContextGL_TexParameteri,
    RemoteGraphicsContextGL_TexStorage2D,
    RemoteGraphicsContextGL_TexStorage3D,
    RemoteGraphicsContextGL_TexSubImage2D0,
    RemoteGraphicsContextGL_TexSubImage2D1,
    RemoteGraphicsContextGL_TexSubImage3D0,
    RemoteGraphicsContextGL_TexSubImage3D1,
    RemoteGraphicsContextGL_TransformFeedbackVaryings,
    RemoteGraphicsContextGL_Uniform1f,
    RemoteGraphicsContextGL_Uniform1fv,
    RemoteGraphicsContextGL_Uniform1i,
    RemoteGraphicsContextGL_Uniform1iv,
    RemoteGraphicsContextGL_Uniform1ui,
    RemoteGraphicsContextGL_Uniform1uiv,
    RemoteGraphicsContextGL_Uniform2f,
    RemoteGraphicsContextGL_Uniform2fv,
    RemoteGraphicsContextGL_Uniform2i,
    RemoteGraphicsContextGL_Uniform2iv,
    RemoteGraphicsContextGL_Uniform2ui,
    RemoteGraphicsContextGL_Uniform2uiv,
    RemoteGraphicsContextGL_Uniform3f,
    RemoteGraphicsContextGL_Uniform3fv,
    RemoteGraphicsContextGL_Uniform3i,
    RemoteGraphicsContextGL_Uniform3iv,
    RemoteGraphicsContextGL_Uniform3ui,
    RemoteGraphicsContextGL_Uniform3uiv,
    RemoteGraphicsContextGL_Uniform4f,
    RemoteGraphicsContextGL_Uniform4fv,
    RemoteGraphicsContextGL_Uniform4i,
    RemoteGraphicsContextGL_Uniform4iv,
    RemoteGraphicsContextGL_Uniform4ui,
    RemoteGraphicsContextGL_Uniform4uiv,
    RemoteGraphicsContextGL_UniformBlockBinding,
    RemoteGraphicsContextGL_UniformMatrix2fv,
    RemoteGraphicsContextGL_UniformMatrix2x3fv,
    RemoteGraphicsContextGL_UniformMatrix2x4fv,
    RemoteGraphicsContextGL_UniformMatrix3fv,
    RemoteGraphicsContextGL_UniformMatrix3x2fv,
    RemoteGraphicsContextGL_UniformMatrix3x4fv,
    RemoteGraphicsContextGL_UniformMatrix4fv,
    RemoteGraphicsContextGL_UniformMatrix4x2fv,
    RemoteGraphicsContextGL_UniformMatrix4x3fv,
    RemoteGraphicsContextGL_UseProgram,
    RemoteGraphicsContextGL_ValidateProgram,
    RemoteGraphicsContextGL_VertexAttrib1f,
    RemoteGraphicsContextGL_VertexAttrib1fv,
    RemoteGraphicsContextGL_VertexAttrib2f,
    RemoteGraphicsContextGL_VertexAttrib2fv,
    RemoteGraphicsContextGL_VertexAttrib3f,
    RemoteGraphicsContextGL_VertexAttrib3fv,
    RemoteGraphicsContextGL_VertexAttrib4f,
    RemoteGraphicsContextGL_VertexAttrib4fv,
    RemoteGraphicsContextGL_VertexAttribDivisor,
    RemoteGraphicsContextGL_VertexAttribI4i,
    RemoteGraphicsContextGL_VertexAttribI4iv,
    RemoteGraphicsContextGL_VertexAttribI4ui,
    RemoteGraphicsContextGL_VertexAttribI4uiv,
    RemoteGraphicsContextGL_VertexAttribIPointer,
    RemoteGraphicsContextGL_VertexAttribPointer,
    RemoteGraphicsContextGL_Viewport,
    RemoteGraphicsContextGL_WaitSync,
    RemoteImageBufferProxy_DidCreateBackend,
#if PLATFORM(COCOA)
    RemoteImageBufferSetProxy_DidPrepareForDisplay,
#endif
    RemoteImageBufferSet_EndPrepareForDisplay,
    RemoteImageBufferSet_UpdateConfiguration,
    RemoteImageBuffer_ConvertToLuminanceMask,
    RemoteImageBuffer_FlushContext,
    RemoteImageBuffer_PutPixelBuffer,
    RemoteImageBuffer_TransformToColorSpace,
    RemoteLegacyCDMFactoryProxy_RemoveSession,
    RemoteLegacyCDMProxy_SetPlayerId,
    RemoteLegacyCDMSessionProxy_ReleaseKeys,
    RemoteLegacyCDMSession_SendError,
    RemoteLegacyCDMSession_SendMessage,
    RemoteMediaEngineConfigurationFactoryProxy_CreateDecodingConfiguration,
    RemoteMediaEngineConfigurationFactoryProxy_CreateEncodingConfiguration,
    RemoteMediaPlayerManagerProxy_CreateMediaPlayer,
    RemoteMediaPlayerManagerProxy_DeleteMediaPlayer,
    RemoteMediaPlayerProxy_AcceleratedRenderingStateChanged,
    RemoteMediaPlayerProxy_ApplicationDidBecomeActive,
    RemoteMediaPlayerProxy_ApplicationWillResignActive,
#if ENABLE(ENCRYPTED_MEDIA)
    RemoteMediaPlayerProxy_AttemptToDecryptWithInstance,
#endif
    RemoteMediaPlayerProxy_AudioOutputDeviceChanged,
    RemoteMediaPlayerProxy_AudioTrackSetEnabled,
    RemoteMediaPlayerProxy_BeginSimulatedHDCPError,
    RemoteMediaPlayerProxy_CancelLoad,
#if ENABLE(ENCRYPTED_MEDIA)
    RemoteMediaPlayerProxy_CdmInstanceAttached,
    RemoteMediaPlayerProxy_CdmInstanceDetached,
#endif
#if ENABLE(WEB_AUDIO)
    RemoteMediaPlayerProxy_CreateAudioSourceProvider,
#endif
    RemoteMediaPlayerProxy_DidLoadingProgress,
    RemoteMediaPlayerProxy_EndSimulatedHDCPError,
    RemoteMediaPlayerProxy_IsInFullscreenOrPictureInPictureChanged,
#if ENABLE(LEGACY_ENCRYPTED_MEDIA)
    RemoteMediaPlayerProxy_KeyAdded,
#endif
    RemoteMediaPlayerProxy_Load,
#if ENABLE(MEDIA_SOURCE)
    RemoteMediaPlayerProxy_LoadMediaSource,
#endif
    RemoteMediaPlayerProxy_NotifyActiveSourceBuffersChanged,
    RemoteMediaPlayerProxy_NotifyTrackModeChanged,
    RemoteMediaPlayerProxy_Pause,
    RemoteMediaPlayerProxy_PauseAtHostTime,
    RemoteMediaPlayerProxy_PerformTaskAtTime,
    RemoteMediaPlayerProxy_Play,
    RemoteMediaPlayerProxy_PlayAtHostTime,
    RemoteMediaPlayerProxy_PlayerContentBoxRectChanged,
    RemoteMediaPlayerProxy_PrepareForPlayback,
    RemoteMediaPlayerProxy_PrepareForRendering,
    RemoteMediaPlayerProxy_PrepareToPlay,
    RemoteMediaPlayerProxy_RequestHostingContext,
    RemoteMediaPlayerProxy_SeekToTarget,
    RemoteMediaPlayerProxy_SetBufferingPolicy,
#if HAVE(SPATIAL_TRACKING_LABEL)
    RemoteMediaPlayerProxy_SetDefaultSpatialTrackingLabel,
#endif
    RemoteMediaPlayerProxy_SetHasMessageClientForTesting,
#if ENABLE(LEGACY_ENCRYPTED_MEDIA)
    RemoteMediaPlayerProxy_SetLegacyCDMSession,
#endif
    RemoteMediaPlayerProxy_SetMuted,
    RemoteMediaPlayerProxy_SetPageIsVisible,
    RemoteMediaPlayerProxy_SetPitchCorrectionAlgorithm,
    RemoteMediaPlayerProxy_SetPlatformDynamicRangeLimit,
    RemoteMediaPlayerProxy_SetPreferredDynamicRangeMode,
#if HAVE(SPATIAL_AUDIO_EXPERIENCE)
    RemoteMediaPlayerProxy_SetPrefersSpatialAudioExperience,
#endif
    RemoteMediaPlayerProxy_SetPreload,
    RemoteMediaPlayerProxy_SetPresentationSize,
    RemoteMediaPlayerProxy_SetPreservesPitch,
    RemoteMediaPlayerProxy_SetPrivateBrowsingMode,
    RemoteMediaPlayerProxy_SetRate,
#if PLATFORM(IOS_FAMILY)
    RemoteMediaPlayerProxy_SetSceneIdentifier,
#endif
    RemoteMediaPlayerProxy_SetShouldCheckHardwareSupport,
#if ENABLE(LEGACY_ENCRYPTED_MEDIA) && ENABLE(ENCRYPTED_MEDIA)
    RemoteMediaPlayerProxy_SetShouldContinueAfterKeyNeeded,
#endif
    RemoteMediaPlayerProxy_SetShouldDisableHDR,
    RemoteMediaPlayerProxy_SetShouldDisableSleep,
#if ENABLE(WEB_AUDIO)
    RemoteMediaPlayerProxy_SetShouldEnableAudioSourceProvider,
#endif
    RemoteMediaPlayerProxy_SetShouldMaintainAspectRatio,
#if ENABLE(WIRELESS_PLAYBACK_TARGET)
    RemoteMediaPlayerProxy_SetShouldPlayToPlaybackTarget,
#endif
    RemoteMediaPlayerProxy_SetSoundStageSize,
#if HAVE(SPATIAL_TRACKING_LABEL)
    RemoteMediaPlayerProxy_SetSpatialTrackingLabel,
#endif
#if ENABLE(VIDEO_PRESENTATION_MODE)
    RemoteMediaPlayerProxy_SetVideoFullscreenGravity,
    RemoteMediaPlayerProxy_SetVideoFullscreenMode,
#endif
#if PLATFORM(COCOA)
    RemoteMediaPlayerProxy_SetVideoLayerSizeFenced,
#endif
    RemoteMediaPlayerProxy_SetVideoPlaybackMetricsUpdateInterval,
    RemoteMediaPlayerProxy_SetVolume,
    RemoteMediaPlayerProxy_SetVolumeLocked,
#if ENABLE(WIRELESS_PLAYBACK_TARGET)
    RemoteMediaPlayerProxy_SetWirelessPlaybackTarget,
    RemoteMediaPlayerProxy_SetWirelessVideoPlaybackDisabled,
#endif
    RemoteMediaPlayerProxy_StartVideoFrameMetadataGathering,
    RemoteMediaPlayerProxy_StopVideoFrameMetadataGathering,
    RemoteMediaPlayerProxy_TextTrackSetMode,
    RemoteMediaPlayerProxy_TracksChanged,
#if ENABLE(VIDEO_PRESENTATION_MODE)
    RemoteMediaPlayerProxy_UpdateVideoFullscreenInlineImage,
    RemoteMediaPlayerProxy_VideoFullscreenStandbyChanged,
#endif
    RemoteMediaPlayerProxy_VideoTrackSetSelected,
    RemoteMediaResourceManager_AccessControlCheckFailed,
    RemoteMediaResourceManager_DataReceived,
    RemoteMediaResourceManager_DataSent,
    RemoteMediaResourceManager_LoadFailed,
    RemoteMediaResourceManager_LoadFinished,
    RemoteMediaResourceManager_RedirectReceived,
    RemoteMediaResourceManager_ResponseReceived,
    RemoteMediaSessionCoordinatorProxy_CoordinatePause,
    RemoteMediaSessionCoordinatorProxy_CoordinatePlay,
    RemoteMediaSessionCoordinatorProxy_CoordinateSeekTo,
    RemoteMediaSessionCoordinatorProxy_CoordinateSetTrack,
    RemoteMediaSessionCoordinatorProxy_Join,
    RemoteMediaSessionCoordinatorProxy_Leave,
    RemoteMediaSessionCoordinatorProxy_PlaybackStateChanged,
    RemoteMediaSessionCoordinatorProxy_PositionStateChanged,
    RemoteMediaSessionCoordinatorProxy_ReadyStateChanged,
    RemoteMediaSessionCoordinatorProxy_TrackIdentifierChanged,
    RemoteMediaSessionCoordinator_CoordinatorStateChanged,
    RemoteMediaSessionCoordinator_PauseSession,
    RemoteMediaSessionCoordinator_PlaySession,
    RemoteMediaSessionCoordinator_SeekSessionToTime,
    RemoteMediaSessionCoordinator_SetSessionTrack,
    RemoteMediaSourceProxy_BufferedChanged,
    RemoteMediaSourceProxy_DurationChanged,
    RemoteMediaSourceProxy_MarkEndOfStream,
    RemoteMediaSourceProxy_SetMediaPlayerReadyState,
    RemoteMediaSourceProxy_SetTimeFudgeFactor,
    RemoteMediaSourceProxy_Shutdown,
    RemoteMediaSourceProxy_UnmarkEndOfStream,
    RemotePipelineLayout_Destruct,
    RemotePipelineLayout_SetLabel,
    RemotePresentationContext_Configure,
    RemotePresentationContext_GetCurrentTexture,
    RemotePresentationContext_Present,
    RemotePresentationContext_Unconfigure,
    RemoteQuerySet_Destroy,
    RemoteQuerySet_Destruct,
    RemoteQuerySet_SetLabel,
    RemoteQueue_CopyExternalImageToTexture,
    RemoteQueue_Destruct,
    RemoteQueue_OnSubmittedWorkDone,
    RemoteQueue_SetLabel,
    RemoteQueue_Submit,
    RemoteQueue_WriteBuffer,
    RemoteQueue_WriteBufferWithCopy,
    RemoteQueue_WriteTexture,
    RemoteQueue_WriteTextureWithCopy,
    RemoteRemoteCommandListenerProxy_UpdateSupportedCommands,
    RemoteRemoteCommandListener_DidReceiveRemoteControlCommand,
    RemoteRenderBundleEncoder_Destruct,
    RemoteRenderBundleEncoder_Draw,
    RemoteRenderBundleEncoder_DrawIndexed,
    RemoteRenderBundleEncoder_DrawIndexedIndirect,
    RemoteRenderBundleEncoder_DrawIndirect,
    RemoteRenderBundleEncoder_Finish,
    RemoteRenderBundleEncoder_InsertDebugMarker,
    RemoteRenderBundleEncoder_PopDebugGroup,
    RemoteRenderBundleEncoder_PushDebugGroup,
    RemoteRenderBundleEncoder_SetBindGroup,
    RemoteRenderBundleEncoder_SetIndexBuffer,
    RemoteRenderBundleEncoder_SetLabel,
    RemoteRenderBundleEncoder_SetPipeline,
    RemoteRenderBundleEncoder_SetVertexBuffer,
    RemoteRenderBundleEncoder_UnsetVertexBuffer,
    RemoteRenderBundle_Destruct,
    RemoteRenderBundle_SetLabel,
    RemoteRenderPassEncoder_BeginOcclusionQuery,
    RemoteRenderPassEncoder_Destruct,
    RemoteRenderPassEncoder_Draw,
    RemoteRenderPassEncoder_DrawIndexed,
    RemoteRenderPassEncoder_DrawIndexedIndirect,
    RemoteRenderPassEncoder_DrawIndirect,
    RemoteRenderPassEncoder_End,
    RemoteRenderPassEncoder_EndOcclusionQuery,
    RemoteRenderPassEncoder_ExecuteBundles,
    RemoteRenderPassEncoder_InsertDebugMarker,
    RemoteRenderPassEncoder_PopDebugGroup,
    RemoteRenderPassEncoder_PushDebugGroup,
    RemoteRenderPassEncoder_SetBindGroup,
    RemoteRenderPassEncoder_SetBlendConstant,
    RemoteRenderPassEncoder_SetIndexBuffer,
    RemoteRenderPassEncoder_SetLabel,
    RemoteRenderPassEncoder_SetPipeline,
    RemoteRenderPassEncoder_SetScissorRect,
    RemoteRenderPassEncoder_SetStencilReference,
    RemoteRenderPassEncoder_SetVertexBuffer,
    RemoteRenderPassEncoder_SetViewport,
    RemoteRenderPassEncoder_UnsetVertexBuffer,
    RemoteRenderPipeline_Destruct,
    RemoteRenderPipeline_GetBindGroupLayout,
    RemoteRenderPipeline_SetLabel,
    RemoteRenderingBackendProxy_DidFinalizeRenderingUpdate,
    RemoteRenderingBackendProxy_DidInitialize,
    RemoteRenderingBackendProxy_DidMarkLayersAsVolatile,
    RemoteRenderingBackend_CacheDecomposedGlyphs,
    RemoteRenderingBackend_CacheFilter,
    RemoteRenderingBackend_CacheFont,
    RemoteRenderingBackend_CacheFontCustomPlatformData,
    RemoteRenderingBackend_CacheGradient,
    RemoteRenderingBackend_CacheNativeImage,
    RemoteRenderingBackend_CreateImageBuffer,
    RemoteRenderingBackend_CreateImageBufferSet,
    RemoteRenderingBackend_CreateRemoteBarcodeDetector,
    RemoteRenderingBackend_CreateRemoteFaceDetector,
    RemoteRenderingBackend_CreateRemoteTextDetector,
    RemoteRenderingBackend_DestroyGetPixelBufferSharedMemory,
#if PLATFORM(COCOA)
    RemoteRenderingBackend_DidDrawRemoteToPDF,
#endif
    RemoteRenderingBackend_FinalizeRenderingUpdate,
#if USE(GRAPHICS_LAYER_WC)
    RemoteRenderingBackend_Flush,
#endif
    RemoteRenderingBackend_GetImageBufferResourceLimitsForTesting,
    RemoteRenderingBackend_GetRemoteBarcodeDetectorSupportedFormats,
    RemoteRenderingBackend_MarkSurfacesVolatile,
    RemoteRenderingBackend_MoveToImageBuffer,
    RemoteRenderingBackend_MoveToSerializedBuffer,
#if PLATFORM(COCOA)
    RemoteRenderingBackend_PrepareImageBufferSetsForDisplay,
#endif
    RemoteRenderingBackend_ReleaseDecomposedGlyphs,
    RemoteRenderingBackend_ReleaseFilter,
    RemoteRenderingBackend_ReleaseFont,
    RemoteRenderingBackend_ReleaseFontCustomPlatformData,
    RemoteRenderingBackend_ReleaseGradient,
    RemoteRenderingBackend_ReleaseImageBuffer,
    RemoteRenderingBackend_ReleaseImageBufferSet,
    RemoteRenderingBackend_ReleaseMemory,
    RemoteRenderingBackend_ReleaseNativeImage,
    RemoteRenderingBackend_ReleaseNativeImages,
    RemoteRenderingBackend_ReleaseRemoteBarcodeDetector,
    RemoteRenderingBackend_ReleaseRemoteFaceDetector,
    RemoteRenderingBackend_ReleaseRemoteTextDetector,
    RemoteSampleBufferDisplayLayerManager_CreateLayer,
    RemoteSampleBufferDisplayLayerManager_ReleaseLayer,
    RemoteSampleBufferDisplayLayer_ClearVideoFrames,
    RemoteSampleBufferDisplayLayer_EnqueueVideoFrame,
    RemoteSampleBufferDisplayLayer_Flush,
    RemoteSampleBufferDisplayLayer_FlushAndRemoveImage,
    RemoteSampleBufferDisplayLayer_Pause,
    RemoteSampleBufferDisplayLayer_Play,
#if !RELEASE_LOG_DISABLED
    RemoteSampleBufferDisplayLayer_SetLogIdentifier,
#endif
    RemoteSampleBufferDisplayLayer_SetSharedVideoFrameMemory,
    RemoteSampleBufferDisplayLayer_SetSharedVideoFrameSemaphore,
    RemoteSampleBufferDisplayLayer_SetShouldMaintainAspectRatio,
    RemoteSampleBufferDisplayLayer_UpdateDisplayMode,
    RemoteSampler_Destruct,
    RemoteSampler_SetLabel,
    RemoteShaderModule_CompilationInfo,
    RemoteShaderModule_Destruct,
    RemoteShaderModule_SetLabel,
    RemoteSharedResourceCache_ReleaseSerializedImageBuffer,
    RemoteSourceBufferProxy_Abort,
    RemoteSourceBufferProxy_AddTrackBuffer,
    RemoteSourceBufferProxy_Append,
    RemoteSourceBufferProxy_AsyncEvictCodedFrames,
    RemoteSourceBufferProxy_Attach,
    RemoteSourceBufferProxy_BufferedSamplesForTrackId,
    RemoteSourceBufferProxy_ClearTrackBuffers,
    RemoteSourceBufferProxy_ComputeSeekTime,
    RemoteSourceBufferProxy_Detach,
    RemoteSourceBufferProxy_EnqueuedSamplesForTrackID,
    RemoteSourceBufferProxy_MemoryPressure,
    RemoteSourceBufferProxy_ReenqueueMediaIfNeeded,
    RemoteSourceBufferProxy_RemoveCodedFrames,
    RemoteSourceBufferProxy_RemovedFromMediaSource,
    RemoteSourceBufferProxy_ResetParserState,
    RemoteSourceBufferProxy_ResetTimestampOffsetInTrackBuffers,
    RemoteSourceBufferProxy_ResetTrackBuffers,
    RemoteSourceBufferProxy_SeekToTime,
    RemoteSourceBufferProxy_SetActive,
    RemoteSourceBufferProxy_SetAllTrackBuffersNeedRandomAccess,
    RemoteSourceBufferProxy_SetAppendWindowEnd,
    RemoteSourceBufferProxy_SetAppendWindowStart,
    RemoteSourceBufferProxy_SetGroupStartTimestamp,
    RemoteSourceBufferProxy_SetGroupStartTimestampToEndTimestamp,
    RemoteSourceBufferProxy_SetMaximumBufferSize,
    RemoteSourceBufferProxy_SetMaximumQueueDepthForTrackID,
    RemoteSourceBufferProxy_SetMediaSourceEnded,
    RemoteSourceBufferProxy_SetMode,
    RemoteSourceBufferProxy_SetShouldGenerateTimestamps,
    RemoteSourceBufferProxy_SetTimestampOffset,
    RemoteSourceBufferProxy_StartChangingType,
    RemoteSourceBufferProxy_UpdateTrackIds,
    RemoteTextDetector_Detect,
    RemoteTextureView_Destruct,
    RemoteTextureView_SetLabel,
    RemoteTexture_CreateView,
    RemoteTexture_Destroy,
    RemoteTexture_Destruct,
    RemoteTexture_SetLabel,
    RemoteTexture_Undestroy,
    RemoteVideoFrameObjectHeapProxyProcessor_NewConvertedVideoFrameBuffer,
    RemoteVideoFrameObjectHeapProxyProcessor_NewVideoFrameBuffer,
    RemoteVideoFrameObjectHeapProxyProcessor_SetSharedVideoFrameMemory,
    RemoteVideoFrameObjectHeapProxyProcessor_SetSharedVideoFrameSemaphore,
#if PLATFORM(COCOA)
    RemoteVideoFrameObjectHeap_GetVideoFrameBuffer,
#endif
    RemoteVideoFrameObjectHeap_ReleaseVideoFrame,
#if PLATFORM(COCOA)
    RemoteVideoFrameObjectHeap_SetSharedVideoFrameMemory,
    RemoteVideoFrameObjectHeap_SetSharedVideoFrameSemaphore,
#endif
    RemoteWCLayerTreeHost_Update,
    RemoteWebInspectorUIProxy_BringToFront,
    RemoteWebInspectorUIProxy_FrontendDidClose,
    RemoteWebInspectorUIProxy_FrontendLoaded,
    RemoteWebInspectorUIProxy_Load,
    RemoteWebInspectorUIProxy_OpenURLExternally,
    RemoteWebInspectorUIProxy_PickColorFromScreen,
    RemoteWebInspectorUIProxy_Reopen,
    RemoteWebInspectorUIProxy_ResetState,
    RemoteWebInspectorUIProxy_RevealFileExternally,
    RemoteWebInspectorUIProxy_Save,
    RemoteWebInspectorUIProxy_SendMessageToBackend,
    RemoteWebInspectorUIProxy_SetForcedAppearance,
    RemoteWebInspectorUIProxy_SetInspectorPageDeveloperExtrasEnabled,
    RemoteWebInspectorUIProxy_SetSheetRect,
    RemoteWebInspectorUIProxy_ShowCertificate,
    RemoteWebInspectorUIProxy_StartWindowDrag,
    RemoteWebInspectorUI_Initialize,
    RemoteWebInspectorUI_SendMessageToFrontend,
#if ENABLE(INSPECTOR_TELEMETRY)
    RemoteWebInspectorUI_SetDiagnosticLoggingAvailable,
#endif
    RemoteWebInspectorUI_ShowConsole,
    RemoteWebInspectorUI_ShowResources,
    RemoteWebInspectorUI_UpdateFindString,
    RemoteWebLockRegistry_DidCompleteLockRequest,
    RemoteWebLockRegistry_DidStealLock,
    RemoteXRBinding_CreateProjectionLayer,
    RemoteXRBinding_Destruct,
    RemoteXRBinding_GetViewSubImage,
    RemoteXRProjectionLayer_Destruct,
    RemoteXRProjectionLayer_EndFrame,
#if PLATFORM(COCOA)
    RemoteXRProjectionLayer_StartFrame,
#endif
    RemoteXRSubImage_Destruct,
    RemoteXRSubImage_GetColorTexture,
    RemoteXRSubImage_GetDepthTexture,
    RemoteXRView_Destruct,
    SampleBufferDisplayLayer_SetDidFail,
    ServiceWorkerDownloadTask_DidFail,
    ServiceWorkerDownloadTask_DidFinish,
    ServiceWorkerDownloadTask_DidReceiveData,
    ServiceWorkerDownloadTask_DidReceiveFormData,
    ServiceWorkerFetchTask_DidFail,
    ServiceWorkerFetchTask_DidFinish,
    ServiceWorkerFetchTask_DidNotHandle,
    ServiceWorkerFetchTask_DidReceiveData,
    ServiceWorkerFetchTask_DidReceiveFormData,
    ServiceWorkerFetchTask_DidReceiveRedirectResponse,
    ServiceWorkerFetchTask_DidReceiveResponse,
    ServiceWorkerFetchTask_UsePreload,
    ServiceWorkerFetchTask_WorkerClosed,
    SourceBufferPrivateRemoteMessageReceiver_SourceBufferPrivateBufferedChanged,
    SourceBufferPrivateRemoteMessageReceiver_SourceBufferPrivateDidAttach,
    SourceBufferPrivateRemoteMessageReceiver_SourceBufferPrivateDidDropSample,
    SourceBufferPrivateRemoteMessageReceiver_SourceBufferPrivateDidReceiveInitializationSegment,
    SourceBufferPrivateRemoteMessageReceiver_SourceBufferPrivateDidReceiveRenderingError,
    SourceBufferPrivateRemoteMessageReceiver_SourceBufferPrivateDurationChanged,
    SourceBufferPrivateRemoteMessageReceiver_SourceBufferPrivateEvictionDataChanged,
    SourceBufferPrivateRemoteMessageReceiver_SourceBufferPrivateHighestPresentationTimestampChanged,
    SourceBufferPrivateRemoteMessageReceiver_TakeOwnershipOfMemory,
    SpeechRecognitionRealtimeMediaSourceManager_CreateSource,
    SpeechRecognitionRealtimeMediaSourceManager_DeleteSource,
    SpeechRecognitionRealtimeMediaSourceManager_Start,
    SpeechRecognitionRealtimeMediaSourceManager_Stop,
    SpeechRecognitionRemoteRealtimeMediaSourceManager_RemoteAudioSamplesAvailable,
    SpeechRecognitionRemoteRealtimeMediaSourceManager_RemoteCaptureFailed,
    SpeechRecognitionRemoteRealtimeMediaSourceManager_RemoteSourceStopped,
#if PLATFORM(COCOA)
    SpeechRecognitionRemoteRealtimeMediaSourceManager_SetStorage,
#endif
    SpeechRecognitionServer_Abort,
    SpeechRecognitionServer_Invalidate,
    SpeechRecognitionServer_Start,
    SpeechRecognitionServer_Stop,
    StorageAreaMap_ClearCache,
    StorageAreaMap_DispatchStorageEvent,
    VisitedLinkStore_AddVisitedLinkHashFromPage,
    VisitedLinkTableController_AllVisitedLinkStateChanged,
    VisitedLinkTableController_RemoveAllVisitedLinks,
    VisitedLinkTableController_SetVisitedLinkTable,
    VisitedLinkTableController_VisitedLinkStateChanged,
    WebAutomationSessionProxy_ComputeElementLayout,
    WebAutomationSessionProxy_DeleteCookie,
    WebAutomationSessionProxy_EvaluateJavaScriptFunction,
    WebAutomationSessionProxy_FocusFrame,
    WebAutomationSessionProxy_GetComputedLabel,
    WebAutomationSessionProxy_GetComputedRole,
    WebAutomationSessionProxy_GetCookiesForFrame,
    WebAutomationSessionProxy_ResolveChildFrameWithName,
    WebAutomationSessionProxy_ResolveChildFrameWithNodeHandle,
    WebAutomationSessionProxy_ResolveChildFrameWithOrdinal,
    WebAutomationSessionProxy_ResolveParentFrame,
    WebAutomationSessionProxy_SelectOptionElement,
    WebAutomationSessionProxy_SetFilesForInputFileUpload,
    WebAutomationSessionProxy_SnapshotRectForScreenshot,
    WebAutomationSessionProxy_TakeScreenshot,
    WebAutomationSession_LogEntryAdded,
    WebBroadcastChannelRegistry_PostMessageToRemote,
    WebCookieManager_DeleteAllCookies,
    WebCookieManager_DeleteAllCookiesModifiedSince,
    WebCookieManager_DeleteCookie,
    WebCookieManager_DeleteCookiesForHostnames,
    WebCookieManager_GetAllCookies,
    WebCookieManager_GetCookies,
    WebCookieManager_GetHTTPCookieAcceptPolicy,
    WebCookieManager_GetHostnamesWithCookies,
#if USE(SOUP)
    WebCookieManager_ReplaceCookies,
#endif
    WebCookieManager_SetCookie,
#if USE(SOUP)
    WebCookieManager_SetCookiePersistentStorage,
#endif
    WebCookieManager_SetCookies,
    WebCookieManager_SetHTTPCookieAcceptPolicy,
    WebCookieManager_StartObservingCookieChanges,
    WebCookieManager_StopObservingCookieChanges,
#if ENABLE(INSPECTOR_EXTENSIONS)
    WebExtensionContextProxy_AddInspectorBackgroundPageIdentifier,
    WebExtensionContextProxy_AddInspectorPageIdentifier,
#endif
    WebExtensionContextProxy_AddPopupPageIdentifier,
    WebExtensionContextProxy_AddTabPageIdentifier,
    WebExtensionContextProxy_DispatchActionClickedEvent,
    WebExtensionContextProxy_DispatchAlarmsEvent,
    WebExtensionContextProxy_DispatchCommandsChangedEvent,
    WebExtensionContextProxy_DispatchCommandsCommandEvent,
    WebExtensionContextProxy_DispatchCookiesChangedEvent,
#if ENABLE(INSPECTOR_EXTENSIONS)
    WebExtensionContextProxy_DispatchDevToolsExtensionPanelHiddenEvent,
    WebExtensionContextProxy_DispatchDevToolsExtensionPanelShownEvent,
    WebExtensionContextProxy_DispatchDevToolsNetworkNavigatedEvent,
    WebExtensionContextProxy_DispatchDevToolsPanelsThemeChangedEvent,
#endif
    WebExtensionContextProxy_DispatchMenusClickedEvent,
    WebExtensionContextProxy_DispatchPermissionsEvent,
    WebExtensionContextProxy_DispatchPortDisconnectEvent,
    WebExtensionContextProxy_DispatchPortMessageEvent,
    WebExtensionContextProxy_DispatchRuntimeConnectEvent,
    WebExtensionContextProxy_DispatchRuntimeInstalledEvent,
    WebExtensionContextProxy_DispatchRuntimeMessageEvent,
    WebExtensionContextProxy_DispatchRuntimeStartupEvent,
    WebExtensionContextProxy_DispatchStorageChangedEvent,
    WebExtensionContextProxy_DispatchTabsActivatedEvent,
    WebExtensionContextProxy_DispatchTabsAttachedEvent,
    WebExtensionContextProxy_DispatchTabsCreatedEvent,
    WebExtensionContextProxy_DispatchTabsDetachedEvent,
    WebExtensionContextProxy_DispatchTabsHighlightedEvent,
    WebExtensionContextProxy_DispatchTabsMovedEvent,
    WebExtensionContextProxy_DispatchTabsRemovedEvent,
    WebExtensionContextProxy_DispatchTabsReplacedEvent,
    WebExtensionContextProxy_DispatchTabsUpdatedEvent,
    WebExtensionContextProxy_DispatchTestFinishedEvent,
    WebExtensionContextProxy_DispatchTestMessageEvent,
    WebExtensionContextProxy_DispatchTestStartedEvent,
    WebExtensionContextProxy_DispatchWebNavigationEvent,
    WebExtensionContextProxy_DispatchWindowsEvent,
    WebExtensionContextProxy_ResourceLoadDidCompleteWithError,
    WebExtensionContextProxy_ResourceLoadDidPerformHTTPRedirection,
    WebExtensionContextProxy_ResourceLoadDidReceiveChallenge,
    WebExtensionContextProxy_ResourceLoadDidReceiveResponse,
    WebExtensionContextProxy_ResourceLoadDidSendRequest,
    WebExtensionContextProxy_SetBackgroundPageIdentifier,
    WebExtensionContextProxy_SetStorageAccessLevel,
    WebExtensionContextProxy_UpdateGrantedPermissions,
    WebExtensionContext_ActionGetBadgeText,
    WebExtensionContext_ActionGetEnabled,
    WebExtensionContext_ActionGetPopup,
    WebExtensionContext_ActionGetTitle,
    WebExtensionContext_ActionOpenPopup,
    WebExtensionContext_ActionSetBadgeText,
    WebExtensionContext_ActionSetEnabled,
    WebExtensionContext_ActionSetIcon,
    WebExtensionContext_ActionSetPopup,
    WebExtensionContext_ActionSetTitle,
    WebExtensionContext_AddListener,
    WebExtensionContext_AlarmsClear,
    WebExtensionContext_AlarmsClearAll,
    WebExtensionContext_AlarmsCreate,
    WebExtensionContext_AlarmsGet,
    WebExtensionContext_AlarmsGetAll,
#if ENABLE(WK_WEB_EXTENSIONS_BOOKMARKS)
    WebExtensionContext_BookmarksCreate,
    WebExtensionContext_BookmarksGet,
    WebExtensionContext_BookmarksGetChildren,
    WebExtensionContext_BookmarksGetRecent,
    WebExtensionContext_BookmarksGetSubTree,
    WebExtensionContext_BookmarksGetTree,
    WebExtensionContext_BookmarksMove,
    WebExtensionContext_BookmarksRemove,
    WebExtensionContext_BookmarksRemoveTree,
    WebExtensionContext_BookmarksSearch,
    WebExtensionContext_BookmarksUpdate,
#endif
    WebExtensionContext_CommandsGetAll,
    WebExtensionContext_CookiesGet,
    WebExtensionContext_CookiesGetAll,
    WebExtensionContext_CookiesGetAllCookieStores,
    WebExtensionContext_CookiesRemove,
    WebExtensionContext_CookiesSet,
    WebExtensionContext_DeclarativeNetRequestDisplayActionCountAsBadgeText,
    WebExtensionContext_DeclarativeNetRequestGetDynamicRules,
    WebExtensionContext_DeclarativeNetRequestGetEnabledRulesets,
    WebExtensionContext_DeclarativeNetRequestGetMatchedRules,
    WebExtensionContext_DeclarativeNetRequestGetSessionRules,
    WebExtensionContext_DeclarativeNetRequestIncrementActionCount,
    WebExtensionContext_DeclarativeNetRequestUpdateDynamicRules,
    WebExtensionContext_DeclarativeNetRequestUpdateEnabledRulesets,
    WebExtensionContext_DeclarativeNetRequestUpdateSessionRules,
#if ENABLE(INSPECTOR_EXTENSIONS)
    WebExtensionContext_DevToolsInspectedWindowEval,
    WebExtensionContext_DevToolsInspectedWindowReload,
    WebExtensionContext_DevToolsPanelsCreate,
#endif
    WebExtensionContext_ExtensionIsAllowedIncognitoAccess,
    WebExtensionContext_MenusCreate,
    WebExtensionContext_MenusRemove,
    WebExtensionContext_MenusRemoveAll,
    WebExtensionContext_MenusUpdate,
    WebExtensionContext_PermissionsContains,
    WebExtensionContext_PermissionsGetAll,
    WebExtensionContext_PermissionsRemove,
    WebExtensionContext_PermissionsRequest,
    WebExtensionContext_PortPostMessage,
    WebExtensionContext_PortRemoved,
    WebExtensionContext_RemoveListener,
    WebExtensionContext_RuntimeConnect,
    WebExtensionContext_RuntimeConnectNative,
    WebExtensionContext_RuntimeGetBackgroundPage,
    WebExtensionContext_RuntimeOpenOptionsPage,
    WebExtensionContext_RuntimeReload,
    WebExtensionContext_RuntimeSendMessage,
    WebExtensionContext_RuntimeSendNativeMessage,
    WebExtensionContext_RuntimeWebPageConnect,
    WebExtensionContext_RuntimeWebPageSendMessage,
    WebExtensionContext_ScriptingExecuteScript,
    WebExtensionContext_ScriptingGetRegisteredScripts,
    WebExtensionContext_ScriptingInsertCSS,
    WebExtensionContext_ScriptingRegisterContentScripts,
    WebExtensionContext_ScriptingRemoveCSS,
    WebExtensionContext_ScriptingUnregisterContentScripts,
    WebExtensionContext_ScriptingUpdateRegisteredScripts,
#if ENABLE(WK_WEB_EXTENSIONS_SIDEBAR)
    WebExtensionContext_SidebarClose,
    WebExtensionContext_SidebarGetActionClickBehavior,
    WebExtensionContext_SidebarGetOptions,
    WebExtensionContext_SidebarGetTitle,
    WebExtensionContext_SidebarIsOpen,
    WebExtensionContext_SidebarOpen,
    WebExtensionContext_SidebarSetActionClickBehavior,
    WebExtensionContext_SidebarSetIcon,
    WebExtensionContext_SidebarSetOptions,
    WebExtensionContext_SidebarSetTitle,
    WebExtensionContext_SidebarToggle,
#endif
    WebExtensionContext_StorageClear,
    WebExtensionContext_StorageGet,
    WebExtensionContext_StorageGetBytesInUse,
    WebExtensionContext_StorageGetKeys,
    WebExtensionContext_StorageRemove,
    WebExtensionContext_StorageSet,
    WebExtensionContext_StorageSetAccessLevel,
    WebExtensionContext_TabsCaptureVisibleTab,
    WebExtensionContext_TabsConnect,
    WebExtensionContext_TabsCreate,
    WebExtensionContext_TabsDetectLanguage,
    WebExtensionContext_TabsDuplicate,
    WebExtensionContext_TabsExecuteScript,
    WebExtensionContext_TabsGet,
    WebExtensionContext_TabsGetCurrent,
    WebExtensionContext_TabsGetZoom,
    WebExtensionContext_TabsGoBack,
    WebExtensionContext_TabsGoForward,
    WebExtensionContext_TabsInsertCSS,
    WebExtensionContext_TabsQuery,
    WebExtensionContext_TabsReload,
    WebExtensionContext_TabsRemove,
    WebExtensionContext_TabsRemoveCSS,
    WebExtensionContext_TabsSendMessage,
    WebExtensionContext_TabsSetZoom,
    WebExtensionContext_TabsToggleReaderMode,
    WebExtensionContext_TabsUpdate,
    WebExtensionContext_WebNavigationGetAllFrames,
    WebExtensionContext_WebNavigationGetFrame,
    WebExtensionContext_WindowsCreate,
    WebExtensionContext_WindowsGet,
    WebExtensionContext_WindowsGetAll,
    WebExtensionContext_WindowsGetLastFocused,
    WebExtensionContext_WindowsRemove,
    WebExtensionContext_WindowsUpdate,
    WebExtensionControllerProxy_Load,
    WebExtensionControllerProxy_Unload,
    WebExtensionController_DidCommitLoadForFrame,
    WebExtensionController_DidFailLoadForFrame,
    WebExtensionController_DidFinishLoadForFrame,
    WebExtensionController_DidStartProvisionalLoadForFrame,
    WebExtensionController_TestAdded,
    WebExtensionController_TestEqual,
    WebExtensionController_TestFinished,
    WebExtensionController_TestLogMessage,
    WebExtensionController_TestResult,
    WebExtensionController_TestSentMessage,
    WebExtensionController_TestStarted,
    WebFileSystemStorageConnection_InvalidateAccessHandle,
    WebFileSystemStorageConnection_InvalidateWritable,
    WebFrameProxy_FindFocusableElementDescendingIntoRemoteFrame,
    WebFrameProxy_SetAppBadge,
    WebFrameProxy_UpdateRemoteFrameSize,
    WebFrame_CreateProvisionalFrame,
    WebFrame_DestroyProvisionalFrame,
    WebFrame_FindFocusableElementDescendingIntoRemoteFrame,
    WebFrame_GetFrameInfo,
    WebFrame_UpdateFrameSize,
    WebFullScreenManagerProxy_BeganEnterFullScreen,
    WebFullScreenManagerProxy_BeganExitFullScreen,
    WebFullScreenManagerProxy_Close,
    WebFullScreenManagerProxy_EnterFullScreen,
    WebFullScreenManagerProxy_ExitFullScreen,
#if ENABLE(QUICKLOOK_FULLSCREEN)
    WebFullScreenManagerProxy_UpdateImageSource,
#endif
    WebFullScreenManager_EnterFullScreenForOwnerElements,
    WebFullScreenManager_ExitFullScreenInMainFrame,
    WebFullScreenManager_RequestExitFullScreen,
    WebFullScreenManager_RequestRestoreFullScreen,
    WebFullScreenManager_SetAnimatingFullScreen,
    WebFullScreenManager_SetFullscreenAutoHideDuration,
    WebFullScreenManager_SetFullscreenInsets,
    WebGeolocationManagerProxy_SetEnableHighAccuracy,
    WebGeolocationManagerProxy_StartUpdating,
    WebGeolocationManagerProxy_StopUpdating,
    WebGeolocationManager_DidChangePosition,
    WebGeolocationManager_DidFailToDeterminePosition,
#if PLATFORM(IOS_FAMILY)
    WebGeolocationManager_ResetPermissions,
#endif
    WebIDBConnectionToServer_DidAbortTransaction,
    WebIDBConnectionToServer_DidClearObjectStore,
    WebIDBConnectionToServer_DidCloseFromServer,
    WebIDBConnectionToServer_DidCommitTransaction,
    WebIDBConnectionToServer_DidCreateIndex,
    WebIDBConnectionToServer_DidCreateObjectStore,
    WebIDBConnectionToServer_DidDeleteDatabase,
    WebIDBConnectionToServer_DidDeleteIndex,
    WebIDBConnectionToServer_DidDeleteObjectStore,
    WebIDBConnectionToServer_DidDeleteRecord,
    WebIDBConnectionToServer_DidGetAllDatabaseNamesAndVersions,
    WebIDBConnectionToServer_DidGetAllRecords,
    WebIDBConnectionToServer_DidGetCount,
    WebIDBConnectionToServer_DidGetRecord,
    WebIDBConnectionToServer_DidIterateCursor,
    WebIDBConnectionToServer_DidOpenCursor,
    WebIDBConnectionToServer_DidOpenDatabase,
    WebIDBConnectionToServer_DidPutOrAdd,
    WebIDBConnectionToServer_DidRenameIndex,
    WebIDBConnectionToServer_DidRenameObjectStore,
    WebIDBConnectionToServer_DidStartTransaction,
    WebIDBConnectionToServer_FireVersionChangeEvent,
    WebIDBConnectionToServer_GenerateIndexKeyForRecord,
    WebIDBConnectionToServer_NotifyOpenDBRequestBlocked,
    WebInspectorBackendProxy_AttachAvailabilityChanged,
    WebInspectorBackendProxy_BringToFront,
    WebInspectorBackendProxy_DidClose,
    WebInspectorBackendProxy_ElementSelectionChanged,
    WebInspectorBackendProxy_RequestOpenLocalInspectorFrontend,
    WebInspectorBackendProxy_SetDeveloperPreferenceOverride,
#if ENABLE(INSPECTOR_NETWORK_THROTTLING)
    WebInspectorBackendProxy_SetEmulatedConditions,
#endif
    WebInspectorBackendProxy_TimelineRecordingChanged,
    WebInspectorInterruptDispatcher_NotifyNeedDebuggerBreak,
    WebInspectorUIProxy_AttachBottom,
    WebInspectorUIProxy_AttachLeft,
    WebInspectorUIProxy_AttachRight,
    WebInspectorUIProxy_BringToFront,
    WebInspectorUIProxy_Detach,
    WebInspectorUIProxy_DidClose,
    WebInspectorUIProxy_EffectiveAppearanceDidChange,
    WebInspectorUIProxy_FrontendLoaded,
    WebInspectorUIProxy_InspectedURLChanged,
    WebInspectorUIProxy_Load,
    WebInspectorUIProxy_OpenURLExternally,
    WebInspectorUIProxy_PickColorFromScreen,
    WebInspectorUIProxy_Reopen,
    WebInspectorUIProxy_ResetState,
    WebInspectorUIProxy_RevealFileExternally,
    WebInspectorUIProxy_Save,
    WebInspectorUIProxy_SendMessageToBackend,
    WebInspectorUIProxy_SetAttachedWindowHeight,
    WebInspectorUIProxy_SetAttachedWindowWidth,
    WebInspectorUIProxy_SetForcedAppearance,
    WebInspectorUIProxy_SetFrontendConnection,
    WebInspectorUIProxy_SetInspectorPageDeveloperExtrasEnabled,
    WebInspectorUIProxy_SetSheetRect,
    WebInspectorUIProxy_ShowCertificate,
    WebInspectorUIProxy_StartWindowDrag,
    WebInspectorUI_AttachedBottom,
    WebInspectorUI_AttachedLeft,
    WebInspectorUI_AttachedRight,
    WebInspectorUI_Detached,
    WebInspectorUI_EstablishConnection,
    WebInspectorUI_EvaluateInFrontendForTesting,
    WebInspectorUI_SendMessageToFrontend,
#if ENABLE(INSPECTOR_TELEMETRY)
    WebInspectorUI_SetDiagnosticLoggingAvailable,
#endif
    WebInspectorUI_SetDockingUnavailable,
    WebInspectorUI_SetIsVisible,
    WebInspectorUI_ShowConsole,
    WebInspectorUI_ShowMainResourceForFrame,
    WebInspectorUI_ShowResources,
    WebInspectorUI_StartElementSelection,
    WebInspectorUI_StartPageProfiling,
    WebInspectorUI_StopElementSelection,
    WebInspectorUI_StopPageProfiling,
    WebInspectorUI_UpdateConnection,
    WebInspectorUI_UpdateFindString,
    WebInspector_Close,
    WebInspector_SetAttached,
    WebInspector_SetFrontendConnection,
    WebInspector_Show,
    WebInspector_ShowConsole,
    WebInspector_ShowMainResourceForFrame,
    WebInspector_ShowResources,
    WebInspector_StartElementSelection,
    WebInspector_StartPageProfiling,
    WebInspector_StopElementSelection,
    WebInspector_StopPageProfiling,
    WebLockRegistryProxy_AbortLockRequest,
    WebLockRegistryProxy_ClientIsGoingAway,
    WebLockRegistryProxy_ReleaseLock,
    WebLockRegistryProxy_RequestLock,
    WebLockRegistryProxy_Snapshot,
    WebNotificationManager_DidClickNotification,
    WebNotificationManager_DidCloseNotifications,
    WebNotificationManager_DidRemoveNotificationDecisions,
    WebNotificationManager_DidShowNotification,
    WebNotificationManager_DidUpdateNotificationDecision,
#if ENABLE(APPLE_PAY_AMS_UI)
    WebPageProxy_AbortApplePayAMSUISession,
#endif
#if ENABLE(MEDIA_USAGE)
    WebPageProxy_AddMediaUsageManagerSession,
#endif
    WebPageProxy_AddMessageToConsoleForTesting,
#if ENABLE(WIRELESS_PLAYBACK_TARGET) && !PLATFORM(IOS_FAMILY)
    WebPageProxy_AddPlaybackTargetPickerClient,
#endif
#if ENABLE(WRITING_TOOLS)
    WebPageProxy_AddTextAnimationForAnimationID,
    WebPageProxy_AddTextAnimationForAnimationIDWithCompletionHandler,
#endif
#if PLATFORM(COCOA)
    WebPageProxy_AssistiveTechnologyMakeFirstResponder,
#endif
    WebPageProxy_BackForwardAddItem,
    WebPageProxy_BackForwardClearChildren,
    WebPageProxy_BackForwardSetChildItem,
    WebPageProxy_BackForwardUpdateItem,
#if ENABLE(MEDIA_STREAM)
    WebPageProxy_BeginMonitoringCaptureDevices,
#endif
#if USE(SYSTEM_PREVIEW)
    WebPageProxy_BeginSystemPreview,
#endif
#if ENABLE(IMAGE_ANALYSIS) && ENABLE(VIDEO)
    WebPageProxy_BeginTextRecognitionForVideoInElementFullScreen,
#endif
#if PLATFORM(GTK) || PLATFORM(WPE)
    WebPageProxy_BindAccessibilityTree,
#endif
    WebPageProxy_BroadcastProcessSyncData,
    WebPageProxy_BroadcastTopDocumentSyncData,
#if ENABLE(IMAGE_ANALYSIS) && ENABLE(VIDEO)
    WebPageProxy_CancelTextRecognitionForVideoInElementFullScreen,
#endif
#if PLATFORM(MAC)
    WebPageProxy_ChangeUniversalAccessZoomFocus,
#endif
    WebPageProxy_ClearAllEditCommands,
    WebPageProxy_ClearTextIndicator,
#if ENABLE(ATTACHMENT_ELEMENT)
    WebPageProxy_CloneAttachmentData,
#endif
    WebPageProxy_ClosePage,
#if PLATFORM(IOS_FAMILY)
    WebPageProxy_CommitPotentialTapFailed,
#endif
    WebPageProxy_CompositionWasCanceled,
    WebPageProxy_ConfigureLoggingChannel,
#if ENABLE(CONTENT_FILTERING)
    WebPageProxy_ContentFilterDidBlockLoadForFrame,
#endif
#if ENABLE(CONTENT_EXTENSIONS)
    WebPageProxy_ContentRuleListNotification,
#endif
#if PLATFORM(IOS_FAMILY)
    WebPageProxy_CouldNotRestorePageState,
#endif
    WebPageProxy_CreateInspectorTarget,
#if ENABLE(PDF_HUD)
    WebPageProxy_CreatePDFHUD,
#endif
#if ENABLE(PDF_PAGE_NUMBER_INDICATOR)
    WebPageProxy_CreatePDFPageNumberIndicator,
#endif
    WebPageProxy_DecidePolicyForNavigationActionAsync,
    WebPageProxy_DecidePolicyForNewWindowAction,
    WebPageProxy_DecidePolicyForResponse,
    WebPageProxy_DestroyInspectorTarget,
#if ENABLE(WINDOW_PROXY_PROPERTY_ACCESS_NOTIFICATION)
    WebPageProxy_DidAccessWindowProxyPropertyViaOpenerForFrame,
#endif
    WebPageProxy_DidAdjustVisibilityWithSelectors,
    WebPageProxy_DidApplyLinkDecorationFiltering,
    WebPageProxy_DidCancelClientRedirectForFrame,
    WebPageProxy_DidChangeContentSize,
    WebPageProxy_DidChangeInspectorFrontendCount,
    WebPageProxy_DidChangeIntrinsicContentSize,
    WebPageProxy_DidChangeMainDocument,
    WebPageProxy_DidChangePageCount,
    WebPageProxy_DidChangeProgress,
    WebPageProxy_DidChangeProvisionalURLForFrame,
    WebPageProxy_DidChangeScrollOffsetPinningForMainFrame,
    WebPageProxy_DidChangeScrollbarsForMainFrame,
    WebPageProxy_DidCommitLoadForFrame,
#if PLATFORM(IOS_FAMILY)
    WebPageProxy_DidCompleteSyntheticClick,
#endif
#if HAVE(VISIBILITY_PROPAGATION_VIEW)
    WebPageProxy_DidCreateContextInWebProcessForVisibilityPropagation,
#endif
    WebPageProxy_DidCreateSleepDisabler,
    WebPageProxy_DidCreateSubframe,
    WebPageProxy_DidDestroyFrame,
    WebPageProxy_DidDestroyNavigation,
    WebPageProxy_DidDestroySleepDisabler,
    WebPageProxy_DidDisplayInsecureContentForFrame,
#if ENABLE(WRITING_TOOLS)
    WebPageProxy_DidEndPartialIntelligenceTextAnimation,
#endif
    WebPageProxy_DidExplicitOpenForFrame,
    WebPageProxy_DidFailLoadForFrame,
    WebPageProxy_DidFailProvisionalLoadForFrame,
    WebPageProxy_DidFindTextManipulationItems,
    WebPageProxy_DidFinishDocumentLoadForFrame,
    WebPageProxy_DidFinishLoadForFrame,
#if USE(QUICK_LOOK)
    WebPageProxy_DidFinishLoadForQuickLookDocumentInMainFrame,
#endif
#if PLATFORM(GTK) || PLATFORM(WPE)
    WebPageProxy_DidFinishLoadForResource,
#endif
    WebPageProxy_DidFinishLoadingDataForCustomContentProvider,
    WebPageProxy_DidFinishProgress,
    WebPageProxy_DidFinishServiceWorkerPageRegistration,
    WebPageProxy_DidFirstLayoutForFrame,
    WebPageProxy_DidFirstVisuallyNonEmptyLayoutForFrame,
    WebPageProxy_DidGetImageForFindMatch,
#if PLATFORM(IOS_FAMILY)
    WebPageProxy_DidGetTapHighlightGeometries,
    WebPageProxy_DidHandleTapAsHover,
#endif
#if PLATFORM(GTK) || PLATFORM(WPE)
    WebPageProxy_DidInitiateLoadForResource,
#endif
#if ENABLE(ATTACHMENT_ELEMENT)
    WebPageProxy_DidInsertAttachmentWithIdentifier,
#endif
    WebPageProxy_DidNavigateWithNavigationData,
#if PLATFORM(IOS_FAMILY)
    WebPageProxy_DidNotHandleTapAsClick,
#endif
    WebPageProxy_DidPerformClientRedirect,
#if PLATFORM(COCOA)
    WebPageProxy_DidPerformDictionaryLookup,
#endif
#if PLATFORM(MAC)
    WebPageProxy_DidPerformImmediateActionHitTest,
#endif
    WebPageProxy_DidPerformServerRedirect,
#if PLATFORM(IOS_FAMILY)
    WebPageProxy_DidProgrammaticallyClearFocusedElement,
#endif
    WebPageProxy_DidReachLayoutMilestone,
#if PLATFORM(IOS_FAMILY) && ENABLE(DRAG_SUPPORT)
    WebPageProxy_DidReceiveEditDragSnapshot,
#endif
    WebPageProxy_DidReceiveEventIPC,
#if ENABLE(MODEL_PROCESS)
    WebPageProxy_DidReceiveInteractiveModelElement,
#endif
#if PLATFORM(IOS_FAMILY)
    WebPageProxy_DidReceivePositionInformation,
#endif
#if PLATFORM(GTK) || PLATFORM(WPE)
    WebPageProxy_DidReceiveResponseForResource,
#endif
    WebPageProxy_DidReceiveServerRedirectForProvisionalLoadForFrame,
    WebPageProxy_DidReceiveTitleForFrame,
#if ENABLE(ATTACHMENT_ELEMENT)
    WebPageProxy_DidRemoveAttachmentWithIdentifier,
#endif
    WebPageProxy_DidResignInputElementStrongPasswordAppearance,
    WebPageProxy_DidRestoreScrollPosition,
    WebPageProxy_DidRunInsecureContentForFrame,
    WebPageProxy_DidSameDocumentNavigationForFrame,
    WebPageProxy_DidSameDocumentNavigationForFrameViaJS,
#if PLATFORM(GTK) || PLATFORM(WPE)
    WebPageProxy_DidSendRequestForResource,
#endif
#if USE(QUICK_LOOK)
    WebPageProxy_DidStartLoadForQuickLookDocumentInMainFrame,
#endif
    WebPageProxy_DidStartProgress,
    WebPageProxy_DidStartProvisionalLoadForFrame,
    WebPageProxy_DidUpdateActivityState,
    WebPageProxy_DidUpdateHistoryTitle,
    WebPageProxy_DidUpdateRenderingAfterCommittingLoad,
#if PLATFORM(IOS_FAMILY)
    WebPageProxy_DisableDoubleTapGesturesDuringTapIfNecessary,
    WebPageProxy_DisableInspectorNodeSearch,
#endif
#if PLATFORM(MAC)
    WebPageProxy_DismissCorrectionPanel,
#endif
#if HAVE(DIGITAL_CREDENTIALS_UI)
    WebPageProxy_DismissDigitalCredentialsPicker,
#endif
    WebPageProxy_DispatchLoadEventToFrameOwnerElement,
    WebPageProxy_DocumentURLForConsoleLog,
    WebPageProxy_EditorStateChanged,
#if PLATFORM(IOS_FAMILY)
    WebPageProxy_ElementDidBlur,
    WebPageProxy_ElementDidFocus,
#endif
    WebPageProxy_EnableAccessibilityForAllProcesses,
#if PLATFORM(IOS_FAMILY)
    WebPageProxy_EnableInspectorNodeSearch,
#endif
    WebPageProxy_EndColorPicker,
    WebPageProxy_EndDataListSuggestions,
    WebPageProxy_EndDateTimePicker,
    WebPageProxy_EndNetworkRequestsForPageLoadTiming,
#if ENABLE(MEDIA_STREAM)
    WebPageProxy_EnumerateMediaDevicesForFrame,
#endif
    WebPageProxy_FixedLayoutSizeDidChange,
    WebPageProxy_FocusFromServiceWorker,
    WebPageProxy_FocusRemoteFrame,
#if PLATFORM(IOS_FAMILY)
    WebPageProxy_FocusedElementDidChangeInputMode,
#endif
    WebPageProxy_FocusedFrameChanged,
    WebPageProxy_FrameNameChanged,
#if ENABLE(GAMEPAD)
    WebPageProxy_GamepadsRecentlyAccessed,
#endif
    WebPageProxy_GetLoadDecisionForIcon,
#if PLATFORM(MAC)
    WebPageProxy_HandleAcceptsFirstMouse,
#endif
    WebPageProxy_HandleAutoFillButtonClick,
#if PLATFORM(IOS_FAMILY)
    WebPageProxy_HandleAutocorrectionContext,
#endif
    WebPageProxy_HandleAutoplayEvent,
#if ENABLE(DATA_DETECTION)
    WebPageProxy_HandleClickForDataDetectionResult,
#endif
#if HAVE(TRANSLATION_UI_SERVICES) && ENABLE(CONTEXT_MENUS)
    WebPageProxy_HandleContextMenuTranslation,
#endif
    WebPageProxy_HandleKeydownInDataList,
    WebPageProxy_HandleMessage,
    WebPageProxy_HandleMessageWithAsyncReply,
#if ENABLE(ARKIT_INLINE_PREVIEW_MAC)
    WebPageProxy_HandleMouseDownForModelElement,
    WebPageProxy_HandleMouseMoveForModelElement,
    WebPageProxy_HandleMouseUpForModelElement,
#endif
#if PLATFORM(IOS_FAMILY)
    WebPageProxy_HandleSmartMagnificationInformationForPotentialTap,
#endif
    WebPageProxy_HasActiveNowPlayingSessionChanged,
#if PLATFORM(IOS_FAMILY)
    WebPageProxy_HideInspectorHighlight,
    WebPageProxy_HideInspectorIndication,
#endif
    WebPageProxy_HidePopupMenu,
#if PLATFORM(COCOA) || PLATFORM(GTK)
    WebPageProxy_HideValidationMessage,
#endif
    WebPageProxy_IgnoreWord,
    WebPageProxy_ImageOrMediaDocumentSizeChanged,
#if ENABLE(ACCESSIBILITY_ANIMATION_CONTROL)
    WebPageProxy_IsAnyAnimationAllowedToPlayDidChange,
#endif
    WebPageProxy_IsPlayingMediaDidChange,
#if PLATFORM(IOS_FAMILY)
    WebPageProxy_IsPotentialTapInProgress,
#endif
    WebPageProxy_LearnWord,
    WebPageProxy_LogDiagnosticMessageFromWebProcess,
    WebPageProxy_LogDiagnosticMessageWithDomainFromWebProcess,
    WebPageProxy_LogDiagnosticMessageWithEnhancedPrivacyFromWebProcess,
    WebPageProxy_LogDiagnosticMessageWithResultFromWebProcess,
    WebPageProxy_LogDiagnosticMessageWithValueDictionaryFromWebProcess,
    WebPageProxy_LogDiagnosticMessageWithValueFromWebProcess,
    WebPageProxy_LogScrollingEvent,
    WebPageProxy_MainFramePluginHandlesPageScaleGestureDidChange,
#if PLATFORM(COCOA)
    WebPageProxy_MakeFirstResponder,
#endif
#if ENABLE(WIRELESS_PLAYBACK_TARGET) && !PLATFORM(IOS_FAMILY)
    WebPageProxy_MockMediaPlaybackTargetPickerDismissPopup,
#endif
#if ENABLE(ARKIT_INLINE_PREVIEW)
    WebPageProxy_ModelElementAnimationCurrentTime,
    WebPageProxy_ModelElementAnimationDuration,
#endif
#if ENABLE(ARKIT_INLINE_PREVIEW_MAC)
    WebPageProxy_ModelElementCreateRemotePreview,
    WebPageProxy_ModelElementDestroyRemotePreview,
#endif
#if ENABLE(ARKIT_INLINE_PREVIEW)
    WebPageProxy_ModelElementGetCamera,
    WebPageProxy_ModelElementHasAudio,
    WebPageProxy_ModelElementIsLoopingAnimation,
    WebPageProxy_ModelElementIsMuted,
    WebPageProxy_ModelElementIsPlayingAnimation,
#endif
#if ENABLE(ARKIT_INLINE_PREVIEW_MAC)
    WebPageProxy_ModelElementLoadRemotePreview,
#endif
#if ENABLE(ARKIT_INLINE_PREVIEW)
    WebPageProxy_ModelElementSetAnimationCurrentTime,
    WebPageProxy_ModelElementSetAnimationIsPlaying,
    WebPageProxy_ModelElementSetCamera,
#endif
#if ENABLE(ARKIT_INLINE_PREVIEW_IOS)
    WebPageProxy_ModelElementSetInteractionEnabled,
#endif
#if ENABLE(ARKIT_INLINE_PREVIEW)
    WebPageProxy_ModelElementSetIsLoopingAnimation,
    WebPageProxy_ModelElementSetIsMuted,
#endif
#if ENABLE(ARKIT_INLINE_PREVIEW_MAC)
    WebPageProxy_ModelElementSizeDidChange,
    WebPageProxy_ModelInlinePreviewUUIDs,
#endif
    WebPageProxy_MouseDidMoveOverElement,
    WebPageProxy_NotifyScrollerThumbIsVisibleInRect,
    WebPageProxy_NowPlayingMetadataChanged,
    WebPageProxy_PageDidScroll,
    WebPageProxy_PageExtendedBackgroundColorDidChange,
    WebPageProxy_PageScaleFactorDidChange,
    WebPageProxy_PerformSwitchHapticFeedback,
#if ENABLE(WIRELESS_PLAYBACK_TARGET) && !PLATFORM(IOS_FAMILY)
    WebPageProxy_PlaybackTargetPickerClientStateDidChange,
#endif
    WebPageProxy_PluginScaleFactorDidChange,
    WebPageProxy_PluginZoomFactorDidChange,
    WebPageProxy_PostMessageToRemote,
#if ENABLE(WRITING_TOOLS)
    WebPageProxy_ProofreadingSessionShowDetailsForSuggestionWithIDRelativeToRect,
    WebPageProxy_ProofreadingSessionUpdateStateForSuggestionWithID,
#endif
    WebPageProxy_RecommendedScrollbarStyleDidChange,
#if PLATFORM(MAC)
    WebPageProxy_RecordAutocorrectionResponse,
#endif
#if ENABLE(ATTACHMENT_ELEMENT)
    WebPageProxy_RegisterAttachmentIdentifier,
    WebPageProxy_RegisterAttachmentIdentifierFromData,
    WebPageProxy_RegisterAttachmentIdentifierFromFilePath,
    WebPageProxy_RegisterAttachmentsFromSerializedData,
#endif
    WebPageProxy_RegisterEditCommandForUndo,
    WebPageProxy_RegisterInsertionUndoGrouping,
#if PLATFORM(COCOA)
    WebPageProxy_RegisterWebProcessAccessibilityToken,
#endif
#if PLATFORM(IOS_FAMILY)
    WebPageProxy_RelayAccessibilityNotification,
#endif
#if USE(DICTATION_ALTERNATIVES)
    WebPageProxy_RemoveDictationAlternatives,
#endif
#if ENABLE(MEDIA_USAGE)
    WebPageProxy_RemoveMediaUsageManagerSession,
#endif
#if ENABLE(PDF_HUD)
    WebPageProxy_RemovePDFHUD,
#endif
#if ENABLE(PDF_PAGE_NUMBER_INDICATOR)
    WebPageProxy_RemovePDFPageNumberIndicator,
#endif
#if ENABLE(WIRELESS_PLAYBACK_TARGET) && !PLATFORM(IOS_FAMILY)
    WebPageProxy_RemovePlaybackTargetPickerClient,
#endif
#if ENABLE(WRITING_TOOLS)
    WebPageProxy_RemoveTextAnimationForAnimationID,
#endif
#if ENABLE(ATTACHMENT_ELEMENT)
    WebPageProxy_RequestAttachmentIcon,
#endif
    WebPageProxy_RequestCheckingOfString,
    WebPageProxy_RequestCookieConsent,
    WebPageProxy_RequestGeolocationPermissionForFrame,
#if ENABLE(ENCRYPTED_MEDIA)
    WebPageProxy_RequestMediaKeySystemPermissionForFrame,
#endif
    WebPageProxy_RequestNotificationPermission,
#if USE(QUICK_LOOK)
    WebPageProxy_RequestPasswordForQuickLookDocumentInMainFrame,
#endif
#if ENABLE(POINTER_LOCK)
    WebPageProxy_RequestPointerLock,
    WebPageProxy_RequestPointerUnlock,
#endif
    WebPageProxy_RequestScrollToRect,
#if ENABLE(IMAGE_ANALYSIS)
    WebPageProxy_RequestTextRecognition,
#endif
#if ENABLE(MEDIA_STREAM)
    WebPageProxy_RequestUserMediaPermissionForFrame,
#endif
    WebPageProxy_ResolveAccessibilityHitTestForTesting,
#if PLATFORM(IOS_FAMILY)
    WebPageProxy_RestorePageCenterAndScale,
    WebPageProxy_RestorePageState,
#endif
    WebPageProxy_RevokeGeolocationAuthorizationToken,
    WebPageProxy_RunModal,
    WebPageProxy_RunOpenPanel,
    WebPageProxy_SampledPageTopColorChanged,
#if PLATFORM(IOS_FAMILY)
    WebPageProxy_SaveImageToLibrary,
#endif
    WebPageProxy_SaveRecentSearches,
#if PLATFORM(IOS_FAMILY)
    WebPageProxy_ScrollingNodeScrollDidEndScroll,
    WebPageProxy_ScrollingNodeScrollWillStartScroll,
#endif
#if PLATFORM(COCOA)
    WebPageProxy_SearchTheWeb,
#endif
    WebPageProxy_SendMessageToInspectorFrontend,
#if PLATFORM(GTK) || PLATFORM(WPE)
    WebPageProxy_SendMessageToWebView,
    WebPageProxy_SendMessageToWebViewWithReply,
#endif
    WebPageProxy_SetAllowsLayoutViewportHeightExpansion,
    WebPageProxy_SetCanShortCircuitHorizontalWheelEvents,
    WebPageProxy_SetColorPickerColor,
    WebPageProxy_SetCursor,
    WebPageProxy_SetCursorHiddenUntilMouseMoves,
#if ENABLE(DATA_DETECTION)
    WebPageProxy_SetDataDetectionResult,
#endif
#if PLATFORM(MAC)
    WebPageProxy_SetEditableElementIsFocused,
#endif
    WebPageProxy_SetFocus,
    WebPageProxy_SetHasActiveAnimatedScrolls,
    WebPageProxy_SetHasExecutedAppBoundBehaviorBeforeNavigation,
    WebPageProxy_SetHasFocusedElementWithUserInteraction,
#if PLATFORM(GTK) || PLATFORM(WPE)
    WebPageProxy_SetInputMethodState,
#endif
#if HAVE(TOUCH_BAR)
    WebPageProxy_SetIsNeverRichlyEditableForTouchBar,
#endif
    WebPageProxy_SetIsResizable,
#if HAVE(TOUCH_BAR)
    WebPageProxy_SetIsTouchBarUpdateSuppressedForHiddenContentEditable,
#endif
    WebPageProxy_SetMenuBarIsVisible,
#if ENABLE(WIRELESS_PLAYBACK_TARGET) && !PLATFORM(IOS_FAMILY)
    WebPageProxy_SetMockMediaPlaybackTargetPickerEnabled,
    WebPageProxy_SetMockMediaPlaybackTargetPickerState,
#endif
#if ENABLE(VIDEO_PRESENTATION_MODE)
    WebPageProxy_SetMockVideoPresentationModeEnabled,
#endif
#if ENABLE(WEB_AUTHN)
    WebPageProxy_SetMockWebAuthenticationConfiguration,
#endif
    WebPageProxy_SetNetworkRequestsInProgress,
#if PLATFORM(COCOA) && ENABLE(DRAG_SUPPORT)
    WebPageProxy_SetPromisedDataForImage,
#endif
    WebPageProxy_SetRenderTreeSize,
#if ENABLE(MEDIA_STREAM)
    WebPageProxy_SetShouldListenToVoiceActivity,
#endif
    WebPageProxy_SetStatusBarIsVisible,
    WebPageProxy_SetTextIndicatorFromFrame,
    WebPageProxy_SetToolbarsAreVisible,
    WebPageProxy_SetWindowFrame,
#if ENABLE(DEVICE_ORIENTATION)
    WebPageProxy_ShouldAllowDeviceOrientationAndMotionAccess,
#endif
    WebPageProxy_ShouldGoToBackForwardListItem,
    WebPageProxy_ShowColorPicker,
    WebPageProxy_ShowContactPicker,
#if ENABLE(CONTEXT_MENUS)
    WebPageProxy_ShowContextMenuFromFrame,
#endif
#if PLATFORM(MAC)
    WebPageProxy_ShowCorrectionPanel,
#endif
#if PLATFORM(IOS_FAMILY)
    WebPageProxy_ShowDataDetectorsUIForPositionInformation,
#endif
    WebPageProxy_ShowDataListSuggestions,
    WebPageProxy_ShowDateTimePicker,
#if USE(DICTATION_ALTERNATIVES)
    WebPageProxy_ShowDictationAlternativeUI,
#endif
#if HAVE(DIGITAL_CREDENTIALS_UI)
    WebPageProxy_ShowDigitalCredentialsPicker,
#endif
#if PLATFORM(GTK)
    WebPageProxy_ShowEmojiPicker,
#endif
#if PLATFORM(IOS_FAMILY)
    WebPageProxy_ShowInspectorHighlight,
    WebPageProxy_ShowInspectorIndication,
#endif
#if ENABLE(MEDIA_CONTROLS_CONTEXT_MENUS) && USE(UICONTEXTMENU)
    WebPageProxy_ShowMediaControlsContextMenu,
#endif
#if ENABLE(PDF_PLUGIN) && PLATFORM(MAC)
    WebPageProxy_ShowPDFContextMenu,
#endif
    WebPageProxy_ShowPage,
#if PLATFORM(IOS_FAMILY) || ENABLE(WIRELESS_PLAYBACK_TARGET) && !PLATFORM(IOS_FAMILY)
    WebPageProxy_ShowPlaybackTargetPicker,
#endif
    WebPageProxy_ShowPopupMenuFromFrame,
    WebPageProxy_ShowShareSheet,
#if (ENABLE(TELEPHONE_NUMBER_DETECTION) && PLATFORM(MAC))
    WebPageProxy_ShowTelephoneNumberMenu,
#endif
#if PLATFORM(COCOA) || PLATFORM(GTK)
    WebPageProxy_ShowValidationMessage,
#endif
#if ENABLE(WEB_PAGE_SPATIAL_BACKDROP)
    WebPageProxy_SpatialBackdropSourceChanged,
#endif
#if ENABLE(SPEECH_SYNTHESIS)
    WebPageProxy_SpeechSynthesisCancel,
    WebPageProxy_SpeechSynthesisPause,
    WebPageProxy_SpeechSynthesisResetState,
    WebPageProxy_SpeechSynthesisResume,
    WebPageProxy_SpeechSynthesisSetFinishedCallback,
    WebPageProxy_SpeechSynthesisSpeak,
#endif
#if ENABLE(APPLE_PAY_AMS_UI)
    WebPageProxy_StartApplePayAMSUISession,
#endif
#if PLATFORM(COCOA) && ENABLE(DRAG_SUPPORT) || (PLATFORM(GTK) || PLATFORM(WPE)) && ENABLE(DRAG_SUPPORT)
    WebPageProxy_StartDrag,
#endif
    WebPageProxy_StartNetworkRequestsForPageLoadTiming,
    WebPageProxy_StartURLSchemeTask,
    WebPageProxy_StopURLSchemeTask,
    WebPageProxy_TakeFocus,
#if ENABLE(ARKIT_INLINE_PREVIEW_IOS)
    WebPageProxy_TakeModelElementFullscreen,
#endif
#if PLATFORM(MAC) || PLATFORM(WPE) || PLATFORM(GTK)
    WebPageProxy_ThemeColorChanged,
#endif
#if PLATFORM(IOS_FAMILY)
    WebPageProxy_UpdateFocusedElementInformation,
    WebPageProxy_UpdateInputContextAfterBlurringAndRefocusingElement,
#endif
#if ENABLE(MEDIA_USAGE)
    WebPageProxy_UpdateMediaUsageManagerSessionState,
#endif
    WebPageProxy_UpdateOpener,
#if ENABLE(PDF_HUD)
    WebPageProxy_UpdatePDFHUDLocation,
#endif
#if ENABLE(PDF_PAGE_NUMBER_INDICATOR)
    WebPageProxy_UpdatePDFPageNumberIndicatorCurrentPage,
    WebPageProxy_UpdatePDFPageNumberIndicatorLocation,
#endif
    WebPageProxy_UpdateRemoteFrameAccessibilityOffset,
    WebPageProxy_UpdateSandboxFlags,
    WebPageProxy_UpdateScrollingMode,
    WebPageProxy_UpdateSpellingUIWithGrammarString,
    WebPageProxy_UpdateSpellingUIWithMisspelledWord,
#if PLATFORM(IOS_FAMILY)
    WebPageProxy_UpdateStringForFind,
#endif
    WebPageProxy_UpdateTextIndicatorFromFrame,
    WebPageProxy_UseFixedLayoutDidChange,
#if ENABLE(MEDIA_STREAM)
    WebPageProxy_ValidateCaptureStateUpdate,
#endif
    WebPageProxy_ViewScaleFactorDidChange,
    WebPageProxy_WillPerformClientRedirectForFrame,
#if PLATFORM(IOS_FAMILY) && ENABLE(DRAG_SUPPORT)
    WebPageProxy_WillReceiveEditDragSnapshot,
#endif
    WebPageProxy_WillSubmitForm,
#if (ENABLE(ATTACHMENT_ELEMENT) && PLATFORM(IOS_FAMILY))
    WebPageProxy_WritePromisedAttachmentToPasteboard,
#endif
#if USE(AUTOMATIC_TEXT_REPLACEMENT)
    WebPageProxy_toggleAutomaticDashSubstitution,
    WebPageProxy_toggleAutomaticLinkDetection,
    WebPageProxy_toggleAutomaticQuoteSubstitution,
    WebPageProxy_toggleAutomaticTextReplacement,
    WebPageProxy_toggleSmartInsertDelete,
#endif
    WebPageTesting_ClearCachedBackForwardListCounts,
#if ENABLE(NOTIFICATIONS)
    WebPageTesting_ClearNotificationPermissionState,
#endif
    WebPageTesting_ClearWheelEventTestMonitor,
    WebPageTesting_DisplayAndTrackRepaints,
    WebPageTesting_IsLayerTreeFrozen,
    WebPageTesting_ResetStateBetweenTests,
    WebPageTesting_SetObscuredContentInsets,
    WebPageTesting_SetPermissionLevel,
    WebPageTesting_SetTracksRepaints,
    WebPage_AccessibilitySettingsDidChange,
    WebPage_AddConsoleMessage,
#if PLATFORM(COCOA)
    WebPage_AddDictationAlternative,
#endif
    WebPage_AddLayerForFindOverlay,
    WebPage_AdjustVisibilityForTargetedElements,
    WebPage_AdvanceToNextMisspelling,
#if (ENABLE(GAMEPAD) && PLATFORM(VISION))
    WebPage_AllowGamepadAccess,
#endif
#if PLATFORM(IOS_FAMILY)
    WebPage_ApplicationDidBecomeActive,
    WebPage_ApplicationDidEnterBackground,
    WebPage_ApplicationDidEnterBackgroundForMedia,
    WebPage_ApplicationDidFinishSnapshottingAfterEnteringBackground,
    WebPage_ApplicationWillEnterForeground,
    WebPage_ApplicationWillEnterForegroundForMedia,
    WebPage_ApplicationWillResignActive,
    WebPage_ApplyAutocorrection,
    WebPage_AttemptSyntheticClick,
#endif
#if PLATFORM(MAC)
    WebPage_AttributedSubstringForCharacterRangeAsync,
#endif
#if PLATFORM(IOS_FAMILY)
    WebPage_AutofillLoginCredentials,
#endif
    WebPage_BeginPrinting,
    WebPage_BeginPrintingDuringDOMPrintOperation,
#if PLATFORM(IOS_FAMILY)
    WebPage_BeginSelectionInDirection,
    WebPage_BlurFocusedElement,
#endif
#if ENABLE(SPEECH_SYNTHESIS)
    WebPage_BoundaryEventOccurred,
#endif
#if PLATFORM(IOS_FAMILY)
    WebPage_CancelAutoscroll,
#endif
#if PLATFORM(GTK) || PLATFORM(WPE)
    WebPage_CancelComposition,
#endif
    WebPage_CancelPointer,
#if PLATFORM(IOS_FAMILY)
    WebPage_CancelPotentialTap,
#endif
#if USE(APPKIT)
    WebPage_CapitalizeWord,
#endif
#if ENABLE(MEDIA_STREAM)
    WebPage_CaptureDevicesChanged,
#endif
    WebPage_CenterSelectionInVisibleArea,
    WebPage_ChangeFont,
    WebPage_ChangeFontAttributes,
    WebPage_ChangeListType,
    WebPage_ChangeSpellingToWord,
#if PLATFORM(COCOA)
    WebPage_CharacterIndexForPointAsync,
#endif
#if (PLATFORM(MAC) && ENABLE(ACCESSIBILITY_ISOLATED_TREE))
    WebPage_ClearAccessibilityIsolatedTree,
#endif
    WebPage_ClearAllDecoratedFoundText,
#if PLATFORM(COCOA)
    WebPage_ClearDictationAlternatives,
#endif
    WebPage_ClearLoadedSubresourceDomains,
    WebPage_ClearSelection,
#if PLATFORM(IOS_FAMILY)
    WebPage_ClearSelectionAfterTappingSelectionHighlightIfNeeded,
    WebPage_ClearServiceWorkerEntitlementOverride,
#endif
    WebPage_Close,
    WebPage_CloseCurrentTypingCommand,
#if PLATFORM(GTK)
    WebPage_CollapseSelectionInFrame,
#endif
#if PLATFORM(IOS_FAMILY)
    WebPage_CommitPotentialTap,
#endif
    WebPage_CompleteTextManipulation,
#if ENABLE(WRITING_TOOLS)
    WebPage_CompositionSessionDidReceiveTextWithReplacementRange,
#endif
    WebPage_ComputePagesForPrinting,
    WebPage_ComputePagesForPrintingDuringDOMPrintOperation,
#if PLATFORM(COCOA)
    WebPage_ConfirmCompositionAsync,
#endif
    WebPage_ConnectInspector,
#if PLATFORM(IOS_FAMILY)
    WebPage_ContentSizeCategoryDidChange,
#endif
    WebPage_ContentsToRootViewPoint,
    WebPage_ContentsToRootViewRect,
#if ENABLE(CONTEXT_MENUS)
    WebPage_ContextMenuForKeyEvent,
#endif
    WebPage_CopyLinkWithHighlight,
    WebPage_CountStringMatches,
#if ENABLE(APP_HIGHLIGHTS)
    WebPage_CreateAppHighlightInSelectedRange,
#endif
#if PLATFORM(COCOA)
    WebPage_CreateBitmapsFromImageData,
#endif
#if ENABLE(MEDIA_SESSION_COORDINATOR)
    WebPage_CreateMediaSessionCoordinator,
#endif
    WebPage_CreateRemoteSubframe,
    WebPage_CreateTextFragmentDirectiveFromSelection,
#if PLATFORM(COCOA)
    WebPage_CreateTextIndicatorForElementWithID,
#endif
#if ENABLE(WRITING_TOOLS)
    WebPage_CreateTextIndicatorForTextAnimationID,
#endif
#if PLATFORM(MAC)
    WebPage_DataDetectorsDidChangeUI,
    WebPage_DataDetectorsDidHideUI,
    WebPage_DataDetectorsDidPresentUI,
#endif
#if PLATFORM(COCOA)
    WebPage_DecodeImageData,
#endif
    WebPage_DecorateTextRangeWithStyle,
#if ENABLE(WRITING_TOOLS)
    WebPage_DecorateTextReplacementsForActiveWritingToolsSession,
#endif
    WebPage_DecreaseListLevel,
#if PLATFORM(GTK) || PLATFORM(WPE)
    WebPage_DeleteSurrounding,
#endif
#if ENABLE(DATA_DETECTION)
    WebPage_DetectDataInAllFrames,
#endif
#if PLATFORM(COCOA)
    WebPage_DictationAlternativesAtSelection,
#endif
#if PLATFORM(MAC)
    WebPage_DidBeginMagnificationGesture,
#endif
    WebPage_DidBeginTextSearchOperation,
#if ENABLE(IOS_TOUCH_EVENTS)
    WebPage_DidBeginTouchPoint,
#endif
#if ENABLE(WRITING_TOOLS)
    WebPage_DidBeginWritingToolsSession,
#endif
    WebPage_DidCancelCheckingText,
    WebPage_DidCancelForOpenPanel,
    WebPage_DidChangeSelectedIndexForActivePopupMenu,
    WebPage_DidChooseColor,
    WebPage_DidChooseDate,
    WebPage_DidChooseFilesForOpenPanel,
#if PLATFORM(IOS_FAMILY)
    WebPage_DidChooseFilesForOpenPanelWithDisplayStringAndIcon,
#endif
    WebPage_DidCloseSuggestions,
#if PLATFORM(IOS_FAMILY) && ENABLE(DRAG_SUPPORT)
    WebPage_DidConcludeDrop,
#endif
#if ENABLE(CONTEXT_MENUS)
    WebPage_DidDismissContextMenu,
#endif
    WebPage_DidEndColorPicker,
#if USE(UICONTEXTMENU)
    WebPage_DidEndContextMenuInteraction,
#endif
    WebPage_DidEndDateTimePicker,
#if PLATFORM(MAC)
    WebPage_DidEndMagnificationGesture,
#endif
#if PLATFORM(IOS_FAMILY)
    WebPage_DidEndUserTriggeredZooming,
#endif
#if ENABLE(WRITING_TOOLS)
    WebPage_DidEndWritingToolsSession,
#endif
    WebPage_DidFinishCheckingText,
    WebPage_DidFinishLoadInAnotherProcess,
    WebPage_DidGetLoadDecisionForIcon,
#if PLATFORM(IOS_FAMILY)
    WebPage_DidInsertFinalDictationResult,
#endif
#if ENABLE(POINTER_LOCK)
    WebPage_DidLosePointerLock,
#endif
#if ENABLE(GEOLOCATION)
    WebPage_DidReceiveGeolocationPermissionDecision,
#endif
#if PLATFORM(IOS_FAMILY)
    WebPage_DidRecognizeLongPress,
    WebPage_DidReleaseAllTouchPoints,
#endif
    WebPage_DidRemoveBackForwardItem,
    WebPage_DidRemoveEditCommand,
    WebPage_DidScalePage,
    WebPage_DidScalePageInViewCoordinates,
    WebPage_DidScalePageRelativeToScrollPosition,
    WebPage_DidScaleView,
    WebPage_DidSelectDataListOption,
#if ENABLE(CONTEXT_MENUS)
    WebPage_DidSelectItemFromActiveContextMenu,
#endif
    WebPage_DidSetPageZoomFactor,
    WebPage_DidSetTextZoomFactor,
#if ENABLE(DRAG_SUPPORT)
    WebPage_DidStartDrag,
#endif
    WebPage_DisconnectInspector,
    WebPage_DispatchLoadEventToFrameOwnerElement,
#if PLATFORM(IOS_FAMILY)
    WebPage_DispatchWheelEventWithoutScrolling,
#endif
#if ENABLE(DRAG_SUPPORT)
    WebPage_DragCancelled,
    WebPage_DragEnded,
#endif
#if PLATFORM(GTK)
    WebPage_DrawPagesForPrinting,
    WebPage_DrawPagesForPrintingDuringDOMPrintOperation,
#endif
#if PLATFORM(COCOA)
    WebPage_DrawPagesToPDF,
    WebPage_DrawPagesToPDFDuringDOMPrintOperation,
    WebPage_DrawRectToImage,
    WebPage_DrawRectToImageDuringDOMPrintOperation,
    WebPage_DrawRemoteToPDF,
#endif
#if (PLATFORM(COCOA) && PLATFORM(IOS_FAMILY))
    WebPage_DrawToImage,
#endif
#if PLATFORM(COCOA)
    WebPage_DrawToPDF,
#endif
#if (PLATFORM(COCOA) && PLATFORM(IOS_FAMILY))
    WebPage_DrawToPDFiOS,
#endif
#if PLATFORM(IOS_FAMILY)
    WebPage_DynamicViewportSizeUpdate,
#endif
    WebPage_EnableAccessibility,
    WebPage_EndPrinting,
    WebPage_EndPrintingDuringDOMPrintOperation,
    WebPage_EnqueueSecurityPolicyViolationEvent,
    WebPage_ExecuteEditCommand,
    WebPage_ExecuteEditCommandWithCallback,
#if ENABLE(SANDBOX_EXTENSIONS)
    WebPage_ExtendSandboxForFilesFromOpenPanel,
#endif
#if PLATFORM(IOS_FAMILY)
    WebPage_ExtendSelection,
    WebPage_ExtendSelectionForReplacement,
#endif
#if PLATFORM(GTK)
    WebPage_FailedToShowPopupMenu,
#endif
    WebPage_FindRectsForStringMatches,
    WebPage_FindString,
#if ENABLE(IMAGE_ANALYSIS)
    WebPage_FindStringIncludingImages,
#endif
    WebPage_FindStringMatches,
    WebPage_FindTextRangesForStringMatches,
#if PLATFORM(COCOA)
    WebPage_FirstRectForCharacterRangeAsync,
#endif
    WebPage_FlushDeferredDidReceiveMouseEvent,
    WebPage_FlushDeferredResizeEvents,
    WebPage_FlushDeferredScrollEvents,
#if PLATFORM(IOS_FAMILY)
    WebPage_FocusNextFocusedElement,
    WebPage_FocusTextInputContextAndPlaceCaret,
#endif
    WebPage_FrameNameWasChangedInAnotherProcess,
    WebPage_FrameWasFocusedInAnotherProcess,
    WebPage_FrameWasRemovedInAnotherProcess,
#if ENABLE(GAMEPAD)
    WebPage_GamepadActivity,
#endif
#if PLATFORM(IOS_FAMILY)
    WebPage_GenerateSyntheticEditingCommand,
#endif
    WebPage_GenerateTestReport,
    WebPage_GetAccessibilityTreeData,
#if ENABLE(APPLICATION_MANIFEST)
    WebPage_GetApplicationManifest,
#endif
    WebPage_GetBytecodeProfile,
#if PLATFORM(COCOA)
    WebPage_GetContentsAsAttributedString,
#endif
#if ENABLE(MHTML)
    WebPage_GetContentsAsMHTMLData,
#endif
    WebPage_GetContentsAsString,
    WebPage_GetFrameTree,
    WebPage_GetImageForFindMatch,
#if PLATFORM(COCOA)
    WebPage_GetInformationFromImageData,
#endif
    WebPage_GetLoadedSubresourceDomains,
    WebPage_GetMainResourceDataOfFrame,
#if PLATFORM(COCOA)
    WebPage_GetMarkedRangeAsync,
#endif
    WebPage_GetPDFFirstPageSize,
    WebPage_GetProcessDisplayName,
#if PLATFORM(IOS_FAMILY)
    WebPage_GetRectsAtSelectionOffsetWithText,
    WebPage_GetRectsForGranularityWithSelectionOffset,
#endif
    WebPage_GetRenderTreeExternalRepresentation,
    WebPage_GetResourceDataFromFrame,
    WebPage_GetSamplingProfilerOutput,
#if PLATFORM(COCOA)
    WebPage_GetSelectedRangeAsync,
#endif
    WebPage_GetSelectionAsWebArchiveData,
#if PLATFORM(IOS_FAMILY)
    WebPage_GetSelectionContext,
#endif
    WebPage_GetSelectionOrContentsAsString,
    WebPage_GetSourceForFrame,
    WebPage_GetTextFragmentMatch,
    WebPage_GetTextFragmentRanges,
    WebPage_GetWebArchiveOfFrame,
    WebPage_GetWebArchiveOfFrameWithFileName,
#if PLATFORM(COCOA)
    WebPage_GetWebArchives,
#endif
    WebPage_GoToBackForwardItem,
    WebPage_GoToBackForwardItemWaitingForProcessLaunch,
#if PLATFORM(MAC)
    WebPage_HandleAcceptedCandidate,
#endif
#if PLATFORM(COCOA)
    WebPage_HandleAlternativeTextUIResult,
#endif
#if PLATFORM(IOS_FAMILY)
    WebPage_HandleAutocorrectionContextRequest,
    WebPage_HandleDoubleTapForDoubleClickAtPoint,
    WebPage_HandleTwoFingerTapAtPoint,
#endif
    WebPage_HandleWheelEvent,
#if PLATFORM(IOS_FAMILY)
    WebPage_HardwareKeyboardAvailabilityChanged,
#endif
#if PLATFORM(COCOA)
    WebPage_HasMarkedText,
#endif
    WebPage_HideFindUI,
#if PLATFORM(MAC)
    WebPage_ImmediateActionDidCancel,
    WebPage_ImmediateActionDidComplete,
    WebPage_ImmediateActionDidUpdate,
#endif
    WebPage_IncreaseListLevel,
    WebPage_IndicateFindMatch,
#if ENABLE(ATTACHMENT_ELEMENT)
    WebPage_InsertAttachment,
#endif
#if PLATFORM(COCOA)
    WebPage_InsertDictatedTextAsync,
#endif
#if PLATFORM(IOS_FAMILY) && ENABLE(DRAG_SUPPORT)
    WebPage_InsertDroppedImagePlaceholders,
#endif
#if (PLATFORM(COCOA) && ENABLE(MULTI_REPRESENTATION_HEIC))
    WebPage_InsertMultiRepresentationHEIC,
#endif
#if PLATFORM(COCOA)
    WebPage_InsertTextAsync,
    WebPage_InsertTextPlaceholder,
#endif
#if PLATFORM(IOS_FAMILY)
    WebPage_InspectorNodeSearchEndedAtPosition,
    WebPage_InspectorNodeSearchMovedToPosition,
#endif
#if ENABLE(WRITING_TOOLS)
    WebPage_IntelligenceTextAnimationsDidComplete,
#endif
    WebPage_KeyEvent,
    WebPage_LastNavigationWasAppInitiated,
    WebPage_ListenForLayoutMilestones,
    WebPage_LoadAlternateHTML,
    WebPage_LoadAndDecodeImage,
    WebPage_LoadData,
    WebPage_LoadDataInFrame,
    WebPage_LoadDidCommitInAnotherProcess,
    WebPage_LoadRequest,
    WebPage_LoadRequestWaitingForProcessLaunch,
    WebPage_LoadSimulatedRequestAndResponse,
    WebPage_LoadURLInFrame,
#if USE(APPKIT)
    WebPage_LowercaseWord,
#endif
#if ENABLE(ENCRYPTED_MEDIA)
    WebPage_MediaKeySystemWasDenied,
    WebPage_MediaKeySystemWasGranted,
#endif
#if ENABLE(MODEL_PROCESS) && ENABLE(DRAG_SUPPORT)
    WebPage_ModelDragEnded,
#endif
#if ENABLE(ARKIT_INLINE_PREVIEW_IOS)
    WebPage_ModelInlinePreviewDidFailToLoad,
    WebPage_ModelInlinePreviewDidLoad,
#endif
    WebPage_MouseEvent,
#if PLATFORM(IOS_FAMILY)
    WebPage_MoveSelectionAtBoundaryWithDirection,
    WebPage_MoveSelectionByOffset,
#endif
    WebPage_NavigateServiceWorkerClient,
    WebPage_NavigateToPDFLinkWithSimulatedClick,
    WebPage_NotifyReportObservers,
    WebPage_NumberOfVisibilityAdjustmentRects,
#if ENABLE(PDF_PLUGIN) && PLATFORM(MAC)
    WebPage_OpenPDFWithPreview,
#endif
#if ENABLE(ACCESSIBILITY_ANIMATION_CONTROL)
    WebPage_PauseAllAnimations,
#endif
    WebPage_PauseAllMediaPlayback,
#if PLATFORM(IOS_FAMILY)
    WebPage_PerformActionOnElement,
    WebPage_PerformActionOnElements,
#endif
#if PLATFORM(COCOA)
    WebPage_PerformDictionaryLookupAtLocation,
#endif
#if PLATFORM(GTK) && ENABLE(DRAG_SUPPORT) || !PLATFORM(GTK) && ENABLE(DRAG_SUPPORT)
    WebPage_PerformDragControllerAction,
#endif
#if !PLATFORM(GTK) && ENABLE(DRAG_SUPPORT)
    WebPage_PerformDragOperation,
#endif
    WebPage_PerformHitTestForMouseEvent,
#if PLATFORM(MAC)
    WebPage_PerformImmediateActionHitTestAtLocation,
#endif
#if ENABLE(ACCESSIBILITY_ANIMATION_CONTROL)
    WebPage_PlayAllAnimations,
#endif
#if ENABLE(WIRELESS_PLAYBACK_TARGET) && !PLATFORM(IOS_FAMILY)
    WebPage_PlaybackTargetAvailabilityDidChange,
    WebPage_PlaybackTargetPickerWasDismissed,
    WebPage_PlaybackTargetSelected,
#endif
    WebPage_PostInjectedBundleMessage,
#if PLATFORM(IOS_FAMILY)
    WebPage_PotentialTapAtPosition,
#endif
    WebPage_PreferencesDidChange,
    WebPage_PreferencesDidChangeDuringDOMPrintOperation,
#if PLATFORM(WPE) && USE(GBM) && ENABLE(WPE_PLATFORM)
    WebPage_PreferredBufferFormatsDidChange,
#endif
#if (PLATFORM(IOS_FAMILY) && ENABLE(REVEAL))
    WebPage_PrepareSelectionForContextMenuWithLocationInView,
#endif
    WebPage_ProcessDidResume,
    WebPage_ProcessSyncDataChangedInAnotherProcess,
    WebPage_ProcessWillSuspend,
#if ENABLE(WRITING_TOOLS)
    WebPage_ProofreadingSessionDidReceiveSuggestions,
    WebPage_ProofreadingSessionDidUpdateStateForSuggestion,
    WebPage_ProofreadingSessionSuggestionTextRectsInRootViewCoordinates,
#endif
    WebPage_ReapplyEditCommand,
#if PLATFORM(COCOA)
    WebPage_RegisterUIProcessAccessibilityTokens,
#endif
    WebPage_RegisterURLSchemeHandler,
    WebPage_Reload,
    WebPage_RemoteDictionaryPopupInfoToRootView,
    WebPage_RemotePostMessage,
#if ENABLE(DATA_DETECTION)
    WebPage_RemoveDataDetectedLinks,
#endif
    WebPage_RemoveLayerForFindOverlay,
#if PLATFORM(COCOA)
    WebPage_RemoveTextPlaceholder,
#endif
#if PLATFORM(IOS_FAMILY)
    WebPage_ReplaceDictatedText,
#endif
    WebPage_ReplaceFoundTextRangeWithString,
#if ENABLE(IMAGE_ANALYSIS_ENHANCEMENTS)
    WebPage_ReplaceImageForRemoveBackground,
#endif
    WebPage_ReplaceMatches,
#if PLATFORM(IOS_FAMILY)
    WebPage_ReplaceSelectedText,
#endif
#if PLATFORM(COCOA)
    WebPage_ReplaceSelectionWithPasteboardData,
#endif
#if PLATFORM(MAC)
    WebPage_RequestAcceptsFirstMouse,
#endif
#if PLATFORM(COCOA)
    WebPage_RequestActiveNowPlayingSessionInfo,
#endif
#if PLATFORM(IOS_FAMILY) && ENABLE(DRAG_SUPPORT)
    WebPage_RequestAdditionalItemsForDragSession,
#endif
    WebPage_RequestAllTargetableElements,
    WebPage_RequestAllTextAndRects,
#if PLATFORM(IOS_FAMILY)
    WebPage_RequestAutocorrectionData,
    WebPage_RequestDocumentEditingContext,
#endif
#if PLATFORM(IOS_FAMILY) && ENABLE(DRAG_SUPPORT)
    WebPage_RequestDragStart,
#endif
#if PLATFORM(IOS_FAMILY)
    WebPage_RequestEvasionRectsAboveSelection,
    WebPage_RequestFocusedElementInformation,
#endif
    WebPage_RequestFontAttributesAtSelectionStart,
    WebPage_RequestImageBitmap,
#if ENABLE(MODEL_PROCESS)
    WebPage_RequestInteractiveModelElementAtPoint,
#endif
    WebPage_RequestMediaPlaybackState,
#if PLATFORM(IOS_FAMILY)
    WebPage_RequestPositionInformation,
#endif
#if (PLATFORM(IOS_FAMILY) && ENABLE(REVEAL))
    WebPage_RequestRVItemInCurrentSelectedRange,
#endif
    WebPage_RequestRectForFoundTextRange,
    WebPage_RequestTargetedElement,
    WebPage_RequestTextExtraction,
    WebPage_ResetVisibilityAdjustmentsForTargetedElements,
    WebPage_ResolveAccessibilityHitTestForTesting,
#if ENABLE(APP_HIGHLIGHTS)
    WebPage_RestoreAppHighlightsAndScrollToIndex,
#endif
    WebPage_RestoreSelectionInFocusedEditableElement,
    WebPage_Resume,
    WebPage_ResumeActiveDOMObjectsAndAnimations,
    WebPage_ResumeAllMediaPlayback,
    WebPage_RunJavaScriptInFrameInScriptWorld,
#if ENABLE(PDF_PLUGIN) && PLATFORM(MAC)
    WebPage_SavePDF,
#endif
    WebPage_ScheduleFullEditorStateUpdate,
    WebPage_ScrollBy,
    WebPage_ScrollTextRangeToVisible,
    WebPage_ScrollToEdge,
    WebPage_ScrollToRect,
    WebPage_SelectAll,
    WebPage_SelectFindMatch,
#if PLATFORM(IOS_FAMILY)
    WebPage_SelectPositionAtBoundaryWithDirection,
    WebPage_SelectPositionAtPoint,
    WebPage_SelectTextWithGranularityAtPoint,
    WebPage_SelectWithGesture,
    WebPage_SelectWithTwoTouches,
    WebPage_SelectWordBackward,
#endif
#if PLATFORM(MAC)
    WebPage_SemanticContextDidChange,
#endif
    WebPage_SendMessageToTargetBackend,
#if PLATFORM(GTK) || PLATFORM(WPE)
    WebPage_SendMessageToWebProcessExtension,
    WebPage_SendMessageToWebProcessExtensionWithReply,
#endif
    WebPage_SendReportToEndpoints,
#if HAVE(APP_ACCENT_COLORS)
    WebPage_SetAccentColor,
#endif
    WebPage_SetActivityState,
#if ENABLE(ADVANCED_PRIVACY_PROTECTIONS)
    WebPage_SetAllowedQueryParametersForAdvancedPrivacyProtections,
#endif
#if PLATFORM(IOS_FAMILY)
    WebPage_SetAllowsMediaDocumentInlinePlayback,
#endif
    WebPage_SetAlwaysShowsHorizontalScroller,
    WebPage_SetAlwaysShowsVerticalScroller,
#if ENABLE(APP_HIGHLIGHTS)
    WebPage_SetAppHighlightsVisibility,
#endif
    WebPage_SetAutoSizingShouldExpandToViewHeight,
    WebPage_SetBackgroundColor,
    WebPage_SetBackgroundExtendsBeyondPage,
    WebPage_SetBaseWritingDirection,
    WebPage_SetCanRunBeforeUnloadConfirmPanel,
    WebPage_SetCanRunModal,
    WebPage_SetCanShowPlaceholder,
    WebPage_SetCanUseCredentialStorage,
#if PLATFORM(MAC)
    WebPage_SetCaretAnimatorType,
    WebPage_SetCaretBlinkingSuspended,
#endif
#if PLATFORM(COCOA)
    WebPage_SetCompositionAsync,
#endif
    WebPage_SetContentOffset,
    WebPage_SetControlledByAutomation,
    WebPage_SetCurrentHistoryItemForReattach,
    WebPage_SetCustomTextEncodingName,
#if HAVE(SPATIAL_TRACKING_LABEL)
    WebPage_SetDefaultSpatialTrackingLabel,
#endif
    WebPage_SetDefaultUnobscuredSize,
#if PLATFORM(IOS_FAMILY)
    WebPage_SetDeviceOrientation,
#endif
    WebPage_SetEditable,
    WebPage_SetEnableHorizontalRubberBanding,
    WebPage_SetEnableVerticalRubberBanding,
    WebPage_SetFixedLayoutSize,
#if PLATFORM(IOS_FAMILY)
    WebPage_SetFocusedElementSelectedIndex,
    WebPage_SetFocusedElementValue,
#endif
#if PLATFORM(MAC)
    WebPage_SetFooterBannerHeight,
#endif
#if PLATFORM(IOS_FAMILY)
    WebPage_SetForceAlwaysUserScalable,
#endif
    WebPage_SetGapBetweenPages,
    WebPage_SetHasCustomUserAgent,
    WebPage_SetHasResourceLoadClient,
#if PLATFORM(MAC)
    WebPage_SetHeaderBannerHeight,
#endif
#if ENABLE(REMOTE_INSPECTOR)
    WebPage_SetIndicating,
#endif
    WebPage_SetInitialFocus,
#if PLATFORM(IOS_FAMILY)
    WebPage_SetInsertionPointColor,
#endif
#if ENABLE(INTERACTION_REGIONS_IN_EVENT_REGION)
    WebPage_SetInteractionRegionsEnabled,
#endif
#if PLATFORM(IOS_FAMILY)
    WebPage_SetIsShowingInputViewForFocusedElement,
#endif
    WebPage_SetIsSuspended,
    WebPage_SetIsTakingSnapshotsForApplicationSuspension,
#if HAVE(UIKIT_RESIZABLE_WINDOWS)
    WebPage_SetIsWindowResizingEnabled,
#endif
    WebPage_SetLastKnownMousePosition,
#if ENABLE(ADVANCED_PRIVACY_PROTECTIONS)
    WebPage_SetLinkDecorationFilteringData,
#endif
#if PLATFORM(COCOA)
    WebPage_SetMainFrameIsScrollable,
#endif
    WebPage_SetMaximumUnobscuredSize,
    WebPage_SetMayStartMediaWhenInWindow,
#if ENABLE(EXTENSION_CAPABILITIES)
    WebPage_SetMediaEnvironment,
#endif
    WebPage_SetMediaVolume,
    WebPage_SetMinimumSizeForAutoLayout,
    WebPage_SetMinimumUnobscuredSize,
#if (ENABLE(MEDIA_STREAM) && USE(GSTREAMER))
    WebPage_SetMockCaptureDevicesInterrupted,
#endif
    WebPage_SetMuted,
    WebPage_SetNeedsDOMWindowResizeEvent,
    WebPage_SetNeedsFixedContainerEdgesUpdate,
    WebPage_SetNeedsFontAttributes,
    WebPage_SetNeedsScrollGeometryUpdates,
#if !PLATFORM(COCOA)
    WebPage_SetObscuredContentInsets,
#endif
#if PLATFORM(COCOA)
    WebPage_SetObscuredContentInsetsFenced,
#endif
#if (ENABLE(MEDIA_STREAM) && USE(GSTREAMER))
    WebPage_SetOrientationForMediaCapture,
#endif
    WebPage_SetOverriddenMediaType,
#if PLATFORM(IOS_FAMILY)
    WebPage_SetOverrideViewportArguments,
#endif
    WebPage_SetPageLength,
    WebPage_SetPaginationBehavesLikeColumns,
    WebPage_SetPaginationMode,
#if HAVE(AUDIT_TOKEN)
    WebPage_SetPresentingApplicationAuditTokenAndBundleIdentifier,
#endif
#if PLATFORM(IOS_FAMILY)
    WebPage_SetSceneIdentifier,
    WebPage_SetScreenIsBeingCaptured,
#endif
    WebPage_SetScrollPinningBehavior,
    WebPage_SetScrollbarOverlayStyle,
#if ENABLE(WRITING_TOOLS)
    WebPage_SetSelectionForActiveWritingToolsSession,
#endif
    WebPage_SetShouldDispatchFakeMouseMoveEvents,
#if ENABLE(WIRELESS_PLAYBACK_TARGET) && !PLATFORM(IOS_FAMILY)
    WebPage_SetShouldPlayToPlaybackTarget,
#endif
#if PLATFORM(IOS_FAMILY)
    WebPage_SetShouldRevealCurrentSelectionAfterInsertion,
#endif
    WebPage_SetShouldScaleViewToFitDocument,
    WebPage_SetShouldSuppressHDR,
    WebPage_SetSizeToContentAutoSizeMaximumSize,
#if PLATFORM(COCOA)
    WebPage_SetSmartInsertDeleteEnabled,
#endif
    WebPage_SetSuppressScrollbarAnimations,
#if PLATFORM(COCOA)
    WebPage_SetTextAsync,
#endif
    WebPage_SetTextForActivePopupMenu,
    WebPage_SetUnderPageBackgroundColorOverride,
    WebPage_SetUnderlayColor,
    WebPage_SetUseColorAppearance,
    WebPage_SetUseFixedLayout,
    WebPage_SetUseIconLoadingClient,
    WebPage_SetUserAgent,
    WebPage_SetUserInterfaceLayoutDirection,
#if PLATFORM(IOS_FAMILY)
    WebPage_SetViewportConfigurationViewLayoutSize,
#endif
    WebPage_SetViewportSizeForCSSViewportUnits,
#if PLATFORM(COCOA)
    WebPage_SetWritingSuggestion,
#endif
#if ENABLE(IMAGE_ANALYSIS_ENHANCEMENTS)
    WebPage_ShouldAllowRemoveBackground,
#endif
#if PLATFORM(IOS_FAMILY)
    WebPage_ShouldDismissKeyboardAfterTapAtPoint,
#endif
    WebPage_SimulateClickOverFirstMatchingTextInViewportWithUserInteraction,
    WebPage_SimulateDeviceOrientationChange,
#if ENABLE(SPEECH_SYNTHESIS)
    WebPage_SpeakingErrorOccurred,
#endif
#if ENABLE(MODEL_PROCESS)
    WebPage_StageModeSessionDidEnd,
    WebPage_StageModeSessionDidUpdate,
#endif
#if PLATFORM(IOS_FAMILY)
    WebPage_StartAutoscrollAtPosition,
#endif
    WebPage_StartDeferringResizeEvents,
    WebPage_StartDeferringScrollEvents,
#if PLATFORM(IOS_FAMILY)
    WebPage_StartInteractionWithElementContextOrPosition,
#endif
    WebPage_StartObservingNowPlayingMetadata,
#if ENABLE(VIDEO_PRESENTATION_MODE)
    WebPage_StartPlayingPredominantVideo,
#endif
    WebPage_StartTextManipulations,
#if ENABLE(IMAGE_ANALYSIS)
    WebPage_StartVisualTranslation,
#endif
#if PLATFORM(IOS_FAMILY)
    WebPage_StopInteraction,
#endif
    WebPage_StopLoading,
    WebPage_StopLoadingDueToProcessSwap,
    WebPage_StopMediaCapture,
    WebPage_StopObservingNowPlayingMetadata,
#if PLATFORM(IOS_FAMILY)
    WebPage_StoreSelectionForAccessibility,
#endif
    WebPage_Suspend,
    WebPage_SuspendActiveDOMObjectsAndAnimations,
    WebPage_SuspendAllMediaPlayback,
    WebPage_SwipeAnimationDidEnd,
    WebPage_SwipeAnimationDidStart,
#if USE(SYSTEM_PREVIEW)
    WebPage_SystemPreviewActionTriggered,
#endif
    WebPage_TakeSnapshot,
    WebPage_TakeSnapshotForTargetedElement,
#if PLATFORM(IOS_FAMILY)
    WebPage_TapHighlightAtPosition,
    WebPage_TextInputContextsInRect,
#endif
#if ENABLE(WRITING_TOOLS)
    WebPage_TextPreviewDataForActiveWritingToolsSession,
#endif
    WebPage_TopDocumentSyncDataChangedInAnotherProcess,
#if !ENABLE(IOS_TOUCH_EVENTS) && ENABLE(TOUCH_EVENTS)
    WebPage_TouchEvent,
#endif
    WebPage_TouchWithIdentifierWasRemoved,
#if (ENABLE(MEDIA_STREAM) && USE(GSTREAMER))
    WebPage_TriggerMockCaptureConfigurationChange,
#endif
    WebPage_TryClose,
    WebPage_TryRestoreScrollPosition,
    WebPage_URLSchemeTaskDidComplete,
    WebPage_URLSchemeTaskDidPerformRedirection,
    WebPage_URLSchemeTaskDidReceiveData,
    WebPage_URLSchemeTaskDidReceiveResponse,
    WebPage_URLSchemeTaskWillPerformRedirection,
    WebPage_UnapplyEditCommand,
#if ENABLE(ATTACHMENT_ELEMENT)
    WebPage_UpdateAttachmentAttributes,
    WebPage_UpdateAttachmentIcon,
#endif
    WebPage_UpdateCORSDisablingPatterns,
    WebPage_UpdateCurrentModifierState,
    WebPage_UpdateFrameScrollingMode,
    WebPage_UpdateFrameTreeSyncData,
    WebPage_UpdateOpener,
    WebPage_UpdateRemotePageAccessibilityOffset,
    WebPage_UpdateRenderingWithForcedRepaint,
#if PLATFORM(IOS_FAMILY)
    WebPage_UpdateSelectionWithDelta,
    WebPage_UpdateSelectionWithExtentPoint,
    WebPage_UpdateSelectionWithExtentPointAndBoundary,
    WebPage_UpdateSelectionWithTouches,
#endif
#if ENABLE(WRITING_TOOLS)
    WebPage_UpdateTextVisibilityForActiveWritingToolsSession,
    WebPage_UpdateUnderlyingTextVisibilityForTextAnimationID,
#endif
    WebPage_UpdateWebsitePolicies,
#if ENABLE(IMAGE_ANALYSIS)
    WebPage_UpdateWithTextRecognitionResult,
#endif
#if USE(APPKIT)
    WebPage_UppercaseWord,
#endif
    WebPage_UseRedirectionForCurrentNavigation,
#if ENABLE(MEDIA_STREAM)
    WebPage_UserMediaAccessWasDenied,
    WebPage_UserMediaAccessWasGranted,
#endif
    WebPage_ValidateCommand,
    WebPage_ViewWillEndLiveResize,
    WebPage_ViewWillStartLiveResize,
#if ENABLE(MEDIA_STREAM)
    WebPage_VoiceActivityDetected,
#endif
#if ENABLE(SPEECH_SYNTHESIS)
    WebPage_VoicesDidChange,
#endif
    WebPage_WasLoadedWithDataTransferFromPrevalentResource,
#if USE(UICONTEXTMENU)
    WebPage_WillBeginContextMenuInteraction,
#endif
#if ENABLE(WRITING_TOOLS)
    WebPage_WillBeginWritingToolsSession,
    WebPage_WillEndWritingToolsSession,
#endif
#if PLATFORM(IOS_FAMILY)
    WebPage_WillInsertFinalDictationResult,
    WebPage_WillStartUserTriggeredZooming,
#endif
#if PLATFORM(COCOA)
    WebPage_WindowAndViewFramesChanged,
#endif
    WebPage_WindowScreenDidChange,
#if ENABLE(WRITING_TOOLS)
    WebPage_WritingToolsSessionDidReceiveAction,
#endif
#if ENABLE(PDF_PLUGIN) && PLATFORM(MAC)
    WebPage_ZoomPDFIn,
    WebPage_ZoomPDFOut,
#endif
#if PLATFORM(GTK) || PLATFORM(WPE)
    WebPasteboardProxy_ClearClipboard,
#endif
#if PLATFORM(IOS_FAMILY)
    WebPasteboardProxy_UpdateSupportedTypeIdentifiers,
    WebPasteboardProxy_WriteImageToPasteboard,
#endif
#if PLATFORM(IOS_FAMILY) || USE(LIBWPE) && !PLATFORM(WPE)
    WebPasteboardProxy_WriteStringToPasteboard,
#endif
#if PLATFORM(GTK) || PLATFORM(WPE)
    WebPasteboardProxy_WriteToClipboard,
#endif
#if PLATFORM(IOS_FAMILY)
    WebPasteboardProxy_WriteURLToPasteboard,
#endif
#if PLATFORM(IOS_FAMILY) || USE(LIBWPE) && !PLATFORM(WPE)
    WebPasteboardProxy_WriteWebContentToPasteboard,
#endif
    WebPermissionControllerProxy_Query,
    WebPermissionController_permissionChanged,
    WebProcessPool_HandleMessage,
#if ENABLE(GAMEPAD)
    WebProcessPool_PlayGamepadEffect,
#endif
    WebProcessPool_ReportWebContentCPUTime,
#if ENABLE(MODEL_PROCESS)
    WebProcessPool_StartedPlayingModels,
#endif
#if ENABLE(GAMEPAD)
    WebProcessPool_StartedUsingGamepads,
    WebProcessPool_StopGamepadEffects,
#endif
#if ENABLE(MODEL_PROCESS)
    WebProcessPool_StoppedPlayingModels,
#endif
#if ENABLE(GAMEPAD)
    WebProcessPool_StoppedUsingGamepads,
#endif
#if PLATFORM(COCOA)
    WebProcessProxy_CacheMediaMIMETypes,
#endif
#if ENABLE(GPU_PROCESS)
    WebProcessProxy_CreateGPUProcessConnection,
#endif
#if ENABLE(MODEL_PROCESS)
    WebProcessProxy_CreateModelProcessConnection,
#endif
#if ENABLE(REMOTE_INSPECTOR) && PLATFORM(COCOA)
    WebProcessProxy_CreateServiceWorkerDebuggable,
#endif
    WebProcessProxy_CreateSpeechRecognitionServer,
#if ENABLE(REMOTE_INSPECTOR) && PLATFORM(COCOA)
    WebProcessProxy_DeleteServiceWorkerDebuggable,
#endif
    WebProcessProxy_DestroySpeechRecognitionServer,
    WebProcessProxy_DidCollectPrewarmInformation,
    WebProcessProxy_DidDestroyUserGestureToken,
    WebProcessProxy_DidExceedActiveMemoryLimit,
    WebProcessProxy_DidExceedCPULimit,
    WebProcessProxy_DidExceedInactiveMemoryLimit,
    WebProcessProxy_DidExceedMemoryFootprintThreshold,
    WebProcessProxy_DidReceiveBackgroundResponsivenessPing,
    WebProcessProxy_DisableSuddenTermination,
    WebProcessProxy_EnableSuddenTermination,
#if ENABLE(GPU_PROCESS)
    WebProcessProxy_GPUProcessConnectionDidBecomeUnresponsive,
#endif
#if ENABLE(NOTIFICATION_EVENT)
    WebProcessProxy_GetNotifications,
#endif
    WebProcessProxy_MemoryPressureStatusChanged,
#if ENABLE(REMOTE_INSPECTOR) && PLATFORM(COCOA)
    WebProcessProxy_SendMessageToInspector,
#endif
#if PLATFORM(GTK) || PLATFORM(WPE)
    WebProcessProxy_SendMessageToWebContext,
    WebProcessProxy_SendMessageToWebContextWithReply,
#endif
    WebProcessProxy_SetAppBadgeFromWorker,
#if HAVE(MEDIA_ACCESSIBILITY_FRAMEWORK)
    WebProcessProxy_SetCaptionDisplayMode,
    WebProcessProxy_SetCaptionLanguage,
#endif
#if HAVE(DISPLAY_LINK)
    WebProcessProxy_SetDisplayLinkPreferredFramesPerSecond,
#endif
#if (ENABLE(LOGD_BLOCKING_IN_WEBCONTENT) && ENABLE(STREAMING_IPC_IN_LOG_FORWARDING)) || (ENABLE(LOGD_BLOCKING_IN_WEBCONTENT) && !ENABLE(STREAMING_IPC_IN_LOG_FORWARDING))
    WebProcessProxy_SetupLogStream,
#endif
#if HAVE(DISPLAY_LINK)
    WebProcessProxy_StartDisplayLink,
    WebProcessProxy_StopDisplayLink,
#endif
    WebProcessProxy_StopResponsivenessTimer,
    WebProcessProxy_SystemBeep,
#if PLATFORM(COCOA)
    WebProcess_AccessibilityPreferencesDidChange,
#endif
#if ENABLE(MEDIA_STREAM)
    WebProcess_AddMockMediaDevice,
#endif
    WebProcess_BackgroundResponsivenessPing,
#if PLATFORM(IOS_FAMILY) && !PLATFORM(MACCATALYST)
    WebProcess_BacklightLevelDidChange,
#endif
    WebProcess_BindAccessibilityFrameWithData,
    WebProcess_ClearCachedPage,
    WebProcess_ClearCurrentModifierStateForTesting,
#if ENABLE(MEDIA_STREAM)
    WebProcess_ClearMockMediaDevices,
#endif
    WebProcess_ClearResourceLoadStatistics,
#if PLATFORM(MAC) || PLATFORM(MACCATALYST)
    WebProcess_ColorPreferencesDidChange,
#endif
#if HAVE(AUDIO_COMPONENT_SERVER_REGISTRATIONS)
    WebProcess_ConsumeAudioComponentRegistrations,
#endif
    WebProcess_CreateWebPage,
    WebProcess_DeleteAllCookies,
    WebProcess_DeleteWebsiteData,
    WebProcess_DeleteWebsiteDataForOrigin,
    WebProcess_DeleteWebsiteDataForOrigins,
    WebProcess_DestroyAutomationSessionProxy,
#if PLATFORM(COCOA)
    WebProcess_DidWriteToPasteboardAsynchronously,
    WebProcess_DisableURLSchemeCheckInDataDetectors,
#endif
#if HAVE(DISPLAY_LINK)
    WebProcess_DisplayDidRefresh,
#endif
#if (PLATFORM(COCOA) && ENABLE(REMOTE_INSPECTOR))
    WebProcess_EnableRemoteWebInspector,
#endif
    WebProcess_EnsureAutomationSessionProxy,
    WebProcess_EstablishRemoteWorkerContextConnectionToNetworkProcess,
    WebProcess_FetchWebsiteData,
    WebProcess_FullKeyboardAccessModeChanged,
#if ENABLE(GAMEPAD)
    WebProcess_GamepadConnected,
    WebProcess_GamepadDisconnected,
#endif
    WebProcess_GarbageCollectJavaScriptObjects,
    WebProcess_GetActivePagesOriginsForTesting,
#if ENABLE(NOTIFY_BLOCKING)
    WebProcess_GetNotifyStateForTesting,
#endif
    WebProcess_GrantAccessToAssetServices,
#if (ENABLE(MEDIA_STREAM) && ENABLE(SANDBOX_EXTENSIONS))
    WebProcess_GrantUserMediaDeviceSandboxExtensions,
#endif
    WebProcess_HandleInjectedBundleMessage,
#if ENABLE(INITIALIZE_ACCESSIBILITY_ON_DEMAND)
    WebProcess_InitializeAccessibility,
#endif
    WebProcess_InitializeWebProcess,
    WebProcess_IsJITEnabled,
    WebProcess_MarkIsNoLongerPrewarmed,
#if PLATFORM(MAC)
    WebProcess_OpenDirectoryCacheInvalidated,
#endif
#if ENABLE(NOTIFY_BLOCKING)
    WebProcess_PostNotification,
    WebProcess_PostObserverNotification,
#endif
#if PLATFORM(COCOA)
    WebProcess_PowerSourceDidChange,
#endif
    WebProcess_PrepareToSuspend,
    WebProcess_PrewarmWithDomainInformation,
    WebProcess_ProcessDidResume,
#if PLATFORM(COCOA)
    WebProcess_RegisterAdditionalFonts,
    WebProcess_RegisterFontMap,
#endif
    WebProcess_RegisterServiceWorkerClients,
    WebProcess_RegisterURLSchemeAsBypassingContentSecurityPolicy,
    WebProcess_RegisterURLSchemeAsCORSEnabled,
    WebProcess_RegisterURLSchemeAsCachePartitioned,
    WebProcess_RegisterURLSchemeAsCanDisplayOnlyIfCanRequest,
    WebProcess_RegisterURLSchemeAsDisplayIsolated,
    WebProcess_RegisterURLSchemeAsEmptyDocument,
    WebProcess_RegisterURLSchemeAsLocal,
#if ENABLE(ALL_LEGACY_REGISTERED_SPECIAL_URL_SCHEMES)
    WebProcess_RegisterURLSchemeAsNoAccess,
#endif
    WebProcess_RegisterURLSchemeAsSecure,
#if ENABLE(WK_WEB_EXTENSIONS)
    WebProcess_RegisterURLSchemeAsWebExtension,
#endif
    WebProcess_ReleaseMemory,
    WebProcess_ReloadExecutionContextsForOrigin,
#if ENABLE(MEDIA_STREAM)
    WebProcess_RemoveMockMediaDevice,
    WebProcess_ResetMockMediaDevices,
#endif
    WebProcess_RevokeAccessToAssetServices,
#if (ENABLE(MEDIA_STREAM) && ENABLE(SANDBOX_EXTENSIONS))
    WebProcess_RevokeUserMediaDeviceSandboxExtensions,
#endif
#if PLATFORM(MAC)
    WebProcess_ScrollerStylePreferenceChanged,
#endif
    WebProcess_SeedResourceLoadStatisticsForTesting,
#if PLATFORM(GTK) || PLATFORM(WPE)
    WebProcess_SendMessageToWebProcessExtension,
#endif
    WebProcess_SendResourceLoadStatisticsDataImmediately,
    WebProcess_SetAlwaysUsesComplexTextCodePath,
#if PLATFORM(GTK) || PLATFORM(WPE)
    WebProcess_SetAvailableInputDevices,
#endif
    WebProcess_SetBackForwardCacheCapacity,
    WebProcess_SetCacheModel,
    WebProcess_SetDefaultRequestTimeoutInterval,
    WebProcess_SetDisableFontSubpixelAntialiasingForTesting,
    WebProcess_SetDomainRelaxationForbiddenForURLScheme,
    WebProcess_SetDomainsWithCrossPageStorageAccess,
    WebProcess_SetDomainsWithUserInteraction,
#if ENABLE(SERVICE_CONTROLS)
    WebProcess_SetEnabledServices,
#endif
    WebProcess_SetEnhancedAccessibility,
#if HAVE(MOUSE_DEVICE_OBSERVATION)
    WebProcess_SetHasMouseDevice,
#endif
#if HAVE(STYLUS_DEVICE_OBSERVATION)
    WebProcess_SetHasStylusDevice,
#endif
    WebProcess_SetHasSuspendedPageProxy,
    WebProcess_SetHiddenPageDOMTimerThrottlingIncreaseLimit,
#if ENABLE(GAMEPAD)
    WebProcess_SetInitialGamepads,
#endif
    WebProcess_SetInjectedBundleParameter,
    WebProcess_SetInjectedBundleParameters,
    WebProcess_SetIsInProcessCache,
    WebProcess_SetJavaScriptGarbageCollectorTimerEnabled,
#if HAVE(MEDIA_ACCESSIBILITY_FRAMEWORK)
    WebProcess_SetMediaAccessibilityPreferences,
#endif
#if PLATFORM(COCOA)
    WebProcess_SetMediaMIMETypes,
#endif
    WebProcess_SetMemoryCacheDisabled,
#if ENABLE(MEDIA_STREAM)
    WebProcess_SetMockMediaDeviceIsEphemeral,
#endif
#if HAVE(ALLOW_ONLY_PARTITIONED_COOKIES)
    WebProcess_SetOptInCookiePartitioningEnabled,
#endif
#if ENABLE(CONTENT_EXTENSIONS)
    WebProcess_SetResourceMonitorContentRuleList,
    WebProcess_SetResourceMonitorContentRuleListAsync,
#endif
#if PLATFORM(COCOA) || PLATFORM(GTK) || PLATFORM(WPE)
    WebProcess_SetScreenProperties,
#endif
    WebProcess_SetTextCheckerState,
    WebProcess_SetThirdPartyCookieBlockingMode,
    WebProcess_SetTrackingPreventionEnabled,
#if PLATFORM(GTK) && !USE(GTK4) && USE(CAIRO)
    WebProcess_SetUseSystemAppearanceForScrollbars,
#endif
    WebProcess_SetWebsiteDataStoreParameters,
    WebProcess_StartMemorySampler,
    WebProcess_StopMemorySampler,
    WebProcess_SwitchFromStaticFontRegistryToUserFontRegistry,
#if PLATFORM(MAC)
    WebProcess_SystemDidWake,
    WebProcess_SystemWillPowerOn,
    WebProcess_SystemWillSleep,
#endif
#if PLATFORM(COCOA)
    WebProcess_UnblockServicesRequiredByAccessibility,
#endif
    WebProcess_UpdateDomainsWithStorageAccessQuirks,
    WebProcess_UpdateScriptTrackingPrivacyFilter,
    WebProcess_UpdateStorageAccessUserAgentStringQuirks,
#if PLATFORM(IOS_FAMILY)
    WebProcess_UserInterfaceIdiomDidChange,
#endif
    WebProcess_UserPreferredLanguagesChanged,
    WebRTCMonitor_NetworksChanged,
    WebRTCResolver_ResolvedAddressError,
    WebRTCResolver_SetResolvedAddress,
#if ENABLE(CONTENT_FILTERING)
    WebResourceLoader_ContentFilterDidBlockLoad,
#endif
    WebResourceLoader_DidBlockAuthenticationChallenge,
    WebResourceLoader_DidFailResourceLoad,
    WebResourceLoader_DidFailServiceWorkerLoad,
    WebResourceLoader_DidFinishResourceLoad,
    WebResourceLoader_DidReceiveData,
#if ENABLE(SHAREABLE_RESOURCE)
    WebResourceLoader_DidReceiveResource,
#endif
    WebResourceLoader_DidReceiveResponse,
    WebResourceLoader_DidSendData,
    WebResourceLoader_ServiceWorkerDidNotHandle,
    WebResourceLoader_SetWorkerStart,
    WebResourceLoader_StopLoadingAfterXFrameOptionsOrContentSecurityPolicyDenied,
    WebResourceLoader_UpdateResultingClientIdentifier,
    WebResourceLoader_WillSendRequest,
    WebSWClientConnection_FireUpdateFoundEvent,
    WebSWClientConnection_FocusServiceWorkerClient,
    WebSWClientConnection_JobRejectedInServer,
    WebSWClientConnection_NotifyClientsOfControllerChange,
    WebSWClientConnection_NotifyRecordResponseBodyChunk,
    WebSWClientConnection_NotifyRecordResponseBodyEnd,
    WebSWClientConnection_PostMessageToServiceWorkerClient,
    WebSWClientConnection_RegistrationJobResolvedInServer,
#if ENABLE(CONTENT_EXTENSIONS)
    WebSWClientConnection_ReportNetworkUsageToWorkerClient,
#endif
    WebSWClientConnection_SetRegistrationLastUpdateTime,
    WebSWClientConnection_SetRegistrationUpdateViaCache,
    WebSWClientConnection_SetSWOriginTableIsImported,
    WebSWClientConnection_SetSWOriginTableSharedMemory,
    WebSWClientConnection_SetServiceWorkerClientIsControlled,
    WebSWClientConnection_StartScriptFetchForServer,
    WebSWClientConnection_UpdateBackgroundFetchRegistration,
    WebSWClientConnection_UpdateRegistrationState,
    WebSWClientConnection_UpdateWorkerState,
    WebSWContextManagerConnection_CancelFetch,
    WebSWContextManagerConnection_Close,
#if ENABLE(REMOTE_INSPECTOR) && PLATFORM(COCOA)
    WebSWContextManagerConnection_ConnectToInspector,
#endif
    WebSWContextManagerConnection_ContinueDidReceiveFetchResponse,
    WebSWContextManagerConnection_ConvertFetchToDownload,
#if ENABLE(SHAREABLE_RESOURCE) && PLATFORM(COCOA)
    WebSWContextManagerConnection_DidSaveScriptsToDisk,
#endif
#if ENABLE(REMOTE_INSPECTOR) && PLATFORM(COCOA)
    WebSWContextManagerConnection_DisconnectFromInspector,
    WebSWContextManagerConnection_DispatchMessageFromInspector,
#endif
    WebSWContextManagerConnection_FireActivateEvent,
    WebSWContextManagerConnection_FireBackgroundFetchClickEvent,
    WebSWContextManagerConnection_FireBackgroundFetchEvent,
    WebSWContextManagerConnection_FireInstallEvent,
    WebSWContextManagerConnection_FireNotificationEvent,
    WebSWContextManagerConnection_FirePushEvent,
    WebSWContextManagerConnection_FireUpdateFoundEvent,
    WebSWContextManagerConnection_InstallServiceWorker,
    WebSWContextManagerConnection_NavigationPreloadFailed,
    WebSWContextManagerConnection_NavigationPreloadIsReady,
    WebSWContextManagerConnection_PostMessageToServiceWorker,
    WebSWContextManagerConnection_SetInspectable,
    WebSWContextManagerConnection_SetRegistrationLastUpdateTime,
    WebSWContextManagerConnection_SetRegistrationUpdateViaCache,
    WebSWContextManagerConnection_SetThrottleState,
    WebSWContextManagerConnection_SetUserAgent,
    WebSWContextManagerConnection_StartFetch,
    WebSWContextManagerConnection_TerminateWorker,
#if ((ENABLE(REMOTE_INSPECTOR) && PLATFORM(COCOA)) && ENABLE(REMOTE_INSPECTOR_SERVICE_WORKER_AUTO_INSPECTION))
    WebSWContextManagerConnection_UnpauseServiceWorkerForRejectedAutomaticInspection,
#endif
    WebSWContextManagerConnection_UpdateAppInitiatedValue,
    WebSWContextManagerConnection_UpdatePreferencesStore,
    WebSWContextManagerConnection_UpdateRegistrationState,
    WebSWContextManagerConnection_UpdateWorkerState,
    WebSWServerConnection_AbortBackgroundFetch,
    WebSWServerConnection_AddCookieChangeSubscriptions,
    WebSWServerConnection_AddRoutes,
    WebSWServerConnection_AddServiceWorkerRegistrationInServer,
    WebSWServerConnection_BackgroundFetchIdentifiers,
    WebSWServerConnection_BackgroundFetchInformation,
    WebSWServerConnection_CookieChangeSubscriptions,
    WebSWServerConnection_DidResolveRegistrationPromise,
    WebSWServerConnection_DisableNavigationPreload,
    WebSWServerConnection_EnableNavigationPreload,
    WebSWServerConnection_FinishFetchingScriptInServer,
    WebSWServerConnection_GetNavigationPreloadState,
#if ENABLE(WEB_PUSH_NOTIFICATIONS)
    WebSWServerConnection_GetNotifications,
#endif
    WebSWServerConnection_GetPushPermissionState,
    WebSWServerConnection_GetPushSubscription,
    WebSWServerConnection_GetRegistrations,
    WebSWServerConnection_MatchBackgroundFetch,
    WebSWServerConnection_MatchRegistration,
    WebSWServerConnection_PostMessageToServiceWorker,
    WebSWServerConnection_RegisterServiceWorkerClient,
    WebSWServerConnection_RemoveCookieChangeSubscriptions,
    WebSWServerConnection_RemoveServiceWorkerRegistrationInServer,
    WebSWServerConnection_RetrieveRecordResponse,
    WebSWServerConnection_RetrieveRecordResponseBody,
    WebSWServerConnection_ScheduleJobInServer,
    WebSWServerConnection_ScheduleUnregisterJobInServer,
    WebSWServerConnection_SetNavigationPreloadHeaderValue,
    WebSWServerConnection_SetThrottleState,
    WebSWServerConnection_StartBackgroundFetch,
    WebSWServerConnection_StoreRegistrationsOnDisk,
    WebSWServerConnection_SubscribeToPushService,
    WebSWServerConnection_TerminateWorkerFromClient,
    WebSWServerConnection_UnregisterServiceWorkerClient,
    WebSWServerConnection_UnsubscribeFromPushService,
    WebSWServerConnection_WhenRegistrationReady,
    WebSWServerConnection_WhenServiceWorkerIsTerminatedForTesting,
    WebSWServerToContextConnection_Claim,
    WebSWServerToContextConnection_DidFailHeartBeatCheck,
    WebSWServerToContextConnection_DidFinishActivation,
    WebSWServerToContextConnection_DidFinishInstall,
    WebSWServerToContextConnection_FindClientByVisibleIdentifier,
    WebSWServerToContextConnection_Focus,
    WebSWServerToContextConnection_MatchAll,
    WebSWServerToContextConnection_Navigate,
    WebSWServerToContextConnection_OpenWindow,
    WebSWServerToContextConnection_PostMessageToServiceWorkerClient,
    WebSWServerToContextConnection_ReportConsoleMessage,
    WebSWServerToContextConnection_ScriptContextFailedToStart,
    WebSWServerToContextConnection_ScriptContextStarted,
    WebSWServerToContextConnection_SetAsInspected,
    WebSWServerToContextConnection_SetScriptResource,
    WebSWServerToContextConnection_SetServiceWorkerHasPendingEvents,
    WebSWServerToContextConnection_SkipWaiting,
    WebSWServerToContextConnection_WorkerTerminated,
    WebScreenOrientationManagerProxy_Lock,
    WebScreenOrientationManagerProxy_SetShouldSendChangeNotification,
    WebScreenOrientationManagerProxy_Unlock,
    WebScreenOrientationManager_OrientationDidChange,
    WebSharedWorkerContextManagerConnection_Close,
    WebSharedWorkerContextManagerConnection_LaunchSharedWorker,
    WebSharedWorkerContextManagerConnection_PostConnectEvent,
    WebSharedWorkerContextManagerConnection_ResumeSharedWorker,
    WebSharedWorkerContextManagerConnection_SetUserAgent,
    WebSharedWorkerContextManagerConnection_SuspendSharedWorker,
    WebSharedWorkerContextManagerConnection_TerminateSharedWorker,
    WebSharedWorkerContextManagerConnection_UpdatePreferencesStore,
    WebSharedWorkerObjectConnection_FetchScriptInClient,
    WebSharedWorkerObjectConnection_NotifyWorkerObjectOfLoadCompletion,
    WebSharedWorkerObjectConnection_PostErrorToWorkerObject,
#if ENABLE(CONTENT_EXTENSIONS)
    WebSharedWorkerObjectConnection_ReportNetworkUsageToWorkerObject,
#endif
    WebSharedWorkerServerConnection_RequestSharedWorker,
    WebSharedWorkerServerConnection_ResumeForBackForwardCache,
    WebSharedWorkerServerConnection_SharedWorkerObjectIsGoingAway,
    WebSharedWorkerServerConnection_SuspendForBackForwardCache,
    WebSharedWorkerServerToContextConnection_PostErrorToWorkerObject,
    WebSharedWorkerServerToContextConnection_SharedWorkerTerminated,
    WebSocketChannel_DidClose,
    WebSocketChannel_DidConnect,
    WebSocketChannel_DidReceiveBinaryData,
    WebSocketChannel_DidReceiveHandshakeResponse,
    WebSocketChannel_DidReceiveMessageError,
    WebSocketChannel_DidReceiveText,
    WebSocketChannel_DidSendHandshakeRequest,
    WebSpeechRecognitionConnection_DidReceiveUpdate,
    WebTransportSession_ReceiveBidirectionalStream,
    WebTransportSession_ReceiveDatagram,
    WebTransportSession_ReceiveIncomingUnidirectionalStream,
    WebTransportSession_StreamReceiveBytes,
    WebUserContentControllerProxy_DidPostMessage,
#if ENABLE(CONTENT_EXTENSIONS)
    WebUserContentController_AddContentRuleLists,
#endif
    WebUserContentController_AddContentWorlds,
    WebUserContentController_AddUserScriptMessageHandlers,
    WebUserContentController_AddUserScripts,
    WebUserContentController_AddUserStyleSheets,
#if ENABLE(CONTENT_EXTENSIONS)
    WebUserContentController_RemoveAllContentRuleLists,
#endif
    WebUserContentController_RemoveAllUserScriptMessageHandlers,
    WebUserContentController_RemoveAllUserScriptMessageHandlersForWorlds,
    WebUserContentController_RemoveAllUserScripts,
    WebUserContentController_RemoveAllUserStyleSheets,
#if ENABLE(CONTENT_EXTENSIONS)
    WebUserContentController_RemoveContentRuleList,
#endif
    WebUserContentController_RemoveContentWorlds,
    WebUserContentController_RemoveUserScript,
    WebUserContentController_RemoveUserScriptMessageHandler,
    WebUserContentController_RemoveUserStyleSheet,
    CancelSyncMessageReply,
#if PLATFORM(COCOA)
    InitializeConnection,
#endif
    LegacySessionState,
    ProcessOutOfStreamMessage,
    SetStreamDestinationID,
    SyncMessageReply,
    AuxiliaryProcess_MainThreadPingReply,
    DigitalCredentialsCoordinator_ProvideRawDigitalCredentialRequestsReply,
    DownloadProxy_DecideDestinationWithSuggestedFilenameReply,
#if HAVE(MODERN_DOWNLOADPROGRESS)
    DownloadProxy_DidReceivePlaceholderURLReply,
#endif
    DownloadProxy_WillSendRequestReply,
#if PLATFORM(COCOA) || PLATFORM(GTK)
    DrawingArea_CommitTransientZoomReply,
#endif
#if PLATFORM(COCOA) || PLATFORM(GTK) || PLATFORM(WPE)
    DrawingArea_DispatchAfterEnsuringDrawingReply,
#endif
    DrawingArea_SetDeviceScaleFactorReply,
#if USE(COORDINATED_GRAPHICS) || USE(TEXTURE_MAPPER) || PLATFORM(COCOA)
    DrawingArea_UpdateGeometryReply,
#endif
#if ENABLE(MAC_GESTURE_EVENTS)
    EventDispatcher_GestureEventReply,
#endif
#if ENABLE(IOS_TOUCH_EVENTS)
    EventDispatcher_TouchEventReply,
#endif
#if ENABLE(ROUTING_ARBITRATION)
    GPUProcessConnection_BeginRoutingArbitrationWithCategoryReply,
#endif
#if (ENABLE(MEDIA_STREAM) && PLATFORM(IOS_FAMILY))
    GPUProcessProxy_StatusBarWasTappedReply,
#endif
    GPUProcess_CreateGPUConnectionToWebProcessReply,
#if ((PLATFORM(VISION) && ENABLE(MODEL_PROCESS)) && HAVE(TASK_IDENTITY_TOKEN))
    GPUProcess_CreateMemoryAttributionIDForTaskReply,
#endif
    GPUProcess_InitializeGPUProcessReply,
#if PLATFORM(COCOA)
    GPUProcess_PostWillTakeSnapshotNotificationReply,
#endif
    GPUProcess_PrepareToSuspendReply,
#if HAVE(SCREEN_CAPTURE_KIT)
    GPUProcess_PromptForGetDisplayMediaReply,
#endif
#if ENABLE(VIDEO)
    GPUProcess_RequestBitmapImageForCurrentTimeReply,
#endif
#if PLATFORM(VISION) && ENABLE(MODEL_PROCESS)
    GPUProcess_RequestSharedSimulationConnectionReply,
#endif
    GPUProcess_SharedPreferencesForWebProcessDidChangeReply,
#if ((PLATFORM(VISION) && ENABLE(MODEL_PROCESS)) && HAVE(TASK_IDENTITY_TOKEN))
    GPUProcess_UnregisterMemoryAttributionIDReply,
#endif
#if ENABLE(MEDIA_STREAM)
    GPUProcess_UpdateCaptureAccessReply,
#endif
    GPUProcess_WebProcessConnectionCountForTestingReply,
#if ENABLE(WEBXR)
    GPUProcess_WebXRPromptAcceptedReply,
#endif
    IPCStreamTester_AsyncPingReply,
    IPCTesterReceiver_AsyncMessageReply,
    IPCTester_AsyncOptionalExceptionDataReply,
    IPCTester_AsyncPingReply,
    LibWebRTCCodecsProxy_CreateDecoderReply,
    LibWebRTCCodecsProxy_CreateEncoderReply,
    LibWebRTCCodecsProxy_DecodeFrameReply,
    LibWebRTCCodecsProxy_EncodeFrameReply,
    LibWebRTCCodecsProxy_FlushDecoderReply,
    LibWebRTCCodecsProxy_FlushEncoderReply,
    LibWebRTCCodecsProxy_SetEncodeRatesReply,
    MediaPlayerPrivateRemote_CommitAllTransactionsReply,
#if PLATFORM(IOS_FAMILY)
    MediaPlayerPrivateRemote_GetRawCookiesReply,
#endif
    MediaPlayerPrivateRemote_SendH2PingReply,
    MediaSourcePrivateRemoteMessageReceiver_ProxySeekToTimeReply,
    MediaSourcePrivateRemoteMessageReceiver_ProxyWaitForTargetReply,
#if PLATFORM(VISION) && ENABLE(GPU_PROCESS)
    ModelProcessProxy_RequestSharedSimulationConnectionReply,
#endif
    ModelProcess_CreateModelConnectionToWebProcessReply,
    ModelProcess_InitializeModelProcessReply,
    ModelProcess_ModelPlayerCountForTestingReply,
    ModelProcess_PrepareToSuspendReply,
    ModelProcess_SharedPreferencesForWebProcessDidChangeReply,
    ModelProcess_WebProcessConnectionCountForTestingReply,
    NetworkBroadcastChannelRegistry_PostMessageReply,
#if ENABLE(WEB_RTC)
    NetworkConnectionToWebProcess_ConnectToRTCDataChannelRemoteSourceReply,
#endif
    NetworkConnectionToWebProcess_CookiesEnabledReply,
    NetworkConnectionToWebProcess_CookiesForDOMAsyncReply,
    NetworkConnectionToWebProcess_CreateRTCProviderReply,
    NetworkConnectionToWebProcess_DeleteCookieReply,
    NetworkConnectionToWebProcess_EstablishSWContextConnectionReply,
    NetworkConnectionToWebProcess_EstablishSharedWorkerContextConnectionReply,
#if PLATFORM(MAC)
    NetworkConnectionToWebProcess_GetProcessDisplayNameReply,
#endif
    NetworkConnectionToWebProcess_HasStorageAccessReply,
    NetworkConnectionToWebProcess_InitializeWebTransportSessionReply,
    NetworkConnectionToWebProcess_IsLoggedInReply,
    NetworkConnectionToWebProcess_IsResourceLoadFinishedReply,
    NetworkConnectionToWebProcess_LoadImageForDecodingReply,
#if ENABLE(DECLARATIVE_WEB_PUSH)
    NetworkConnectionToWebProcess_NavigatorGetPushPermissionStateReply,
    NetworkConnectionToWebProcess_NavigatorGetPushSubscriptionReply,
    NetworkConnectionToWebProcess_NavigatorSubscribeToPushServiceReply,
    NetworkConnectionToWebProcess_NavigatorUnsubscribeFromPushServiceReply,
#endif
    NetworkConnectionToWebProcess_PingPongForServiceWorkersReply,
    NetworkConnectionToWebProcess_RegisterBlobPathForTestingReply,
    NetworkConnectionToWebProcess_RequestStorageAccessReply,
    NetworkConnectionToWebProcess_ResourceLoadStatisticsUpdatedReply,
    NetworkConnectionToWebProcess_SendH2PingReply,
    NetworkConnectionToWebProcess_SetCookieFromDOMAsyncReply,
    NetworkConnectionToWebProcess_SetLoginStatusReply,
#if ENABLE(CONTENT_EXTENSIONS)
    NetworkConnectionToWebProcess_ShouldOffloadIFrameForHostReply,
#endif
    NetworkConnectionToWebProcess_StorageAccessQuirkForTopFrameDomainReply,
#if HAVE(COOKIE_CHANGE_LISTENER_API)
    NetworkConnectionToWebProcess_SubscribeToCookieChangeNotificationsReply,
#endif
    NetworkConnectionToWebProcess_TakeAllMessagesForPortReply,
    NetworkConnectionToWebProcess_WriteBlobsToTemporaryFilesForIndexedDBReply,
    NetworkMDNSRegister_RegisterMDNSNameReply,
#if ENABLE(WEB_RTC)
    NetworkProcessConnection_ConnectToRTCDataChannelRemoteSourceReply,
#endif
    NetworkProcessProxy_DataTaskDidReceiveResponseReply,
    NetworkProcessProxy_DataTaskReceivedChallengeReply,
    NetworkProcessProxy_DataTaskWillPerformHTTPRedirectionReply,
    NetworkProcessProxy_DeleteWebsiteDataInUIProcessForRegistrableDomainsReply,
    NetworkProcessProxy_DeleteWebsiteDataInWebProcessesForOriginReply,
    NetworkProcessProxy_EstablishRemoteWorkerContextConnectionToNetworkProcessReply,
#if ENABLE(APP_BOUND_DOMAINS)
    NetworkProcessProxy_GetAppBoundDomainsReply,
#endif
#if ENABLE(APPLE_PAY_REMOTE_UI)
    NetworkProcessProxy_GetPaymentCoordinatorEmbeddingUserAgentReply,
#endif
#if ENABLE(APPLE_PAY_REMOTE_UI_USES_SCENE)
    NetworkProcessProxy_GetWindowSceneAndBundleIdentifierForPaymentPresentationReply,
#endif
    NetworkProcessProxy_NavigateServiceWorkerClientReply,
    NetworkProcessProxy_OpenWindowFromServiceWorkerReply,
    NetworkProcessProxy_ReloadExecutionContextsForOriginReply,
    NetworkProcessProxy_RequestBackgroundFetchPermissionReply,
    NetworkProcessProxy_RequestStorageAccessConfirmReply,
    NetworkProcessProxy_SetDomainsWithCrossPageStorageAccessReply,
    NetworkProcessProxy_TriggerBrowsingContextGroupSwitchForNavigationReply,
    NetworkProcess_AbortBackgroundFetchReply,
    NetworkProcess_AddAllowedFirstPartyForCookiesReply,
    NetworkProcess_AllowFileAccessFromWebProcessReply,
    NetworkProcess_AllowFilesAccessFromWebProcessReply,
#if PLATFORM(COCOA)
    NetworkProcess_AppPrivacyReportTestingDataReply,
#endif
    NetworkProcess_CancelDataTaskReply,
    NetworkProcess_CancelDownloadReply,
#if ENABLE(APP_BOUND_DOMAINS)
    NetworkProcess_ClearAppBoundSessionReply,
#endif
#if PLATFORM(COCOA)
    NetworkProcess_ClearAppPrivacyReportTestingDataReply,
#endif
    NetworkProcess_ClearBundleIdentifierReply,
    NetworkProcess_ClearPrevalentResourceReply,
    NetworkProcess_ClearPrivateClickMeasurementReply,
#if PLATFORM(IOS_FAMILY) && !PLATFORM(MACCATALYST)
    NetworkProcess_ClearServiceWorkerEntitlementOverrideReply,
#endif
    NetworkProcess_ClearUserInteractionReply,
    NetworkProcess_ClickBackgroundFetchReply,
    NetworkProcess_CloseITPDatabaseReply,
    NetworkProcess_ClosePCMDatabaseReply,
    NetworkProcess_CountNonDefaultSessionSetsReply,
    NetworkProcess_CreateNetworkConnectionToWebProcessReply,
    NetworkProcess_DataTaskWithRequestReply,
    NetworkProcess_DeleteCookiesForTestingReply,
    NetworkProcess_DeleteWebsiteDataForOriginsReply,
    NetworkProcess_DeleteWebsiteDataReply,
    NetworkProcess_DestroySessionReply,
    NetworkProcess_DomainIDExistsInDatabaseReply,
    NetworkProcess_DumpPrivateClickMeasurementReply,
    NetworkProcess_DumpResourceLoadStatisticsReply,
    NetworkProcess_EnsureSessionWithDataStoreIdentifierRemovedReply,
    NetworkProcess_FetchLocalStorageReply,
    NetworkProcess_FetchSessionStorageReply,
    NetworkProcess_FetchWebsiteDataReply,
    NetworkProcess_FlushCookiesReply,
    NetworkProcess_GetAllBackgroundFetchIdentifiersReply,
    NetworkProcess_GetAllStorageAccessEntriesReply,
    NetworkProcess_GetAppBadgeForTestingReply,
    NetworkProcess_GetBackgroundFetchStateReply,
    NetworkProcess_GetPendingPushMessageReply,
    NetworkProcess_GetPendingPushMessagesReply,
    NetworkProcess_GetResourceLoadStatisticsDataSummaryReply,
    NetworkProcess_GrantStorageAccessForTestingReply,
    NetworkProcess_HadUserInteractionReply,
#if ENABLE(APP_BOUND_DOMAINS)
    NetworkProcess_HasAppBoundSessionReply,
#endif
    NetworkProcess_HasIsolatedSessionReply,
    NetworkProcess_HasLocalStorageReply,
    NetworkProcess_HasPushSubscriptionForTestingReply,
    NetworkProcess_InitializeNetworkProcessReply,
    NetworkProcess_InsertExpiredStatisticForTestingReply,
    NetworkProcess_IsGrandfatheredReply,
    NetworkProcess_IsPrevalentResourceReply,
    NetworkProcess_IsRegisteredAsRedirectingToReply,
    NetworkProcess_IsRegisteredAsSubFrameUnderReply,
    NetworkProcess_IsRegisteredAsSubresourceUnderReply,
    NetworkProcess_IsRelationshipOnlyInDatabaseOnceReply,
    NetworkProcess_IsResourceLoadStatisticsEphemeralReply,
    NetworkProcess_IsVeryPrevalentResourceReply,
    NetworkProcess_LogUserInteractionReply,
    NetworkProcess_MarkAttributedPrivateClickMeasurementsAsExpiredForTestingReply,
    NetworkProcess_MarkPrivateClickMeasurementsAsExpiredForTestingReply,
    NetworkProcess_MergeStatisticForTestingReply,
    NetworkProcess_PauseBackgroundFetchReply,
    NetworkProcess_PrepareToSuspendReply,
    NetworkProcess_ProcessNotificationEventReply,
    NetworkProcess_ProcessPushMessageReply,
    NetworkProcess_RemovePushSubscriptionsForOriginReply,
    NetworkProcess_RenameOriginInWebsiteDataReply,
    NetworkProcess_ResetCacheMaxAgeCapForPrevalentResourcesReply,
    NetworkProcess_ResetCrossSiteLoadsWithLinkDecorationForTestingReply,
    NetworkProcess_ResetParametersToDefaultValuesReply,
    NetworkProcess_ResetQuotaReply,
#if ENABLE(CONTENT_EXTENSIONS)
    NetworkProcess_ResetResourceMonitorThrottlerForTestingReply,
#endif
    NetworkProcess_ResetStoragePersistedStateReply,
    NetworkProcess_RestoreLocalStorageReply,
    NetworkProcess_RestoreSessionStorageReply,
    NetworkProcess_ResumeBackgroundFetchReply,
    NetworkProcess_RunningOrTerminatingServiceWorkerCountForTestingReply,
    NetworkProcess_ScheduleClearInMemoryAndPersistentReply,
    NetworkProcess_ScheduleCookieBlockingUpdateReply,
    NetworkProcess_ScheduleStatisticsAndDataRecordsProcessingReply,
#if ENABLE(APP_BOUND_DOMAINS)
    NetworkProcess_SetAppBoundDomainsForResourceLoadStatisticsReply,
#endif
#if PLATFORM(IOS_FAMILY)
    NetworkProcess_SetBackupExclusionPeriodForTestingReply,
#endif
    NetworkProcess_SetCacheMaxAgeCapForPrevalentResourcesReply,
    NetworkProcess_SetCrossSiteLoadWithLinkDecorationForTestingReply,
    NetworkProcess_SetFirstPartyHostCNAMEDomainForTestingReply,
    NetworkProcess_SetFirstPartyWebsiteDataRemovalModeForTestingReply,
    NetworkProcess_SetGrandfatheredReply,
    NetworkProcess_SetGrandfatheringTimeReply,
    NetworkProcess_SetIsRunningResourceLoadStatisticsTestReply,
    NetworkProcess_SetLastSeenReply,
#if ENABLE(MANAGED_DOMAINS)
    NetworkProcess_SetManagedDomainsForResourceLoadStatisticsReply,
#endif
    NetworkProcess_SetMaxStatisticsEntriesReply,
    NetworkProcess_SetMinimumTimeBetweenDataRecordsRemovalReply,
    NetworkProcess_SetOriginQuotaRatioEnabledForTestingReply,
    NetworkProcess_SetPCMFraudPreventionValuesForTestingReply,
    NetworkProcess_SetPrevalentResourceForDebugModeReply,
    NetworkProcess_SetPrevalentResourceReply,
    NetworkProcess_SetPrivateClickMeasurementAppBundleIDForTestingReply,
    NetworkProcess_SetPrivateClickMeasurementAttributionReportURLsForTestingReply,
    NetworkProcess_SetPrivateClickMeasurementEphemeralMeasurementForTestingReply,
    NetworkProcess_SetPrivateClickMeasurementOverrideTimerForTestingReply,
    NetworkProcess_SetPrivateClickMeasurementTokenPublicKeyURLForTestingReply,
    NetworkProcess_SetPrivateClickMeasurementTokenSignatureURLForTestingReply,
    NetworkProcess_SetPruneEntriesDownToReply,
    NetworkProcess_SetPushAndNotificationsEnabledForOriginReply,
    NetworkProcess_SetResourceLoadStatisticsDebugModeReply,
    NetworkProcess_SetResourceLoadStatisticsTimeAdvanceForTestingReply,
    NetworkProcess_SetShouldClassifyResourcesBeforeDataRecordsRemovalReply,
    NetworkProcess_SetShouldDowngradeReferrerForTestingReply,
    NetworkProcess_SetShouldEnbleSameSiteStrictEnforcementForTestingReply,
    NetworkProcess_SetSubframeUnderTopFrameDomainReply,
    NetworkProcess_SetSubresourceUnderTopFrameDomainReply,
    NetworkProcess_SetSubresourceUniqueRedirectFromReply,
    NetworkProcess_SetSubresourceUniqueRedirectToReply,
    NetworkProcess_SetThirdPartyCNAMEDomainForTestingReply,
    NetworkProcess_SetThirdPartyCookieBlockingModeReply,
    NetworkProcess_SetTimeToLiveUserInteractionReply,
    NetworkProcess_SetToSameSiteStrictCookiesForTestingReply,
    NetworkProcess_SetTopFrameUniqueRedirectFromReply,
    NetworkProcess_SetTopFrameUniqueRedirectToReply,
    NetworkProcess_SetVeryPrevalentResourceReply,
    NetworkProcess_SharedPreferencesForWebProcessDidChangeReply,
    NetworkProcess_SimulatePrivateClickMeasurementSessionRestartReply,
    NetworkProcess_StatisticsDatabaseHasAllTablesReply,
    NetworkProcess_StoreServiceWorkerRegistrationsReply,
    NetworkProcess_SyncLocalStorageReply,
    NetworkProcess_TerminateIdleServiceWorkersReply,
    NetworkProcess_UpdateBundleIdentifierReply,
    NetworkProcess_UpdatePrevalentDomainsToBlockCookiesForReply,
    NetworkProcess_WebsiteDataOriginDirectoryForTestingReply,
#if PLATFORM(COCOA)
    NetworkRTCProvider_GetInterfaceNameReply,
#endif
    NetworkSocketChannel_SendDataReply,
    NetworkSocketChannel_SendStringReply,
    NetworkStorageManager_CacheStorageAllCachesReply,
    NetworkStorageManager_CacheStorageClearMemoryRepresentationReply,
    NetworkStorageManager_CacheStorageOpenCacheReply,
    NetworkStorageManager_CacheStoragePutRecordsReply,
    NetworkStorageManager_CacheStorageRemoveCacheReply,
    NetworkStorageManager_CacheStorageRemoveRecordsReply,
    NetworkStorageManager_CacheStorageRepresentationReply,
    NetworkStorageManager_CacheStorageRetrieveRecordsReply,
    NetworkStorageManager_ClearReply,
    NetworkStorageManager_CloseSyncAccessHandleReply,
    NetworkStorageManager_CloseWritableReply,
    NetworkStorageManager_ConnectToStorageAreaReply,
    NetworkStorageManager_CreateSyncAccessHandleReply,
    NetworkStorageManager_CreateWritableReply,
    NetworkStorageManager_EstimateReply,
    NetworkStorageManager_ExecuteCommandForWritableReply,
    NetworkStorageManager_FileSystemGetDirectoryReply,
    NetworkStorageManager_GetDirectoryHandleReply,
    NetworkStorageManager_GetFileHandleReply,
    NetworkStorageManager_GetFileReply,
    NetworkStorageManager_GetHandleNamesReply,
    NetworkStorageManager_GetHandleReply,
    NetworkStorageManager_IsSameEntryReply,
    NetworkStorageManager_MoveReply,
    NetworkStorageManager_PersistReply,
    NetworkStorageManager_PersistedReply,
    NetworkStorageManager_RemoveEntryReply,
    NetworkStorageManager_RemoveItemReply,
    NetworkStorageManager_RequestNewCapacityForSyncAccessHandleReply,
    NetworkStorageManager_ResolveReply,
    NetworkStorageManager_SetItemReply,
    NetworkTransportSession_CreateBidirectionalStreamReply,
    NetworkTransportSession_CreateOutgoingUnidirectionalStreamReply,
    NetworkTransportSession_SendDatagramReply,
    NetworkTransportSession_StreamSendBytesReply,
#if ENABLE(WEB_PUSH_NOTIFICATIONS)
    NotificationManagerMessageHandler_GetPermissionStateReply,
#endif
#if ENABLE(NOTIFICATIONS)
    NotificationManagerMessageHandler_RequestPermissionReply,
    NotificationManagerMessageHandler_ShowNotificationReply,
#endif
    PlatformXRSystem_EnumerateImmersiveXRDevicesReply,
    PlatformXRSystem_RequestFrameReply,
    PlatformXRSystem_RequestPermissionOnSessionFeaturesReply,
    PushClientConnection_GetAppBadgeForTestingReply,
    PushClientConnection_GetNotificationsReply,
    PushClientConnection_GetPendingPushMessageReply,
    PushClientConnection_GetPendingPushMessagesReply,
    PushClientConnection_GetPushPermissionStateReply,
    PushClientConnection_GetPushSubscriptionReply,
    PushClientConnection_GetPushTopicsForTestingReply,
    PushClientConnection_IncrementSilentPushCountReply,
    PushClientConnection_InjectEncryptedPushMessageForTestingReply,
    PushClientConnection_InjectPushMessageForTestingReply,
    PushClientConnection_RemoveAllPushSubscriptionsReply,
    PushClientConnection_RemovePushSubscriptionsForOriginReply,
    PushClientConnection_RequestPushPermissionReply,
    PushClientConnection_SetProtocolVersionForTestingReply,
    PushClientConnection_SetPublicTokenForTestingReply,
    PushClientConnection_SetPushAndNotificationsEnabledForOriginReply,
    PushClientConnection_SetServiceWorkerIsBeingInspectedReply,
    PushClientConnection_ShowNotificationReply,
    PushClientConnection_SubscribeToPushServiceReply,
    PushClientConnection_UnsubscribeFromPushServiceReply,
    RemoteAudioDestinationManager_CreateAudioDestinationReply,
    RemoteAudioDestinationManager_StartAudioDestinationReply,
    RemoteAudioDestinationManager_StopAudioDestinationReply,
    RemoteAudioMediaStreamTrackRendererInternalUnitManager_CreateUnitReply,
    RemoteBarcodeDetector_DetectReply,
    RemoteBuffer_CopyReply,
    RemoteBuffer_MapAsyncReply,
    RemoteCDMInstanceProxy_InitializeWithConfigurationReply,
    RemoteCDMInstanceProxy_SetServerCertificateReply,
    RemoteCDMInstanceSessionProxy_CloseSessionReply,
    RemoteCDMInstanceSessionProxy_LoadSessionReply,
    RemoteCDMInstanceSessionProxy_RemoveSessionDataReply,
    RemoteCDMInstanceSessionProxy_RequestLicenseReply,
    RemoteCDMInstanceSessionProxy_UpdateLicenseReply,
    RemoteCDMProxy_GetSupportedConfigurationReply,
    RemoteDevice_CreateComputePipelineAsyncReply,
    RemoteDevice_CreateRenderPipelineAsyncReply,
    RemoteDevice_PopErrorScopeReply,
    RemoteDevice_ResolveDeviceLostPromiseReply,
    RemoteDevice_ResolveUncapturedErrorEventReply,
    RemoteFaceDetector_DetectReply,
    RemoteLegacyCDMFactoryProxy_RemoveSessionReply,
    RemoteMediaEngineConfigurationFactoryProxy_CreateDecodingConfigurationReply,
    RemoteMediaEngineConfigurationFactoryProxy_CreateEncodingConfigurationReply,
    RemoteMediaPlayerProxy_DidLoadingProgressReply,
#if ENABLE(MEDIA_SOURCE)
    RemoteMediaPlayerProxy_LoadMediaSourceReply,
#endif
    RemoteMediaPlayerProxy_LoadReply,
    RemoteMediaPlayerProxy_PerformTaskAtTimeReply,
    RemoteMediaPlayerProxy_RequestHostingContextReply,
    RemoteMediaResourceManager_DataReceivedReply,
    RemoteMediaResourceManager_RedirectReceivedReply,
    RemoteMediaResourceManager_ResponseReceivedReply,
    RemoteMediaSessionCoordinatorProxy_CoordinatePauseReply,
    RemoteMediaSessionCoordinatorProxy_CoordinatePlayReply,
    RemoteMediaSessionCoordinatorProxy_CoordinateSeekToReply,
    RemoteMediaSessionCoordinatorProxy_CoordinateSetTrackReply,
    RemoteMediaSessionCoordinatorProxy_JoinReply,
    RemoteMediaSessionCoordinator_PauseSessionReply,
    RemoteMediaSessionCoordinator_PlaySessionReply,
    RemoteMediaSessionCoordinator_SeekSessionToTimeReply,
    RemoteMediaSessionCoordinator_SetSessionTrackReply,
    RemoteQueue_OnSubmittedWorkDoneReply,
    RemoteQueue_WriteBufferReply,
    RemoteQueue_WriteTextureReply,
    RemoteRenderingBackend_GetImageBufferResourceLimitsForTestingReply,
    RemoteRenderingBackend_GetRemoteBarcodeDetectorSupportedFormatsReply,
    RemoteSampleBufferDisplayLayerManager_CreateLayerReply,
    RemoteShaderModule_CompilationInfoReply,
    RemoteSourceBufferProxy_AppendReply,
    RemoteSourceBufferProxy_BufferedSamplesForTrackIdReply,
    RemoteSourceBufferProxy_ComputeSeekTimeReply,
    RemoteSourceBufferProxy_EnqueuedSamplesForTrackIDReply,
    RemoteSourceBufferProxy_RemoveCodedFramesReply,
    RemoteSourceBufferProxy_SetMaximumBufferSizeReply,
    RemoteTextDetector_DetectReply,
    RemoteWCLayerTreeHost_UpdateReply,
    RemoteWebInspectorUIProxy_LoadReply,
    RemoteWebInspectorUIProxy_PickColorFromScreenReply,
    SourceBufferPrivateRemoteMessageReceiver_SourceBufferPrivateBufferedChangedReply,
    SourceBufferPrivateRemoteMessageReceiver_SourceBufferPrivateDidAttachReply,
    SourceBufferPrivateRemoteMessageReceiver_SourceBufferPrivateDidReceiveInitializationSegmentReply,
    SourceBufferPrivateRemoteMessageReceiver_SourceBufferPrivateDurationChangedReply,
    WebAutomationSessionProxy_ComputeElementLayoutReply,
    WebAutomationSessionProxy_DeleteCookieReply,
    WebAutomationSessionProxy_EvaluateJavaScriptFunctionReply,
    WebAutomationSessionProxy_FocusFrameReply,
    WebAutomationSessionProxy_GetComputedLabelReply,
    WebAutomationSessionProxy_GetComputedRoleReply,
    WebAutomationSessionProxy_GetCookiesForFrameReply,
    WebAutomationSessionProxy_ResolveChildFrameWithNameReply,
    WebAutomationSessionProxy_ResolveChildFrameWithNodeHandleReply,
    WebAutomationSessionProxy_ResolveChildFrameWithOrdinalReply,
    WebAutomationSessionProxy_ResolveParentFrameReply,
    WebAutomationSessionProxy_SelectOptionElementReply,
    WebAutomationSessionProxy_SetFilesForInputFileUploadReply,
    WebAutomationSessionProxy_SnapshotRectForScreenshotReply,
    WebAutomationSessionProxy_TakeScreenshotReply,
    WebBroadcastChannelRegistry_PostMessageToRemoteReply,
    WebCookieManager_DeleteAllCookiesModifiedSinceReply,
    WebCookieManager_DeleteAllCookiesReply,
    WebCookieManager_DeleteCookieReply,
    WebCookieManager_DeleteCookiesForHostnamesReply,
    WebCookieManager_GetAllCookiesReply,
    WebCookieManager_GetCookiesReply,
    WebCookieManager_GetHTTPCookieAcceptPolicyReply,
    WebCookieManager_GetHostnamesWithCookiesReply,
#if USE(SOUP)
    WebCookieManager_ReplaceCookiesReply,
#endif
    WebCookieManager_SetCookieReply,
    WebCookieManager_SetCookiesReply,
    WebCookieManager_SetHTTPCookieAcceptPolicyReply,
    WebExtensionContextProxy_DispatchRuntimeConnectEventReply,
    WebExtensionContextProxy_DispatchRuntimeMessageEventReply,
    WebExtensionContext_ActionGetBadgeTextReply,
    WebExtensionContext_ActionGetEnabledReply,
    WebExtensionContext_ActionGetPopupReply,
    WebExtensionContext_ActionGetTitleReply,
    WebExtensionContext_ActionOpenPopupReply,
    WebExtensionContext_ActionSetBadgeTextReply,
    WebExtensionContext_ActionSetEnabledReply,
    WebExtensionContext_ActionSetIconReply,
    WebExtensionContext_ActionSetPopupReply,
    WebExtensionContext_ActionSetTitleReply,
    WebExtensionContext_AlarmsClearAllReply,
    WebExtensionContext_AlarmsClearReply,
    WebExtensionContext_AlarmsGetAllReply,
    WebExtensionContext_AlarmsGetReply,
#if ENABLE(WK_WEB_EXTENSIONS_BOOKMARKS)
    WebExtensionContext_BookmarksCreateReply,
    WebExtensionContext_BookmarksGetChildrenReply,
    WebExtensionContext_BookmarksGetRecentReply,
    WebExtensionContext_BookmarksGetReply,
    WebExtensionContext_BookmarksGetSubTreeReply,
    WebExtensionContext_BookmarksGetTreeReply,
    WebExtensionContext_BookmarksMoveReply,
    WebExtensionContext_BookmarksRemoveReply,
    WebExtensionContext_BookmarksRemoveTreeReply,
    WebExtensionContext_BookmarksSearchReply,
    WebExtensionContext_BookmarksUpdateReply,
#endif
    WebExtensionContext_CommandsGetAllReply,
    WebExtensionContext_CookiesGetAllCookieStoresReply,
    WebExtensionContext_CookiesGetAllReply,
    WebExtensionContext_CookiesGetReply,
    WebExtensionContext_CookiesRemoveReply,
    WebExtensionContext_CookiesSetReply,
    WebExtensionContext_DeclarativeNetRequestDisplayActionCountAsBadgeTextReply,
    WebExtensionContext_DeclarativeNetRequestGetDynamicRulesReply,
    WebExtensionContext_DeclarativeNetRequestGetEnabledRulesetsReply,
    WebExtensionContext_DeclarativeNetRequestGetMatchedRulesReply,
    WebExtensionContext_DeclarativeNetRequestGetSessionRulesReply,
    WebExtensionContext_DeclarativeNetRequestIncrementActionCountReply,
    WebExtensionContext_DeclarativeNetRequestUpdateDynamicRulesReply,
    WebExtensionContext_DeclarativeNetRequestUpdateEnabledRulesetsReply,
    WebExtensionContext_DeclarativeNetRequestUpdateSessionRulesReply,
#if ENABLE(INSPECTOR_EXTENSIONS)
    WebExtensionContext_DevToolsInspectedWindowEvalReply,
    WebExtensionContext_DevToolsPanelsCreateReply,
#endif
    WebExtensionContext_ExtensionIsAllowedIncognitoAccessReply,
    WebExtensionContext_MenusCreateReply,
    WebExtensionContext_MenusRemoveAllReply,
    WebExtensionContext_MenusRemoveReply,
    WebExtensionContext_MenusUpdateReply,
    WebExtensionContext_PermissionsContainsReply,
    WebExtensionContext_PermissionsGetAllReply,
    WebExtensionContext_PermissionsRemoveReply,
    WebExtensionContext_PermissionsRequestReply,
    WebExtensionContext_RuntimeConnectNativeReply,
    WebExtensionContext_RuntimeConnectReply,
    WebExtensionContext_RuntimeGetBackgroundPageReply,
    WebExtensionContext_RuntimeOpenOptionsPageReply,
    WebExtensionContext_RuntimeSendMessageReply,
    WebExtensionContext_RuntimeSendNativeMessageReply,
    WebExtensionContext_RuntimeWebPageConnectReply,
    WebExtensionContext_RuntimeWebPageSendMessageReply,
    WebExtensionContext_ScriptingExecuteScriptReply,
    WebExtensionContext_ScriptingGetRegisteredScriptsReply,
    WebExtensionContext_ScriptingInsertCSSReply,
    WebExtensionContext_ScriptingRegisterContentScriptsReply,
    WebExtensionContext_ScriptingRemoveCSSReply,
    WebExtensionContext_ScriptingUnregisterContentScriptsReply,
    WebExtensionContext_ScriptingUpdateRegisteredScriptsReply,
#if ENABLE(WK_WEB_EXTENSIONS_SIDEBAR)
    WebExtensionContext_SidebarCloseReply,
    WebExtensionContext_SidebarGetActionClickBehaviorReply,
    WebExtensionContext_SidebarGetOptionsReply,
    WebExtensionContext_SidebarGetTitleReply,
    WebExtensionContext_SidebarIsOpenReply,
    WebExtensionContext_SidebarOpenReply,
    WebExtensionContext_SidebarSetActionClickBehaviorReply,
    WebExtensionContext_SidebarSetIconReply,
    WebExtensionContext_SidebarSetOptionsReply,
    WebExtensionContext_SidebarSetTitleReply,
    WebExtensionContext_SidebarToggleReply,
#endif
    WebExtensionContext_StorageClearReply,
    WebExtensionContext_StorageGetBytesInUseReply,
    WebExtensionContext_StorageGetKeysReply,
    WebExtensionContext_StorageGetReply,
    WebExtensionContext_StorageRemoveReply,
    WebExtensionContext_StorageSetAccessLevelReply,
    WebExtensionContext_StorageSetReply,
    WebExtensionContext_TabsCaptureVisibleTabReply,
    WebExtensionContext_TabsConnectReply,
    WebExtensionContext_TabsCreateReply,
    WebExtensionContext_TabsDetectLanguageReply,
    WebExtensionContext_TabsDuplicateReply,
    WebExtensionContext_TabsExecuteScriptReply,
    WebExtensionContext_TabsGetCurrentReply,
    WebExtensionContext_TabsGetReply,
    WebExtensionContext_TabsGetZoomReply,
    WebExtensionContext_TabsGoBackReply,
    WebExtensionContext_TabsGoForwardReply,
    WebExtensionContext_TabsInsertCSSReply,
    WebExtensionContext_TabsQueryReply,
    WebExtensionContext_TabsReloadReply,
    WebExtensionContext_TabsRemoveCSSReply,
    WebExtensionContext_TabsRemoveReply,
    WebExtensionContext_TabsSendMessageReply,
    WebExtensionContext_TabsSetZoomReply,
    WebExtensionContext_TabsToggleReaderModeReply,
    WebExtensionContext_TabsUpdateReply,
    WebExtensionContext_WebNavigationGetAllFramesReply,
    WebExtensionContext_WebNavigationGetFrameReply,
    WebExtensionContext_WindowsCreateReply,
    WebExtensionContext_WindowsGetAllReply,
    WebExtensionContext_WindowsGetLastFocusedReply,
    WebExtensionContext_WindowsGetReply,
    WebExtensionContext_WindowsRemoveReply,
    WebExtensionContext_WindowsUpdateReply,
    WebFrameProxy_FindFocusableElementDescendingIntoRemoteFrameReply,
    WebFrame_FindFocusableElementDescendingIntoRemoteFrameReply,
    WebFrame_GetFrameInfoReply,
    WebFullScreenManagerProxy_BeganEnterFullScreenReply,
    WebFullScreenManagerProxy_BeganExitFullScreenReply,
    WebFullScreenManagerProxy_EnterFullScreenReply,
    WebFullScreenManagerProxy_ExitFullScreenReply,
    WebFullScreenManager_EnterFullScreenForOwnerElementsReply,
    WebFullScreenManager_ExitFullScreenInMainFrameReply,
    WebFullScreenManager_RequestRestoreFullScreenReply,
    WebInspectorUIProxy_LoadReply,
    WebInspectorUIProxy_PickColorFromScreenReply,
    WebInspector_ShowReply,
    WebLockRegistryProxy_AbortLockRequestReply,
    WebLockRegistryProxy_SnapshotReply,
#if ENABLE(WRITING_TOOLS)
    WebPageProxy_AddTextAnimationForAnimationIDWithCompletionHandlerReply,
#endif
#if USE(SYSTEM_PREVIEW)
    WebPageProxy_BeginSystemPreviewReply,
#endif
    WebPageProxy_DecidePolicyForNavigationActionAsyncReply,
    WebPageProxy_DecidePolicyForNewWindowActionReply,
    WebPageProxy_DecidePolicyForResponseReply,
#if HAVE(DIGITAL_CREDENTIALS_UI)
    WebPageProxy_DismissDigitalCredentialsPickerReply,
#endif
    WebPageProxy_DocumentURLForConsoleLogReply,
#if ENABLE(MEDIA_STREAM)
    WebPageProxy_EnumerateMediaDevicesForFrameReply,
#endif
    WebPageProxy_FocusFromServiceWorkerReply,
    WebPageProxy_HandleMessageWithAsyncReplyReply,
#if PLATFORM(IOS_FAMILY)
    WebPageProxy_IsPotentialTapInProgressReply,
#endif
#if ENABLE(ARKIT_INLINE_PREVIEW)
    WebPageProxy_ModelElementAnimationCurrentTimeReply,
    WebPageProxy_ModelElementAnimationDurationReply,
#endif
#if ENABLE(ARKIT_INLINE_PREVIEW_MAC)
    WebPageProxy_ModelElementCreateRemotePreviewReply,
#endif
#if ENABLE(ARKIT_INLINE_PREVIEW)
    WebPageProxy_ModelElementGetCameraReply,
    WebPageProxy_ModelElementHasAudioReply,
    WebPageProxy_ModelElementIsLoopingAnimationReply,
    WebPageProxy_ModelElementIsMutedReply,
    WebPageProxy_ModelElementIsPlayingAnimationReply,
#endif
#if ENABLE(ARKIT_INLINE_PREVIEW_MAC)
    WebPageProxy_ModelElementLoadRemotePreviewReply,
#endif
#if ENABLE(ARKIT_INLINE_PREVIEW)
    WebPageProxy_ModelElementSetAnimationCurrentTimeReply,
    WebPageProxy_ModelElementSetAnimationIsPlayingReply,
    WebPageProxy_ModelElementSetCameraReply,
    WebPageProxy_ModelElementSetIsLoopingAnimationReply,
    WebPageProxy_ModelElementSetIsMutedReply,
#endif
#if ENABLE(ARKIT_INLINE_PREVIEW_MAC)
    WebPageProxy_ModelElementSizeDidChangeReply,
    WebPageProxy_ModelInlinePreviewUUIDsReply,
#endif
    WebPageProxy_RequestCookieConsentReply,
    WebPageProxy_RequestNotificationPermissionReply,
#if USE(QUICK_LOOK)
    WebPageProxy_RequestPasswordForQuickLookDocumentInMainFrameReply,
#endif
#if ENABLE(POINTER_LOCK)
    WebPageProxy_RequestPointerLockReply,
    WebPageProxy_RequestPointerUnlockReply,
#endif
#if ENABLE(IMAGE_ANALYSIS)
    WebPageProxy_RequestTextRecognitionReply,
#endif
    WebPageProxy_ResolveAccessibilityHitTestForTestingReply,
#if PLATFORM(GTK) || PLATFORM(WPE)
    WebPageProxy_SendMessageToWebViewWithReplyReply,
#endif
#if ENABLE(DEVICE_ORIENTATION)
    WebPageProxy_ShouldAllowDeviceOrientationAndMotionAccessReply,
#endif
    WebPageProxy_ShouldGoToBackForwardListItemReply,
    WebPageProxy_ShowContactPickerReply,
#if HAVE(DIGITAL_CREDENTIALS_UI)
    WebPageProxy_ShowDigitalCredentialsPickerReply,
#endif
#if PLATFORM(GTK)
    WebPageProxy_ShowEmojiPickerReply,
#endif
#if ENABLE(MEDIA_CONTROLS_CONTEXT_MENUS) && USE(UICONTEXTMENU)
    WebPageProxy_ShowMediaControlsContextMenuReply,
#endif
#if ENABLE(PDF_PLUGIN) && PLATFORM(MAC)
    WebPageProxy_ShowPDFContextMenuReply,
#endif
    WebPageProxy_ShowShareSheetReply,
#if ENABLE(SPEECH_SYNTHESIS)
    WebPageProxy_SpeechSynthesisPauseReply,
    WebPageProxy_SpeechSynthesisResumeReply,
    WebPageProxy_SpeechSynthesisSetFinishedCallbackReply,
    WebPageProxy_SpeechSynthesisSpeakReply,
#endif
#if ENABLE(APPLE_PAY_AMS_UI)
    WebPageProxy_StartApplePayAMSUISessionReply,
#endif
#if ENABLE(MEDIA_STREAM)
    WebPageProxy_ValidateCaptureStateUpdateReply,
#endif
    WebPageProxy_WillSubmitFormReply,
    WebPageTesting_ClearCachedBackForwardListCountsReply,
    WebPageTesting_DisplayAndTrackRepaintsReply,
    WebPageTesting_IsLayerTreeFrozenReply,
    WebPageTesting_SetObscuredContentInsetsReply,
    WebPageTesting_SetTracksRepaintsReply,
#if PLATFORM(COCOA)
    WebPage_AddDictationAlternativeReply,
#endif
    WebPage_AddLayerForFindOverlayReply,
    WebPage_AdjustVisibilityForTargetedElementsReply,
#if PLATFORM(IOS_FAMILY)
    WebPage_ApplyAutocorrectionReply,
#endif
#if PLATFORM(MAC)
    WebPage_AttributedSubstringForCharacterRangeAsyncReply,
#endif
#if PLATFORM(IOS_FAMILY)
    WebPage_BeginSelectionInDirectionReply,
#endif
#if PLATFORM(COCOA)
    WebPage_CharacterIndexForPointAsyncReply,
#endif
#if PLATFORM(IOS_FAMILY)
    WebPage_ClearServiceWorkerEntitlementOverrideReply,
    WebPage_CommitPotentialTapReply,
#endif
    WebPage_CompleteTextManipulationReply,
#if ENABLE(WRITING_TOOLS)
    WebPage_CompositionSessionDidReceiveTextWithReplacementRangeReply,
#endif
    WebPage_ComputePagesForPrintingDuringDOMPrintOperationReply,
    WebPage_ComputePagesForPrintingReply,
    WebPage_ContentsToRootViewPointReply,
    WebPage_ContentsToRootViewRectReply,
    WebPage_CountStringMatchesReply,
#if ENABLE(APP_HIGHLIGHTS)
    WebPage_CreateAppHighlightInSelectedRangeReply,
#endif
#if PLATFORM(COCOA)
    WebPage_CreateBitmapsFromImageDataReply,
#endif
#if ENABLE(MEDIA_SESSION_COORDINATOR)
    WebPage_CreateMediaSessionCoordinatorReply,
#endif
    WebPage_CreateTextFragmentDirectiveFromSelectionReply,
#if PLATFORM(COCOA)
    WebPage_CreateTextIndicatorForElementWithIDReply,
#endif
#if ENABLE(WRITING_TOOLS)
    WebPage_CreateTextIndicatorForTextAnimationIDReply,
#endif
#if PLATFORM(COCOA)
    WebPage_DecodeImageDataReply,
#endif
#if ENABLE(WRITING_TOOLS)
    WebPage_DecorateTextReplacementsForActiveWritingToolsSessionReply,
#endif
#if ENABLE(DATA_DETECTION)
    WebPage_DetectDataInAllFramesReply,
#endif
#if PLATFORM(COCOA)
    WebPage_DictationAlternativesAtSelectionReply,
#endif
    WebPage_DidGetLoadDecisionForIconReply,
#if PLATFORM(IOS_FAMILY)
    WebPage_DispatchWheelEventWithoutScrollingReply,
#endif
#if ENABLE(DRAG_SUPPORT)
    WebPage_DragEndedReply,
#endif
#if PLATFORM(GTK)
    WebPage_DrawPagesForPrintingDuringDOMPrintOperationReply,
    WebPage_DrawPagesForPrintingReply,
#endif
#if PLATFORM(COCOA)
    WebPage_DrawPagesToPDFDuringDOMPrintOperationReply,
    WebPage_DrawPagesToPDFReply,
    WebPage_DrawRectToImageDuringDOMPrintOperationReply,
    WebPage_DrawRectToImageReply,
#endif
#if (PLATFORM(COCOA) && PLATFORM(IOS_FAMILY))
    WebPage_DrawToImageReply,
#endif
#if PLATFORM(COCOA)
    WebPage_DrawToPDFReply,
#endif
#if (PLATFORM(COCOA) && PLATFORM(IOS_FAMILY))
    WebPage_DrawToPDFiOSReply,
#endif
    WebPage_EndPrintingDuringDOMPrintOperationReply,
    WebPage_EndPrintingReply,
    WebPage_ExecuteEditCommandWithCallbackReply,
#if PLATFORM(IOS_FAMILY)
    WebPage_ExtendSelectionForReplacementReply,
    WebPage_ExtendSelectionReply,
#endif
    WebPage_FindRectsForStringMatchesReply,
#if ENABLE(IMAGE_ANALYSIS)
    WebPage_FindStringIncludingImagesReply,
#endif
    WebPage_FindStringMatchesReply,
    WebPage_FindStringReply,
    WebPage_FindTextRangesForStringMatchesReply,
#if PLATFORM(COCOA)
    WebPage_FirstRectForCharacterRangeAsyncReply,
#endif
#if PLATFORM(IOS_FAMILY)
    WebPage_FocusNextFocusedElementReply,
    WebPage_FocusTextInputContextAndPlaceCaretReply,
#endif
    WebPage_GetAccessibilityTreeDataReply,
#if ENABLE(APPLICATION_MANIFEST)
    WebPage_GetApplicationManifestReply,
#endif
    WebPage_GetBytecodeProfileReply,
#if PLATFORM(COCOA)
    WebPage_GetContentsAsAttributedStringReply,
#endif
#if ENABLE(MHTML)
    WebPage_GetContentsAsMHTMLDataReply,
#endif
    WebPage_GetContentsAsStringReply,
    WebPage_GetFrameTreeReply,
#if PLATFORM(COCOA)
    WebPage_GetInformationFromImageDataReply,
#endif
    WebPage_GetLoadedSubresourceDomainsReply,
    WebPage_GetMainResourceDataOfFrameReply,
#if PLATFORM(COCOA)
    WebPage_GetMarkedRangeAsyncReply,
#endif
    WebPage_GetPDFFirstPageSizeReply,
    WebPage_GetProcessDisplayNameReply,
#if PLATFORM(IOS_FAMILY)
    WebPage_GetRectsAtSelectionOffsetWithTextReply,
    WebPage_GetRectsForGranularityWithSelectionOffsetReply,
#endif
    WebPage_GetRenderTreeExternalRepresentationReply,
    WebPage_GetResourceDataFromFrameReply,
    WebPage_GetSamplingProfilerOutputReply,
#if PLATFORM(COCOA)
    WebPage_GetSelectedRangeAsyncReply,
#endif
    WebPage_GetSelectionAsWebArchiveDataReply,
#if PLATFORM(IOS_FAMILY)
    WebPage_GetSelectionContextReply,
#endif
    WebPage_GetSelectionOrContentsAsStringReply,
    WebPage_GetSourceForFrameReply,
    WebPage_GetTextFragmentMatchReply,
    WebPage_GetTextFragmentRangesReply,
    WebPage_GetWebArchiveOfFrameReply,
    WebPage_GetWebArchiveOfFrameWithFileNameReply,
#if PLATFORM(COCOA)
    WebPage_GetWebArchivesReply,
#endif
    WebPage_HandleWheelEventReply,
#if PLATFORM(COCOA)
    WebPage_HasMarkedTextReply,
#endif
#if ENABLE(ATTACHMENT_ELEMENT)
    WebPage_InsertAttachmentReply,
#endif
#if PLATFORM(IOS_FAMILY) && ENABLE(DRAG_SUPPORT)
    WebPage_InsertDroppedImagePlaceholdersReply,
#endif
#if PLATFORM(COCOA)
    WebPage_InsertTextPlaceholderReply,
#endif
    WebPage_LastNavigationWasAppInitiatedReply,
    WebPage_LoadAndDecodeImageReply,
#if PLATFORM(IOS_FAMILY)
    WebPage_MoveSelectionAtBoundaryWithDirectionReply,
    WebPage_MoveSelectionByOffsetReply,
#endif
    WebPage_NavigateServiceWorkerClientReply,
    WebPage_NumberOfVisibilityAdjustmentRectsReply,
#if ENABLE(PDF_PLUGIN) && PLATFORM(MAC)
    WebPage_OpenPDFWithPreviewReply,
#endif
#if ENABLE(ACCESSIBILITY_ANIMATION_CONTROL)
    WebPage_PauseAllAnimationsReply,
#endif
    WebPage_PauseAllMediaPlaybackReply,
#if PLATFORM(IOS_FAMILY)
    WebPage_PerformActionOnElementReply,
#endif
#if PLATFORM(GTK) && ENABLE(DRAG_SUPPORT) || !PLATFORM(GTK) && ENABLE(DRAG_SUPPORT)
    WebPage_PerformDragControllerActionReply,
#endif
#if !PLATFORM(GTK) && ENABLE(DRAG_SUPPORT)
    WebPage_PerformDragOperationReply,
#endif
    WebPage_PerformHitTestForMouseEventReply,
#if ENABLE(ACCESSIBILITY_ANIMATION_CONTROL)
    WebPage_PlayAllAnimationsReply,
#endif
#if PLATFORM(IOS_FAMILY)
    WebPage_PotentialTapAtPositionReply,
#endif
#if (PLATFORM(IOS_FAMILY) && ENABLE(REVEAL))
    WebPage_PrepareSelectionForContextMenuWithLocationInViewReply,
#endif
#if ENABLE(WRITING_TOOLS)
    WebPage_ProofreadingSessionDidReceiveSuggestionsReply,
    WebPage_ProofreadingSessionSuggestionTextRectsInRootViewCoordinatesReply,
#endif
    WebPage_RemoteDictionaryPopupInfoToRootViewReply,
#if ENABLE(DATA_DETECTION)
    WebPage_RemoveDataDetectedLinksReply,
#endif
    WebPage_RemoveLayerForFindOverlayReply,
#if PLATFORM(COCOA)
    WebPage_RemoveTextPlaceholderReply,
#endif
    WebPage_ReplaceMatchesReply,
#if PLATFORM(COCOA)
    WebPage_RequestActiveNowPlayingSessionInfoReply,
#endif
#if PLATFORM(IOS_FAMILY) && ENABLE(DRAG_SUPPORT)
    WebPage_RequestAdditionalItemsForDragSessionReply,
#endif
    WebPage_RequestAllTargetableElementsReply,
    WebPage_RequestAllTextAndRectsReply,
#if PLATFORM(IOS_FAMILY)
    WebPage_RequestAutocorrectionDataReply,
    WebPage_RequestDocumentEditingContextReply,
#endif
#if PLATFORM(IOS_FAMILY) && ENABLE(DRAG_SUPPORT)
    WebPage_RequestDragStartReply,
#endif
#if PLATFORM(IOS_FAMILY)
    WebPage_RequestEvasionRectsAboveSelectionReply,
    WebPage_RequestFocusedElementInformationReply,
#endif
    WebPage_RequestFontAttributesAtSelectionStartReply,
    WebPage_RequestImageBitmapReply,
    WebPage_RequestMediaPlaybackStateReply,
#if (PLATFORM(IOS_FAMILY) && ENABLE(REVEAL))
    WebPage_RequestRVItemInCurrentSelectedRangeReply,
#endif
    WebPage_RequestRectForFoundTextRangeReply,
    WebPage_RequestTargetedElementReply,
    WebPage_RequestTextExtractionReply,
    WebPage_ResetVisibilityAdjustmentsForTargetedElementsReply,
    WebPage_ResolveAccessibilityHitTestForTestingReply,
    WebPage_ResumeAllMediaPlaybackReply,
    WebPage_ResumeReply,
    WebPage_RunJavaScriptInFrameInScriptWorldReply,
#if ENABLE(PDF_PLUGIN) && PLATFORM(MAC)
    WebPage_SavePDFReply,
#endif
#if PLATFORM(IOS_FAMILY)
    WebPage_SelectPositionAtBoundaryWithDirectionReply,
    WebPage_SelectPositionAtPointReply,
    WebPage_SelectTextWithGranularityAtPointReply,
    WebPage_SelectWithGestureReply,
    WebPage_SelectWithTwoTouchesReply,
#endif
#if PLATFORM(GTK) || PLATFORM(WPE)
    WebPage_SendMessageToWebProcessExtensionWithReplyReply,
#endif
    WebPage_SetActivityStateReply,
    WebPage_SetInitialFocusReply,
    WebPage_SetIsSuspendedReply,
    WebPage_SetMutedReply,
#if ENABLE(WRITING_TOOLS)
    WebPage_SetSelectionForActiveWritingToolsSessionReply,
#endif
#if ENABLE(IMAGE_ANALYSIS_ENHANCEMENTS)
    WebPage_ShouldAllowRemoveBackgroundReply,
#endif
#if PLATFORM(IOS_FAMILY)
    WebPage_ShouldDismissKeyboardAfterTapAtPointReply,
#endif
    WebPage_SimulateClickOverFirstMatchingTextInViewportWithUserInteractionReply,
#if ENABLE(VIDEO_PRESENTATION_MODE)
    WebPage_StartPlayingPredominantVideoReply,
#endif
    WebPage_StartTextManipulationsReply,
    WebPage_StopMediaCaptureReply,
    WebPage_SuspendAllMediaPlaybackReply,
    WebPage_SuspendReply,
    WebPage_TakeSnapshotForTargetedElementReply,
    WebPage_TakeSnapshotReply,
#if PLATFORM(IOS_FAMILY)
    WebPage_TextInputContextsInRectReply,
#endif
#if ENABLE(WRITING_TOOLS)
    WebPage_TextPreviewDataForActiveWritingToolsSessionReply,
#endif
#if !ENABLE(IOS_TOUCH_EVENTS) && ENABLE(TOUCH_EVENTS)
    WebPage_TouchEventReply,
#endif
    WebPage_TryCloseReply,
    WebPage_URLSchemeTaskWillPerformRedirectionReply,
#if ENABLE(ATTACHMENT_ELEMENT)
    WebPage_UpdateAttachmentAttributesReply,
#endif
    WebPage_UpdateRenderingWithForcedRepaintReply,
#if PLATFORM(IOS_FAMILY)
    WebPage_UpdateSelectionWithDeltaReply,
    WebPage_UpdateSelectionWithExtentPointAndBoundaryReply,
    WebPage_UpdateSelectionWithExtentPointReply,
    WebPage_UpdateSelectionWithTouchesReply,
#endif
#if ENABLE(WRITING_TOOLS)
    WebPage_UpdateTextVisibilityForActiveWritingToolsSessionReply,
    WebPage_UpdateUnderlyingTextVisibilityForTextAnimationIDReply,
#endif
#if ENABLE(IMAGE_ANALYSIS)
    WebPage_UpdateWithTextRecognitionResultReply,
#endif
#if ENABLE(MEDIA_STREAM)
    WebPage_UserMediaAccessWasGrantedReply,
#endif
    WebPage_ValidateCommandReply,
#if ENABLE(WRITING_TOOLS)
    WebPage_WillBeginWritingToolsSessionReply,
    WebPage_WillEndWritingToolsSessionReply,
#endif
    WebPermissionControllerProxy_QueryReply,
#if ENABLE(GAMEPAD)
    WebProcessPool_PlayGamepadEffectReply,
    WebProcessPool_StopGamepadEffectsReply,
    WebProcessPool_StoppedUsingGamepadsReply,
#endif
#if ENABLE(REMOTE_INSPECTOR) && PLATFORM(COCOA)
    WebProcessProxy_CreateServiceWorkerDebuggableReply,
#endif
#if ENABLE(NOTIFICATION_EVENT)
    WebProcessProxy_GetNotificationsReply,
#endif
#if PLATFORM(GTK) || PLATFORM(WPE)
    WebProcessProxy_SendMessageToWebContextWithReplyReply,
#endif
#if (ENABLE(LOGD_BLOCKING_IN_WEBCONTENT) && ENABLE(STREAMING_IPC_IN_LOG_FORWARDING)) || (ENABLE(LOGD_BLOCKING_IN_WEBCONTENT) && !ENABLE(STREAMING_IPC_IN_LOG_FORWARDING))
    WebProcessProxy_SetupLogStreamReply,
#endif
    WebProcess_ClearCachedPageReply,
    WebProcess_DeleteAllCookiesReply,
    WebProcess_DeleteWebsiteDataForOriginReply,
    WebProcess_DeleteWebsiteDataForOriginsReply,
    WebProcess_DeleteWebsiteDataReply,
    WebProcess_EstablishRemoteWorkerContextConnectionToNetworkProcessReply,
    WebProcess_FetchWebsiteDataReply,
    WebProcess_GetActivePagesOriginsForTestingReply,
#if ENABLE(NOTIFY_BLOCKING)
    WebProcess_GetNotifyStateForTestingReply,
#endif
    WebProcess_InitializeWebProcessReply,
    WebProcess_IsJITEnabledReply,
    WebProcess_PrepareToSuspendReply,
    WebProcess_RegisterServiceWorkerClientsReply,
    WebProcess_ReleaseMemoryReply,
    WebProcess_ReloadExecutionContextsForOriginReply,
    WebProcess_SeedResourceLoadStatisticsForTestingReply,
    WebProcess_SendResourceLoadStatisticsDataImmediatelyReply,
    WebProcess_SetDomainsWithCrossPageStorageAccessReply,
    WebProcess_SetIsInProcessCacheReply,
#if ENABLE(CONTENT_EXTENSIONS)
    WebProcess_SetResourceMonitorContentRuleListAsyncReply,
#endif
    WebProcess_SetThirdPartyCookieBlockingModeReply,
    WebResourceLoader_WillSendRequestReply,
    WebSWClientConnection_FocusServiceWorkerClientReply,
    WebSWClientConnection_SetServiceWorkerClientIsControlledReply,
    WebSWContextManagerConnection_FireBackgroundFetchClickEventReply,
    WebSWContextManagerConnection_FireBackgroundFetchEventReply,
    WebSWContextManagerConnection_FireNotificationEventReply,
    WebSWContextManagerConnection_FirePushEventReply,
    WebSWServerConnection_AbortBackgroundFetchReply,
    WebSWServerConnection_AddCookieChangeSubscriptionsReply,
    WebSWServerConnection_AddRoutesReply,
    WebSWServerConnection_BackgroundFetchIdentifiersReply,
    WebSWServerConnection_BackgroundFetchInformationReply,
    WebSWServerConnection_CookieChangeSubscriptionsReply,
    WebSWServerConnection_DisableNavigationPreloadReply,
    WebSWServerConnection_EnableNavigationPreloadReply,
    WebSWServerConnection_GetNavigationPreloadStateReply,
#if ENABLE(WEB_PUSH_NOTIFICATIONS)
    WebSWServerConnection_GetNotificationsReply,
#endif
    WebSWServerConnection_GetPushPermissionStateReply,
    WebSWServerConnection_GetPushSubscriptionReply,
    WebSWServerConnection_GetRegistrationsReply,
    WebSWServerConnection_MatchBackgroundFetchReply,
    WebSWServerConnection_MatchRegistrationReply,
    WebSWServerConnection_RemoveCookieChangeSubscriptionsReply,
    WebSWServerConnection_RetrieveRecordResponseReply,
    WebSWServerConnection_ScheduleUnregisterJobInServerReply,
    WebSWServerConnection_SetNavigationPreloadHeaderValueReply,
    WebSWServerConnection_StartBackgroundFetchReply,
    WebSWServerConnection_StoreRegistrationsOnDiskReply,
    WebSWServerConnection_SubscribeToPushServiceReply,
    WebSWServerConnection_TerminateWorkerFromClientReply,
    WebSWServerConnection_UnsubscribeFromPushServiceReply,
    WebSWServerConnection_WhenRegistrationReadyReply,
    WebSWServerConnection_WhenServiceWorkerIsTerminatedForTestingReply,
    WebSWServerToContextConnection_ClaimReply,
    WebSWServerToContextConnection_FindClientByVisibleIdentifierReply,
    WebSWServerToContextConnection_FocusReply,
    WebSWServerToContextConnection_MatchAllReply,
    WebSWServerToContextConnection_NavigateReply,
    WebSWServerToContextConnection_OpenWindowReply,
    WebSWServerToContextConnection_SkipWaitingReply,
    WebScreenOrientationManagerProxy_LockReply,
    WebSharedWorkerContextManagerConnection_PostConnectEventReply,
    WebSharedWorkerObjectConnection_FetchScriptInClientReply,
    WebUserContentControllerProxy_DidPostMessageReply,
    FirstSynchronous,
    LastAsynchronous = FirstSynchronous - 1,
#if USE(AUDIO_SESSION)
    GPUConnectionToWebProcess_EnsureAudioSession,
#endif
    IPCConnectionTester_SyncMessage,
    IPCStreamTester_CheckAutoreleasePool,
    IPCStreamTester_SyncCrashOnZero,
    IPCStreamTester_SyncMessage,
    IPCStreamTester_SyncMessageEmptyReply,
    IPCStreamTester_SyncMessageNotStreamEncodableBoth,
    IPCStreamTester_SyncMessageNotStreamEncodableReply,
    IPCStreamTester_SyncMessageReturningSharedMemory1,
    IPCTester_ReleaseConnectionTester,
    IPCTester_ReleaseStreamTester,
    IPCTester_StopMessageTesting,
    IPCTester_SyncPing,
    IPCTester_SyncPingEmptyReply,
    NetworkConnectionToWebProcess_BlobSize,
    NetworkConnectionToWebProcess_BlobType,
    NetworkConnectionToWebProcess_CookieRequestHeaderFieldValue,
    NetworkConnectionToWebProcess_CookiesEnabledSync,
    NetworkConnectionToWebProcess_CookiesForDOM,
    NetworkConnectionToWebProcess_DomCookiesForHost,
    NetworkConnectionToWebProcess_GetNetworkLoadInformationResponse,
    NetworkConnectionToWebProcess_GetNetworkLoadIntermediateInformation,
    NetworkConnectionToWebProcess_GetRawCookies,
    NetworkConnectionToWebProcess_PerformSynchronousLoad,
    NetworkConnectionToWebProcess_TakeNetworkLoadInformationMetrics,
    NetworkConnectionToWebProcess_TestProcessIncomingSyncMessagesWhenWaitingForSyncReply,
    NetworkProcessProxy_TestProcessIncomingSyncMessagesWhenWaitingForSyncReply,
    NetworkProcess_ProcessWillSuspendImminentlyForTestingSync,
    NetworkProcess_ResetServiceWorkerFetchTimeoutForTesting,
    NetworkProcess_SetCacheModelSynchronouslyForTesting,
    NetworkProcess_SetServiceWorkerFetchTimeoutForTesting,
    NetworkStorageManager_ConnectToStorageAreaSync,
#if ENABLE(WEB_PUSH_NOTIFICATIONS)
    NotificationManagerMessageHandler_GetPermissionStateSync,
#endif
    RemoteAdapter_RequestDevice,
    RemoteAudioSessionProxy_TryToSetActive,
    RemoteBindGroup_UpdateExternalTextures,
    RemoteBuffer_GetMappedRange,
    RemoteCDMFactoryProxy_CreateCDM,
    RemoteCDMFactoryProxy_SupportsKeySystem,
    RemoteCDMInstanceProxy_CreateSession,
    RemoteCDMProxy_CreateInstance,
    RemoteCompositorIntegration_PaintCompositedResultsToCanvas,
    RemoteCompositorIntegration_PrepareForDisplay,
#if PLATFORM(COCOA)
    RemoteCompositorIntegration_RecreateRenderBuffers,
#endif
    RemoteGPU_IsValid,
    RemoteGPU_RequestAdapter,
#if ENABLE(WEBXR)
    RemoteGraphicsContextGL_AddFoveation,
#endif
    RemoteGraphicsContextGL_CheckFramebufferStatus,
    RemoteGraphicsContextGL_ClientWaitSync,
#if ENABLE(VIDEO) && PLATFORM(COCOA)
    RemoteGraphicsContextGL_CopyTextureFromVideoFrame,
#endif
    RemoteGraphicsContextGL_DrawSurfaceBufferToImageBuffer,
#if ENABLE(WEBXR)
    RemoteGraphicsContextGL_EnableRequiredWebXRExtensions,
#endif
    RemoteGraphicsContextGL_FenceSync,
    RemoteGraphicsContextGL_GetActiveAttrib,
    RemoteGraphicsContextGL_GetActiveUniform,
    RemoteGraphicsContextGL_GetActiveUniformBlockName,
    RemoteGraphicsContextGL_GetActiveUniformBlockiv,
    RemoteGraphicsContextGL_GetActiveUniforms,
    RemoteGraphicsContextGL_GetAttribLocation,
    RemoteGraphicsContextGL_GetBooleanv,
    RemoteGraphicsContextGL_GetBufferParameteri,
    RemoteGraphicsContextGL_GetBufferSubDataInline,
    RemoteGraphicsContextGL_GetBufferSubDataSharedMemory,
    RemoteGraphicsContextGL_GetErrors,
    RemoteGraphicsContextGL_GetFloatv,
    RemoteGraphicsContextGL_GetFragDataLocation,
    RemoteGraphicsContextGL_GetFramebufferAttachmentParameteri,
    RemoteGraphicsContextGL_GetInteger64,
    RemoteGraphicsContextGL_GetInteger64EXT,
    RemoteGraphicsContextGL_GetInteger64i,
    RemoteGraphicsContextGL_GetIntegeri_v,
    RemoteGraphicsContextGL_GetIntegerv,
    RemoteGraphicsContextGL_GetInternalformativ,
    RemoteGraphicsContextGL_GetProgramInfoLog,
    RemoteGraphicsContextGL_GetProgrami,
    RemoteGraphicsContextGL_GetQuery,
    RemoteGraphicsContextGL_GetQueryObjectiEXT,
    RemoteGraphicsContextGL_GetQueryObjectui,
    RemoteGraphicsContextGL_GetQueryObjectui64EXT,
    RemoteGraphicsContextGL_GetQueryiEXT,
    RemoteGraphicsContextGL_GetRenderbufferParameteri,
    RemoteGraphicsContextGL_GetSamplerParameterf,
    RemoteGraphicsContextGL_GetSamplerParameteri,
    RemoteGraphicsContextGL_GetShaderInfoLog,
    RemoteGraphicsContextGL_GetShaderPrecisionFormat,
    RemoteGraphicsContextGL_GetShaderSource,
    RemoteGraphicsContextGL_GetShaderi,
    RemoteGraphicsContextGL_GetString,
    RemoteGraphicsContextGL_GetSynci,
    RemoteGraphicsContextGL_GetTexParameterf,
    RemoteGraphicsContextGL_GetTexParameteri,
    RemoteGraphicsContextGL_GetTransformFeedbackVarying,
    RemoteGraphicsContextGL_GetTranslatedShaderSourceANGLE,
    RemoteGraphicsContextGL_GetUniformBlockIndex,
    RemoteGraphicsContextGL_GetUniformIndices,
    RemoteGraphicsContextGL_GetUniformLocation,
    RemoteGraphicsContextGL_GetUniformfv,
    RemoteGraphicsContextGL_GetUniformiv,
    RemoteGraphicsContextGL_GetUniformuiv,
    RemoteGraphicsContextGL_GetVertexAttribOffset,
    RemoteGraphicsContextGL_IsBuffer,
    RemoteGraphicsContextGL_IsEnabled,
    RemoteGraphicsContextGL_IsFramebuffer,
    RemoteGraphicsContextGL_IsProgram,
    RemoteGraphicsContextGL_IsQuery,
    RemoteGraphicsContextGL_IsQueryEXT,
    RemoteGraphicsContextGL_IsRenderbuffer,
    RemoteGraphicsContextGL_IsSampler,
    RemoteGraphicsContextGL_IsShader,
    RemoteGraphicsContextGL_IsSync,
    RemoteGraphicsContextGL_IsTexture,
    RemoteGraphicsContextGL_IsTransformFeedback,
    RemoteGraphicsContextGL_IsVertexArray,
#if PLATFORM(COCOA) || USE(GRAPHICS_LAYER_WC) || USE(GBM) || !PLATFORM(COCOA) && !USE(GRAPHICS_LAYER_WC) && !USE(GBM)
    RemoteGraphicsContextGL_PrepareForDisplay,
#endif
    RemoteGraphicsContextGL_ReadPixelsInline,
    RemoteGraphicsContextGL_ReadPixelsSharedMemory,
#if ENABLE(MEDIA_STREAM) || ENABLE(WEB_CODECS)
    RemoteGraphicsContextGL_SurfaceBufferToVideoFrame,
#endif
#if ENABLE(RE_DYNAMIC_CONTENT_SCALING)
    RemoteImageBufferSet_DynamicContentScalingDisplayList,
    RemoteImageBuffer_DynamicContentScalingDisplayList,
#endif
    RemoteImageBuffer_FilteredNativeImage,
    RemoteImageBuffer_FlushContextSync,
    RemoteImageBuffer_GetPixelBuffer,
    RemoteImageBuffer_GetPixelBufferWithNewMemory,
    RemoteImageBuffer_GetShareableBitmap,
    RemoteLegacyCDMFactoryProxy_CreateCDM,
    RemoteLegacyCDMFactoryProxy_SupportsKeySystem,
    RemoteLegacyCDMProxy_CreateSession,
    RemoteLegacyCDMProxy_SupportsMIMEType,
    RemoteLegacyCDMSessionProxy_CachedKeyForKeyID,
    RemoteLegacyCDMSessionProxy_GenerateKeyRequest,
    RemoteLegacyCDMSessionProxy_Update,
    RemoteMediaPlayerManagerProxy_GetSupportedTypes,
    RemoteMediaPlayerManagerProxy_SupportsKeySystem,
    RemoteMediaPlayerManagerProxy_SupportsTypeAndCodecs,
#if PLATFORM(IOS_FAMILY)
    RemoteMediaPlayerProxy_AccessLog,
#endif
#if PLATFORM(COCOA)
    RemoteMediaPlayerProxy_ColorSpace,
#endif
#if PLATFORM(IOS_FAMILY)
    RemoteMediaPlayerProxy_ErrorLog,
#endif
    RemoteMediaPlayerProxy_IsCrossOrigin,
#if PLATFORM(COCOA)
    RemoteMediaPlayerProxy_NativeImageForCurrentTime,
#endif
    RemoteMediaPlayerProxy_VideoFrameForCurrentTimeIfChanged,
    RemoteMediaSourceProxy_AddSourceBuffer,
#if PLATFORM(COCOA)
    RemoteRenderingBackend_PrepareImageBufferSetsForDisplaySync,
#endif
    RemoteSourceBufferProxy_CanSwitchToType,
    RemoteSourceBufferProxy_EvictCodedFrames,
    RemoteSourceBufferProxy_MinimumUpcomingPresentationTimeForTrackID,
#if PLATFORM(COCOA)
    RemoteVideoFrameObjectHeap_ConvertFrameBuffer,
    RemoteVideoFrameObjectHeap_PixelBuffer,
#endif
    WebPageProxy_AccessibilityScreenToRootView,
    WebPageProxy_BackForwardGoToItem,
    WebPageProxy_BackForwardItemAtIndex,
    WebPageProxy_BackForwardListContainsItem,
    WebPageProxy_BackForwardListCounts,
    WebPageProxy_BindRemoteAccessibilityFrames,
    WebPageProxy_CanUndoRedo,
    WebPageProxy_CheckGrammarOfString,
    WebPageProxy_CheckSpellingOfString,
#if USE(UNIFIED_TEXT_CHECKING)
    WebPageProxy_CheckTextOfParagraph,
#endif
    WebPageProxy_CreateNewPage,
    WebPageProxy_DecidePolicyForNavigationActionSync,
#if USE(DICTATION_ALTERNATIVES)
    WebPageProxy_DictationAlternatives,
#endif
#if PLATFORM(MAC)
    WebPageProxy_DismissCorrectionPanelSoon,
#endif
    WebPageProxy_ExceededDatabaseQuota,
#if PLATFORM(COCOA)
    WebPageProxy_ExecuteSavedCommandBySelector,
#endif
    WebPageProxy_ExecuteUndoRedo,
    WebPageProxy_FrameTextForTesting,
    WebPageProxy_GetGuessesForWord,
#if PLATFORM(COCOA)
    WebPageProxy_GetIsSpeaking,
#endif
    WebPageProxy_GetMenuBarIsVisible,
    WebPageProxy_GetStatusBarIsVisible,
    WebPageProxy_GetToolbarsAreVisible,
    WebPageProxy_GetWindowFrame,
    WebPageProxy_HandleSynchronousMessage,
#if PLATFORM(IOS_FAMILY)
    WebPageProxy_InterpretKeyEvent,
#endif
    WebPageProxy_LayerTreeAsTextForTesting,
    WebPageProxy_LoadRecentSearches,
    WebPageProxy_LoadSynchronousURLSchemeTask,
    WebPageProxy_PrintFrame,
    WebPageProxy_RenderTreeAsTextForTesting,
    WebPageProxy_RequestDOMPasteAccess,
    WebPageProxy_RootViewPointToScreen,
    WebPageProxy_RootViewRectToScreen,
    WebPageProxy_RootViewToAccessibilityScreen,
    WebPageProxy_RunBeforeUnloadConfirmPanel,
    WebPageProxy_RunJavaScriptAlert,
    WebPageProxy_RunJavaScriptConfirm,
    WebPageProxy_RunJavaScriptPrompt,
    WebPageProxy_ScreenToRootView,
    WebPageProxy_SerializeAndWrapCryptoKey,
#if ENABLE(ATTACHMENT_ELEMENT)
    WebPageProxy_SerializedAttachmentDataForIdentifiers,
#endif
    WebPageProxy_ShouldGoToBackForwardListItemSync,
#if ENABLE(SPEECH_SYNTHESIS)
    WebPageProxy_SpeechSynthesisVoiceList,
#endif
    WebPageProxy_SpellingUIIsShowing,
#if USE(APPKIT)
    WebPageProxy_SubstitutionsPanelIsShowing,
#endif
    WebPageProxy_UnwrapCryptoKey,
    WebPageTesting_IsEditingCommandEnabled,
    WebPage_BindRemoteAccessibilityFrames,
#if (PLATFORM(COCOA) && PLATFORM(IOS_FAMILY))
    WebPage_ComputePagesForPrintingiOS,
#endif
    WebPage_FrameTextForTesting,
#if PLATFORM(MAC)
    WebPage_GetAccessibilityWebProcessDebugInfo,
#endif
#if PLATFORM(COCOA)
    WebPage_GetDataSelectionForPasteboard,
    WebPage_GetStringSelectionForPasteboard,
#endif
    WebPage_LayerTreeAsTextForTesting,
#if PLATFORM(COCOA)
    WebPage_ReadSelectionFromPasteboard,
#endif
    WebPage_RenderTreeAsTextForTesting,
#if PLATFORM(COCOA)
    WebPage_ShouldDelayWindowOrderingEvent,
#endif
#if PLATFORM(IOS_FAMILY)
    WebPage_SyncApplyAutocorrection,
#endif
    WebPage_TestProcessIncomingSyncMessagesWhenWaitingForSyncReply,
#if PLATFORM(COCOA)
    WebPasteboardProxy_AddPasteboardTypes,
#endif
    WebPasteboardProxy_AllPasteboardItemInfo,
    WebPasteboardProxy_ContainsStringSafeForDOMToReadForType,
#if PLATFORM(COCOA)
    WebPasteboardProxy_ContainsURLStringSuitableForLoading,
    WebPasteboardProxy_GetNumberOfFiles,
    WebPasteboardProxy_GetPasteboardBufferForType,
#endif
#if PLATFORM(COCOA) || PLATFORM(GTK) || PLATFORM(WPE)
    WebPasteboardProxy_GetPasteboardChangeCount,
#endif
#if PLATFORM(COCOA)
    WebPasteboardProxy_GetPasteboardColor,
#endif
    WebPasteboardProxy_GetPasteboardItemsCount,
#if PLATFORM(COCOA)
    WebPasteboardProxy_GetPasteboardPathnamesForType,
    WebPasteboardProxy_GetPasteboardStringForType,
    WebPasteboardProxy_GetPasteboardStringsForType,
#endif
#if PLATFORM(COCOA) || USE(LIBWPE) && !PLATFORM(WPE)
    WebPasteboardProxy_GetPasteboardTypes,
#endif
#if PLATFORM(COCOA)
    WebPasteboardProxy_GetPasteboardURL,
#endif
#if PLATFORM(GTK) || PLATFORM(WPE)
    WebPasteboardProxy_GetTypes,
#endif
    WebPasteboardProxy_InformationForItemAtIndex,
#if PLATFORM(GTK) || PLATFORM(WPE)
    WebPasteboardProxy_ReadBuffer,
#endif
    WebPasteboardProxy_ReadBufferFromPasteboard,
#if PLATFORM(GTK) || PLATFORM(WPE)
    WebPasteboardProxy_ReadFilePaths,
#endif
    WebPasteboardProxy_ReadStringFromPasteboard,
#if PLATFORM(GTK) || PLATFORM(WPE)
    WebPasteboardProxy_ReadText,
#endif
    WebPasteboardProxy_ReadURLFromPasteboard,
#if PLATFORM(COCOA)
    WebPasteboardProxy_SetPasteboardBufferForType,
    WebPasteboardProxy_SetPasteboardColor,
    WebPasteboardProxy_SetPasteboardStringForType,
    WebPasteboardProxy_SetPasteboardTypes,
    WebPasteboardProxy_SetPasteboardURL,
#endif
#if (PLATFORM(COCOA) && ENABLE(IPC_TESTING_API))
    WebPasteboardProxy_TestIPCSharedMemory,
#endif
    WebPasteboardProxy_TypesSafeForDOMToReadAndWrite,
#if PLATFORM(COCOA)
    WebPasteboardProxy_URLStringSuitableForLoading,
#endif
    WebPasteboardProxy_WriteCustomData,
    WebProcessPool_HandleSynchronousMessage,
    WebProcessProxy_GetNetworkProcessConnection,
#if PLATFORM(MAC) || PLATFORM(MACCATALYST)
    WebProcessProxy_IsAXAuthenticated,
#endif
    WebProcessProxy_SerializeAndWrapCryptoKey,
    WebProcessProxy_ShouldTerminate,
    WebProcessProxy_UnwrapCryptoKey,
    WebProcessProxy_WaitForSharedPreferencesForWebProcessToSync,
    WebScreenOrientationManagerProxy_CurrentOrientation,
    WrappedAsyncMessageForTesting,
    Count,
    Invalid = Count,
    Last = Count - 1
};

namespace Detail {
struct MessageDescription {
    ASCIILiteral description;
    ReceiverName receiverName;
    bool messageAllowedWhenWaitingForSyncReply : 1;
    bool messageAllowedWhenWaitingForUnboundedSyncReply : 1;
};

using MessageDescriptionsArray = std::array<MessageDescription, static_cast<size_t>(MessageName::Count) + 1>;
extern const MessageDescriptionsArray messageDescriptions;

}

inline ReceiverName receiverName(MessageName messageName)
{
    messageName = std::min(messageName, MessageName::Last);
    return Detail::messageDescriptions[static_cast<size_t>(messageName)].receiverName;
}

inline ASCIILiteral description(MessageName messageName)
{
    messageName = std::min(messageName, MessageName::Last);
    return Detail::messageDescriptions[static_cast<size_t>(messageName)].description;
}

inline bool messageAllowedWhenWaitingForSyncReply(MessageName messageName)
{
    messageName = std::min(messageName, MessageName::Last);
    return Detail::messageDescriptions[static_cast<size_t>(messageName)].messageAllowedWhenWaitingForSyncReply;
}

inline bool messageAllowedWhenWaitingForUnboundedSyncReply(MessageName messageName)
{
    messageName = std::min(messageName, MessageName::Last);
    return Detail::messageDescriptions[static_cast<size_t>(messageName)].messageAllowedWhenWaitingForUnboundedSyncReply;
}

constexpr bool messageIsSync(MessageName name)
{
    return name >= MessageName::FirstSynchronous;
}

} // namespace IPC

namespace WTF {

template<> constexpr bool isValidEnum<IPC::MessageName>(std::underlying_type_t<IPC::MessageName> messageName)
{
    return messageName <= WTF::enumToUnderlyingType(IPC::MessageName::Last);
}

} // namespace WTF
