/*
 * Copyright (c) Visioglobe SAS. All rights reserved.
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE.txt', which is part of this source code package.
 */

/**
 * @ingroup models
 * @brief VMECameraDistanceRange represents a distance element that may be associated
 * with a VMECameraUpdate object.
 *
 * It encapsulates some logic for controlling the distance of the camera. It should only
 * be constructed using the factory helper methods below.
 
 * The camera will use the previously specified camera distance range when it's not specified in the camera update.
 * @example
 * @code
 VMECameraUpdate* lUpdate = [VMECameraUpdate cameraUpdateWithBuilderBlock:^(VMECameraUpdateBuilder *builder) {
    builder.distanceRange = [VMECameraDistanceRange cameraDistanceRangeMinAltitude:100 andMaxAltitude:100];
 }];
 * @endcode
 * @note In the above example, the camera will keep its altitude = 100 until another VMECameraUpdate
 * is set with a new VMECameraDistanceRange.
 *
 * The VMECameraDistanceRange object is immutable.
 *
 * @version 1.18
 */
@interface VMECameraDistanceRange : NSObject <NSCopying>

/**
 * Keep the camera's current altitude range.
 *
 * @version 1.18
 */
+(instancetype)cameraDistanceCurrentAltitudeRange;

/**
 * Use the default altitude range.
 *
 * @version 1.18
 */
+(instancetype)cameraDistanceDefaultAltitudeRange;

/**
 * Use the radius to control the distance of the camera.
 *
 * The radius distance is represented as the distance from the camera to the ground along the camera's view axis.
 * Internally the radius distance will be converted to a min/max altitude which must respect the min/max altitude limits
 * of the map.
 *
 * @param minRadius the minimum radius of the camera
 * @param maxRadius the maximum radius of the camera
 *
 * @version 1.18
 */
+(instancetype)cameraDistanceRangeMinRadius:(double)minRadius andMaxRadius:(double)maxRadius;

/**
 * Use the altitude  to control the distance of the camera
 * @param minAltitude the minimum altitude of the camera, can't be lower than the minimum altitude set in VisioMapEditor
 * @param maxAltitude the maximum altitude of the camera, can't be higher than the maximum altitude set in VisioMapEditor
 *
 * @version 1.18
 */
+(instancetype)cameraDistanceRangeMinAltitude:(double)minAltitude andMaxAltitude:(double)maxAltitude;

-(BOOL) isEqualToCameraDistanceRange:(VMECameraDistanceRange*) pDistanceRange;
@end
