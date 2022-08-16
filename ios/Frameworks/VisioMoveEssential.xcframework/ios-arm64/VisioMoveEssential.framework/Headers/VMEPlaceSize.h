/*
 * Copyright (c) Visioglobe SAS. All rights reserved.
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE.txt', which is part of this source code package.
 */

/**
 * @ingroup models
 * @brief An object that determines the size of the place within the map
 * @version 1.1
 */
@interface VMEPlaceSize : NSObject
/**
 * Create an place size object with a scale
 *
 * @param scale The scale in meters to apply to the place.
 *
 * @version 1.1
 */
-(instancetype)initWithScale:(float)scale;
/**
 * Create an place size object with a scale and a constant size distance.
 *
 * @param scale The scale in meters to apply to the place.
 * @param constantSizeDistance Controls the distance at which the place does not
 * become bigger as you approach it
 *
 * @version 1.1
 */
-(instancetype)initWithScale:(float)scale
        constantSizeDistance:(float)constantSizeDistance;
/**
 * Controls the distance at which the place does not become bigger as you approach
 * it. When the camera is within this distance of the place, the visible size of
 * the place on the screen will be the same as what it looked like when it was
 * constantSizeDistance meters away. If set to 0.0, the size of the place will be
 * determined by scale, regardless of it's distance from the camera.
 *
 * Default value is set to 0.
 *
 * @version 1.1
 */
@property (nonatomic, readonly) float constantSizeDistance;
/**
 * The scale in meters to apply to the place.
 *
 * @version 1.1
 */
@property (nonatomic, readonly) float scale;
@end
