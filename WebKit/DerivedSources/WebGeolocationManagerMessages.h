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
#include <wtf/Forward.h>
#include <wtf/RuntimeApplicationChecks.h>
#include <wtf/ThreadSafeRefCounted.h>
#include <wtf/text/WTFString.h>

namespace WebCore {
class GeolocationPositionData;
class RegistrableDomain;
}

namespace Messages {
namespace WebGeolocationManager {

static inline IPC::ReceiverName messageReceiverName()
{
    return IPC::ReceiverName::WebGeolocationManager;
}

class DidChangePosition {
public:
    using Arguments = std::tuple<WebCore::RegistrableDomain, WebCore::GeolocationPositionData>;

    static IPC::MessageName name() { return IPC::MessageName::WebGeolocationManager_DidChangePosition; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidChangePosition(const WebCore::RegistrableDomain& registrableDomain, const WebCore::GeolocationPositionData& position)
        : m_registrableDomain(registrableDomain)
        , m_position(position)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_registrableDomain;
        SUPPRESS_FORWARD_DECL_ARG encoder << m_position;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RegistrableDomain& m_registrableDomain;
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::GeolocationPositionData& m_position;
};

class DidFailToDeterminePosition {
public:
    using Arguments = std::tuple<WebCore::RegistrableDomain, String>;

    static IPC::MessageName name() { return IPC::MessageName::WebGeolocationManager_DidFailToDeterminePosition; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    DidFailToDeterminePosition(const WebCore::RegistrableDomain& registrableDomain, const String& errorMessage)
        : m_registrableDomain(registrableDomain)
        , m_errorMessage(errorMessage)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_registrableDomain;
        encoder << m_errorMessage;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RegistrableDomain& m_registrableDomain;
    const String& m_errorMessage;
};

#if PLATFORM(IOS_FAMILY)
class ResetPermissions {
public:
    using Arguments = std::tuple<WebCore::RegistrableDomain>;

    static IPC::MessageName name() { return IPC::MessageName::WebGeolocationManager_ResetPermissions; }
    static constexpr bool isSync = false;
    static constexpr bool canDispatchOutOfOrder = false;
    static constexpr bool replyCanDispatchOutOfOrder = false;
    static constexpr bool deferSendingIfSuspended = false;

    explicit ResetPermissions(const WebCore::RegistrableDomain& registrableDomain)
        : m_registrableDomain(registrableDomain)
    {
    }

    template<typename Encoder>
    void encode(Encoder& encoder)
    {
        SUPPRESS_FORWARD_DECL_ARG encoder << m_registrableDomain;
    }

private:
    SUPPRESS_FORWARD_DECL_MEMBER const WebCore::RegistrableDomain& m_registrableDomain;
};
#endif

} // namespace WebGeolocationManager
} // namespace Messages
