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
#include "WebPageProxy.h"

#include "ArgumentCoders.h" // NOLINT
#include "CallbackID.h" // NOLINT
#include "ColorControlSupportsAlpha.h" // NOLINT
#if ENABLE(CONTEXT_MENUS)
#include "ContextMenuContextData.h" // NOLINT
#endif
#if ENABLE(DATA_DETECTION)
#include "DataDetectionResult.h" // NOLINT
#endif
#include "Decoder.h" // NOLINT
#include "EditorState.h" // NOLINT
#if PLATFORM(IOS_FAMILY)
#include "FocusedElementInformation.h" // NOLINT
#endif
#include "FrameInfoData.h" // NOLINT
#include "GeolocationIdentifier.h" // NOLINT
#include "HandleMessage.h" // NOLINT
#include "IdentifierTypes.h" // NOLINT
#if PLATFORM(GTK) || PLATFORM(WPE)
#include "InputMethodState.h" // NOLINT
#endif
#if PLATFORM(IOS_FAMILY)
#include "InteractionInformationAtPosition.h" // NOLINT
#endif
#if PLATFORM(IOS_FAMILY)
#include "KeyEventInterpretationContext.h" // NOLINT
#endif
#if HAVE(VISIBILITY_PROPAGATION_VIEW)
#include "LayerHostingContext.h" // NOLINT
#endif
#if ENABLE(ARKIT_INLINE_PREVIEW) || ENABLE(ARKIT_INLINE_PREVIEW_IOS)
#include "ModelIdentifier.h" // NOLINT
#endif
#include "NavigationActionData.h" // NOLINT
#if ENABLE(PDF_PLUGIN) && PLATFORM(MAC)
#include "PDFContextMenu.h" // NOLINT
#endif
#if ENABLE(PDF_HUD) || ENABLE(PDF_PAGE_NUMBER_INDICATOR) || ENABLE(PDF_PLUGIN) && PLATFORM(MAC)
#include "PDFPluginIdentifier.h" // NOLINT
#endif
#if PLATFORM(IOS_FAMILY)
#include "PageClient.h" // NOLINT
#endif
#include "PlatformPopupMenuData.h" // NOLINT
#include "PolicyDecision.h" // NOLINT
#include "SameDocumentNavigationType.h" // NOLINT
#include "SessionState.h" // NOLINT
#if ENABLE(ATTACHMENT_ELEMENT)
#include "SharedBufferReference.h" // NOLINT
#endif
#include "SharedPreferencesForWebProcess.h" // NOLINT
#include "URLSchemeTaskParameters.h" // NOLINT
#include "UndoOrRedo.h" // NOLINT
#include "UserData.h" // NOLINT
#if PLATFORM(GTK) || PLATFORM(WPE)
#include "UserMessage.h" // NOLINT
#endif
#if PLATFORM(IOS_FAMILY)
#include "WebAutocorrectionContext.h" // NOLINT
#endif
#include "WebBackForwardListCounts.h" // NOLINT
#include "WebEvent.h" // NOLINT
#include "WebEventModifier.h" // NOLINT
#include "WebHitTestResultData.h" // NOLINT
#include "WebNavigationDataStore.h" // NOLINT
#include "WebPageCreationParameters.h" // NOLINT
#include "WebPageProxyMessages.h" // NOLINT
#include "WebPopupItem.h" // NOLINT
#if ENABLE(SPEECH_SYNTHESIS)
#include "WebSpeechSynthesisVoice.h" // NOLINT
#endif
#include "WebURLSchemeHandlerIdentifier.h" // NOLINT
#include <JavaScriptCore/InspectorTarget.h> // NOLINT
#if PLATFORM(IOS_FAMILY)
#include <WebCore/ActivityState.h> // NOLINT
#endif
#if PLATFORM(MAC)
#include <WebCore/AlternativeTextClient.h> // NOLINT
#endif
#if ENABLE(APPLE_PAY_AMS_UI)
#include <WebCore/ApplePayAMSUIRequest.h> // NOLINT
#endif
#if ENABLE(ATTACHMENT_ELEMENT)
#include <WebCore/AttachmentAssociatedElement.h> // NOLINT
#endif
#if PLATFORM(IOS_FAMILY)
#include <WebCore/AudioSession.h> // NOLINT
#endif
#include <WebCore/AutoplayEvent.h> // NOLINT
#include <WebCore/BackForwardFrameItemIdentifier.h> // NOLINT
#include <WebCore/BackForwardItemIdentifier.h> // NOLINT
#if ENABLE(MEDIA_STREAM)
#include <WebCore/CaptureDeviceWithCapabilities.h> // NOLINT
#endif
#include <WebCore/CertificateInfo.h> // NOLINT
#if ENABLE(ENCRYPTED_MEDIA) || ENABLE(MEDIA_STREAM)
#include <WebCore/ClientOrigin.h> // NOLINT
#endif
#include <WebCore/Color.h> // NOLINT
#include <WebCore/ContactInfo.h> // NOLINT
#include <WebCore/ContactsRequestData.h> // NOLINT
#if ENABLE(CONTENT_FILTERING)
#include <WebCore/ContentFilterUnblockHandler.h> // NOLINT
#endif
#if ENABLE(CONTENT_EXTENSIONS)
#include <WebCore/ContentRuleListResults.h> // NOLINT
#endif
#include <WebCore/CookieConsentDecisionResult.h> // NOLINT
#include <WebCore/CrossOriginOpenerPolicy.h> // NOLINT
#include <WebCore/CryptoKeyData.h> // NOLINT
#include <WebCore/Cursor.h> // NOLINT
#include <WebCore/DOMPasteAccess.h> // NOLINT
#if ENABLE(DATA_DETECTION)
#include <WebCore/DataDetectorElementInfo.h> // NOLINT
#endif
#include <WebCore/DataListSuggestionInformation.h> // NOLINT
#include <WebCore/DateTimeChooserParameters.h> // NOLINT
#if ENABLE(DEVICE_ORIENTATION)
#include <WebCore/DeviceOrientationOrMotionPermissionState.h> // NOLINT
#endif
#include <WebCore/DiagnosticLoggingClient.h> // NOLINT
#include <WebCore/DiagnosticLoggingDomain.h> // NOLINT
#if USE(DICTATION_ALTERNATIVES)
#include <WebCore/DictationContext.h> // NOLINT
#endif
#if PLATFORM(COCOA)
#include <WebCore/DictionaryPopupInfo.h> // NOLINT
#endif
#if HAVE(DIGITAL_CREDENTIALS_UI)
#include <WebCore/DigitalCredentialsRequestData.h> // NOLINT
#endif
#if HAVE(DIGITAL_CREDENTIALS_UI)
#include <WebCore/DigitalCredentialsResponseData.h> // NOLINT
#endif
#include <WebCore/DocumentLoader.h> // NOLINT
#include <WebCore/DocumentSyncData.h> // NOLINT
#if (PLATFORM(GTK) || PLATFORM(WPE)) && ENABLE(DRAG_SUPPORT)
#include <WebCore/DragActions.h> // NOLINT
#endif
#if PLATFORM(COCOA) && ENABLE(DRAG_SUPPORT)
#include <WebCore/DragItem.h> // NOLINT
#endif
#if PLATFORM(IOS_FAMILY)
#include <WebCore/ElementContext.h> // NOLINT
#endif
#if ENABLE(MEDIA_STREAM)
#include <WebCore/Exception.h> // NOLINT
#endif
#if HAVE(DIGITAL_CREDENTIALS_UI)
#include <WebCore/ExceptionData.h> // NOLINT
#endif
#include <WebCore/FileChooser.h> // NOLINT
#include <WebCore/FloatPoint.h> // NOLINT
#if PLATFORM(IOS_FAMILY)
#include <WebCore/FloatQuad.h> // NOLINT
#endif
#include <WebCore/FloatRect.h> // NOLINT
#include <WebCore/FloatSize.h> // NOLINT
#include <WebCore/FocusDirection.h> // NOLINT
#include <WebCore/FrameIdentifier.h> // NOLINT
#include <WebCore/FrameLoaderTypes.h> // NOLINT
#if ENABLE(ARKIT_INLINE_PREVIEW)
#include <WebCore/HTMLModelElementCamera.h> // NOLINT
#endif
#include <WebCore/ImageBuffer.h> // NOLINT
#if PLATFORM(IOS_FAMILY)
#include <WebCore/InputMode.h> // NOLINT
#endif
#if PLATFORM(IOS_FAMILY)
#include <WebCore/InspectorOverlay.h> // NOLINT
#endif
#include <WebCore/IntPoint.h> // NOLINT
#include <WebCore/IntRect.h> // NOLINT
#include <WebCore/IntSize.h> // NOLINT
#include <WebCore/LayerTreeAsTextOptions.h> // NOLINT
#include <WebCore/LayoutMilestone.h> // NOLINT
#if ENABLE(ARKIT_INLINE_PREVIEW_MAC)
#include <WebCore/LayoutPoint.h> // NOLINT
#endif
#include <WebCore/LinkIcon.h> // NOLINT
#include <WebCore/LocalFrameLoaderClient.h> // NOLINT
#if ENABLE(MEDIA_CONTROLS_CONTEXT_MENUS) && USE(UICONTEXTMENU)
#include <WebCore/MediaControlsContextMenuItem.h> // NOLINT
#endif
#if ENABLE(MEDIA_STREAM)
#include <WebCore/MediaDeviceHashSalts.h> // NOLINT
#endif
#if ENABLE(ENCRYPTED_MEDIA)
#include <WebCore/MediaKeySystemRequestIdentifier.h> // NOLINT
#endif
#if ENABLE(WIRELESS_PLAYBACK_TARGET) && !PLATFORM(IOS_FAMILY)
#include <WebCore/MediaPlaybackTargetContext.h> // NOLINT
#endif
#if ENABLE(IMAGE_ANALYSIS) && ENABLE(VIDEO)
#include <WebCore/MediaPlayerIdentifier.h> // NOLINT
#endif
#include <WebCore/MediaProducer.h> // NOLINT
#if ENABLE(MEDIA_USAGE)
#include <WebCore/MediaSessionIdentifier.h> // NOLINT
#endif
#if ENABLE(MEDIA_STREAM)
#include <WebCore/MediaStreamRequest.h> // NOLINT
#endif
#if ENABLE(MEDIA_USAGE)
#include <WebCore/MediaUsageInfo.h> // NOLINT
#endif
#include <WebCore/MessageWithMessagePorts.h> // NOLINT
#if ENABLE(WEB_AUTHN)
#include <WebCore/MockWebAuthenticationConfiguration.h> // NOLINT
#endif
#include <WebCore/NavigationIdentifier.h> // NOLINT
#if ENABLE(MODEL_PROCESS) || PLATFORM(COCOA) && ENABLE(DRAG_SUPPORT)
#include <WebCore/NodeIdentifier.h> // NOLINT
#endif
#include <WebCore/NowPlayingInfo.h> // NOLINT
#include <WebCore/PageIdentifier.h> // NOLINT
#if ENABLE(WIRELESS_PLAYBACK_TARGET) && !PLATFORM(IOS_FAMILY)
#include <WebCore/PlaybackTargetClientContextIdentifier.h> // NOLINT
#endif
#include <WebCore/ProcessQualified.h> // NOLINT
#include <WebCore/ProcessSyncData.h> // NOLINT
#if (ENABLE(ATTACHMENT_ELEMENT) && PLATFORM(IOS_FAMILY))
#include <WebCore/PromisedAttachmentInfo.h> // NOLINT
#endif
#include <WebCore/RectEdges.h> // NOLINT
#include <WebCore/RemoteUserInputEventData.h> // NOLINT
#include <WebCore/RenderTreeAsText.h> // NOLINT
#include <WebCore/ResourceError.h> // NOLINT
#include <WebCore/ResourceLoaderIdentifier.h> // NOLINT
#include <WebCore/ResourceRequest.h> // NOLINT
#include <WebCore/ResourceResponse.h> // NOLINT
#include <WebCore/ResourceResponseBase.h> // NOLINT
#include <WebCore/SandboxFlags.h> // NOLINT
#include <WebCore/ScrollTypes.h> // NOLINT
#if PLATFORM(IOS_FAMILY)
#include <WebCore/ScrollingNodeID.h> // NOLINT
#endif
#include <WebCore/SearchPopupMenu.h> // NOLINT
#include <WebCore/SecurityOriginData.h> // NOLINT
#if (PLATFORM(GTK) || PLATFORM(WPE)) && ENABLE(DRAG_SUPPORT)
#include <WebCore/SelectionData.h> // NOLINT
#endif
#if ENABLE(ATTACHMENT_ELEMENT)
#include <WebCore/SerializedAttachmentData.h> // NOLINT
#endif
#include <WebCore/ShareData.h> // NOLINT
#include <WebCore/ShareableBitmapHandle.h> // NOLINT
#if USE(QUICK_LOOK)
#include <WebCore/ShareableResource.h> // NOLINT
#endif
#if PLATFORM(COCOA) && ENABLE(DRAG_SUPPORT) || PLATFORM(IOS_FAMILY)
#include <WebCore/SharedMemory.h> // NOLINT
#endif
#include <WebCore/SleepDisablerIdentifier.h> // NOLINT
#if ENABLE(WEB_PAGE_SPATIAL_BACKDROP)
#include <WebCore/SpatialBackdropSource.h> // NOLINT
#endif
#if USE(SYSTEM_PREVIEW)
#include <WebCore/SystemPreviewInfo.h> // NOLINT
#endif
#if ENABLE(WRITING_TOOLS)
#include <WebCore/TextAnimationTypes.h> // NOLINT
#endif
#include <WebCore/TextCheckerClient.h> // NOLINT
#include <WebCore/TextChecking.h> // NOLINT
#include <WebCore/TextIndicator.h> // NOLINT
#include <WebCore/TextManipulationItem.h> // NOLINT
#if ENABLE(IMAGE_ANALYSIS)
#include <WebCore/TextRecognitionResult.h> // NOLINT
#endif
#if HAVE(TRANSLATION_UI_SERVICES) && ENABLE(CONTEXT_MENUS)
#include <WebCore/TranslationContextMenuInfo.h> // NOLINT
#endif
#if ENABLE(MEDIA_STREAM)
#include <WebCore/UserMediaRequestIdentifier.h> // NOLINT
#endif
#include <WebCore/WindowFeatures.h> // NOLINT
#include <WebCore/WrappedCryptoKey.h> // NOLINT
#if ENABLE(WRITING_TOOLS)
#include <WebCore/WritingToolsTypes.h> // NOLINT
#endif
#include <optional> // NOLINT
#include <span> // NOLINT
#include <utility> // NOLINT
#if ENABLE(ARKIT_INLINE_PREVIEW) || ENABLE(ARKIT_INLINE_PREVIEW_MAC) || HAVE(DIGITAL_CREDENTIALS_UI)
#include <wtf/Expected.h> // NOLINT
#endif
#if ENABLE(ARKIT_INLINE_PREVIEW_MAC)
#include <wtf/MachSendRight.h> // NOLINT
#endif
#include <wtf/MonotonicTime.h> // NOLINT
#include <wtf/ObjectIdentifier.h> // NOLINT
#include <wtf/OptionSet.h> // NOLINT
#include <wtf/Ref.h> // NOLINT
#include <wtf/RefCounted.h> // NOLINT
#if ENABLE(ARKIT_INLINE_PREVIEW)
#include <wtf/Seconds.h> // NOLINT
#endif
#include <wtf/URLHash.h> // NOLINT
#if ENABLE(WRITING_TOOLS)
#include <wtf/UUID.h> // NOLINT
#endif
#include <wtf/Vector.h> // NOLINT
#include <wtf/WallTime.h> // NOLINT
#include <wtf/text/WTFString.h> // NOLINT

#if ENABLE(IPC_TESTING_API)
#include "JSIPCBinding.h"
#endif

