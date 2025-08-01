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

#if ENABLE(GPU_PROCESS)

#include "ArgumentCoders.h"
#include "Connection.h"
#include "ConnectionHandle.h"
#include "GPUProcessConnectionParameters.h"
#include "GPUProcessCreationParameters.h"
#include "GPUProcessSessionParameters.h"
#include "MessageNames.h"
#include "SandboxExtension.h"
#include <WebCore/IntDegrees.h>
#include <WebCore/ProcessIdentity.h>
#include <WebCore/ShareableBitmapHandle.h>
#include <span>
#include <wtf/Forward.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>
#include <wtf/Vector.h>
#include <wtf/text/WTFString.h>

namespace IPC {
class SharedBufferReference;
class SharedFileHandle;
}

namespace PAL {
class SessionID;
}

namespace WebCore {
class CaptureDevice;
struct MediaPlayerIdentifierType;
using MediaPlayerIdentifier = ObjectIdentifier<MediaPlayerIdentifierType>;
struct PageIdentifierType;
using PageIdentifier = ObjectIdentifier<PageIdentifierType>;
struct ProcessIdentifierType;
using ProcessIdentifier = ObjectIdentifier<ProcessIdentifierType>;
class SecurityOriginData;
enum class VideoFrameRotation : uint16_t;
enum class DisplayCapturePromptType : uint8_t;
struct MockMediaDevice;
struct ScreenProperties;
}

namespace WebKit {
struct CoreIPCAuditToken;
struct GPUProcessPreferences;
struct SharedPreferencesForWebProcess;
}

namespace Messages {
namespace GPUProcess {

static inline IPC::ReceiverName messageReceiverName()
{
#if ASSERT_ENABLED
    static std::once_flag onceFlag;
    std::call_once(
        onceFlag,
        [&] {
            ASSERT(isInGPUProcess());
        }
    );
#endif
    return IPC::ReceiverName::GPUProcess;
}

class InitializeGPUProcess {
public:
    using Arguments = std::tuple<WebKit::GPUProcessCreationParameters>;

    static IPC::MessageName name() { return IPC::MessageName::GPUProcess_InitializeGPUProcess; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::GPUProcess_InitializeGPUProcessReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    explicit InitializeGPUProcess(WebKit::GPUProcessCreationParameters&& processCreationParameters)
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
    WebKit::GPUProcessCreationParameters&& m_processCreationParameters;
};

class CreateGPUConnectionToWebProcess {
public:
    using Arguments = std::tuple<WebCore::ProcessIdentifier, PAL::SessionID, IPC::ConnectionHandle, WebKit::GPUProcessConnectionParameters>;

    static IPC::MessageName name() { return IPC::MessageName::GPUProcess_CreateGPUConnectionToWebProcess; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::GPUProcess_CreateGPUConnectionToWebProcessReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    CreateGPUConnectionToWebProcess(const WebCore::ProcessIdentifier& processIdentifier, const PAL::SessionID& sessionID, IPC::ConnectionHandle&& connectionHandle, WebKit::GPUProcessConnectionParameters&& parameters)
        : m_processIdentifier(processIdentifier)
        , m_sessionID(sessionID)
        , m_connectionHandle(WTFMove(connectionHandle))
        , m_parameters(WTFMove(parameters))
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_processIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        encoder << WTFMove(m_connectionHandle);
        encoder << WTFMove(m_parameters);
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ProcessIdentifier& m_processIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    IPC::ConnectionHandle&& m_connectionHandle;
    WebKit::GPUProcessConnectionParameters&& m_parameters;
};

class SharedPreferencesForWebProcessDidChange {
public:
    using Arguments = std::tuple<WebCore::ProcessIdentifier, WebKit::SharedPreferencesForWebProcess>;

    static IPC::MessageName name() { return IPC::MessageName::GPUProcess_SharedPreferencesForWebProcessDidChange; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::GPUProcess_SharedPreferencesForWebProcessDidChangeReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    SharedPreferencesForWebProcessDidChange(const WebCore::ProcessIdentifier& processIdentifier, const WebKit::SharedPreferencesForWebProcess& sharedPreferencesForWebProcess)
        : m_processIdentifier(processIdentifier)
        , m_sharedPreferencesForWebProcess(sharedPreferencesForWebProcess)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_processIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sharedPreferencesForWebProcess;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ProcessIdentifier& m_processIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::SharedPreferencesForWebProcess& m_sharedPreferencesForWebProcess;
};

class UpdateGPUProcessPreferences {
public:
    using Arguments = std::tuple<WebKit::GPUProcessPreferences>;

