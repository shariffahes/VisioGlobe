/*
 * Copyright (c) Visioglobe SAS. All rights reserved.
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE.txt', which is part of this source code package.
 */

#import "VMEPosition.h"

/**
 * @ingroup models
 * @brief A VMELocation object incorporates the position within the map as well
 * as values indicating the accuracy of the measurements and the bearing in which 
 * the location is moving.
 *
 * @version 1.2
 */
@interface VMELocation : NSObject <NSCopying>

/**
 * Instantiate a new instance of VMELocation
 *
 * @param position The position of the location.  The position is represented 
 * graphically within the map.
 * @param bearing The bearing of the location. The bearing is used to orient the camera when
 * location tracker is enabled. Negative values will be ignored.
 * @param accuracy The radius of uncertainty for the location, measured in 
 * meters.  The accuracy is represented graphically within the map.  Negative values will be ignored.
 *
 * @returns A new VMELocation object.
 *
 * @version 1.2
 */
-(instancetype) initWithPosition:(VMEPosition*) position
                         bearing:(double) bearing
                        accuracy:(double) accuracy;

/**
 * The physical position within the map.
 *
 * @version 1.2
 */
@property (nonatomic, readonly) VMEPosition* position;

/**
 * Horizontal accuracy.  The radius of uncertainty for the location, measured in meters.
 *
 * @version 1.2
 */
@property (nonatomic, readonly) double accuracy;

/**
 * The direction in which the device is traveling.
 *
 * @version 1.2
 */
@property (nonatomic, readonly) double bearing;
@end
