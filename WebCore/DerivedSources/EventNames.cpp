/*
 * Copyright (C) 2005-2024 Apple Inc. All rights reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 *
 */

#include "config.h"
#include "EventNames.h"

namespace WebCore {

EventNames::EventNames()
    : DOMActivateEvent("DOMActivate"_s)
    , DOMCharacterDataModifiedEvent("DOMCharacterDataModified"_s)
    , DOMContentLoadedEvent("DOMContentLoaded"_s)
    , DOMNodeInsertedEvent("DOMNodeInserted"_s)
    , DOMNodeInsertedIntoDocumentEvent("DOMNodeInsertedIntoDocument"_s)
    , DOMNodeRemovedEvent("DOMNodeRemoved"_s)
    , DOMNodeRemovedFromDocumentEvent("DOMNodeRemovedFromDocument"_s)
    , DOMSubtreeModifiedEvent("DOMSubtreeModified"_s)
    , abortEvent("abort"_s)
    , activateEvent("activate"_s)
    , activeEvent("active"_s)
    , addsourcebufferEvent("addsourcebuffer"_s)
    , addstreamEvent("addstream"_s)
    , addtrackEvent("addtrack"_s)
    , afterprintEvent("afterprint"_s)
    , animationcancelEvent("animationcancel"_s)
    , animationendEvent("animationend"_s)
    , animationiterationEvent("animationiteration"_s)
    , animationstartEvent("animationstart"_s)
    , audioendEvent("audioend"_s)
    , audioprocessEvent("audioprocess"_s)
    , audiostartEvent("audiostart"_s)
    , autocompleteEvent("autocomplete"_s)
    , autocompleteerrorEvent("autocompleteerror"_s)
    , auxclickEvent("auxclick"_s)
    , backgroundfetchabortEvent("backgroundfetchabort"_s)
    , backgroundfetchclickEvent("backgroundfetchclick"_s)
    , backgroundfetchfailEvent("backgroundfetchfail"_s)
    , backgroundfetchsuccessEvent("backgroundfetchsuccess"_s)
    , beforecopyEvent("beforecopy"_s)
    , beforecutEvent("beforecut"_s)
    , beforeinputEvent("beforeinput"_s)
    , beforeloadEvent("beforeload"_s)
    , beforematchEvent("beforematch"_s)
    , beforepasteEvent("beforepaste"_s)
    , beforeprintEvent("beforeprint"_s)
    , beforetoggleEvent("beforetoggle"_s)
    , beforeunloadEvent("beforeunload"_s)
    , beginEventEvent("beginEvent"_s)
    , blockedEvent("blocked"_s)
    , blurEvent("blur"_s)
    , boundaryEvent("boundary"_s)
    , bufferedamountlowEvent("bufferedamountlow"_s)
    , bufferedchangeEvent("bufferedchange"_s)
    , cachedEvent("cached"_s)
    , cancelEvent("cancel"_s)
    , canplayEvent("canplay"_s)
    , canplaythroughEvent("canplaythrough"_s)
    , changeEvent("change"_s)
    , chargingchangeEvent("chargingchange"_s)
    , chargingtimechangeEvent("chargingtimechange"_s)
    , checkingEvent("checking"_s)
    , clickEvent("click"_s)
    , closeEvent("close"_s)
    , closingEvent("closing"_s)
    , commandEvent("command"_s)
    , completeEvent("complete"_s)
    , compositionendEvent("compositionend"_s)
    , compositionstartEvent("compositionstart"_s)
    , compositionupdateEvent("compositionupdate"_s)
    , configurationchangeEvent("configurationchange"_s)
    , connectEvent("connect"_s)
    , connectingEvent("connecting"_s)
    , connectionstatechangeEvent("connectionstatechange"_s)
    , contentvisibilityautostatechangeEvent("contentvisibilityautostatechange"_s)
    , contextmenuEvent("contextmenu"_s)
    , controllerchangeEvent("controllerchange"_s)
    , cookiechangeEvent("cookiechange"_s)
    , coordinatorstatechangeEvent("coordinatorstatechange"_s)
    , copyEvent("copy"_s)
#if ENABLE(APPLE_PAY_COUPON_CODE)
    , couponcodechangedEvent("couponcodechanged"_s)
#endif
    , cuechangeEvent("cuechange"_s)
    , currententrychangeEvent("currententrychange"_s)
    , cutEvent("cut"_s)
    , dataavailableEvent("dataavailable"_s)
    , datachannelEvent("datachannel"_s)
    , dblclickEvent("dblclick"_s)
    , dequeueEvent("dequeue"_s)
    , devicechangeEvent("devicechange"_s)
    , devicemotionEvent("devicemotion"_s)
    , deviceorientationEvent("deviceorientation"_s)
    , dischargingtimechangeEvent("dischargingtimechange"_s)
    , disconnectEvent("disconnect"_s)
    , disposeEvent("dispose"_s)
    , downloadingEvent("downloading"_s)
    , dragEvent("drag"_s)
    , dragendEvent("dragend"_s)
    , dragenterEvent("dragenter"_s)
    , dragleaveEvent("dragleave"_s)
    , dragoverEvent("dragover"_s)
    , dragstartEvent("dragstart"_s)
    , dropEvent("drop"_s)
    , durationchangeEvent("durationchange"_s)
    , emptiedEvent("emptied"_s)
    , encryptedEvent("encrypted"_s)
    , endEvent("end"_s)
    , endEventEvent("endEvent"_s)
    , endedEvent("ended"_s)
    , endstreamingEvent("endstreaming"_s)
    , enterEvent("enter"_s)
    , enterpictureinpictureEvent("enterpictureinpicture"_s)
    , errorEvent("error"_s)
    , exitEvent("exit"_s)
    , fetchEvent("fetch"_s)
    , finishEvent("finish"_s)
    , focusEvent("focus"_s)
    , focusinEvent("focusin"_s)
    , focusoutEvent("focusout"_s)
    , formdataEvent("formdata"_s)
    , fullscreenchangeEvent("fullscreenchange"_s)
    , fullscreenerrorEvent("fullscreenerror"_s)
    , gamepadconnectedEvent("gamepadconnected"_s)
    , gamepaddisconnectedEvent("gamepaddisconnected"_s)
    , gatheringstatechangeEvent("gatheringstatechange"_s)
    , gesturechangeEvent("gesturechange"_s)
    , gestureendEvent("gestureend"_s)
    , gesturescrollendEvent("gesturescrollend"_s)
    , gesturescrollstartEvent("gesturescrollstart"_s)
    , gesturescrollupdateEvent("gesturescrollupdate"_s)
    , gesturestartEvent("gesturestart"_s)
    , gesturetapEvent("gesturetap"_s)
    , gesturetapdownEvent("gesturetapdown"_s)
    , gotpointercaptureEvent("gotpointercapture"_s)
    , hashchangeEvent("hashchange"_s)
    , icecandidateEvent("icecandidate"_s)
    , icecandidateerrorEvent("icecandidateerror"_s)
    , iceconnectionstatechangeEvent("iceconnectionstatechange"_s)
    , icegatheringstatechangeEvent("icegatheringstatechange"_s)
    , inactiveEvent("inactive"_s)
    , inputEvent("input"_s)
    , inputsourceschangeEvent("inputsourceschange"_s)
    , installEvent("install"_s)
    , invalidEvent("invalid"_s)
    , keydownEvent("keydown"_s)
    , keypressEvent("keypress"_s)
    , keystatuseschangeEvent("keystatuseschange"_s)
    , keyupEvent("keyup"_s)
    , languagechangeEvent("languagechange"_s)
    , leavepictureinpictureEvent("leavepictureinpicture"_s)
    , levelchangeEvent("levelchange"_s)
    , loadEvent("load"_s)
    , loadeddataEvent("loadeddata"_s)
    , loadedmetadataEvent("loadedmetadata"_s)
    , loadendEvent("loadend"_s)
    , loadingEvent("loading"_s)
    , loadingdoneEvent("loadingdone"_s)
    , loadingerrorEvent("loadingerror"_s)
    , loadstartEvent("loadstart"_s)
    , lostpointercaptureEvent("lostpointercapture"_s)
    , markEvent("mark"_s)
    , merchantvalidationEvent("merchantvalidation"_s)
    , messageEvent("message"_s)
    , messageerrorEvent("messageerror"_s)
    , mousedownEvent("mousedown"_s)
    , mouseenterEvent("mouseenter"_s)
    , mouseleaveEvent("mouseleave"_s)
    , mousemoveEvent("mousemove"_s)
    , mouseoutEvent("mouseout"_s)
    , mouseoverEvent("mouseover"_s)
    , mouseupEvent("mouseup"_s)
    , mousewheelEvent("mousewheel"_s)
    , muteEvent("mute"_s)
    , navigateEvent("navigate"_s)
    , navigateerrorEvent("navigateerror"_s)
    , navigatesuccessEvent("navigatesuccess"_s)
    , negotiationneededEvent("negotiationneeded"_s)
    , nexttrackEvent("nexttrack"_s)
    , nomatchEvent("nomatch"_s)
    , notificationclickEvent("notificationclick"_s)
    , notificationcloseEvent("notificationclose"_s)
    , noupdateEvent("noupdate"_s)
    , obsoleteEvent("obsolete"_s)
    , offlineEvent("offline"_s)
    , onlineEvent("online"_s)
    , openEvent("open"_s)
    , orientationchangeEvent("orientationchange"_s)
    , overflowchangedEvent("overflowchanged"_s)
    , pagehideEvent("pagehide"_s)
    , pagerevealEvent("pagereveal"_s)
    , pageshowEvent("pageshow"_s)
    , pageswapEvent("pageswap"_s)
    , pasteEvent("paste"_s)
    , pauseEvent("pause"_s)
    , payerdetailchangeEvent("payerdetailchange"_s)
    , paymentauthorizedEvent("paymentauthorized"_s)
    , paymentmethodchangeEvent("paymentmethodchange"_s)
    , paymentmethodselectedEvent("paymentmethodselected"_s)
    , playEvent("play"_s)
    , playingEvent("playing"_s)
    , pointercancelEvent("pointercancel"_s)
    , pointerdownEvent("pointerdown"_s)
    , pointerenterEvent("pointerenter"_s)
    , pointerleaveEvent("pointerleave"_s)
    , pointerlockchangeEvent("pointerlockchange"_s)
    , pointerlockerrorEvent("pointerlockerror"_s)
    , pointermoveEvent("pointermove"_s)
    , pointeroutEvent("pointerout"_s)
    , pointeroverEvent("pointerover"_s)
    , pointerupEvent("pointerup"_s)
    , popstateEvent("popstate"_s)
    , previoustrackEvent("previoustrack"_s)
    , processorerrorEvent("processorerror"_s)
    , progressEvent("progress"_s)
    , pushEvent("push"_s)
    , pushnotificationEvent("pushnotification"_s)
    , pushsubscriptionchangeEvent("pushsubscriptionchange"_s)
    , qualitychangeEvent("qualitychange"_s)
    , ratechangeEvent("ratechange"_s)
    , readystatechangeEvent("readystatechange"_s)
    , redrawEvent("redraw"_s)
    , rejectionhandledEvent("rejectionhandled"_s)
    , releaseEvent("release"_s)
    , removeEvent("remove"_s)
    , removesourcebufferEvent("removesourcebuffer"_s)
    , removestreamEvent("removestream"_s)
    , removetrackEvent("removetrack"_s)
    , resetEvent("reset"_s)
    , resizeEvent("resize"_s)
    , resourcetimingbufferfullEvent("resourcetimingbufferfull"_s)
    , resultEvent("result"_s)
    , resumeEvent("resume"_s)
    , rtctransformEvent("rtctransform"_s)
    , scrollEvent("scroll"_s)
    , scrollendEvent("scrollend"_s)
    , securitypolicyviolationEvent("securitypolicyviolation"_s)
    , seekedEvent("seeked"_s)
    , seekingEvent("seeking"_s)
    , selectEvent("select"_s)
    , selectedcandidatepairchangeEvent("selectedcandidatepairchange"_s)
    , selectendEvent("selectend"_s)
    , selectionchangeEvent("selectionchange"_s)
    , selectstartEvent("selectstart"_s)
    , shippingaddresschangeEvent("shippingaddresschange"_s)
    , shippingcontactselectedEvent("shippingcontactselected"_s)
    , shippingmethodselectedEvent("shippingmethodselected"_s)
    , shippingoptionchangeEvent("shippingoptionchange"_s)
    , showEvent("show"_s)
    , signalingstatechangeEvent("signalingstatechange"_s)
    , slotchangeEvent("slotchange"_s)
    , soundendEvent("soundend"_s)
    , soundstartEvent("soundstart"_s)
    , sourcecloseEvent("sourceclose"_s)
    , sourceendedEvent("sourceended"_s)
    , sourceopenEvent("sourceopen"_s)
    , speechendEvent("speechend"_s)
    , speechstartEvent("speechstart"_s)
    , squeezeEvent("squeeze"_s)
    , squeezeendEvent("squeezeend"_s)
    , squeezestartEvent("squeezestart"_s)
    , stalledEvent("stalled"_s)
    , startEvent("start"_s)
    , startedEvent("started"_s)
    , startstreamingEvent("startstreaming"_s)
    , statechangeEvent("statechange"_s)
    , stopEvent("stop"_s)
    , storageEvent("storage"_s)
    , submitEvent("submit"_s)
    , successEvent("success"_s)
    , suspendEvent("suspend"_s)
    , textInputEvent("textInput"_s)
    , timeoutEvent("timeout"_s)
    , timeupdateEvent("timeupdate"_s)
    , toggleEvent("toggle"_s)
    , tonechangeEvent("tonechange"_s)
    , touchcancelEvent("touchcancel"_s)
    , touchendEvent("touchend"_s)
    , touchforcechangeEvent("touchforcechange"_s)
    , touchmoveEvent("touchmove"_s)
    , touchstartEvent("touchstart"_s)
    , trackEvent("track"_s)
    , transitioncancelEvent("transitioncancel"_s)
    , transitionendEvent("transitionend"_s)
    , transitionrunEvent("transitionrun"_s)
    , transitionstartEvent("transitionstart"_s)
    , uncapturederrorEvent("uncapturederror"_s)
    , unhandledrejectionEvent("unhandledrejection"_s)
    , unloadEvent("unload"_s)
    , unmuteEvent("unmute"_s)
    , updateEvent("update"_s)
    , updateendEvent("updateend"_s)
    , updatefoundEvent("updatefound"_s)
    , updatereadyEvent("updateready"_s)
    , updatestartEvent("updatestart"_s)
    , upgradeneededEvent("upgradeneeded"_s)
    , validatemerchantEvent("validatemerchant"_s)
    , versionchangeEvent("versionchange"_s)
    , visibilitychangeEvent("visibilitychange"_s)
    , voiceschangedEvent("voiceschanged"_s)
    , volumechangeEvent("volumechange"_s)
    , waitingEvent("waiting"_s)
    , waitingforkeyEvent("waitingforkey"_s)
    , webglcontextcreationerrorEvent("webglcontextcreationerror"_s)
    , webglcontextlostEvent("webglcontextlost"_s)
    , webglcontextrestoredEvent("webglcontextrestored"_s)
    , webkitAnimationEndEvent("webkitAnimationEnd"_s)
    , webkitAnimationIterationEvent("webkitAnimationIteration"_s)
    , webkitAnimationStartEvent("webkitAnimationStart"_s)
    , webkitBeforeTextInsertedEvent("webkitBeforeTextInserted"_s)
    , webkitTransitionEndEvent("webkitTransitionEnd"_s)
    , webkitautofillrequestEvent("webkitautofillrequest"_s)
    , webkitbeginfullscreenEvent("webkitbeginfullscreen"_s)
    , webkitcurrentplaybacktargetiswirelesschangedEvent("webkitcurrentplaybacktargetiswirelesschanged"_s)
    , webkitendfullscreenEvent("webkitendfullscreen"_s)
    , webkitfullscreenchangeEvent("webkitfullscreenchange"_s)
    , webkitfullscreenerrorEvent("webkitfullscreenerror"_s)
    , webkitkeyaddedEvent("webkitkeyadded"_s)
    , webkitkeyerrorEvent("webkitkeyerror"_s)
    , webkitkeymessageEvent("webkitkeymessage"_s)
    , webkitmediasessionmetadatachangedEvent("webkitmediasessionmetadatachanged"_s)
    , webkitmouseforcechangedEvent("webkitmouseforcechanged"_s)
    , webkitmouseforcedownEvent("webkitmouseforcedown"_s)
    , webkitmouseforceupEvent("webkitmouseforceup"_s)
    , webkitmouseforcewillbeginEvent("webkitmouseforcewillbegin"_s)
    , webkitneedkeyEvent("webkitneedkey"_s)
    , webkitnetworkinfochangeEvent("webkitnetworkinfochange"_s)
    , webkitplaybacktargetavailabilitychangedEvent("webkitplaybacktargetavailabilitychanged"_s)
    , webkitpresentationmodechangedEvent("webkitpresentationmodechanged"_s)
    , webkitremovesourcebufferEvent("webkitremovesourcebuffer"_s)
    , webkitsourcecloseEvent("webkitsourceclose"_s)
    , webkitsourceendedEvent("webkitsourceended"_s)
    , webkitsourceopenEvent("webkitsourceopen"_s)
    , wheelEvent("wheel"_s)
    , writeEvent("write"_s)
    , writeendEvent("writeend"_s)
    , writestartEvent("writestart"_s)
    , zoomEvent("zoom"_s)
    , m_typeInfoMap({
        { "DOMActivate"_s, { EventType::DOMActivate, { EventCategory::MouseClickRelated }, EventTypeInfo::DefaultEventHandler::Yes } },
        { "DOMCharacterDataModified"_s, { EventType::DOMCharacterDataModified, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "DOMContentLoaded"_s, { EventType::DOMContentLoaded, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "DOMNodeInserted"_s, { EventType::DOMNodeInserted, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "DOMNodeInsertedIntoDocument"_s, { EventType::DOMNodeInsertedIntoDocument, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "DOMNodeRemoved"_s, { EventType::DOMNodeRemoved, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "DOMNodeRemovedFromDocument"_s, { EventType::DOMNodeRemovedFromDocument, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "DOMSubtreeModified"_s, { EventType::DOMSubtreeModified, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "abort"_s, { EventType::abort, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "activate"_s, { EventType::activate, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "active"_s, { EventType::active, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "addsourcebuffer"_s, { EventType::addsourcebuffer, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "addstream"_s, { EventType::addstream, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "addtrack"_s, { EventType::addtrack, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "afterprint"_s, { EventType::afterprint, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "animationcancel"_s, { EventType::animationcancel, { EventCategory::CSSAnimation }, EventTypeInfo::DefaultEventHandler::No } },
        { "animationend"_s, { EventType::animationend, { EventCategory::CSSAnimation }, EventTypeInfo::DefaultEventHandler::No } },
        { "animationiteration"_s, { EventType::animationiteration, { EventCategory::CSSAnimation }, EventTypeInfo::DefaultEventHandler::No } },
        { "animationstart"_s, { EventType::animationstart, { EventCategory::CSSAnimation }, EventTypeInfo::DefaultEventHandler::No } },
        { "audioend"_s, { EventType::audioend, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "audioprocess"_s, { EventType::audioprocess, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "audiostart"_s, { EventType::audiostart, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "autocomplete"_s, { EventType::autocomplete, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "autocompleteerror"_s, { EventType::autocompleteerror, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "auxclick"_s, { EventType::auxclick, { EventCategory::MouseClickRelated }, EventTypeInfo::DefaultEventHandler::Yes } },
        { "backgroundfetchabort"_s, { EventType::backgroundfetchabort, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "backgroundfetchclick"_s, { EventType::backgroundfetchclick, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "backgroundfetchfail"_s, { EventType::backgroundfetchfail, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "backgroundfetchsuccess"_s, { EventType::backgroundfetchsuccess, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "beforecopy"_s, { EventType::beforecopy, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "beforecut"_s, { EventType::beforecut, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "beforeinput"_s, { EventType::beforeinput, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "beforeload"_s, { EventType::beforeload, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "beforematch"_s, { EventType::beforematch, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "beforepaste"_s, { EventType::beforepaste, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "beforeprint"_s, { EventType::beforeprint, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "beforetoggle"_s, { EventType::beforetoggle, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "beforeunload"_s, { EventType::beforeunload, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "beginEvent"_s, { EventType::beginEvent, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "blocked"_s, { EventType::blocked, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "blur"_s, { EventType::blur, { }, EventTypeInfo::DefaultEventHandler::Yes } },
        { "boundary"_s, { EventType::boundary, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "bufferedamountlow"_s, { EventType::bufferedamountlow, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "bufferedchange"_s, { EventType::bufferedchange, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "cached"_s, { EventType::cached, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "cancel"_s, { EventType::cancel, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "canplay"_s, { EventType::canplay, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "canplaythrough"_s, { EventType::canplaythrough, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "change"_s, { EventType::change, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "chargingchange"_s, { EventType::chargingchange, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "chargingtimechange"_s, { EventType::chargingtimechange, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "checking"_s, { EventType::checking, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "click"_s, { EventType::click, { EventCategory::MouseClickRelated }, EventTypeInfo::DefaultEventHandler::Yes } },
        { "close"_s, { EventType::close, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "closing"_s, { EventType::closing, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "command"_s, { EventType::command, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "complete"_s, { EventType::complete, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "compositionend"_s, { EventType::compositionend, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "compositionstart"_s, { EventType::compositionstart, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "compositionupdate"_s, { EventType::compositionupdate, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "configurationchange"_s, { EventType::configurationchange, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "connect"_s, { EventType::connect, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "connecting"_s, { EventType::connecting, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "connectionstatechange"_s, { EventType::connectionstatechange, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "contentvisibilityautostatechange"_s, { EventType::contentvisibilityautostatechange, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "contextmenu"_s, { EventType::contextmenu, { }, EventTypeInfo::DefaultEventHandler::Yes } },
        { "controllerchange"_s, { EventType::controllerchange, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "cookiechange"_s, { EventType::cookiechange, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "coordinatorstatechange"_s, { EventType::coordinatorstatechange, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "copy"_s, { EventType::copy, { }, EventTypeInfo::DefaultEventHandler::No } },
#if ENABLE(APPLE_PAY_COUPON_CODE)
        { "couponcodechanged"_s, { EventType::couponcodechanged, { }, EventTypeInfo::DefaultEventHandler::No } },
#endif
        { "cuechange"_s, { EventType::cuechange, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "currententrychange"_s, { EventType::currententrychange, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "cut"_s, { EventType::cut, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "dataavailable"_s, { EventType::dataavailable, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "datachannel"_s, { EventType::datachannel, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "dblclick"_s, { EventType::dblclick, { }, EventTypeInfo::DefaultEventHandler::Yes } },
        { "dequeue"_s, { EventType::dequeue, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "devicechange"_s, { EventType::devicechange, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "devicemotion"_s, { EventType::devicemotion, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "deviceorientation"_s, { EventType::deviceorientation, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "dischargingtimechange"_s, { EventType::dischargingtimechange, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "disconnect"_s, { EventType::disconnect, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "dispose"_s, { EventType::dispose, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "downloading"_s, { EventType::downloading, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "drag"_s, { EventType::drag, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "dragend"_s, { EventType::dragend, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "dragenter"_s, { EventType::dragenter, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "dragleave"_s, { EventType::dragleave, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "dragover"_s, { EventType::dragover, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "dragstart"_s, { EventType::dragstart, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "drop"_s, { EventType::drop, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "durationchange"_s, { EventType::durationchange, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "emptied"_s, { EventType::emptied, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "encrypted"_s, { EventType::encrypted, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "end"_s, { EventType::end, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "endEvent"_s, { EventType::endEvent, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "ended"_s, { EventType::ended, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "endstreaming"_s, { EventType::endstreaming, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "enter"_s, { EventType::enter, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "enterpictureinpicture"_s, { EventType::enterpictureinpicture, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "error"_s, { EventType::error, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "exit"_s, { EventType::exit, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "fetch"_s, { EventType::fetch, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "finish"_s, { EventType::finish, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "focus"_s, { EventType::focus, { }, EventTypeInfo::DefaultEventHandler::Yes } },
        { "focusin"_s, { EventType::focusin, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "focusout"_s, { EventType::focusout, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "formdata"_s, { EventType::formdata, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "fullscreenchange"_s, { EventType::fullscreenchange, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "fullscreenerror"_s, { EventType::fullscreenerror, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "gamepadconnected"_s, { EventType::gamepadconnected, { EventCategory::Gamepad }, EventTypeInfo::DefaultEventHandler::No } },
        { "gamepaddisconnected"_s, { EventType::gamepaddisconnected, { EventCategory::Gamepad }, EventTypeInfo::DefaultEventHandler::No } },
        { "gatheringstatechange"_s, { EventType::gatheringstatechange, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "gesturechange"_s, { EventType::gesturechange, { EventCategory::Gesture }, EventTypeInfo::DefaultEventHandler::No } },
        { "gestureend"_s, { EventType::gestureend, { EventCategory::Gesture }, EventTypeInfo::DefaultEventHandler::No } },
        { "gesturescrollend"_s, { EventType::gesturescrollend, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "gesturescrollstart"_s, { EventType::gesturescrollstart, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "gesturescrollupdate"_s, { EventType::gesturescrollupdate, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "gesturestart"_s, { EventType::gesturestart, { EventCategory::Gesture }, EventTypeInfo::DefaultEventHandler::No } },
        { "gesturetap"_s, { EventType::gesturetap, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "gesturetapdown"_s, { EventType::gesturetapdown, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "gotpointercapture"_s, { EventType::gotpointercapture, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "hashchange"_s, { EventType::hashchange, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "icecandidate"_s, { EventType::icecandidate, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "icecandidateerror"_s, { EventType::icecandidateerror, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "iceconnectionstatechange"_s, { EventType::iceconnectionstatechange, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "icegatheringstatechange"_s, { EventType::icegatheringstatechange, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "inactive"_s, { EventType::inactive, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "input"_s, { EventType::input, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "inputsourceschange"_s, { EventType::inputsourceschange, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "install"_s, { EventType::install, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "invalid"_s, { EventType::invalid, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "keydown"_s, { EventType::keydown, { }, EventTypeInfo::DefaultEventHandler::Yes } },
        { "keypress"_s, { EventType::keypress, { }, EventTypeInfo::DefaultEventHandler::Yes } },
        { "keystatuseschange"_s, { EventType::keystatuseschange, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "keyup"_s, { EventType::keyup, { }, EventTypeInfo::DefaultEventHandler::Yes } },
        { "languagechange"_s, { EventType::languagechange, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "leavepictureinpicture"_s, { EventType::leavepictureinpicture, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "levelchange"_s, { EventType::levelchange, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "load"_s, { EventType::load, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "loadeddata"_s, { EventType::loadeddata, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "loadedmetadata"_s, { EventType::loadedmetadata, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "loadend"_s, { EventType::loadend, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "loading"_s, { EventType::loading, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "loadingdone"_s, { EventType::loadingdone, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "loadingerror"_s, { EventType::loadingerror, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "loadstart"_s, { EventType::loadstart, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "lostpointercapture"_s, { EventType::lostpointercapture, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "mark"_s, { EventType::mark, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "merchantvalidation"_s, { EventType::merchantvalidation, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "message"_s, { EventType::message, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "messageerror"_s, { EventType::messageerror, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "mousedown"_s, { EventType::mousedown, { EventCategory::MouseClickRelated, EventCategory::SimulatedMouse, EventCategory::ExtendedTouchRelated }, EventTypeInfo::DefaultEventHandler::Yes } },
        { "mouseenter"_s, { EventType::mouseenter, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "mouseleave"_s, { EventType::mouseleave, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "mousemove"_s, { EventType::mousemove, { EventCategory::MouseMoveRelated, EventCategory::SimulatedMouse, EventCategory::ExtendedTouchRelated }, EventTypeInfo::DefaultEventHandler::Yes } },
        { "mouseout"_s, { EventType::mouseout, { EventCategory::MouseMoveRelated }, EventTypeInfo::DefaultEventHandler::No } },
        { "mouseover"_s, { EventType::mouseover, { EventCategory::MouseMoveRelated }, EventTypeInfo::DefaultEventHandler::No } },
        { "mouseup"_s, { EventType::mouseup, { EventCategory::MouseClickRelated, EventCategory::SimulatedMouse, EventCategory::ExtendedTouchRelated }, EventTypeInfo::DefaultEventHandler::Yes } },
        { "mousewheel"_s, { EventType::mousewheel, { EventCategory::Wheel }, EventTypeInfo::DefaultEventHandler::Yes } },
        { "mute"_s, { EventType::mute, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "navigate"_s, { EventType::navigate, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "navigateerror"_s, { EventType::navigateerror, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "navigatesuccess"_s, { EventType::navigatesuccess, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "negotiationneeded"_s, { EventType::negotiationneeded, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "nexttrack"_s, { EventType::nexttrack, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "nomatch"_s, { EventType::nomatch, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "notificationclick"_s, { EventType::notificationclick, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "notificationclose"_s, { EventType::notificationclose, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "noupdate"_s, { EventType::noupdate, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "obsolete"_s, { EventType::obsolete, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "offline"_s, { EventType::offline, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "online"_s, { EventType::online, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "open"_s, { EventType::open, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "orientationchange"_s, { EventType::orientationchange, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "overflowchanged"_s, { EventType::overflowchanged, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "pagehide"_s, { EventType::pagehide, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "pagereveal"_s, { EventType::pagereveal, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "pageshow"_s, { EventType::pageshow, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "pageswap"_s, { EventType::pageswap, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "paste"_s, { EventType::paste, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "pause"_s, { EventType::pause, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "payerdetailchange"_s, { EventType::payerdetailchange, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "paymentauthorized"_s, { EventType::paymentauthorized, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "paymentmethodchange"_s, { EventType::paymentmethodchange, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "paymentmethodselected"_s, { EventType::paymentmethodselected, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "play"_s, { EventType::play, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "playing"_s, { EventType::playing, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "pointercancel"_s, { EventType::pointercancel, { EventCategory::TouchRelated, EventCategory::ExtendedTouchRelated }, EventTypeInfo::DefaultEventHandler::Yes } },
        { "pointerdown"_s, { EventType::pointerdown, { EventCategory::TouchRelated, EventCategory::ExtendedTouchRelated }, EventTypeInfo::DefaultEventHandler::Yes } },
        { "pointerenter"_s, { EventType::pointerenter, { EventCategory::TouchRelated, EventCategory::ExtendedTouchRelated }, EventTypeInfo::DefaultEventHandler::Yes } },
        { "pointerleave"_s, { EventType::pointerleave, { EventCategory::TouchRelated, EventCategory::ExtendedTouchRelated }, EventTypeInfo::DefaultEventHandler::Yes } },
        { "pointerlockchange"_s, { EventType::pointerlockchange, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "pointerlockerror"_s, { EventType::pointerlockerror, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "pointermove"_s, { EventType::pointermove, { EventCategory::TouchRelated, EventCategory::ExtendedTouchRelated }, EventTypeInfo::DefaultEventHandler::Yes } },
        { "pointerout"_s, { EventType::pointerout, { EventCategory::TouchRelated, EventCategory::ExtendedTouchRelated }, EventTypeInfo::DefaultEventHandler::Yes } },
        { "pointerover"_s, { EventType::pointerover, { EventCategory::TouchRelated, EventCategory::ExtendedTouchRelated }, EventTypeInfo::DefaultEventHandler::Yes } },
        { "pointerup"_s, { EventType::pointerup, { EventCategory::TouchRelated, EventCategory::ExtendedTouchRelated }, EventTypeInfo::DefaultEventHandler::Yes } },
        { "popstate"_s, { EventType::popstate, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "previoustrack"_s, { EventType::previoustrack, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "processorerror"_s, { EventType::processorerror, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "progress"_s, { EventType::progress, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "push"_s, { EventType::push, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "pushnotification"_s, { EventType::pushnotification, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "pushsubscriptionchange"_s, { EventType::pushsubscriptionchange, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "qualitychange"_s, { EventType::qualitychange, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "ratechange"_s, { EventType::ratechange, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "readystatechange"_s, { EventType::readystatechange, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "redraw"_s, { EventType::redraw, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "rejectionhandled"_s, { EventType::rejectionhandled, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "release"_s, { EventType::release, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "remove"_s, { EventType::remove, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "removesourcebuffer"_s, { EventType::removesourcebuffer, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "removestream"_s, { EventType::removestream, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "removetrack"_s, { EventType::removetrack, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "reset"_s, { EventType::reset, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "resize"_s, { EventType::resize, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "resourcetimingbufferfull"_s, { EventType::resourcetimingbufferfull, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "result"_s, { EventType::result, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "resume"_s, { EventType::resume, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "rtctransform"_s, { EventType::rtctransform, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "scroll"_s, { EventType::scroll, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "scrollend"_s, { EventType::scrollend, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "securitypolicyviolation"_s, { EventType::securitypolicyviolation, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "seeked"_s, { EventType::seeked, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "seeking"_s, { EventType::seeking, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "select"_s, { EventType::select, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "selectedcandidatepairchange"_s, { EventType::selectedcandidatepairchange, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "selectend"_s, { EventType::selectend, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "selectionchange"_s, { EventType::selectionchange, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "selectstart"_s, { EventType::selectstart, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "shippingaddresschange"_s, { EventType::shippingaddresschange, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "shippingcontactselected"_s, { EventType::shippingcontactselected, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "shippingmethodselected"_s, { EventType::shippingmethodselected, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "shippingoptionchange"_s, { EventType::shippingoptionchange, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "show"_s, { EventType::show, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "signalingstatechange"_s, { EventType::signalingstatechange, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "slotchange"_s, { EventType::slotchange, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "soundend"_s, { EventType::soundend, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "soundstart"_s, { EventType::soundstart, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "sourceclose"_s, { EventType::sourceclose, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "sourceended"_s, { EventType::sourceended, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "sourceopen"_s, { EventType::sourceopen, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "speechend"_s, { EventType::speechend, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "speechstart"_s, { EventType::speechstart, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "squeeze"_s, { EventType::squeeze, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "squeezeend"_s, { EventType::squeezeend, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "squeezestart"_s, { EventType::squeezestart, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "stalled"_s, { EventType::stalled, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "start"_s, { EventType::start, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "started"_s, { EventType::started, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "startstreaming"_s, { EventType::startstreaming, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "statechange"_s, { EventType::statechange, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "stop"_s, { EventType::stop, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "storage"_s, { EventType::storage, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "submit"_s, { EventType::submit, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "success"_s, { EventType::success, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "suspend"_s, { EventType::suspend, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "textInput"_s, { EventType::textInput, { }, EventTypeInfo::DefaultEventHandler::Yes } },
        { "timeout"_s, { EventType::timeout, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "timeupdate"_s, { EventType::timeupdate, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "toggle"_s, { EventType::toggle, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "tonechange"_s, { EventType::tonechange, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "touchcancel"_s, { EventType::touchcancel, { EventCategory::TouchRelated, EventCategory::ExtendedTouchRelated }, EventTypeInfo::DefaultEventHandler::Yes } },
        { "touchend"_s, { EventType::touchend, { EventCategory::TouchRelated, EventCategory::ExtendedTouchRelated }, EventTypeInfo::DefaultEventHandler::Yes } },
        { "touchforcechange"_s, { EventType::touchforcechange, { EventCategory::TouchRelated, EventCategory::ExtendedTouchRelated }, EventTypeInfo::DefaultEventHandler::Yes } },
        { "touchmove"_s, { EventType::touchmove, { EventCategory::TouchScrollBlocking, EventCategory::TouchRelated, EventCategory::ExtendedTouchRelated }, EventTypeInfo::DefaultEventHandler::Yes } },
        { "touchstart"_s, { EventType::touchstart, { EventCategory::TouchScrollBlocking, EventCategory::TouchRelated, EventCategory::ExtendedTouchRelated }, EventTypeInfo::DefaultEventHandler::Yes } },
        { "track"_s, { EventType::track, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "transitioncancel"_s, { EventType::transitioncancel, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "transitionend"_s, { EventType::transitionend, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "transitionrun"_s, { EventType::transitionrun, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "transitionstart"_s, { EventType::transitionstart, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "uncapturederror"_s, { EventType::uncapturederror, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "unhandledrejection"_s, { EventType::unhandledrejection, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "unload"_s, { EventType::unload, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "unmute"_s, { EventType::unmute, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "update"_s, { EventType::update, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "updateend"_s, { EventType::updateend, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "updatefound"_s, { EventType::updatefound, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "updateready"_s, { EventType::updateready, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "updatestart"_s, { EventType::updatestart, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "upgradeneeded"_s, { EventType::upgradeneeded, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "validatemerchant"_s, { EventType::validatemerchant, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "versionchange"_s, { EventType::versionchange, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "visibilitychange"_s, { EventType::visibilitychange, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "voiceschanged"_s, { EventType::voiceschanged, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "volumechange"_s, { EventType::volumechange, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "waiting"_s, { EventType::waiting, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "waitingforkey"_s, { EventType::waitingforkey, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "webglcontextcreationerror"_s, { EventType::webglcontextcreationerror, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "webglcontextlost"_s, { EventType::webglcontextlost, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "webglcontextrestored"_s, { EventType::webglcontextrestored, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "webkitAnimationEnd"_s, { EventType::webkitAnimationEnd, { EventCategory::CSSAnimation }, EventTypeInfo::DefaultEventHandler::No } },
        { "webkitAnimationIteration"_s, { EventType::webkitAnimationIteration, { EventCategory::CSSAnimation }, EventTypeInfo::DefaultEventHandler::No } },
        { "webkitAnimationStart"_s, { EventType::webkitAnimationStart, { EventCategory::CSSAnimation }, EventTypeInfo::DefaultEventHandler::No } },
        { "webkitBeforeTextInserted"_s, { EventType::webkitBeforeTextInserted, { }, EventTypeInfo::DefaultEventHandler::Yes } },
        { "webkitTransitionEnd"_s, { EventType::webkitTransitionEnd, { EventCategory::CSSTransition }, EventTypeInfo::DefaultEventHandler::No } },
        { "webkitautofillrequest"_s, { EventType::webkitautofillrequest, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "webkitbeginfullscreen"_s, { EventType::webkitbeginfullscreen, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "webkitcurrentplaybacktargetiswirelesschanged"_s, { EventType::webkitcurrentplaybacktargetiswirelesschanged, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "webkitendfullscreen"_s, { EventType::webkitendfullscreen, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "webkitfullscreenchange"_s, { EventType::webkitfullscreenchange, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "webkitfullscreenerror"_s, { EventType::webkitfullscreenerror, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "webkitkeyadded"_s, { EventType::webkitkeyadded, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "webkitkeyerror"_s, { EventType::webkitkeyerror, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "webkitkeymessage"_s, { EventType::webkitkeymessage, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "webkitmediasessionmetadatachanged"_s, { EventType::webkitmediasessionmetadatachanged, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "webkitmouseforcechanged"_s, { EventType::webkitmouseforcechanged, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "webkitmouseforcedown"_s, { EventType::webkitmouseforcedown, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "webkitmouseforceup"_s, { EventType::webkitmouseforceup, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "webkitmouseforcewillbegin"_s, { EventType::webkitmouseforcewillbegin, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "webkitneedkey"_s, { EventType::webkitneedkey, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "webkitnetworkinfochange"_s, { EventType::webkitnetworkinfochange, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "webkitplaybacktargetavailabilitychanged"_s, { EventType::webkitplaybacktargetavailabilitychanged, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "webkitpresentationmodechanged"_s, { EventType::webkitpresentationmodechanged, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "webkitremovesourcebuffer"_s, { EventType::webkitremovesourcebuffer, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "webkitsourceclose"_s, { EventType::webkitsourceclose, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "webkitsourceended"_s, { EventType::webkitsourceended, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "webkitsourceopen"_s, { EventType::webkitsourceopen, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "wheel"_s, { EventType::wheel, { EventCategory::Wheel }, EventTypeInfo::DefaultEventHandler::Yes } },
        { "write"_s, { EventType::write, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "writeend"_s, { EventType::writeend, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "writestart"_s, { EventType::writestart, { }, EventTypeInfo::DefaultEventHandler::No } },
        { "zoom"_s, { EventType::zoom, { }, EventTypeInfo::DefaultEventHandler::No } },
    })
{ }

std::array<const AtomString, 326> EventNames::allEventNames() const
{
    return { {
        DOMActivateEvent,
        DOMCharacterDataModifiedEvent,
        DOMContentLoadedEvent,
        DOMNodeInsertedEvent,
        DOMNodeInsertedIntoDocumentEvent,
        DOMNodeRemovedEvent,
        DOMNodeRemovedFromDocumentEvent,
        DOMSubtreeModifiedEvent,
        abortEvent,
        activateEvent,
        activeEvent,
        addsourcebufferEvent,
        addstreamEvent,
        addtrackEvent,
        afterprintEvent,
        animationcancelEvent,
        animationendEvent,
        animationiterationEvent,
        animationstartEvent,
        audioendEvent,
        audioprocessEvent,
        audiostartEvent,
        autocompleteEvent,
        autocompleteerrorEvent,
        auxclickEvent,
        backgroundfetchabortEvent,
        backgroundfetchclickEvent,
        backgroundfetchfailEvent,
        backgroundfetchsuccessEvent,
        beforecopyEvent,
        beforecutEvent,
        beforeinputEvent,
        beforeloadEvent,
        beforematchEvent,
        beforepasteEvent,
        beforeprintEvent,
        beforetoggleEvent,
        beforeunloadEvent,
        beginEventEvent,
        blockedEvent,
        blurEvent,
        boundaryEvent,
        bufferedamountlowEvent,
        bufferedchangeEvent,
        cachedEvent,
        cancelEvent,
        canplayEvent,
        canplaythroughEvent,
        changeEvent,
        chargingchangeEvent,
        chargingtimechangeEvent,
        checkingEvent,
        clickEvent,
        closeEvent,
        closingEvent,
        commandEvent,
        completeEvent,
        compositionendEvent,
        compositionstartEvent,
        compositionupdateEvent,
        configurationchangeEvent,
        connectEvent,
        connectingEvent,
        connectionstatechangeEvent,
        contentvisibilityautostatechangeEvent,
        contextmenuEvent,
        controllerchangeEvent,
        cookiechangeEvent,
        coordinatorstatechangeEvent,
        copyEvent,
#if ENABLE(APPLE_PAY_COUPON_CODE)
        couponcodechangedEvent,
#endif
        cuechangeEvent,
        currententrychangeEvent,
        cutEvent,
        dataavailableEvent,
        datachannelEvent,
        dblclickEvent,
        dequeueEvent,
        devicechangeEvent,
        devicemotionEvent,
        deviceorientationEvent,
        dischargingtimechangeEvent,
        disconnectEvent,
        disposeEvent,
        downloadingEvent,
        dragEvent,
        dragendEvent,
        dragenterEvent,
        dragleaveEvent,
        dragoverEvent,
        dragstartEvent,
        dropEvent,
        durationchangeEvent,
        emptiedEvent,
        encryptedEvent,
        endEvent,
        endEventEvent,
        endedEvent,
        endstreamingEvent,
        enterEvent,
        enterpictureinpictureEvent,
        errorEvent,
        exitEvent,
        fetchEvent,
        finishEvent,
        focusEvent,
        focusinEvent,
        focusoutEvent,
        formdataEvent,
        fullscreenchangeEvent,
        fullscreenerrorEvent,
        gamepadconnectedEvent,
        gamepaddisconnectedEvent,
        gatheringstatechangeEvent,
        gesturechangeEvent,
        gestureendEvent,
        gesturescrollendEvent,
        gesturescrollstartEvent,
        gesturescrollupdateEvent,
        gesturestartEvent,
        gesturetapEvent,
        gesturetapdownEvent,
        gotpointercaptureEvent,
        hashchangeEvent,
        icecandidateEvent,
        icecandidateerrorEvent,
        iceconnectionstatechangeEvent,
        icegatheringstatechangeEvent,
        inactiveEvent,
        inputEvent,
        inputsourceschangeEvent,
        installEvent,
        invalidEvent,
        keydownEvent,
        keypressEvent,
        keystatuseschangeEvent,
        keyupEvent,
        languagechangeEvent,
        leavepictureinpictureEvent,
        levelchangeEvent,
        loadEvent,
        loadeddataEvent,
        loadedmetadataEvent,
        loadendEvent,
        loadingEvent,
        loadingdoneEvent,
        loadingerrorEvent,
        loadstartEvent,
        lostpointercaptureEvent,
        markEvent,
        merchantvalidationEvent,
        messageEvent,
        messageerrorEvent,
        mousedownEvent,
        mouseenterEvent,
        mouseleaveEvent,
        mousemoveEvent,
        mouseoutEvent,
        mouseoverEvent,
        mouseupEvent,
        mousewheelEvent,
        muteEvent,
        navigateEvent,
        navigateerrorEvent,
        navigatesuccessEvent,
        negotiationneededEvent,
        nexttrackEvent,
        nomatchEvent,
        notificationclickEvent,
        notificationcloseEvent,
        noupdateEvent,
        obsoleteEvent,
        offlineEvent,
        onlineEvent,
        openEvent,
        orientationchangeEvent,
        overflowchangedEvent,
        pagehideEvent,
        pagerevealEvent,
        pageshowEvent,
        pageswapEvent,
        pasteEvent,
        pauseEvent,
        payerdetailchangeEvent,
        paymentauthorizedEvent,
        paymentmethodchangeEvent,
        paymentmethodselectedEvent,
        playEvent,
        playingEvent,
        pointercancelEvent,
        pointerdownEvent,
        pointerenterEvent,
        pointerleaveEvent,
        pointerlockchangeEvent,
        pointerlockerrorEvent,
        pointermoveEvent,
        pointeroutEvent,
        pointeroverEvent,
        pointerupEvent,
        popstateEvent,
        previoustrackEvent,
        processorerrorEvent,
        progressEvent,
        pushEvent,
        pushnotificationEvent,
        pushsubscriptionchangeEvent,
        qualitychangeEvent,
        ratechangeEvent,
        readystatechangeEvent,
        redrawEvent,
        rejectionhandledEvent,
        releaseEvent,
        removeEvent,
        removesourcebufferEvent,
        removestreamEvent,
        removetrackEvent,
        resetEvent,
        resizeEvent,
        resourcetimingbufferfullEvent,
        resultEvent,
        resumeEvent,
        rtctransformEvent,
        scrollEvent,
        scrollendEvent,
        securitypolicyviolationEvent,
        seekedEvent,
        seekingEvent,
        selectEvent,
        selectedcandidatepairchangeEvent,
        selectendEvent,
        selectionchangeEvent,
        selectstartEvent,
        shippingaddresschangeEvent,
        shippingcontactselectedEvent,
        shippingmethodselectedEvent,
        shippingoptionchangeEvent,
        showEvent,
        signalingstatechangeEvent,
        slotchangeEvent,
        soundendEvent,
        soundstartEvent,
        sourcecloseEvent,
        sourceendedEvent,
        sourceopenEvent,
        speechendEvent,
        speechstartEvent,
        squeezeEvent,
        squeezeendEvent,
        squeezestartEvent,
        stalledEvent,
        startEvent,
        startedEvent,
        startstreamingEvent,
        statechangeEvent,
        stopEvent,
        storageEvent,
        submitEvent,
        successEvent,
        suspendEvent,
        textInputEvent,
        timeoutEvent,
        timeupdateEvent,
        toggleEvent,
        tonechangeEvent,
        touchcancelEvent,
        touchendEvent,
        touchforcechangeEvent,
        touchmoveEvent,
        touchstartEvent,
        trackEvent,
        transitioncancelEvent,
        transitionendEvent,
        transitionrunEvent,
        transitionstartEvent,
        uncapturederrorEvent,
        unhandledrejectionEvent,
        unloadEvent,
        unmuteEvent,
        updateEvent,
        updateendEvent,
        updatefoundEvent,
        updatereadyEvent,
        updatestartEvent,
        upgradeneededEvent,
        validatemerchantEvent,
        versionchangeEvent,
        visibilitychangeEvent,
        voiceschangedEvent,
        volumechangeEvent,
        waitingEvent,
        waitingforkeyEvent,
        webglcontextcreationerrorEvent,
        webglcontextlostEvent,
        webglcontextrestoredEvent,
        webkitAnimationEndEvent,
        webkitAnimationIterationEvent,
        webkitAnimationStartEvent,
        webkitBeforeTextInsertedEvent,
        webkitTransitionEndEvent,
        webkitautofillrequestEvent,
        webkitbeginfullscreenEvent,
        webkitcurrentplaybacktargetiswirelesschangedEvent,
        webkitendfullscreenEvent,
        webkitfullscreenchangeEvent,
        webkitfullscreenerrorEvent,
        webkitkeyaddedEvent,
        webkitkeyerrorEvent,
        webkitkeymessageEvent,
        webkitmediasessionmetadatachangedEvent,
        webkitmouseforcechangedEvent,
        webkitmouseforcedownEvent,
        webkitmouseforceupEvent,
        webkitmouseforcewillbeginEvent,
        webkitneedkeyEvent,
        webkitnetworkinfochangeEvent,
        webkitplaybacktargetavailabilitychangedEvent,
        webkitpresentationmodechangedEvent,
        webkitremovesourcebufferEvent,
        webkitsourcecloseEvent,
        webkitsourceendedEvent,
        webkitsourceopenEvent,
        wheelEvent,
        writeEvent,
        writeendEvent,
        writestartEvent,
        zoomEvent,
    } };
}

WTF::HashSet<AtomString> EventNames::allEventHandlerNames() const
{
    WTF::HashSet<AtomString> set;
    set.add("ondomactivate"_s);
    set.add("ondomcharacterdatamodified"_s);
    set.add("ondomcontentloaded"_s);
    set.add("ondomnodeinserted"_s);
    set.add("ondomnodeinsertedintodocument"_s);
    set.add("ondomnoderemoved"_s);
    set.add("ondomnoderemovedfromdocument"_s);
    set.add("ondomsubtreemodified"_s);
    set.add("onabort"_s);
    set.add("onactivate"_s);
    set.add("onactive"_s);
    set.add("onaddsourcebuffer"_s);
    set.add("onaddstream"_s);
    set.add("onaddtrack"_s);
    set.add("onafterprint"_s);
    set.add("onanimationcancel"_s);
    set.add("onanimationend"_s);
    set.add("onanimationiteration"_s);
    set.add("onanimationstart"_s);
    set.add("onaudioend"_s);
    set.add("onaudioprocess"_s);
    set.add("onaudiostart"_s);
    set.add("onautocomplete"_s);
    set.add("onautocompleteerror"_s);
    set.add("onauxclick"_s);
    set.add("onbackgroundfetchabort"_s);
    set.add("onbackgroundfetchclick"_s);
    set.add("onbackgroundfetchfail"_s);
    set.add("onbackgroundfetchsuccess"_s);
    set.add("onbeforecopy"_s);
    set.add("onbeforecut"_s);
    set.add("onbeforeinput"_s);
    set.add("onbeforeload"_s);
    set.add("onbeforematch"_s);
    set.add("onbeforepaste"_s);
    set.add("onbeforeprint"_s);
    set.add("onbeforetoggle"_s);
    set.add("onbeforeunload"_s);
    set.add("onbeginevent"_s);
    set.add("onblocked"_s);
    set.add("onblur"_s);
    set.add("onboundary"_s);
    set.add("onbufferedamountlow"_s);
    set.add("onbufferedchange"_s);
    set.add("oncached"_s);
    set.add("oncancel"_s);
    set.add("oncanplay"_s);
    set.add("oncanplaythrough"_s);
    set.add("onchange"_s);
    set.add("onchargingchange"_s);
    set.add("onchargingtimechange"_s);
    set.add("onchecking"_s);
    set.add("onclick"_s);
    set.add("onclose"_s);
    set.add("onclosing"_s);
    set.add("oncommand"_s);
    set.add("oncomplete"_s);
    set.add("oncompositionend"_s);
    set.add("oncompositionstart"_s);
    set.add("oncompositionupdate"_s);
    set.add("onconfigurationchange"_s);
    set.add("onconnect"_s);
    set.add("onconnecting"_s);
    set.add("onconnectionstatechange"_s);
    set.add("oncontentvisibilityautostatechange"_s);
    set.add("oncontextmenu"_s);
    set.add("oncontrollerchange"_s);
    set.add("oncookiechange"_s);
    set.add("oncoordinatorstatechange"_s);
    set.add("oncopy"_s);
#if ENABLE(APPLE_PAY_COUPON_CODE)
    set.add("oncouponcodechanged"_s);
#endif
    set.add("oncuechange"_s);
    set.add("oncurrententrychange"_s);
    set.add("oncut"_s);
    set.add("ondataavailable"_s);
    set.add("ondatachannel"_s);
    set.add("ondblclick"_s);
    set.add("ondequeue"_s);
    set.add("ondevicechange"_s);
    set.add("ondevicemotion"_s);
    set.add("ondeviceorientation"_s);
    set.add("ondischargingtimechange"_s);
    set.add("ondisconnect"_s);
    set.add("ondispose"_s);
    set.add("ondownloading"_s);
    set.add("ondrag"_s);
    set.add("ondragend"_s);
    set.add("ondragenter"_s);
    set.add("ondragleave"_s);
    set.add("ondragover"_s);
    set.add("ondragstart"_s);
    set.add("ondrop"_s);
    set.add("ondurationchange"_s);
    set.add("onemptied"_s);
    set.add("onencrypted"_s);
    set.add("onend"_s);
    set.add("onendevent"_s);
    set.add("onended"_s);
    set.add("onendstreaming"_s);
    set.add("onenter"_s);
    set.add("onenterpictureinpicture"_s);
    set.add("onerror"_s);
    set.add("onexit"_s);
    set.add("onfetch"_s);
    set.add("onfinish"_s);
    set.add("onfocus"_s);
    set.add("onfocusin"_s);
    set.add("onfocusout"_s);
    set.add("onformdata"_s);
    set.add("onfullscreenchange"_s);
    set.add("onfullscreenerror"_s);
    set.add("ongamepadconnected"_s);
    set.add("ongamepaddisconnected"_s);
    set.add("ongatheringstatechange"_s);
    set.add("ongesturechange"_s);
    set.add("ongestureend"_s);
    set.add("ongesturescrollend"_s);
    set.add("ongesturescrollstart"_s);
    set.add("ongesturescrollupdate"_s);
    set.add("ongesturestart"_s);
    set.add("ongesturetap"_s);
    set.add("ongesturetapdown"_s);
    set.add("ongotpointercapture"_s);
    set.add("onhashchange"_s);
    set.add("onicecandidate"_s);
    set.add("onicecandidateerror"_s);
    set.add("oniceconnectionstatechange"_s);
    set.add("onicegatheringstatechange"_s);
    set.add("oninactive"_s);
    set.add("oninput"_s);
    set.add("oninputsourceschange"_s);
    set.add("oninstall"_s);
    set.add("oninvalid"_s);
    set.add("onkeydown"_s);
    set.add("onkeypress"_s);
    set.add("onkeystatuseschange"_s);
    set.add("onkeyup"_s);
    set.add("onlanguagechange"_s);
    set.add("onleavepictureinpicture"_s);
    set.add("onlevelchange"_s);
    set.add("onload"_s);
    set.add("onloadeddata"_s);
    set.add("onloadedmetadata"_s);
    set.add("onloadend"_s);
    set.add("onloading"_s);
    set.add("onloadingdone"_s);
    set.add("onloadingerror"_s);
    set.add("onloadstart"_s);
    set.add("onlostpointercapture"_s);
    set.add("onmark"_s);
    set.add("onmerchantvalidation"_s);
    set.add("onmessage"_s);
    set.add("onmessageerror"_s);
    set.add("onmousedown"_s);
    set.add("onmouseenter"_s);
    set.add("onmouseleave"_s);
    set.add("onmousemove"_s);
    set.add("onmouseout"_s);
    set.add("onmouseover"_s);
    set.add("onmouseup"_s);
    set.add("onmousewheel"_s);
    set.add("onmute"_s);
    set.add("onnavigate"_s);
    set.add("onnavigateerror"_s);
    set.add("onnavigatesuccess"_s);
    set.add("onnegotiationneeded"_s);
    set.add("onnexttrack"_s);
    set.add("onnomatch"_s);
    set.add("onnotificationclick"_s);
    set.add("onnotificationclose"_s);
    set.add("onnoupdate"_s);
    set.add("onobsolete"_s);
    set.add("onoffline"_s);
    set.add("ononline"_s);
    set.add("onopen"_s);
    set.add("onorientationchange"_s);
    set.add("onoverflowchanged"_s);
    set.add("onpagehide"_s);
    set.add("onpagereveal"_s);
    set.add("onpageshow"_s);
    set.add("onpageswap"_s);
    set.add("onpaste"_s);
    set.add("onpause"_s);
    set.add("onpayerdetailchange"_s);
    set.add("onpaymentauthorized"_s);
    set.add("onpaymentmethodchange"_s);
    set.add("onpaymentmethodselected"_s);
    set.add("onplay"_s);
    set.add("onplaying"_s);
    set.add("onpointercancel"_s);
    set.add("onpointerdown"_s);
    set.add("onpointerenter"_s);
    set.add("onpointerleave"_s);
    set.add("onpointerlockchange"_s);
    set.add("onpointerlockerror"_s);
    set.add("onpointermove"_s);
    set.add("onpointerout"_s);
    set.add("onpointerover"_s);
    set.add("onpointerup"_s);
    set.add("onpopstate"_s);
    set.add("onprevioustrack"_s);
    set.add("onprocessorerror"_s);
    set.add("onprogress"_s);
    set.add("onpush"_s);
    set.add("onpushnotification"_s);
    set.add("onpushsubscriptionchange"_s);
    set.add("onqualitychange"_s);
    set.add("onratechange"_s);
    set.add("onreadystatechange"_s);
    set.add("onredraw"_s);
    set.add("onrejectionhandled"_s);
    set.add("onrelease"_s);
    set.add("onremove"_s);
    set.add("onremovesourcebuffer"_s);
    set.add("onremovestream"_s);
    set.add("onremovetrack"_s);
    set.add("onreset"_s);
    set.add("onresize"_s);
    set.add("onresourcetimingbufferfull"_s);
    set.add("onresult"_s);
    set.add("onresume"_s);
    set.add("onrtctransform"_s);
    set.add("onscroll"_s);
    set.add("onscrollend"_s);
    set.add("onsecuritypolicyviolation"_s);
    set.add("onseeked"_s);
    set.add("onseeking"_s);
    set.add("onselect"_s);
    set.add("onselectedcandidatepairchange"_s);
    set.add("onselectend"_s);
    set.add("onselectionchange"_s);
    set.add("onselectstart"_s);
    set.add("onshippingaddresschange"_s);
    set.add("onshippingcontactselected"_s);
    set.add("onshippingmethodselected"_s);
    set.add("onshippingoptionchange"_s);
    set.add("onshow"_s);
    set.add("onsignalingstatechange"_s);
    set.add("onslotchange"_s);
    set.add("onsoundend"_s);
    set.add("onsoundstart"_s);
    set.add("onsourceclose"_s);
    set.add("onsourceended"_s);
    set.add("onsourceopen"_s);
    set.add("onspeechend"_s);
    set.add("onspeechstart"_s);
    set.add("onsqueeze"_s);
    set.add("onsqueezeend"_s);
    set.add("onsqueezestart"_s);
    set.add("onstalled"_s);
    set.add("onstart"_s);
    set.add("onstarted"_s);
    set.add("onstartstreaming"_s);
    set.add("onstatechange"_s);
    set.add("onstop"_s);
    set.add("onstorage"_s);
    set.add("onsubmit"_s);
    set.add("onsuccess"_s);
    set.add("onsuspend"_s);
    set.add("ontextinput"_s);
    set.add("ontimeout"_s);
    set.add("ontimeupdate"_s);
    set.add("ontoggle"_s);
    set.add("ontonechange"_s);
    set.add("ontouchcancel"_s);
    set.add("ontouchend"_s);
    set.add("ontouchforcechange"_s);
    set.add("ontouchmove"_s);
    set.add("ontouchstart"_s);
    set.add("ontrack"_s);
    set.add("ontransitioncancel"_s);
    set.add("ontransitionend"_s);
    set.add("ontransitionrun"_s);
    set.add("ontransitionstart"_s);
    set.add("onuncapturederror"_s);
    set.add("onunhandledrejection"_s);
    set.add("onunload"_s);
    set.add("onunmute"_s);
    set.add("onupdate"_s);
    set.add("onupdateend"_s);
    set.add("onupdatefound"_s);
    set.add("onupdateready"_s);
    set.add("onupdatestart"_s);
    set.add("onupgradeneeded"_s);
    set.add("onvalidatemerchant"_s);
    set.add("onversionchange"_s);
    set.add("onvisibilitychange"_s);
    set.add("onvoiceschanged"_s);
    set.add("onvolumechange"_s);
    set.add("onwaiting"_s);
    set.add("onwaitingforkey"_s);
    set.add("onwebglcontextcreationerror"_s);
    set.add("onwebglcontextlost"_s);
    set.add("onwebglcontextrestored"_s);
    set.add("onwebkitanimationend"_s);
    set.add("onwebkitanimationiteration"_s);
    set.add("onwebkitanimationstart"_s);
    set.add("onwebkitbeforetextinserted"_s);
    set.add("onwebkittransitionend"_s);
    set.add("onwebkitautofillrequest"_s);
    set.add("onwebkitbeginfullscreen"_s);
    set.add("onwebkitcurrentplaybacktargetiswirelesschanged"_s);
    set.add("onwebkitendfullscreen"_s);
    set.add("onwebkitfullscreenchange"_s);
    set.add("onwebkitfullscreenerror"_s);
    set.add("onwebkitkeyadded"_s);
    set.add("onwebkitkeyerror"_s);
    set.add("onwebkitkeymessage"_s);
    set.add("onwebkitmediasessionmetadatachanged"_s);
    set.add("onwebkitmouseforcechanged"_s);
    set.add("onwebkitmouseforcedown"_s);
    set.add("onwebkitmouseforceup"_s);
    set.add("onwebkitmouseforcewillbegin"_s);
    set.add("onwebkitneedkey"_s);
    set.add("onwebkitnetworkinfochange"_s);
    set.add("onwebkitplaybacktargetavailabilitychanged"_s);
    set.add("onwebkitpresentationmodechanged"_s);
    set.add("onwebkitremovesourcebuffer"_s);
    set.add("onwebkitsourceclose"_s);
    set.add("onwebkitsourceended"_s);
    set.add("onwebkitsourceopen"_s);
    set.add("onwheel"_s);
    set.add("onwrite"_s);
    set.add("onwriteend"_s);
    set.add("onwritestart"_s);
    set.add("onzoom"_s);
    return set;

}

} // namespace WebCore