    static IPC::MessageName name() { return IPC::MessageName::GPUProcess_UpdateGPUProcessPreferences; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit UpdateGPUProcessPreferences(const WebKit::GPUProcessPreferences& preferences)
        : m_preferences(preferences)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_preferences;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::GPUProcessPreferences& m_preferences;
};

class UpdateSandboxAccess {
public:
    using Arguments = std::tuple<Vector<WebKit::SandboxExtensionHandle>>;

    static IPC::MessageName name() { return IPC::MessageName::GPUProcess_UpdateSandboxAccess; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit UpdateSandboxAccess(Vector<WebKit::SandboxExtensionHandle>&& extensions)
        : m_extensions(WTFMove(extensions))
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << WTFMove(m_extensions);
    }

private:
    Vector<WebKit::SandboxExtensionHandle>&& m_extensions;
};

class PrepareToSuspend {
public:
    using Arguments = std::tuple<bool, MonotonicTime>;

    static IPC::MessageName name() { return IPC::MessageName::GPUProcess_PrepareToSuspend; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::GPUProcess_PrepareToSuspendReply; }
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

    static IPC::MessageName name() { return IPC::MessageName::GPUProcess_ProcessDidResume; }
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

class AddSession {
public:
    using Arguments = std::tuple<PAL::SessionID, WebKit::GPUProcessSessionParameters>;

    static IPC::MessageName name() { return IPC::MessageName::GPUProcess_AddSession; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    AddSession(const PAL::SessionID& sessionID, WebKit::GPUProcessSessionParameters&& parameters)
        : m_sessionID(sessionID)
        , m_parameters(WTFMove(parameters))
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
        encoder << WTFMove(m_parameters);
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
    WebKit::GPUProcessSessionParameters&& m_parameters;
};

class RemoveSession {
public:
    using Arguments = std::tuple<PAL::SessionID>;

    static IPC::MessageName name() { return IPC::MessageName::GPUProcess_RemoveSession; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit RemoveSession(const PAL::SessionID& sessionID)
        : m_sessionID(sessionID)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_sessionID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const PAL::SessionID& m_sessionID;
};

#if ENABLE(MEDIA_STREAM)
class SetMockCaptureDevicesEnabled {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::GPUProcess_SetMockCaptureDevicesEnabled; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetMockCaptureDevicesEnabled(bool isEnabled)
        : m_isEnabled(isEnabled)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_isEnabled;
    }

private:
    bool m_isEnabled;
};
#endif

#if ENABLE(MEDIA_STREAM)
class SetOrientationForMediaCapture {
public:
    using Arguments = std::tuple<WebCore::IntDegrees>;

    static IPC::MessageName name() { return IPC::MessageName::GPUProcess_SetOrientationForMediaCapture; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetOrientationForMediaCapture(const WebCore::IntDegrees& orientation)
        : m_orientation(orientation)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_orientation;
    }

private:
    const WebCore::IntDegrees& m_orientation;
};
#endif

#if ENABLE(MEDIA_STREAM)
class RotationAngleForCaptureDeviceChanged {
public:
    using Arguments = std::tuple<String, WebCore::VideoFrameRotation>;

    static IPC::MessageName name() { return IPC::MessageName::GPUProcess_RotationAngleForCaptureDeviceChanged; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    RotationAngleForCaptureDeviceChanged(const String& persistentId, WebCore::VideoFrameRotation rotation)
        : m_persistentId(persistentId)
        , m_rotation(rotation)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_persistentId;
        encoder << m_rotation;
    }

private:
    const String& m_persistentId;
    WebCore::VideoFrameRotation m_rotation;
};
#endif

#if ENABLE(MEDIA_STREAM)
class UpdateCaptureAccess {
public:
    using Arguments = std::tuple<bool, bool, bool, WebCore::ProcessIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::GPUProcess_UpdateCaptureAccess; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::GPUProcess_UpdateCaptureAccessReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    UpdateCaptureAccess(bool allowAudioCapture, bool allowVideoCapture, bool allowDisplayCapture, const WebCore::ProcessIdentifier& processID)
        : m_allowAudioCapture(allowAudioCapture)
        , m_allowVideoCapture(allowVideoCapture)
        , m_allowDisplayCapture(allowDisplayCapture)
        , m_processID(processID)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_allowAudioCapture;
        encoder << m_allowVideoCapture;
        encoder << m_allowDisplayCapture;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_processID;
    }

private:
    bool m_allowAudioCapture;
    bool m_allowVideoCapture;
    bool m_allowDisplayCapture;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ProcessIdentifier& m_processID;
};
#endif

#if ENABLE(MEDIA_STREAM)
class UpdateCaptureOrigin {
public:
    using Arguments = std::tuple<WebCore::SecurityOriginData, WebCore::ProcessIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::GPUProcess_UpdateCaptureOrigin; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    UpdateCaptureOrigin(const WebCore::SecurityOriginData& originData, const WebCore::ProcessIdentifier& processID)
        : m_originData(originData)
        , m_processID(processID)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_originData;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_processID;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::SecurityOriginData& m_originData;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ProcessIdentifier& m_processID;
};
#endif

#if ENABLE(MEDIA_STREAM)
class AddMockMediaDevice {
public:
    using Arguments = std::tuple<WebCore::MockMediaDevice>;

