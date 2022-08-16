/*
 * Copyright (c) Visioglobe SAS. All rights reserved.
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE.txt', which is part of this source code package.
 */

/**
 * @ingroup models
 * @brief VMECameraHeading represents a heading element that may be associated
 * with a VMECameraUpdate object.
 *
 * It encapsulates some logic for controlling the camera's heading. It should only
 * be constructed using the factory helper methods below.
 *
 * The VMECameraHeading object is immutable.
 *
 * @version 1.2
 */
@interface VMECameraHeading : NSObject <NSCopying>

/**
 * Keep the camera's current heading.
 *
 * @version 1.2
 */
+(instancetype)cameraHeadingCurrent;

/**
 * Use the place's defined heading.
 *
 * @param placeID The id of the place who's heading should be used.
 *
 * @version 1.2
 */
+(instancetype)cameraHeadingForPlaceID:(NSString*) placeID;

/**
 * Provide a specific heading
 *
 * @param heading The heading value to be applied to the camera (0 for north,
 * increasing value start to east).
 *
 * @version 1.2
 */
+(instancetype)cameraHeadingWithHeading:(float)heading;

-(BOOL) isEqualToHeading:(VMECameraHeading*) pHeading;
@end
