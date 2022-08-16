/*
 * Copyright (c) Visioglobe SAS. All rights reserved.
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE.txt', which is part of this source code package.
 */
#import "VMEMacros.h"
@class VMEMapView;
@class VMERouteResult;
/**
 * @ingroup listeners
 * @brief Interface definition of methods that are invoked when life cycle events occur
 *
 * @example
 * @code
 @interface SampleViewController : UIViewController <VMELifeCycleListener>
 @end
 - (void)viewDidLoad {
    // ...
    [self.mapView setLifeCycleListener:self];
    [self.mapView loadMap];
 }

 -(void)mapDidLoad:(VMEMapView*)mapView {
    // ...
 }
 * @endcode
 *
 * @version 1.12
 */
@protocol VMELifeCycleListener <NSObject>

/**
 * Invoked when the map view is ready to receive place updates
 *
 * @param mapView The originator of the notification
 *
 * @see VMEMapView::updatePlaceData: for more info on updating place data
 *
 * @version 1.12
 * @deprecated Deprecated in 1.13.  Replaced with VMELifeCycleListener::mapDidInitializeEngine:.
 */
@optional
-(void) mapReadyForPlaceUpdate:(VMEMapView*)mapView VME_DEPRECATED_MSG("Please use mapDidInitializeEngine:");


/**
 * Invoked when the 3D rendering engine has been initialized
 *
 * @param mapView The originator of the notification
 *
 * @version 1.13
 */
@optional
-(void) mapDidInitializeEngine:(VMEMapView*)mapView;

/**
 * Invoked when the map bundle has been loaded and is ready to gain focus
 *
 * @param mapView The originator of the notification
 *
 * @version 1.12
 */
@optional
-(void) mapDidLoad:(VMEMapView*)mapView;

/**
 * Invoked when the map has returned to normal focus.
 * Normal focus indicates that:
 *  - the map surfaces have been loaded and
 *  - no other views appear above the map.
 *
 * @param mapView The originator of the notification
 *
 * @version 1.12
 */
@optional
-(void) mapDidGainFocus:(VMEMapView*)mapView;

/**
 * Invoked when a route is displayed within the map
 *
 * @param mapView The originator of the notification
 * @param result The result object containing information related to the displayed route
 *
 * @version 1.12
 */
@optional
-(void) map:(VMEMapView*)mapView didDisplayRoute:(VMERouteResult*)result;

/**
 * Invoked when the place info is displayed above the map
 *
 * @param mapView The originator of the notification
 * @param placeID The place ID of the place info being displayed
 *
 * @version 1.12
 */
@optional
-(void) map:(VMEMapView*)mapView didDisplayPlaceInfo:(NSString*)placeID;

/**
 * Invoked when the search view is displayed above the map
 *
 * @param mapView The originator of the notification
 *
 * @version 1.12
 */
@optional
-(void) mapDidDisplaySearch:(VMEMapView*)mapView;

/**
 * Invoked when the route setup view is displayed above the map
 *
 * @param mapView The originator of the notification
 *
 * @version 1.12
 */
@optional
-(void) mapDidDisplayRouteSetup:(VMEMapView*)mapView;
@end
