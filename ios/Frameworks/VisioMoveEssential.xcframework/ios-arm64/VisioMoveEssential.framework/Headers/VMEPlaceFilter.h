/*
 * Copyright (c) Visioglobe SAS. All rights reserved.
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE.txt', which is part of this source code package.
 */

#import "VMEPosition.h"

/**
 * @ingroup models
 * @brief An object that defines the criteria for performing a place query.
 *
 * @version 1.8
 */
@interface VMEPlaceFilter : NSObject
/**
 * The target is the center point around which the filter parameters will be applied.
 *
 * @version 1.8
 */
@property (nonatomic, strong, readonly) id target;
/**
 * Restricts the place results to this array of place ids.
 * Useful when only interested in a certain group of places (e.g. near by restaurants)
 *
 * @version 1.8
 */
@property (nonatomic, strong) NSArray<NSString*>* restrictToPlaceIDs;
/**
 * Restricts the place results to the target's layer.
 * By default, this is YES.
 *
 * @version 1.8
 */
@property (nonatomic) BOOL restrictToTargetLayer;
/**
 * Defines the distance (in meters) within which to return place results.
 * The distance between the target and place is computed using the routing
 * network.
 * By default, there is no restricted radius.
 *
 * @version 1.8
 */
@property (nonatomic) double radius;
/**
 * Instantiates a route request
 *
 * @param placeID The place id to use as the target
 *
 * @version 1.8
 */
-(instancetype)initWithPlaceID:(NSString*)placeID;
/**
 * Instantiates a route request
 *
 * @param position The position to use as the target
 *
 * @version 1.8
 */
-(instancetype)initWithPosition:(VMEPosition*)position;

-(BOOL) isEqualToPlaceFilter:(VMEPlaceFilter*) placeFilter;
@end
