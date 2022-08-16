/*
 * Copyright (c) Visioglobe SAS. All rights reserved.
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE.txt', which is part of this source code package.
 */

#import "VMECameraMoveReason.h"

@class VMELatLng;

/**
 * @ingroup models
 * @brief An immutable class that aggregates all camera context such as target, altitude, bearing, pitch, and radius.
 *
 *
 * @version 1.24
 */
@interface VMECameraContext : NSObject

/**
 * Create a VMECameraContext object
 *
 * @param target The latitude and longitude coordinates that the camera is focused on.
 * @param altitude The distance (in meters) between the camera and the ground.
 * @param radius The distance (in meters) between the camera and the target.
 * @param pitch The tilt angle of the camera.  A pitch of 0 degrees indicates the camera is looking
 *              at the horizon.  A pitch of -90 degree indicates the camera is looking directly
 *              at the ground.
 * @param bearing The bearing angle of the camera.  A bearing of 0 degrees indicates North.
 *
 * @version 1.24
 */
-(instancetype)initWithLatLng:(VMELatLng*)target altitude:(double)altitude radius:(double)radius pitch:(double)pitch bearing:(double)bearing;

/**
 * The location that the camera is pointing at.
 *
 * @version 1.24
 */
@property (nonatomic, readonly) VMELatLng* target;

/**
 * The altitude of the camera.
 *
 * @version 1.24
 */
@property (nonatomic, readonly) double altitude;

/**
 * Direction that the camera is pointing in, in degrees clockwise from north.
 *
 * @version 1.24
 */
@property (nonatomic, readonly) double bearing;

/**
 * The pitch, in degrees, of the camera angle from the horizon (0 degrees is looking towards the horizon, -90 is looking towards the ground, and 90 is looking towards the sky).
 *
 * @version 1.24
 */
@property (nonatomic, readonly) double pitch;

/**
 * The distance between the camera to the ground along is pitch angle.
 *
 * @version 1.24
 */
@property (nonatomic, readonly) double radius;

/**
 * Compares this camera context to the specified object.
 * @param object The camera context to compare this camera context against.
 * @returns YES if this VMECameraContext represents the same camera context as the specified, NO otherwise.
 *
 * @version 1.24
 */
-(BOOL) isEqual:(id) object;

/**
 * @returns Returns a string that describes the contents of the receiver.
 */
- (NSString *)description;
@end

