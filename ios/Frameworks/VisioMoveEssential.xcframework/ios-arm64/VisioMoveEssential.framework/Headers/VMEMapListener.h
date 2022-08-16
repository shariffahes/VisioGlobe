/*
 * Copyright (c) Visioglobe SAS. All rights reserved.
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE.txt', which is part of this source code package.
 */

@class VMEMapView;
@class VMESceneContext;

/**
 * @ingroup listeners
 * @brief Map listener to be notified of map related events occuring
 * on the VMEMapView object.
 *
 * @example
 * @code
 - (void)viewDidLoad {
   [super viewDidLoad];
   [self.mapView setMapListener:(VMEMapListener*)self];
   [self.mapView loadMap];
 }

 -(void) map:(VMEMapView *)mapView sceneDidUpdate:(VMESceneContext *)scene withMode:(VMEViewMode)viewMode {
     NSString* lMsg = [NSString stringWithFormat:@"Mode: %ld Scene: %@", (long)viewMode, scene.description];
     NSLog(@"%@", lMsg);
 }

 -(void) map:(VMEMapView*)mapView didReceiveTapGesture:(VMEPosition*)position {
     if (position == nil) {
         NSString* lMsg = [NSString stringWithFormat:@"mapTapGesture outside of map: "];
         NSLog(@"%@", lMsg);
     } else {
         NSString* lMsg = [NSString stringWithFormat:@"mapTapGesture: Position: %@", position];
         NSLog(@"%@", lMsg);
     }
 }
 * @endcode
 *
 * @version 1.0
 */
@protocol VMEMapListener <NSObject>

/**
 * Notifies the listener that the map's scene or view mode has changed.
 *
 * @param mapView The originator of the notification
 * @param scene The maps's scene
 * @param viewMode The map's view mode
 *
 * @version 1.9
 */
@optional
-(void) map:(VMEMapView*)mapView sceneDidUpdate:(VMESceneContext*)scene withMode:(VMEViewMode)viewMode;

/**
 * Notifies the listener that a tap gesture has occurred on map view.
 * @param mapView The originator of the notification
 * @param position The position returned by the click in lat/lon coordinate - will be nil if you click outside of map
 *
 * @version 1.18
 */
-(void) map:(VMEMapView*)mapView didReceiveTapGesture:(VMEPosition*) position;
@end
