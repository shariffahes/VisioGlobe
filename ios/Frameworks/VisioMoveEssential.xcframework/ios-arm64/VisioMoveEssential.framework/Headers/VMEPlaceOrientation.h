/*
 * Copyright (c) Visioglobe SAS. All rights reserved.
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE.txt', which is part of this source code package.
 */

/**
 * @ingroup models
 * @brief VMEPlaceOrientation represents an orientation element that may be
 * associated with a place object.
 *
 * It encapsulates some logic for controlling the camera's heading. It should only
 * be constructed using the factory helper methods below.
 *
 * @version 1.1
 */
@interface  VMEPlaceOrientation : NSObject
/**
 * Place is always camera facing.
 *
 * @version 1.2
 */
+(instancetype)placeOrientationFacing;
/**
 * Place is flat on ground and facing camera
 *
 * @version 1.2
 */
+(instancetype)placeOrientationFlat;
/**
 * Place is flat on ground and has a fixed heading
 *
 * @version 1.2
 */
+(instancetype)placeOrientationFixedWithHeading:(float)heading;
@end
