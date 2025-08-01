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
#include "WebPage.h"

#include "ArgumentCoders.h" // NOLINT
#include "CallbackID.h" // NOLINT
#include "ContentAsStringIncludesChildFrames.h" // NOLINT
#include "ContentWorldData.h" // NOLINT
#if HAVE(AUDIT_TOKEN)
#include "CoreIPCAuditToken.h" // NOLINT
#endif
#if ENABLE(DATA_DETECTION)
#include "DataDetectionResult.h" // NOLINT
#endif
#include "Decoder.h" // NOLINT
#if PLATFORM(IOS_FAMILY)
#include "DocumentEditingContext.h" // NOLINT
#endif
#if !PLATFORM(GTK) && ENABLE(DRAG_SUPPORT) || PLATFORM(GTK) && ENABLE(DRAG_SUPPORT)
#include "DragControllerAction.h" // NOLINT
#endif
#if PLATFORM(IOS_FAMILY) && ENABLE(DRAG_SUPPORT)
#include "DragInitiationResult.h" // NOLINT
#endif
#include "DrawingAreaInfo.h" // NOLINT
#if PLATFORM(IOS_FAMILY)
#include "DynamicViewportSizeUpdate.h" // NOLINT
#endif
#include "EditingRange.h" // NOLINT
#if PLATFORM(IOS_FAMILY)
#include "EditorState.h" // NOLINT
#endif
#if PLATFORM(IOS_FAMILY)
#include "FocusedElementInformation.h" // NOLINT
#endif
#include "FormDataReference.h" // NOLINT
#if ENABLE(PDF_PLUGIN) && PLATFORM(MAC)
#include "FrameInfoData.h" // NOLINT
#endif
#include "FrameTreeNodeData.h" // NOLINT
#if ENABLE(GAMEPAD)
#include "GamepadData.h" // NOLINT
#endif
#if ENABLE(GEOLOCATION)
#include "GeolocationIdentifier.h" // NOLINT
#endif
#if PLATFORM(IOS_FAMILY)
#include "GestureTypes.h" // NOLINT
#endif
#include "GoToBackForwardItemParameters.h" // NOLINT
#include "HandleMessage.h" // NOLINT
#if PLATFORM(IOS_FAMILY)
#include "HardwareKeyboardState.h" // NOLINT
#endif
#include "IdentifierTypes.h" // NOLINT
#include "ImageBufferBackendHandle.h" // NOLINT
#include "ImageOptions.h" // NOLINT
#if PLATFORM(COCOA)
#include "InsertTextOptions.h" // NOLINT
#endif
#if PLATFORM(IOS_FAMILY)
#include "InteractionInformationRequest.h" // NOLINT
#endif
#include "JavaScriptEvaluationResult.h" // NOLINT
#include "LoadParameters.h" // NOLINT
#include "MediaPlaybackState.h" // NOLINT
#if ENABLE(WIRELESS_PLAYBACK_TARGET) && !PLATFORM(IOS_FAMILY)
#include "MediaPlaybackTargetContextSerialized.h" // NOLINT
#endif
#if ENABLE(PDF_PLUGIN) && PLATFORM(MAC)
#include "PDFPluginIdentifier.h" // NOLINT
#endif
#include "PageClient.h" // NOLINT
#include "PrintInfo.h" // NOLINT
#if PLATFORM(WPE) && USE(GBM) && ENABLE(WPE_PLATFORM)
#include "RendererBufferFormat.h" // NOLINT
#endif
#if (PLATFORM(IOS_FAMILY) && ENABLE(REVEAL))
#include "RevealItem.h" // NOLINT
#endif
#include "RunJavaScriptParameters.h" // NOLINT
#include "SandboxExtension.h" // NOLINT
#include "SessionState.h" // NOLINT
#include "SharedBufferReference.h" // NOLINT
#if PLATFORM(IOS_FAMILY)
#include "SyntheticEditingCommandType.h" // NOLINT
#endif
#if ENABLE(IMAGE_ANALYSIS)
#include "TextRecognitionUpdateResult.h" // NOLINT
#endif
#if PLATFORM(IOS_FAMILY)
#include "TransactionID.h" // NOLINT
#endif
#include "UserData.h" // NOLINT
#if PLATFORM(GTK) || PLATFORM(WPE)
#include "UserMessage.h" // NOLINT
#endif
#if PLATFORM(COCOA)
#include "ViewWindowCoordinates.h" // NOLINT
#endif
#if PLATFORM(IOS_FAMILY)
#include "WebAutocorrectionData.h" // NOLINT
#endif
#if ENABLE(CONTEXT_MENUS)
#include "WebContextMenuItemData.h" // NOLINT
#endif
#if !ENABLE(IOS_TOUCH_EVENTS) && ENABLE(TOUCH_EVENTS)
#include "WebEvent.h" // NOLINT
#endif
#include "WebEventModifier.h" // NOLINT
#include "WebFindOptions.h" // NOLINT
#include "WebFoundTextRange.h" // NOLINT
#include "WebHitTestResultData.h" // NOLINT
#include "WebKeyboardEvent.h" // NOLINT
#include "WebMouseEvent.h" // NOLINT
#include "WebPageMessages.h" // NOLINT
#include "WebPageProxyIdentifier.h" // NOLINT
#include "WebPreferencesStore.h" // NOLINT
#if !ENABLE(IOS_TOUCH_EVENTS) && ENABLE(TOUCH_EVENTS)
#include "WebTouchEvent.h" // NOLINT
#endif
#include "WebURLSchemeHandlerIdentifier.h" // NOLINT
#include "WebWheelEvent.h" // NOLINT
#include "WebsitePoliciesData.h" // NOLINT
#include <JavaScriptCore/ConsoleTypes.h> // NOLINT
#include <JavaScriptCore/InspectorFrontendChannel.h> // NOLINT
#if PLATFORM(MAC)
#include <WebCore/AXObjectCache.h> // NOLINT
#endif
#include <WebCore/ActivityState.h> // NOLINT
#if ENABLE(APP_HIGHLIGHTS)
#include <WebCore/AppHighlight.h> // NOLINT
#endif
#if ENABLE(APPLICATION_MANIFEST)
#include <WebCore/ApplicationManifest.h> // NOLINT
#endif
#if ENABLE(WRITING_TOOLS) || PLATFORM(COCOA) || PLATFORM(MAC)
#include <WebCore/AttributedString.h> // NOLINT
#endif
#include <WebCore/BackForwardItemIdentifier.h> // NOLINT
#if ENABLE(MEDIA_STREAM)
#include <WebCore/CaptureDevice.h> // NOLINT
#endif
#if PLATFORM(MAC)
#include <WebCore/CaretAnimator.h> // NOLINT
#endif
#if ENABLE(WRITING_TOOLS) || PLATFORM(COCOA)
#include <WebCore/CharacterRange.h> // NOLINT
#endif
#include <WebCore/Color.h> // NOLINT
#if PLATFORM(COCOA)
#include <WebCore/CompositionHighlight.h> // NOLINT
#endif
#if PLATFORM(COCOA)
#include <WebCore/CompositionUnderline.h> // NOLINT
#endif
#if ENABLE(DATA_DETECTION)
#include <WebCore/DataDetectorType.h> // NOLINT
#endif
#if PLATFORM(COCOA)
#include <WebCore/DictationAlternative.h> // NOLINT
#endif
#if PLATFORM(COCOA)
#include <WebCore/DictationContext.h> // NOLINT
#endif
#include <WebCore/DictionaryPopupInfo.h> // NOLINT
#include <WebCore/DocumentSyncData.h> // NOLINT
#if !PLATFORM(GTK) && ENABLE(DRAG_SUPPORT) || ENABLE(DRAG_SUPPORT) || PLATFORM(GTK) && ENABLE(DRAG_SUPPORT) || PLATFORM(IOS_FAMILY) && ENABLE(DRAG_SUPPORT)
#include <WebCore/DragActions.h> // NOLINT
#endif
#if !PLATFORM(GTK) && ENABLE(DRAG_SUPPORT) || PLATFORM(GTK) && ENABLE(DRAG_SUPPORT)
#include <WebCore/DragData.h> // NOLINT
#endif
#include <WebCore/ElementContext.h> // NOLINT
#include <WebCore/ElementTargetingTypes.h> // NOLINT
#include <WebCore/FloatPoint.h> // NOLINT
#include <WebCore/FloatRect.h> // NOLINT
#include <WebCore/FloatSize.h> // NOLINT
#include <WebCore/FontAttributeChanges.h> // NOLINT
#include <WebCore/FontAttributes.h> // NOLINT
#include <WebCore/FrameIdentifier.h> // NOLINT
#include <WebCore/FrameLoaderTypes.h> // NOLINT
#include <WebCore/FrameTreeSyncData.h> // NOLINT
#if ENABLE(GAMEPAD)
#include <WebCore/GamepadProviderClient.h> // NOLINT
#endif
#if ENABLE(APP_HIGHLIGHTS)
#include <WebCore/HighlightVisibility.h> // NOLINT
#endif
#include <WebCore/ImageTypes.h> // NOLINT
#if PLATFORM(COCOA)
#include <WebCore/ImageUtilities.h> // NOLINT
#endif
#if PLATFORM(IOS_FAMILY)
#include <WebCore/IntDegrees.h> // NOLINT
#endif
#include <WebCore/IntPoint.h> // NOLINT
#include <WebCore/IntRect.h> // NOLINT
#include <WebCore/IntSize.h> // NOLINT
#include <WebCore/JSDOMExceptionHandling.h> // NOLINT
#include <WebCore/LayerHostingContextIdentifier.h> // NOLINT
#include <WebCore/LayerTreeAsTextOptions.h> // NOLINT
#include <WebCore/LayoutMilestone.h> // NOLINT
#if PLATFORM(COCOA)
#include <WebCore/LegacyWebArchive.h> // NOLINT
#endif
#if ENABLE(ADVANCED_PRIVACY_PROTECTIONS)
#include <WebCore/LinkDecorationFilteringData.h> // NOLINT
#endif
#include <WebCore/MarkupExclusionRule.h> // NOLINT
#if ENABLE(MEDIA_STREAM)
#include <WebCore/MediaConstraintType.h> // NOLINT
#endif
#if ENABLE(MEDIA_STREAM)
#include <WebCore/MediaDeviceHashSalts.h> // NOLINT
#endif
#if ENABLE(ENCRYPTED_MEDIA)
#include <WebCore/MediaKeySystemRequestIdentifier.h> // NOLINT
#endif
#include <WebCore/MediaProducer.h> // NOLINT
#include <WebCore/MessageWithMessagePorts.h> // NOLINT
#include <WebCore/NavigationIdentifier.h> // NOLINT
#include <WebCore/NavigationScheduler.h> // NOLINT
#include <WebCore/NodeIdentifier.h> // NOLINT
#if PLATFORM(COCOA)
#include <WebCore/NowPlayingInfo.h> // NOLINT
#endif
#include <WebCore/Pagination.h> // NOLINT
#include <WebCore/PlatformEvent.h> // NOLINT
#include <WebCore/PlatformLayerIdentifier.h> // NOLINT
#include <WebCore/PlatformWheelEvent.h> // NOLINT
#if ENABLE(WIRELESS_PLAYBACK_TARGET) && !PLATFORM(IOS_FAMILY)
#include <WebCore/PlaybackTargetClientContextIdentifier.h> // NOLINT
#endif
#include <WebCore/PointerID.h> // NOLINT
#include <WebCore/ProcessQualified.h> // NOLINT
#include <WebCore/ProcessSyncData.h> // NOLINT
#include <WebCore/RectEdges.h> // NOLINT
#include <WebCore/RegistrableDomain.h> // NOLINT
#include <WebCore/RemoteUserInputEventData.h> // NOLINT
#include <WebCore/RenderTreeAsText.h> // NOLINT
#include <WebCore/Report.h> // NOLINT
#include <WebCore/ResourceError.h> // NOLINT
#include <WebCore/ResourceLoaderIdentifier.h> // NOLINT
#include <WebCore/ResourceRequest.h> // NOLINT
#include <WebCore/ResourceResponse.h> // NOLINT
#include <WebCore/ScriptExecutionContextIdentifier.h> // NOLINT
#include <WebCore/ScrollTypes.h> // NOLINT
#include <WebCore/ScrollingCoordinatorTypes.h> // NOLINT
#include <WebCore/ScrollingNodeID.h> // NOLINT
#include <WebCore/SecurityOriginData.h> // NOLINT
#include <WebCore/SecurityPolicyViolationEvent.h> // NOLINT
#if PLATFORM(GTK) && ENABLE(DRAG_SUPPORT)
#include <WebCore/SelectionData.h> // NOLINT
#endif
#include <WebCore/ShareableBitmap.h> // NOLINT
#include <WebCore/ShareableBitmapHandle.h> // NOLINT
#include <WebCore/SharedBuffer.h> // NOLINT
#if ENABLE(APP_HIGHLIGHTS) || PLATFORM(GTK)
#include <WebCore/SharedMemory.h> // NOLINT
#endif
#if PLATFORM(COCOA)
#include <WebCore/SnapshotIdentifier.h> // NOLINT
#endif
#if USE(SYSTEM_PREVIEW)
#include <WebCore/SystemPreviewInfo.h> // NOLINT
#endif
#include <WebCore/TextCheckerClient.h> // NOLINT
#include <WebCore/TextExtractionTypes.h> // NOLINT
#if PLATFORM(IOS_FAMILY)
#include <WebCore/TextGranularity.h> // NOLINT
#endif
#if ENABLE(WRITING_TOOLS) || PLATFORM(COCOA) || PLATFORM(IOS_FAMILY) && ENABLE(DRAG_SUPPORT)
#include <WebCore/TextIndicator.h> // NOLINT
#endif
#include <WebCore/TextManipulationControllerExclusionRule.h> // NOLINT
#include <WebCore/TextManipulationControllerManipulationFailure.h> // NOLINT
#include <WebCore/TextManipulationItem.h> // NOLINT
#if ENABLE(IMAGE_ANALYSIS)
#include <WebCore/TextRecognitionResult.h> // NOLINT
#endif
#if ENABLE(MODEL_PROCESS)
#include <WebCore/TransformationMatrix.h> // NOLINT
#endif
#if ENABLE(MEDIA_STREAM)
#include <WebCore/UserMediaRequestIdentifier.h> // NOLINT
#endif
#if PLATFORM(IOS_FAMILY)
#include <WebCore/ViewportArguments.h> // NOLINT
#endif
#include <WebCore/ViolationReportType.h> // NOLINT
#if PLATFORM(IOS_FAMILY)
#include <WebCore/VisibleSelection.h> // NOLINT
#endif
#include <WebCore/WritingDirection.h> // NOLINT
#if ENABLE(WRITING_TOOLS)
#include <WebCore/WritingToolsTypes.h> // NOLINT
#endif
#include <optional> // NOLINT
#include <span> // NOLINT
#include <utility> // NOLINT
#include <wtf/Expected.h> // NOLINT
#if PLATFORM(COCOA)
#include <wtf/HashMap.h> // NOLINT
#endif
#if PLATFORM(COCOA)
#include <wtf/MachSendRight.h> // NOLINT
#endif
#include <wtf/ObjectIdentifier.h> // NOLINT
#include <wtf/OptionSet.h> // NOLINT
#include <wtf/Ref.h> // NOLINT
#if (PLATFORM(COCOA) && PLATFORM(IOS_FAMILY)) || ENABLE(WRITING_TOOLS) || PLATFORM(COCOA)
#include <wtf/RefCounted.h> // NOLINT
#endif
#include <wtf/URLHash.h> // NOLINT
#if ENABLE(WRITING_TOOLS)
#include <wtf/UUID.h> // NOLINT
#endif
#include <wtf/Vector.h> // NOLINT
#include <wtf/text/WTFString.h> // NOLINT

#if ENABLE(IPC_TESTING_API)
#include "JSIPCBinding.h"
#endif

