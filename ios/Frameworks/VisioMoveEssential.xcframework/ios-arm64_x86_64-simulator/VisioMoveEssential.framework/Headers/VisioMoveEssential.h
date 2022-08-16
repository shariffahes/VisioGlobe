/*
 * Copyright (c) Visioglobe SAS. All rights reserved.
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE.txt', which is part of this source code package.
 */

#import <UIKit/UIKit.h>

#import <VisioMoveEssential/VMEMacros.h>
#import <VisioMoveEssential/VMEAnchorMode.h>
#import <VisioMoveEssential/VMEAnimationCallback.h>
#import <VisioMoveEssential/VMEBuildingListener.h>
#import <VisioMoveEssential/VMECameraHeading.h>
#import <VisioMoveEssential/VMECameraMoveReason.h>
#import <VisioMoveEssential/VMECameraUpdate.h>
#import <VisioMoveEssential/VMECameraUpdateBuilder.h>
#import <VisioMoveEssential/VMECategory.h>
#import <VisioMoveEssential/VMEComputeRouteCallback.h>
#import <VisioMoveEssential/VMELifeCycleListener.h>
#import <VisioMoveEssential/VMELatLng.h>
#import <VisioMoveEssential/VMELocation.h>
#import <VisioMoveEssential/VMELocationTrackingMode.h>
#import <VisioMoveEssential/VMELocationTrackingModeListener.h>
#import <VisioMoveEssential/VMEManeuverType.h>
#import <VisioMoveEssential/VMEMapDescriptor.h>
#import <VisioMoveEssential/VMEMapListener.h>
#import <VisioMoveEssential/VMEMapView.h>
#import <VisioMoveEssential/VMEPlace.h>
#import <VisioMoveEssential/VMEPlaceAltitudeMode.h>
#import <VisioMoveEssential/VMEPlaceAnchorMode.h>
#import <VisioMoveEssential/VMEPlaceDisplayMode.h>
#import <VisioMoveEssential/VMEPlaceFilter.h>
#import <VisioMoveEssential/VMEPlaceFilterCallback.h>
#import <VisioMoveEssential/VMEPlaceListener.h>
#import <VisioMoveEssential/VMEPlaceOrientation.h>
#import <VisioMoveEssential/VMEPlaceSize.h>
#import <VisioMoveEssential/VMEPlaceVisibilityRamp.h>
#import <VisioMoveEssential/VMEPosition.h>
#import <VisioMoveEssential/VMERouteRequest.h>
#import <VisioMoveEssential/VMERouteResult.h>
#import <VisioMoveEssential/VMESegment.h>
#import <VisioMoveEssential/VMESceneContext.h>
#import <VisioMoveEssential/VMESceneUpdate.h>
#import <VisioMoveEssential/VMESearchViewCallback.h>
#import <VisioMoveEssential/VMEViewMode.h>

#define VME_VERSION_STRING @"1.27.1"
#define VME_MIN_DATA_SDK_VERSION_STRING @"2.1.3"