namespace WebKit {

void WebPageProxy::didReceiveMessage(IPC::Connection& connection, IPC::Decoder& decoder)
{
    auto sharedPreferences = sharedPreferencesForWebProcess(connection);
    UNUSED_VARIABLE(sharedPreferences);
    Ref protectedThis { *this };
    if (decoder.messageName() == Messages::WebPageProxy::ShowPage::name())
        return IPC::handleMessage<Messages::WebPageProxy::ShowPage>(connection, decoder, this, &WebPageProxy::showPage);
    if (decoder.messageName() == Messages::WebPageProxy::ClosePage::name())
        return IPC::handleMessage<Messages::WebPageProxy::ClosePage>(connection, decoder, this, &WebPageProxy::closePage);
    if (decoder.messageName() == Messages::WebPageProxy::MouseDidMoveOverElement::name())
        return IPC::handleMessage<Messages::WebPageProxy::MouseDidMoveOverElement>(connection, decoder, this, &WebPageProxy::mouseDidMoveOverElement);
    if (decoder.messageName() == Messages::WebPageProxy::DidReceiveEventIPC::name())
        return IPC::handleMessage<Messages::WebPageProxy::DidReceiveEventIPC>(connection, decoder, this, &WebPageProxy::didReceiveEventIPC);
    if (decoder.messageName() == Messages::WebPageProxy::SetCursor::name())
        return IPC::handleMessage<Messages::WebPageProxy::SetCursor>(connection, decoder, this, &WebPageProxy::setCursor);
    if (decoder.messageName() == Messages::WebPageProxy::SetCursorHiddenUntilMouseMoves::name())
        return IPC::handleMessage<Messages::WebPageProxy::SetCursorHiddenUntilMouseMoves>(connection, decoder, this, &WebPageProxy::setCursorHiddenUntilMouseMoves);
    if (decoder.messageName() == Messages::WebPageProxy::SetFocus::name())
        return IPC::handleMessage<Messages::WebPageProxy::SetFocus>(connection, decoder, this, &WebPageProxy::setFocus);
    if (decoder.messageName() == Messages::WebPageProxy::TakeFocus::name())
        return IPC::handleMessage<Messages::WebPageProxy::TakeFocus>(connection, decoder, this, &WebPageProxy::takeFocus);
    if (decoder.messageName() == Messages::WebPageProxy::FocusFromServiceWorker::name())
        return IPC::handleMessageAsync<Messages::WebPageProxy::FocusFromServiceWorker>(connection, decoder, this, &WebPageProxy::focusFromServiceWorker);
    if (decoder.messageName() == Messages::WebPageProxy::FocusedFrameChanged::name())
        return IPC::handleMessage<Messages::WebPageProxy::FocusedFrameChanged>(connection, decoder, this, &WebPageProxy::focusedFrameChanged);
    if (decoder.messageName() == Messages::WebPageProxy::SetRenderTreeSize::name())
        return IPC::handleMessage<Messages::WebPageProxy::SetRenderTreeSize>(connection, decoder, this, &WebPageProxy::setRenderTreeSize);
    if (decoder.messageName() == Messages::WebPageProxy::SetToolbarsAreVisible::name())
        return IPC::handleMessage<Messages::WebPageProxy::SetToolbarsAreVisible>(connection, decoder, this, &WebPageProxy::setToolbarsAreVisible);
    if (decoder.messageName() == Messages::WebPageProxy::SetMenuBarIsVisible::name())
        return IPC::handleMessage<Messages::WebPageProxy::SetMenuBarIsVisible>(connection, decoder, this, &WebPageProxy::setMenuBarIsVisible);
    if (decoder.messageName() == Messages::WebPageProxy::SetStatusBarIsVisible::name())
        return IPC::handleMessage<Messages::WebPageProxy::SetStatusBarIsVisible>(connection, decoder, this, &WebPageProxy::setStatusBarIsVisible);
    if (decoder.messageName() == Messages::WebPageProxy::SetIsResizable::name())
        return IPC::handleMessage<Messages::WebPageProxy::SetIsResizable>(connection, decoder, this, &WebPageProxy::setIsResizable);
    if (decoder.messageName() == Messages::WebPageProxy::SetWindowFrame::name())
        return IPC::handleMessage<Messages::WebPageProxy::SetWindowFrame>(connection, decoder, this, &WebPageProxy::setWindowFrame);
#if PLATFORM(IOS_FAMILY)
    if (decoder.messageName() == Messages::WebPageProxy::RelayAccessibilityNotification::name())
        return IPC::handleMessage<Messages::WebPageProxy::RelayAccessibilityNotification>(connection, decoder, this, &WebPageProxy::relayAccessibilityNotification);
#endif
    if (decoder.messageName() == Messages::WebPageProxy::EnableAccessibilityForAllProcesses::name())
        return IPC::handleMessage<Messages::WebPageProxy::EnableAccessibilityForAllProcesses>(connection, decoder, this, &WebPageProxy::enableAccessibilityForAllProcesses);
#if PLATFORM(COCOA) || PLATFORM(GTK)
    if (decoder.messageName() == Messages::WebPageProxy::ShowValidationMessage::name())
        return IPC::handleMessage<Messages::WebPageProxy::ShowValidationMessage>(connection, decoder, this, &WebPageProxy::showValidationMessage);
    if (decoder.messageName() == Messages::WebPageProxy::HideValidationMessage::name())
        return IPC::handleMessage<Messages::WebPageProxy::HideValidationMessage>(connection, decoder, this, &WebPageProxy::hideValidationMessage);
#endif
    if (decoder.messageName() == Messages::WebPageProxy::PageDidScroll::name())
        return IPC::handleMessage<Messages::WebPageProxy::PageDidScroll>(connection, decoder, this, &WebPageProxy::pageDidScroll);
    if (decoder.messageName() == Messages::WebPageProxy::SetHasActiveAnimatedScrolls::name())
        return IPC::handleMessage<Messages::WebPageProxy::SetHasActiveAnimatedScrolls>(connection, decoder, this, &WebPageProxy::setHasActiveAnimatedScrolls);
    if (decoder.messageName() == Messages::WebPageProxy::RunOpenPanel::name())
        return IPC::handleMessage<Messages::WebPageProxy::RunOpenPanel>(connection, decoder, this, &WebPageProxy::runOpenPanel);
    if (decoder.messageName() == Messages::WebPageProxy::ShowShareSheet::name()) {
        if (!(sharedPreferences && sharedPreferences->webShareEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebPageProxy::ShowShareSheet>(connection, decoder, this, &WebPageProxy::showShareSheet);
    }
    if (decoder.messageName() == Messages::WebPageProxy::ShowContactPicker::name()) {
        if (!(sharedPreferences && sharedPreferences->contactPickerAPIEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebPageProxy::ShowContactPicker>(connection, decoder, this, &WebPageProxy::showContactPicker);
    }
#if HAVE(DIGITAL_CREDENTIALS_UI)
    if (decoder.messageName() == Messages::WebPageProxy::ShowDigitalCredentialsPicker::name()) {
        if (!(sharedPreferences && sharedPreferences->digitalCredentialsEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebPageProxy::ShowDigitalCredentialsPicker>(connection, decoder, this, &WebPageProxy::showDigitalCredentialsPicker);
    }
    if (decoder.messageName() == Messages::WebPageProxy::DismissDigitalCredentialsPicker::name()) {
        if (!(sharedPreferences && sharedPreferences->digitalCredentialsEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebPageProxy::DismissDigitalCredentialsPicker>(connection, decoder, this, &WebPageProxy::dismissDigitalCredentialsPicker);
    }
#endif
    if (decoder.messageName() == Messages::WebPageProxy::RunModal::name())
        return IPC::handleMessage<Messages::WebPageProxy::RunModal>(connection, decoder, this, &WebPageProxy::runModal);
    if (decoder.messageName() == Messages::WebPageProxy::NotifyScrollerThumbIsVisibleInRect::name())
        return IPC::handleMessage<Messages::WebPageProxy::NotifyScrollerThumbIsVisibleInRect>(connection, decoder, this, &WebPageProxy::notifyScrollerThumbIsVisibleInRect);
    if (decoder.messageName() == Messages::WebPageProxy::RecommendedScrollbarStyleDidChange::name())
        return IPC::handleMessage<Messages::WebPageProxy::RecommendedScrollbarStyleDidChange>(connection, decoder, this, &WebPageProxy::recommendedScrollbarStyleDidChange);
    if (decoder.messageName() == Messages::WebPageProxy::DidChangeScrollbarsForMainFrame::name())
        return IPC::handleMessage<Messages::WebPageProxy::DidChangeScrollbarsForMainFrame>(connection, decoder, this, &WebPageProxy::didChangeScrollbarsForMainFrame);
    if (decoder.messageName() == Messages::WebPageProxy::DidChangeScrollOffsetPinningForMainFrame::name())
        return IPC::handleMessage<Messages::WebPageProxy::DidChangeScrollOffsetPinningForMainFrame>(connection, decoder, this, &WebPageProxy::didChangeScrollOffsetPinningForMainFrame);
    if (decoder.messageName() == Messages::WebPageProxy::DidChangePageCount::name())
        return IPC::handleMessage<Messages::WebPageProxy::DidChangePageCount>(connection, decoder, this, &WebPageProxy::didChangePageCount);
#if PLATFORM(MAC) || PLATFORM(WPE) || PLATFORM(GTK)
    if (decoder.messageName() == Messages::WebPageProxy::ThemeColorChanged::name())
        return IPC::handleMessage<Messages::WebPageProxy::ThemeColorChanged>(connection, decoder, this, &WebPageProxy::themeColorChanged);
#endif
#if ENABLE(WEB_PAGE_SPATIAL_BACKDROP)
    if (decoder.messageName() == Messages::WebPageProxy::SpatialBackdropSourceChanged::name()) {
        if (!(sharedPreferences && sharedPreferences->webPageSpatialBackdropEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::WebPageProxy::SpatialBackdropSourceChanged>(connection, decoder, this, &WebPageProxy::spatialBackdropSourceChanged);
    }
#endif
    if (decoder.messageName() == Messages::WebPageProxy::PageExtendedBackgroundColorDidChange::name())
        return IPC::handleMessage<Messages::WebPageProxy::PageExtendedBackgroundColorDidChange>(connection, decoder, this, &WebPageProxy::pageExtendedBackgroundColorDidChange);
    if (decoder.messageName() == Messages::WebPageProxy::SampledPageTopColorChanged::name())
        return IPC::handleMessage<Messages::WebPageProxy::SampledPageTopColorChanged>(connection, decoder, this, &WebPageProxy::sampledPageTopColorChanged);
    if (decoder.messageName() == Messages::WebPageProxy::SetCanShortCircuitHorizontalWheelEvents::name())
        return IPC::handleMessage<Messages::WebPageProxy::SetCanShortCircuitHorizontalWheelEvents>(connection, decoder, this, &WebPageProxy::setCanShortCircuitHorizontalWheelEvents);
    if (decoder.messageName() == Messages::WebPageProxy::DidChangeContentSize::name())
        return IPC::handleMessage<Messages::WebPageProxy::DidChangeContentSize>(connection, decoder, this, &WebPageProxy::didChangeContentSize);
    if (decoder.messageName() == Messages::WebPageProxy::DidChangeIntrinsicContentSize::name())
        return IPC::handleMessage<Messages::WebPageProxy::DidChangeIntrinsicContentSize>(connection, decoder, this, &WebPageProxy::didChangeIntrinsicContentSize);
    if (decoder.messageName() == Messages::WebPageProxy::ShowColorPicker::name()) {
        if (!(sharedPreferences && sharedPreferences->inputTypeColorEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::WebPageProxy::ShowColorPicker>(connection, decoder, this, &WebPageProxy::showColorPicker);
    }
    if (decoder.messageName() == Messages::WebPageProxy::SetColorPickerColor::name()) {
        if (!(sharedPreferences && sharedPreferences->inputTypeColorEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::WebPageProxy::SetColorPickerColor>(connection, decoder, this, &WebPageProxy::setColorPickerColor);
    }
    if (decoder.messageName() == Messages::WebPageProxy::EndColorPicker::name()) {
        if (!(sharedPreferences && sharedPreferences->inputTypeColorEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::WebPageProxy::EndColorPicker>(connection, decoder, this, &WebPageProxy::endColorPicker);
    }
    if (decoder.messageName() == Messages::WebPageProxy::ShowDataListSuggestions::name()) {
        if (!(sharedPreferences && sharedPreferences->dataListElementEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::WebPageProxy::ShowDataListSuggestions>(connection, decoder, this, &WebPageProxy::showDataListSuggestions);
    }
    if (decoder.messageName() == Messages::WebPageProxy::HandleKeydownInDataList::name()) {
        if (!(sharedPreferences && sharedPreferences->dataListElementEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::WebPageProxy::HandleKeydownInDataList>(connection, decoder, this, &WebPageProxy::handleKeydownInDataList);
    }
    if (decoder.messageName() == Messages::WebPageProxy::EndDataListSuggestions::name()) {
        if (!(sharedPreferences && sharedPreferences->dataListElementEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::WebPageProxy::EndDataListSuggestions>(connection, decoder, this, &WebPageProxy::endDataListSuggestions);
    }
    if (decoder.messageName() == Messages::WebPageProxy::ShowDateTimePicker::name()) {
        if (!(sharedPreferences && (sharedPreferences->inputTypeDateEnabled || sharedPreferences->inputTypeDateTimeLocalEnabled || sharedPreferences->inputTypeMonthEnabled || sharedPreferences->inputTypeTimeEnabled || sharedPreferences->inputTypeWeekEnabled))) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::WebPageProxy::ShowDateTimePicker>(connection, decoder, this, &WebPageProxy::showDateTimePicker);
    }
    if (decoder.messageName() == Messages::WebPageProxy::EndDateTimePicker::name()) {
        if (!(sharedPreferences && (sharedPreferences->inputTypeDateEnabled || sharedPreferences->inputTypeDateTimeLocalEnabled || sharedPreferences->inputTypeMonthEnabled || sharedPreferences->inputTypeTimeEnabled || sharedPreferences->inputTypeWeekEnabled))) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::WebPageProxy::EndDateTimePicker>(connection, decoder, this, &WebPageProxy::endDateTimePicker);
    }
    if (decoder.messageName() == Messages::WebPageProxy::DecidePolicyForResponse::name())
        return IPC::handleMessageAsync<Messages::WebPageProxy::DecidePolicyForResponse>(connection, decoder, this, &WebPageProxy::decidePolicyForResponse);
    if (decoder.messageName() == Messages::WebPageProxy::DecidePolicyForNavigationActionAsync::name())
        return IPC::handleMessageAsync<Messages::WebPageProxy::DecidePolicyForNavigationActionAsync>(connection, decoder, this, &WebPageProxy::decidePolicyForNavigationActionAsync);
    if (decoder.messageName() == Messages::WebPageProxy::DecidePolicyForNewWindowAction::name())
        return IPC::handleMessageAsync<Messages::WebPageProxy::DecidePolicyForNewWindowAction>(connection, decoder, this, &WebPageProxy::decidePolicyForNewWindowAction);
    if (decoder.messageName() == Messages::WebPageProxy::DidChangeProgress::name())
        return IPC::handleMessage<Messages::WebPageProxy::DidChangeProgress>(connection, decoder, this, &WebPageProxy::didChangeProgress);
    if (decoder.messageName() == Messages::WebPageProxy::DidFinishProgress::name())
        return IPC::handleMessage<Messages::WebPageProxy::DidFinishProgress>(connection, decoder, this, &WebPageProxy::didFinishProgress);
    if (decoder.messageName() == Messages::WebPageProxy::DidStartProgress::name())
        return IPC::handleMessage<Messages::WebPageProxy::DidStartProgress>(connection, decoder, this, &WebPageProxy::didStartProgress);
    if (decoder.messageName() == Messages::WebPageProxy::SetNetworkRequestsInProgress::name())
        return IPC::handleMessage<Messages::WebPageProxy::SetNetworkRequestsInProgress>(connection, decoder, this, &WebPageProxy::setNetworkRequestsInProgress);
    if (decoder.messageName() == Messages::WebPageProxy::StartNetworkRequestsForPageLoadTiming::name())
        return IPC::handleMessage<Messages::WebPageProxy::StartNetworkRequestsForPageLoadTiming>(connection, decoder, this, &WebPageProxy::startNetworkRequestsForPageLoadTiming);
    if (decoder.messageName() == Messages::WebPageProxy::EndNetworkRequestsForPageLoadTiming::name())
        return IPC::handleMessage<Messages::WebPageProxy::EndNetworkRequestsForPageLoadTiming>(connection, decoder, this, &WebPageProxy::endNetworkRequestsForPageLoadTiming);
    if (decoder.messageName() == Messages::WebPageProxy::DidCreateSubframe::name())
        return IPC::handleMessage<Messages::WebPageProxy::DidCreateSubframe>(connection, decoder, this, &WebPageProxy::didCreateSubframe);
    if (decoder.messageName() == Messages::WebPageProxy::DidDestroyFrame::name())
        return IPC::handleMessage<Messages::WebPageProxy::DidDestroyFrame>(connection, decoder, this, &WebPageProxy::didDestroyFrame);
    if (decoder.messageName() == Messages::WebPageProxy::DidStartProvisionalLoadForFrame::name())
        return IPC::handleMessage<Messages::WebPageProxy::DidStartProvisionalLoadForFrame>(connection, decoder, this, &WebPageProxy::didStartProvisionalLoadForFrame);
    if (decoder.messageName() == Messages::WebPageProxy::DidReceiveServerRedirectForProvisionalLoadForFrame::name())
        return IPC::handleMessage<Messages::WebPageProxy::DidReceiveServerRedirectForProvisionalLoadForFrame>(connection, decoder, this, &WebPageProxy::didReceiveServerRedirectForProvisionalLoadForFrame);
    if (decoder.messageName() == Messages::WebPageProxy::WillPerformClientRedirectForFrame::name())
        return IPC::handleMessage<Messages::WebPageProxy::WillPerformClientRedirectForFrame>(connection, decoder, this, &WebPageProxy::willPerformClientRedirectForFrame);
    if (decoder.messageName() == Messages::WebPageProxy::DidCancelClientRedirectForFrame::name())
        return IPC::handleMessage<Messages::WebPageProxy::DidCancelClientRedirectForFrame>(connection, decoder, this, &WebPageProxy::didCancelClientRedirectForFrame);
    if (decoder.messageName() == Messages::WebPageProxy::DidChangeProvisionalURLForFrame::name())
        return IPC::handleMessage<Messages::WebPageProxy::DidChangeProvisionalURLForFrame>(connection, decoder, this, &WebPageProxy::didChangeProvisionalURLForFrame);
    if (decoder.messageName() == Messages::WebPageProxy::DidFailProvisionalLoadForFrame::name())
        return IPC::handleMessage<Messages::WebPageProxy::DidFailProvisionalLoadForFrame>(connection, decoder, this, &WebPageProxy::didFailProvisionalLoadForFrame);
    if (decoder.messageName() == Messages::WebPageProxy::DidCommitLoadForFrame::name())
        return IPC::handleMessage<Messages::WebPageProxy::DidCommitLoadForFrame>(connection, decoder, this, &WebPageProxy::didCommitLoadForFrame);
    if (decoder.messageName() == Messages::WebPageProxy::DidFailLoadForFrame::name())
        return IPC::handleMessage<Messages::WebPageProxy::DidFailLoadForFrame>(connection, decoder, this, &WebPageProxy::didFailLoadForFrame);
    if (decoder.messageName() == Messages::WebPageProxy::DidFinishDocumentLoadForFrame::name())
        return IPC::handleMessage<Messages::WebPageProxy::DidFinishDocumentLoadForFrame>(connection, decoder, this, &WebPageProxy::didFinishDocumentLoadForFrame);
    if (decoder.messageName() == Messages::WebPageProxy::DidFinishLoadForFrame::name())
        return IPC::handleMessage<Messages::WebPageProxy::DidFinishLoadForFrame>(connection, decoder, this, &WebPageProxy::didFinishLoadForFrame);
    if (decoder.messageName() == Messages::WebPageProxy::DidFirstLayoutForFrame::name())
        return IPC::handleMessage<Messages::WebPageProxy::DidFirstLayoutForFrame>(connection, decoder, this, &WebPageProxy::didFirstLayoutForFrame);
    if (decoder.messageName() == Messages::WebPageProxy::DidFirstVisuallyNonEmptyLayoutForFrame::name())
        return IPC::handleMessage<Messages::WebPageProxy::DidFirstVisuallyNonEmptyLayoutForFrame>(connection, decoder, this, &WebPageProxy::didFirstVisuallyNonEmptyLayoutForFrame);
    if (decoder.messageName() == Messages::WebPageProxy::DidReachLayoutMilestone::name())
        return IPC::handleMessage<Messages::WebPageProxy::DidReachLayoutMilestone>(connection, decoder, this, &WebPageProxy::didReachLayoutMilestone);
    if (decoder.messageName() == Messages::WebPageProxy::DidReceiveTitleForFrame::name())
        return IPC::handleMessage<Messages::WebPageProxy::DidReceiveTitleForFrame>(connection, decoder, this, &WebPageProxy::didReceiveTitleForFrame);
    if (decoder.messageName() == Messages::WebPageProxy::DidDisplayInsecureContentForFrame::name())
        return IPC::handleMessage<Messages::WebPageProxy::DidDisplayInsecureContentForFrame>(connection, decoder, this, &WebPageProxy::didDisplayInsecureContentForFrame);
    if (decoder.messageName() == Messages::WebPageProxy::DidRunInsecureContentForFrame::name())
        return IPC::handleMessage<Messages::WebPageProxy::DidRunInsecureContentForFrame>(connection, decoder, this, &WebPageProxy::didRunInsecureContentForFrame);
    if (decoder.messageName() == Messages::WebPageProxy::DidSameDocumentNavigationForFrame::name())
        return IPC::handleMessage<Messages::WebPageProxy::DidSameDocumentNavigationForFrame>(connection, decoder, this, &WebPageProxy::didSameDocumentNavigationForFrame);
    if (decoder.messageName() == Messages::WebPageProxy::DidSameDocumentNavigationForFrameViaJS::name())
        return IPC::handleMessage<Messages::WebPageProxy::DidSameDocumentNavigationForFrameViaJS>(connection, decoder, this, &WebPageProxy::didSameDocumentNavigationForFrameViaJS);
    if (decoder.messageName() == Messages::WebPageProxy::DidChangeMainDocument::name())
        return IPC::handleMessage<Messages::WebPageProxy::DidChangeMainDocument>(connection, decoder, this, &WebPageProxy::didChangeMainDocument);
    if (decoder.messageName() == Messages::WebPageProxy::DidExplicitOpenForFrame::name())
        return IPC::handleMessage<Messages::WebPageProxy::DidExplicitOpenForFrame>(connection, decoder, this, &WebPageProxy::didExplicitOpenForFrame);
    if (decoder.messageName() == Messages::WebPageProxy::DidDestroyNavigation::name())
        return IPC::handleMessage<Messages::WebPageProxy::DidDestroyNavigation>(connection, decoder, this, &WebPageProxy::didDestroyNavigation);
    if (decoder.messageName() == Messages::WebPageProxy::UpdateSandboxFlags::name())
        return IPC::handleMessage<Messages::WebPageProxy::UpdateSandboxFlags>(connection, decoder, this, &WebPageProxy::updateSandboxFlags);
    if (decoder.messageName() == Messages::WebPageProxy::UpdateOpener::name())
        return IPC::handleMessage<Messages::WebPageProxy::UpdateOpener>(connection, decoder, this, &WebPageProxy::updateOpener);
    if (decoder.messageName() == Messages::WebPageProxy::UpdateScrollingMode::name()) {
        if (!(sharedPreferences && sharedPreferences->siteIsolationEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::WebPageProxy::UpdateScrollingMode>(connection, decoder, this, &WebPageProxy::updateScrollingMode);
    }
    if (decoder.messageName() == Messages::WebPageProxy::ResolveAccessibilityHitTestForTesting::name())
        return IPC::handleMessageAsync<Messages::WebPageProxy::ResolveAccessibilityHitTestForTesting>(connection, decoder, this, &WebPageProxy::resolveAccessibilityHitTestForTesting);
    if (decoder.messageName() == Messages::WebPageProxy::MainFramePluginHandlesPageScaleGestureDidChange::name())
        return IPC::handleMessage<Messages::WebPageProxy::MainFramePluginHandlesPageScaleGestureDidChange>(connection, decoder, this, &WebPageProxy::mainFramePluginHandlesPageScaleGestureDidChange);
#if PLATFORM(GTK) || PLATFORM(WPE)
    if (decoder.messageName() == Messages::WebPageProxy::DidInitiateLoadForResource::name())
        return IPC::handleMessage<Messages::WebPageProxy::DidInitiateLoadForResource>(connection, decoder, this, &WebPageProxy::didInitiateLoadForResource);
    if (decoder.messageName() == Messages::WebPageProxy::DidSendRequestForResource::name())
        return IPC::handleMessage<Messages::WebPageProxy::DidSendRequestForResource>(connection, decoder, this, &WebPageProxy::didSendRequestForResource);
    if (decoder.messageName() == Messages::WebPageProxy::DidReceiveResponseForResource::name())
        return IPC::handleMessage<Messages::WebPageProxy::DidReceiveResponseForResource>(connection, decoder, this, &WebPageProxy::didReceiveResponseForResource);
    if (decoder.messageName() == Messages::WebPageProxy::DidFinishLoadForResource::name())
        return IPC::handleMessage<Messages::WebPageProxy::DidFinishLoadForResource>(connection, decoder, this, &WebPageProxy::didFinishLoadForResource);
#endif
    if (decoder.messageName() == Messages::WebPageProxy::DidNavigateWithNavigationData::name())
        return IPC::handleMessage<Messages::WebPageProxy::DidNavigateWithNavigationData>(connection, decoder, this, &WebPageProxy::didNavigateWithNavigationData);
    if (decoder.messageName() == Messages::WebPageProxy::DidPerformClientRedirect::name())
        return IPC::handleMessage<Messages::WebPageProxy::DidPerformClientRedirect>(connection, decoder, this, &WebPageProxy::didPerformClientRedirect);
    if (decoder.messageName() == Messages::WebPageProxy::DidPerformServerRedirect::name())
        return IPC::handleMessage<Messages::WebPageProxy::DidPerformServerRedirect>(connection, decoder, this, &WebPageProxy::didPerformServerRedirect);
    if (decoder.messageName() == Messages::WebPageProxy::DidUpdateHistoryTitle::name())
        return IPC::handleMessage<Messages::WebPageProxy::DidUpdateHistoryTitle>(connection, decoder, this, &WebPageProxy::didUpdateHistoryTitle);
    if (decoder.messageName() == Messages::WebPageProxy::DidFinishLoadingDataForCustomContentProvider::name())
        return IPC::handleMessage<Messages::WebPageProxy::DidFinishLoadingDataForCustomContentProvider>(connection, decoder, this, &WebPageProxy::didFinishLoadingDataForCustomContentProvider);
    if (decoder.messageName() == Messages::WebPageProxy::WillSubmitForm::name())
        return IPC::handleMessageAsync<Messages::WebPageProxy::WillSubmitForm>(connection, decoder, this, &WebPageProxy::willSubmitForm);
#if PLATFORM(IOS_FAMILY)
    if (decoder.messageName() == Messages::WebPageProxy::DidReceivePositionInformation::name())
        return IPC::handleMessage<Messages::WebPageProxy::DidReceivePositionInformation>(connection, decoder, this, &WebPageProxy::didReceivePositionInformation);
    if (decoder.messageName() == Messages::WebPageProxy::SaveImageToLibrary::name())
        return IPC::handleMessage<Messages::WebPageProxy::SaveImageToLibrary>(connection, decoder, this, &WebPageProxy::saveImageToLibrary);
    if (decoder.messageName() == Messages::WebPageProxy::ShowPlaybackTargetPicker::name())
        return IPC::handleMessage<Messages::WebPageProxy::ShowPlaybackTargetPicker>(connection, decoder, this, &WebPageProxy::showPlaybackTargetPicker);
    if (decoder.messageName() == Messages::WebPageProxy::CommitPotentialTapFailed::name())
        return IPC::handleMessage<Messages::WebPageProxy::CommitPotentialTapFailed>(connection, decoder, this, &WebPageProxy::commitPotentialTapFailed);
    if (decoder.messageName() == Messages::WebPageProxy::DidNotHandleTapAsClick::name())
        return IPC::handleMessage<Messages::WebPageProxy::DidNotHandleTapAsClick>(connection, decoder, this, &WebPageProxy::didNotHandleTapAsClick);
    if (decoder.messageName() == Messages::WebPageProxy::DidCompleteSyntheticClick::name())
        return IPC::handleMessage<Messages::WebPageProxy::DidCompleteSyntheticClick>(connection, decoder, this, &WebPageProxy::didCompleteSyntheticClick);
    if (decoder.messageName() == Messages::WebPageProxy::DidHandleTapAsHover::name())
        return IPC::handleMessage<Messages::WebPageProxy::DidHandleTapAsHover>(connection, decoder, this, &WebPageProxy::didHandleTapAsHover);
    if (decoder.messageName() == Messages::WebPageProxy::DisableDoubleTapGesturesDuringTapIfNecessary::name())
        return IPC::handleMessage<Messages::WebPageProxy::DisableDoubleTapGesturesDuringTapIfNecessary>(connection, decoder, this, &WebPageProxy::disableDoubleTapGesturesDuringTapIfNecessary);
    if (decoder.messageName() == Messages::WebPageProxy::HandleSmartMagnificationInformationForPotentialTap::name())
        return IPC::handleMessage<Messages::WebPageProxy::HandleSmartMagnificationInformationForPotentialTap>(connection, decoder, this, &WebPageProxy::handleSmartMagnificationInformationForPotentialTap);
    if (decoder.messageName() == Messages::WebPageProxy::IsPotentialTapInProgress::name())
        return IPC::handleMessageAsync<Messages::WebPageProxy::IsPotentialTapInProgress>(connection, decoder, this, &WebPageProxy::isPotentialTapInProgress);
#endif
#if ENABLE(DATA_DETECTION)
    if (decoder.messageName() == Messages::WebPageProxy::SetDataDetectionResult::name())
        return IPC::handleMessage<Messages::WebPageProxy::SetDataDetectionResult>(connection, decoder, this, &WebPageProxy::setDataDetectionResult);
    if (decoder.messageName() == Messages::WebPageProxy::HandleClickForDataDetectionResult::name())
        return IPC::handleMessage<Messages::WebPageProxy::HandleClickForDataDetectionResult>(connection, decoder, this, &WebPageProxy::handleClickForDataDetectionResult);
#endif
    if (decoder.messageName() == Messages::WebPageProxy::PageScaleFactorDidChange::name())
        return IPC::handleMessage<Messages::WebPageProxy::PageScaleFactorDidChange>(connection, decoder, this, &WebPageProxy::pageScaleFactorDidChange);
    if (decoder.messageName() == Messages::WebPageProxy::ViewScaleFactorDidChange::name())
        return IPC::handleMessage<Messages::WebPageProxy::ViewScaleFactorDidChange>(connection, decoder, this, &WebPageProxy::viewScaleFactorDidChange);
    if (decoder.messageName() == Messages::WebPageProxy::PluginScaleFactorDidChange::name())
        return IPC::handleMessage<Messages::WebPageProxy::PluginScaleFactorDidChange>(connection, decoder, this, &WebPageProxy::pluginScaleFactorDidChange);
    if (decoder.messageName() == Messages::WebPageProxy::PluginZoomFactorDidChange::name())
        return IPC::handleMessage<Messages::WebPageProxy::PluginZoomFactorDidChange>(connection, decoder, this, &WebPageProxy::pluginZoomFactorDidChange);
#if PLATFORM(GTK) || PLATFORM(WPE)
    if (decoder.messageName() == Messages::WebPageProxy::BindAccessibilityTree::name())
        return IPC::handleMessage<Messages::WebPageProxy::BindAccessibilityTree>(connection, decoder, this, &WebPageProxy::bindAccessibilityTree);
    if (decoder.messageName() == Messages::WebPageProxy::SetInputMethodState::name())
        return IPC::handleMessage<Messages::WebPageProxy::SetInputMethodState>(connection, decoder, this, &WebPageProxy::setInputMethodState);
#endif
    if (decoder.messageName() == Messages::WebPageProxy::BackForwardAddItem::name())
        return IPC::handleMessage<Messages::WebPageProxy::BackForwardAddItem>(connection, decoder, this, &WebPageProxy::backForwardAddItem);
    if (decoder.messageName() == Messages::WebPageProxy::BackForwardSetChildItem::name())
        return IPC::handleMessage<Messages::WebPageProxy::BackForwardSetChildItem>(connection, decoder, this, &WebPageProxy::backForwardSetChildItem);
    if (decoder.messageName() == Messages::WebPageProxy::BackForwardClearChildren::name())
        return IPC::handleMessage<Messages::WebPageProxy::BackForwardClearChildren>(connection, decoder, this, &WebPageProxy::backForwardClearChildren);
    if (decoder.messageName() == Messages::WebPageProxy::BackForwardUpdateItem::name())
        return IPC::handleMessage<Messages::WebPageProxy::BackForwardUpdateItem>(connection, decoder, this, &WebPageProxy::backForwardUpdateItem);
    if (decoder.messageName() == Messages::WebPageProxy::ShouldGoToBackForwardListItem::name())
        return IPC::handleMessageAsync<Messages::WebPageProxy::ShouldGoToBackForwardListItem>(connection, decoder, this, &WebPageProxy::shouldGoToBackForwardListItem);
    if (decoder.messageName() == Messages::WebPageProxy::RegisterEditCommandForUndo::name())
        return IPC::handleMessage<Messages::WebPageProxy::RegisterEditCommandForUndo>(connection, decoder, this, &WebPageProxy::registerEditCommandForUndo);
    if (decoder.messageName() == Messages::WebPageProxy::ClearAllEditCommands::name())
        return IPC::handleMessage<Messages::WebPageProxy::ClearAllEditCommands>(connection, decoder, this, &WebPageProxy::clearAllEditCommands);
    if (decoder.messageName() == Messages::WebPageProxy::RegisterInsertionUndoGrouping::name())
        return IPC::handleMessage<Messages::WebPageProxy::RegisterInsertionUndoGrouping>(connection, decoder, this, &WebPageProxy::registerInsertionUndoGrouping);
    if (decoder.messageName() == Messages::WebPageProxy::LogDiagnosticMessageFromWebProcess::name())
        return IPC::handleMessage<Messages::WebPageProxy::LogDiagnosticMessageFromWebProcess>(connection, decoder, this, &WebPageProxy::logDiagnosticMessageFromWebProcess);
    if (decoder.messageName() == Messages::WebPageProxy::LogDiagnosticMessageWithResultFromWebProcess::name())
        return IPC::handleMessage<Messages::WebPageProxy::LogDiagnosticMessageWithResultFromWebProcess>(connection, decoder, this, &WebPageProxy::logDiagnosticMessageWithResultFromWebProcess);
    if (decoder.messageName() == Messages::WebPageProxy::LogDiagnosticMessageWithValueFromWebProcess::name())
        return IPC::handleMessage<Messages::WebPageProxy::LogDiagnosticMessageWithValueFromWebProcess>(connection, decoder, this, &WebPageProxy::logDiagnosticMessageWithValueFromWebProcess);
    if (decoder.messageName() == Messages::WebPageProxy::LogDiagnosticMessageWithEnhancedPrivacyFromWebProcess::name())
        return IPC::handleMessage<Messages::WebPageProxy::LogDiagnosticMessageWithEnhancedPrivacyFromWebProcess>(connection, decoder, this, &WebPageProxy::logDiagnosticMessageWithEnhancedPrivacyFromWebProcess);
    if (decoder.messageName() == Messages::WebPageProxy::LogDiagnosticMessageWithValueDictionaryFromWebProcess::name())
        return IPC::handleMessage<Messages::WebPageProxy::LogDiagnosticMessageWithValueDictionaryFromWebProcess>(connection, decoder, this, &WebPageProxy::logDiagnosticMessageWithValueDictionaryFromWebProcess);
    if (decoder.messageName() == Messages::WebPageProxy::LogDiagnosticMessageWithDomainFromWebProcess::name())
        return IPC::handleMessage<Messages::WebPageProxy::LogDiagnosticMessageWithDomainFromWebProcess>(connection, decoder, this, &WebPageProxy::logDiagnosticMessageWithDomainFromWebProcess);
    if (decoder.messageName() == Messages::WebPageProxy::LogScrollingEvent::name())
        return IPC::handleMessage<Messages::WebPageProxy::LogScrollingEvent>(connection, decoder, this, &WebPageProxy::logScrollingEvent);
    if (decoder.messageName() == Messages::WebPageProxy::EditorStateChanged::name())
        return IPC::handleMessage<Messages::WebPageProxy::EditorStateChanged>(connection, decoder, this, &WebPageProxy::editorStateChanged);
    if (decoder.messageName() == Messages::WebPageProxy::CompositionWasCanceled::name())
        return IPC::handleMessage<Messages::WebPageProxy::CompositionWasCanceled>(connection, decoder, this, &WebPageProxy::compositionWasCanceled);
    if (decoder.messageName() == Messages::WebPageProxy::SetHasFocusedElementWithUserInteraction::name())
        return IPC::handleMessage<Messages::WebPageProxy::SetHasFocusedElementWithUserInteraction>(connection, decoder, this, &WebPageProxy::setHasFocusedElementWithUserInteraction);
#if ENABLE(IMAGE_ANALYSIS)
    if (decoder.messageName() == Messages::WebPageProxy::RequestTextRecognition::name())
        return IPC::handleMessageAsync<Messages::WebPageProxy::RequestTextRecognition>(connection, decoder, this, &WebPageProxy::requestTextRecognition);
#endif
#if HAVE(TRANSLATION_UI_SERVICES) && ENABLE(CONTEXT_MENUS)
    if (decoder.messageName() == Messages::WebPageProxy::HandleContextMenuTranslation::name())
        return IPC::handleMessage<Messages::WebPageProxy::HandleContextMenuTranslation>(connection, decoder, this, &WebPageProxy::handleContextMenuTranslation);
#endif
#if ENABLE(WRITING_TOOLS)
    if (decoder.messageName() == Messages::WebPageProxy::ProofreadingSessionShowDetailsForSuggestionWithIDRelativeToRect::name())
        return IPC::handleMessage<Messages::WebPageProxy::ProofreadingSessionShowDetailsForSuggestionWithIDRelativeToRect>(connection, decoder, this, &WebPageProxy::proofreadingSessionShowDetailsForSuggestionWithIDRelativeToRect);
    if (decoder.messageName() == Messages::WebPageProxy::ProofreadingSessionUpdateStateForSuggestionWithID::name())
        return IPC::handleMessage<Messages::WebPageProxy::ProofreadingSessionUpdateStateForSuggestionWithID>(connection, decoder, this, &WebPageProxy::proofreadingSessionUpdateStateForSuggestionWithID);
    if (decoder.messageName() == Messages::WebPageProxy::AddTextAnimationForAnimationID::name())
        return IPC::handleMessage<Messages::WebPageProxy::AddTextAnimationForAnimationID>(connection, decoder, this, &WebPageProxy::addTextAnimationForAnimationID);
    if (decoder.messageName() == Messages::WebPageProxy::AddTextAnimationForAnimationIDWithCompletionHandler::name())
        return IPC::handleMessageAsync<Messages::WebPageProxy::AddTextAnimationForAnimationIDWithCompletionHandler>(connection, decoder, this, &WebPageProxy::addTextAnimationForAnimationIDWithCompletionHandler);
    if (decoder.messageName() == Messages::WebPageProxy::RemoveTextAnimationForAnimationID::name())
        return IPC::handleMessage<Messages::WebPageProxy::RemoveTextAnimationForAnimationID>(connection, decoder, this, &WebPageProxy::removeTextAnimationForAnimationID);
    if (decoder.messageName() == Messages::WebPageProxy::DidEndPartialIntelligenceTextAnimation::name())
        return IPC::handleMessage<Messages::WebPageProxy::DidEndPartialIntelligenceTextAnimation>(connection, decoder, this, &WebPageProxy::didEndPartialIntelligenceTextAnimation);
#endif
#if ENABLE(MEDIA_CONTROLS_CONTEXT_MENUS) && USE(UICONTEXTMENU)
    if (decoder.messageName() == Messages::WebPageProxy::ShowMediaControlsContextMenu::name()) {
        if (!(sharedPreferences && sharedPreferences->mediaControlsContextMenusEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebPageProxy::ShowMediaControlsContextMenu>(connection, decoder, this, &WebPageProxy::showMediaControlsContextMenu);
    }
#endif
#if HAVE(TOUCH_BAR)
    if (decoder.messageName() == Messages::WebPageProxy::SetIsTouchBarUpdateSuppressedForHiddenContentEditable::name())
        return IPC::handleMessage<Messages::WebPageProxy::SetIsTouchBarUpdateSuppressedForHiddenContentEditable>(connection, decoder, this, &WebPageProxy::setIsTouchBarUpdateSuppressedForHiddenContentEditable);
    if (decoder.messageName() == Messages::WebPageProxy::SetIsNeverRichlyEditableForTouchBar::name())
        return IPC::handleMessage<Messages::WebPageProxy::SetIsNeverRichlyEditableForTouchBar>(connection, decoder, this, &WebPageProxy::setIsNeverRichlyEditableForTouchBar);
#endif
    if (decoder.messageName() == Messages::WebPageProxy::SetTextIndicatorFromFrame::name())
        return IPC::handleMessage<Messages::WebPageProxy::SetTextIndicatorFromFrame>(connection, decoder, this, &WebPageProxy::setTextIndicatorFromFrame);
    if (decoder.messageName() == Messages::WebPageProxy::UpdateTextIndicatorFromFrame::name())
        return IPC::handleMessage<Messages::WebPageProxy::UpdateTextIndicatorFromFrame>(connection, decoder, this, &WebPageProxy::updateTextIndicatorFromFrame);
    if (decoder.messageName() == Messages::WebPageProxy::ClearTextIndicator::name())
        return IPC::handleMessage<Messages::WebPageProxy::ClearTextIndicator>(connection, decoder, this, &WebPageProxy::clearTextIndicator);
    if (decoder.messageName() == Messages::WebPageProxy::DidGetImageForFindMatch::name())
        return IPC::handleMessage<Messages::WebPageProxy::DidGetImageForFindMatch>(connection, decoder, this, &WebPageProxy::didGetImageForFindMatch);
    if (decoder.messageName() == Messages::WebPageProxy::ShowPopupMenuFromFrame::name())
        return IPC::handleMessage<Messages::WebPageProxy::ShowPopupMenuFromFrame>(connection, decoder, this, &WebPageProxy::showPopupMenuFromFrame);
    if (decoder.messageName() == Messages::WebPageProxy::HidePopupMenu::name())
        return IPC::handleMessage<Messages::WebPageProxy::HidePopupMenu>(connection, decoder, this, &WebPageProxy::hidePopupMenu);
#if ENABLE(CONTEXT_MENUS)
    if (decoder.messageName() == Messages::WebPageProxy::ShowContextMenuFromFrame::name())
        return IPC::handleMessage<Messages::WebPageProxy::ShowContextMenuFromFrame>(connection, decoder, this, &WebPageProxy::showContextMenuFromFrame);
#endif
    if (decoder.messageName() == Messages::WebPageProxy::DidFinishServiceWorkerPageRegistration::name()) {
        if (!(sharedPreferences && sharedPreferences->serviceWorkersEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::WebPageProxy::DidFinishServiceWorkerPageRegistration>(connection, decoder, this, &WebPageProxy::didFinishServiceWorkerPageRegistration);
    }
    if (decoder.messageName() == Messages::WebPageProxy::RequestGeolocationPermissionForFrame::name()) {
        if (!(sharedPreferences && sharedPreferences->geolocationAPIEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::WebPageProxy::RequestGeolocationPermissionForFrame>(connection, decoder, this, &WebPageProxy::requestGeolocationPermissionForFrame);
    }
    if (decoder.messageName() == Messages::WebPageProxy::RevokeGeolocationAuthorizationToken::name()) {
        if (!(sharedPreferences && sharedPreferences->geolocationAPIEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::WebPageProxy::RevokeGeolocationAuthorizationToken>(connection, decoder, this, &WebPageProxy::revokeGeolocationAuthorizationToken);
    }
#if ENABLE(MEDIA_STREAM)
    if (decoder.messageName() == Messages::WebPageProxy::RequestUserMediaPermissionForFrame::name())
        return IPC::handleMessage<Messages::WebPageProxy::RequestUserMediaPermissionForFrame>(connection, decoder, this, &WebPageProxy::requestUserMediaPermissionForFrame);
    if (decoder.messageName() == Messages::WebPageProxy::EnumerateMediaDevicesForFrame::name())
        return IPC::handleMessageAsync<Messages::WebPageProxy::EnumerateMediaDevicesForFrame>(connection, decoder, this, &WebPageProxy::enumerateMediaDevicesForFrame);
    if (decoder.messageName() == Messages::WebPageProxy::BeginMonitoringCaptureDevices::name())
        return IPC::handleMessage<Messages::WebPageProxy::BeginMonitoringCaptureDevices>(connection, decoder, this, &WebPageProxy::beginMonitoringCaptureDevices);
    if (decoder.messageName() == Messages::WebPageProxy::ValidateCaptureStateUpdate::name())
        return IPC::handleMessageAsync<Messages::WebPageProxy::ValidateCaptureStateUpdate>(connection, decoder, this, &WebPageProxy::validateCaptureStateUpdate);
    if (decoder.messageName() == Messages::WebPageProxy::SetShouldListenToVoiceActivity::name())
        return IPC::handleMessage<Messages::WebPageProxy::SetShouldListenToVoiceActivity>(connection, decoder, this, &WebPageProxy::setShouldListenToVoiceActivity);
#endif
#if ENABLE(ENCRYPTED_MEDIA)
    if (decoder.messageName() == Messages::WebPageProxy::RequestMediaKeySystemPermissionForFrame::name()) {
        if (!(sharedPreferences && sharedPreferences->encryptedMediaAPIEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::WebPageProxy::RequestMediaKeySystemPermissionForFrame>(connection, decoder, this, &WebPageProxy::requestMediaKeySystemPermissionForFrame);
    }
#endif
    if (decoder.messageName() == Messages::WebPageProxy::RequestNotificationPermission::name())
        return IPC::handleMessageAsync<Messages::WebPageProxy::RequestNotificationPermission>(connection, decoder, this, &WebPageProxy::requestNotificationPermission);
    if (decoder.messageName() == Messages::WebPageProxy::UpdateSpellingUIWithMisspelledWord::name())
        return IPC::handleMessage<Messages::WebPageProxy::UpdateSpellingUIWithMisspelledWord>(connection, decoder, this, &WebPageProxy::updateSpellingUIWithMisspelledWord);
    if (decoder.messageName() == Messages::WebPageProxy::UpdateSpellingUIWithGrammarString::name())
        return IPC::handleMessage<Messages::WebPageProxy::UpdateSpellingUIWithGrammarString>(connection, decoder, this, &WebPageProxy::updateSpellingUIWithGrammarString);
    if (decoder.messageName() == Messages::WebPageProxy::LearnWord::name())
        return IPC::handleMessage<Messages::WebPageProxy::LearnWord>(connection, decoder, this, &WebPageProxy::learnWord);
    if (decoder.messageName() == Messages::WebPageProxy::IgnoreWord::name())
        return IPC::handleMessage<Messages::WebPageProxy::IgnoreWord>(connection, decoder, this, &WebPageProxy::ignoreWord);
    if (decoder.messageName() == Messages::WebPageProxy::RequestCheckingOfString::name())
        return IPC::handleMessage<Messages::WebPageProxy::RequestCheckingOfString>(connection, decoder, this, &WebPageProxy::requestCheckingOfString);
#if PLATFORM(COCOA) && ENABLE(DRAG_SUPPORT)
    if (decoder.messageName() == Messages::WebPageProxy::StartDrag::name())
        return IPC::handleMessage<Messages::WebPageProxy::StartDrag>(connection, decoder, this, &WebPageProxy::startDrag);
    if (decoder.messageName() == Messages::WebPageProxy::SetPromisedDataForImage::name())
        return IPC::handleMessage<Messages::WebPageProxy::SetPromisedDataForImage>(connection, decoder, this, &WebPageProxy::setPromisedDataForImage);
#endif
#if (PLATFORM(GTK) || PLATFORM(WPE)) && ENABLE(DRAG_SUPPORT)
    if (decoder.messageName() == Messages::WebPageProxy::StartDrag::name())
        return IPC::handleMessage<Messages::WebPageProxy::StartDrag>(connection, decoder, this, &WebPageProxy::startDrag);
#endif
#if PLATFORM(IOS_FAMILY) && ENABLE(DRAG_SUPPORT)
    if (decoder.messageName() == Messages::WebPageProxy::WillReceiveEditDragSnapshot::name())
        return IPC::handleMessage<Messages::WebPageProxy::WillReceiveEditDragSnapshot>(connection, decoder, this, &WebPageProxy::willReceiveEditDragSnapshot);
    if (decoder.messageName() == Messages::WebPageProxy::DidReceiveEditDragSnapshot::name())
        return IPC::handleMessage<Messages::WebPageProxy::DidReceiveEditDragSnapshot>(connection, decoder, this, &WebPageProxy::didReceiveEditDragSnapshot);
#endif
#if ENABLE(MODEL_PROCESS)
    if (decoder.messageName() == Messages::WebPageProxy::DidReceiveInteractiveModelElement::name())
        return IPC::handleMessage<Messages::WebPageProxy::DidReceiveInteractiveModelElement>(connection, decoder, this, &WebPageProxy::didReceiveInteractiveModelElement);
#endif
#if PLATFORM(COCOA)
    if (decoder.messageName() == Messages::WebPageProxy::DidPerformDictionaryLookup::name())
        return IPC::handleMessage<Messages::WebPageProxy::DidPerformDictionaryLookup>(connection, decoder, this, &WebPageProxy::didPerformDictionaryLookup);
    if (decoder.messageName() == Messages::WebPageProxy::RegisterWebProcessAccessibilityToken::name())
        return IPC::handleMessage<Messages::WebPageProxy::RegisterWebProcessAccessibilityToken>(connection, decoder, this, &WebPageProxy::registerWebProcessAccessibilityToken);
    if (decoder.messageName() == Messages::WebPageProxy::MakeFirstResponder::name())
        return IPC::handleMessage<Messages::WebPageProxy::MakeFirstResponder>(connection, decoder, this, &WebPageProxy::makeFirstResponder);
    if (decoder.messageName() == Messages::WebPageProxy::AssistiveTechnologyMakeFirstResponder::name())
        return IPC::handleMessage<Messages::WebPageProxy::AssistiveTechnologyMakeFirstResponder>(connection, decoder, this, &WebPageProxy::assistiveTechnologyMakeFirstResponder);
    if (decoder.messageName() == Messages::WebPageProxy::SearchTheWeb::name())
        return IPC::handleMessage<Messages::WebPageProxy::SearchTheWeb>(connection, decoder, this, &WebPageProxy::searchTheWeb);
#endif
#if USE(AUTOMATIC_TEXT_REPLACEMENT)
    if (decoder.messageName() == Messages::WebPageProxy::toggleSmartInsertDelete::name())
        return IPC::handleMessage<Messages::WebPageProxy::toggleSmartInsertDelete>(connection, decoder, this, &WebPageProxy::toggleSmartInsertDelete);
    if (decoder.messageName() == Messages::WebPageProxy::toggleAutomaticQuoteSubstitution::name())
        return IPC::handleMessage<Messages::WebPageProxy::toggleAutomaticQuoteSubstitution>(connection, decoder, this, &WebPageProxy::toggleAutomaticQuoteSubstitution);
    if (decoder.messageName() == Messages::WebPageProxy::toggleAutomaticLinkDetection::name())
        return IPC::handleMessage<Messages::WebPageProxy::toggleAutomaticLinkDetection>(connection, decoder, this, &WebPageProxy::toggleAutomaticLinkDetection);
    if (decoder.messageName() == Messages::WebPageProxy::toggleAutomaticDashSubstitution::name())
        return IPC::handleMessage<Messages::WebPageProxy::toggleAutomaticDashSubstitution>(connection, decoder, this, &WebPageProxy::toggleAutomaticDashSubstitution);
    if (decoder.messageName() == Messages::WebPageProxy::toggleAutomaticTextReplacement::name())
        return IPC::handleMessage<Messages::WebPageProxy::toggleAutomaticTextReplacement>(connection, decoder, this, &WebPageProxy::toggleAutomaticTextReplacement);
#endif
#if PLATFORM(MAC)
    if (decoder.messageName() == Messages::WebPageProxy::ShowCorrectionPanel::name())
        return IPC::handleMessage<Messages::WebPageProxy::ShowCorrectionPanel>(connection, decoder, this, &WebPageProxy::showCorrectionPanel);
    if (decoder.messageName() == Messages::WebPageProxy::DismissCorrectionPanel::name())
        return IPC::handleMessage<Messages::WebPageProxy::DismissCorrectionPanel>(connection, decoder, this, &WebPageProxy::dismissCorrectionPanel);
    if (decoder.messageName() == Messages::WebPageProxy::RecordAutocorrectionResponse::name())
        return IPC::handleMessage<Messages::WebPageProxy::RecordAutocorrectionResponse>(connection, decoder, this, &WebPageProxy::recordAutocorrectionResponse);
    if (decoder.messageName() == Messages::WebPageProxy::SetEditableElementIsFocused::name())
        return IPC::handleMessage<Messages::WebPageProxy::SetEditableElementIsFocused>(connection, decoder, this, &WebPageProxy::setEditableElementIsFocused);
    if (decoder.messageName() == Messages::WebPageProxy::HandleAcceptsFirstMouse::name())
        return IPC::handleMessage<Messages::WebPageProxy::HandleAcceptsFirstMouse>(connection, decoder, this, &WebPageProxy::handleAcceptsFirstMouse);
#endif
    if (decoder.messageName() == Messages::WebPageProxy::DidUpdateRenderingAfterCommittingLoad::name())
        return IPC::handleMessage<Messages::WebPageProxy::DidUpdateRenderingAfterCommittingLoad>(connection, decoder, this, &WebPageProxy::didUpdateRenderingAfterCommittingLoad);
#if USE(DICTATION_ALTERNATIVES)
    if (decoder.messageName() == Messages::WebPageProxy::ShowDictationAlternativeUI::name())
        return IPC::handleMessage<Messages::WebPageProxy::ShowDictationAlternativeUI>(connection, decoder, this, &WebPageProxy::showDictationAlternativeUI);
    if (decoder.messageName() == Messages::WebPageProxy::RemoveDictationAlternatives::name())
        return IPC::handleMessage<Messages::WebPageProxy::RemoveDictationAlternatives>(connection, decoder, this, &WebPageProxy::removeDictationAlternatives);
#endif
#if ENABLE(IMAGE_ANALYSIS) && ENABLE(VIDEO)
    if (decoder.messageName() == Messages::WebPageProxy::BeginTextRecognitionForVideoInElementFullScreen::name()) {
        if (!(sharedPreferences && sharedPreferences->textRecognitionInVideosEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::WebPageProxy::BeginTextRecognitionForVideoInElementFullScreen>(connection, decoder, this, &WebPageProxy::beginTextRecognitionForVideoInElementFullScreen);
    }
    if (decoder.messageName() == Messages::WebPageProxy::CancelTextRecognitionForVideoInElementFullScreen::name()) {
        if (!(sharedPreferences && sharedPreferences->textRecognitionInVideosEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::WebPageProxy::CancelTextRecognitionForVideoInElementFullScreen>(connection, decoder, this, &WebPageProxy::cancelTextRecognitionForVideoInElementFullScreen);
    }
#endif
#if PLATFORM(IOS_FAMILY)
    if (decoder.messageName() == Messages::WebPageProxy::CouldNotRestorePageState::name())
        return IPC::handleMessage<Messages::WebPageProxy::CouldNotRestorePageState>(connection, decoder, this, &WebPageProxy::couldNotRestorePageState);
    if (decoder.messageName() == Messages::WebPageProxy::RestorePageState::name())
        return IPC::handleMessage<Messages::WebPageProxy::RestorePageState>(connection, decoder, this, &WebPageProxy::restorePageState);
    if (decoder.messageName() == Messages::WebPageProxy::RestorePageCenterAndScale::name())
        return IPC::handleMessage<Messages::WebPageProxy::RestorePageCenterAndScale>(connection, decoder, this, &WebPageProxy::restorePageCenterAndScale);
    if (decoder.messageName() == Messages::WebPageProxy::DidGetTapHighlightGeometries::name())
        return IPC::handleMessage<Messages::WebPageProxy::DidGetTapHighlightGeometries>(connection, decoder, this, &WebPageProxy::didGetTapHighlightGeometries);
    if (decoder.messageName() == Messages::WebPageProxy::ElementDidFocus::name())
        return IPC::handleMessage<Messages::WebPageProxy::ElementDidFocus>(connection, decoder, this, &WebPageProxy::elementDidFocus);
    if (decoder.messageName() == Messages::WebPageProxy::ElementDidBlur::name())
        return IPC::handleMessage<Messages::WebPageProxy::ElementDidBlur>(connection, decoder, this, &WebPageProxy::elementDidBlur);
    if (decoder.messageName() == Messages::WebPageProxy::UpdateInputContextAfterBlurringAndRefocusingElement::name())
        return IPC::handleMessage<Messages::WebPageProxy::UpdateInputContextAfterBlurringAndRefocusingElement>(connection, decoder, this, &WebPageProxy::updateInputContextAfterBlurringAndRefocusingElement);
    if (decoder.messageName() == Messages::WebPageProxy::DidProgrammaticallyClearFocusedElement::name())
        return IPC::handleMessage<Messages::WebPageProxy::DidProgrammaticallyClearFocusedElement>(connection, decoder, this, &WebPageProxy::didProgrammaticallyClearFocusedElement);
    if (decoder.messageName() == Messages::WebPageProxy::UpdateFocusedElementInformation::name())
        return IPC::handleMessage<Messages::WebPageProxy::UpdateFocusedElementInformation>(connection, decoder, this, &WebPageProxy::updateFocusedElementInformation);
    if (decoder.messageName() == Messages::WebPageProxy::FocusedElementDidChangeInputMode::name())
        return IPC::handleMessage<Messages::WebPageProxy::FocusedElementDidChangeInputMode>(connection, decoder, this, &WebPageProxy::focusedElementDidChangeInputMode);
    if (decoder.messageName() == Messages::WebPageProxy::ScrollingNodeScrollWillStartScroll::name())
        return IPC::handleMessage<Messages::WebPageProxy::ScrollingNodeScrollWillStartScroll>(connection, decoder, this, &WebPageProxy::scrollingNodeScrollWillStartScroll);
    if (decoder.messageName() == Messages::WebPageProxy::ScrollingNodeScrollDidEndScroll::name())
        return IPC::handleMessage<Messages::WebPageProxy::ScrollingNodeScrollDidEndScroll>(connection, decoder, this, &WebPageProxy::scrollingNodeScrollDidEndScroll);
    if (decoder.messageName() == Messages::WebPageProxy::ShowInspectorHighlight::name())
        return IPC::handleMessage<Messages::WebPageProxy::ShowInspectorHighlight>(connection, decoder, this, &WebPageProxy::showInspectorHighlight);
    if (decoder.messageName() == Messages::WebPageProxy::HideInspectorHighlight::name())
        return IPC::handleMessage<Messages::WebPageProxy::HideInspectorHighlight>(connection, decoder, this, &WebPageProxy::hideInspectorHighlight);
    if (decoder.messageName() == Messages::WebPageProxy::ShowInspectorIndication::name())
        return IPC::handleMessage<Messages::WebPageProxy::ShowInspectorIndication>(connection, decoder, this, &WebPageProxy::showInspectorIndication);
    if (decoder.messageName() == Messages::WebPageProxy::HideInspectorIndication::name())
        return IPC::handleMessage<Messages::WebPageProxy::HideInspectorIndication>(connection, decoder, this, &WebPageProxy::hideInspectorIndication);
    if (decoder.messageName() == Messages::WebPageProxy::EnableInspectorNodeSearch::name())
        return IPC::handleMessage<Messages::WebPageProxy::EnableInspectorNodeSearch>(connection, decoder, this, &WebPageProxy::enableInspectorNodeSearch);
    if (decoder.messageName() == Messages::WebPageProxy::DisableInspectorNodeSearch::name())
        return IPC::handleMessage<Messages::WebPageProxy::DisableInspectorNodeSearch>(connection, decoder, this, &WebPageProxy::disableInspectorNodeSearch);
    if (decoder.messageName() == Messages::WebPageProxy::UpdateStringForFind::name())
        return IPC::handleMessage<Messages::WebPageProxy::UpdateStringForFind>(connection, decoder, this, &WebPageProxy::updateStringForFind);
    if (decoder.messageName() == Messages::WebPageProxy::HandleAutocorrectionContext::name())
        return IPC::handleMessage<Messages::WebPageProxy::HandleAutocorrectionContext>(connection, decoder, this, &WebPageProxy::handleAutocorrectionContext);
    if (decoder.messageName() == Messages::WebPageProxy::ShowDataDetectorsUIForPositionInformation::name())
        return IPC::handleMessage<Messages::WebPageProxy::ShowDataDetectorsUIForPositionInformation>(connection, decoder, this, &WebPageProxy::showDataDetectorsUIForPositionInformation);
#endif
    if (decoder.messageName() == Messages::WebPageProxy::DidChangeInspectorFrontendCount::name())
        return IPC::handleMessage<Messages::WebPageProxy::DidChangeInspectorFrontendCount>(connection, decoder, this, &WebPageProxy::didChangeInspectorFrontendCount);
    if (decoder.messageName() == Messages::WebPageProxy::CreateInspectorTarget::name())
        return IPC::handleMessage<Messages::WebPageProxy::CreateInspectorTarget>(connection, decoder, this, &WebPageProxy::createInspectorTarget);
    if (decoder.messageName() == Messages::WebPageProxy::DestroyInspectorTarget::name())
        return IPC::handleMessage<Messages::WebPageProxy::DestroyInspectorTarget>(connection, decoder, this, &WebPageProxy::destroyInspectorTarget);
    if (decoder.messageName() == Messages::WebPageProxy::SendMessageToInspectorFrontend::name())
        return IPC::handleMessage<Messages::WebPageProxy::SendMessageToInspectorFrontend>(connection, decoder, this, &WebPageProxy::sendMessageToInspectorFrontend);
    if (decoder.messageName() == Messages::WebPageProxy::SaveRecentSearches::name())
        return IPC::handleMessage<Messages::WebPageProxy::SaveRecentSearches>(connection, decoder, this, &WebPageProxy::saveRecentSearches);
    if (decoder.messageName() == Messages::WebPageProxy::DidUpdateActivityState::name())
        return IPC::handleMessage<Messages::WebPageProxy::DidUpdateActivityState>(connection, decoder, this, &WebPageProxy::didUpdateActivityState);
#if (ENABLE(TELEPHONE_NUMBER_DETECTION) && PLATFORM(MAC))
    if (decoder.messageName() == Messages::WebPageProxy::ShowTelephoneNumberMenu::name())
        return IPC::handleMessage<Messages::WebPageProxy::ShowTelephoneNumberMenu>(connection, decoder, this, &WebPageProxy::showTelephoneNumberMenu);
#endif
#if USE(QUICK_LOOK)
    if (decoder.messageName() == Messages::WebPageProxy::DidStartLoadForQuickLookDocumentInMainFrame::name())
        return IPC::handleMessage<Messages::WebPageProxy::DidStartLoadForQuickLookDocumentInMainFrame>(connection, decoder, this, &WebPageProxy::didStartLoadForQuickLookDocumentInMainFrame);
    if (decoder.messageName() == Messages::WebPageProxy::DidFinishLoadForQuickLookDocumentInMainFrame::name())
        return IPC::handleMessage<Messages::WebPageProxy::DidFinishLoadForQuickLookDocumentInMainFrame>(connection, decoder, this, &WebPageProxy::didFinishLoadForQuickLookDocumentInMainFrame);
    if (decoder.messageName() == Messages::WebPageProxy::RequestPasswordForQuickLookDocumentInMainFrame::name())
        return IPC::handleMessageAsync<Messages::WebPageProxy::RequestPasswordForQuickLookDocumentInMainFrame>(connection, decoder, this, &WebPageProxy::requestPasswordForQuickLookDocumentInMainFrame);
#endif
#if ENABLE(CONTENT_FILTERING)
    if (decoder.messageName() == Messages::WebPageProxy::ContentFilterDidBlockLoadForFrame::name())
        return IPC::handleMessage<Messages::WebPageProxy::ContentFilterDidBlockLoadForFrame>(connection, decoder, this, &WebPageProxy::contentFilterDidBlockLoadForFrame);
#endif
#if ENABLE(ACCESSIBILITY_ANIMATION_CONTROL)
    if (decoder.messageName() == Messages::WebPageProxy::IsAnyAnimationAllowedToPlayDidChange::name())
        return IPC::handleMessage<Messages::WebPageProxy::IsAnyAnimationAllowedToPlayDidChange>(connection, decoder, this, &WebPageProxy::isAnyAnimationAllowedToPlayDidChange);
#endif
    if (decoder.messageName() == Messages::WebPageProxy::IsPlayingMediaDidChange::name())
        return IPC::handleMessage<Messages::WebPageProxy::IsPlayingMediaDidChange>(connection, decoder, this, &WebPageProxy::isPlayingMediaDidChange);
    if (decoder.messageName() == Messages::WebPageProxy::HandleAutoplayEvent::name())
        return IPC::handleMessage<Messages::WebPageProxy::HandleAutoplayEvent>(connection, decoder, this, &WebPageProxy::handleAutoplayEvent);
#if PLATFORM(MAC)
    if (decoder.messageName() == Messages::WebPageProxy::DidPerformImmediateActionHitTest::name())
        return IPC::handleMessage<Messages::WebPageProxy::DidPerformImmediateActionHitTest>(connection, decoder, this, &WebPageProxy::didPerformImmediateActionHitTest);
#endif
    if (decoder.messageName() == Messages::WebPageProxy::HandleMessage::name())
        return IPC::handleMessage<Messages::WebPageProxy::HandleMessage>(connection, decoder, this, &WebPageProxy::handleMessage);
    if (decoder.messageName() == Messages::WebPageProxy::HandleMessageWithAsyncReply::name())
        return IPC::handleMessageAsync<Messages::WebPageProxy::HandleMessageWithAsyncReply>(connection, decoder, this, &WebPageProxy::handleMessageWithAsyncReply);
    if (decoder.messageName() == Messages::WebPageProxy::HandleAutoFillButtonClick::name())
        return IPC::handleMessage<Messages::WebPageProxy::HandleAutoFillButtonClick>(connection, decoder, this, &WebPageProxy::handleAutoFillButtonClick);
    if (decoder.messageName() == Messages::WebPageProxy::DidResignInputElementStrongPasswordAppearance::name())
        return IPC::handleMessage<Messages::WebPageProxy::DidResignInputElementStrongPasswordAppearance>(connection, decoder, this, &WebPageProxy::didResignInputElementStrongPasswordAppearance);
    if (decoder.messageName() == Messages::WebPageProxy::PerformSwitchHapticFeedback::name())
        return IPC::handleMessage<Messages::WebPageProxy::PerformSwitchHapticFeedback>(connection, decoder, this, &WebPageProxy::performSwitchHapticFeedback);
#if ENABLE(CONTENT_EXTENSIONS)
    if (decoder.messageName() == Messages::WebPageProxy::ContentRuleListNotification::name())
        return IPC::handleMessage<Messages::WebPageProxy::ContentRuleListNotification>(connection, decoder, this, &WebPageProxy::contentRuleListNotification);
#endif
#if ENABLE(WIRELESS_PLAYBACK_TARGET) && !PLATFORM(IOS_FAMILY)
    if (decoder.messageName() == Messages::WebPageProxy::AddPlaybackTargetPickerClient::name())
        return IPC::handleMessage<Messages::WebPageProxy::AddPlaybackTargetPickerClient>(connection, decoder, this, &WebPageProxy::addPlaybackTargetPickerClient);
    if (decoder.messageName() == Messages::WebPageProxy::RemovePlaybackTargetPickerClient::name())
        return IPC::handleMessage<Messages::WebPageProxy::RemovePlaybackTargetPickerClient>(connection, decoder, this, &WebPageProxy::removePlaybackTargetPickerClient);
    if (decoder.messageName() == Messages::WebPageProxy::ShowPlaybackTargetPicker::name())
        return IPC::handleMessage<Messages::WebPageProxy::ShowPlaybackTargetPicker>(connection, decoder, this, &WebPageProxy::showPlaybackTargetPicker);
    if (decoder.messageName() == Messages::WebPageProxy::PlaybackTargetPickerClientStateDidChange::name())
        return IPC::handleMessage<Messages::WebPageProxy::PlaybackTargetPickerClientStateDidChange>(connection, decoder, this, &WebPageProxy::playbackTargetPickerClientStateDidChange);
    if (decoder.messageName() == Messages::WebPageProxy::SetMockMediaPlaybackTargetPickerEnabled::name())
        return IPC::handleMessage<Messages::WebPageProxy::SetMockMediaPlaybackTargetPickerEnabled>(connection, decoder, this, &WebPageProxy::setMockMediaPlaybackTargetPickerEnabled);
    if (decoder.messageName() == Messages::WebPageProxy::SetMockMediaPlaybackTargetPickerState::name())
        return IPC::handleMessage<Messages::WebPageProxy::SetMockMediaPlaybackTargetPickerState>(connection, decoder, this, &WebPageProxy::setMockMediaPlaybackTargetPickerState);
    if (decoder.messageName() == Messages::WebPageProxy::MockMediaPlaybackTargetPickerDismissPopup::name())
        return IPC::handleMessage<Messages::WebPageProxy::MockMediaPlaybackTargetPickerDismissPopup>(connection, decoder, this, &WebPageProxy::mockMediaPlaybackTargetPickerDismissPopup);
#endif
#if ENABLE(VIDEO_PRESENTATION_MODE)
    if (decoder.messageName() == Messages::WebPageProxy::SetMockVideoPresentationModeEnabled::name()) {
        if (!(sharedPreferences && (sharedPreferences->videoPresentationManagerEnabled || sharedPreferences->videoPresentationModeAPIEnabled))) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::WebPageProxy::SetMockVideoPresentationModeEnabled>(connection, decoder, this, &WebPageProxy::setMockVideoPresentationModeEnabled);
    }
#endif
#if ENABLE(POINTER_LOCK)
    if (decoder.messageName() == Messages::WebPageProxy::RequestPointerLock::name())
        return IPC::handleMessageAsync<Messages::WebPageProxy::RequestPointerLock>(connection, decoder, this, &WebPageProxy::requestPointerLock);
    if (decoder.messageName() == Messages::WebPageProxy::RequestPointerUnlock::name())
        return IPC::handleMessageAsync<Messages::WebPageProxy::RequestPointerUnlock>(connection, decoder, this, &WebPageProxy::requestPointerUnlock);
#endif
    if (decoder.messageName() == Messages::WebPageProxy::ImageOrMediaDocumentSizeChanged::name())
        return IPC::handleMessage<Messages::WebPageProxy::ImageOrMediaDocumentSizeChanged>(connection, decoder, this, &WebPageProxy::imageOrMediaDocumentSizeChanged);
    if (decoder.messageName() == Messages::WebPageProxy::UseFixedLayoutDidChange::name())
        return IPC::handleMessage<Messages::WebPageProxy::UseFixedLayoutDidChange>(connection, decoder, this, &WebPageProxy::useFixedLayoutDidChange);
    if (decoder.messageName() == Messages::WebPageProxy::FixedLayoutSizeDidChange::name())
        return IPC::handleMessage<Messages::WebPageProxy::FixedLayoutSizeDidChange>(connection, decoder, this, &WebPageProxy::fixedLayoutSizeDidChange);
    if (decoder.messageName() == Messages::WebPageProxy::DidRestoreScrollPosition::name())
        return IPC::handleMessage<Messages::WebPageProxy::DidRestoreScrollPosition>(connection, decoder, this, &WebPageProxy::didRestoreScrollPosition);
    if (decoder.messageName() == Messages::WebPageProxy::RequestScrollToRect::name())
        return IPC::handleMessage<Messages::WebPageProxy::RequestScrollToRect>(connection, decoder, this, &WebPageProxy::requestScrollToRect);
    if (decoder.messageName() == Messages::WebPageProxy::GetLoadDecisionForIcon::name())
        return IPC::handleMessage<Messages::WebPageProxy::GetLoadDecisionForIcon>(connection, decoder, this, &WebPageProxy::getLoadDecisionForIcon);
    if (decoder.messageName() == Messages::WebPageProxy::StartURLSchemeTask::name())
        return IPC::handleMessage<Messages::WebPageProxy::StartURLSchemeTask>(connection, decoder, this, &WebPageProxy::startURLSchemeTask);
    if (decoder.messageName() == Messages::WebPageProxy::StopURLSchemeTask::name())
        return IPC::handleMessage<Messages::WebPageProxy::StopURLSchemeTask>(connection, decoder, this, &WebPageProxy::stopURLSchemeTask);
#if ENABLE(DEVICE_ORIENTATION)
    if (decoder.messageName() == Messages::WebPageProxy::ShouldAllowDeviceOrientationAndMotionAccess::name()) {
        if (!(sharedPreferences && sharedPreferences->deviceOrientationPermissionAPIEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebPageProxy::ShouldAllowDeviceOrientationAndMotionAccess>(connection, decoder, this, &WebPageProxy::shouldAllowDeviceOrientationAndMotionAccess);
    }
#endif
#if ENABLE(ATTACHMENT_ELEMENT)
    if (decoder.messageName() == Messages::WebPageProxy::RegisterAttachmentIdentifierFromData::name()) {
        if (!(sharedPreferences && sharedPreferences->attachmentElementEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::WebPageProxy::RegisterAttachmentIdentifierFromData>(connection, decoder, this, &WebPageProxy::registerAttachmentIdentifierFromData);
    }
    if (decoder.messageName() == Messages::WebPageProxy::RegisterAttachmentIdentifierFromFilePath::name()) {
        if (!(sharedPreferences && sharedPreferences->attachmentElementEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::WebPageProxy::RegisterAttachmentIdentifierFromFilePath>(connection, decoder, this, &WebPageProxy::registerAttachmentIdentifierFromFilePath);
    }
    if (decoder.messageName() == Messages::WebPageProxy::RegisterAttachmentIdentifier::name()) {
        if (!(sharedPreferences && sharedPreferences->attachmentElementEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::WebPageProxy::RegisterAttachmentIdentifier>(connection, decoder, this, &WebPageProxy::registerAttachmentIdentifier);
    }
    if (decoder.messageName() == Messages::WebPageProxy::RegisterAttachmentsFromSerializedData::name()) {
        if (!(sharedPreferences && sharedPreferences->attachmentElementEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::WebPageProxy::RegisterAttachmentsFromSerializedData>(connection, decoder, this, &WebPageProxy::registerAttachmentsFromSerializedData);
    }
    if (decoder.messageName() == Messages::WebPageProxy::CloneAttachmentData::name()) {
        if (!(sharedPreferences && sharedPreferences->attachmentElementEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::WebPageProxy::CloneAttachmentData>(connection, decoder, this, &WebPageProxy::cloneAttachmentData);
    }
    if (decoder.messageName() == Messages::WebPageProxy::DidInsertAttachmentWithIdentifier::name()) {
        if (!(sharedPreferences && sharedPreferences->attachmentElementEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::WebPageProxy::DidInsertAttachmentWithIdentifier>(connection, decoder, this, &WebPageProxy::didInsertAttachmentWithIdentifier);
    }
    if (decoder.messageName() == Messages::WebPageProxy::DidRemoveAttachmentWithIdentifier::name()) {
        if (!(sharedPreferences && sharedPreferences->attachmentElementEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::WebPageProxy::DidRemoveAttachmentWithIdentifier>(connection, decoder, this, &WebPageProxy::didRemoveAttachmentWithIdentifier);
    }
#endif
#if (ENABLE(ATTACHMENT_ELEMENT) && PLATFORM(IOS_FAMILY))
    if (decoder.messageName() == Messages::WebPageProxy::WritePromisedAttachmentToPasteboard::name()) {
        if (!(sharedPreferences && sharedPreferences->attachmentElementEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::WebPageProxy::WritePromisedAttachmentToPasteboard>(connection, decoder, this, &WebPageProxy::writePromisedAttachmentToPasteboard);
    }
#endif
#if ENABLE(ATTACHMENT_ELEMENT)
    if (decoder.messageName() == Messages::WebPageProxy::RequestAttachmentIcon::name()) {
        if (!(sharedPreferences && sharedPreferences->attachmentElementEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::WebPageProxy::RequestAttachmentIcon>(connection, decoder, this, &WebPageProxy::requestAttachmentIcon);
    }
#endif
#if ENABLE(SPEECH_SYNTHESIS)
    if (decoder.messageName() == Messages::WebPageProxy::SpeechSynthesisSpeak::name()) {
        if (!(sharedPreferences && sharedPreferences->speechSynthesisAPIEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebPageProxy::SpeechSynthesisSpeak>(connection, decoder, this, &WebPageProxy::speechSynthesisSpeak);
    }
    if (decoder.messageName() == Messages::WebPageProxy::SpeechSynthesisSetFinishedCallback::name()) {
        if (!(sharedPreferences && sharedPreferences->speechSynthesisAPIEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebPageProxy::SpeechSynthesisSetFinishedCallback>(connection, decoder, this, &WebPageProxy::speechSynthesisSetFinishedCallback);
    }
    if (decoder.messageName() == Messages::WebPageProxy::SpeechSynthesisCancel::name()) {
        if (!(sharedPreferences && sharedPreferences->speechSynthesisAPIEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::WebPageProxy::SpeechSynthesisCancel>(connection, decoder, this, &WebPageProxy::speechSynthesisCancel);
    }
    if (decoder.messageName() == Messages::WebPageProxy::SpeechSynthesisPause::name()) {
        if (!(sharedPreferences && sharedPreferences->speechSynthesisAPIEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebPageProxy::SpeechSynthesisPause>(connection, decoder, this, &WebPageProxy::speechSynthesisPause);
    }
    if (decoder.messageName() == Messages::WebPageProxy::SpeechSynthesisResume::name()) {
        if (!(sharedPreferences && sharedPreferences->speechSynthesisAPIEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebPageProxy::SpeechSynthesisResume>(connection, decoder, this, &WebPageProxy::speechSynthesisResume);
    }
    if (decoder.messageName() == Messages::WebPageProxy::SpeechSynthesisResetState::name()) {
        if (!(sharedPreferences && sharedPreferences->speechSynthesisAPIEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::WebPageProxy::SpeechSynthesisResetState>(connection, decoder, this, &WebPageProxy::speechSynthesisResetState);
    }
#endif
#if ENABLE(PDF_PLUGIN) && PLATFORM(MAC)
    if (decoder.messageName() == Messages::WebPageProxy::ShowPDFContextMenu::name())
        return IPC::handleMessageAsync<Messages::WebPageProxy::ShowPDFContextMenu>(connection, decoder, this, &WebPageProxy::showPDFContextMenu);
#endif
#if ENABLE(PDF_HUD)
    if (decoder.messageName() == Messages::WebPageProxy::CreatePDFHUD::name())
        return IPC::handleMessage<Messages::WebPageProxy::CreatePDFHUD>(connection, decoder, this, &WebPageProxy::createPDFHUD);
    if (decoder.messageName() == Messages::WebPageProxy::UpdatePDFHUDLocation::name())
        return IPC::handleMessage<Messages::WebPageProxy::UpdatePDFHUDLocation>(connection, decoder, this, &WebPageProxy::updatePDFHUDLocation);
    if (decoder.messageName() == Messages::WebPageProxy::RemovePDFHUD::name())
        return IPC::handleMessage<Messages::WebPageProxy::RemovePDFHUD>(connection, decoder, this, &WebPageProxy::removePDFHUD);
#endif
#if ENABLE(PDF_PAGE_NUMBER_INDICATOR)
    if (decoder.messageName() == Messages::WebPageProxy::CreatePDFPageNumberIndicator::name())
        return IPC::handleMessage<Messages::WebPageProxy::CreatePDFPageNumberIndicator>(connection, decoder, this, &WebPageProxy::createPDFPageNumberIndicator);
    if (decoder.messageName() == Messages::WebPageProxy::UpdatePDFPageNumberIndicatorLocation::name())
        return IPC::handleMessage<Messages::WebPageProxy::UpdatePDFPageNumberIndicatorLocation>(connection, decoder, this, &WebPageProxy::updatePDFPageNumberIndicatorLocation);
    if (decoder.messageName() == Messages::WebPageProxy::UpdatePDFPageNumberIndicatorCurrentPage::name())
        return IPC::handleMessage<Messages::WebPageProxy::UpdatePDFPageNumberIndicatorCurrentPage>(connection, decoder, this, &WebPageProxy::updatePDFPageNumberIndicatorCurrentPage);
    if (decoder.messageName() == Messages::WebPageProxy::RemovePDFPageNumberIndicator::name())
        return IPC::handleMessage<Messages::WebPageProxy::RemovePDFPageNumberIndicator>(connection, decoder, this, &WebPageProxy::removePDFPageNumberIndicator);
#endif
    if (decoder.messageName() == Messages::WebPageProxy::ConfigureLoggingChannel::name())
        return IPC::handleMessage<Messages::WebPageProxy::ConfigureLoggingChannel>(connection, decoder, this, &WebPageProxy::configureLoggingChannel);
#if PLATFORM(GTK)
    if (decoder.messageName() == Messages::WebPageProxy::ShowEmojiPicker::name())
        return IPC::handleMessageAsync<Messages::WebPageProxy::ShowEmojiPicker>(connection, decoder, this, &WebPageProxy::showEmojiPicker);
#endif
#if HAVE(VISIBILITY_PROPAGATION_VIEW)
    if (decoder.messageName() == Messages::WebPageProxy::DidCreateContextInWebProcessForVisibilityPropagation::name())
        return IPC::handleMessage<Messages::WebPageProxy::DidCreateContextInWebProcessForVisibilityPropagation>(connection, decoder, this, &WebPageProxy::didCreateContextInWebProcessForVisibilityPropagation);
#endif
#if ENABLE(WEB_AUTHN)
    if (decoder.messageName() == Messages::WebPageProxy::SetMockWebAuthenticationConfiguration::name()) {
        if (!(sharedPreferences && sharedPreferences->allowTestOnlyIPC)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::WebPageProxy::SetMockWebAuthenticationConfiguration>(connection, decoder, this, &WebPageProxy::setMockWebAuthenticationConfiguration);
    }
#endif
#if PLATFORM(GTK) || PLATFORM(WPE)
    if (decoder.messageName() == Messages::WebPageProxy::SendMessageToWebView::name())
        return IPC::handleMessage<Messages::WebPageProxy::SendMessageToWebView>(connection, decoder, this, &WebPageProxy::sendMessageToWebView);
    if (decoder.messageName() == Messages::WebPageProxy::SendMessageToWebViewWithReply::name())
        return IPC::handleMessageAsync<Messages::WebPageProxy::SendMessageToWebViewWithReply>(connection, decoder, this, &WebPageProxy::sendMessageToWebViewWithReply);
#endif
    if (decoder.messageName() == Messages::WebPageProxy::DidFindTextManipulationItems::name())
        return IPC::handleMessage<Messages::WebPageProxy::DidFindTextManipulationItems>(connection, decoder, this, &WebPageProxy::didFindTextManipulationItems);
#if ENABLE(MEDIA_USAGE)
    if (decoder.messageName() == Messages::WebPageProxy::AddMediaUsageManagerSession::name())
        return IPC::handleMessage<Messages::WebPageProxy::AddMediaUsageManagerSession>(connection, decoder, this, &WebPageProxy::addMediaUsageManagerSession);
    if (decoder.messageName() == Messages::WebPageProxy::UpdateMediaUsageManagerSessionState::name())
        return IPC::handleMessage<Messages::WebPageProxy::UpdateMediaUsageManagerSessionState>(connection, decoder, this, &WebPageProxy::updateMediaUsageManagerSessionState);
    if (decoder.messageName() == Messages::WebPageProxy::RemoveMediaUsageManagerSession::name())
        return IPC::handleMessage<Messages::WebPageProxy::RemoveMediaUsageManagerSession>(connection, decoder, this, &WebPageProxy::removeMediaUsageManagerSession);
#endif
    if (decoder.messageName() == Messages::WebPageProxy::SetHasExecutedAppBoundBehaviorBeforeNavigation::name())
        return IPC::handleMessage<Messages::WebPageProxy::SetHasExecutedAppBoundBehaviorBeforeNavigation>(connection, decoder, this, &WebPageProxy::setHasExecutedAppBoundBehaviorBeforeNavigation);
#if PLATFORM(MAC)
    if (decoder.messageName() == Messages::WebPageProxy::ChangeUniversalAccessZoomFocus::name())
        return IPC::handleMessage<Messages::WebPageProxy::ChangeUniversalAccessZoomFocus>(connection, decoder, this, &WebPageProxy::changeUniversalAccessZoomFocus);
#endif
#if ENABLE(ARKIT_INLINE_PREVIEW_IOS)
    if (decoder.messageName() == Messages::WebPageProxy::TakeModelElementFullscreen::name()) {
        if (!(sharedPreferences && sharedPreferences->modelElementEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::WebPageProxy::TakeModelElementFullscreen>(connection, decoder, this, &WebPageProxy::takeModelElementFullscreen);
    }
    if (decoder.messageName() == Messages::WebPageProxy::ModelElementSetInteractionEnabled::name()) {
        if (!(sharedPreferences && sharedPreferences->modelElementEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::WebPageProxy::ModelElementSetInteractionEnabled>(connection, decoder, this, &WebPageProxy::modelElementSetInteractionEnabled);
    }
#endif
#if ENABLE(ARKIT_INLINE_PREVIEW_MAC)
    if (decoder.messageName() == Messages::WebPageProxy::ModelElementCreateRemotePreview::name()) {
        if (!(sharedPreferences && sharedPreferences->modelElementEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebPageProxy::ModelElementCreateRemotePreview>(connection, decoder, this, &WebPageProxy::modelElementCreateRemotePreview);
    }
    if (decoder.messageName() == Messages::WebPageProxy::ModelElementLoadRemotePreview::name()) {
        if (!(sharedPreferences && sharedPreferences->modelElementEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebPageProxy::ModelElementLoadRemotePreview>(connection, decoder, this, &WebPageProxy::modelElementLoadRemotePreview);
    }
    if (decoder.messageName() == Messages::WebPageProxy::ModelElementDestroyRemotePreview::name()) {
        if (!(sharedPreferences && sharedPreferences->modelElementEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::WebPageProxy::ModelElementDestroyRemotePreview>(connection, decoder, this, &WebPageProxy::modelElementDestroyRemotePreview);
    }
    if (decoder.messageName() == Messages::WebPageProxy::ModelElementSizeDidChange::name()) {
        if (!(sharedPreferences && sharedPreferences->modelElementEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebPageProxy::ModelElementSizeDidChange>(connection, decoder, this, &WebPageProxy::modelElementSizeDidChange);
    }
    if (decoder.messageName() == Messages::WebPageProxy::HandleMouseDownForModelElement::name()) {
        if (!(sharedPreferences && sharedPreferences->modelElementEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::WebPageProxy::HandleMouseDownForModelElement>(connection, decoder, this, &WebPageProxy::handleMouseDownForModelElement);
    }
    if (decoder.messageName() == Messages::WebPageProxy::HandleMouseMoveForModelElement::name()) {
        if (!(sharedPreferences && sharedPreferences->modelElementEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::WebPageProxy::HandleMouseMoveForModelElement>(connection, decoder, this, &WebPageProxy::handleMouseMoveForModelElement);
    }
    if (decoder.messageName() == Messages::WebPageProxy::HandleMouseUpForModelElement::name()) {
        if (!(sharedPreferences && sharedPreferences->modelElementEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::WebPageProxy::HandleMouseUpForModelElement>(connection, decoder, this, &WebPageProxy::handleMouseUpForModelElement);
    }
    if (decoder.messageName() == Messages::WebPageProxy::ModelInlinePreviewUUIDs::name()) {
        if (!(sharedPreferences && sharedPreferences->modelElementEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebPageProxy::ModelInlinePreviewUUIDs>(connection, decoder, this, &WebPageProxy::modelInlinePreviewUUIDs);
    }
#endif
#if ENABLE(ARKIT_INLINE_PREVIEW)
    if (decoder.messageName() == Messages::WebPageProxy::ModelElementGetCamera::name()) {
        if (!(sharedPreferences && sharedPreferences->modelElementEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebPageProxy::ModelElementGetCamera>(connection, decoder, this, &WebPageProxy::modelElementGetCamera);
    }
    if (decoder.messageName() == Messages::WebPageProxy::ModelElementSetCamera::name()) {
        if (!(sharedPreferences && sharedPreferences->modelElementEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebPageProxy::ModelElementSetCamera>(connection, decoder, this, &WebPageProxy::modelElementSetCamera);
    }
    if (decoder.messageName() == Messages::WebPageProxy::ModelElementIsPlayingAnimation::name()) {
        if (!(sharedPreferences && sharedPreferences->modelElementEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebPageProxy::ModelElementIsPlayingAnimation>(connection, decoder, this, &WebPageProxy::modelElementIsPlayingAnimation);
    }
    if (decoder.messageName() == Messages::WebPageProxy::ModelElementSetAnimationIsPlaying::name()) {
        if (!(sharedPreferences && sharedPreferences->modelElementEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebPageProxy::ModelElementSetAnimationIsPlaying>(connection, decoder, this, &WebPageProxy::modelElementSetAnimationIsPlaying);
    }
    if (decoder.messageName() == Messages::WebPageProxy::ModelElementIsLoopingAnimation::name()) {
        if (!(sharedPreferences && sharedPreferences->modelElementEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebPageProxy::ModelElementIsLoopingAnimation>(connection, decoder, this, &WebPageProxy::modelElementIsLoopingAnimation);
    }
    if (decoder.messageName() == Messages::WebPageProxy::ModelElementSetIsLoopingAnimation::name()) {
        if (!(sharedPreferences && sharedPreferences->modelElementEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebPageProxy::ModelElementSetIsLoopingAnimation>(connection, decoder, this, &WebPageProxy::modelElementSetIsLoopingAnimation);
    }
    if (decoder.messageName() == Messages::WebPageProxy::ModelElementAnimationDuration::name()) {
        if (!(sharedPreferences && sharedPreferences->modelElementEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebPageProxy::ModelElementAnimationDuration>(connection, decoder, this, &WebPageProxy::modelElementAnimationDuration);
    }
    if (decoder.messageName() == Messages::WebPageProxy::ModelElementAnimationCurrentTime::name()) {
        if (!(sharedPreferences && sharedPreferences->modelElementEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebPageProxy::ModelElementAnimationCurrentTime>(connection, decoder, this, &WebPageProxy::modelElementAnimationCurrentTime);
    }
    if (decoder.messageName() == Messages::WebPageProxy::ModelElementSetAnimationCurrentTime::name()) {
        if (!(sharedPreferences && sharedPreferences->modelElementEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebPageProxy::ModelElementSetAnimationCurrentTime>(connection, decoder, this, &WebPageProxy::modelElementSetAnimationCurrentTime);
    }
    if (decoder.messageName() == Messages::WebPageProxy::ModelElementHasAudio::name()) {
        if (!(sharedPreferences && sharedPreferences->modelElementEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebPageProxy::ModelElementHasAudio>(connection, decoder, this, &WebPageProxy::modelElementHasAudio);
    }
    if (decoder.messageName() == Messages::WebPageProxy::ModelElementIsMuted::name()) {
        if (!(sharedPreferences && sharedPreferences->modelElementEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebPageProxy::ModelElementIsMuted>(connection, decoder, this, &WebPageProxy::modelElementIsMuted);
    }
    if (decoder.messageName() == Messages::WebPageProxy::ModelElementSetIsMuted::name()) {
        if (!(sharedPreferences && sharedPreferences->modelElementEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebPageProxy::ModelElementSetIsMuted>(connection, decoder, this, &WebPageProxy::modelElementSetIsMuted);
    }
#endif
#if ENABLE(APPLE_PAY_AMS_UI)
    if (decoder.messageName() == Messages::WebPageProxy::StartApplePayAMSUISession::name()) {
        if (!(sharedPreferences && sharedPreferences->applePayEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebPageProxy::StartApplePayAMSUISession>(connection, decoder, this, &WebPageProxy::startApplePayAMSUISession);
    }
    if (decoder.messageName() == Messages::WebPageProxy::AbortApplePayAMSUISession::name()) {
        if (!(sharedPreferences && sharedPreferences->applePayEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::WebPageProxy::AbortApplePayAMSUISession>(connection, decoder, this, &WebPageProxy::abortApplePayAMSUISession);
    }
#endif
#if USE(SYSTEM_PREVIEW)
    if (decoder.messageName() == Messages::WebPageProxy::BeginSystemPreview::name()) {
        if (!(sharedPreferences && sharedPreferences->systemPreviewEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebPageProxy::BeginSystemPreview>(connection, decoder, this, &WebPageProxy::beginSystemPreview);
    }
#endif
    if (decoder.messageName() == Messages::WebPageProxy::DidCreateSleepDisabler::name())
        return IPC::handleMessage<Messages::WebPageProxy::DidCreateSleepDisabler>(connection, decoder, this, &WebPageProxy::didCreateSleepDisabler);
    if (decoder.messageName() == Messages::WebPageProxy::DidDestroySleepDisabler::name())
        return IPC::handleMessage<Messages::WebPageProxy::DidDestroySleepDisabler>(connection, decoder, this, &WebPageProxy::didDestroySleepDisabler);
    if (decoder.messageName() == Messages::WebPageProxy::RequestCookieConsent::name()) {
        if (!(sharedPreferences && sharedPreferences->cookieConsentAPIEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebPageProxy::RequestCookieConsent>(connection, decoder, this, &WebPageProxy::requestCookieConsent);
    }
#if ENABLE(WINDOW_PROXY_PROPERTY_ACCESS_NOTIFICATION)
    if (decoder.messageName() == Messages::WebPageProxy::DidAccessWindowProxyPropertyViaOpenerForFrame::name())
        return IPC::handleMessage<Messages::WebPageProxy::DidAccessWindowProxyPropertyViaOpenerForFrame>(connection, decoder, this, &WebPageProxy::didAccessWindowProxyPropertyViaOpenerForFrame);
#endif
    if (decoder.messageName() == Messages::WebPageProxy::DidApplyLinkDecorationFiltering::name())
        return IPC::handleMessage<Messages::WebPageProxy::DidApplyLinkDecorationFiltering>(connection, decoder, this, &WebPageProxy::didApplyLinkDecorationFiltering);
    if (decoder.messageName() == Messages::WebPageProxy::BroadcastProcessSyncData::name()) {
        if (!(sharedPreferences && sharedPreferences->siteIsolationEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::WebPageProxy::BroadcastProcessSyncData>(connection, decoder, this, &WebPageProxy::broadcastProcessSyncData);
    }
    if (decoder.messageName() == Messages::WebPageProxy::BroadcastTopDocumentSyncData::name()) {
        if (!(sharedPreferences && sharedPreferences->siteIsolationEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::WebPageProxy::BroadcastTopDocumentSyncData>(connection, decoder, this, &WebPageProxy::broadcastTopDocumentSyncData);
    }
    if (decoder.messageName() == Messages::WebPageProxy::DispatchLoadEventToFrameOwnerElement::name()) {
        if (!(sharedPreferences && sharedPreferences->siteIsolationEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::WebPageProxy::DispatchLoadEventToFrameOwnerElement>(connection, decoder, this, &WebPageProxy::dispatchLoadEventToFrameOwnerElement);
    }
    if (decoder.messageName() == Messages::WebPageProxy::FocusRemoteFrame::name()) {
        if (!(sharedPreferences && sharedPreferences->siteIsolationEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::WebPageProxy::FocusRemoteFrame>(connection, decoder, this, &WebPageProxy::focusRemoteFrame);
    }
    if (decoder.messageName() == Messages::WebPageProxy::PostMessageToRemote::name()) {
        if (!(sharedPreferences && sharedPreferences->siteIsolationEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::WebPageProxy::PostMessageToRemote>(connection, decoder, this, &WebPageProxy::postMessageToRemote);
    }
    if (decoder.messageName() == Messages::WebPageProxy::AddMessageToConsoleForTesting::name())
        return IPC::handleMessage<Messages::WebPageProxy::AddMessageToConsoleForTesting>(connection, decoder, this, &WebPageProxy::addMessageToConsoleForTesting);
    if (decoder.messageName() == Messages::WebPageProxy::UpdateRemoteFrameAccessibilityOffset::name()) {
        if (!(sharedPreferences && sharedPreferences->siteIsolationEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::WebPageProxy::UpdateRemoteFrameAccessibilityOffset>(connection, decoder, this, &WebPageProxy::updateRemoteFrameAccessibilityOffset);
    }
    if (decoder.messageName() == Messages::WebPageProxy::DocumentURLForConsoleLog::name()) {
        if (!(sharedPreferences && sharedPreferences->siteIsolationEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessageAsync<Messages::WebPageProxy::DocumentURLForConsoleLog>(connection, decoder, this, &WebPageProxy::documentURLForConsoleLog);
    }
    if (decoder.messageName() == Messages::WebPageProxy::NowPlayingMetadataChanged::name())
        return IPC::handleMessage<Messages::WebPageProxy::NowPlayingMetadataChanged>(connection, decoder, this, &WebPageProxy::nowPlayingMetadataChanged);
    if (decoder.messageName() == Messages::WebPageProxy::DidAdjustVisibilityWithSelectors::name())
        return IPC::handleMessage<Messages::WebPageProxy::DidAdjustVisibilityWithSelectors>(connection, decoder, this, &WebPageProxy::didAdjustVisibilityWithSelectors);
    if (decoder.messageName() == Messages::WebPageProxy::FrameNameChanged::name()) {
        if (!(sharedPreferences && sharedPreferences->siteIsolationEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::WebPageProxy::FrameNameChanged>(connection, decoder, this, &WebPageProxy::frameNameChanged);
    }
#if ENABLE(GAMEPAD)
    if (decoder.messageName() == Messages::WebPageProxy::GamepadsRecentlyAccessed::name()) {
        if (!(sharedPreferences && sharedPreferences->gamepadsEnabled)) {
            RELEASE_LOG_ERROR(IPC, "Message %s received by a disabled message endpoint", IPC::description(decoder.messageName()).characters());
            return decoder.markInvalid();
        }
        return IPC::handleMessage<Messages::WebPageProxy::GamepadsRecentlyAccessed>(connection, decoder, this, &WebPageProxy::gamepadsRecentlyAccessed);
    }
#endif
    if (decoder.messageName() == Messages::WebPageProxy::HasActiveNowPlayingSessionChanged::name())
        return IPC::handleMessage<Messages::WebPageProxy::HasActiveNowPlayingSessionChanged>(connection, decoder, this, &WebPageProxy::hasActiveNowPlayingSessionChanged);
    if (decoder.messageName() == Messages::WebPageProxy::SetAllowsLayoutViewportHeightExpansion::name())
        return IPC::handleMessage<Messages::WebPageProxy::SetAllowsLayoutViewportHeightExpansion>(connection, decoder, this, &WebPageProxy::setAllowsLayoutViewportHeightExpansion);
    UNUSED_PARAM(connection);
    RELEASE_LOG_ERROR(IPC, "Unhandled message %s to %" PRIu64, IPC::description(decoder.messageName()).characters(), decoder.destinationID());
    decoder.markInvalid();
}

bool WebPageProxy::didReceiveSyncMessage(IPC::Connection& connection, IPC::Decoder& decoder, UniqueRef<IPC::Encoder>& replyEncoder)
{
    ASSERT(!isInAuxiliaryProcess());
    auto sharedPreferences = sharedPreferencesForWebProcess(connection);
    UNUSED_VARIABLE(sharedPreferences);
    Ref protectedThis { *this };
    if (decoder.messageName() == Messages::WebPageProxy::CreateNewPage::name())
        return IPC::handleMessageSynchronous<Messages::WebPageProxy::CreateNewPage>(connection, decoder, replyEncoder, this, &WebPageProxy::createNewPage);
    if (decoder.messageName() == Messages::WebPageProxy::RunJavaScriptAlert::name())
        return IPC::handleMessageSynchronous<Messages::WebPageProxy::RunJavaScriptAlert>(connection, decoder, replyEncoder, this, &WebPageProxy::runJavaScriptAlert);
    if (decoder.messageName() == Messages::WebPageProxy::RunJavaScriptConfirm::name())
        return IPC::handleMessageSynchronous<Messages::WebPageProxy::RunJavaScriptConfirm>(connection, decoder, replyEncoder, this, &WebPageProxy::runJavaScriptConfirm);
    if (decoder.messageName() == Messages::WebPageProxy::RunJavaScriptPrompt::name())
        return IPC::handleMessageSynchronous<Messages::WebPageProxy::RunJavaScriptPrompt>(connection, decoder, replyEncoder, this, &WebPageProxy::runJavaScriptPrompt);
    if (decoder.messageName() == Messages::WebPageProxy::GetToolbarsAreVisible::name())
        return IPC::handleMessageSynchronous<Messages::WebPageProxy::GetToolbarsAreVisible>(connection, decoder, replyEncoder, this, &WebPageProxy::getToolbarsAreVisible);
    if (decoder.messageName() == Messages::WebPageProxy::GetMenuBarIsVisible::name())
        return IPC::handleMessageSynchronous<Messages::WebPageProxy::GetMenuBarIsVisible>(connection, decoder, replyEncoder, this, &WebPageProxy::getMenuBarIsVisible);
    if (decoder.messageName() == Messages::WebPageProxy::GetStatusBarIsVisible::name())
        return IPC::handleMessageSynchronous<Messages::WebPageProxy::GetStatusBarIsVisible>(connection, decoder, replyEncoder, this, &WebPageProxy::getStatusBarIsVisible);
    if (decoder.messageName() == Messages::WebPageProxy::GetWindowFrame::name())
        return IPC::handleMessageSynchronous<Messages::WebPageProxy::GetWindowFrame>(connection, decoder, replyEncoder, this, &WebPageProxy::getWindowFrame);
    if (decoder.messageName() == Messages::WebPageProxy::ScreenToRootView::name())
        return IPC::handleMessageSynchronous<Messages::WebPageProxy::ScreenToRootView>(connection, decoder, replyEncoder, this, &WebPageProxy::screenToRootView);
    if (decoder.messageName() == Messages::WebPageProxy::RootViewPointToScreen::name())
        return IPC::handleMessageSynchronous<Messages::WebPageProxy::RootViewPointToScreen>(connection, decoder, replyEncoder, this, &WebPageProxy::rootViewPointToScreen);
    if (decoder.messageName() == Messages::WebPageProxy::RootViewRectToScreen::name())
        return IPC::handleMessageSynchronous<Messages::WebPageProxy::RootViewRectToScreen>(connection, decoder, replyEncoder, this, &WebPageProxy::rootViewRectToScreen);
    if (decoder.messageName() == Messages::WebPageProxy::AccessibilityScreenToRootView::name())
        return IPC::handleMessageSynchronous<Messages::WebPageProxy::AccessibilityScreenToRootView>(connection, decoder, replyEncoder, this, &WebPageProxy::accessibilityScreenToRootView);
    if (decoder.messageName() == Messages::WebPageProxy::RootViewToAccessibilityScreen::name())
        return IPC::handleMessageSynchronous<Messages::WebPageProxy::RootViewToAccessibilityScreen>(connection, decoder, replyEncoder, this, &WebPageProxy::rootViewToAccessibilityScreen);
    if (decoder.messageName() == Messages::WebPageProxy::RunBeforeUnloadConfirmPanel::name())
        return IPC::handleMessageSynchronous<Messages::WebPageProxy::RunBeforeUnloadConfirmPanel>(connection, decoder, replyEncoder, this, &WebPageProxy::runBeforeUnloadConfirmPanel);
    if (decoder.messageName() == Messages::WebPageProxy::PrintFrame::name())
        return IPC::handleMessageSynchronous<Messages::WebPageProxy::PrintFrame>(connection, decoder, replyEncoder, this, &WebPageProxy::printFrame);
    if (decoder.messageName() == Messages::WebPageProxy::DecidePolicyForNavigationActionSync::name())
        return IPC::handleMessageSynchronous<Messages::WebPageProxy::DecidePolicyForNavigationActionSync>(connection, decoder, replyEncoder, this, &WebPageProxy::decidePolicyForNavigationActionSync);
#if PLATFORM(IOS_FAMILY)
    if (decoder.messageName() == Messages::WebPageProxy::InterpretKeyEvent::name())
        return IPC::handleMessageSynchronous<Messages::WebPageProxy::InterpretKeyEvent>(connection, decoder, replyEncoder, this, &WebPageProxy::interpretKeyEvent);
#endif
    if (decoder.messageName() == Messages::WebPageProxy::BackForwardGoToItem::name())
        return IPC::handleMessageSynchronous<Messages::WebPageProxy::BackForwardGoToItem>(connection, decoder, replyEncoder, this, &WebPageProxy::backForwardGoToItem);
    if (decoder.messageName() == Messages::WebPageProxy::BackForwardItemAtIndex::name())
        return IPC::handleMessageSynchronous<Messages::WebPageProxy::BackForwardItemAtIndex>(connection, decoder, replyEncoder, this, &WebPageProxy::backForwardItemAtIndex);
    if (decoder.messageName() == Messages::WebPageProxy::BackForwardListContainsItem::name())
        return IPC::handleMessageSynchronous<Messages::WebPageProxy::BackForwardListContainsItem>(connection, decoder, replyEncoder, this, &WebPageProxy::backForwardListContainsItem);
    if (decoder.messageName() == Messages::WebPageProxy::BackForwardListCounts::name())
        return IPC::handleMessageSynchronous<Messages::WebPageProxy::BackForwardListCounts>(connection, decoder, replyEncoder, this, &WebPageProxy::backForwardListCounts);
    if (decoder.messageName() == Messages::WebPageProxy::ShouldGoToBackForwardListItemSync::name())
        return IPC::handleMessageSynchronous<Messages::WebPageProxy::ShouldGoToBackForwardListItemSync>(connection, decoder, replyEncoder, this, &WebPageProxy::shouldGoToBackForwardListItemSync);
    if (decoder.messageName() == Messages::WebPageProxy::CanUndoRedo::name())
        return IPC::handleMessageSynchronous<Messages::WebPageProxy::CanUndoRedo>(connection, decoder, replyEncoder, this, &WebPageProxy::canUndoRedo);
    if (decoder.messageName() == Messages::WebPageProxy::ExecuteUndoRedo::name())
        return IPC::handleMessageSynchronous<Messages::WebPageProxy::ExecuteUndoRedo>(connection, decoder, replyEncoder, this, &WebPageProxy::executeUndoRedo);
    if (decoder.messageName() == Messages::WebPageProxy::RequestDOMPasteAccess::name())
        return IPC::handleMessageSynchronous<Messages::WebPageProxy::RequestDOMPasteAccess>(connection, decoder, replyEncoder, this, &WebPageProxy::requestDOMPasteAccess);
    if (decoder.messageName() == Messages::WebPageProxy::ExceededDatabaseQuota::name())
        return IPC::handleMessageSynchronous<Messages::WebPageProxy::ExceededDatabaseQuota>(connection, decoder, replyEncoder, this, &WebPageProxy::exceededDatabaseQuota);
#if USE(UNIFIED_TEXT_CHECKING)
    if (decoder.messageName() == Messages::WebPageProxy::CheckTextOfParagraph::name())
        return IPC::handleMessageSynchronous<Messages::WebPageProxy::CheckTextOfParagraph>(connection, decoder, replyEncoder, this, &WebPageProxy::checkTextOfParagraph);
#endif
    if (decoder.messageName() == Messages::WebPageProxy::CheckSpellingOfString::name())
        return IPC::handleMessageSynchronous<Messages::WebPageProxy::CheckSpellingOfString>(connection, decoder, replyEncoder, this, &WebPageProxy::checkSpellingOfString);
    if (decoder.messageName() == Messages::WebPageProxy::CheckGrammarOfString::name())
        return IPC::handleMessageSynchronous<Messages::WebPageProxy::CheckGrammarOfString>(connection, decoder, replyEncoder, this, &WebPageProxy::checkGrammarOfString);
    if (decoder.messageName() == Messages::WebPageProxy::SpellingUIIsShowing::name())
        return IPC::handleMessageSynchronous<Messages::WebPageProxy::SpellingUIIsShowing>(connection, decoder, replyEncoder, this, &WebPageProxy::spellingUIIsShowing);
    if (decoder.messageName() == Messages::WebPageProxy::GetGuessesForWord::name())
        return IPC::handleMessageSynchronous<Messages::WebPageProxy::GetGuessesForWord>(connection, decoder, replyEncoder, this, &WebPageProxy::getGuessesForWord);
#if PLATFORM(COCOA)
    if (decoder.messageName() == Messages::WebPageProxy::ExecuteSavedCommandBySelector::name())
        return IPC::handleMessageSynchronous<Messages::WebPageProxy::ExecuteSavedCommandBySelector>(connection, decoder, replyEncoder, this, &WebPageProxy::executeSavedCommandBySelector);
    if (decoder.messageName() == Messages::WebPageProxy::GetIsSpeaking::name())
        return IPC::handleMessageSynchronous<Messages::WebPageProxy::GetIsSpeaking>(connection, decoder, replyEncoder, this, &WebPageProxy::getIsSpeaking);
#endif
#if USE(APPKIT)
    if (decoder.messageName() == Messages::WebPageProxy::SubstitutionsPanelIsShowing::name())
        return IPC::handleMessageSynchronous<Messages::WebPageProxy::SubstitutionsPanelIsShowing>(connection, decoder, replyEncoder, this, &WebPageProxy::substitutionsPanelIsShowing);
#endif
#if PLATFORM(MAC)
    if (decoder.messageName() == Messages::WebPageProxy::DismissCorrectionPanelSoon::name())
        return IPC::handleMessageSynchronous<Messages::WebPageProxy::DismissCorrectionPanelSoon>(connection, decoder, replyEncoder, this, &WebPageProxy::dismissCorrectionPanelSoon);
#endif
#if USE(DICTATION_ALTERNATIVES)
    if (decoder.messageName() == Messages::WebPageProxy::DictationAlternatives::name())
        return IPC::handleMessageSynchronous<Messages::WebPageProxy::DictationAlternatives>(connection, decoder, replyEncoder, this, &WebPageProxy::dictationAlternatives);
#endif
    if (decoder.messageName() == Messages::WebPageProxy::LoadRecentSearches::name())
        return IPC::handleMessageSynchronous<Messages::WebPageProxy::LoadRecentSearches>(connection, decoder, replyEncoder, this, &WebPageProxy::loadRecentSearches);
    if (decoder.messageName() == Messages::WebPageProxy::SerializeAndWrapCryptoKey::name())
        return IPC::handleMessageSynchronous<Messages::WebPageProxy::SerializeAndWrapCryptoKey>(connection, decoder, replyEncoder, this, &WebPageProxy::serializeAndWrapCryptoKey);
    if (decoder.messageName() == Messages::WebPageProxy::UnwrapCryptoKey::name())
        return IPC::handleMessageSynchronous<Messages::WebPageProxy::UnwrapCryptoKey>(connection, decoder, replyEncoder, this, &WebPageProxy::unwrapCryptoKey);
    if (decoder.messageName() == Messages::WebPageProxy::HandleSynchronousMessage::name())
        return IPC::handleMessageSynchronous<Messages::WebPageProxy::HandleSynchronousMessage>(connection, decoder, replyEncoder, this, &WebPageProxy::handleSynchronousMessage);
    if (decoder.messageName() == Messages::WebPageProxy::LoadSynchronousURLSchemeTask::name())
        return IPC::handleMessageSynchronous<Messages::WebPageProxy::LoadSynchronousURLSchemeTask>(connection, decoder, replyEncoder, this, &WebPageProxy::loadSynchronousURLSchemeTask);
#if ENABLE(ATTACHMENT_ELEMENT)
    if (decoder.messageName() == Messages::WebPageProxy::SerializedAttachmentDataForIdentifiers::name() && sharedPreferences && sharedPreferences->attachmentElementEnabled)
        return IPC::handleMessageSynchronous<Messages::WebPageProxy::SerializedAttachmentDataForIdentifiers>(connection, decoder, replyEncoder, this, &WebPageProxy::serializedAttachmentDataForIdentifiers);
#endif
#if ENABLE(SPEECH_SYNTHESIS)
    if (decoder.messageName() == Messages::WebPageProxy::SpeechSynthesisVoiceList::name() && sharedPreferences && sharedPreferences->speechSynthesisAPIEnabled)
        return IPC::handleMessageSynchronous<Messages::WebPageProxy::SpeechSynthesisVoiceList>(connection, decoder, replyEncoder, this, &WebPageProxy::speechSynthesisVoiceList);
#endif
    if (decoder.messageName() == Messages::WebPageProxy::RenderTreeAsTextForTesting::name() && sharedPreferences && sharedPreferences->siteIsolationEnabled)
        return IPC::handleMessageSynchronous<Messages::WebPageProxy::RenderTreeAsTextForTesting>(connection, decoder, replyEncoder, this, &WebPageProxy::renderTreeAsTextForTesting);
    if (decoder.messageName() == Messages::WebPageProxy::FrameTextForTesting::name() && sharedPreferences && sharedPreferences->siteIsolationEnabled)
        return IPC::handleMessageSynchronous<Messages::WebPageProxy::FrameTextForTesting>(connection, decoder, replyEncoder, this, &WebPageProxy::frameTextForTesting);
    if (decoder.messageName() == Messages::WebPageProxy::LayerTreeAsTextForTesting::name() && sharedPreferences && sharedPreferences->siteIsolationEnabled)
        return IPC::handleMessageSynchronous<Messages::WebPageProxy::LayerTreeAsTextForTesting>(connection, decoder, replyEncoder, this, &WebPageProxy::layerTreeAsTextForTesting);
    if (decoder.messageName() == Messages::WebPageProxy::BindRemoteAccessibilityFrames::name() && sharedPreferences && sharedPreferences->siteIsolationEnabled)
        return IPC::handleMessageSynchronous<Messages::WebPageProxy::BindRemoteAccessibilityFrames>(connection, decoder, replyEncoder, this, &WebPageProxy::bindRemoteAccessibilityFrames);
    UNUSED_PARAM(connection);
    UNUSED_PARAM(replyEncoder);
    RELEASE_LOG_ERROR(IPC, "Unhandled synchronous message %s to %" PRIu64, description(decoder.messageName()).characters(), decoder.destinationID());
    decoder.markInvalid();
    return false;
}

} // namespace WebKit

#if ENABLE(IPC_TESTING_API)

namespace IPC {

template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_CreateNewPage>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::CreateNewPage::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_CreateNewPage>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::CreateNewPage::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_ShowPage>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ShowPage::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_ClosePage>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ClosePage::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_RunJavaScriptAlert>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::RunJavaScriptAlert::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_RunJavaScriptAlert>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::RunJavaScriptAlert::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_RunJavaScriptConfirm>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::RunJavaScriptConfirm::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_RunJavaScriptConfirm>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::RunJavaScriptConfirm::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_RunJavaScriptPrompt>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::RunJavaScriptPrompt::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_RunJavaScriptPrompt>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::RunJavaScriptPrompt::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_MouseDidMoveOverElement>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::MouseDidMoveOverElement::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_DidReceiveEventIPC>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DidReceiveEventIPC::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_SetCursor>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::SetCursor::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_SetCursorHiddenUntilMouseMoves>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::SetCursorHiddenUntilMouseMoves::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_SetFocus>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::SetFocus::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_TakeFocus>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::TakeFocus::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_FocusFromServiceWorker>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::FocusFromServiceWorker::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_FocusFromServiceWorker>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::FocusFromServiceWorker::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_FocusedFrameChanged>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::FocusedFrameChanged::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_SetRenderTreeSize>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::SetRenderTreeSize::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_SetToolbarsAreVisible>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::SetToolbarsAreVisible::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_GetToolbarsAreVisible>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::GetToolbarsAreVisible::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_GetToolbarsAreVisible>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::GetToolbarsAreVisible::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_SetMenuBarIsVisible>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::SetMenuBarIsVisible::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_GetMenuBarIsVisible>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::GetMenuBarIsVisible::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_GetMenuBarIsVisible>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::GetMenuBarIsVisible::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_SetStatusBarIsVisible>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::SetStatusBarIsVisible::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_GetStatusBarIsVisible>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::GetStatusBarIsVisible::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_GetStatusBarIsVisible>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::GetStatusBarIsVisible::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_SetIsResizable>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::SetIsResizable::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_SetWindowFrame>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::SetWindowFrame::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_GetWindowFrame>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::GetWindowFrame::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_GetWindowFrame>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::GetWindowFrame::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_ScreenToRootView>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ScreenToRootView::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_ScreenToRootView>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ScreenToRootView::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_RootViewPointToScreen>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::RootViewPointToScreen::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_RootViewPointToScreen>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::RootViewPointToScreen::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_RootViewRectToScreen>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::RootViewRectToScreen::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_RootViewRectToScreen>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::RootViewRectToScreen::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_AccessibilityScreenToRootView>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::AccessibilityScreenToRootView::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_AccessibilityScreenToRootView>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::AccessibilityScreenToRootView::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_RootViewToAccessibilityScreen>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::RootViewToAccessibilityScreen::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_RootViewToAccessibilityScreen>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::RootViewToAccessibilityScreen::ReplyArguments>(globalObject, decoder);
}
#if PLATFORM(IOS_FAMILY)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_RelayAccessibilityNotification>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::RelayAccessibilityNotification::Arguments>(globalObject, decoder);
}
#endif
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_EnableAccessibilityForAllProcesses>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::EnableAccessibilityForAllProcesses::Arguments>(globalObject, decoder);
}
#if PLATFORM(COCOA) || PLATFORM(GTK)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_ShowValidationMessage>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ShowValidationMessage::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_HideValidationMessage>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::HideValidationMessage::Arguments>(globalObject, decoder);
}
#endif
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_RunBeforeUnloadConfirmPanel>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::RunBeforeUnloadConfirmPanel::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_RunBeforeUnloadConfirmPanel>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::RunBeforeUnloadConfirmPanel::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_PageDidScroll>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::PageDidScroll::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_SetHasActiveAnimatedScrolls>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::SetHasActiveAnimatedScrolls::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_RunOpenPanel>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::RunOpenPanel::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_ShowShareSheet>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ShowShareSheet::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_ShowShareSheet>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ShowShareSheet::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_ShowContactPicker>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ShowContactPicker::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_ShowContactPicker>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ShowContactPicker::ReplyArguments>(globalObject, decoder);
}
#if HAVE(DIGITAL_CREDENTIALS_UI)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_ShowDigitalCredentialsPicker>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ShowDigitalCredentialsPicker::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_ShowDigitalCredentialsPicker>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ShowDigitalCredentialsPicker::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_DismissDigitalCredentialsPicker>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DismissDigitalCredentialsPicker::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_DismissDigitalCredentialsPicker>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DismissDigitalCredentialsPicker::ReplyArguments>(globalObject, decoder);
}
#endif
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_PrintFrame>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::PrintFrame::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_PrintFrame>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::PrintFrame::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_RunModal>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::RunModal::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_NotifyScrollerThumbIsVisibleInRect>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::NotifyScrollerThumbIsVisibleInRect::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_RecommendedScrollbarStyleDidChange>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::RecommendedScrollbarStyleDidChange::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_DidChangeScrollbarsForMainFrame>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DidChangeScrollbarsForMainFrame::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_DidChangeScrollOffsetPinningForMainFrame>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DidChangeScrollOffsetPinningForMainFrame::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_DidChangePageCount>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DidChangePageCount::Arguments>(globalObject, decoder);
}
#if PLATFORM(MAC) || PLATFORM(WPE) || PLATFORM(GTK)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_ThemeColorChanged>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ThemeColorChanged::Arguments>(globalObject, decoder);
}
#endif
#if ENABLE(WEB_PAGE_SPATIAL_BACKDROP)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_SpatialBackdropSourceChanged>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::SpatialBackdropSourceChanged::Arguments>(globalObject, decoder);
}
#endif
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_PageExtendedBackgroundColorDidChange>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::PageExtendedBackgroundColorDidChange::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_SampledPageTopColorChanged>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::SampledPageTopColorChanged::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_SetCanShortCircuitHorizontalWheelEvents>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::SetCanShortCircuitHorizontalWheelEvents::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_DidChangeContentSize>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DidChangeContentSize::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_DidChangeIntrinsicContentSize>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DidChangeIntrinsicContentSize::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_ShowColorPicker>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ShowColorPicker::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_SetColorPickerColor>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::SetColorPickerColor::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_EndColorPicker>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::EndColorPicker::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_ShowDataListSuggestions>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ShowDataListSuggestions::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_HandleKeydownInDataList>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::HandleKeydownInDataList::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_EndDataListSuggestions>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::EndDataListSuggestions::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_ShowDateTimePicker>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ShowDateTimePicker::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_EndDateTimePicker>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::EndDateTimePicker::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_DecidePolicyForResponse>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DecidePolicyForResponse::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_DecidePolicyForResponse>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DecidePolicyForResponse::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_DecidePolicyForNavigationActionAsync>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DecidePolicyForNavigationActionAsync::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_DecidePolicyForNavigationActionAsync>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DecidePolicyForNavigationActionAsync::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_DecidePolicyForNavigationActionSync>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DecidePolicyForNavigationActionSync::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_DecidePolicyForNavigationActionSync>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DecidePolicyForNavigationActionSync::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_DecidePolicyForNewWindowAction>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DecidePolicyForNewWindowAction::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_DecidePolicyForNewWindowAction>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DecidePolicyForNewWindowAction::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_DidChangeProgress>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DidChangeProgress::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_DidFinishProgress>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DidFinishProgress::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_DidStartProgress>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DidStartProgress::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_SetNetworkRequestsInProgress>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::SetNetworkRequestsInProgress::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_StartNetworkRequestsForPageLoadTiming>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::StartNetworkRequestsForPageLoadTiming::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_EndNetworkRequestsForPageLoadTiming>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::EndNetworkRequestsForPageLoadTiming::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_DidCreateSubframe>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DidCreateSubframe::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_DidDestroyFrame>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DidDestroyFrame::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_DidStartProvisionalLoadForFrame>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DidStartProvisionalLoadForFrame::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_DidReceiveServerRedirectForProvisionalLoadForFrame>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DidReceiveServerRedirectForProvisionalLoadForFrame::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_WillPerformClientRedirectForFrame>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::WillPerformClientRedirectForFrame::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_DidCancelClientRedirectForFrame>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DidCancelClientRedirectForFrame::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_DidChangeProvisionalURLForFrame>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DidChangeProvisionalURLForFrame::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_DidFailProvisionalLoadForFrame>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DidFailProvisionalLoadForFrame::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_DidCommitLoadForFrame>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DidCommitLoadForFrame::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_DidFailLoadForFrame>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DidFailLoadForFrame::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_DidFinishDocumentLoadForFrame>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DidFinishDocumentLoadForFrame::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_DidFinishLoadForFrame>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DidFinishLoadForFrame::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_DidFirstLayoutForFrame>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DidFirstLayoutForFrame::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_DidFirstVisuallyNonEmptyLayoutForFrame>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DidFirstVisuallyNonEmptyLayoutForFrame::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_DidReachLayoutMilestone>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DidReachLayoutMilestone::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_DidReceiveTitleForFrame>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DidReceiveTitleForFrame::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_DidDisplayInsecureContentForFrame>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DidDisplayInsecureContentForFrame::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_DidRunInsecureContentForFrame>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DidRunInsecureContentForFrame::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_DidSameDocumentNavigationForFrame>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DidSameDocumentNavigationForFrame::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_DidSameDocumentNavigationForFrameViaJS>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DidSameDocumentNavigationForFrameViaJS::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_DidChangeMainDocument>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DidChangeMainDocument::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_DidExplicitOpenForFrame>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DidExplicitOpenForFrame::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_DidDestroyNavigation>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DidDestroyNavigation::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_UpdateSandboxFlags>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::UpdateSandboxFlags::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_UpdateOpener>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::UpdateOpener::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_UpdateScrollingMode>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::UpdateScrollingMode::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_ResolveAccessibilityHitTestForTesting>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ResolveAccessibilityHitTestForTesting::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_ResolveAccessibilityHitTestForTesting>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ResolveAccessibilityHitTestForTesting::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_MainFramePluginHandlesPageScaleGestureDidChange>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::MainFramePluginHandlesPageScaleGestureDidChange::Arguments>(globalObject, decoder);
}
#if PLATFORM(GTK) || PLATFORM(WPE)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_DidInitiateLoadForResource>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DidInitiateLoadForResource::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_DidSendRequestForResource>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DidSendRequestForResource::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_DidReceiveResponseForResource>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DidReceiveResponseForResource::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_DidFinishLoadForResource>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DidFinishLoadForResource::Arguments>(globalObject, decoder);
}
#endif
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_DidNavigateWithNavigationData>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DidNavigateWithNavigationData::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_DidPerformClientRedirect>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DidPerformClientRedirect::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_DidPerformServerRedirect>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DidPerformServerRedirect::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_DidUpdateHistoryTitle>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DidUpdateHistoryTitle::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_DidFinishLoadingDataForCustomContentProvider>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DidFinishLoadingDataForCustomContentProvider::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_WillSubmitForm>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::WillSubmitForm::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_WillSubmitForm>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::WillSubmitForm::ReplyArguments>(globalObject, decoder);
}
#if PLATFORM(IOS_FAMILY)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_InterpretKeyEvent>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::InterpretKeyEvent::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_InterpretKeyEvent>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::InterpretKeyEvent::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_DidReceivePositionInformation>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DidReceivePositionInformation::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_SaveImageToLibrary>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::SaveImageToLibrary::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_ShowPlaybackTargetPicker>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ShowPlaybackTargetPicker::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_CommitPotentialTapFailed>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::CommitPotentialTapFailed::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_DidNotHandleTapAsClick>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DidNotHandleTapAsClick::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_DidCompleteSyntheticClick>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DidCompleteSyntheticClick::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_DidHandleTapAsHover>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DidHandleTapAsHover::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_DisableDoubleTapGesturesDuringTapIfNecessary>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DisableDoubleTapGesturesDuringTapIfNecessary::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_HandleSmartMagnificationInformationForPotentialTap>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::HandleSmartMagnificationInformationForPotentialTap::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_IsPotentialTapInProgress>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::IsPotentialTapInProgress::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_IsPotentialTapInProgress>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::IsPotentialTapInProgress::ReplyArguments>(globalObject, decoder);
}
#endif
#if ENABLE(DATA_DETECTION)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_SetDataDetectionResult>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::SetDataDetectionResult::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_HandleClickForDataDetectionResult>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::HandleClickForDataDetectionResult::Arguments>(globalObject, decoder);
}
#endif
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_PageScaleFactorDidChange>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::PageScaleFactorDidChange::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_ViewScaleFactorDidChange>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ViewScaleFactorDidChange::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_PluginScaleFactorDidChange>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::PluginScaleFactorDidChange::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_PluginZoomFactorDidChange>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::PluginZoomFactorDidChange::Arguments>(globalObject, decoder);
}
#if PLATFORM(GTK) || PLATFORM(WPE)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_BindAccessibilityTree>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::BindAccessibilityTree::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_SetInputMethodState>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::SetInputMethodState::Arguments>(globalObject, decoder);
}
#endif
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_BackForwardAddItem>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::BackForwardAddItem::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_BackForwardSetChildItem>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::BackForwardSetChildItem::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_BackForwardClearChildren>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::BackForwardClearChildren::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_BackForwardUpdateItem>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::BackForwardUpdateItem::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_BackForwardGoToItem>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::BackForwardGoToItem::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_BackForwardGoToItem>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::BackForwardGoToItem::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_BackForwardItemAtIndex>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::BackForwardItemAtIndex::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_BackForwardItemAtIndex>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::BackForwardItemAtIndex::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_BackForwardListContainsItem>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::BackForwardListContainsItem::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_BackForwardListContainsItem>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::BackForwardListContainsItem::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_BackForwardListCounts>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::BackForwardListCounts::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_BackForwardListCounts>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::BackForwardListCounts::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_ShouldGoToBackForwardListItem>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ShouldGoToBackForwardListItem::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_ShouldGoToBackForwardListItem>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ShouldGoToBackForwardListItem::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_ShouldGoToBackForwardListItemSync>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ShouldGoToBackForwardListItemSync::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_ShouldGoToBackForwardListItemSync>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ShouldGoToBackForwardListItemSync::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_RegisterEditCommandForUndo>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::RegisterEditCommandForUndo::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_ClearAllEditCommands>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ClearAllEditCommands::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_RegisterInsertionUndoGrouping>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::RegisterInsertionUndoGrouping::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_CanUndoRedo>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::CanUndoRedo::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_CanUndoRedo>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::CanUndoRedo::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_ExecuteUndoRedo>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ExecuteUndoRedo::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_ExecuteUndoRedo>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ExecuteUndoRedo::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_LogDiagnosticMessageFromWebProcess>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::LogDiagnosticMessageFromWebProcess::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_LogDiagnosticMessageWithResultFromWebProcess>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::LogDiagnosticMessageWithResultFromWebProcess::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_LogDiagnosticMessageWithValueFromWebProcess>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::LogDiagnosticMessageWithValueFromWebProcess::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_LogDiagnosticMessageWithEnhancedPrivacyFromWebProcess>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::LogDiagnosticMessageWithEnhancedPrivacyFromWebProcess::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_LogDiagnosticMessageWithValueDictionaryFromWebProcess>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::LogDiagnosticMessageWithValueDictionaryFromWebProcess::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_LogDiagnosticMessageWithDomainFromWebProcess>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::LogDiagnosticMessageWithDomainFromWebProcess::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_LogScrollingEvent>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::LogScrollingEvent::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_EditorStateChanged>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::EditorStateChanged::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_CompositionWasCanceled>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::CompositionWasCanceled::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_SetHasFocusedElementWithUserInteraction>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::SetHasFocusedElementWithUserInteraction::Arguments>(globalObject, decoder);
}
#if ENABLE(IMAGE_ANALYSIS)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_RequestTextRecognition>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::RequestTextRecognition::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_RequestTextRecognition>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::RequestTextRecognition::ReplyArguments>(globalObject, decoder);
}
#endif
#if HAVE(TRANSLATION_UI_SERVICES) && ENABLE(CONTEXT_MENUS)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_HandleContextMenuTranslation>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::HandleContextMenuTranslation::Arguments>(globalObject, decoder);
}
#endif
#if ENABLE(WRITING_TOOLS)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_ProofreadingSessionShowDetailsForSuggestionWithIDRelativeToRect>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ProofreadingSessionShowDetailsForSuggestionWithIDRelativeToRect::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_ProofreadingSessionUpdateStateForSuggestionWithID>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ProofreadingSessionUpdateStateForSuggestionWithID::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_AddTextAnimationForAnimationID>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::AddTextAnimationForAnimationID::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_AddTextAnimationForAnimationIDWithCompletionHandler>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::AddTextAnimationForAnimationIDWithCompletionHandler::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_AddTextAnimationForAnimationIDWithCompletionHandler>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::AddTextAnimationForAnimationIDWithCompletionHandler::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_RemoveTextAnimationForAnimationID>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::RemoveTextAnimationForAnimationID::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_DidEndPartialIntelligenceTextAnimation>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DidEndPartialIntelligenceTextAnimation::Arguments>(globalObject, decoder);
}
#endif
#if ENABLE(MEDIA_CONTROLS_CONTEXT_MENUS) && USE(UICONTEXTMENU)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_ShowMediaControlsContextMenu>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ShowMediaControlsContextMenu::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_ShowMediaControlsContextMenu>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ShowMediaControlsContextMenu::ReplyArguments>(globalObject, decoder);
}
#endif
#if HAVE(TOUCH_BAR)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_SetIsTouchBarUpdateSuppressedForHiddenContentEditable>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::SetIsTouchBarUpdateSuppressedForHiddenContentEditable::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_SetIsNeverRichlyEditableForTouchBar>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::SetIsNeverRichlyEditableForTouchBar::Arguments>(globalObject, decoder);
}
#endif
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_RequestDOMPasteAccess>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::RequestDOMPasteAccess::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_RequestDOMPasteAccess>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::RequestDOMPasteAccess::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_SetTextIndicatorFromFrame>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::SetTextIndicatorFromFrame::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_UpdateTextIndicatorFromFrame>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::UpdateTextIndicatorFromFrame::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_ClearTextIndicator>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ClearTextIndicator::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_DidGetImageForFindMatch>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DidGetImageForFindMatch::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_ShowPopupMenuFromFrame>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ShowPopupMenuFromFrame::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_HidePopupMenu>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::HidePopupMenu::Arguments>(globalObject, decoder);
}
#if ENABLE(CONTEXT_MENUS)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_ShowContextMenuFromFrame>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ShowContextMenuFromFrame::Arguments>(globalObject, decoder);
}
#endif
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_DidFinishServiceWorkerPageRegistration>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DidFinishServiceWorkerPageRegistration::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_ExceededDatabaseQuota>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ExceededDatabaseQuota::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_ExceededDatabaseQuota>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ExceededDatabaseQuota::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_RequestGeolocationPermissionForFrame>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::RequestGeolocationPermissionForFrame::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_RevokeGeolocationAuthorizationToken>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::RevokeGeolocationAuthorizationToken::Arguments>(globalObject, decoder);
}
#if ENABLE(MEDIA_STREAM)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_RequestUserMediaPermissionForFrame>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::RequestUserMediaPermissionForFrame::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_EnumerateMediaDevicesForFrame>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::EnumerateMediaDevicesForFrame::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_EnumerateMediaDevicesForFrame>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::EnumerateMediaDevicesForFrame::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_BeginMonitoringCaptureDevices>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::BeginMonitoringCaptureDevices::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_ValidateCaptureStateUpdate>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ValidateCaptureStateUpdate::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_ValidateCaptureStateUpdate>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ValidateCaptureStateUpdate::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_SetShouldListenToVoiceActivity>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::SetShouldListenToVoiceActivity::Arguments>(globalObject, decoder);
}
#endif
#if ENABLE(ENCRYPTED_MEDIA)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_RequestMediaKeySystemPermissionForFrame>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::RequestMediaKeySystemPermissionForFrame::Arguments>(globalObject, decoder);
}
#endif
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_RequestNotificationPermission>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::RequestNotificationPermission::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_RequestNotificationPermission>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::RequestNotificationPermission::ReplyArguments>(globalObject, decoder);
}
#if USE(UNIFIED_TEXT_CHECKING)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_CheckTextOfParagraph>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::CheckTextOfParagraph::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_CheckTextOfParagraph>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::CheckTextOfParagraph::ReplyArguments>(globalObject, decoder);
}
#endif
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_CheckSpellingOfString>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::CheckSpellingOfString::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_CheckSpellingOfString>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::CheckSpellingOfString::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_CheckGrammarOfString>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::CheckGrammarOfString::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_CheckGrammarOfString>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::CheckGrammarOfString::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_SpellingUIIsShowing>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::SpellingUIIsShowing::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_SpellingUIIsShowing>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::SpellingUIIsShowing::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_UpdateSpellingUIWithMisspelledWord>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::UpdateSpellingUIWithMisspelledWord::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_UpdateSpellingUIWithGrammarString>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::UpdateSpellingUIWithGrammarString::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_GetGuessesForWord>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::GetGuessesForWord::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_GetGuessesForWord>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::GetGuessesForWord::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_LearnWord>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::LearnWord::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_IgnoreWord>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::IgnoreWord::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_RequestCheckingOfString>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::RequestCheckingOfString::Arguments>(globalObject, decoder);
}
#if PLATFORM(COCOA) && ENABLE(DRAG_SUPPORT)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_StartDrag>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::StartDrag::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_SetPromisedDataForImage>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::SetPromisedDataForImage::Arguments>(globalObject, decoder);
}
#endif
#if (PLATFORM(GTK) || PLATFORM(WPE)) && ENABLE(DRAG_SUPPORT)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_StartDrag>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::StartDrag::Arguments>(globalObject, decoder);
}
#endif
#if PLATFORM(IOS_FAMILY) && ENABLE(DRAG_SUPPORT)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_WillReceiveEditDragSnapshot>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::WillReceiveEditDragSnapshot::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_DidReceiveEditDragSnapshot>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DidReceiveEditDragSnapshot::Arguments>(globalObject, decoder);
}
#endif
#if ENABLE(MODEL_PROCESS)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_DidReceiveInteractiveModelElement>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DidReceiveInteractiveModelElement::Arguments>(globalObject, decoder);
}
#endif
#if PLATFORM(COCOA)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_DidPerformDictionaryLookup>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DidPerformDictionaryLookup::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_ExecuteSavedCommandBySelector>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ExecuteSavedCommandBySelector::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_ExecuteSavedCommandBySelector>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ExecuteSavedCommandBySelector::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_RegisterWebProcessAccessibilityToken>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::RegisterWebProcessAccessibilityToken::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_GetIsSpeaking>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::GetIsSpeaking::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_GetIsSpeaking>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::GetIsSpeaking::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_MakeFirstResponder>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::MakeFirstResponder::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_AssistiveTechnologyMakeFirstResponder>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::AssistiveTechnologyMakeFirstResponder::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_SearchTheWeb>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::SearchTheWeb::Arguments>(globalObject, decoder);
}
#endif
#if USE(APPKIT)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_SubstitutionsPanelIsShowing>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::SubstitutionsPanelIsShowing::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_SubstitutionsPanelIsShowing>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::SubstitutionsPanelIsShowing::ReplyArguments>(globalObject, decoder);
}
#endif
#if USE(AUTOMATIC_TEXT_REPLACEMENT)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_toggleSmartInsertDelete>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::toggleSmartInsertDelete::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_toggleAutomaticQuoteSubstitution>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::toggleAutomaticQuoteSubstitution::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_toggleAutomaticLinkDetection>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::toggleAutomaticLinkDetection::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_toggleAutomaticDashSubstitution>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::toggleAutomaticDashSubstitution::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_toggleAutomaticTextReplacement>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::toggleAutomaticTextReplacement::Arguments>(globalObject, decoder);
}
#endif
#if PLATFORM(MAC)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_ShowCorrectionPanel>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ShowCorrectionPanel::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_DismissCorrectionPanel>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DismissCorrectionPanel::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_DismissCorrectionPanelSoon>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DismissCorrectionPanelSoon::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_DismissCorrectionPanelSoon>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DismissCorrectionPanelSoon::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_RecordAutocorrectionResponse>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::RecordAutocorrectionResponse::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_SetEditableElementIsFocused>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::SetEditableElementIsFocused::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_HandleAcceptsFirstMouse>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::HandleAcceptsFirstMouse::Arguments>(globalObject, decoder);
}
#endif
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_DidUpdateRenderingAfterCommittingLoad>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DidUpdateRenderingAfterCommittingLoad::Arguments>(globalObject, decoder);
}
#if USE(DICTATION_ALTERNATIVES)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_ShowDictationAlternativeUI>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ShowDictationAlternativeUI::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_RemoveDictationAlternatives>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::RemoveDictationAlternatives::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_DictationAlternatives>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DictationAlternatives::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_DictationAlternatives>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DictationAlternatives::ReplyArguments>(globalObject, decoder);
}
#endif
#if ENABLE(IMAGE_ANALYSIS) && ENABLE(VIDEO)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_BeginTextRecognitionForVideoInElementFullScreen>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::BeginTextRecognitionForVideoInElementFullScreen::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_CancelTextRecognitionForVideoInElementFullScreen>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::CancelTextRecognitionForVideoInElementFullScreen::Arguments>(globalObject, decoder);
}
#endif
#if PLATFORM(IOS_FAMILY)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_CouldNotRestorePageState>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::CouldNotRestorePageState::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_RestorePageState>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::RestorePageState::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_RestorePageCenterAndScale>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::RestorePageCenterAndScale::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_DidGetTapHighlightGeometries>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DidGetTapHighlightGeometries::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_ElementDidFocus>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ElementDidFocus::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_ElementDidBlur>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ElementDidBlur::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_UpdateInputContextAfterBlurringAndRefocusingElement>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::UpdateInputContextAfterBlurringAndRefocusingElement::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_DidProgrammaticallyClearFocusedElement>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DidProgrammaticallyClearFocusedElement::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_UpdateFocusedElementInformation>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::UpdateFocusedElementInformation::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_FocusedElementDidChangeInputMode>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::FocusedElementDidChangeInputMode::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_ScrollingNodeScrollWillStartScroll>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ScrollingNodeScrollWillStartScroll::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_ScrollingNodeScrollDidEndScroll>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ScrollingNodeScrollDidEndScroll::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_ShowInspectorHighlight>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ShowInspectorHighlight::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_HideInspectorHighlight>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::HideInspectorHighlight::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_ShowInspectorIndication>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ShowInspectorIndication::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_HideInspectorIndication>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::HideInspectorIndication::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_EnableInspectorNodeSearch>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::EnableInspectorNodeSearch::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_DisableInspectorNodeSearch>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DisableInspectorNodeSearch::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_UpdateStringForFind>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::UpdateStringForFind::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_HandleAutocorrectionContext>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::HandleAutocorrectionContext::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_ShowDataDetectorsUIForPositionInformation>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ShowDataDetectorsUIForPositionInformation::Arguments>(globalObject, decoder);
}
#endif
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_DidChangeInspectorFrontendCount>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DidChangeInspectorFrontendCount::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_CreateInspectorTarget>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::CreateInspectorTarget::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_DestroyInspectorTarget>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DestroyInspectorTarget::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_SendMessageToInspectorFrontend>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::SendMessageToInspectorFrontend::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_SaveRecentSearches>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::SaveRecentSearches::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_LoadRecentSearches>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::LoadRecentSearches::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_LoadRecentSearches>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::LoadRecentSearches::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_DidUpdateActivityState>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DidUpdateActivityState::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_SerializeAndWrapCryptoKey>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::SerializeAndWrapCryptoKey::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_SerializeAndWrapCryptoKey>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::SerializeAndWrapCryptoKey::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_UnwrapCryptoKey>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::UnwrapCryptoKey::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_UnwrapCryptoKey>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::UnwrapCryptoKey::ReplyArguments>(globalObject, decoder);
}
#if (ENABLE(TELEPHONE_NUMBER_DETECTION) && PLATFORM(MAC))
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_ShowTelephoneNumberMenu>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ShowTelephoneNumberMenu::Arguments>(globalObject, decoder);
}
#endif
#if USE(QUICK_LOOK)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_DidStartLoadForQuickLookDocumentInMainFrame>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DidStartLoadForQuickLookDocumentInMainFrame::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_DidFinishLoadForQuickLookDocumentInMainFrame>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DidFinishLoadForQuickLookDocumentInMainFrame::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_RequestPasswordForQuickLookDocumentInMainFrame>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::RequestPasswordForQuickLookDocumentInMainFrame::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_RequestPasswordForQuickLookDocumentInMainFrame>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::RequestPasswordForQuickLookDocumentInMainFrame::ReplyArguments>(globalObject, decoder);
}
#endif
#if ENABLE(CONTENT_FILTERING)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_ContentFilterDidBlockLoadForFrame>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ContentFilterDidBlockLoadForFrame::Arguments>(globalObject, decoder);
}
#endif
#if ENABLE(ACCESSIBILITY_ANIMATION_CONTROL)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_IsAnyAnimationAllowedToPlayDidChange>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::IsAnyAnimationAllowedToPlayDidChange::Arguments>(globalObject, decoder);
}
#endif
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_IsPlayingMediaDidChange>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::IsPlayingMediaDidChange::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_HandleAutoplayEvent>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::HandleAutoplayEvent::Arguments>(globalObject, decoder);
}
#if PLATFORM(MAC)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_DidPerformImmediateActionHitTest>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DidPerformImmediateActionHitTest::Arguments>(globalObject, decoder);
}
#endif
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_HandleMessage>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::HandleMessage::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_HandleMessageWithAsyncReply>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::HandleMessageWithAsyncReply::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_HandleMessageWithAsyncReply>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::HandleMessageWithAsyncReply::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_HandleSynchronousMessage>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::HandleSynchronousMessage::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_HandleSynchronousMessage>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::HandleSynchronousMessage::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_HandleAutoFillButtonClick>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::HandleAutoFillButtonClick::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_DidResignInputElementStrongPasswordAppearance>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DidResignInputElementStrongPasswordAppearance::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_PerformSwitchHapticFeedback>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::PerformSwitchHapticFeedback::Arguments>(globalObject, decoder);
}
#if ENABLE(CONTENT_EXTENSIONS)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_ContentRuleListNotification>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ContentRuleListNotification::Arguments>(globalObject, decoder);
}
#endif
#if ENABLE(WIRELESS_PLAYBACK_TARGET) && !PLATFORM(IOS_FAMILY)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_AddPlaybackTargetPickerClient>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::AddPlaybackTargetPickerClient::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_RemovePlaybackTargetPickerClient>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::RemovePlaybackTargetPickerClient::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_ShowPlaybackTargetPicker>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ShowPlaybackTargetPicker::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_PlaybackTargetPickerClientStateDidChange>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::PlaybackTargetPickerClientStateDidChange::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_SetMockMediaPlaybackTargetPickerEnabled>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::SetMockMediaPlaybackTargetPickerEnabled::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_SetMockMediaPlaybackTargetPickerState>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::SetMockMediaPlaybackTargetPickerState::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_MockMediaPlaybackTargetPickerDismissPopup>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::MockMediaPlaybackTargetPickerDismissPopup::Arguments>(globalObject, decoder);
}
#endif
#if ENABLE(VIDEO_PRESENTATION_MODE)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_SetMockVideoPresentationModeEnabled>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::SetMockVideoPresentationModeEnabled::Arguments>(globalObject, decoder);
}
#endif
#if ENABLE(POINTER_LOCK)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_RequestPointerLock>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::RequestPointerLock::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_RequestPointerLock>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::RequestPointerLock::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_RequestPointerUnlock>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::RequestPointerUnlock::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_RequestPointerUnlock>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::RequestPointerUnlock::ReplyArguments>(globalObject, decoder);
}
#endif
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_ImageOrMediaDocumentSizeChanged>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ImageOrMediaDocumentSizeChanged::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_UseFixedLayoutDidChange>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::UseFixedLayoutDidChange::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_FixedLayoutSizeDidChange>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::FixedLayoutSizeDidChange::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_DidRestoreScrollPosition>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DidRestoreScrollPosition::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_RequestScrollToRect>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::RequestScrollToRect::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_GetLoadDecisionForIcon>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::GetLoadDecisionForIcon::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_StartURLSchemeTask>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::StartURLSchemeTask::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_StopURLSchemeTask>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::StopURLSchemeTask::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_LoadSynchronousURLSchemeTask>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::LoadSynchronousURLSchemeTask::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_LoadSynchronousURLSchemeTask>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::LoadSynchronousURLSchemeTask::ReplyArguments>(globalObject, decoder);
}
#if ENABLE(DEVICE_ORIENTATION)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_ShouldAllowDeviceOrientationAndMotionAccess>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ShouldAllowDeviceOrientationAndMotionAccess::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_ShouldAllowDeviceOrientationAndMotionAccess>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ShouldAllowDeviceOrientationAndMotionAccess::ReplyArguments>(globalObject, decoder);
}
#endif
#if ENABLE(ATTACHMENT_ELEMENT)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_RegisterAttachmentIdentifierFromData>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::RegisterAttachmentIdentifierFromData::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_RegisterAttachmentIdentifierFromFilePath>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::RegisterAttachmentIdentifierFromFilePath::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_RegisterAttachmentIdentifier>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::RegisterAttachmentIdentifier::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_RegisterAttachmentsFromSerializedData>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::RegisterAttachmentsFromSerializedData::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_CloneAttachmentData>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::CloneAttachmentData::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_DidInsertAttachmentWithIdentifier>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DidInsertAttachmentWithIdentifier::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_DidRemoveAttachmentWithIdentifier>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DidRemoveAttachmentWithIdentifier::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_SerializedAttachmentDataForIdentifiers>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::SerializedAttachmentDataForIdentifiers::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_SerializedAttachmentDataForIdentifiers>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::SerializedAttachmentDataForIdentifiers::ReplyArguments>(globalObject, decoder);
}
#endif
#if (ENABLE(ATTACHMENT_ELEMENT) && PLATFORM(IOS_FAMILY))
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_WritePromisedAttachmentToPasteboard>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::WritePromisedAttachmentToPasteboard::Arguments>(globalObject, decoder);
}
#endif
#if ENABLE(ATTACHMENT_ELEMENT)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_RequestAttachmentIcon>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::RequestAttachmentIcon::Arguments>(globalObject, decoder);
}
#endif
#if ENABLE(SPEECH_SYNTHESIS)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_SpeechSynthesisVoiceList>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::SpeechSynthesisVoiceList::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_SpeechSynthesisVoiceList>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::SpeechSynthesisVoiceList::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_SpeechSynthesisSpeak>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::SpeechSynthesisSpeak::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_SpeechSynthesisSpeak>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::SpeechSynthesisSpeak::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_SpeechSynthesisSetFinishedCallback>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::SpeechSynthesisSetFinishedCallback::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_SpeechSynthesisSetFinishedCallback>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::SpeechSynthesisSetFinishedCallback::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_SpeechSynthesisCancel>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::SpeechSynthesisCancel::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_SpeechSynthesisPause>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::SpeechSynthesisPause::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_SpeechSynthesisPause>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::SpeechSynthesisPause::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_SpeechSynthesisResume>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::SpeechSynthesisResume::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_SpeechSynthesisResume>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::SpeechSynthesisResume::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_SpeechSynthesisResetState>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::SpeechSynthesisResetState::Arguments>(globalObject, decoder);
}
#endif
#if ENABLE(PDF_PLUGIN) && PLATFORM(MAC)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_ShowPDFContextMenu>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ShowPDFContextMenu::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_ShowPDFContextMenu>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ShowPDFContextMenu::ReplyArguments>(globalObject, decoder);
}
#endif
#if ENABLE(PDF_HUD)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_CreatePDFHUD>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::CreatePDFHUD::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_UpdatePDFHUDLocation>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::UpdatePDFHUDLocation::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_RemovePDFHUD>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::RemovePDFHUD::Arguments>(globalObject, decoder);
}
#endif
#if ENABLE(PDF_PAGE_NUMBER_INDICATOR)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_CreatePDFPageNumberIndicator>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::CreatePDFPageNumberIndicator::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_UpdatePDFPageNumberIndicatorLocation>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::UpdatePDFPageNumberIndicatorLocation::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_UpdatePDFPageNumberIndicatorCurrentPage>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::UpdatePDFPageNumberIndicatorCurrentPage::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_RemovePDFPageNumberIndicator>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::RemovePDFPageNumberIndicator::Arguments>(globalObject, decoder);
}
#endif
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_ConfigureLoggingChannel>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ConfigureLoggingChannel::Arguments>(globalObject, decoder);
}
#if PLATFORM(GTK)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_ShowEmojiPicker>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ShowEmojiPicker::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_ShowEmojiPicker>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ShowEmojiPicker::ReplyArguments>(globalObject, decoder);
}
#endif
#if HAVE(VISIBILITY_PROPAGATION_VIEW)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_DidCreateContextInWebProcessForVisibilityPropagation>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DidCreateContextInWebProcessForVisibilityPropagation::Arguments>(globalObject, decoder);
}
#endif
#if ENABLE(WEB_AUTHN)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_SetMockWebAuthenticationConfiguration>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::SetMockWebAuthenticationConfiguration::Arguments>(globalObject, decoder);
}
#endif
#if PLATFORM(GTK) || PLATFORM(WPE)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_SendMessageToWebView>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::SendMessageToWebView::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_SendMessageToWebViewWithReply>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::SendMessageToWebViewWithReply::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_SendMessageToWebViewWithReply>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::SendMessageToWebViewWithReply::ReplyArguments>(globalObject, decoder);
}
#endif
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_DidFindTextManipulationItems>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DidFindTextManipulationItems::Arguments>(globalObject, decoder);
}
#if ENABLE(MEDIA_USAGE)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_AddMediaUsageManagerSession>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::AddMediaUsageManagerSession::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_UpdateMediaUsageManagerSessionState>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::UpdateMediaUsageManagerSessionState::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_RemoveMediaUsageManagerSession>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::RemoveMediaUsageManagerSession::Arguments>(globalObject, decoder);
}
#endif
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_SetHasExecutedAppBoundBehaviorBeforeNavigation>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::SetHasExecutedAppBoundBehaviorBeforeNavigation::Arguments>(globalObject, decoder);
}
#if PLATFORM(MAC)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_ChangeUniversalAccessZoomFocus>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ChangeUniversalAccessZoomFocus::Arguments>(globalObject, decoder);
}
#endif
#if ENABLE(ARKIT_INLINE_PREVIEW_IOS)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_TakeModelElementFullscreen>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::TakeModelElementFullscreen::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_ModelElementSetInteractionEnabled>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ModelElementSetInteractionEnabled::Arguments>(globalObject, decoder);
}
#endif
#if ENABLE(ARKIT_INLINE_PREVIEW_MAC)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_ModelElementCreateRemotePreview>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ModelElementCreateRemotePreview::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_ModelElementCreateRemotePreview>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ModelElementCreateRemotePreview::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_ModelElementLoadRemotePreview>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ModelElementLoadRemotePreview::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_ModelElementLoadRemotePreview>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ModelElementLoadRemotePreview::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_ModelElementDestroyRemotePreview>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ModelElementDestroyRemotePreview::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_ModelElementSizeDidChange>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ModelElementSizeDidChange::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_ModelElementSizeDidChange>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ModelElementSizeDidChange::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_HandleMouseDownForModelElement>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::HandleMouseDownForModelElement::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_HandleMouseMoveForModelElement>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::HandleMouseMoveForModelElement::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_HandleMouseUpForModelElement>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::HandleMouseUpForModelElement::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_ModelInlinePreviewUUIDs>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ModelInlinePreviewUUIDs::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_ModelInlinePreviewUUIDs>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ModelInlinePreviewUUIDs::ReplyArguments>(globalObject, decoder);
}
#endif
#if ENABLE(ARKIT_INLINE_PREVIEW)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_ModelElementGetCamera>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ModelElementGetCamera::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_ModelElementGetCamera>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ModelElementGetCamera::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_ModelElementSetCamera>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ModelElementSetCamera::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_ModelElementSetCamera>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ModelElementSetCamera::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_ModelElementIsPlayingAnimation>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ModelElementIsPlayingAnimation::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_ModelElementIsPlayingAnimation>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ModelElementIsPlayingAnimation::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_ModelElementSetAnimationIsPlaying>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ModelElementSetAnimationIsPlaying::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_ModelElementSetAnimationIsPlaying>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ModelElementSetAnimationIsPlaying::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_ModelElementIsLoopingAnimation>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ModelElementIsLoopingAnimation::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_ModelElementIsLoopingAnimation>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ModelElementIsLoopingAnimation::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_ModelElementSetIsLoopingAnimation>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ModelElementSetIsLoopingAnimation::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_ModelElementSetIsLoopingAnimation>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ModelElementSetIsLoopingAnimation::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_ModelElementAnimationDuration>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ModelElementAnimationDuration::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_ModelElementAnimationDuration>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ModelElementAnimationDuration::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_ModelElementAnimationCurrentTime>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ModelElementAnimationCurrentTime::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_ModelElementAnimationCurrentTime>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ModelElementAnimationCurrentTime::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_ModelElementSetAnimationCurrentTime>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ModelElementSetAnimationCurrentTime::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_ModelElementSetAnimationCurrentTime>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ModelElementSetAnimationCurrentTime::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_ModelElementHasAudio>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ModelElementHasAudio::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_ModelElementHasAudio>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ModelElementHasAudio::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_ModelElementIsMuted>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ModelElementIsMuted::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_ModelElementIsMuted>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ModelElementIsMuted::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_ModelElementSetIsMuted>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ModelElementSetIsMuted::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_ModelElementSetIsMuted>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::ModelElementSetIsMuted::ReplyArguments>(globalObject, decoder);
}
#endif
#if ENABLE(APPLE_PAY_AMS_UI)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_StartApplePayAMSUISession>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::StartApplePayAMSUISession::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_StartApplePayAMSUISession>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::StartApplePayAMSUISession::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_AbortApplePayAMSUISession>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::AbortApplePayAMSUISession::Arguments>(globalObject, decoder);
}
#endif
#if USE(SYSTEM_PREVIEW)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_BeginSystemPreview>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::BeginSystemPreview::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_BeginSystemPreview>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::BeginSystemPreview::ReplyArguments>(globalObject, decoder);
}
#endif
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_DidCreateSleepDisabler>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DidCreateSleepDisabler::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_DidDestroySleepDisabler>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DidDestroySleepDisabler::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_RequestCookieConsent>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::RequestCookieConsent::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_RequestCookieConsent>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::RequestCookieConsent::ReplyArguments>(globalObject, decoder);
}
#if ENABLE(WINDOW_PROXY_PROPERTY_ACCESS_NOTIFICATION)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_DidAccessWindowProxyPropertyViaOpenerForFrame>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DidAccessWindowProxyPropertyViaOpenerForFrame::Arguments>(globalObject, decoder);
}
#endif
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_DidApplyLinkDecorationFiltering>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DidApplyLinkDecorationFiltering::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_BroadcastProcessSyncData>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::BroadcastProcessSyncData::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_BroadcastTopDocumentSyncData>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::BroadcastTopDocumentSyncData::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_DispatchLoadEventToFrameOwnerElement>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DispatchLoadEventToFrameOwnerElement::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_FocusRemoteFrame>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::FocusRemoteFrame::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_PostMessageToRemote>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::PostMessageToRemote::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_RenderTreeAsTextForTesting>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::RenderTreeAsTextForTesting::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_RenderTreeAsTextForTesting>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::RenderTreeAsTextForTesting::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_FrameTextForTesting>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::FrameTextForTesting::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_FrameTextForTesting>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::FrameTextForTesting::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_LayerTreeAsTextForTesting>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::LayerTreeAsTextForTesting::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_LayerTreeAsTextForTesting>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::LayerTreeAsTextForTesting::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_AddMessageToConsoleForTesting>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::AddMessageToConsoleForTesting::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_BindRemoteAccessibilityFrames>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::BindRemoteAccessibilityFrames::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_BindRemoteAccessibilityFrames>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::BindRemoteAccessibilityFrames::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_UpdateRemoteFrameAccessibilityOffset>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::UpdateRemoteFrameAccessibilityOffset::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_DocumentURLForConsoleLog>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DocumentURLForConsoleLog::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPageProxy_DocumentURLForConsoleLog>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DocumentURLForConsoleLog::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_NowPlayingMetadataChanged>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::NowPlayingMetadataChanged::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_DidAdjustVisibilityWithSelectors>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::DidAdjustVisibilityWithSelectors::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_FrameNameChanged>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::FrameNameChanged::Arguments>(globalObject, decoder);
}
#if ENABLE(GAMEPAD)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_GamepadsRecentlyAccessed>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::GamepadsRecentlyAccessed::Arguments>(globalObject, decoder);
}
#endif
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_HasActiveNowPlayingSessionChanged>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::HasActiveNowPlayingSessionChanged::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPageProxy_SetAllowsLayoutViewportHeightExpansion>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPageProxy::SetAllowsLayoutViewportHeightExpansion::Arguments>(globalObject, decoder);
}

}

#endif