namespace WebKit {

void WebPage::didReceiveMessage(IPC::Connection& connection, IPC::Decoder& decoder)
{
    Ref protectedThis { *this };
    if (decoder.messageName() == Messages::WebPage::SetInitialFocus::name())
        return IPC::handleMessageAsync<Messages::WebPage::SetInitialFocus>(connection, decoder, this, &WebPage::setInitialFocus);
    if (decoder.messageName() == Messages::WebPage::SetActivityState::name())
        return IPC::handleMessageAsync<Messages::WebPage::SetActivityState>(connection, decoder, this, &WebPage::setActivityState);
    if (decoder.messageName() == Messages::WebPage::SetBackgroundColor::name())
        return IPC::handleMessage<Messages::WebPage::SetBackgroundColor>(connection, decoder, this, &WebPage::setBackgroundColor);
    if (decoder.messageName() == Messages::WebPage::AddConsoleMessage::name())
        return IPC::handleMessage<Messages::WebPage::AddConsoleMessage>(connection, decoder, this, &WebPage::addConsoleMessage);
    if (decoder.messageName() == Messages::WebPage::EnqueueSecurityPolicyViolationEvent::name())
        return IPC::handleMessage<Messages::WebPage::EnqueueSecurityPolicyViolationEvent>(connection, decoder, this, &WebPage::enqueueSecurityPolicyViolationEvent);
    if (decoder.messageName() == Messages::WebPage::SendReportToEndpoints::name())
        return IPC::handleMessage<Messages::WebPage::SendReportToEndpoints>(connection, decoder, this, &WebPage::sendReportToEndpoints);
    if (decoder.messageName() == Messages::WebPage::NotifyReportObservers::name())
        return IPC::handleMessage<Messages::WebPage::NotifyReportObservers>(connection, decoder, this, &WebPage::notifyReportObservers);
#if PLATFORM(COCOA)
    if (decoder.messageName() == Messages::WebPage::SetObscuredContentInsetsFenced::name())
        return IPC::handleMessage<Messages::WebPage::SetObscuredContentInsetsFenced>(connection, decoder, this, &WebPage::setObscuredContentInsetsFenced);
#endif
#if !PLATFORM(COCOA)
    if (decoder.messageName() == Messages::WebPage::SetObscuredContentInsets::name())
        return IPC::handleMessage<Messages::WebPage::SetObscuredContentInsets>(connection, decoder, this, &WebPage::setObscuredContentInsets);
#endif
    if (decoder.messageName() == Messages::WebPage::SetShouldSuppressHDR::name())
        return IPC::handleMessage<Messages::WebPage::SetShouldSuppressHDR>(connection, decoder, this, &WebPage::setShouldSuppressHDR);
    if (decoder.messageName() == Messages::WebPage::SetUnderlayColor::name())
        return IPC::handleMessage<Messages::WebPage::SetUnderlayColor>(connection, decoder, this, &WebPage::setUnderlayColor);
    if (decoder.messageName() == Messages::WebPage::SetUnderPageBackgroundColorOverride::name())
        return IPC::handleMessage<Messages::WebPage::SetUnderPageBackgroundColorOverride>(connection, decoder, this, &WebPage::setUnderPageBackgroundColorOverride);
    if (decoder.messageName() == Messages::WebPage::SetNeedsFixedContainerEdgesUpdate::name())
        return IPC::handleMessage<Messages::WebPage::SetNeedsFixedContainerEdgesUpdate>(connection, decoder, this, &WebPage::setNeedsFixedContainerEdgesUpdate);
    if (decoder.messageName() == Messages::WebPage::ViewWillStartLiveResize::name())
        return IPC::handleMessage<Messages::WebPage::ViewWillStartLiveResize>(connection, decoder, this, &WebPage::viewWillStartLiveResize);
    if (decoder.messageName() == Messages::WebPage::ViewWillEndLiveResize::name())
        return IPC::handleMessage<Messages::WebPage::ViewWillEndLiveResize>(connection, decoder, this, &WebPage::viewWillEndLiveResize);
    if (decoder.messageName() == Messages::WebPage::ExecuteEditCommandWithCallback::name())
        return IPC::handleMessageAsync<Messages::WebPage::ExecuteEditCommandWithCallback>(connection, decoder, this, &WebPage::executeEditCommandWithCallback);
    if (decoder.messageName() == Messages::WebPage::KeyEvent::name())
        return IPC::handleMessage<Messages::WebPage::KeyEvent>(connection, decoder, this, &WebPage::keyEvent);
    if (decoder.messageName() == Messages::WebPage::MouseEvent::name())
        return IPC::handleMessage<Messages::WebPage::MouseEvent>(connection, decoder, this, &WebPage::mouseEvent);
    if (decoder.messageName() == Messages::WebPage::SetLastKnownMousePosition::name())
        return IPC::handleMessage<Messages::WebPage::SetLastKnownMousePosition>(connection, decoder, this, &WebPage::setLastKnownMousePosition);
#if PLATFORM(IOS_FAMILY)
    if (decoder.messageName() == Messages::WebPage::SetSceneIdentifier::name())
        return IPC::handleMessage<Messages::WebPage::SetSceneIdentifier>(connection, decoder, this, &WebPage::setSceneIdentifier);
    if (decoder.messageName() == Messages::WebPage::SetViewportConfigurationViewLayoutSize::name())
        return IPC::handleMessage<Messages::WebPage::SetViewportConfigurationViewLayoutSize>(connection, decoder, this, &WebPage::setViewportConfigurationViewLayoutSize);
    if (decoder.messageName() == Messages::WebPage::SetDeviceOrientation::name())
        return IPC::handleMessage<Messages::WebPage::SetDeviceOrientation>(connection, decoder, this, &WebPage::setDeviceOrientation);
    if (decoder.messageName() == Messages::WebPage::SetOverrideViewportArguments::name())
        return IPC::handleMessage<Messages::WebPage::SetOverrideViewportArguments>(connection, decoder, this, &WebPage::setOverrideViewportArguments);
    if (decoder.messageName() == Messages::WebPage::DynamicViewportSizeUpdate::name())
        return IPC::handleMessage<Messages::WebPage::DynamicViewportSizeUpdate>(connection, decoder, this, &WebPage::dynamicViewportSizeUpdate);
    if (decoder.messageName() == Messages::WebPage::SetScreenIsBeingCaptured::name())
        return IPC::handleMessage<Messages::WebPage::SetScreenIsBeingCaptured>(connection, decoder, this, &WebPage::setScreenIsBeingCaptured);
    if (decoder.messageName() == Messages::WebPage::SetInsertionPointColor::name())
        return IPC::handleMessage<Messages::WebPage::SetInsertionPointColor>(connection, decoder, this, &WebPage::setInsertionPointColor);
    if (decoder.messageName() == Messages::WebPage::AttemptSyntheticClick::name())
        return IPC::handleMessage<Messages::WebPage::AttemptSyntheticClick>(connection, decoder, this, &WebPage::attemptSyntheticClick);
    if (decoder.messageName() == Messages::WebPage::PotentialTapAtPosition::name())
        return IPC::handleMessageAsync<Messages::WebPage::PotentialTapAtPosition>(connection, decoder, this, &WebPage::potentialTapAtPosition);
    if (decoder.messageName() == Messages::WebPage::CommitPotentialTap::name())
        return IPC::handleMessageAsync<Messages::WebPage::CommitPotentialTap>(connection, decoder, this, &WebPage::commitPotentialTap);
    if (decoder.messageName() == Messages::WebPage::CancelPotentialTap::name())
        return IPC::handleMessage<Messages::WebPage::CancelPotentialTap>(connection, decoder, this, &WebPage::cancelPotentialTap);
    if (decoder.messageName() == Messages::WebPage::TapHighlightAtPosition::name())
        return IPC::handleMessage<Messages::WebPage::TapHighlightAtPosition>(connection, decoder, this, &WebPage::tapHighlightAtPosition);
    if (decoder.messageName() == Messages::WebPage::DidRecognizeLongPress::name())
        return IPC::handleMessage<Messages::WebPage::DidRecognizeLongPress>(connection, decoder, this, &WebPage::didRecognizeLongPress);
    if (decoder.messageName() == Messages::WebPage::HandleDoubleTapForDoubleClickAtPoint::name())
        return IPC::handleMessage<Messages::WebPage::HandleDoubleTapForDoubleClickAtPoint>(connection, decoder, this, &WebPage::handleDoubleTapForDoubleClickAtPoint);
    if (decoder.messageName() == Messages::WebPage::InspectorNodeSearchMovedToPosition::name())
        return IPC::handleMessage<Messages::WebPage::InspectorNodeSearchMovedToPosition>(connection, decoder, this, &WebPage::inspectorNodeSearchMovedToPosition);
    if (decoder.messageName() == Messages::WebPage::InspectorNodeSearchEndedAtPosition::name())
        return IPC::handleMessage<Messages::WebPage::InspectorNodeSearchEndedAtPosition>(connection, decoder, this, &WebPage::inspectorNodeSearchEndedAtPosition);
    if (decoder.messageName() == Messages::WebPage::BlurFocusedElement::name())
        return IPC::handleMessage<Messages::WebPage::BlurFocusedElement>(connection, decoder, this, &WebPage::blurFocusedElement);
    if (decoder.messageName() == Messages::WebPage::SelectWithGesture::name())
        return IPC::handleMessageAsync<Messages::WebPage::SelectWithGesture>(connection, decoder, this, &WebPage::selectWithGesture);
    if (decoder.messageName() == Messages::WebPage::UpdateSelectionWithTouches::name())
        return IPC::handleMessageAsync<Messages::WebPage::UpdateSelectionWithTouches>(connection, decoder, this, &WebPage::updateSelectionWithTouches);
    if (decoder.messageName() == Messages::WebPage::SelectWithTwoTouches::name())
        return IPC::handleMessageAsync<Messages::WebPage::SelectWithTwoTouches>(connection, decoder, this, &WebPage::selectWithTwoTouches);
    if (decoder.messageName() == Messages::WebPage::ExtendSelection::name())
        return IPC::handleMessageAsync<Messages::WebPage::ExtendSelection>(connection, decoder, this, &WebPage::extendSelection);
    if (decoder.messageName() == Messages::WebPage::SelectWordBackward::name())
        return IPC::handleMessage<Messages::WebPage::SelectWordBackward>(connection, decoder, this, &WebPage::selectWordBackward);
    if (decoder.messageName() == Messages::WebPage::ExtendSelectionForReplacement::name())
        return IPC::handleMessageAsync<Messages::WebPage::ExtendSelectionForReplacement>(connection, decoder, this, &WebPage::extendSelectionForReplacement);
    if (decoder.messageName() == Messages::WebPage::MoveSelectionByOffset::name())
        return IPC::handleMessageAsync<Messages::WebPage::MoveSelectionByOffset>(connection, decoder, this, &WebPage::moveSelectionByOffset);
    if (decoder.messageName() == Messages::WebPage::SelectTextWithGranularityAtPoint::name())
        return IPC::handleMessageAsync<Messages::WebPage::SelectTextWithGranularityAtPoint>(connection, decoder, this, &WebPage::selectTextWithGranularityAtPoint);
    if (decoder.messageName() == Messages::WebPage::SelectPositionAtBoundaryWithDirection::name())
        return IPC::handleMessageAsync<Messages::WebPage::SelectPositionAtBoundaryWithDirection>(connection, decoder, this, &WebPage::selectPositionAtBoundaryWithDirection);
    if (decoder.messageName() == Messages::WebPage::MoveSelectionAtBoundaryWithDirection::name())
        return IPC::handleMessageAsync<Messages::WebPage::MoveSelectionAtBoundaryWithDirection>(connection, decoder, this, &WebPage::moveSelectionAtBoundaryWithDirection);
    if (decoder.messageName() == Messages::WebPage::SelectPositionAtPoint::name())
        return IPC::handleMessageAsync<Messages::WebPage::SelectPositionAtPoint>(connection, decoder, this, &WebPage::selectPositionAtPoint);
    if (decoder.messageName() == Messages::WebPage::BeginSelectionInDirection::name())
        return IPC::handleMessageAsync<Messages::WebPage::BeginSelectionInDirection>(connection, decoder, this, &WebPage::beginSelectionInDirection);
    if (decoder.messageName() == Messages::WebPage::UpdateSelectionWithExtentPoint::name())
        return IPC::handleMessageAsync<Messages::WebPage::UpdateSelectionWithExtentPoint>(connection, decoder, this, &WebPage::updateSelectionWithExtentPoint);
    if (decoder.messageName() == Messages::WebPage::UpdateSelectionWithExtentPointAndBoundary::name())
        return IPC::handleMessageAsync<Messages::WebPage::UpdateSelectionWithExtentPointAndBoundary>(connection, decoder, this, &WebPage::updateSelectionWithExtentPointAndBoundary);
    if (decoder.messageName() == Messages::WebPage::DidReleaseAllTouchPoints::name())
        return IPC::handleMessage<Messages::WebPage::DidReleaseAllTouchPoints>(connection, decoder, this, &WebPage::didReleaseAllTouchPoints);
    if (decoder.messageName() == Messages::WebPage::ClearSelectionAfterTappingSelectionHighlightIfNeeded::name())
        return IPC::handleMessage<Messages::WebPage::ClearSelectionAfterTappingSelectionHighlightIfNeeded>(connection, decoder, this, &WebPage::clearSelectionAfterTappingSelectionHighlightIfNeeded);
#endif
#if (PLATFORM(IOS_FAMILY) && ENABLE(REVEAL))
    if (decoder.messageName() == Messages::WebPage::RequestRVItemInCurrentSelectedRange::name())
        return IPC::handleMessageAsync<Messages::WebPage::RequestRVItemInCurrentSelectedRange>(connection, decoder, this, &WebPage::requestRVItemInCurrentSelectedRange);
    if (decoder.messageName() == Messages::WebPage::PrepareSelectionForContextMenuWithLocationInView::name())
        return IPC::handleMessageAsync<Messages::WebPage::PrepareSelectionForContextMenuWithLocationInView>(connection, decoder, this, &WebPage::prepareSelectionForContextMenuWithLocationInView);
#endif
#if PLATFORM(IOS_FAMILY)
    if (decoder.messageName() == Messages::WebPage::WillInsertFinalDictationResult::name())
        return IPC::handleMessage<Messages::WebPage::WillInsertFinalDictationResult>(connection, decoder, this, &WebPage::willInsertFinalDictationResult);
    if (decoder.messageName() == Messages::WebPage::DidInsertFinalDictationResult::name())
        return IPC::handleMessage<Messages::WebPage::DidInsertFinalDictationResult>(connection, decoder, this, &WebPage::didInsertFinalDictationResult);
    if (decoder.messageName() == Messages::WebPage::ReplaceDictatedText::name())
        return IPC::handleMessage<Messages::WebPage::ReplaceDictatedText>(connection, decoder, this, &WebPage::replaceDictatedText);
    if (decoder.messageName() == Messages::WebPage::ReplaceSelectedText::name())
        return IPC::handleMessage<Messages::WebPage::ReplaceSelectedText>(connection, decoder, this, &WebPage::replaceSelectedText);
    if (decoder.messageName() == Messages::WebPage::RequestAutocorrectionData::name())
        return IPC::handleMessageAsync<Messages::WebPage::RequestAutocorrectionData>(connection, decoder, this, &WebPage::requestAutocorrectionData);
    if (decoder.messageName() == Messages::WebPage::ApplyAutocorrection::name())
        return IPC::handleMessageAsync<Messages::WebPage::ApplyAutocorrection>(connection, decoder, this, &WebPage::applyAutocorrection);
    if (decoder.messageName() == Messages::WebPage::HandleAutocorrectionContextRequest::name())
        return IPC::handleMessage<Messages::WebPage::HandleAutocorrectionContextRequest>(connection, decoder, this, &WebPage::handleAutocorrectionContextRequest);
    if (decoder.messageName() == Messages::WebPage::RequestEvasionRectsAboveSelection::name())
        return IPC::handleMessageAsync<Messages::WebPage::RequestEvasionRectsAboveSelection>(connection, decoder, this, &WebPage::requestEvasionRectsAboveSelection);
    if (decoder.messageName() == Messages::WebPage::RequestPositionInformation::name())
        return IPC::handleMessage<Messages::WebPage::RequestPositionInformation>(connection, decoder, this, &WebPage::requestPositionInformation);
    if (decoder.messageName() == Messages::WebPage::StartInteractionWithElementContextOrPosition::name())
        return IPC::handleMessage<Messages::WebPage::StartInteractionWithElementContextOrPosition>(connection, decoder, this, &WebPage::startInteractionWithElementContextOrPosition);
    if (decoder.messageName() == Messages::WebPage::StopInteraction::name())
        return IPC::handleMessage<Messages::WebPage::StopInteraction>(connection, decoder, this, &WebPage::stopInteraction);
    if (decoder.messageName() == Messages::WebPage::PerformActionOnElement::name())
        return IPC::handleMessageAsync<Messages::WebPage::PerformActionOnElement>(connection, decoder, this, &WebPage::performActionOnElement);
    if (decoder.messageName() == Messages::WebPage::PerformActionOnElements::name())
        return IPC::handleMessage<Messages::WebPage::PerformActionOnElements>(connection, decoder, this, &WebPage::performActionOnElements);
    if (decoder.messageName() == Messages::WebPage::FocusNextFocusedElement::name())
        return IPC::handleMessageAsync<Messages::WebPage::FocusNextFocusedElement>(connection, decoder, this, &WebPage::focusNextFocusedElement);
    if (decoder.messageName() == Messages::WebPage::AutofillLoginCredentials::name())
        return IPC::handleMessage<Messages::WebPage::AutofillLoginCredentials>(connection, decoder, this, &WebPage::autofillLoginCredentials);
    if (decoder.messageName() == Messages::WebPage::SetFocusedElementValue::name())
        return IPC::handleMessage<Messages::WebPage::SetFocusedElementValue>(connection, decoder, this, &WebPage::setFocusedElementValue);
    if (decoder.messageName() == Messages::WebPage::SetFocusedElementSelectedIndex::name())
        return IPC::handleMessage<Messages::WebPage::SetFocusedElementSelectedIndex>(connection, decoder, this, &WebPage::setFocusedElementSelectedIndex);
    if (decoder.messageName() == Messages::WebPage::ApplicationWillResignActive::name())
        return IPC::handleMessage<Messages::WebPage::ApplicationWillResignActive>(connection, decoder, this, &WebPage::applicationWillResignActive);
    if (decoder.messageName() == Messages::WebPage::ApplicationDidEnterBackground::name())
        return IPC::handleMessage<Messages::WebPage::ApplicationDidEnterBackground>(connection, decoder, this, &WebPage::applicationDidEnterBackground);
    if (decoder.messageName() == Messages::WebPage::ApplicationDidFinishSnapshottingAfterEnteringBackground::name())
        return IPC::handleMessage<Messages::WebPage::ApplicationDidFinishSnapshottingAfterEnteringBackground>(connection, decoder, this, &WebPage::applicationDidFinishSnapshottingAfterEnteringBackground);
    if (decoder.messageName() == Messages::WebPage::ApplicationWillEnterForeground::name())
        return IPC::handleMessage<Messages::WebPage::ApplicationWillEnterForeground>(connection, decoder, this, &WebPage::applicationWillEnterForeground);
    if (decoder.messageName() == Messages::WebPage::ApplicationDidBecomeActive::name())
        return IPC::handleMessage<Messages::WebPage::ApplicationDidBecomeActive>(connection, decoder, this, &WebPage::applicationDidBecomeActive);
    if (decoder.messageName() == Messages::WebPage::ApplicationDidEnterBackgroundForMedia::name())
        return IPC::handleMessage<Messages::WebPage::ApplicationDidEnterBackgroundForMedia>(connection, decoder, this, &WebPage::applicationDidEnterBackgroundForMedia);
    if (decoder.messageName() == Messages::WebPage::ApplicationWillEnterForegroundForMedia::name())
        return IPC::handleMessage<Messages::WebPage::ApplicationWillEnterForegroundForMedia>(connection, decoder, this, &WebPage::applicationWillEnterForegroundForMedia);
    if (decoder.messageName() == Messages::WebPage::ContentSizeCategoryDidChange::name())
        return IPC::handleMessage<Messages::WebPage::ContentSizeCategoryDidChange>(connection, decoder, this, &WebPage::contentSizeCategoryDidChange);
    if (decoder.messageName() == Messages::WebPage::GetSelectionContext::name())
        return IPC::handleMessageAsync<Messages::WebPage::GetSelectionContext>(connection, decoder, this, &WebPage::getSelectionContext);
    if (decoder.messageName() == Messages::WebPage::SetAllowsMediaDocumentInlinePlayback::name())
        return IPC::handleMessage<Messages::WebPage::SetAllowsMediaDocumentInlinePlayback>(connection, decoder, this, &WebPage::setAllowsMediaDocumentInlinePlayback);
    if (decoder.messageName() == Messages::WebPage::HandleTwoFingerTapAtPoint::name())
        return IPC::handleMessage<Messages::WebPage::HandleTwoFingerTapAtPoint>(connection, decoder, this, &WebPage::handleTwoFingerTapAtPoint);
    if (decoder.messageName() == Messages::WebPage::SetForceAlwaysUserScalable::name())
        return IPC::handleMessage<Messages::WebPage::SetForceAlwaysUserScalable>(connection, decoder, this, &WebPage::setForceAlwaysUserScalable);
    if (decoder.messageName() == Messages::WebPage::GetRectsForGranularityWithSelectionOffset::name())
        return IPC::handleMessageAsync<Messages::WebPage::GetRectsForGranularityWithSelectionOffset>(connection, decoder, this, &WebPage::getRectsForGranularityWithSelectionOffset);
    if (decoder.messageName() == Messages::WebPage::GetRectsAtSelectionOffsetWithText::name())
        return IPC::handleMessageAsync<Messages::WebPage::GetRectsAtSelectionOffsetWithText>(connection, decoder, this, &WebPage::getRectsAtSelectionOffsetWithText);
    if (decoder.messageName() == Messages::WebPage::StoreSelectionForAccessibility::name())
        return IPC::handleMessage<Messages::WebPage::StoreSelectionForAccessibility>(connection, decoder, this, &WebPage::storeSelectionForAccessibility);
    if (decoder.messageName() == Messages::WebPage::StartAutoscrollAtPosition::name())
        return IPC::handleMessage<Messages::WebPage::StartAutoscrollAtPosition>(connection, decoder, this, &WebPage::startAutoscrollAtPosition);
    if (decoder.messageName() == Messages::WebPage::CancelAutoscroll::name())
        return IPC::handleMessage<Messages::WebPage::CancelAutoscroll>(connection, decoder, this, &WebPage::cancelAutoscroll);
    if (decoder.messageName() == Messages::WebPage::RequestFocusedElementInformation::name())
        return IPC::handleMessageAsync<Messages::WebPage::RequestFocusedElementInformation>(connection, decoder, this, &WebPage::requestFocusedElementInformation);
    if (decoder.messageName() == Messages::WebPage::HardwareKeyboardAvailabilityChanged::name())
        return IPC::handleMessage<Messages::WebPage::HardwareKeyboardAvailabilityChanged>(connection, decoder, this, &WebPage::hardwareKeyboardAvailabilityChanged);
    if (decoder.messageName() == Messages::WebPage::SetIsShowingInputViewForFocusedElement::name())
        return IPC::handleMessage<Messages::WebPage::SetIsShowingInputViewForFocusedElement>(connection, decoder, this, &WebPage::setIsShowingInputViewForFocusedElement);
    if (decoder.messageName() == Messages::WebPage::UpdateSelectionWithDelta::name())
        return IPC::handleMessageAsync<Messages::WebPage::UpdateSelectionWithDelta>(connection, decoder, this, &WebPage::updateSelectionWithDelta);
    if (decoder.messageName() == Messages::WebPage::RequestDocumentEditingContext::name())
        return IPC::handleMessageAsync<Messages::WebPage::RequestDocumentEditingContext>(connection, decoder, this, &WebPage::requestDocumentEditingContext);
    if (decoder.messageName() == Messages::WebPage::GenerateSyntheticEditingCommand::name())
        return IPC::handleMessage<Messages::WebPage::GenerateSyntheticEditingCommand>(connection, decoder, this, &WebPage::generateSyntheticEditingCommand);
    if (decoder.messageName() == Messages::WebPage::SetShouldRevealCurrentSelectionAfterInsertion::name())
        return IPC::handleMessage<Messages::WebPage::SetShouldRevealCurrentSelectionAfterInsertion>(connection, decoder, this, &WebPage::setShouldRevealCurrentSelectionAfterInsertion);
    if (decoder.messageName() == Messages::WebPage::TextInputContextsInRect::name())
        return IPC::handleMessageAsync<Messages::WebPage::TextInputContextsInRect>(connection, decoder, this, &WebPage::textInputContextsInRect);
    if (decoder.messageName() == Messages::WebPage::FocusTextInputContextAndPlaceCaret::name())
        return IPC::handleMessageAsync<Messages::WebPage::FocusTextInputContextAndPlaceCaret>(connection, decoder, this, &WebPage::focusTextInputContextAndPlaceCaret);
    if (decoder.messageName() == Messages::WebPage::ClearServiceWorkerEntitlementOverride::name())
        return IPC::handleMessageAsync<Messages::WebPage::ClearServiceWorkerEntitlementOverride>(connection, decoder, this, &WebPage::clearServiceWorkerEntitlementOverride);
#endif
    if (decoder.messageName() == Messages::WebPage::ProcessWillSuspend::name())
        return IPC::handleMessage<Messages::WebPage::ProcessWillSuspend>(connection, decoder, this, &WebPage::processWillSuspend);
    if (decoder.messageName() == Messages::WebPage::ProcessDidResume::name())
        return IPC::handleMessage<Messages::WebPage::ProcessDidResume>(connection, decoder, this, &WebPage::processDidResume);
    if (decoder.messageName() == Messages::WebPage::RequestImageBitmap::name())
        return IPC::handleMessageAsync<Messages::WebPage::RequestImageBitmap>(connection, decoder, this, &WebPage::requestImageBitmap);
    if (decoder.messageName() == Messages::WebPage::SetControlledByAutomation::name())
        return IPC::handleMessage<Messages::WebPage::SetControlledByAutomation>(connection, decoder, this, &WebPage::setControlledByAutomation);
    if (decoder.messageName() == Messages::WebPage::ConnectInspector::name())
        return IPC::handleMessage<Messages::WebPage::ConnectInspector>(connection, decoder, this, &WebPage::connectInspector);
    if (decoder.messageName() == Messages::WebPage::DisconnectInspector::name())
        return IPC::handleMessage<Messages::WebPage::DisconnectInspector>(connection, decoder, this, &WebPage::disconnectInspector);
    if (decoder.messageName() == Messages::WebPage::SendMessageToTargetBackend::name())
        return IPC::handleMessage<Messages::WebPage::SendMessageToTargetBackend>(connection, decoder, this, &WebPage::sendMessageToTargetBackend);
#if ENABLE(REMOTE_INSPECTOR)
    if (decoder.messageName() == Messages::WebPage::SetIndicating::name())
        return IPC::handleMessage<Messages::WebPage::SetIndicating>(connection, decoder, this, &WebPage::setIndicating);
#endif
#if ENABLE(IOS_TOUCH_EVENTS)
    if (decoder.messageName() == Messages::WebPage::DidBeginTouchPoint::name())
        return IPC::handleMessage<Messages::WebPage::DidBeginTouchPoint>(connection, decoder, this, &WebPage::didBeginTouchPoint);
#endif
#if !ENABLE(IOS_TOUCH_EVENTS) && ENABLE(TOUCH_EVENTS)
    if (decoder.messageName() == Messages::WebPage::TouchEvent::name())
        return IPC::handleMessageAsync<Messages::WebPage::TouchEvent>(connection, decoder, this, &WebPage::touchEvent);
#endif
    if (decoder.messageName() == Messages::WebPage::CancelPointer::name())
        return IPC::handleMessage<Messages::WebPage::CancelPointer>(connection, decoder, this, &WebPage::cancelPointer);
    if (decoder.messageName() == Messages::WebPage::TouchWithIdentifierWasRemoved::name())
        return IPC::handleMessage<Messages::WebPage::TouchWithIdentifierWasRemoved>(connection, decoder, this, &WebPage::touchWithIdentifierWasRemoved);
    if (decoder.messageName() == Messages::WebPage::DidEndColorPicker::name())
        return IPC::handleMessage<Messages::WebPage::DidEndColorPicker>(connection, decoder, this, &WebPage::didEndColorPicker);
    if (decoder.messageName() == Messages::WebPage::DidChooseColor::name())
        return IPC::handleMessage<Messages::WebPage::DidChooseColor>(connection, decoder, this, &WebPage::didChooseColor);
    if (decoder.messageName() == Messages::WebPage::DidSelectDataListOption::name())
        return IPC::handleMessage<Messages::WebPage::DidSelectDataListOption>(connection, decoder, this, &WebPage::didSelectDataListOption);
    if (decoder.messageName() == Messages::WebPage::DidCloseSuggestions::name())
        return IPC::handleMessage<Messages::WebPage::DidCloseSuggestions>(connection, decoder, this, &WebPage::didCloseSuggestions);
    if (decoder.messageName() == Messages::WebPage::DidChooseDate::name())
        return IPC::handleMessage<Messages::WebPage::DidChooseDate>(connection, decoder, this, &WebPage::didChooseDate);
    if (decoder.messageName() == Messages::WebPage::DidEndDateTimePicker::name())
        return IPC::handleMessage<Messages::WebPage::DidEndDateTimePicker>(connection, decoder, this, &WebPage::didEndDateTimePicker);
    if (decoder.messageName() == Messages::WebPage::ScrollBy::name())
        return IPC::handleMessage<Messages::WebPage::ScrollBy>(connection, decoder, this, &WebPage::scrollBy);
    if (decoder.messageName() == Messages::WebPage::CenterSelectionInVisibleArea::name())
        return IPC::handleMessage<Messages::WebPage::CenterSelectionInVisibleArea>(connection, decoder, this, &WebPage::centerSelectionInVisibleArea);
    if (decoder.messageName() == Messages::WebPage::GoToBackForwardItem::name())
        return IPC::handleMessage<Messages::WebPage::GoToBackForwardItem>(connection, decoder, this, &WebPage::goToBackForwardItem);
    if (decoder.messageName() == Messages::WebPage::GoToBackForwardItemWaitingForProcessLaunch::name())
        return IPC::handleMessage<Messages::WebPage::GoToBackForwardItemWaitingForProcessLaunch>(connection, decoder, this, &WebPage::goToBackForwardItemWaitingForProcessLaunch);
    if (decoder.messageName() == Messages::WebPage::TryRestoreScrollPosition::name())
        return IPC::handleMessage<Messages::WebPage::TryRestoreScrollPosition>(connection, decoder, this, &WebPage::tryRestoreScrollPosition);
    if (decoder.messageName() == Messages::WebPage::LoadURLInFrame::name())
        return IPC::handleMessage<Messages::WebPage::LoadURLInFrame>(connection, decoder, this, &WebPage::loadURLInFrame);
    if (decoder.messageName() == Messages::WebPage::LoadDataInFrame::name())
        return IPC::handleMessage<Messages::WebPage::LoadDataInFrame>(connection, decoder, this, &WebPage::loadDataInFrame);
    if (decoder.messageName() == Messages::WebPage::LoadRequest::name())
        return IPC::handleMessage<Messages::WebPage::LoadRequest>(connection, decoder, this, &WebPage::loadRequest);
    if (decoder.messageName() == Messages::WebPage::LoadDidCommitInAnotherProcess::name())
        return IPC::handleMessage<Messages::WebPage::LoadDidCommitInAnotherProcess>(connection, decoder, this, &WebPage::loadDidCommitInAnotherProcess);
    if (decoder.messageName() == Messages::WebPage::LoadRequestWaitingForProcessLaunch::name())
        return IPC::handleMessage<Messages::WebPage::LoadRequestWaitingForProcessLaunch>(connection, decoder, this, &WebPage::loadRequestWaitingForProcessLaunch);
    if (decoder.messageName() == Messages::WebPage::LoadData::name())
        return IPC::handleMessage<Messages::WebPage::LoadData>(connection, decoder, this, &WebPage::loadData);
    if (decoder.messageName() == Messages::WebPage::LoadSimulatedRequestAndResponse::name())
        return IPC::handleMessage<Messages::WebPage::LoadSimulatedRequestAndResponse>(connection, decoder, this, &WebPage::loadSimulatedRequestAndResponse);
    if (decoder.messageName() == Messages::WebPage::LoadAlternateHTML::name())
        return IPC::handleMessage<Messages::WebPage::LoadAlternateHTML>(connection, decoder, this, &WebPage::loadAlternateHTML);
    if (decoder.messageName() == Messages::WebPage::CreateRemoteSubframe::name())
        return IPC::handleMessage<Messages::WebPage::CreateRemoteSubframe>(connection, decoder, this, &WebPage::createRemoteSubframe);
    if (decoder.messageName() == Messages::WebPage::GetFrameTree::name())
        return IPC::handleMessageAsync<Messages::WebPage::GetFrameTree>(connection, decoder, this, &WebPage::getFrameTree);
    if (decoder.messageName() == Messages::WebPage::DidFinishLoadInAnotherProcess::name())
        return IPC::handleMessage<Messages::WebPage::DidFinishLoadInAnotherProcess>(connection, decoder, this, &WebPage::didFinishLoadInAnotherProcess);
    if (decoder.messageName() == Messages::WebPage::FrameWasRemovedInAnotherProcess::name())
        return IPC::handleMessage<Messages::WebPage::FrameWasRemovedInAnotherProcess>(connection, decoder, this, &WebPage::frameWasRemovedInAnotherProcess);
    if (decoder.messageName() == Messages::WebPage::UpdateFrameTreeSyncData::name())
        return IPC::handleMessage<Messages::WebPage::UpdateFrameTreeSyncData>(connection, decoder, this, &WebPage::updateFrameTreeSyncData);
    if (decoder.messageName() == Messages::WebPage::ProcessSyncDataChangedInAnotherProcess::name())
        return IPC::handleMessage<Messages::WebPage::ProcessSyncDataChangedInAnotherProcess>(connection, decoder, this, &WebPage::processSyncDataChangedInAnotherProcess);
    if (decoder.messageName() == Messages::WebPage::TopDocumentSyncDataChangedInAnotherProcess::name())
        return IPC::handleMessage<Messages::WebPage::TopDocumentSyncDataChangedInAnotherProcess>(connection, decoder, this, &WebPage::topDocumentSyncDataChangedInAnotherProcess);
    if (decoder.messageName() == Messages::WebPage::NavigateToPDFLinkWithSimulatedClick::name())
        return IPC::handleMessage<Messages::WebPage::NavigateToPDFLinkWithSimulatedClick>(connection, decoder, this, &WebPage::navigateToPDFLinkWithSimulatedClick);
    if (decoder.messageName() == Messages::WebPage::GetPDFFirstPageSize::name())
        return IPC::handleMessageAsync<Messages::WebPage::GetPDFFirstPageSize>(connection, decoder, this, &WebPage::getPDFFirstPageSize);
    if (decoder.messageName() == Messages::WebPage::Reload::name())
        return IPC::handleMessage<Messages::WebPage::Reload>(connection, decoder, this, &WebPage::reload);
    if (decoder.messageName() == Messages::WebPage::StopLoading::name())
        return IPC::handleMessage<Messages::WebPage::StopLoading>(connection, decoder, this, &WebPage::stopLoading);
    if (decoder.messageName() == Messages::WebPage::StopLoadingDueToProcessSwap::name())
        return IPC::handleMessage<Messages::WebPage::StopLoadingDueToProcessSwap>(connection, decoder, this, &WebPage::stopLoadingDueToProcessSwap);
    if (decoder.messageName() == Messages::WebPage::SetCurrentHistoryItemForReattach::name())
        return IPC::handleMessage<Messages::WebPage::SetCurrentHistoryItemForReattach>(connection, decoder, this, &WebPage::setCurrentHistoryItemForReattach);
    if (decoder.messageName() == Messages::WebPage::DidRemoveBackForwardItem::name())
        return IPC::handleMessage<Messages::WebPage::DidRemoveBackForwardItem>(connection, decoder, this, &WebPage::didRemoveBackForwardItem);
    if (decoder.messageName() == Messages::WebPage::UpdateWebsitePolicies::name())
        return IPC::handleMessage<Messages::WebPage::UpdateWebsitePolicies>(connection, decoder, this, &WebPage::updateWebsitePolicies);
    if (decoder.messageName() == Messages::WebPage::ClearSelection::name())
        return IPC::handleMessage<Messages::WebPage::ClearSelection>(connection, decoder, this, &WebPage::clearSelection);
    if (decoder.messageName() == Messages::WebPage::RestoreSelectionInFocusedEditableElement::name())
        return IPC::handleMessage<Messages::WebPage::RestoreSelectionInFocusedEditableElement>(connection, decoder, this, &WebPage::restoreSelectionInFocusedEditableElement);
    if (decoder.messageName() == Messages::WebPage::GetContentsAsString::name())
        return IPC::handleMessageAsync<Messages::WebPage::GetContentsAsString>(connection, decoder, this, &WebPage::getContentsAsString);
#if PLATFORM(COCOA)
    if (decoder.messageName() == Messages::WebPage::GetContentsAsAttributedString::name())
        return IPC::handleMessageAsync<Messages::WebPage::GetContentsAsAttributedString>(connection, decoder, this, &WebPage::getContentsAsAttributedString);
#endif
#if ENABLE(MHTML)
    if (decoder.messageName() == Messages::WebPage::GetContentsAsMHTMLData::name())
        return IPC::handleMessageAsync<Messages::WebPage::GetContentsAsMHTMLData>(connection, decoder, this, &WebPage::getContentsAsMHTMLData);
#endif
    if (decoder.messageName() == Messages::WebPage::GetMainResourceDataOfFrame::name())
        return IPC::handleMessageAsync<Messages::WebPage::GetMainResourceDataOfFrame>(connection, decoder, this, &WebPage::getMainResourceDataOfFrame);
    if (decoder.messageName() == Messages::WebPage::GetResourceDataFromFrame::name())
        return IPC::handleMessageAsync<Messages::WebPage::GetResourceDataFromFrame>(connection, decoder, this, &WebPage::getResourceDataFromFrame);
    if (decoder.messageName() == Messages::WebPage::GetRenderTreeExternalRepresentation::name())
        return IPC::handleMessageAsync<Messages::WebPage::GetRenderTreeExternalRepresentation>(connection, decoder, this, &WebPage::getRenderTreeExternalRepresentation);
    if (decoder.messageName() == Messages::WebPage::GetSelectionOrContentsAsString::name())
        return IPC::handleMessageAsync<Messages::WebPage::GetSelectionOrContentsAsString>(connection, decoder, this, &WebPage::getSelectionOrContentsAsString);
    if (decoder.messageName() == Messages::WebPage::GetSelectionAsWebArchiveData::name())
        return IPC::handleMessageAsync<Messages::WebPage::GetSelectionAsWebArchiveData>(connection, decoder, this, &WebPage::getSelectionAsWebArchiveData);
    if (decoder.messageName() == Messages::WebPage::GetSourceForFrame::name())
        return IPC::handleMessageAsync<Messages::WebPage::GetSourceForFrame>(connection, decoder, this, &WebPage::getSourceForFrame);
    if (decoder.messageName() == Messages::WebPage::GetWebArchiveOfFrame::name())
        return IPC::handleMessageAsync<Messages::WebPage::GetWebArchiveOfFrame>(connection, decoder, this, &WebPage::getWebArchiveOfFrame);
    if (decoder.messageName() == Messages::WebPage::GetWebArchiveOfFrameWithFileName::name())
        return IPC::handleMessageAsync<Messages::WebPage::GetWebArchiveOfFrameWithFileName>(connection, decoder, this, &WebPage::getWebArchiveOfFrameWithFileName);
#if PLATFORM(COCOA)
    if (decoder.messageName() == Messages::WebPage::GetWebArchives::name())
        return IPC::handleMessageAsync<Messages::WebPage::GetWebArchives>(connection, decoder, this, &WebPage::getWebArchives);
#endif
    if (decoder.messageName() == Messages::WebPage::RunJavaScriptInFrameInScriptWorld::name())
        return IPC::handleMessageAsync<Messages::WebPage::RunJavaScriptInFrameInScriptWorld>(connection, decoder, this, &WebPage::runJavaScriptInFrameInScriptWorld);
    if (decoder.messageName() == Messages::WebPage::GetAccessibilityTreeData::name())
        return IPC::handleMessageAsync<Messages::WebPage::GetAccessibilityTreeData>(connection, decoder, this, &WebPage::getAccessibilityTreeData);
    if (decoder.messageName() == Messages::WebPage::UpdateRenderingWithForcedRepaint::name())
        return IPC::handleMessageAsync<Messages::WebPage::UpdateRenderingWithForcedRepaint>(connection, decoder, this, &WebPage::updateRenderingWithForcedRepaint);
    if (decoder.messageName() == Messages::WebPage::SelectAll::name())
        return IPC::handleMessage<Messages::WebPage::SelectAll>(connection, decoder, this, &WebPage::selectAll);
    if (decoder.messageName() == Messages::WebPage::ScheduleFullEditorStateUpdate::name())
        return IPC::handleMessage<Messages::WebPage::ScheduleFullEditorStateUpdate>(connection, decoder, this, &WebPage::scheduleFullEditorStateUpdate);
#if PLATFORM(COCOA)
    if (decoder.messageName() == Messages::WebPage::PerformDictionaryLookupAtLocation::name())
        return IPC::handleMessage<Messages::WebPage::PerformDictionaryLookupAtLocation>(connection, decoder, this, &WebPage::performDictionaryLookupAtLocation);
#endif
#if ENABLE(DATA_DETECTION)
    if (decoder.messageName() == Messages::WebPage::DetectDataInAllFrames::name())
        return IPC::handleMessageAsync<Messages::WebPage::DetectDataInAllFrames>(connection, decoder, this, &WebPage::detectDataInAllFrames);
    if (decoder.messageName() == Messages::WebPage::RemoveDataDetectedLinks::name())
        return IPC::handleMessageAsync<Messages::WebPage::RemoveDataDetectedLinks>(connection, decoder, this, &WebPage::removeDataDetectedLinks);
#endif
    if (decoder.messageName() == Messages::WebPage::ChangeFont::name())
        return IPC::handleMessage<Messages::WebPage::ChangeFont>(connection, decoder, this, &WebPage::changeFont);
    if (decoder.messageName() == Messages::WebPage::ChangeFontAttributes::name())
        return IPC::handleMessage<Messages::WebPage::ChangeFontAttributes>(connection, decoder, this, &WebPage::changeFontAttributes);
    if (decoder.messageName() == Messages::WebPage::PreferencesDidChange::name())
        return IPC::handleMessage<Messages::WebPage::PreferencesDidChange>(connection, decoder, this, &WebPage::preferencesDidChange);
    if (decoder.messageName() == Messages::WebPage::PreferencesDidChangeDuringDOMPrintOperation::name())
        return IPC::handleMessage<Messages::WebPage::PreferencesDidChangeDuringDOMPrintOperation>(connection, decoder, this, &WebPage::preferencesDidChangeDuringDOMPrintOperation);
    if (decoder.messageName() == Messages::WebPage::SetUserAgent::name())
        return IPC::handleMessage<Messages::WebPage::SetUserAgent>(connection, decoder, this, &WebPage::setUserAgent);
    if (decoder.messageName() == Messages::WebPage::SetHasCustomUserAgent::name())
        return IPC::handleMessage<Messages::WebPage::SetHasCustomUserAgent>(connection, decoder, this, &WebPage::setHasCustomUserAgent);
    if (decoder.messageName() == Messages::WebPage::SetCustomTextEncodingName::name())
        return IPC::handleMessage<Messages::WebPage::SetCustomTextEncodingName>(connection, decoder, this, &WebPage::setCustomTextEncodingName);
    if (decoder.messageName() == Messages::WebPage::SuspendActiveDOMObjectsAndAnimations::name())
        return IPC::handleMessage<Messages::WebPage::SuspendActiveDOMObjectsAndAnimations>(connection, decoder, this, &WebPage::suspendActiveDOMObjectsAndAnimations);
    if (decoder.messageName() == Messages::WebPage::ResumeActiveDOMObjectsAndAnimations::name())
        return IPC::handleMessage<Messages::WebPage::ResumeActiveDOMObjectsAndAnimations>(connection, decoder, this, &WebPage::resumeActiveDOMObjectsAndAnimations);
    if (decoder.messageName() == Messages::WebPage::Suspend::name())
        return IPC::handleMessageAsync<Messages::WebPage::Suspend>(connection, decoder, this, &WebPage::suspend);
    if (decoder.messageName() == Messages::WebPage::Resume::name())
        return IPC::handleMessageAsync<Messages::WebPage::Resume>(connection, decoder, this, &WebPage::resume);
    if (decoder.messageName() == Messages::WebPage::Close::name())
        return IPC::handleMessage<Messages::WebPage::Close>(connection, decoder, this, &WebPage::close);
    if (decoder.messageName() == Messages::WebPage::TryClose::name())
        return IPC::handleMessageAsync<Messages::WebPage::TryClose>(connection, decoder, this, &WebPage::tryClose);
    if (decoder.messageName() == Messages::WebPage::SetEditable::name())
        return IPC::handleMessage<Messages::WebPage::SetEditable>(connection, decoder, this, &WebPage::setEditable);
    if (decoder.messageName() == Messages::WebPage::ValidateCommand::name())
        return IPC::handleMessageAsync<Messages::WebPage::ValidateCommand>(connection, decoder, this, &WebPage::validateCommand);
    if (decoder.messageName() == Messages::WebPage::ExecuteEditCommand::name())
        return IPC::handleMessage<Messages::WebPage::ExecuteEditCommand>(connection, decoder, this, &WebPage::executeEditCommand);
    if (decoder.messageName() == Messages::WebPage::IncreaseListLevel::name())
        return IPC::handleMessage<Messages::WebPage::IncreaseListLevel>(connection, decoder, this, &WebPage::increaseListLevel);
    if (decoder.messageName() == Messages::WebPage::DecreaseListLevel::name())
        return IPC::handleMessage<Messages::WebPage::DecreaseListLevel>(connection, decoder, this, &WebPage::decreaseListLevel);
    if (decoder.messageName() == Messages::WebPage::ChangeListType::name())
        return IPC::handleMessage<Messages::WebPage::ChangeListType>(connection, decoder, this, &WebPage::changeListType);
    if (decoder.messageName() == Messages::WebPage::SetBaseWritingDirection::name())
        return IPC::handleMessage<Messages::WebPage::SetBaseWritingDirection>(connection, decoder, this, &WebPage::setBaseWritingDirection);
    if (decoder.messageName() == Messages::WebPage::SetNeedsFontAttributes::name())
        return IPC::handleMessage<Messages::WebPage::SetNeedsFontAttributes>(connection, decoder, this, &WebPage::setNeedsFontAttributes);
    if (decoder.messageName() == Messages::WebPage::RequestFontAttributesAtSelectionStart::name())
        return IPC::handleMessageAsync<Messages::WebPage::RequestFontAttributesAtSelectionStart>(connection, decoder, this, &WebPage::requestFontAttributesAtSelectionStart);
    if (decoder.messageName() == Messages::WebPage::DidRemoveEditCommand::name())
        return IPC::handleMessage<Messages::WebPage::DidRemoveEditCommand>(connection, decoder, this, &WebPage::didRemoveEditCommand);
    if (decoder.messageName() == Messages::WebPage::ReapplyEditCommand::name())
        return IPC::handleMessage<Messages::WebPage::ReapplyEditCommand>(connection, decoder, this, &WebPage::reapplyEditCommand);
    if (decoder.messageName() == Messages::WebPage::UnapplyEditCommand::name())
        return IPC::handleMessage<Messages::WebPage::UnapplyEditCommand>(connection, decoder, this, &WebPage::unapplyEditCommand);
    if (decoder.messageName() == Messages::WebPage::DidSetPageZoomFactor::name())
        return IPC::handleMessage<Messages::WebPage::DidSetPageZoomFactor>(connection, decoder, this, &WebPage::didSetPageZoomFactor);
    if (decoder.messageName() == Messages::WebPage::DidSetTextZoomFactor::name())
        return IPC::handleMessage<Messages::WebPage::DidSetTextZoomFactor>(connection, decoder, this, &WebPage::didSetTextZoomFactor);
    if (decoder.messageName() == Messages::WebPage::WindowScreenDidChange::name())
        return IPC::handleMessage<Messages::WebPage::WindowScreenDidChange>(connection, decoder, this, &WebPage::windowScreenDidChange);
    if (decoder.messageName() == Messages::WebPage::AccessibilitySettingsDidChange::name())
        return IPC::handleMessage<Messages::WebPage::AccessibilitySettingsDidChange>(connection, decoder, this, &WebPage::accessibilitySettingsDidChange);
    if (decoder.messageName() == Messages::WebPage::DidScalePage::name())
        return IPC::handleMessage<Messages::WebPage::DidScalePage>(connection, decoder, this, &WebPage::didScalePage);
    if (decoder.messageName() == Messages::WebPage::DidScalePageInViewCoordinates::name())
        return IPC::handleMessage<Messages::WebPage::DidScalePageInViewCoordinates>(connection, decoder, this, &WebPage::didScalePageInViewCoordinates);
    if (decoder.messageName() == Messages::WebPage::DidScalePageRelativeToScrollPosition::name())
        return IPC::handleMessage<Messages::WebPage::DidScalePageRelativeToScrollPosition>(connection, decoder, this, &WebPage::didScalePageRelativeToScrollPosition);
    if (decoder.messageName() == Messages::WebPage::DidScaleView::name())
        return IPC::handleMessage<Messages::WebPage::DidScaleView>(connection, decoder, this, &WebPage::didScaleView);
    if (decoder.messageName() == Messages::WebPage::SetUseFixedLayout::name())
        return IPC::handleMessage<Messages::WebPage::SetUseFixedLayout>(connection, decoder, this, &WebPage::setUseFixedLayout);
    if (decoder.messageName() == Messages::WebPage::SetFixedLayoutSize::name())
        return IPC::handleMessage<Messages::WebPage::SetFixedLayoutSize>(connection, decoder, this, &WebPage::setFixedLayoutSize);
    if (decoder.messageName() == Messages::WebPage::SetDefaultUnobscuredSize::name())
        return IPC::handleMessage<Messages::WebPage::SetDefaultUnobscuredSize>(connection, decoder, this, &WebPage::setDefaultUnobscuredSize);
    if (decoder.messageName() == Messages::WebPage::SetMinimumUnobscuredSize::name())
        return IPC::handleMessage<Messages::WebPage::SetMinimumUnobscuredSize>(connection, decoder, this, &WebPage::setMinimumUnobscuredSize);
    if (decoder.messageName() == Messages::WebPage::SetMaximumUnobscuredSize::name())
        return IPC::handleMessage<Messages::WebPage::SetMaximumUnobscuredSize>(connection, decoder, this, &WebPage::setMaximumUnobscuredSize);
    if (decoder.messageName() == Messages::WebPage::ListenForLayoutMilestones::name())
        return IPC::handleMessage<Messages::WebPage::ListenForLayoutMilestones>(connection, decoder, this, &WebPage::listenForLayoutMilestones);
    if (decoder.messageName() == Messages::WebPage::SetSuppressScrollbarAnimations::name())
        return IPC::handleMessage<Messages::WebPage::SetSuppressScrollbarAnimations>(connection, decoder, this, &WebPage::setSuppressScrollbarAnimations);
    if (decoder.messageName() == Messages::WebPage::SetEnableVerticalRubberBanding::name())
        return IPC::handleMessage<Messages::WebPage::SetEnableVerticalRubberBanding>(connection, decoder, this, &WebPage::setEnableVerticalRubberBanding);
    if (decoder.messageName() == Messages::WebPage::SetEnableHorizontalRubberBanding::name())
        return IPC::handleMessage<Messages::WebPage::SetEnableHorizontalRubberBanding>(connection, decoder, this, &WebPage::setEnableHorizontalRubberBanding);
    if (decoder.messageName() == Messages::WebPage::SetBackgroundExtendsBeyondPage::name())
        return IPC::handleMessage<Messages::WebPage::SetBackgroundExtendsBeyondPage>(connection, decoder, this, &WebPage::setBackgroundExtendsBeyondPage);
    if (decoder.messageName() == Messages::WebPage::SetPaginationMode::name())
        return IPC::handleMessage<Messages::WebPage::SetPaginationMode>(connection, decoder, this, &WebPage::setPaginationMode);
    if (decoder.messageName() == Messages::WebPage::SetPaginationBehavesLikeColumns::name())
        return IPC::handleMessage<Messages::WebPage::SetPaginationBehavesLikeColumns>(connection, decoder, this, &WebPage::setPaginationBehavesLikeColumns);
    if (decoder.messageName() == Messages::WebPage::SetPageLength::name())
        return IPC::handleMessage<Messages::WebPage::SetPageLength>(connection, decoder, this, &WebPage::setPageLength);
    if (decoder.messageName() == Messages::WebPage::SetGapBetweenPages::name())
        return IPC::handleMessage<Messages::WebPage::SetGapBetweenPages>(connection, decoder, this, &WebPage::setGapBetweenPages);
    if (decoder.messageName() == Messages::WebPage::PostInjectedBundleMessage::name())
        return IPC::handleMessage<Messages::WebPage::PostInjectedBundleMessage>(connection, decoder, this, &WebPage::postInjectedBundleMessage);
    if (decoder.messageName() == Messages::WebPage::FindString::name())
        return IPC::handleMessageAsync<Messages::WebPage::FindString>(connection, decoder, this, &WebPage::findString);
#if ENABLE(IMAGE_ANALYSIS)
    if (decoder.messageName() == Messages::WebPage::FindStringIncludingImages::name())
        return IPC::handleMessageAsync<Messages::WebPage::FindStringIncludingImages>(connection, decoder, this, &WebPage::findStringIncludingImages);
#endif
    if (decoder.messageName() == Messages::WebPage::FindStringMatches::name())
        return IPC::handleMessageAsync<Messages::WebPage::FindStringMatches>(connection, decoder, this, &WebPage::findStringMatches);
    if (decoder.messageName() == Messages::WebPage::GetImageForFindMatch::name())
        return IPC::handleMessage<Messages::WebPage::GetImageForFindMatch>(connection, decoder, this, &WebPage::getImageForFindMatch);
    if (decoder.messageName() == Messages::WebPage::SelectFindMatch::name())
        return IPC::handleMessage<Messages::WebPage::SelectFindMatch>(connection, decoder, this, &WebPage::selectFindMatch);
    if (decoder.messageName() == Messages::WebPage::IndicateFindMatch::name())
        return IPC::handleMessage<Messages::WebPage::IndicateFindMatch>(connection, decoder, this, &WebPage::indicateFindMatch);
    if (decoder.messageName() == Messages::WebPage::HideFindUI::name())
        return IPC::handleMessage<Messages::WebPage::HideFindUI>(connection, decoder, this, &WebPage::hideFindUI);
    if (decoder.messageName() == Messages::WebPage::CountStringMatches::name())
        return IPC::handleMessageAsync<Messages::WebPage::CountStringMatches>(connection, decoder, this, &WebPage::countStringMatches);
    if (decoder.messageName() == Messages::WebPage::ReplaceMatches::name())
        return IPC::handleMessageAsync<Messages::WebPage::ReplaceMatches>(connection, decoder, this, &WebPage::replaceMatches);
    if (decoder.messageName() == Messages::WebPage::FindRectsForStringMatches::name())
        return IPC::handleMessageAsync<Messages::WebPage::FindRectsForStringMatches>(connection, decoder, this, &WebPage::findRectsForStringMatches);
    if (decoder.messageName() == Messages::WebPage::FindTextRangesForStringMatches::name())
        return IPC::handleMessageAsync<Messages::WebPage::FindTextRangesForStringMatches>(connection, decoder, this, &WebPage::findTextRangesForStringMatches);
    if (decoder.messageName() == Messages::WebPage::ReplaceFoundTextRangeWithString::name())
        return IPC::handleMessage<Messages::WebPage::ReplaceFoundTextRangeWithString>(connection, decoder, this, &WebPage::replaceFoundTextRangeWithString);
    if (decoder.messageName() == Messages::WebPage::DecorateTextRangeWithStyle::name())
        return IPC::handleMessage<Messages::WebPage::DecorateTextRangeWithStyle>(connection, decoder, this, &WebPage::decorateTextRangeWithStyle);
    if (decoder.messageName() == Messages::WebPage::ScrollTextRangeToVisible::name())
        return IPC::handleMessage<Messages::WebPage::ScrollTextRangeToVisible>(connection, decoder, this, &WebPage::scrollTextRangeToVisible);
    if (decoder.messageName() == Messages::WebPage::ClearAllDecoratedFoundText::name())
        return IPC::handleMessage<Messages::WebPage::ClearAllDecoratedFoundText>(connection, decoder, this, &WebPage::clearAllDecoratedFoundText);
    if (decoder.messageName() == Messages::WebPage::DidBeginTextSearchOperation::name())
        return IPC::handleMessage<Messages::WebPage::DidBeginTextSearchOperation>(connection, decoder, this, &WebPage::didBeginTextSearchOperation);
    if (decoder.messageName() == Messages::WebPage::RequestRectForFoundTextRange::name())
        return IPC::handleMessageAsync<Messages::WebPage::RequestRectForFoundTextRange>(connection, decoder, this, &WebPage::requestRectForFoundTextRange);
    if (decoder.messageName() == Messages::WebPage::AddLayerForFindOverlay::name())
        return IPC::handleMessageAsync<Messages::WebPage::AddLayerForFindOverlay>(connection, decoder, this, &WebPage::addLayerForFindOverlay);
    if (decoder.messageName() == Messages::WebPage::RemoveLayerForFindOverlay::name())
        return IPC::handleMessageAsync<Messages::WebPage::RemoveLayerForFindOverlay>(connection, decoder, this, &WebPage::removeLayerForFindOverlay);
#if PLATFORM(GTK) && ENABLE(DRAG_SUPPORT)
    if (decoder.messageName() == Messages::WebPage::PerformDragControllerAction::name())
        return IPC::handleMessageAsync<Messages::WebPage::PerformDragControllerAction>(connection, decoder, this, &WebPage::performDragControllerAction);
#endif
#if !PLATFORM(GTK) && ENABLE(DRAG_SUPPORT)
    if (decoder.messageName() == Messages::WebPage::PerformDragControllerAction::name())
        return IPC::handleMessageAsync<Messages::WebPage::PerformDragControllerAction>(connection, decoder, this, &WebPage::performDragControllerAction);
    if (decoder.messageName() == Messages::WebPage::PerformDragOperation::name())
        return IPC::handleMessageAsync<Messages::WebPage::PerformDragOperation>(connection, decoder, this, &WebPage::performDragOperation);
#endif
#if ENABLE(DRAG_SUPPORT)
    if (decoder.messageName() == Messages::WebPage::DidStartDrag::name())
        return IPC::handleMessage<Messages::WebPage::DidStartDrag>(connection, decoder, this, &WebPage::didStartDrag);
    if (decoder.messageName() == Messages::WebPage::DragEnded::name())
        return IPC::handleMessageAsync<Messages::WebPage::DragEnded>(connection, decoder, this, &WebPage::dragEnded);
    if (decoder.messageName() == Messages::WebPage::DragCancelled::name())
        return IPC::handleMessage<Messages::WebPage::DragCancelled>(connection, decoder, this, &WebPage::dragCancelled);
#endif
#if ENABLE(MODEL_PROCESS)
    if (decoder.messageName() == Messages::WebPage::RequestInteractiveModelElementAtPoint::name())
        return IPC::handleMessage<Messages::WebPage::RequestInteractiveModelElementAtPoint>(connection, decoder, this, &WebPage::requestInteractiveModelElementAtPoint);
    if (decoder.messageName() == Messages::WebPage::StageModeSessionDidUpdate::name())
        return IPC::handleMessage<Messages::WebPage::StageModeSessionDidUpdate>(connection, decoder, this, &WebPage::stageModeSessionDidUpdate);
    if (decoder.messageName() == Messages::WebPage::StageModeSessionDidEnd::name())
        return IPC::handleMessage<Messages::WebPage::StageModeSessionDidEnd>(connection, decoder, this, &WebPage::stageModeSessionDidEnd);
#endif
#if ENABLE(MODEL_PROCESS) && ENABLE(DRAG_SUPPORT)
    if (decoder.messageName() == Messages::WebPage::ModelDragEnded::name())
        return IPC::handleMessage<Messages::WebPage::ModelDragEnded>(connection, decoder, this, &WebPage::modelDragEnded);
#endif
#if PLATFORM(IOS_FAMILY) && ENABLE(DRAG_SUPPORT)
    if (decoder.messageName() == Messages::WebPage::RequestDragStart::name())
        return IPC::handleMessageAsync<Messages::WebPage::RequestDragStart>(connection, decoder, this, &WebPage::requestDragStart);
    if (decoder.messageName() == Messages::WebPage::RequestAdditionalItemsForDragSession::name())
        return IPC::handleMessageAsync<Messages::WebPage::RequestAdditionalItemsForDragSession>(connection, decoder, this, &WebPage::requestAdditionalItemsForDragSession);
    if (decoder.messageName() == Messages::WebPage::InsertDroppedImagePlaceholders::name())
        return IPC::handleMessageAsync<Messages::WebPage::InsertDroppedImagePlaceholders>(connection, decoder, this, &WebPage::insertDroppedImagePlaceholders);
    if (decoder.messageName() == Messages::WebPage::DidConcludeDrop::name())
        return IPC::handleMessage<Messages::WebPage::DidConcludeDrop>(connection, decoder, this, &WebPage::didConcludeDrop);
#endif
#if PLATFORM(COCOA)
    if (decoder.messageName() == Messages::WebPage::InsertTextPlaceholder::name())
        return IPC::handleMessageAsync<Messages::WebPage::InsertTextPlaceholder>(connection, decoder, this, &WebPage::insertTextPlaceholder);
    if (decoder.messageName() == Messages::WebPage::RemoveTextPlaceholder::name())
        return IPC::handleMessageAsync<Messages::WebPage::RemoveTextPlaceholder>(connection, decoder, this, &WebPage::removeTextPlaceholder);
#endif
    if (decoder.messageName() == Messages::WebPage::DidChangeSelectedIndexForActivePopupMenu::name())
        return IPC::handleMessage<Messages::WebPage::DidChangeSelectedIndexForActivePopupMenu>(connection, decoder, this, &WebPage::didChangeSelectedIndexForActivePopupMenu);
    if (decoder.messageName() == Messages::WebPage::SetTextForActivePopupMenu::name())
        return IPC::handleMessage<Messages::WebPage::SetTextForActivePopupMenu>(connection, decoder, this, &WebPage::setTextForActivePopupMenu);
#if PLATFORM(GTK)
    if (decoder.messageName() == Messages::WebPage::FailedToShowPopupMenu::name())
        return IPC::handleMessage<Messages::WebPage::FailedToShowPopupMenu>(connection, decoder, this, &WebPage::failedToShowPopupMenu);
#endif
#if ENABLE(CONTEXT_MENUS)
    if (decoder.messageName() == Messages::WebPage::DidDismissContextMenu::name())
        return IPC::handleMessage<Messages::WebPage::DidDismissContextMenu>(connection, decoder, this, &WebPage::didDismissContextMenu);
    if (decoder.messageName() == Messages::WebPage::DidSelectItemFromActiveContextMenu::name())
        return IPC::handleMessage<Messages::WebPage::DidSelectItemFromActiveContextMenu>(connection, decoder, this, &WebPage::didSelectItemFromActiveContextMenu);
    if (decoder.messageName() == Messages::WebPage::ContextMenuForKeyEvent::name())
        return IPC::handleMessage<Messages::WebPage::ContextMenuForKeyEvent>(connection, decoder, this, &WebPage::contextMenuForKeyEvent);
#endif
#if PLATFORM(IOS_FAMILY)
    if (decoder.messageName() == Messages::WebPage::DidChooseFilesForOpenPanelWithDisplayStringAndIcon::name())
        return IPC::handleMessage<Messages::WebPage::DidChooseFilesForOpenPanelWithDisplayStringAndIcon>(connection, decoder, this, &WebPage::didChooseFilesForOpenPanelWithDisplayStringAndIcon);
#endif
    if (decoder.messageName() == Messages::WebPage::DidChooseFilesForOpenPanel::name())
        return IPC::handleMessage<Messages::WebPage::DidChooseFilesForOpenPanel>(connection, decoder, this, &WebPage::didChooseFilesForOpenPanel);
    if (decoder.messageName() == Messages::WebPage::DidCancelForOpenPanel::name())
        return IPC::handleMessage<Messages::WebPage::DidCancelForOpenPanel>(connection, decoder, this, &WebPage::didCancelForOpenPanel);
#if ENABLE(SANDBOX_EXTENSIONS)
    if (decoder.messageName() == Messages::WebPage::ExtendSandboxForFilesFromOpenPanel::name())
        return IPC::handleMessage<Messages::WebPage::ExtendSandboxForFilesFromOpenPanel>(connection, decoder, this, &WebPage::extendSandboxForFilesFromOpenPanel);
#endif
    if (decoder.messageName() == Messages::WebPage::AdvanceToNextMisspelling::name())
        return IPC::handleMessage<Messages::WebPage::AdvanceToNextMisspelling>(connection, decoder, this, &WebPage::advanceToNextMisspelling);
    if (decoder.messageName() == Messages::WebPage::ChangeSpellingToWord::name())
        return IPC::handleMessage<Messages::WebPage::ChangeSpellingToWord>(connection, decoder, this, &WebPage::changeSpellingToWord);
    if (decoder.messageName() == Messages::WebPage::DidFinishCheckingText::name())
        return IPC::handleMessage<Messages::WebPage::DidFinishCheckingText>(connection, decoder, this, &WebPage::didFinishCheckingText);
    if (decoder.messageName() == Messages::WebPage::DidCancelCheckingText::name())
        return IPC::handleMessage<Messages::WebPage::DidCancelCheckingText>(connection, decoder, this, &WebPage::didCancelCheckingText);
#if USE(APPKIT)
    if (decoder.messageName() == Messages::WebPage::UppercaseWord::name())
        return IPC::handleMessage<Messages::WebPage::UppercaseWord>(connection, decoder, this, &WebPage::uppercaseWord);
    if (decoder.messageName() == Messages::WebPage::LowercaseWord::name())
        return IPC::handleMessage<Messages::WebPage::LowercaseWord>(connection, decoder, this, &WebPage::lowercaseWord);
    if (decoder.messageName() == Messages::WebPage::CapitalizeWord::name())
        return IPC::handleMessage<Messages::WebPage::CapitalizeWord>(connection, decoder, this, &WebPage::capitalizeWord);
#endif
#if PLATFORM(COCOA)
    if (decoder.messageName() == Messages::WebPage::SetSmartInsertDeleteEnabled::name())
        return IPC::handleMessage<Messages::WebPage::SetSmartInsertDeleteEnabled>(connection, decoder, this, &WebPage::setSmartInsertDeleteEnabled);
#endif
#if ENABLE(GEOLOCATION)
    if (decoder.messageName() == Messages::WebPage::DidReceiveGeolocationPermissionDecision::name())
        return IPC::handleMessage<Messages::WebPage::DidReceiveGeolocationPermissionDecision>(connection, decoder, this, &WebPage::didReceiveGeolocationPermissionDecision);
#endif
#if ENABLE(MEDIA_STREAM)
    if (decoder.messageName() == Messages::WebPage::UserMediaAccessWasGranted::name())
        return IPC::handleMessageAsync<Messages::WebPage::UserMediaAccessWasGranted>(connection, decoder, this, &WebPage::userMediaAccessWasGranted);
    if (decoder.messageName() == Messages::WebPage::UserMediaAccessWasDenied::name())
        return IPC::handleMessage<Messages::WebPage::UserMediaAccessWasDenied>(connection, decoder, this, &WebPage::userMediaAccessWasDenied);
    if (decoder.messageName() == Messages::WebPage::CaptureDevicesChanged::name())
        return IPC::handleMessage<Messages::WebPage::CaptureDevicesChanged>(connection, decoder, this, &WebPage::captureDevicesChanged);
    if (decoder.messageName() == Messages::WebPage::VoiceActivityDetected::name())
        return IPC::handleMessage<Messages::WebPage::VoiceActivityDetected>(connection, decoder, this, &WebPage::voiceActivityDetected);
#endif
#if (ENABLE(MEDIA_STREAM) && USE(GSTREAMER))
    if (decoder.messageName() == Messages::WebPage::SetOrientationForMediaCapture::name())
        return IPC::handleMessage<Messages::WebPage::SetOrientationForMediaCapture>(connection, decoder, this, &WebPage::setOrientationForMediaCapture);
    if (decoder.messageName() == Messages::WebPage::SetMockCaptureDevicesInterrupted::name())
        return IPC::handleMessage<Messages::WebPage::SetMockCaptureDevicesInterrupted>(connection, decoder, this, &WebPage::setMockCaptureDevicesInterrupted);
    if (decoder.messageName() == Messages::WebPage::TriggerMockCaptureConfigurationChange::name())
        return IPC::handleMessage<Messages::WebPage::TriggerMockCaptureConfigurationChange>(connection, decoder, this, &WebPage::triggerMockCaptureConfigurationChange);
#endif
#if ENABLE(ENCRYPTED_MEDIA)
    if (decoder.messageName() == Messages::WebPage::MediaKeySystemWasGranted::name())
        return IPC::handleMessage<Messages::WebPage::MediaKeySystemWasGranted>(connection, decoder, this, &WebPage::mediaKeySystemWasGranted);
    if (decoder.messageName() == Messages::WebPage::MediaKeySystemWasDenied::name())
        return IPC::handleMessage<Messages::WebPage::MediaKeySystemWasDenied>(connection, decoder, this, &WebPage::mediaKeySystemWasDenied);
#endif
    if (decoder.messageName() == Messages::WebPage::RequestMediaPlaybackState::name())
        return IPC::handleMessageAsync<Messages::WebPage::RequestMediaPlaybackState>(connection, decoder, this, &WebPage::requestMediaPlaybackState);
    if (decoder.messageName() == Messages::WebPage::PauseAllMediaPlayback::name())
        return IPC::handleMessageAsync<Messages::WebPage::PauseAllMediaPlayback>(connection, decoder, this, &WebPage::pauseAllMediaPlayback);
    if (decoder.messageName() == Messages::WebPage::SuspendAllMediaPlayback::name())
        return IPC::handleMessageAsync<Messages::WebPage::SuspendAllMediaPlayback>(connection, decoder, this, &WebPage::suspendAllMediaPlayback);
    if (decoder.messageName() == Messages::WebPage::ResumeAllMediaPlayback::name())
        return IPC::handleMessageAsync<Messages::WebPage::ResumeAllMediaPlayback>(connection, decoder, this, &WebPage::resumeAllMediaPlayback);
    if (decoder.messageName() == Messages::WebPage::SwipeAnimationDidStart::name())
        return IPC::handleMessage<Messages::WebPage::SwipeAnimationDidStart>(connection, decoder, this, &WebPage::swipeAnimationDidStart);
    if (decoder.messageName() == Messages::WebPage::SwipeAnimationDidEnd::name())
        return IPC::handleMessage<Messages::WebPage::SwipeAnimationDidEnd>(connection, decoder, this, &WebPage::swipeAnimationDidEnd);
    if (decoder.messageName() == Messages::WebPage::BeginPrinting::name())
        return IPC::handleMessage<Messages::WebPage::BeginPrinting>(connection, decoder, this, &WebPage::beginPrinting);
    if (decoder.messageName() == Messages::WebPage::BeginPrintingDuringDOMPrintOperation::name())
        return IPC::handleMessage<Messages::WebPage::BeginPrintingDuringDOMPrintOperation>(connection, decoder, this, &WebPage::beginPrintingDuringDOMPrintOperation);
    if (decoder.messageName() == Messages::WebPage::EndPrinting::name())
        return IPC::handleMessageAsync<Messages::WebPage::EndPrinting>(connection, decoder, this, &WebPage::endPrinting);
    if (decoder.messageName() == Messages::WebPage::EndPrintingDuringDOMPrintOperation::name())
        return IPC::handleMessageAsync<Messages::WebPage::EndPrintingDuringDOMPrintOperation>(connection, decoder, this, &WebPage::endPrintingDuringDOMPrintOperation);
    if (decoder.messageName() == Messages::WebPage::ComputePagesForPrinting::name())
        return IPC::handleMessageAsync<Messages::WebPage::ComputePagesForPrinting>(connection, decoder, this, &WebPage::computePagesForPrinting);
    if (decoder.messageName() == Messages::WebPage::ComputePagesForPrintingDuringDOMPrintOperation::name())
        return IPC::handleMessageAsync<Messages::WebPage::ComputePagesForPrintingDuringDOMPrintOperation>(connection, decoder, this, &WebPage::computePagesForPrintingDuringDOMPrintOperation);
#if PLATFORM(COCOA)
    if (decoder.messageName() == Messages::WebPage::DrawRectToImage::name())
        return IPC::handleMessageAsync<Messages::WebPage::DrawRectToImage>(connection, decoder, this, &WebPage::drawRectToImage);
    if (decoder.messageName() == Messages::WebPage::DrawRectToImageDuringDOMPrintOperation::name())
        return IPC::handleMessageAsync<Messages::WebPage::DrawRectToImageDuringDOMPrintOperation>(connection, decoder, this, &WebPage::drawRectToImageDuringDOMPrintOperation);
    if (decoder.messageName() == Messages::WebPage::DrawPagesToPDF::name())
        return IPC::handleMessageAsync<Messages::WebPage::DrawPagesToPDF>(connection, decoder, this, &WebPage::drawPagesToPDF);
    if (decoder.messageName() == Messages::WebPage::DrawPagesToPDFDuringDOMPrintOperation::name())
        return IPC::handleMessageAsync<Messages::WebPage::DrawPagesToPDFDuringDOMPrintOperation>(connection, decoder, this, &WebPage::drawPagesToPDFDuringDOMPrintOperation);
#endif
#if (PLATFORM(COCOA) && PLATFORM(IOS_FAMILY))
    if (decoder.messageName() == Messages::WebPage::DrawToPDFiOS::name())
        return IPC::handleMessageAsync<Messages::WebPage::DrawToPDFiOS>(connection, decoder, this, &WebPage::drawToPDFiOS);
    if (decoder.messageName() == Messages::WebPage::DrawToImage::name())
        return IPC::handleMessageAsync<Messages::WebPage::DrawToImage>(connection, decoder, this, &WebPage::drawToImage);
#endif
#if PLATFORM(COCOA)
    if (decoder.messageName() == Messages::WebPage::DrawToPDF::name())
        return IPC::handleMessageAsync<Messages::WebPage::DrawToPDF>(connection, decoder, this, &WebPage::drawToPDF);
    if (decoder.messageName() == Messages::WebPage::DrawRemoteToPDF::name())
        return IPC::handleMessage<Messages::WebPage::DrawRemoteToPDF>(connection, decoder, this, &WebPage::drawRemoteToPDF);
#endif
#if PLATFORM(GTK)
    if (decoder.messageName() == Messages::WebPage::DrawPagesForPrinting::name())
        return IPC::handleMessageAsync<Messages::WebPage::DrawPagesForPrinting>(connection, decoder, this, &WebPage::drawPagesForPrinting);
    if (decoder.messageName() == Messages::WebPage::DrawPagesForPrintingDuringDOMPrintOperation::name())
        return IPC::handleMessageAsync<Messages::WebPage::DrawPagesForPrintingDuringDOMPrintOperation>(connection, decoder, this, &WebPage::drawPagesForPrintingDuringDOMPrintOperation);
#endif
    if (decoder.messageName() == Messages::WebPage::SetMediaVolume::name())
        return IPC::handleMessage<Messages::WebPage::SetMediaVolume>(connection, decoder, this, &WebPage::setMediaVolume);
    if (decoder.messageName() == Messages::WebPage::SetMuted::name())
        return IPC::handleMessageAsync<Messages::WebPage::SetMuted>(connection, decoder, this, &WebPage::setMuted);
    if (decoder.messageName() == Messages::WebPage::SetMayStartMediaWhenInWindow::name())
        return IPC::handleMessage<Messages::WebPage::SetMayStartMediaWhenInWindow>(connection, decoder, this, &WebPage::setMayStartMediaWhenInWindow);
    if (decoder.messageName() == Messages::WebPage::StopMediaCapture::name())
        return IPC::handleMessageAsync<Messages::WebPage::StopMediaCapture>(connection, decoder, this, &WebPage::stopMediaCapture);
    if (decoder.messageName() == Messages::WebPage::SetCanRunBeforeUnloadConfirmPanel::name())
        return IPC::handleMessage<Messages::WebPage::SetCanRunBeforeUnloadConfirmPanel>(connection, decoder, this, &WebPage::setCanRunBeforeUnloadConfirmPanel);
    if (decoder.messageName() == Messages::WebPage::SetCanRunModal::name())
        return IPC::handleMessage<Messages::WebPage::SetCanRunModal>(connection, decoder, this, &WebPage::setCanRunModal);
#if PLATFORM(GTK) || PLATFORM(WPE)
    if (decoder.messageName() == Messages::WebPage::CancelComposition::name())
        return IPC::handleMessage<Messages::WebPage::CancelComposition>(connection, decoder, this, &WebPage::cancelComposition);
    if (decoder.messageName() == Messages::WebPage::DeleteSurrounding::name())
        return IPC::handleMessage<Messages::WebPage::DeleteSurrounding>(connection, decoder, this, &WebPage::deleteSurrounding);
#endif
#if PLATFORM(GTK)
    if (decoder.messageName() == Messages::WebPage::CollapseSelectionInFrame::name())
        return IPC::handleMessage<Messages::WebPage::CollapseSelectionInFrame>(connection, decoder, this, &WebPage::collapseSelectionInFrame);
#endif
    if (decoder.messageName() == Messages::WebPage::CopyLinkWithHighlight::name())
        return IPC::handleMessage<Messages::WebPage::CopyLinkWithHighlight>(connection, decoder, this, &WebPage::copyLinkWithHighlight);
    if (decoder.messageName() == Messages::WebPage::UpdateRemotePageAccessibilityOffset::name())
        return IPC::handleMessage<Messages::WebPage::UpdateRemotePageAccessibilityOffset>(connection, decoder, this, &WebPage::updateRemotePageAccessibilityOffset);
    if (decoder.messageName() == Messages::WebPage::ResolveAccessibilityHitTestForTesting::name())
        return IPC::handleMessageAsync<Messages::WebPage::ResolveAccessibilityHitTestForTesting>(connection, decoder, this, &WebPage::resolveAccessibilityHitTestForTesting);
    if (decoder.messageName() == Messages::WebPage::EnableAccessibility::name())
        return IPC::handleMessage<Messages::WebPage::EnableAccessibility>(connection, decoder, this, &WebPage::enableAccessibility);
#if (PLATFORM(MAC) && ENABLE(ACCESSIBILITY_ISOLATED_TREE))
    if (decoder.messageName() == Messages::WebPage::ClearAccessibilityIsolatedTree::name())
        return IPC::handleMessage<Messages::WebPage::ClearAccessibilityIsolatedTree>(connection, decoder, this, &WebPage::clearAccessibilityIsolatedTree);
#endif
#if PLATFORM(COCOA)
    if (decoder.messageName() == Messages::WebPage::WindowAndViewFramesChanged::name())
        return IPC::handleMessage<Messages::WebPage::WindowAndViewFramesChanged>(connection, decoder, this, &WebPage::windowAndViewFramesChanged);
    if (decoder.messageName() == Messages::WebPage::SetMainFrameIsScrollable::name())
        return IPC::handleMessage<Messages::WebPage::SetMainFrameIsScrollable>(connection, decoder, this, &WebPage::setMainFrameIsScrollable);
    if (decoder.messageName() == Messages::WebPage::RegisterUIProcessAccessibilityTokens::name())
        return IPC::handleMessage<Messages::WebPage::RegisterUIProcessAccessibilityTokens>(connection, decoder, this, &WebPage::registerUIProcessAccessibilityTokens);
    if (decoder.messageName() == Messages::WebPage::ReplaceSelectionWithPasteboardData::name())
        return IPC::handleMessage<Messages::WebPage::ReplaceSelectionWithPasteboardData>(connection, decoder, this, &WebPage::replaceSelectionWithPasteboardData);
#endif
#if (PLATFORM(COCOA) && ENABLE(MULTI_REPRESENTATION_HEIC))
    if (decoder.messageName() == Messages::WebPage::InsertMultiRepresentationHEIC::name())
        return IPC::handleMessage<Messages::WebPage::InsertMultiRepresentationHEIC>(connection, decoder, this, &WebPage::insertMultiRepresentationHEIC);
#endif
#if PLATFORM(COCOA)
    if (decoder.messageName() == Messages::WebPage::SetTextAsync::name())
        return IPC::handleMessage<Messages::WebPage::SetTextAsync>(connection, decoder, this, &WebPage::setTextAsync);
    if (decoder.messageName() == Messages::WebPage::InsertTextAsync::name())
        return IPC::handleMessage<Messages::WebPage::InsertTextAsync>(connection, decoder, this, &WebPage::insertTextAsync);
    if (decoder.messageName() == Messages::WebPage::InsertDictatedTextAsync::name())
        return IPC::handleMessage<Messages::WebPage::InsertDictatedTextAsync>(connection, decoder, this, &WebPage::insertDictatedTextAsync);
    if (decoder.messageName() == Messages::WebPage::AddDictationAlternative::name())
        return IPC::handleMessageAsync<Messages::WebPage::AddDictationAlternative>(connection, decoder, this, &WebPage::addDictationAlternative);
    if (decoder.messageName() == Messages::WebPage::DictationAlternativesAtSelection::name())
        return IPC::handleMessageAsync<Messages::WebPage::DictationAlternativesAtSelection>(connection, decoder, this, &WebPage::dictationAlternativesAtSelection);
    if (decoder.messageName() == Messages::WebPage::ClearDictationAlternatives::name())
        return IPC::handleMessage<Messages::WebPage::ClearDictationAlternatives>(connection, decoder, this, &WebPage::clearDictationAlternatives);
    if (decoder.messageName() == Messages::WebPage::HasMarkedText::name())
        return IPC::handleMessageAsync<Messages::WebPage::HasMarkedText>(connection, decoder, this, &WebPage::hasMarkedText);
    if (decoder.messageName() == Messages::WebPage::GetMarkedRangeAsync::name())
        return IPC::handleMessageAsync<Messages::WebPage::GetMarkedRangeAsync>(connection, decoder, this, &WebPage::getMarkedRangeAsync);
    if (decoder.messageName() == Messages::WebPage::GetSelectedRangeAsync::name())
        return IPC::handleMessageAsync<Messages::WebPage::GetSelectedRangeAsync>(connection, decoder, this, &WebPage::getSelectedRangeAsync);
    if (decoder.messageName() == Messages::WebPage::CharacterIndexForPointAsync::name())
        return IPC::handleMessageAsync<Messages::WebPage::CharacterIndexForPointAsync>(connection, decoder, this, &WebPage::characterIndexForPointAsync);
    if (decoder.messageName() == Messages::WebPage::FirstRectForCharacterRangeAsync::name())
        return IPC::handleMessageAsync<Messages::WebPage::FirstRectForCharacterRangeAsync>(connection, decoder, this, &WebPage::firstRectForCharacterRangeAsync);
    if (decoder.messageName() == Messages::WebPage::SetCompositionAsync::name())
        return IPC::handleMessage<Messages::WebPage::SetCompositionAsync>(connection, decoder, this, &WebPage::setCompositionAsync);
    if (decoder.messageName() == Messages::WebPage::SetWritingSuggestion::name())
        return IPC::handleMessage<Messages::WebPage::SetWritingSuggestion>(connection, decoder, this, &WebPage::setWritingSuggestion);
    if (decoder.messageName() == Messages::WebPage::ConfirmCompositionAsync::name())
        return IPC::handleMessage<Messages::WebPage::ConfirmCompositionAsync>(connection, decoder, this, &WebPage::confirmCompositionAsync);
#endif
#if PLATFORM(MAC)
    if (decoder.messageName() == Messages::WebPage::AttributedSubstringForCharacterRangeAsync::name())
        return IPC::handleMessageAsync<Messages::WebPage::AttributedSubstringForCharacterRangeAsync>(connection, decoder, this, &WebPage::attributedSubstringForCharacterRangeAsync);
    if (decoder.messageName() == Messages::WebPage::RequestAcceptsFirstMouse::name())
        return IPC::handleMessage<Messages::WebPage::RequestAcceptsFirstMouse>(connection, decoder, this, &WebPage::requestAcceptsFirstMouse);
    if (decoder.messageName() == Messages::WebPage::SetCaretAnimatorType::name())
        return IPC::handleMessage<Messages::WebPage::SetCaretAnimatorType>(connection, decoder, this, &WebPage::setCaretAnimatorType);
    if (decoder.messageName() == Messages::WebPage::SetCaretBlinkingSuspended::name())
        return IPC::handleMessage<Messages::WebPage::SetCaretBlinkingSuspended>(connection, decoder, this, &WebPage::setCaretBlinkingSuspended);
#endif
#if ENABLE(IMAGE_ANALYSIS_ENHANCEMENTS)
    if (decoder.messageName() == Messages::WebPage::ReplaceImageForRemoveBackground::name())
        return IPC::handleMessage<Messages::WebPage::ReplaceImageForRemoveBackground>(connection, decoder, this, &WebPage::replaceImageForRemoveBackground);
    if (decoder.messageName() == Messages::WebPage::ShouldAllowRemoveBackground::name())
        return IPC::handleMessageAsync<Messages::WebPage::ShouldAllowRemoveBackground>(connection, decoder, this, &WebPage::shouldAllowRemoveBackground);
#endif
    if (decoder.messageName() == Messages::WebPage::SetAlwaysShowsHorizontalScroller::name())
        return IPC::handleMessage<Messages::WebPage::SetAlwaysShowsHorizontalScroller>(connection, decoder, this, &WebPage::setAlwaysShowsHorizontalScroller);
    if (decoder.messageName() == Messages::WebPage::SetAlwaysShowsVerticalScroller::name())
        return IPC::handleMessage<Messages::WebPage::SetAlwaysShowsVerticalScroller>(connection, decoder, this, &WebPage::setAlwaysShowsVerticalScroller);
    if (decoder.messageName() == Messages::WebPage::SetMinimumSizeForAutoLayout::name())
        return IPC::handleMessage<Messages::WebPage::SetMinimumSizeForAutoLayout>(connection, decoder, this, &WebPage::setMinimumSizeForAutoLayout);
    if (decoder.messageName() == Messages::WebPage::SetSizeToContentAutoSizeMaximumSize::name())
        return IPC::handleMessage<Messages::WebPage::SetSizeToContentAutoSizeMaximumSize>(connection, decoder, this, &WebPage::setSizeToContentAutoSizeMaximumSize);
    if (decoder.messageName() == Messages::WebPage::SetAutoSizingShouldExpandToViewHeight::name())
        return IPC::handleMessage<Messages::WebPage::SetAutoSizingShouldExpandToViewHeight>(connection, decoder, this, &WebPage::setAutoSizingShouldExpandToViewHeight);
    if (decoder.messageName() == Messages::WebPage::SetViewportSizeForCSSViewportUnits::name())
        return IPC::handleMessage<Messages::WebPage::SetViewportSizeForCSSViewportUnits>(connection, decoder, this, &WebPage::setViewportSizeForCSSViewportUnits);
#if PLATFORM(COCOA)
    if (decoder.messageName() == Messages::WebPage::HandleAlternativeTextUIResult::name())
        return IPC::handleMessage<Messages::WebPage::HandleAlternativeTextUIResult>(connection, decoder, this, &WebPage::handleAlternativeTextUIResult);
#endif
#if PLATFORM(IOS_FAMILY)
    if (decoder.messageName() == Messages::WebPage::WillStartUserTriggeredZooming::name())
        return IPC::handleMessage<Messages::WebPage::WillStartUserTriggeredZooming>(connection, decoder, this, &WebPage::willStartUserTriggeredZooming);
    if (decoder.messageName() == Messages::WebPage::DidEndUserTriggeredZooming::name())
        return IPC::handleMessage<Messages::WebPage::DidEndUserTriggeredZooming>(connection, decoder, this, &WebPage::didEndUserTriggeredZooming);
#endif
    if (decoder.messageName() == Messages::WebPage::SetScrollPinningBehavior::name())
        return IPC::handleMessage<Messages::WebPage::SetScrollPinningBehavior>(connection, decoder, this, &WebPage::setScrollPinningBehavior);
    if (decoder.messageName() == Messages::WebPage::SetScrollbarOverlayStyle::name())
        return IPC::handleMessage<Messages::WebPage::SetScrollbarOverlayStyle>(connection, decoder, this, &WebPage::setScrollbarOverlayStyle);
    if (decoder.messageName() == Messages::WebPage::GetBytecodeProfile::name())
        return IPC::handleMessageAsync<Messages::WebPage::GetBytecodeProfile>(connection, decoder, this, &WebPage::getBytecodeProfile);
    if (decoder.messageName() == Messages::WebPage::GetSamplingProfilerOutput::name())
        return IPC::handleMessageAsync<Messages::WebPage::GetSamplingProfilerOutput>(connection, decoder, this, &WebPage::getSamplingProfilerOutput);
    if (decoder.messageName() == Messages::WebPage::TakeSnapshot::name())
        return IPC::handleMessageAsync<Messages::WebPage::TakeSnapshot>(connection, decoder, this, &WebPage::takeSnapshot);
#if PLATFORM(MAC)
    if (decoder.messageName() == Messages::WebPage::PerformImmediateActionHitTestAtLocation::name())
        return IPC::handleMessage<Messages::WebPage::PerformImmediateActionHitTestAtLocation>(connection, decoder, this, &WebPage::performImmediateActionHitTestAtLocation);
    if (decoder.messageName() == Messages::WebPage::ImmediateActionDidUpdate::name())
        return IPC::handleMessage<Messages::WebPage::ImmediateActionDidUpdate>(connection, decoder, this, &WebPage::immediateActionDidUpdate);
    if (decoder.messageName() == Messages::WebPage::ImmediateActionDidCancel::name())
        return IPC::handleMessage<Messages::WebPage::ImmediateActionDidCancel>(connection, decoder, this, &WebPage::immediateActionDidCancel);
    if (decoder.messageName() == Messages::WebPage::ImmediateActionDidComplete::name())
        return IPC::handleMessage<Messages::WebPage::ImmediateActionDidComplete>(connection, decoder, this, &WebPage::immediateActionDidComplete);
    if (decoder.messageName() == Messages::WebPage::DataDetectorsDidPresentUI::name())
        return IPC::handleMessage<Messages::WebPage::DataDetectorsDidPresentUI>(connection, decoder, this, &WebPage::dataDetectorsDidPresentUI);
    if (decoder.messageName() == Messages::WebPage::DataDetectorsDidChangeUI::name())
        return IPC::handleMessage<Messages::WebPage::DataDetectorsDidChangeUI>(connection, decoder, this, &WebPage::dataDetectorsDidChangeUI);
    if (decoder.messageName() == Messages::WebPage::DataDetectorsDidHideUI::name())
        return IPC::handleMessage<Messages::WebPage::DataDetectorsDidHideUI>(connection, decoder, this, &WebPage::dataDetectorsDidHideUI);
    if (decoder.messageName() == Messages::WebPage::HandleAcceptedCandidate::name())
        return IPC::handleMessage<Messages::WebPage::HandleAcceptedCandidate>(connection, decoder, this, &WebPage::handleAcceptedCandidate);
    if (decoder.messageName() == Messages::WebPage::SemanticContextDidChange::name())
        return IPC::handleMessage<Messages::WebPage::SemanticContextDidChange>(connection, decoder, this, &WebPage::semanticContextDidChange);
    if (decoder.messageName() == Messages::WebPage::SetHeaderBannerHeight::name())
        return IPC::handleMessage<Messages::WebPage::SetHeaderBannerHeight>(connection, decoder, this, &WebPage::setHeaderBannerHeight);
    if (decoder.messageName() == Messages::WebPage::SetFooterBannerHeight::name())
        return IPC::handleMessage<Messages::WebPage::SetFooterBannerHeight>(connection, decoder, this, &WebPage::setFooterBannerHeight);
    if (decoder.messageName() == Messages::WebPage::DidBeginMagnificationGesture::name())
        return IPC::handleMessage<Messages::WebPage::DidBeginMagnificationGesture>(connection, decoder, this, &WebPage::didBeginMagnificationGesture);
    if (decoder.messageName() == Messages::WebPage::DidEndMagnificationGesture::name())
        return IPC::handleMessage<Messages::WebPage::DidEndMagnificationGesture>(connection, decoder, this, &WebPage::didEndMagnificationGesture);
#endif
    if (decoder.messageName() == Messages::WebPage::StartDeferringResizeEvents::name())
        return IPC::handleMessage<Messages::WebPage::StartDeferringResizeEvents>(connection, decoder, this, &WebPage::startDeferringResizeEvents);
    if (decoder.messageName() == Messages::WebPage::FlushDeferredResizeEvents::name())
        return IPC::handleMessage<Messages::WebPage::FlushDeferredResizeEvents>(connection, decoder, this, &WebPage::flushDeferredResizeEvents);
    if (decoder.messageName() == Messages::WebPage::StartDeferringScrollEvents::name())
        return IPC::handleMessage<Messages::WebPage::StartDeferringScrollEvents>(connection, decoder, this, &WebPage::startDeferringScrollEvents);
    if (decoder.messageName() == Messages::WebPage::FlushDeferredScrollEvents::name())
        return IPC::handleMessage<Messages::WebPage::FlushDeferredScrollEvents>(connection, decoder, this, &WebPage::flushDeferredScrollEvents);
    if (decoder.messageName() == Messages::WebPage::FlushDeferredDidReceiveMouseEvent::name())
        return IPC::handleMessage<Messages::WebPage::FlushDeferredDidReceiveMouseEvent>(connection, decoder, this, &WebPage::flushDeferredDidReceiveMouseEvent);
    if (decoder.messageName() == Messages::WebPage::PerformHitTestForMouseEvent::name())
        return IPC::handleMessageAsync<Messages::WebPage::PerformHitTestForMouseEvent>(connection, decoder, this, &WebPage::performHitTestForMouseEvent);
    if (decoder.messageName() == Messages::WebPage::SetUseColorAppearance::name())
        return IPC::handleMessage<Messages::WebPage::SetUseColorAppearance>(connection, decoder, this, &WebPage::setUseColorAppearance);
#if HAVE(APP_ACCENT_COLORS)
    if (decoder.messageName() == Messages::WebPage::SetAccentColor::name())
        return IPC::handleMessage<Messages::WebPage::SetAccentColor>(connection, decoder, this, &WebPage::setAccentColor);
#endif
#if PLATFORM(COCOA)
    if (decoder.messageName() == Messages::WebPage::RequestActiveNowPlayingSessionInfo::name())
        return IPC::handleMessageAsync<Messages::WebPage::RequestActiveNowPlayingSessionInfo>(connection, decoder, this, &WebPage::requestActiveNowPlayingSessionInfo);
#endif
    if (decoder.messageName() == Messages::WebPage::SetShouldDispatchFakeMouseMoveEvents::name())
        return IPC::handleMessage<Messages::WebPage::SetShouldDispatchFakeMouseMoveEvents>(connection, decoder, this, &WebPage::setShouldDispatchFakeMouseMoveEvents);
#if ENABLE(WIRELESS_PLAYBACK_TARGET) && !PLATFORM(IOS_FAMILY)
    if (decoder.messageName() == Messages::WebPage::PlaybackTargetSelected::name())
        return IPC::handleMessage<Messages::WebPage::PlaybackTargetSelected>(connection, decoder, this, &WebPage::playbackTargetSelected);
    if (decoder.messageName() == Messages::WebPage::PlaybackTargetAvailabilityDidChange::name())
        return IPC::handleMessage<Messages::WebPage::PlaybackTargetAvailabilityDidChange>(connection, decoder, this, &WebPage::playbackTargetAvailabilityDidChange);
    if (decoder.messageName() == Messages::WebPage::SetShouldPlayToPlaybackTarget::name())
        return IPC::handleMessage<Messages::WebPage::SetShouldPlayToPlaybackTarget>(connection, decoder, this, &WebPage::setShouldPlayToPlaybackTarget);
    if (decoder.messageName() == Messages::WebPage::PlaybackTargetPickerWasDismissed::name())
        return IPC::handleMessage<Messages::WebPage::PlaybackTargetPickerWasDismissed>(connection, decoder, this, &WebPage::playbackTargetPickerWasDismissed);
#endif
#if ENABLE(POINTER_LOCK)
    if (decoder.messageName() == Messages::WebPage::DidLosePointerLock::name())
        return IPC::handleMessage<Messages::WebPage::DidLosePointerLock>(connection, decoder, this, &WebPage::didLosePointerLock);
#endif
    if (decoder.messageName() == Messages::WebPage::SetShouldScaleViewToFitDocument::name())
        return IPC::handleMessage<Messages::WebPage::SetShouldScaleViewToFitDocument>(connection, decoder, this, &WebPage::setShouldScaleViewToFitDocument);
    if (decoder.messageName() == Messages::WebPage::SetUserInterfaceLayoutDirection::name())
        return IPC::handleMessage<Messages::WebPage::SetUserInterfaceLayoutDirection>(connection, decoder, this, &WebPage::setUserInterfaceLayoutDirection);
    if (decoder.messageName() == Messages::WebPage::DidGetLoadDecisionForIcon::name())
        return IPC::handleMessageAsync<Messages::WebPage::DidGetLoadDecisionForIcon>(connection, decoder, this, &WebPage::didGetLoadDecisionForIcon);
    if (decoder.messageName() == Messages::WebPage::SetUseIconLoadingClient::name())
        return IPC::handleMessage<Messages::WebPage::SetUseIconLoadingClient>(connection, decoder, this, &WebPage::setUseIconLoadingClient);
#if ENABLE(GAMEPAD)
    if (decoder.messageName() == Messages::WebPage::GamepadActivity::name())
        return IPC::handleMessage<Messages::WebPage::GamepadActivity>(connection, decoder, this, &WebPage::gamepadActivity);
#endif
#if (ENABLE(GAMEPAD) && PLATFORM(VISION))
    if (decoder.messageName() == Messages::WebPage::AllowGamepadAccess::name())
        return IPC::handleMessage<Messages::WebPage::AllowGamepadAccess>(connection, decoder, this, &WebPage::allowGamepadAccess);
#endif
    if (decoder.messageName() == Messages::WebPage::RegisterURLSchemeHandler::name())
        return IPC::handleMessage<Messages::WebPage::RegisterURLSchemeHandler>(connection, decoder, this, &WebPage::registerURLSchemeHandler);
    if (decoder.messageName() == Messages::WebPage::URLSchemeTaskWillPerformRedirection::name())
        return IPC::handleMessageAsync<Messages::WebPage::URLSchemeTaskWillPerformRedirection>(connection, decoder, this, &WebPage::urlSchemeTaskWillPerformRedirection);
    if (decoder.messageName() == Messages::WebPage::URLSchemeTaskDidPerformRedirection::name())
        return IPC::handleMessage<Messages::WebPage::URLSchemeTaskDidPerformRedirection>(connection, decoder, this, &WebPage::urlSchemeTaskDidPerformRedirection);
    if (decoder.messageName() == Messages::WebPage::URLSchemeTaskDidReceiveResponse::name())
        return IPC::handleMessage<Messages::WebPage::URLSchemeTaskDidReceiveResponse>(connection, decoder, this, &WebPage::urlSchemeTaskDidReceiveResponse);
    if (decoder.messageName() == Messages::WebPage::URLSchemeTaskDidReceiveData::name())
        return IPC::handleMessage<Messages::WebPage::URLSchemeTaskDidReceiveData>(connection, decoder, this, &WebPage::urlSchemeTaskDidReceiveData);
    if (decoder.messageName() == Messages::WebPage::URLSchemeTaskDidComplete::name())
        return IPC::handleMessage<Messages::WebPage::URLSchemeTaskDidComplete>(connection, decoder, this, &WebPage::urlSchemeTaskDidComplete);
    if (decoder.messageName() == Messages::WebPage::SetIsSuspended::name())
        return IPC::handleMessageAsync<Messages::WebPage::SetIsSuspended>(connection, decoder, this, &WebPage::setIsSuspended);
#if ENABLE(ATTACHMENT_ELEMENT)
    if (decoder.messageName() == Messages::WebPage::InsertAttachment::name())
        return IPC::handleMessageAsync<Messages::WebPage::InsertAttachment>(connection, decoder, this, &WebPage::insertAttachment);
    if (decoder.messageName() == Messages::WebPage::UpdateAttachmentAttributes::name())
        return IPC::handleMessageAsync<Messages::WebPage::UpdateAttachmentAttributes>(connection, decoder, this, &WebPage::updateAttachmentAttributes);
    if (decoder.messageName() == Messages::WebPage::UpdateAttachmentIcon::name())
        return IPC::handleMessage<Messages::WebPage::UpdateAttachmentIcon>(connection, decoder, this, &WebPage::updateAttachmentIcon);
#endif
#if ENABLE(APPLICATION_MANIFEST)
    if (decoder.messageName() == Messages::WebPage::GetApplicationManifest::name())
        return IPC::handleMessageAsync<Messages::WebPage::GetApplicationManifest>(connection, decoder, this, &WebPage::getApplicationManifest);
#endif
    if (decoder.messageName() == Messages::WebPage::GetTextFragmentMatch::name())
        return IPC::handleMessageAsync<Messages::WebPage::GetTextFragmentMatch>(connection, decoder, this, &WebPage::getTextFragmentMatch);
#if ENABLE(PDF_PLUGIN) && PLATFORM(MAC)
    if (decoder.messageName() == Messages::WebPage::ZoomPDFIn::name())
        return IPC::handleMessage<Messages::WebPage::ZoomPDFIn>(connection, decoder, this, &WebPage::zoomPDFIn);
    if (decoder.messageName() == Messages::WebPage::ZoomPDFOut::name())
        return IPC::handleMessage<Messages::WebPage::ZoomPDFOut>(connection, decoder, this, &WebPage::zoomPDFOut);
    if (decoder.messageName() == Messages::WebPage::SavePDF::name())
        return IPC::handleMessageAsync<Messages::WebPage::SavePDF>(connection, decoder, this, &WebPage::savePDF);
    if (decoder.messageName() == Messages::WebPage::OpenPDFWithPreview::name())
        return IPC::handleMessageAsync<Messages::WebPage::OpenPDFWithPreview>(connection, decoder, this, &WebPage::openPDFWithPreview);
#endif
    if (decoder.messageName() == Messages::WebPage::UpdateCurrentModifierState::name())
        return IPC::handleMessage<Messages::WebPage::UpdateCurrentModifierState>(connection, decoder, this, &WebPage::updateCurrentModifierState);
    if (decoder.messageName() == Messages::WebPage::SimulateDeviceOrientationChange::name())
        return IPC::handleMessage<Messages::WebPage::SimulateDeviceOrientationChange>(connection, decoder, this, &WebPage::simulateDeviceOrientationChange);
#if ENABLE(SPEECH_SYNTHESIS)
    if (decoder.messageName() == Messages::WebPage::SpeakingErrorOccurred::name())
        return IPC::handleMessage<Messages::WebPage::SpeakingErrorOccurred>(connection, decoder, this, &WebPage::speakingErrorOccurred);
    if (decoder.messageName() == Messages::WebPage::BoundaryEventOccurred::name())
        return IPC::handleMessage<Messages::WebPage::BoundaryEventOccurred>(connection, decoder, this, &WebPage::boundaryEventOccurred);
    if (decoder.messageName() == Messages::WebPage::VoicesDidChange::name())
        return IPC::handleMessage<Messages::WebPage::VoicesDidChange>(connection, decoder, this, &WebPage::voicesDidChange);
#endif
    if (decoder.messageName() == Messages::WebPage::SetCanShowPlaceholder::name())
        return IPC::handleMessage<Messages::WebPage::SetCanShowPlaceholder>(connection, decoder, this, &WebPage::setCanShowPlaceholder);
    if (decoder.messageName() == Messages::WebPage::WasLoadedWithDataTransferFromPrevalentResource::name())
        return IPC::handleMessage<Messages::WebPage::WasLoadedWithDataTransferFromPrevalentResource>(connection, decoder, this, &WebPage::wasLoadedWithDataTransferFromPrevalentResource);
    if (decoder.messageName() == Messages::WebPage::ClearLoadedSubresourceDomains::name())
        return IPC::handleMessage<Messages::WebPage::ClearLoadedSubresourceDomains>(connection, decoder, this, &WebPage::clearLoadedSubresourceDomains);
    if (decoder.messageName() == Messages::WebPage::GetLoadedSubresourceDomains::name())
        return IPC::handleMessageAsync<Messages::WebPage::GetLoadedSubresourceDomains>(connection, decoder, this, &WebPage::getLoadedSubresourceDomains);
#if USE(SYSTEM_PREVIEW)
    if (decoder.messageName() == Messages::WebPage::SystemPreviewActionTriggered::name())
        return IPC::handleMessage<Messages::WebPage::SystemPreviewActionTriggered>(connection, decoder, this, &WebPage::systemPreviewActionTriggered);
#endif
#if PLATFORM(GTK) || PLATFORM(WPE)
    if (decoder.messageName() == Messages::WebPage::SendMessageToWebProcessExtension::name())
        return IPC::handleMessage<Messages::WebPage::SendMessageToWebProcessExtension>(connection, decoder, this, &WebPage::sendMessageToWebProcessExtension);
    if (decoder.messageName() == Messages::WebPage::SendMessageToWebProcessExtensionWithReply::name())
        return IPC::handleMessageAsync<Messages::WebPage::SendMessageToWebProcessExtensionWithReply>(connection, decoder, this, &WebPage::sendMessageToWebProcessExtensionWithReply);
#endif
#if PLATFORM(WPE) && USE(GBM) && ENABLE(WPE_PLATFORM)
    if (decoder.messageName() == Messages::WebPage::PreferredBufferFormatsDidChange::name())
        return IPC::handleMessage<Messages::WebPage::PreferredBufferFormatsDidChange>(connection, decoder, this, &WebPage::preferredBufferFormatsDidChange);
#endif
    if (decoder.messageName() == Messages::WebPage::StartTextManipulations::name())
        return IPC::handleMessageAsync<Messages::WebPage::StartTextManipulations>(connection, decoder, this, &WebPage::startTextManipulations);
    if (decoder.messageName() == Messages::WebPage::CompleteTextManipulation::name())
        return IPC::handleMessageAsync<Messages::WebPage::CompleteTextManipulation>(connection, decoder, this, &WebPage::completeTextManipulation);
    if (decoder.messageName() == Messages::WebPage::SetOverriddenMediaType::name())
        return IPC::handleMessage<Messages::WebPage::SetOverriddenMediaType>(connection, decoder, this, &WebPage::setOverriddenMediaType);
    if (decoder.messageName() == Messages::WebPage::GetProcessDisplayName::name())
        return IPC::handleMessageAsync<Messages::WebPage::GetProcessDisplayName>(connection, decoder, this, &WebPage::getProcessDisplayName);
    if (decoder.messageName() == Messages::WebPage::UpdateCORSDisablingPatterns::name())
        return IPC::handleMessage<Messages::WebPage::UpdateCORSDisablingPatterns>(connection, decoder, this, &WebPage::updateCORSDisablingPatterns);
    if (decoder.messageName() == Messages::WebPage::SetIsTakingSnapshotsForApplicationSuspension::name())
        return IPC::handleMessage<Messages::WebPage::SetIsTakingSnapshotsForApplicationSuspension>(connection, decoder, this, &WebPage::setIsTakingSnapshotsForApplicationSuspension);
    if (decoder.messageName() == Messages::WebPage::SetNeedsDOMWindowResizeEvent::name())
        return IPC::handleMessage<Messages::WebPage::SetNeedsDOMWindowResizeEvent>(connection, decoder, this, &WebPage::setNeedsDOMWindowResizeEvent);
    if (decoder.messageName() == Messages::WebPage::SetHasResourceLoadClient::name())
        return IPC::handleMessage<Messages::WebPage::SetHasResourceLoadClient>(connection, decoder, this, &WebPage::setHasResourceLoadClient);
    if (decoder.messageName() == Messages::WebPage::SetCanUseCredentialStorage::name())
        return IPC::handleMessage<Messages::WebPage::SetCanUseCredentialStorage>(connection, decoder, this, &WebPage::setCanUseCredentialStorage);
#if ENABLE(APP_HIGHLIGHTS)
    if (decoder.messageName() == Messages::WebPage::CreateAppHighlightInSelectedRange::name())
        return IPC::handleMessageAsync<Messages::WebPage::CreateAppHighlightInSelectedRange>(connection, decoder, this, &WebPage::createAppHighlightInSelectedRange);
    if (decoder.messageName() == Messages::WebPage::RestoreAppHighlightsAndScrollToIndex::name())
        return IPC::handleMessage<Messages::WebPage::RestoreAppHighlightsAndScrollToIndex>(connection, decoder, this, &WebPage::restoreAppHighlightsAndScrollToIndex);
    if (decoder.messageName() == Messages::WebPage::SetAppHighlightsVisibility::name())
        return IPC::handleMessage<Messages::WebPage::SetAppHighlightsVisibility>(connection, decoder, this, &WebPage::setAppHighlightsVisibility);
#endif
    if (decoder.messageName() == Messages::WebPage::CreateTextFragmentDirectiveFromSelection::name())
        return IPC::handleMessageAsync<Messages::WebPage::CreateTextFragmentDirectiveFromSelection>(connection, decoder, this, &WebPage::createTextFragmentDirectiveFromSelection);
    if (decoder.messageName() == Messages::WebPage::GetTextFragmentRanges::name())
        return IPC::handleMessageAsync<Messages::WebPage::GetTextFragmentRanges>(connection, decoder, this, &WebPage::getTextFragmentRanges);
    if (decoder.messageName() == Messages::WebPage::HandleWheelEvent::name())
        return IPC::handleMessageAsync<Messages::WebPage::HandleWheelEvent>(connection, decoder, this, &WebPage::handleWheelEvent);
#if PLATFORM(IOS_FAMILY)
    if (decoder.messageName() == Messages::WebPage::DispatchWheelEventWithoutScrolling::name())
        return IPC::handleMessageAsync<Messages::WebPage::DispatchWheelEventWithoutScrolling>(connection, decoder, this, &WebPage::dispatchWheelEventWithoutScrolling);
#endif
    if (decoder.messageName() == Messages::WebPage::LastNavigationWasAppInitiated::name())
        return IPC::handleMessageAsync<Messages::WebPage::LastNavigationWasAppInitiated>(connection, decoder, this, &WebPage::lastNavigationWasAppInitiated);
#if ENABLE(MEDIA_SESSION_COORDINATOR)
    if (decoder.messageName() == Messages::WebPage::CreateMediaSessionCoordinator::name())
        return IPC::handleMessageAsync<Messages::WebPage::CreateMediaSessionCoordinator>(connection, decoder, this, &WebPage::createMediaSessionCoordinator);
#endif
#if ENABLE(IMAGE_ANALYSIS)
    if (decoder.messageName() == Messages::WebPage::UpdateWithTextRecognitionResult::name())
        return IPC::handleMessageAsync<Messages::WebPage::UpdateWithTextRecognitionResult>(connection, decoder, this, &WebPage::updateWithTextRecognitionResult);
    if (decoder.messageName() == Messages::WebPage::StartVisualTranslation::name())
        return IPC::handleMessage<Messages::WebPage::StartVisualTranslation>(connection, decoder, this, &WebPage::startVisualTranslation);
#endif
    if (decoder.messageName() == Messages::WebPage::ScrollToRect::name())
        return IPC::handleMessage<Messages::WebPage::ScrollToRect>(connection, decoder, this, &WebPage::scrollToRect);
    if (decoder.messageName() == Messages::WebPage::SetContentOffset::name())
        return IPC::handleMessage<Messages::WebPage::SetContentOffset>(connection, decoder, this, &WebPage::setContentOffset);
    if (decoder.messageName() == Messages::WebPage::ScrollToEdge::name())
        return IPC::handleMessage<Messages::WebPage::ScrollToEdge>(connection, decoder, this, &WebPage::scrollToEdge);
    if (decoder.messageName() == Messages::WebPage::NavigateServiceWorkerClient::name())
        return IPC::handleMessageAsync<Messages::WebPage::NavigateServiceWorkerClient>(connection, decoder, this, &WebPage::navigateServiceWorkerClient);
#if ENABLE(ARKIT_INLINE_PREVIEW_IOS)
    if (decoder.messageName() == Messages::WebPage::ModelInlinePreviewDidLoad::name())
        return IPC::handleMessage<Messages::WebPage::ModelInlinePreviewDidLoad>(connection, decoder, this, &WebPage::modelInlinePreviewDidLoad);
    if (decoder.messageName() == Messages::WebPage::ModelInlinePreviewDidFailToLoad::name())
        return IPC::handleMessage<Messages::WebPage::ModelInlinePreviewDidFailToLoad>(connection, decoder, this, &WebPage::modelInlinePreviewDidFailToLoad);
#endif
#if HAVE(UIKIT_RESIZABLE_WINDOWS)
    if (decoder.messageName() == Messages::WebPage::SetIsWindowResizingEnabled::name())
        return IPC::handleMessage<Messages::WebPage::SetIsWindowResizingEnabled>(connection, decoder, this, &WebPage::setIsWindowResizingEnabled);
#endif
#if ENABLE(INTERACTION_REGIONS_IN_EVENT_REGION)
    if (decoder.messageName() == Messages::WebPage::SetInteractionRegionsEnabled::name())
        return IPC::handleMessage<Messages::WebPage::SetInteractionRegionsEnabled>(connection, decoder, this, &WebPage::setInteractionRegionsEnabled);
#endif
    if (decoder.messageName() == Messages::WebPage::SetNeedsScrollGeometryUpdates::name())
        return IPC::handleMessage<Messages::WebPage::SetNeedsScrollGeometryUpdates>(connection, decoder, this, &WebPage::setNeedsScrollGeometryUpdates);
    if (decoder.messageName() == Messages::WebPage::GenerateTestReport::name())
        return IPC::handleMessage<Messages::WebPage::GenerateTestReport>(connection, decoder, this, &WebPage::generateTestReport);
#if ENABLE(ADVANCED_PRIVACY_PROTECTIONS)
    if (decoder.messageName() == Messages::WebPage::SetLinkDecorationFilteringData::name())
        return IPC::handleMessage<Messages::WebPage::SetLinkDecorationFilteringData>(connection, decoder, this, &WebPage::setLinkDecorationFilteringData);
    if (decoder.messageName() == Messages::WebPage::SetAllowedQueryParametersForAdvancedPrivacyProtections::name())
        return IPC::handleMessage<Messages::WebPage::SetAllowedQueryParametersForAdvancedPrivacyProtections>(connection, decoder, this, &WebPage::setAllowedQueryParametersForAdvancedPrivacyProtections);
#endif
#if ENABLE(ACCESSIBILITY_ANIMATION_CONTROL)
    if (decoder.messageName() == Messages::WebPage::PauseAllAnimations::name())
        return IPC::handleMessageAsync<Messages::WebPage::PauseAllAnimations>(connection, decoder, this, &WebPage::pauseAllAnimations);
    if (decoder.messageName() == Messages::WebPage::PlayAllAnimations::name())
        return IPC::handleMessageAsync<Messages::WebPage::PlayAllAnimations>(connection, decoder, this, &WebPage::playAllAnimations);
#endif
    if (decoder.messageName() == Messages::WebPage::UseRedirectionForCurrentNavigation::name())
        return IPC::handleMessage<Messages::WebPage::UseRedirectionForCurrentNavigation>(connection, decoder, this, &WebPage::useRedirectionForCurrentNavigation);
    if (decoder.messageName() == Messages::WebPage::UpdateFrameScrollingMode::name())
        return IPC::handleMessage<Messages::WebPage::UpdateFrameScrollingMode>(connection, decoder, this, &WebPage::updateFrameScrollingMode);
    if (decoder.messageName() == Messages::WebPage::DispatchLoadEventToFrameOwnerElement::name())
        return IPC::handleMessage<Messages::WebPage::DispatchLoadEventToFrameOwnerElement>(connection, decoder, this, &WebPage::dispatchLoadEventToFrameOwnerElement);
    if (decoder.messageName() == Messages::WebPage::FrameWasFocusedInAnotherProcess::name())
        return IPC::handleMessage<Messages::WebPage::FrameWasFocusedInAnotherProcess>(connection, decoder, this, &WebPage::frameWasFocusedInAnotherProcess);
    if (decoder.messageName() == Messages::WebPage::RemotePostMessage::name())
        return IPC::handleMessage<Messages::WebPage::RemotePostMessage>(connection, decoder, this, &WebPage::remotePostMessage);
    if (decoder.messageName() == Messages::WebPage::RequestAllTextAndRects::name())
        return IPC::handleMessageAsync<Messages::WebPage::RequestAllTextAndRects>(connection, decoder, this, &WebPage::requestAllTextAndRects);
    if (decoder.messageName() == Messages::WebPage::RequestTargetedElement::name())
        return IPC::handleMessageAsync<Messages::WebPage::RequestTargetedElement>(connection, decoder, this, &WebPage::requestTargetedElement);
    if (decoder.messageName() == Messages::WebPage::RequestAllTargetableElements::name())
        return IPC::handleMessageAsync<Messages::WebPage::RequestAllTargetableElements>(connection, decoder, this, &WebPage::requestAllTargetableElements);
    if (decoder.messageName() == Messages::WebPage::RequestTextExtraction::name())
        return IPC::handleMessageAsync<Messages::WebPage::RequestTextExtraction>(connection, decoder, this, &WebPage::requestTextExtraction);
#if PLATFORM(IOS_FAMILY)
    if (decoder.messageName() == Messages::WebPage::ShouldDismissKeyboardAfterTapAtPoint::name())
        return IPC::handleMessageAsync<Messages::WebPage::ShouldDismissKeyboardAfterTapAtPoint>(connection, decoder, this, &WebPage::shouldDismissKeyboardAfterTapAtPoint);
#endif
#if ENABLE(EXTENSION_CAPABILITIES)
    if (decoder.messageName() == Messages::WebPage::SetMediaEnvironment::name())
        return IPC::handleMessage<Messages::WebPage::SetMediaEnvironment>(connection, decoder, this, &WebPage::setMediaEnvironment);
#endif
#if ENABLE(WRITING_TOOLS)
    if (decoder.messageName() == Messages::WebPage::WillBeginWritingToolsSession::name())
        return IPC::handleMessageAsync<Messages::WebPage::WillBeginWritingToolsSession>(connection, decoder, this, &WebPage::willBeginWritingToolsSession);
    if (decoder.messageName() == Messages::WebPage::DidBeginWritingToolsSession::name())
        return IPC::handleMessage<Messages::WebPage::DidBeginWritingToolsSession>(connection, decoder, this, &WebPage::didBeginWritingToolsSession);
    if (decoder.messageName() == Messages::WebPage::ProofreadingSessionDidReceiveSuggestions::name())
        return IPC::handleMessageAsync<Messages::WebPage::ProofreadingSessionDidReceiveSuggestions>(connection, decoder, this, &WebPage::proofreadingSessionDidReceiveSuggestions);
    if (decoder.messageName() == Messages::WebPage::ProofreadingSessionDidUpdateStateForSuggestion::name())
        return IPC::handleMessage<Messages::WebPage::ProofreadingSessionDidUpdateStateForSuggestion>(connection, decoder, this, &WebPage::proofreadingSessionDidUpdateStateForSuggestion);
    if (decoder.messageName() == Messages::WebPage::WillEndWritingToolsSession::name())
        return IPC::handleMessageAsync<Messages::WebPage::WillEndWritingToolsSession>(connection, decoder, this, &WebPage::willEndWritingToolsSession);
    if (decoder.messageName() == Messages::WebPage::DidEndWritingToolsSession::name())
        return IPC::handleMessage<Messages::WebPage::DidEndWritingToolsSession>(connection, decoder, this, &WebPage::didEndWritingToolsSession);
    if (decoder.messageName() == Messages::WebPage::CompositionSessionDidReceiveTextWithReplacementRange::name())
        return IPC::handleMessageAsync<Messages::WebPage::CompositionSessionDidReceiveTextWithReplacementRange>(connection, decoder, this, &WebPage::compositionSessionDidReceiveTextWithReplacementRange);
    if (decoder.messageName() == Messages::WebPage::WritingToolsSessionDidReceiveAction::name())
        return IPC::handleMessage<Messages::WebPage::WritingToolsSessionDidReceiveAction>(connection, decoder, this, &WebPage::writingToolsSessionDidReceiveAction);
    if (decoder.messageName() == Messages::WebPage::ProofreadingSessionSuggestionTextRectsInRootViewCoordinates::name())
        return IPC::handleMessageAsync<Messages::WebPage::ProofreadingSessionSuggestionTextRectsInRootViewCoordinates>(connection, decoder, this, &WebPage::proofreadingSessionSuggestionTextRectsInRootViewCoordinates);
    if (decoder.messageName() == Messages::WebPage::UpdateTextVisibilityForActiveWritingToolsSession::name())
        return IPC::handleMessageAsync<Messages::WebPage::UpdateTextVisibilityForActiveWritingToolsSession>(connection, decoder, this, &WebPage::updateTextVisibilityForActiveWritingToolsSession);
    if (decoder.messageName() == Messages::WebPage::TextPreviewDataForActiveWritingToolsSession::name())
        return IPC::handleMessageAsync<Messages::WebPage::TextPreviewDataForActiveWritingToolsSession>(connection, decoder, this, &WebPage::textPreviewDataForActiveWritingToolsSession);
    if (decoder.messageName() == Messages::WebPage::SetSelectionForActiveWritingToolsSession::name())
        return IPC::handleMessageAsync<Messages::WebPage::SetSelectionForActiveWritingToolsSession>(connection, decoder, this, &WebPage::setSelectionForActiveWritingToolsSession);
    if (decoder.messageName() == Messages::WebPage::DecorateTextReplacementsForActiveWritingToolsSession::name())
        return IPC::handleMessageAsync<Messages::WebPage::DecorateTextReplacementsForActiveWritingToolsSession>(connection, decoder, this, &WebPage::decorateTextReplacementsForActiveWritingToolsSession);
    if (decoder.messageName() == Messages::WebPage::CreateTextIndicatorForTextAnimationID::name())
        return IPC::handleMessageAsync<Messages::WebPage::CreateTextIndicatorForTextAnimationID>(connection, decoder, this, &WebPage::createTextIndicatorForTextAnimationID);
    if (decoder.messageName() == Messages::WebPage::UpdateUnderlyingTextVisibilityForTextAnimationID::name())
        return IPC::handleMessageAsync<Messages::WebPage::UpdateUnderlyingTextVisibilityForTextAnimationID>(connection, decoder, this, &WebPage::updateUnderlyingTextVisibilityForTextAnimationID);
    if (decoder.messageName() == Messages::WebPage::IntelligenceTextAnimationsDidComplete::name())
        return IPC::handleMessage<Messages::WebPage::IntelligenceTextAnimationsDidComplete>(connection, decoder, this, &WebPage::intelligenceTextAnimationsDidComplete);
#endif
#if PLATFORM(COCOA)
    if (decoder.messageName() == Messages::WebPage::CreateTextIndicatorForElementWithID::name())
        return IPC::handleMessageAsync<Messages::WebPage::CreateTextIndicatorForElementWithID>(connection, decoder, this, &WebPage::createTextIndicatorForElementWithID);
#endif
    if (decoder.messageName() == Messages::WebPage::TakeSnapshotForTargetedElement::name())
        return IPC::handleMessageAsync<Messages::WebPage::TakeSnapshotForTargetedElement>(connection, decoder, this, &WebPage::takeSnapshotForTargetedElement);
    if (decoder.messageName() == Messages::WebPage::ResetVisibilityAdjustmentsForTargetedElements::name())
        return IPC::handleMessageAsync<Messages::WebPage::ResetVisibilityAdjustmentsForTargetedElements>(connection, decoder, this, &WebPage::resetVisibilityAdjustmentsForTargetedElements);
    if (decoder.messageName() == Messages::WebPage::AdjustVisibilityForTargetedElements::name())
        return IPC::handleMessageAsync<Messages::WebPage::AdjustVisibilityForTargetedElements>(connection, decoder, this, &WebPage::adjustVisibilityForTargetedElements);
    if (decoder.messageName() == Messages::WebPage::NumberOfVisibilityAdjustmentRects::name())
        return IPC::handleMessageAsync<Messages::WebPage::NumberOfVisibilityAdjustmentRects>(connection, decoder, this, &WebPage::numberOfVisibilityAdjustmentRects);
    if (decoder.messageName() == Messages::WebPage::ContentsToRootViewRect::name())
        return IPC::handleMessageAsync<Messages::WebPage::ContentsToRootViewRect>(connection, decoder, this, &WebPage::contentsToRootViewRect);
    if (decoder.messageName() == Messages::WebPage::ContentsToRootViewPoint::name())
        return IPC::handleMessageAsync<Messages::WebPage::ContentsToRootViewPoint>(connection, decoder, this, &WebPage::contentsToRootViewPoint);
    if (decoder.messageName() == Messages::WebPage::RemoteDictionaryPopupInfoToRootView::name())
        return IPC::handleMessageAsync<Messages::WebPage::RemoteDictionaryPopupInfoToRootView>(connection, decoder, this, &WebPage::remoteDictionaryPopupInfoToRootView);
#if HAVE(SPATIAL_TRACKING_LABEL)
    if (decoder.messageName() == Messages::WebPage::SetDefaultSpatialTrackingLabel::name())
        return IPC::handleMessage<Messages::WebPage::SetDefaultSpatialTrackingLabel>(connection, decoder, this, &WebPage::setDefaultSpatialTrackingLabel);
#endif
    if (decoder.messageName() == Messages::WebPage::StartObservingNowPlayingMetadata::name())
        return IPC::handleMessage<Messages::WebPage::StartObservingNowPlayingMetadata>(connection, decoder, this, &WebPage::startObservingNowPlayingMetadata);
    if (decoder.messageName() == Messages::WebPage::StopObservingNowPlayingMetadata::name())
        return IPC::handleMessage<Messages::WebPage::StopObservingNowPlayingMetadata>(connection, decoder, this, &WebPage::stopObservingNowPlayingMetadata);
    if (decoder.messageName() == Messages::WebPage::LoadAndDecodeImage::name())
        return IPC::handleMessageAsync<Messages::WebPage::LoadAndDecodeImage>(connection, decoder, this, &WebPage::loadAndDecodeImage);
#if PLATFORM(COCOA)
    if (decoder.messageName() == Messages::WebPage::GetInformationFromImageData::name())
        return IPC::handleMessageAsync<Messages::WebPage::GetInformationFromImageData>(connection, decoder, this, &WebPage::getInformationFromImageData);
    if (decoder.messageName() == Messages::WebPage::CreateBitmapsFromImageData::name())
        return IPC::handleMessageAsync<Messages::WebPage::CreateBitmapsFromImageData>(connection, decoder, this, &WebPage::createBitmapsFromImageData);
    if (decoder.messageName() == Messages::WebPage::DecodeImageData::name())
        return IPC::handleMessageAsync<Messages::WebPage::DecodeImageData>(connection, decoder, this, &WebPage::decodeImageData);
#endif
    if (decoder.messageName() == Messages::WebPage::FrameNameWasChangedInAnotherProcess::name())
        return IPC::handleMessage<Messages::WebPage::FrameNameWasChangedInAnotherProcess>(connection, decoder, this, &WebPage::frameNameWasChangedInAnotherProcess);
#if ENABLE(VIDEO_PRESENTATION_MODE)
    if (decoder.messageName() == Messages::WebPage::StartPlayingPredominantVideo::name())
        return IPC::handleMessageAsync<Messages::WebPage::StartPlayingPredominantVideo>(connection, decoder, this, &WebPage::startPlayingPredominantVideo);
#endif
    if (decoder.messageName() == Messages::WebPage::CloseCurrentTypingCommand::name())
        return IPC::handleMessage<Messages::WebPage::CloseCurrentTypingCommand>(connection, decoder, this, &WebPage::closeCurrentTypingCommand);
    if (decoder.messageName() == Messages::WebPage::SimulateClickOverFirstMatchingTextInViewportWithUserInteraction::name())
        return IPC::handleMessageAsync<Messages::WebPage::SimulateClickOverFirstMatchingTextInViewportWithUserInteraction>(connection, decoder, this, &WebPage::simulateClickOverFirstMatchingTextInViewportWithUserInteraction);
    if (decoder.messageName() == Messages::WebPage::UpdateOpener::name())
        return IPC::handleMessage<Messages::WebPage::UpdateOpener>(connection, decoder, this, &WebPage::updateOpener);
#if HAVE(AUDIT_TOKEN)
    if (decoder.messageName() == Messages::WebPage::SetPresentingApplicationAuditTokenAndBundleIdentifier::name())
        return IPC::handleMessage<Messages::WebPage::SetPresentingApplicationAuditTokenAndBundleIdentifier>(connection, decoder, this, &WebPage::setPresentingApplicationAuditTokenAndBundleIdentifier);
#endif
#if USE(UICONTEXTMENU)
    if (decoder.messageName() == Messages::WebPage::WillBeginContextMenuInteraction::name())
        return IPC::handleMessage<Messages::WebPage::WillBeginContextMenuInteraction>(connection, decoder, this, &WebPage::willBeginContextMenuInteraction);
    if (decoder.messageName() == Messages::WebPage::DidEndContextMenuInteraction::name())
        return IPC::handleMessage<Messages::WebPage::DidEndContextMenuInteraction>(connection, decoder, this, &WebPage::didEndContextMenuInteraction);
#endif
    if (dispatchMessage(connection, decoder))
        return;
    UNUSED_PARAM(connection);
    RELEASE_LOG_ERROR(IPC, "Unhandled message %s to %" PRIu64, IPC::description(decoder.messageName()).characters(), decoder.destinationID());
    decoder.markInvalid();
}

bool WebPage::didReceiveSyncMessage(IPC::Connection& connection, IPC::Decoder& decoder, UniqueRef<IPC::Encoder>& replyEncoder)
{
    ASSERT(isInWebProcess());
    Ref protectedThis { *this };
    if (decoder.messageName() == Messages::WebPage::TestProcessIncomingSyncMessagesWhenWaitingForSyncReply::name())
        return IPC::handleMessageSynchronous<Messages::WebPage::TestProcessIncomingSyncMessagesWhenWaitingForSyncReply>(connection, decoder, replyEncoder, this, &WebPage::testProcessIncomingSyncMessagesWhenWaitingForSyncReply);
#if PLATFORM(IOS_FAMILY)
    if (decoder.messageName() == Messages::WebPage::SyncApplyAutocorrection::name())
        return IPC::handleMessageSynchronous<Messages::WebPage::SyncApplyAutocorrection>(connection, decoder, replyEncoder, this, &WebPage::syncApplyAutocorrection);
#endif
#if (PLATFORM(COCOA) && PLATFORM(IOS_FAMILY))
    if (decoder.messageName() == Messages::WebPage::ComputePagesForPrintingiOS::name())
        return IPC::handleMessageSynchronous<Messages::WebPage::ComputePagesForPrintingiOS>(connection, decoder, replyEncoder, this, &WebPage::computePagesForPrintingiOS);
#endif
    if (decoder.messageName() == Messages::WebPage::BindRemoteAccessibilityFrames::name())
        return IPC::handleMessageSynchronous<Messages::WebPage::BindRemoteAccessibilityFrames>(connection, decoder, replyEncoder, this, &WebPage::bindRemoteAccessibilityFrames);
#if PLATFORM(MAC)
    if (decoder.messageName() == Messages::WebPage::GetAccessibilityWebProcessDebugInfo::name())
        return IPC::handleMessageSynchronous<Messages::WebPage::GetAccessibilityWebProcessDebugInfo>(connection, decoder, replyEncoder, this, &WebPage::getAccessibilityWebProcessDebugInfo);
#endif
#if PLATFORM(COCOA)
    if (decoder.messageName() == Messages::WebPage::GetStringSelectionForPasteboard::name())
        return IPC::handleMessageSynchronous<Messages::WebPage::GetStringSelectionForPasteboard>(connection, decoder, replyEncoder, this, &WebPage::getStringSelectionForPasteboard);
    if (decoder.messageName() == Messages::WebPage::GetDataSelectionForPasteboard::name())
        return IPC::handleMessageSynchronous<Messages::WebPage::GetDataSelectionForPasteboard>(connection, decoder, replyEncoder, this, &WebPage::getDataSelectionForPasteboard);
    if (decoder.messageName() == Messages::WebPage::ReadSelectionFromPasteboard::name())
        return IPC::handleMessageSynchronous<Messages::WebPage::ReadSelectionFromPasteboard>(connection, decoder, replyEncoder, this, &WebPage::readSelectionFromPasteboard);
    if (decoder.messageName() == Messages::WebPage::ShouldDelayWindowOrderingEvent::name())
        return IPC::handleMessageSynchronous<Messages::WebPage::ShouldDelayWindowOrderingEvent>(connection, decoder, replyEncoder, this, &WebPage::shouldDelayWindowOrderingEvent);
#endif
    if (decoder.messageName() == Messages::WebPage::RenderTreeAsTextForTesting::name())
        return IPC::handleMessageSynchronous<Messages::WebPage::RenderTreeAsTextForTesting>(connection, decoder, replyEncoder, this, &WebPage::renderTreeAsTextForTesting);
    if (decoder.messageName() == Messages::WebPage::LayerTreeAsTextForTesting::name())
        return IPC::handleMessageSynchronous<Messages::WebPage::LayerTreeAsTextForTesting>(connection, decoder, replyEncoder, this, &WebPage::layerTreeAsTextForTesting);
    if (decoder.messageName() == Messages::WebPage::FrameTextForTesting::name())
        return IPC::handleMessageSynchronous<Messages::WebPage::FrameTextForTesting>(connection, decoder, replyEncoder, this, &WebPage::frameTextForTesting);
    UNUSED_PARAM(connection);
    UNUSED_PARAM(replyEncoder);
    RELEASE_LOG_ERROR(IPC, "Unhandled synchronous message %s to %" PRIu64, description(decoder.messageName()).characters(), decoder.destinationID());
    decoder.markInvalid();
    return false;
}

} // namespace WebKit