    static IPC::MessageName name() { return IPC::MessageName::GPUProcess_AddMockMediaDevice; }
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

    static IPC::MessageName name() { return IPC::MessageName::GPUProcess_ClearMockMediaDevices; }
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

    static IPC::MessageName name() { return IPC::MessageName::GPUProcess_RemoveMockMediaDevice; }
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

    static IPC::MessageName name() { return IPC::MessageName::GPUProcess_SetMockMediaDeviceIsEphemeral; }
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

    static IPC::MessageName name() { return IPC::MessageName::GPUProcess_ResetMockMediaDevices; }
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

#if ENABLE(MEDIA_STREAM)
class SetMockCaptureDevicesInterrupted {
public:
    using Arguments = std::tuple<bool, bool>;

    static IPC::MessageName name() { return IPC::MessageName::GPUProcess_SetMockCaptureDevicesInterrupted; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SetMockCaptureDevicesInterrupted(bool isCameraInterrupted, bool isMicrophoneInterrupted)
        : m_isCameraInterrupted(isCameraInterrupted)
        , m_isMicrophoneInterrupted(isMicrophoneInterrupted)
    {
        ASSERT(!isInAuxiliaryProcess());
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

#if ENABLE(MEDIA_STREAM)
class TriggerMockCaptureConfigurationChange {
public:
    using Arguments = std::tuple<bool, bool, bool>;

    static IPC::MessageName name() { return IPC::MessageName::GPUProcess_TriggerMockCaptureConfigurationChange; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    TriggerMockCaptureConfigurationChange(bool forCamera, bool forMicrophone, bool forDisplay)
        : m_forCamera(forCamera)
        , m_forMicrophone(forMicrophone)
        , m_forDisplay(forDisplay)
    {
        ASSERT(!isInAuxiliaryProcess());
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

#if ENABLE(MEDIA_STREAM)
class SetShouldListenToVoiceActivity {
public:
    using Arguments = std::tuple<bool>;

    static IPC::MessageName name() { return IPC::MessageName::GPUProcess_SetShouldListenToVoiceActivity; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit SetShouldListenToVoiceActivity(bool shouldListen)
        : m_shouldListen(shouldListen)
    {
        ASSERT(!isInAuxiliaryProcess());
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

#if ENABLE(MEDIA_STREAM)
class EnableMicrophoneMuteStatusAPI {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::GPUProcess_EnableMicrophoneMuteStatusAPI; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    EnableMicrophoneMuteStatusAPI()
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
class SetScreenProperties {
public:
    using Arguments = std::tuple<WebCore::ScreenProperties>;

    static IPC::MessageName name() { return IPC::MessageName::GPUProcess_SetScreenProperties; }
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

#if HAVE(SCREEN_CAPTURE_KIT)
class PromptForGetDisplayMedia {
public:
    using Arguments = std::tuple<WebCore::DisplayCapturePromptType>;

    static IPC::MessageName name() { return IPC::MessageName::GPUProcess_PromptForGetDisplayMedia; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::GPUProcess_PromptForGetDisplayMediaReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebCore::CaptureDevice>>;
    using Reply = CompletionHandler<void(std::optional<WebCore::CaptureDevice>&&)>;
    using Promise = WTF::NativePromise<std::optional<WebCore::CaptureDevice>, IPC::Error>;
    explicit PromptForGetDisplayMedia(WebCore::DisplayCapturePromptType type)
        : m_type(type)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_type;
    }

private:
    WebCore::DisplayCapturePromptType m_type;
};
#endif

#if HAVE(SCREEN_CAPTURE_KIT)
class CancelGetDisplayMediaPrompt {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::GPUProcess_CancelGetDisplayMediaPrompt; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    CancelGetDisplayMediaPrompt()
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

#if ENABLE(VIDEO)
class RequestBitmapImageForCurrentTime {
public:
    using Arguments = std::tuple<WebCore::ProcessIdentifier, WebCore::MediaPlayerIdentifier>;

    static IPC::MessageName name() { return IPC::MessageName::GPUProcess_RequestBitmapImageForCurrentTime; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::GPUProcess_RequestBitmapImageForCurrentTimeReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<WebCore::ShareableBitmapHandle>>;
    using Reply = CompletionHandler<void(std::optional<WebCore::ShareableBitmapHandle>&&)>;
    using Promise = WTF::NativePromise<std::optional<WebCore::ShareableBitmapHandle>, IPC::Error>;
    RequestBitmapImageForCurrentTime(const WebCore::ProcessIdentifier& processIdentifier, const WebCore::MediaPlayerIdentifier& playerIdentifier)
        : m_processIdentifier(processIdentifier)
        , m_playerIdentifier(playerIdentifier)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_processIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_playerIdentifier;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ProcessIdentifier& m_processIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::MediaPlayerIdentifier& m_playerIdentifier;
};
#endif

#if PLATFORM(MAC)
class OpenDirectoryCacheInvalidated {
public:
    using Arguments = std::tuple<WebKit::SandboxExtensionHandle>;

    static IPC::MessageName name() { return IPC::MessageName::GPUProcess_OpenDirectoryCacheInvalidated; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit OpenDirectoryCacheInvalidated(WebKit::SandboxExtensionHandle&& handle)
        : m_handle(WTFMove(handle))
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << WTFMove(m_handle);
    }

private:
    WebKit::SandboxExtensionHandle&& m_handle;
};
#endif

#if HAVE(AUDIO_COMPONENT_SERVER_REGISTRATIONS)
class ConsumeAudioComponentRegistrations {
public:
    using Arguments = std::tuple<IPC::SharedBufferReference>;

    static IPC::MessageName name() { return IPC::MessageName::GPUProcess_ConsumeAudioComponentRegistrations; }
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

#if HAVE(POWERLOG_TASK_MODE_QUERY)
class EnablePowerLogging {
public:
    using Arguments = std::tuple<WebKit::SandboxExtensionHandle>;

    static IPC::MessageName name() { return IPC::MessageName::GPUProcess_EnablePowerLogging; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit EnablePowerLogging(WebKit::SandboxExtensionHandle&& handle)
        : m_handle(WTFMove(handle))
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << WTFMove(m_handle);
    }

private:
    WebKit::SandboxExtensionHandle&& m_handle;
};
#endif

class UserPreferredLanguagesChanged {
public:
    using Arguments = std::tuple<Vector<String>>;

    static IPC::MessageName name() { return IPC::MessageName::GPUProcess_UserPreferredLanguagesChanged; }
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

class WebProcessConnectionCountForTesting {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::GPUProcess_WebProcessConnectionCountForTesting; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::GPUProcess_WebProcessConnectionCountForTestingReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<uint64_t>;
    using Reply = CompletionHandler<void(uint64_t)>;
    using Promise = WTF::NativePromise<uint64_t, IPC::Error>;
    WebProcessConnectionCountForTesting()
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
    }

private:
};

#if USE(EXTENSIONKIT)
class ResolveBookmarkDataForCacheDirectory {
public:
    using Arguments = std::tuple<std::span<const uint8_t>>;

    static IPC::MessageName name() { return IPC::MessageName::GPUProcess_ResolveBookmarkDataForCacheDirectory; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit ResolveBookmarkDataForCacheDirectory(const std::span<const uint8_t>& bookmarkData)
        : m_bookmarkData(bookmarkData)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_bookmarkData;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const std::span<const uint8_t>& m_bookmarkData;
};
#endif

#if ENABLE(WEBXR)
class WebXRPromptAccepted {
public:
    using Arguments = std::tuple<std::optional<WebCore::ProcessIdentity>>;

    static IPC::MessageName name() { return IPC::MessageName::GPUProcess_WebXRPromptAccepted; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::GPUProcess_WebXRPromptAcceptedReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<bool>;
    using Reply = CompletionHandler<void(bool)>;
    using Promise = WTF::NativePromise<bool, IPC::Error>;
    explicit WebXRPromptAccepted(std::optional<WebCore::ProcessIdentity>&& processIdentity)
        : m_processIdentity(WTFMove(processIdentity))
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << WTFMove(m_processIdentity);
    }

private:
    std::optional<WebCore::ProcessIdentity>&& m_processIdentity;
};
#endif

#if HAVE(AUDIT_TOKEN)
class SetPresentingApplicationAuditToken {
public:
    using Arguments = std::tuple<WebCore::ProcessIdentifier, WebCore::PageIdentifier, std::optional<WebKit::CoreIPCAuditToken>>;

    static IPC::MessageName name() { return IPC::MessageName::GPUProcess_SetPresentingApplicationAuditToken; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    SetPresentingApplicationAuditToken(const WebCore::ProcessIdentifier& processIdentifier, const WebCore::PageIdentifier& pageIdentifier, const std::optional<WebKit::CoreIPCAuditToken>& auditToken)
        : m_processIdentifier(processIdentifier)
        , m_pageIdentifier(pageIdentifier)
        , m_auditToken(auditToken)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_processIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_pageIdentifier;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_auditToken;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::ProcessIdentifier& m_processIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::PageIdentifier& m_pageIdentifier;
    SUPPRESS_FORWARD_DECL_MEMBER const std::optional<WebKit::CoreIPCAuditToken>& m_auditToken;
};
#endif

#if PLATFORM(VISION) && ENABLE(MODEL_PROCESS)
class RequestSharedSimulationConnection {
public:
    using Arguments = std::tuple<WebKit::CoreIPCAuditToken>;

    static IPC::MessageName name() { return IPC::MessageName::GPUProcess_RequestSharedSimulationConnection; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::GPUProcess_RequestSharedSimulationConnectionReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<IPC::SharedFileHandle>>;
    using Reply = CompletionHandler<void(std::optional<IPC::SharedFileHandle>&&)>;
    using Promise = WTF::NativePromise<std::optional<IPC::SharedFileHandle>, IPC::Error>;
    explicit RequestSharedSimulationConnection(const WebKit::CoreIPCAuditToken& modelProcessAuditToken)
        : m_modelProcessAuditToken(modelProcessAuditToken)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_modelProcessAuditToken;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebKit::CoreIPCAuditToken& m_modelProcessAuditToken;
};
#endif

#if ((PLATFORM(VISION) && ENABLE(MODEL_PROCESS)) && HAVE(TASK_IDENTITY_TOKEN))
class CreateMemoryAttributionIDForTask {
public:
    using Arguments = std::tuple<WebCore::ProcessIdentity>;

    static IPC::MessageName name() { return IPC::MessageName::GPUProcess_CreateMemoryAttributionIDForTask; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::GPUProcess_CreateMemoryAttributionIDForTaskReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<std::optional<String>>;
    using Reply = CompletionHandler<void(std::optional<String>&&)>;
    using Promise = WTF::NativePromise<std::optional<String>, IPC::Error>;
    explicit CreateMemoryAttributionIDForTask(WebCore::ProcessIdentity&& processIdentity)
        : m_processIdentity(WTFMove(processIdentity))
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << WTFMove(m_processIdentity);
    }

private:
    WebCore::ProcessIdentity&& m_processIdentity;
};
#endif

#if ((PLATFORM(VISION) && ENABLE(MODEL_PROCESS)) && HAVE(TASK_IDENTITY_TOKEN))
class UnregisterMemoryAttributionID {
public:
    using Arguments = std::tuple<String>;

    static IPC::MessageName name() { return IPC::MessageName::GPUProcess_UnregisterMemoryAttributionID; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::GPUProcess_UnregisterMemoryAttributionIDReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    explicit UnregisterMemoryAttributionID(const String& attributionID)
        : m_attributionID(attributionID)
    {
        ASSERT(!isInAuxiliaryProcess());
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        encoder << m_attributionID;
    }

private:
    const String& m_attributionID;
};
#endif

#if PLATFORM(COCOA)
class PostWillTakeSnapshotNotification {
public:
    using Arguments = std::tuple<>;

    static IPC::MessageName name() { return IPC::MessageName::GPUProcess_PostWillTakeSnapshotNotification; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    static IPC::MessageName asyncMessageReplyName() { return IPC::MessageName::GPUProcess_PostWillTakeSnapshotNotificationReply; }
    static constexpr auto callbackThread = WTF::CompletionHandlerCallThread::ConstructionThread;
    using ReplyArguments = std::tuple<>;
    using Reply = CompletionHandler<void()>;
    using Promise = WTF::NativePromise<void, IPC::Error>;
    PostWillTakeSnapshotNotification()
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
class RegisterFonts {
public:
    using Arguments = std::tuple<Vector<WebKit::SandboxExtensionHandle>>;

    static IPC::MessageName name() { return IPC::MessageName::GPUProcess_RegisterFonts; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit RegisterFonts(Vector<WebKit::SandboxExtensionHandle>&& sandboxExtensions)
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
    Vector<WebKit::SandboxExtensionHandle>&& m_sandboxExtensions;
};
#endif

} // namespace GPUProcess
} // namespace Messages

#endif // ENABLE(GPU_PROCESS)
