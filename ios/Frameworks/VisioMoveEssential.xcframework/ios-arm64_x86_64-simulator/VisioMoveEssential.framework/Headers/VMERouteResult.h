/*
 * Copyright (c) Visioglobe SAS. All rights reserved.
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE.txt', which is part of this source code package.
 */

#import "VMESegment.h"

/**
 * @ingroup models
 * @brief Contains information related to a computed route.
 *
 * @version 1.2
 */
@interface VMERouteResult : NSObject <NSCopying>
/**
 * Instantiates a route result object.
 *
 * @param destinations An array of destinations in the order that they will be visited.
 * @param duration The duration (seconds) of the route.
 * @param length The length (metres) of the route.
 *
 * @version 1.2
 */
-(instancetype) initWithDestinations:(NSArray*) destinations
                            duration:(double) duration
                              length:(double) length;

/**
 * Instantiates a route result object.
 *
 * @param destinations An array of destinations in the order that they will be visited.
 * @param duration The duration (seconds) of the route.
 * @param length The length (metres) of the route.
 * @param segments The array of segment objects that make up the route.
 *
 * @version 1.17
 */
-(instancetype) initWithDestinations:(NSArray*) destinations
                            duration:(double) duration
                              length:(double) length
                            segments:(NSArray<VMESegment*>*)segments;

/**
 * Determines if this object is equal to another VMERouteResult object.
 *
 * @param routeResult The object to compare self to.
 * @returns YES if the objects are equal, otherwise NO.
 *
 * @version 1.2
 */
-(BOOL) isEqualToRouteResult:(VMERouteResult*) routeResult;

/**
 * The duration (seconds) of the route
 *
 * @version 1.2
 */
@property (readonly) double duration;
/**
 * The length (metres) of the route
 *
 * @version 1.2
 */
@property (readonly) double length;
/**
 * An array of destinations in the order that they will be visited.  If there
 * was an invalid origin or destination in the request, it will be removed from
 * this array.
 *
 * @version 1.2
 */
@property (readonly) NSArray* destinations;

/**
 * An array of segments that make up the route.
 *
 * @version 1.17
 */
@property (readonly) NSArray<VMESegment*>* segments;
@end
