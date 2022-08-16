/*
 * Copyright (c) Visioglobe SAS. All rights reserved.
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE.txt', which is part of this source code package.
 */
#import <Foundation/Foundation.h>
#import <VisioMoveEssential/VMEViewMode.h>
#import <VisioMoveEssential/VMECameraHeading.h>
#import <VisioMoveEssential/VMECameraPitch.h>
#import <VisioMoveEssential/VMECameraDistanceRange.h>

#import "VMEMacros.h"
/**
 * @ingroup models
 * @brief Used to build a VMECameraUpdate object.
 *
 * @version 1.7
 */
@interface VMECameraUpdateBuilder : NSObject
/**
 * @see For more info, VMECameraUpdate.targets.
 *
 * @version 1.7
 */
@property (nonatomic, copy) NSArray* targets;
/**
 * @see For more info, VMECameraUpdate.viewMode.
 *
 * @version 1.7
 */
@property (nonatomic) VMEViewMode viewMode;
/**
 * @see For more info, VMECameraUpdate.heading.
 *
 * @version 1.7
 */
@property (nonatomic, copy) VMECameraHeading* heading;
/**
 * @see For more info, VMECameraUpdate.paddingTop.
 *
 * @version 1.7
 */
@property (nonatomic) CGFloat paddingTop;
/**
 * @see For more info, VMECameraUpdate.paddingBottom.
 *
 * @version 1.7
 */
@property (nonatomic) CGFloat paddingBottom;
/**
 * @see For more info, VMECameraUpdate.paddingLeft.
 *
 * @version 1.7
 */
@property (nonatomic) CGFloat paddingLeft;
/**
 * @see For more info, VMECameraUpdate.paddingRight.
 *
 * @version 1.7
 */
@property (nonatomic) CGFloat paddingRight;
/**
 * @see For more info, VMECameraUpdate.minAltitude.
 *
 * @version 1.7
 * @deprecated Deprecated in 1.18.  Replaced with VMECameraUpdateBuilder::distanceRange.
 */
@property (nonatomic) double minAltitude VME_DEPRECATED_MSG("Please use VMECameraUpdate.distanceRange");
/**
 * @see For more info, VMECameraUpdate.maxAltitude.
 *
 * @version 1.7
 * @deprecated Deprecated in 1.18.  Replaced with VMECameraUpdateBuilder::distanceRange.
 */
@property (nonatomic) double maxAltitude VME_DEPRECATED_MSG("Please use VMECameraUpdate.distanceRange");
/**
 * @see For more info, VMECameraUpdate.pitch.
 *
 * @version 1.18
 */
@property (nonatomic, copy) VMECameraPitch* pitch;
/**
 * @see For more info, VMECameraUpdate.distanceRange.
 *
 * @version 1.18
 */
@property (nonatomic, copy) VMECameraDistanceRange* distanceRange;

@end
