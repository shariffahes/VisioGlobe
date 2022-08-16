/*
 * Copyright (c) Visioglobe SAS. All rights reserved.
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE.txt', which is part of this source code package.
 */

#import <VisioMoveEssential/VMERouteRequestType.h>
#import <VisioMoveEssential/VMERouteDestinationsOrder.h>
/**
 * @ingroup models
 * @brief Represents a route request to VMEMapView::computeRoute:callback:
 *
 * @version 1.0
 */
@interface VMERouteRequest : NSObject <NSCopying>

/**
 * Instantiates a route request.
 *
 * @note By default:
 *  - VMERouteRequest::requestType is set to VMERouteRequestTypeFastest
 *  - VMERouteRequest::destinationsOrder is set to VMERouteDestinationsOrderInOrder
 *  - VMERouteRequest::isAccessible is set to NO.
 *
 * @version 1.7
 */
-(instancetype) init;

/**
 * Instantiates a route request.
 *
 * @param requestType Determines the type of request
 * @param destinationsOrder Determines the visiting order of the destination objects
 *
 * @note By default:
 *  - VMERouteRequest::isAccessible is set to NO.
 *
 * @version 1.2
 */
-(instancetype) initWithRequestType:(VMERouteRequestType) requestType
                  destinationsOrder:(VMERouteDestinationsOrder) destinationsOrder;

/**
 * Instantiates a route request.
 *
 * @param requestType Determines the type of request
 * @param destinationsOrder Determines the visiting order of the destination objects
 * @param isAccessible Determines if route will be accessible.
 *
 * @version 1.2
 */
-(instancetype) initWithRequestType:(VMERouteRequestType) requestType
                  destinationsOrder:(VMERouteDestinationsOrder) destinationsOrder
                         accessible:(BOOL) isAccessible;

/**
 *
 * @returns The origin of the route.  The origin may be one of the following types:
 *  - VMEPosition - The physical position within the map
 *  - NSString - The id of a place within the map.
 *
 * @version 1.0
 */
-(id) getOrigin;
/**
 * Sets the origin of the route.
 *
 * @param origin The origin may be one of the following types:
 *  - VMEPosition - The physical position within the map
 *  - NSString - The id of a place within the map.
 *
 *
 * @version 1.2
 */
-(void) setOrigin:(id) origin;

/**
 * @returns An ordered array containing the following types:
 *  - VMEPosition - The physical position within the map
 *  - NSString - The id of a place within the map.
 *
 * @version 1.0
 */
-(NSArray*) getDestinations;

/**
 * Adds a destination to the end of the destinations array’s content.
 *
 * @param destination The destination may be one of the following types:
 *  - VMEPosition - The physical position within the map
 *  - NSString - The id of a place within the map
 *
 * @return YES if the destination was added successfully, otherwise NO.
 *
 * @version 1.0
 * @version 1.2 Now returns a BOOL and the destination parameter was made generic.
 */
-(BOOL) addDestination:(id) destination;

/**
 * Adds the objects contained in the given array to the end of the destinations
 * array’s content.
 *
 * @param destinations The destinations array may contain the following object
 * types:
 *  - VMEPosition - The physical position within the map
 *  - NSString - The id of a place within the map.
 *
 * @return YES if one or more of the destination entries where valid, otherwise NO.
 *
 * @version 1.0
 * @version 1.2 Change return type to BOOL
 */
-(BOOL) addDestinations:(NSArray*) destinations;

/**
 * Remove all destinations objects from the destination array.
 *
 * @version 1.2
 */
-(void) removeAllDestinations;

/**
 * Remove destination object at the given index
 *
 * @param index Index of destination to remove.
 *
 * @version 1.2
 */
-(void) removeDestinationAtIndex:(NSUInteger)index;

/**
 * Replace destination object at the given index with the given position
 *
 * @param index Index of destination to replace.
 * @param destination The object to add to the destination.  The destination may
 * be one of the following types:
 *  - VMEPosition - The physical position within the map
 *  - NSString - The id of a place within the map.
 *
 * @return YES if the replace occurred successfully, otherwise NO.
 *
 * @version 1.2
 */
-(BOOL) replaceDestinationAtIndex:(NSUInteger)index withDestination:(id)destination;

/**
 * Determines if this object is equal to another VMERouteRequest object.
 *
 * @param routeRequest The object to compare self to.
 * @returns YES if the objects are equal, otherwise NO.
 *
 * @version 1.2
 */
-(BOOL) isEqualToRouteRequest:(VMERouteRequest*) routeRequest;

/**
 * Requests that the computed route is accessible.
 * @see Refer the map's "App Configuration" within VisioMapEditor to determine
 * what routing attributes/modalities are filtered when enabled.
 *
 * @version 1.0
 */
@property (nonatomic) BOOL isAccessible;
/**
 * Determines the destination visiting order.
 *
 * @version 1.2
 */
@property (nonatomic) VMERouteDestinationsOrder destinationsOrder;
/**
 * Determines how the route should be optimized.
 *
 * @version 1.2
 */
@property (nonatomic) VMERouteRequestType requestType;

@end
