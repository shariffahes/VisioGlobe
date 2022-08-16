/*
 * Copyright (c) Visioglobe SAS. All rights reserved.
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE.txt', which is part of this source code package.
 */
#import "VMERouteRequest.h"
#import "VMERouteResult.h"
@class VMEMapView;
/**
 * @ingroup callbacks
 * @brief Callback protocol for receiving compute route results.  For computing a route
 * see VMEMapView::computeRoute:callback:.
 *
 * @version 1.0
 */
@protocol VMEComputeRouteCallback <NSObject>
/**
 * Notified when compute route was successful
 * @param mapView The map view who received the compute route request
 * @param routeRequest The original route request object.
 * @param routeResult The results of the route request.
 * @return YES if the route should be added to the map, otherwise NO.
 *
 * @version 1.2
 */
@required
-(BOOL) computeRouteDidFinish:(VMEMapView*)mapView
                   parameters:(VMERouteRequest*)routeRequest
                       result:(VMERouteResult*)routeResult;

/**
 * Notified when compute route failed.
 * @param mapView The map view who received the compute route request
 * @param routeRequest The original route request object.
 * @param error A localized error string indicating the reason for the failure.
 *
 * @version 1.0
 */
@required
-(void) computeRouteDidFail:(VMEMapView*)mapView
                 parameters:(VMERouteRequest*)routeRequest
                      error:(NSString*) error;
@end
