/*
 * Copyright (c) Visioglobe SAS. All rights reserved.
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE.txt', which is part of this source code package.
 */

@class VMEMapView;
@class VMEPlaceFilter;
@class VMERouteResult;
/**
 * @ingroup callbacks
 * @brief A callback  protocol to receive place filter query notifications.
 *
 * @version 1.8
 */
@protocol VMEPlaceFilterCallback <NSObject>
/**
 * This method be will called by the SDK once the place filter query has completed.
 *
 * @param mapView The map view who received the original request
 * @param filter The original place filter used for the query.
 * @param results An array of VMERouteResult objects sorted by distance in
 * ascending order.  The list may be empty if the filter matched with no results.
 *
 * @version 1.8
 */
-(void)placeFilterDidFinish:(VMEMapView*)mapView
                 parameters:(VMEPlaceFilter*)filter
                    results:(NSArray<VMERouteResult*>*)results;
@end