#if ENABLE(IPC_TESTING_API)

namespace IPC {

template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetInitialFocus>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetInitialFocus::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_SetInitialFocus>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetInitialFocus::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetActivityState>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetActivityState::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_SetActivityState>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetActivityState::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetBackgroundColor>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetBackgroundColor::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_AddConsoleMessage>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::AddConsoleMessage::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_EnqueueSecurityPolicyViolationEvent>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::EnqueueSecurityPolicyViolationEvent::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SendReportToEndpoints>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SendReportToEndpoints::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_NotifyReportObservers>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::NotifyReportObservers::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_TestProcessIncomingSyncMessagesWhenWaitingForSyncReply>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::TestProcessIncomingSyncMessagesWhenWaitingForSyncReply::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_TestProcessIncomingSyncMessagesWhenWaitingForSyncReply>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::TestProcessIncomingSyncMessagesWhenWaitingForSyncReply::ReplyArguments>(globalObject, decoder);
}
#if PLATFORM(COCOA)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetObscuredContentInsetsFenced>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetObscuredContentInsetsFenced::Arguments>(globalObject, decoder);
}
#endif
#if !PLATFORM(COCOA)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetObscuredContentInsets>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetObscuredContentInsets::Arguments>(globalObject, decoder);
}
#endif
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetShouldSuppressHDR>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetShouldSuppressHDR::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetUnderlayColor>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetUnderlayColor::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetUnderPageBackgroundColorOverride>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetUnderPageBackgroundColorOverride::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetNeedsFixedContainerEdgesUpdate>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetNeedsFixedContainerEdgesUpdate::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_ViewWillStartLiveResize>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ViewWillStartLiveResize::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_ViewWillEndLiveResize>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ViewWillEndLiveResize::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_ExecuteEditCommandWithCallback>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ExecuteEditCommandWithCallback::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_ExecuteEditCommandWithCallback>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ExecuteEditCommandWithCallback::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_KeyEvent>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::KeyEvent::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_MouseEvent>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::MouseEvent::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetLastKnownMousePosition>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetLastKnownMousePosition::Arguments>(globalObject, decoder);
}
#if PLATFORM(IOS_FAMILY)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetSceneIdentifier>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetSceneIdentifier::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetViewportConfigurationViewLayoutSize>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetViewportConfigurationViewLayoutSize::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetDeviceOrientation>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetDeviceOrientation::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetOverrideViewportArguments>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetOverrideViewportArguments::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_DynamicViewportSizeUpdate>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::DynamicViewportSizeUpdate::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetScreenIsBeingCaptured>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetScreenIsBeingCaptured::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetInsertionPointColor>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetInsertionPointColor::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_AttemptSyntheticClick>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::AttemptSyntheticClick::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_PotentialTapAtPosition>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::PotentialTapAtPosition::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_PotentialTapAtPosition>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::PotentialTapAtPosition::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_CommitPotentialTap>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::CommitPotentialTap::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_CommitPotentialTap>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::CommitPotentialTap::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_CancelPotentialTap>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::CancelPotentialTap::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_TapHighlightAtPosition>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::TapHighlightAtPosition::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_DidRecognizeLongPress>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::DidRecognizeLongPress::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_HandleDoubleTapForDoubleClickAtPoint>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::HandleDoubleTapForDoubleClickAtPoint::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_InspectorNodeSearchMovedToPosition>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::InspectorNodeSearchMovedToPosition::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_InspectorNodeSearchEndedAtPosition>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::InspectorNodeSearchEndedAtPosition::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_BlurFocusedElement>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::BlurFocusedElement::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SelectWithGesture>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SelectWithGesture::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_SelectWithGesture>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SelectWithGesture::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_UpdateSelectionWithTouches>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::UpdateSelectionWithTouches::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_UpdateSelectionWithTouches>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::UpdateSelectionWithTouches::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SelectWithTwoTouches>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SelectWithTwoTouches::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_SelectWithTwoTouches>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SelectWithTwoTouches::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_ExtendSelection>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ExtendSelection::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_ExtendSelection>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ExtendSelection::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SelectWordBackward>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SelectWordBackward::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_ExtendSelectionForReplacement>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ExtendSelectionForReplacement::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_ExtendSelectionForReplacement>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ExtendSelectionForReplacement::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_MoveSelectionByOffset>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::MoveSelectionByOffset::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_MoveSelectionByOffset>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::MoveSelectionByOffset::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SelectTextWithGranularityAtPoint>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SelectTextWithGranularityAtPoint::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_SelectTextWithGranularityAtPoint>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SelectTextWithGranularityAtPoint::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SelectPositionAtBoundaryWithDirection>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SelectPositionAtBoundaryWithDirection::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_SelectPositionAtBoundaryWithDirection>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SelectPositionAtBoundaryWithDirection::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_MoveSelectionAtBoundaryWithDirection>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::MoveSelectionAtBoundaryWithDirection::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_MoveSelectionAtBoundaryWithDirection>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::MoveSelectionAtBoundaryWithDirection::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SelectPositionAtPoint>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SelectPositionAtPoint::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_SelectPositionAtPoint>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SelectPositionAtPoint::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_BeginSelectionInDirection>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::BeginSelectionInDirection::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_BeginSelectionInDirection>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::BeginSelectionInDirection::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_UpdateSelectionWithExtentPoint>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::UpdateSelectionWithExtentPoint::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_UpdateSelectionWithExtentPoint>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::UpdateSelectionWithExtentPoint::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_UpdateSelectionWithExtentPointAndBoundary>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::UpdateSelectionWithExtentPointAndBoundary::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_UpdateSelectionWithExtentPointAndBoundary>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::UpdateSelectionWithExtentPointAndBoundary::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_DidReleaseAllTouchPoints>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::DidReleaseAllTouchPoints::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_ClearSelectionAfterTappingSelectionHighlightIfNeeded>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ClearSelectionAfterTappingSelectionHighlightIfNeeded::Arguments>(globalObject, decoder);
}
#endif
#if (PLATFORM(IOS_FAMILY) && ENABLE(REVEAL))
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_RequestRVItemInCurrentSelectedRange>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::RequestRVItemInCurrentSelectedRange::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_RequestRVItemInCurrentSelectedRange>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::RequestRVItemInCurrentSelectedRange::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_PrepareSelectionForContextMenuWithLocationInView>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::PrepareSelectionForContextMenuWithLocationInView::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_PrepareSelectionForContextMenuWithLocationInView>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::PrepareSelectionForContextMenuWithLocationInView::ReplyArguments>(globalObject, decoder);
}
#endif
#if PLATFORM(IOS_FAMILY)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_WillInsertFinalDictationResult>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::WillInsertFinalDictationResult::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_DidInsertFinalDictationResult>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::DidInsertFinalDictationResult::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_ReplaceDictatedText>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ReplaceDictatedText::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_ReplaceSelectedText>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ReplaceSelectedText::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_RequestAutocorrectionData>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::RequestAutocorrectionData::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_RequestAutocorrectionData>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::RequestAutocorrectionData::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_ApplyAutocorrection>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ApplyAutocorrection::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_ApplyAutocorrection>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ApplyAutocorrection::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SyncApplyAutocorrection>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SyncApplyAutocorrection::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_SyncApplyAutocorrection>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SyncApplyAutocorrection::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_HandleAutocorrectionContextRequest>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::HandleAutocorrectionContextRequest::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_RequestEvasionRectsAboveSelection>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::RequestEvasionRectsAboveSelection::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_RequestEvasionRectsAboveSelection>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::RequestEvasionRectsAboveSelection::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_RequestPositionInformation>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::RequestPositionInformation::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_StartInteractionWithElementContextOrPosition>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::StartInteractionWithElementContextOrPosition::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_StopInteraction>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::StopInteraction::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_PerformActionOnElement>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::PerformActionOnElement::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_PerformActionOnElement>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::PerformActionOnElement::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_PerformActionOnElements>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::PerformActionOnElements::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_FocusNextFocusedElement>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::FocusNextFocusedElement::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_FocusNextFocusedElement>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::FocusNextFocusedElement::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_AutofillLoginCredentials>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::AutofillLoginCredentials::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetFocusedElementValue>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetFocusedElementValue::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetFocusedElementSelectedIndex>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetFocusedElementSelectedIndex::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_ApplicationWillResignActive>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ApplicationWillResignActive::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_ApplicationDidEnterBackground>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ApplicationDidEnterBackground::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_ApplicationDidFinishSnapshottingAfterEnteringBackground>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ApplicationDidFinishSnapshottingAfterEnteringBackground::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_ApplicationWillEnterForeground>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ApplicationWillEnterForeground::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_ApplicationDidBecomeActive>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ApplicationDidBecomeActive::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_ApplicationDidEnterBackgroundForMedia>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ApplicationDidEnterBackgroundForMedia::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_ApplicationWillEnterForegroundForMedia>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ApplicationWillEnterForegroundForMedia::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_ContentSizeCategoryDidChange>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ContentSizeCategoryDidChange::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_GetSelectionContext>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::GetSelectionContext::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_GetSelectionContext>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::GetSelectionContext::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetAllowsMediaDocumentInlinePlayback>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetAllowsMediaDocumentInlinePlayback::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_HandleTwoFingerTapAtPoint>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::HandleTwoFingerTapAtPoint::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetForceAlwaysUserScalable>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetForceAlwaysUserScalable::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_GetRectsForGranularityWithSelectionOffset>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::GetRectsForGranularityWithSelectionOffset::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_GetRectsForGranularityWithSelectionOffset>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::GetRectsForGranularityWithSelectionOffset::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_GetRectsAtSelectionOffsetWithText>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::GetRectsAtSelectionOffsetWithText::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_GetRectsAtSelectionOffsetWithText>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::GetRectsAtSelectionOffsetWithText::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_StoreSelectionForAccessibility>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::StoreSelectionForAccessibility::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_StartAutoscrollAtPosition>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::StartAutoscrollAtPosition::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_CancelAutoscroll>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::CancelAutoscroll::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_RequestFocusedElementInformation>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::RequestFocusedElementInformation::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_RequestFocusedElementInformation>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::RequestFocusedElementInformation::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_HardwareKeyboardAvailabilityChanged>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::HardwareKeyboardAvailabilityChanged::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetIsShowingInputViewForFocusedElement>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetIsShowingInputViewForFocusedElement::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_UpdateSelectionWithDelta>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::UpdateSelectionWithDelta::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_UpdateSelectionWithDelta>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::UpdateSelectionWithDelta::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_RequestDocumentEditingContext>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::RequestDocumentEditingContext::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_RequestDocumentEditingContext>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::RequestDocumentEditingContext::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_GenerateSyntheticEditingCommand>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::GenerateSyntheticEditingCommand::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetShouldRevealCurrentSelectionAfterInsertion>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetShouldRevealCurrentSelectionAfterInsertion::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_TextInputContextsInRect>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::TextInputContextsInRect::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_TextInputContextsInRect>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::TextInputContextsInRect::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_FocusTextInputContextAndPlaceCaret>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::FocusTextInputContextAndPlaceCaret::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_FocusTextInputContextAndPlaceCaret>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::FocusTextInputContextAndPlaceCaret::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_ClearServiceWorkerEntitlementOverride>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ClearServiceWorkerEntitlementOverride::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_ClearServiceWorkerEntitlementOverride>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ClearServiceWorkerEntitlementOverride::ReplyArguments>(globalObject, decoder);
}
#endif
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_ProcessWillSuspend>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ProcessWillSuspend::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_ProcessDidResume>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ProcessDidResume::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_RequestImageBitmap>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::RequestImageBitmap::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_RequestImageBitmap>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::RequestImageBitmap::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetControlledByAutomation>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetControlledByAutomation::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_ConnectInspector>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ConnectInspector::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_DisconnectInspector>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::DisconnectInspector::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SendMessageToTargetBackend>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SendMessageToTargetBackend::Arguments>(globalObject, decoder);
}
#if ENABLE(REMOTE_INSPECTOR)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetIndicating>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetIndicating::Arguments>(globalObject, decoder);
}
#endif
#if ENABLE(IOS_TOUCH_EVENTS)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_DidBeginTouchPoint>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::DidBeginTouchPoint::Arguments>(globalObject, decoder);
}
#endif
#if !ENABLE(IOS_TOUCH_EVENTS) && ENABLE(TOUCH_EVENTS)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_TouchEvent>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::TouchEvent::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_TouchEvent>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::TouchEvent::ReplyArguments>(globalObject, decoder);
}
#endif
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_CancelPointer>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::CancelPointer::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_TouchWithIdentifierWasRemoved>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::TouchWithIdentifierWasRemoved::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_DidEndColorPicker>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::DidEndColorPicker::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_DidChooseColor>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::DidChooseColor::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_DidSelectDataListOption>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::DidSelectDataListOption::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_DidCloseSuggestions>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::DidCloseSuggestions::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_DidChooseDate>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::DidChooseDate::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_DidEndDateTimePicker>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::DidEndDateTimePicker::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_ScrollBy>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ScrollBy::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_CenterSelectionInVisibleArea>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::CenterSelectionInVisibleArea::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_GoToBackForwardItem>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::GoToBackForwardItem::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_GoToBackForwardItemWaitingForProcessLaunch>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::GoToBackForwardItemWaitingForProcessLaunch::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_TryRestoreScrollPosition>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::TryRestoreScrollPosition::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_LoadURLInFrame>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::LoadURLInFrame::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_LoadDataInFrame>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::LoadDataInFrame::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_LoadRequest>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::LoadRequest::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_LoadDidCommitInAnotherProcess>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::LoadDidCommitInAnotherProcess::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_LoadRequestWaitingForProcessLaunch>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::LoadRequestWaitingForProcessLaunch::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_LoadData>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::LoadData::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_LoadSimulatedRequestAndResponse>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::LoadSimulatedRequestAndResponse::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_LoadAlternateHTML>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::LoadAlternateHTML::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_CreateRemoteSubframe>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::CreateRemoteSubframe::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_GetFrameTree>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::GetFrameTree::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_GetFrameTree>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::GetFrameTree::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_DidFinishLoadInAnotherProcess>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::DidFinishLoadInAnotherProcess::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_FrameWasRemovedInAnotherProcess>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::FrameWasRemovedInAnotherProcess::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_UpdateFrameTreeSyncData>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::UpdateFrameTreeSyncData::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_ProcessSyncDataChangedInAnotherProcess>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ProcessSyncDataChangedInAnotherProcess::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_TopDocumentSyncDataChangedInAnotherProcess>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::TopDocumentSyncDataChangedInAnotherProcess::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_NavigateToPDFLinkWithSimulatedClick>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::NavigateToPDFLinkWithSimulatedClick::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_GetPDFFirstPageSize>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::GetPDFFirstPageSize::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_GetPDFFirstPageSize>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::GetPDFFirstPageSize::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_Reload>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::Reload::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_StopLoading>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::StopLoading::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_StopLoadingDueToProcessSwap>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::StopLoadingDueToProcessSwap::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetCurrentHistoryItemForReattach>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetCurrentHistoryItemForReattach::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_DidRemoveBackForwardItem>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::DidRemoveBackForwardItem::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_UpdateWebsitePolicies>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::UpdateWebsitePolicies::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_ClearSelection>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ClearSelection::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_RestoreSelectionInFocusedEditableElement>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::RestoreSelectionInFocusedEditableElement::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_GetContentsAsString>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::GetContentsAsString::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_GetContentsAsString>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::GetContentsAsString::ReplyArguments>(globalObject, decoder);
}
#if PLATFORM(COCOA)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_GetContentsAsAttributedString>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::GetContentsAsAttributedString::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_GetContentsAsAttributedString>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::GetContentsAsAttributedString::ReplyArguments>(globalObject, decoder);
}
#endif
#if ENABLE(MHTML)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_GetContentsAsMHTMLData>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::GetContentsAsMHTMLData::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_GetContentsAsMHTMLData>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::GetContentsAsMHTMLData::ReplyArguments>(globalObject, decoder);
}
#endif
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_GetMainResourceDataOfFrame>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::GetMainResourceDataOfFrame::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_GetMainResourceDataOfFrame>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::GetMainResourceDataOfFrame::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_GetResourceDataFromFrame>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::GetResourceDataFromFrame::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_GetResourceDataFromFrame>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::GetResourceDataFromFrame::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_GetRenderTreeExternalRepresentation>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::GetRenderTreeExternalRepresentation::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_GetRenderTreeExternalRepresentation>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::GetRenderTreeExternalRepresentation::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_GetSelectionOrContentsAsString>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::GetSelectionOrContentsAsString::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_GetSelectionOrContentsAsString>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::GetSelectionOrContentsAsString::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_GetSelectionAsWebArchiveData>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::GetSelectionAsWebArchiveData::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_GetSelectionAsWebArchiveData>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::GetSelectionAsWebArchiveData::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_GetSourceForFrame>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::GetSourceForFrame::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_GetSourceForFrame>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::GetSourceForFrame::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_GetWebArchiveOfFrame>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::GetWebArchiveOfFrame::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_GetWebArchiveOfFrame>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::GetWebArchiveOfFrame::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_GetWebArchiveOfFrameWithFileName>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::GetWebArchiveOfFrameWithFileName::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_GetWebArchiveOfFrameWithFileName>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::GetWebArchiveOfFrameWithFileName::ReplyArguments>(globalObject, decoder);
}
#if PLATFORM(COCOA)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_GetWebArchives>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::GetWebArchives::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_GetWebArchives>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::GetWebArchives::ReplyArguments>(globalObject, decoder);
}
#endif
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_RunJavaScriptInFrameInScriptWorld>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::RunJavaScriptInFrameInScriptWorld::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_RunJavaScriptInFrameInScriptWorld>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::RunJavaScriptInFrameInScriptWorld::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_GetAccessibilityTreeData>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::GetAccessibilityTreeData::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_GetAccessibilityTreeData>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::GetAccessibilityTreeData::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_UpdateRenderingWithForcedRepaint>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::UpdateRenderingWithForcedRepaint::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_UpdateRenderingWithForcedRepaint>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::UpdateRenderingWithForcedRepaint::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SelectAll>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SelectAll::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_ScheduleFullEditorStateUpdate>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ScheduleFullEditorStateUpdate::Arguments>(globalObject, decoder);
}
#if PLATFORM(COCOA)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_PerformDictionaryLookupAtLocation>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::PerformDictionaryLookupAtLocation::Arguments>(globalObject, decoder);
}
#endif
#if ENABLE(DATA_DETECTION)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_DetectDataInAllFrames>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::DetectDataInAllFrames::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_DetectDataInAllFrames>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::DetectDataInAllFrames::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_RemoveDataDetectedLinks>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::RemoveDataDetectedLinks::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_RemoveDataDetectedLinks>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::RemoveDataDetectedLinks::ReplyArguments>(globalObject, decoder);
}
#endif
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_ChangeFont>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ChangeFont::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_ChangeFontAttributes>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ChangeFontAttributes::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_PreferencesDidChange>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::PreferencesDidChange::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_PreferencesDidChangeDuringDOMPrintOperation>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::PreferencesDidChangeDuringDOMPrintOperation::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetUserAgent>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetUserAgent::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetHasCustomUserAgent>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetHasCustomUserAgent::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetCustomTextEncodingName>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetCustomTextEncodingName::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SuspendActiveDOMObjectsAndAnimations>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SuspendActiveDOMObjectsAndAnimations::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_ResumeActiveDOMObjectsAndAnimations>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ResumeActiveDOMObjectsAndAnimations::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_Suspend>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::Suspend::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_Suspend>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::Suspend::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_Resume>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::Resume::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_Resume>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::Resume::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_Close>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::Close::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_TryClose>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::TryClose::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_TryClose>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::TryClose::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetEditable>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetEditable::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_ValidateCommand>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ValidateCommand::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_ValidateCommand>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ValidateCommand::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_ExecuteEditCommand>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ExecuteEditCommand::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_IncreaseListLevel>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::IncreaseListLevel::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_DecreaseListLevel>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::DecreaseListLevel::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_ChangeListType>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ChangeListType::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetBaseWritingDirection>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetBaseWritingDirection::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetNeedsFontAttributes>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetNeedsFontAttributes::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_RequestFontAttributesAtSelectionStart>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::RequestFontAttributesAtSelectionStart::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_RequestFontAttributesAtSelectionStart>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::RequestFontAttributesAtSelectionStart::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_DidRemoveEditCommand>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::DidRemoveEditCommand::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_ReapplyEditCommand>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ReapplyEditCommand::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_UnapplyEditCommand>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::UnapplyEditCommand::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_DidSetPageZoomFactor>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::DidSetPageZoomFactor::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_DidSetTextZoomFactor>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::DidSetTextZoomFactor::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_WindowScreenDidChange>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::WindowScreenDidChange::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_AccessibilitySettingsDidChange>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::AccessibilitySettingsDidChange::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_DidScalePage>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::DidScalePage::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_DidScalePageInViewCoordinates>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::DidScalePageInViewCoordinates::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_DidScalePageRelativeToScrollPosition>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::DidScalePageRelativeToScrollPosition::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_DidScaleView>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::DidScaleView::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetUseFixedLayout>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetUseFixedLayout::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetFixedLayoutSize>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetFixedLayoutSize::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetDefaultUnobscuredSize>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetDefaultUnobscuredSize::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetMinimumUnobscuredSize>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetMinimumUnobscuredSize::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetMaximumUnobscuredSize>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetMaximumUnobscuredSize::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_ListenForLayoutMilestones>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ListenForLayoutMilestones::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetSuppressScrollbarAnimations>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetSuppressScrollbarAnimations::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetEnableVerticalRubberBanding>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetEnableVerticalRubberBanding::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetEnableHorizontalRubberBanding>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetEnableHorizontalRubberBanding::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetBackgroundExtendsBeyondPage>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetBackgroundExtendsBeyondPage::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetPaginationMode>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetPaginationMode::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetPaginationBehavesLikeColumns>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetPaginationBehavesLikeColumns::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetPageLength>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetPageLength::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetGapBetweenPages>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetGapBetweenPages::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_PostInjectedBundleMessage>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::PostInjectedBundleMessage::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_FindString>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::FindString::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_FindString>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::FindString::ReplyArguments>(globalObject, decoder);
}
#if ENABLE(IMAGE_ANALYSIS)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_FindStringIncludingImages>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::FindStringIncludingImages::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_FindStringIncludingImages>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::FindStringIncludingImages::ReplyArguments>(globalObject, decoder);
}
#endif
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_FindStringMatches>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::FindStringMatches::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_FindStringMatches>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::FindStringMatches::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_GetImageForFindMatch>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::GetImageForFindMatch::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SelectFindMatch>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SelectFindMatch::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_IndicateFindMatch>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::IndicateFindMatch::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_HideFindUI>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::HideFindUI::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_CountStringMatches>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::CountStringMatches::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_CountStringMatches>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::CountStringMatches::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_ReplaceMatches>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ReplaceMatches::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_ReplaceMatches>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ReplaceMatches::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_FindRectsForStringMatches>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::FindRectsForStringMatches::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_FindRectsForStringMatches>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::FindRectsForStringMatches::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_FindTextRangesForStringMatches>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::FindTextRangesForStringMatches::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_FindTextRangesForStringMatches>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::FindTextRangesForStringMatches::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_ReplaceFoundTextRangeWithString>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ReplaceFoundTextRangeWithString::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_DecorateTextRangeWithStyle>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::DecorateTextRangeWithStyle::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_ScrollTextRangeToVisible>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ScrollTextRangeToVisible::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_ClearAllDecoratedFoundText>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ClearAllDecoratedFoundText::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_DidBeginTextSearchOperation>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::DidBeginTextSearchOperation::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_RequestRectForFoundTextRange>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::RequestRectForFoundTextRange::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_RequestRectForFoundTextRange>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::RequestRectForFoundTextRange::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_AddLayerForFindOverlay>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::AddLayerForFindOverlay::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_AddLayerForFindOverlay>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::AddLayerForFindOverlay::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_RemoveLayerForFindOverlay>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::RemoveLayerForFindOverlay::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_RemoveLayerForFindOverlay>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::RemoveLayerForFindOverlay::ReplyArguments>(globalObject, decoder);
}
#if PLATFORM(GTK) && ENABLE(DRAG_SUPPORT)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_PerformDragControllerAction>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::PerformDragControllerAction::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_PerformDragControllerAction>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::PerformDragControllerAction::ReplyArguments>(globalObject, decoder);
}
#endif
#if !PLATFORM(GTK) && ENABLE(DRAG_SUPPORT)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_PerformDragControllerAction>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::PerformDragControllerAction::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_PerformDragControllerAction>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::PerformDragControllerAction::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_PerformDragOperation>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::PerformDragOperation::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_PerformDragOperation>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::PerformDragOperation::ReplyArguments>(globalObject, decoder);
}
#endif
#if ENABLE(DRAG_SUPPORT)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_DidStartDrag>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::DidStartDrag::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_DragEnded>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::DragEnded::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_DragEnded>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::DragEnded::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_DragCancelled>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::DragCancelled::Arguments>(globalObject, decoder);
}
#endif
#if ENABLE(MODEL_PROCESS)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_RequestInteractiveModelElementAtPoint>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::RequestInteractiveModelElementAtPoint::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_StageModeSessionDidUpdate>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::StageModeSessionDidUpdate::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_StageModeSessionDidEnd>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::StageModeSessionDidEnd::Arguments>(globalObject, decoder);
}
#endif
#if ENABLE(MODEL_PROCESS) && ENABLE(DRAG_SUPPORT)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_ModelDragEnded>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ModelDragEnded::Arguments>(globalObject, decoder);
}
#endif
#if PLATFORM(IOS_FAMILY) && ENABLE(DRAG_SUPPORT)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_RequestDragStart>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::RequestDragStart::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_RequestDragStart>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::RequestDragStart::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_RequestAdditionalItemsForDragSession>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::RequestAdditionalItemsForDragSession::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_RequestAdditionalItemsForDragSession>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::RequestAdditionalItemsForDragSession::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_InsertDroppedImagePlaceholders>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::InsertDroppedImagePlaceholders::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_InsertDroppedImagePlaceholders>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::InsertDroppedImagePlaceholders::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_DidConcludeDrop>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::DidConcludeDrop::Arguments>(globalObject, decoder);
}
#endif
#if PLATFORM(COCOA)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_InsertTextPlaceholder>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::InsertTextPlaceholder::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_InsertTextPlaceholder>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::InsertTextPlaceholder::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_RemoveTextPlaceholder>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::RemoveTextPlaceholder::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_RemoveTextPlaceholder>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::RemoveTextPlaceholder::ReplyArguments>(globalObject, decoder);
}
#endif
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_DidChangeSelectedIndexForActivePopupMenu>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::DidChangeSelectedIndexForActivePopupMenu::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetTextForActivePopupMenu>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetTextForActivePopupMenu::Arguments>(globalObject, decoder);
}
#if PLATFORM(GTK)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_FailedToShowPopupMenu>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::FailedToShowPopupMenu::Arguments>(globalObject, decoder);
}
#endif
#if ENABLE(CONTEXT_MENUS)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_DidDismissContextMenu>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::DidDismissContextMenu::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_DidSelectItemFromActiveContextMenu>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::DidSelectItemFromActiveContextMenu::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_ContextMenuForKeyEvent>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ContextMenuForKeyEvent::Arguments>(globalObject, decoder);
}
#endif
#if PLATFORM(IOS_FAMILY)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_DidChooseFilesForOpenPanelWithDisplayStringAndIcon>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::DidChooseFilesForOpenPanelWithDisplayStringAndIcon::Arguments>(globalObject, decoder);
}
#endif
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_DidChooseFilesForOpenPanel>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::DidChooseFilesForOpenPanel::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_DidCancelForOpenPanel>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::DidCancelForOpenPanel::Arguments>(globalObject, decoder);
}
#if ENABLE(SANDBOX_EXTENSIONS)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_ExtendSandboxForFilesFromOpenPanel>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ExtendSandboxForFilesFromOpenPanel::Arguments>(globalObject, decoder);
}
#endif
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_AdvanceToNextMisspelling>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::AdvanceToNextMisspelling::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_ChangeSpellingToWord>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ChangeSpellingToWord::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_DidFinishCheckingText>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::DidFinishCheckingText::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_DidCancelCheckingText>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::DidCancelCheckingText::Arguments>(globalObject, decoder);
}
#if USE(APPKIT)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_UppercaseWord>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::UppercaseWord::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_LowercaseWord>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::LowercaseWord::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_CapitalizeWord>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::CapitalizeWord::Arguments>(globalObject, decoder);
}
#endif
#if PLATFORM(COCOA)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetSmartInsertDeleteEnabled>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetSmartInsertDeleteEnabled::Arguments>(globalObject, decoder);
}
#endif
#if ENABLE(GEOLOCATION)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_DidReceiveGeolocationPermissionDecision>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::DidReceiveGeolocationPermissionDecision::Arguments>(globalObject, decoder);
}
#endif
#if ENABLE(MEDIA_STREAM)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_UserMediaAccessWasGranted>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::UserMediaAccessWasGranted::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_UserMediaAccessWasGranted>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::UserMediaAccessWasGranted::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_UserMediaAccessWasDenied>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::UserMediaAccessWasDenied::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_CaptureDevicesChanged>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::CaptureDevicesChanged::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_VoiceActivityDetected>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::VoiceActivityDetected::Arguments>(globalObject, decoder);
}
#endif
#if (ENABLE(MEDIA_STREAM) && USE(GSTREAMER))
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetOrientationForMediaCapture>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetOrientationForMediaCapture::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetMockCaptureDevicesInterrupted>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetMockCaptureDevicesInterrupted::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_TriggerMockCaptureConfigurationChange>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::TriggerMockCaptureConfigurationChange::Arguments>(globalObject, decoder);
}
#endif
#if ENABLE(ENCRYPTED_MEDIA)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_MediaKeySystemWasGranted>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::MediaKeySystemWasGranted::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_MediaKeySystemWasDenied>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::MediaKeySystemWasDenied::Arguments>(globalObject, decoder);
}
#endif
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_RequestMediaPlaybackState>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::RequestMediaPlaybackState::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_RequestMediaPlaybackState>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::RequestMediaPlaybackState::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_PauseAllMediaPlayback>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::PauseAllMediaPlayback::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_PauseAllMediaPlayback>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::PauseAllMediaPlayback::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SuspendAllMediaPlayback>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SuspendAllMediaPlayback::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_SuspendAllMediaPlayback>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SuspendAllMediaPlayback::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_ResumeAllMediaPlayback>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ResumeAllMediaPlayback::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_ResumeAllMediaPlayback>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ResumeAllMediaPlayback::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SwipeAnimationDidStart>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SwipeAnimationDidStart::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SwipeAnimationDidEnd>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SwipeAnimationDidEnd::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_BeginPrinting>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::BeginPrinting::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_BeginPrintingDuringDOMPrintOperation>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::BeginPrintingDuringDOMPrintOperation::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_EndPrinting>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::EndPrinting::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_EndPrinting>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::EndPrinting::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_EndPrintingDuringDOMPrintOperation>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::EndPrintingDuringDOMPrintOperation::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_EndPrintingDuringDOMPrintOperation>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::EndPrintingDuringDOMPrintOperation::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_ComputePagesForPrinting>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ComputePagesForPrinting::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_ComputePagesForPrinting>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ComputePagesForPrinting::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_ComputePagesForPrintingDuringDOMPrintOperation>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ComputePagesForPrintingDuringDOMPrintOperation::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_ComputePagesForPrintingDuringDOMPrintOperation>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ComputePagesForPrintingDuringDOMPrintOperation::ReplyArguments>(globalObject, decoder);
}
#if PLATFORM(COCOA)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_DrawRectToImage>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::DrawRectToImage::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_DrawRectToImage>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::DrawRectToImage::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_DrawRectToImageDuringDOMPrintOperation>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::DrawRectToImageDuringDOMPrintOperation::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_DrawRectToImageDuringDOMPrintOperation>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::DrawRectToImageDuringDOMPrintOperation::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_DrawPagesToPDF>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::DrawPagesToPDF::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_DrawPagesToPDF>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::DrawPagesToPDF::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_DrawPagesToPDFDuringDOMPrintOperation>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::DrawPagesToPDFDuringDOMPrintOperation::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_DrawPagesToPDFDuringDOMPrintOperation>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::DrawPagesToPDFDuringDOMPrintOperation::ReplyArguments>(globalObject, decoder);
}
#endif
#if (PLATFORM(COCOA) && PLATFORM(IOS_FAMILY))
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_ComputePagesForPrintingiOS>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ComputePagesForPrintingiOS::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_ComputePagesForPrintingiOS>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ComputePagesForPrintingiOS::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_DrawToPDFiOS>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::DrawToPDFiOS::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_DrawToPDFiOS>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::DrawToPDFiOS::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_DrawToImage>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::DrawToImage::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_DrawToImage>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::DrawToImage::ReplyArguments>(globalObject, decoder);
}
#endif
#if PLATFORM(COCOA)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_DrawToPDF>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::DrawToPDF::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_DrawToPDF>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::DrawToPDF::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_DrawRemoteToPDF>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::DrawRemoteToPDF::Arguments>(globalObject, decoder);
}
#endif
#if PLATFORM(GTK)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_DrawPagesForPrinting>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::DrawPagesForPrinting::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_DrawPagesForPrinting>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::DrawPagesForPrinting::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_DrawPagesForPrintingDuringDOMPrintOperation>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::DrawPagesForPrintingDuringDOMPrintOperation::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_DrawPagesForPrintingDuringDOMPrintOperation>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::DrawPagesForPrintingDuringDOMPrintOperation::ReplyArguments>(globalObject, decoder);
}
#endif
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetMediaVolume>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetMediaVolume::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetMuted>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetMuted::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_SetMuted>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetMuted::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetMayStartMediaWhenInWindow>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetMayStartMediaWhenInWindow::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_StopMediaCapture>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::StopMediaCapture::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_StopMediaCapture>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::StopMediaCapture::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetCanRunBeforeUnloadConfirmPanel>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetCanRunBeforeUnloadConfirmPanel::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetCanRunModal>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetCanRunModal::Arguments>(globalObject, decoder);
}
#if PLATFORM(GTK) || PLATFORM(WPE)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_CancelComposition>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::CancelComposition::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_DeleteSurrounding>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::DeleteSurrounding::Arguments>(globalObject, decoder);
}
#endif
#if PLATFORM(GTK)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_CollapseSelectionInFrame>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::CollapseSelectionInFrame::Arguments>(globalObject, decoder);
}
#endif
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_CopyLinkWithHighlight>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::CopyLinkWithHighlight::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_BindRemoteAccessibilityFrames>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::BindRemoteAccessibilityFrames::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_BindRemoteAccessibilityFrames>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::BindRemoteAccessibilityFrames::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_UpdateRemotePageAccessibilityOffset>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::UpdateRemotePageAccessibilityOffset::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_ResolveAccessibilityHitTestForTesting>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ResolveAccessibilityHitTestForTesting::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_ResolveAccessibilityHitTestForTesting>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ResolveAccessibilityHitTestForTesting::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_EnableAccessibility>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::EnableAccessibility::Arguments>(globalObject, decoder);
}
#if PLATFORM(MAC)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_GetAccessibilityWebProcessDebugInfo>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::GetAccessibilityWebProcessDebugInfo::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_GetAccessibilityWebProcessDebugInfo>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::GetAccessibilityWebProcessDebugInfo::ReplyArguments>(globalObject, decoder);
}
#endif
#if (PLATFORM(MAC) && ENABLE(ACCESSIBILITY_ISOLATED_TREE))
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_ClearAccessibilityIsolatedTree>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ClearAccessibilityIsolatedTree::Arguments>(globalObject, decoder);
}
#endif
#if PLATFORM(COCOA)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_WindowAndViewFramesChanged>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::WindowAndViewFramesChanged::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetMainFrameIsScrollable>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetMainFrameIsScrollable::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_RegisterUIProcessAccessibilityTokens>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::RegisterUIProcessAccessibilityTokens::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_GetStringSelectionForPasteboard>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::GetStringSelectionForPasteboard::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_GetStringSelectionForPasteboard>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::GetStringSelectionForPasteboard::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_GetDataSelectionForPasteboard>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::GetDataSelectionForPasteboard::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_GetDataSelectionForPasteboard>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::GetDataSelectionForPasteboard::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_ReadSelectionFromPasteboard>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ReadSelectionFromPasteboard::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_ReadSelectionFromPasteboard>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ReadSelectionFromPasteboard::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_ReplaceSelectionWithPasteboardData>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ReplaceSelectionWithPasteboardData::Arguments>(globalObject, decoder);
}
#endif
#if (PLATFORM(COCOA) && ENABLE(MULTI_REPRESENTATION_HEIC))
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_InsertMultiRepresentationHEIC>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::InsertMultiRepresentationHEIC::Arguments>(globalObject, decoder);
}
#endif
#if PLATFORM(COCOA)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_ShouldDelayWindowOrderingEvent>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ShouldDelayWindowOrderingEvent::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_ShouldDelayWindowOrderingEvent>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ShouldDelayWindowOrderingEvent::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetTextAsync>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetTextAsync::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_InsertTextAsync>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::InsertTextAsync::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_InsertDictatedTextAsync>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::InsertDictatedTextAsync::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_AddDictationAlternative>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::AddDictationAlternative::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_AddDictationAlternative>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::AddDictationAlternative::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_DictationAlternativesAtSelection>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::DictationAlternativesAtSelection::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_DictationAlternativesAtSelection>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::DictationAlternativesAtSelection::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_ClearDictationAlternatives>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ClearDictationAlternatives::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_HasMarkedText>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::HasMarkedText::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_HasMarkedText>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::HasMarkedText::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_GetMarkedRangeAsync>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::GetMarkedRangeAsync::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_GetMarkedRangeAsync>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::GetMarkedRangeAsync::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_GetSelectedRangeAsync>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::GetSelectedRangeAsync::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_GetSelectedRangeAsync>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::GetSelectedRangeAsync::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_CharacterIndexForPointAsync>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::CharacterIndexForPointAsync::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_CharacterIndexForPointAsync>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::CharacterIndexForPointAsync::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_FirstRectForCharacterRangeAsync>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::FirstRectForCharacterRangeAsync::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_FirstRectForCharacterRangeAsync>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::FirstRectForCharacterRangeAsync::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetCompositionAsync>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetCompositionAsync::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetWritingSuggestion>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetWritingSuggestion::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_ConfirmCompositionAsync>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ConfirmCompositionAsync::Arguments>(globalObject, decoder);
}
#endif
#if PLATFORM(MAC)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_AttributedSubstringForCharacterRangeAsync>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::AttributedSubstringForCharacterRangeAsync::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_AttributedSubstringForCharacterRangeAsync>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::AttributedSubstringForCharacterRangeAsync::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_RequestAcceptsFirstMouse>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::RequestAcceptsFirstMouse::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetCaretAnimatorType>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetCaretAnimatorType::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetCaretBlinkingSuspended>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetCaretBlinkingSuspended::Arguments>(globalObject, decoder);
}
#endif
#if ENABLE(IMAGE_ANALYSIS_ENHANCEMENTS)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_ReplaceImageForRemoveBackground>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ReplaceImageForRemoveBackground::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_ShouldAllowRemoveBackground>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ShouldAllowRemoveBackground::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_ShouldAllowRemoveBackground>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ShouldAllowRemoveBackground::ReplyArguments>(globalObject, decoder);
}
#endif
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetAlwaysShowsHorizontalScroller>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetAlwaysShowsHorizontalScroller::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetAlwaysShowsVerticalScroller>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetAlwaysShowsVerticalScroller::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetMinimumSizeForAutoLayout>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetMinimumSizeForAutoLayout::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetSizeToContentAutoSizeMaximumSize>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetSizeToContentAutoSizeMaximumSize::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetAutoSizingShouldExpandToViewHeight>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetAutoSizingShouldExpandToViewHeight::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetViewportSizeForCSSViewportUnits>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetViewportSizeForCSSViewportUnits::Arguments>(globalObject, decoder);
}
#if PLATFORM(COCOA)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_HandleAlternativeTextUIResult>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::HandleAlternativeTextUIResult::Arguments>(globalObject, decoder);
}
#endif
#if PLATFORM(IOS_FAMILY)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_WillStartUserTriggeredZooming>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::WillStartUserTriggeredZooming::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_DidEndUserTriggeredZooming>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::DidEndUserTriggeredZooming::Arguments>(globalObject, decoder);
}
#endif
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetScrollPinningBehavior>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetScrollPinningBehavior::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetScrollbarOverlayStyle>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetScrollbarOverlayStyle::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_GetBytecodeProfile>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::GetBytecodeProfile::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_GetBytecodeProfile>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::GetBytecodeProfile::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_GetSamplingProfilerOutput>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::GetSamplingProfilerOutput::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_GetSamplingProfilerOutput>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::GetSamplingProfilerOutput::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_TakeSnapshot>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::TakeSnapshot::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_TakeSnapshot>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::TakeSnapshot::ReplyArguments>(globalObject, decoder);
}
#if PLATFORM(MAC)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_PerformImmediateActionHitTestAtLocation>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::PerformImmediateActionHitTestAtLocation::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_ImmediateActionDidUpdate>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ImmediateActionDidUpdate::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_ImmediateActionDidCancel>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ImmediateActionDidCancel::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_ImmediateActionDidComplete>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ImmediateActionDidComplete::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_DataDetectorsDidPresentUI>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::DataDetectorsDidPresentUI::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_DataDetectorsDidChangeUI>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::DataDetectorsDidChangeUI::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_DataDetectorsDidHideUI>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::DataDetectorsDidHideUI::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_HandleAcceptedCandidate>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::HandleAcceptedCandidate::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SemanticContextDidChange>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SemanticContextDidChange::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetHeaderBannerHeight>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetHeaderBannerHeight::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetFooterBannerHeight>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetFooterBannerHeight::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_DidBeginMagnificationGesture>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::DidBeginMagnificationGesture::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_DidEndMagnificationGesture>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::DidEndMagnificationGesture::Arguments>(globalObject, decoder);
}
#endif
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_StartDeferringResizeEvents>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::StartDeferringResizeEvents::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_FlushDeferredResizeEvents>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::FlushDeferredResizeEvents::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_StartDeferringScrollEvents>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::StartDeferringScrollEvents::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_FlushDeferredScrollEvents>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::FlushDeferredScrollEvents::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_FlushDeferredDidReceiveMouseEvent>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::FlushDeferredDidReceiveMouseEvent::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_PerformHitTestForMouseEvent>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::PerformHitTestForMouseEvent::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_PerformHitTestForMouseEvent>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::PerformHitTestForMouseEvent::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetUseColorAppearance>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetUseColorAppearance::Arguments>(globalObject, decoder);
}
#if HAVE(APP_ACCENT_COLORS)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetAccentColor>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetAccentColor::Arguments>(globalObject, decoder);
}
#endif
#if PLATFORM(COCOA)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_RequestActiveNowPlayingSessionInfo>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::RequestActiveNowPlayingSessionInfo::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_RequestActiveNowPlayingSessionInfo>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::RequestActiveNowPlayingSessionInfo::ReplyArguments>(globalObject, decoder);
}
#endif
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetShouldDispatchFakeMouseMoveEvents>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetShouldDispatchFakeMouseMoveEvents::Arguments>(globalObject, decoder);
}
#if ENABLE(WIRELESS_PLAYBACK_TARGET) && !PLATFORM(IOS_FAMILY)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_PlaybackTargetSelected>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::PlaybackTargetSelected::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_PlaybackTargetAvailabilityDidChange>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::PlaybackTargetAvailabilityDidChange::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetShouldPlayToPlaybackTarget>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetShouldPlayToPlaybackTarget::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_PlaybackTargetPickerWasDismissed>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::PlaybackTargetPickerWasDismissed::Arguments>(globalObject, decoder);
}
#endif
#if ENABLE(POINTER_LOCK)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_DidLosePointerLock>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::DidLosePointerLock::Arguments>(globalObject, decoder);
}
#endif
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetShouldScaleViewToFitDocument>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetShouldScaleViewToFitDocument::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetUserInterfaceLayoutDirection>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetUserInterfaceLayoutDirection::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_DidGetLoadDecisionForIcon>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::DidGetLoadDecisionForIcon::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_DidGetLoadDecisionForIcon>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::DidGetLoadDecisionForIcon::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetUseIconLoadingClient>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetUseIconLoadingClient::Arguments>(globalObject, decoder);
}
#if ENABLE(GAMEPAD)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_GamepadActivity>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::GamepadActivity::Arguments>(globalObject, decoder);
}
#endif
#if (ENABLE(GAMEPAD) && PLATFORM(VISION))
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_AllowGamepadAccess>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::AllowGamepadAccess::Arguments>(globalObject, decoder);
}
#endif
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_RegisterURLSchemeHandler>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::RegisterURLSchemeHandler::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_URLSchemeTaskWillPerformRedirection>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::URLSchemeTaskWillPerformRedirection::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_URLSchemeTaskWillPerformRedirection>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::URLSchemeTaskWillPerformRedirection::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_URLSchemeTaskDidPerformRedirection>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::URLSchemeTaskDidPerformRedirection::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_URLSchemeTaskDidReceiveResponse>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::URLSchemeTaskDidReceiveResponse::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_URLSchemeTaskDidReceiveData>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::URLSchemeTaskDidReceiveData::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_URLSchemeTaskDidComplete>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::URLSchemeTaskDidComplete::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetIsSuspended>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetIsSuspended::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_SetIsSuspended>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetIsSuspended::ReplyArguments>(globalObject, decoder);
}
#if ENABLE(ATTACHMENT_ELEMENT)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_InsertAttachment>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::InsertAttachment::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_InsertAttachment>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::InsertAttachment::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_UpdateAttachmentAttributes>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::UpdateAttachmentAttributes::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_UpdateAttachmentAttributes>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::UpdateAttachmentAttributes::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_UpdateAttachmentIcon>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::UpdateAttachmentIcon::Arguments>(globalObject, decoder);
}
#endif
#if ENABLE(APPLICATION_MANIFEST)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_GetApplicationManifest>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::GetApplicationManifest::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_GetApplicationManifest>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::GetApplicationManifest::ReplyArguments>(globalObject, decoder);
}
#endif
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_GetTextFragmentMatch>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::GetTextFragmentMatch::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_GetTextFragmentMatch>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::GetTextFragmentMatch::ReplyArguments>(globalObject, decoder);
}
#if ENABLE(PDF_PLUGIN) && PLATFORM(MAC)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_ZoomPDFIn>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ZoomPDFIn::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_ZoomPDFOut>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ZoomPDFOut::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SavePDF>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SavePDF::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_SavePDF>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SavePDF::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_OpenPDFWithPreview>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::OpenPDFWithPreview::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_OpenPDFWithPreview>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::OpenPDFWithPreview::ReplyArguments>(globalObject, decoder);
}
#endif
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_UpdateCurrentModifierState>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::UpdateCurrentModifierState::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SimulateDeviceOrientationChange>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SimulateDeviceOrientationChange::Arguments>(globalObject, decoder);
}
#if ENABLE(SPEECH_SYNTHESIS)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SpeakingErrorOccurred>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SpeakingErrorOccurred::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_BoundaryEventOccurred>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::BoundaryEventOccurred::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_VoicesDidChange>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::VoicesDidChange::Arguments>(globalObject, decoder);
}
#endif
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetCanShowPlaceholder>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetCanShowPlaceholder::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_WasLoadedWithDataTransferFromPrevalentResource>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::WasLoadedWithDataTransferFromPrevalentResource::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_ClearLoadedSubresourceDomains>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ClearLoadedSubresourceDomains::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_GetLoadedSubresourceDomains>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::GetLoadedSubresourceDomains::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_GetLoadedSubresourceDomains>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::GetLoadedSubresourceDomains::ReplyArguments>(globalObject, decoder);
}
#if USE(SYSTEM_PREVIEW)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SystemPreviewActionTriggered>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SystemPreviewActionTriggered::Arguments>(globalObject, decoder);
}
#endif
#if PLATFORM(GTK) || PLATFORM(WPE)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SendMessageToWebProcessExtension>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SendMessageToWebProcessExtension::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SendMessageToWebProcessExtensionWithReply>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SendMessageToWebProcessExtensionWithReply::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_SendMessageToWebProcessExtensionWithReply>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SendMessageToWebProcessExtensionWithReply::ReplyArguments>(globalObject, decoder);
}
#endif
#if PLATFORM(WPE) && USE(GBM) && ENABLE(WPE_PLATFORM)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_PreferredBufferFormatsDidChange>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::PreferredBufferFormatsDidChange::Arguments>(globalObject, decoder);
}
#endif
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_StartTextManipulations>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::StartTextManipulations::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_StartTextManipulations>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::StartTextManipulations::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_CompleteTextManipulation>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::CompleteTextManipulation::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_CompleteTextManipulation>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::CompleteTextManipulation::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetOverriddenMediaType>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetOverriddenMediaType::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_GetProcessDisplayName>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::GetProcessDisplayName::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_GetProcessDisplayName>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::GetProcessDisplayName::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_UpdateCORSDisablingPatterns>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::UpdateCORSDisablingPatterns::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetIsTakingSnapshotsForApplicationSuspension>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetIsTakingSnapshotsForApplicationSuspension::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetNeedsDOMWindowResizeEvent>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetNeedsDOMWindowResizeEvent::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetHasResourceLoadClient>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetHasResourceLoadClient::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetCanUseCredentialStorage>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetCanUseCredentialStorage::Arguments>(globalObject, decoder);
}
#if ENABLE(APP_HIGHLIGHTS)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_CreateAppHighlightInSelectedRange>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::CreateAppHighlightInSelectedRange::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_CreateAppHighlightInSelectedRange>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::CreateAppHighlightInSelectedRange::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_RestoreAppHighlightsAndScrollToIndex>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::RestoreAppHighlightsAndScrollToIndex::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetAppHighlightsVisibility>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetAppHighlightsVisibility::Arguments>(globalObject, decoder);
}
#endif
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_CreateTextFragmentDirectiveFromSelection>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::CreateTextFragmentDirectiveFromSelection::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_CreateTextFragmentDirectiveFromSelection>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::CreateTextFragmentDirectiveFromSelection::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_GetTextFragmentRanges>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::GetTextFragmentRanges::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_GetTextFragmentRanges>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::GetTextFragmentRanges::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_HandleWheelEvent>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::HandleWheelEvent::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_HandleWheelEvent>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::HandleWheelEvent::ReplyArguments>(globalObject, decoder);
}
#if PLATFORM(IOS_FAMILY)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_DispatchWheelEventWithoutScrolling>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::DispatchWheelEventWithoutScrolling::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_DispatchWheelEventWithoutScrolling>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::DispatchWheelEventWithoutScrolling::ReplyArguments>(globalObject, decoder);
}
#endif
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_LastNavigationWasAppInitiated>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::LastNavigationWasAppInitiated::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_LastNavigationWasAppInitiated>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::LastNavigationWasAppInitiated::ReplyArguments>(globalObject, decoder);
}
#if ENABLE(MEDIA_SESSION_COORDINATOR)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_CreateMediaSessionCoordinator>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::CreateMediaSessionCoordinator::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_CreateMediaSessionCoordinator>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::CreateMediaSessionCoordinator::ReplyArguments>(globalObject, decoder);
}
#endif
#if ENABLE(IMAGE_ANALYSIS)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_UpdateWithTextRecognitionResult>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::UpdateWithTextRecognitionResult::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_UpdateWithTextRecognitionResult>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::UpdateWithTextRecognitionResult::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_StartVisualTranslation>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::StartVisualTranslation::Arguments>(globalObject, decoder);
}
#endif
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_ScrollToRect>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ScrollToRect::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetContentOffset>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetContentOffset::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_ScrollToEdge>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ScrollToEdge::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_NavigateServiceWorkerClient>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::NavigateServiceWorkerClient::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_NavigateServiceWorkerClient>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::NavigateServiceWorkerClient::ReplyArguments>(globalObject, decoder);
}
#if ENABLE(ARKIT_INLINE_PREVIEW_IOS)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_ModelInlinePreviewDidLoad>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ModelInlinePreviewDidLoad::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_ModelInlinePreviewDidFailToLoad>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ModelInlinePreviewDidFailToLoad::Arguments>(globalObject, decoder);
}
#endif
#if HAVE(UIKIT_RESIZABLE_WINDOWS)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetIsWindowResizingEnabled>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetIsWindowResizingEnabled::Arguments>(globalObject, decoder);
}
#endif
#if ENABLE(INTERACTION_REGIONS_IN_EVENT_REGION)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetInteractionRegionsEnabled>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetInteractionRegionsEnabled::Arguments>(globalObject, decoder);
}
#endif
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetNeedsScrollGeometryUpdates>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetNeedsScrollGeometryUpdates::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_GenerateTestReport>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::GenerateTestReport::Arguments>(globalObject, decoder);
}
#if ENABLE(ADVANCED_PRIVACY_PROTECTIONS)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetLinkDecorationFilteringData>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetLinkDecorationFilteringData::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetAllowedQueryParametersForAdvancedPrivacyProtections>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetAllowedQueryParametersForAdvancedPrivacyProtections::Arguments>(globalObject, decoder);
}
#endif
#if ENABLE(ACCESSIBILITY_ANIMATION_CONTROL)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_PauseAllAnimations>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::PauseAllAnimations::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_PauseAllAnimations>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::PauseAllAnimations::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_PlayAllAnimations>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::PlayAllAnimations::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_PlayAllAnimations>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::PlayAllAnimations::ReplyArguments>(globalObject, decoder);
}
#endif
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_UseRedirectionForCurrentNavigation>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::UseRedirectionForCurrentNavigation::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_UpdateFrameScrollingMode>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::UpdateFrameScrollingMode::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_DispatchLoadEventToFrameOwnerElement>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::DispatchLoadEventToFrameOwnerElement::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_FrameWasFocusedInAnotherProcess>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::FrameWasFocusedInAnotherProcess::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_RemotePostMessage>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::RemotePostMessage::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_RenderTreeAsTextForTesting>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::RenderTreeAsTextForTesting::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_RenderTreeAsTextForTesting>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::RenderTreeAsTextForTesting::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_LayerTreeAsTextForTesting>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::LayerTreeAsTextForTesting::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_LayerTreeAsTextForTesting>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::LayerTreeAsTextForTesting::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_FrameTextForTesting>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::FrameTextForTesting::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_FrameTextForTesting>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::FrameTextForTesting::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_RequestAllTextAndRects>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::RequestAllTextAndRects::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_RequestAllTextAndRects>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::RequestAllTextAndRects::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_RequestTargetedElement>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::RequestTargetedElement::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_RequestTargetedElement>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::RequestTargetedElement::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_RequestAllTargetableElements>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::RequestAllTargetableElements::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_RequestAllTargetableElements>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::RequestAllTargetableElements::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_RequestTextExtraction>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::RequestTextExtraction::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_RequestTextExtraction>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::RequestTextExtraction::ReplyArguments>(globalObject, decoder);
}
#if PLATFORM(IOS_FAMILY)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_ShouldDismissKeyboardAfterTapAtPoint>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ShouldDismissKeyboardAfterTapAtPoint::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_ShouldDismissKeyboardAfterTapAtPoint>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ShouldDismissKeyboardAfterTapAtPoint::ReplyArguments>(globalObject, decoder);
}
#endif
#if ENABLE(EXTENSION_CAPABILITIES)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetMediaEnvironment>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetMediaEnvironment::Arguments>(globalObject, decoder);
}
#endif
#if ENABLE(WRITING_TOOLS)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_WillBeginWritingToolsSession>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::WillBeginWritingToolsSession::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_WillBeginWritingToolsSession>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::WillBeginWritingToolsSession::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_DidBeginWritingToolsSession>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::DidBeginWritingToolsSession::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_ProofreadingSessionDidReceiveSuggestions>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ProofreadingSessionDidReceiveSuggestions::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_ProofreadingSessionDidReceiveSuggestions>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ProofreadingSessionDidReceiveSuggestions::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_ProofreadingSessionDidUpdateStateForSuggestion>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ProofreadingSessionDidUpdateStateForSuggestion::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_WillEndWritingToolsSession>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::WillEndWritingToolsSession::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_WillEndWritingToolsSession>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::WillEndWritingToolsSession::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_DidEndWritingToolsSession>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::DidEndWritingToolsSession::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_CompositionSessionDidReceiveTextWithReplacementRange>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::CompositionSessionDidReceiveTextWithReplacementRange::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_CompositionSessionDidReceiveTextWithReplacementRange>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::CompositionSessionDidReceiveTextWithReplacementRange::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_WritingToolsSessionDidReceiveAction>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::WritingToolsSessionDidReceiveAction::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_ProofreadingSessionSuggestionTextRectsInRootViewCoordinates>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ProofreadingSessionSuggestionTextRectsInRootViewCoordinates::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_ProofreadingSessionSuggestionTextRectsInRootViewCoordinates>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ProofreadingSessionSuggestionTextRectsInRootViewCoordinates::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_UpdateTextVisibilityForActiveWritingToolsSession>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::UpdateTextVisibilityForActiveWritingToolsSession::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_UpdateTextVisibilityForActiveWritingToolsSession>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::UpdateTextVisibilityForActiveWritingToolsSession::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_TextPreviewDataForActiveWritingToolsSession>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::TextPreviewDataForActiveWritingToolsSession::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_TextPreviewDataForActiveWritingToolsSession>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::TextPreviewDataForActiveWritingToolsSession::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetSelectionForActiveWritingToolsSession>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetSelectionForActiveWritingToolsSession::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_SetSelectionForActiveWritingToolsSession>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetSelectionForActiveWritingToolsSession::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_DecorateTextReplacementsForActiveWritingToolsSession>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::DecorateTextReplacementsForActiveWritingToolsSession::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_DecorateTextReplacementsForActiveWritingToolsSession>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::DecorateTextReplacementsForActiveWritingToolsSession::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_CreateTextIndicatorForTextAnimationID>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::CreateTextIndicatorForTextAnimationID::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_CreateTextIndicatorForTextAnimationID>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::CreateTextIndicatorForTextAnimationID::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_UpdateUnderlyingTextVisibilityForTextAnimationID>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::UpdateUnderlyingTextVisibilityForTextAnimationID::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_UpdateUnderlyingTextVisibilityForTextAnimationID>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::UpdateUnderlyingTextVisibilityForTextAnimationID::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_IntelligenceTextAnimationsDidComplete>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::IntelligenceTextAnimationsDidComplete::Arguments>(globalObject, decoder);
}
#endif
#if PLATFORM(COCOA)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_CreateTextIndicatorForElementWithID>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::CreateTextIndicatorForElementWithID::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_CreateTextIndicatorForElementWithID>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::CreateTextIndicatorForElementWithID::ReplyArguments>(globalObject, decoder);
}
#endif
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_TakeSnapshotForTargetedElement>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::TakeSnapshotForTargetedElement::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_TakeSnapshotForTargetedElement>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::TakeSnapshotForTargetedElement::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_ResetVisibilityAdjustmentsForTargetedElements>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ResetVisibilityAdjustmentsForTargetedElements::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_ResetVisibilityAdjustmentsForTargetedElements>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ResetVisibilityAdjustmentsForTargetedElements::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_AdjustVisibilityForTargetedElements>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::AdjustVisibilityForTargetedElements::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_AdjustVisibilityForTargetedElements>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::AdjustVisibilityForTargetedElements::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_NumberOfVisibilityAdjustmentRects>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::NumberOfVisibilityAdjustmentRects::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_NumberOfVisibilityAdjustmentRects>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::NumberOfVisibilityAdjustmentRects::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_ContentsToRootViewRect>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ContentsToRootViewRect::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_ContentsToRootViewRect>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ContentsToRootViewRect::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_ContentsToRootViewPoint>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ContentsToRootViewPoint::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_ContentsToRootViewPoint>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::ContentsToRootViewPoint::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_RemoteDictionaryPopupInfoToRootView>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::RemoteDictionaryPopupInfoToRootView::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_RemoteDictionaryPopupInfoToRootView>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::RemoteDictionaryPopupInfoToRootView::ReplyArguments>(globalObject, decoder);
}
#if HAVE(SPATIAL_TRACKING_LABEL)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetDefaultSpatialTrackingLabel>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetDefaultSpatialTrackingLabel::Arguments>(globalObject, decoder);
}
#endif
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_StartObservingNowPlayingMetadata>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::StartObservingNowPlayingMetadata::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_StopObservingNowPlayingMetadata>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::StopObservingNowPlayingMetadata::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_LoadAndDecodeImage>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::LoadAndDecodeImage::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_LoadAndDecodeImage>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::LoadAndDecodeImage::ReplyArguments>(globalObject, decoder);
}
#if PLATFORM(COCOA)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_GetInformationFromImageData>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::GetInformationFromImageData::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_GetInformationFromImageData>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::GetInformationFromImageData::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_CreateBitmapsFromImageData>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::CreateBitmapsFromImageData::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_CreateBitmapsFromImageData>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::CreateBitmapsFromImageData::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_DecodeImageData>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::DecodeImageData::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_DecodeImageData>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::DecodeImageData::ReplyArguments>(globalObject, decoder);
}
#endif
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_FrameNameWasChangedInAnotherProcess>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::FrameNameWasChangedInAnotherProcess::Arguments>(globalObject, decoder);
}
#if ENABLE(VIDEO_PRESENTATION_MODE)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_StartPlayingPredominantVideo>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::StartPlayingPredominantVideo::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_StartPlayingPredominantVideo>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::StartPlayingPredominantVideo::ReplyArguments>(globalObject, decoder);
}
#endif
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_CloseCurrentTypingCommand>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::CloseCurrentTypingCommand::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SimulateClickOverFirstMatchingTextInViewportWithUserInteraction>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SimulateClickOverFirstMatchingTextInViewportWithUserInteraction::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessageReply<MessageName::WebPage_SimulateClickOverFirstMatchingTextInViewportWithUserInteraction>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SimulateClickOverFirstMatchingTextInViewportWithUserInteraction::ReplyArguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_UpdateOpener>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::UpdateOpener::Arguments>(globalObject, decoder);
}
#if HAVE(AUDIT_TOKEN)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_SetPresentingApplicationAuditTokenAndBundleIdentifier>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::SetPresentingApplicationAuditTokenAndBundleIdentifier::Arguments>(globalObject, decoder);
}
#endif
#if USE(UICONTEXTMENU)
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_WillBeginContextMenuInteraction>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::WillBeginContextMenuInteraction::Arguments>(globalObject, decoder);
}
template<> std::optional<JSC::JSValue> jsValueForDecodedMessage<MessageName::WebPage_DidEndContextMenuInteraction>(JSC::JSGlobalObject* globalObject, Decoder& decoder)
{
    return jsValueForDecodedArguments<Messages::WebPage::DidEndContextMenuInteraction::Arguments>(globalObject, decoder);
}
#endif

}

#endif

