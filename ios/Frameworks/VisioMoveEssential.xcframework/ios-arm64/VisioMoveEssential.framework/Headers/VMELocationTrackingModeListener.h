/*
 * Copyright (c) Visioglobe SAS. All rights reserved.
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE.txt', which is part of this source code package.
 */
#import "VMEMacros.h"
@class VMEMapView;


#pragma mark - VMELocationTrackingModeListener
/**
 * @ingroup listeners
 * @brief Interface definition of methods that are invoked when location tracking mode related events occur.
 *
 * @example
 * @code
 interface SampleViewController : UIViewController <VMELocationTrackingModeListener>
 end
 - (void)viewDidLoad {
    // ...
    [self.mapView setLocationTrackingModeListener:self];
    [self.mapView loadMap];
 }

-(void) map:(VMEMapView*)mapView didUpdateLocationTrackingMode(VMELocationTrackingMode)locationTrackingMode {
    // ...
 }
 * @endcode
 * @version 1.19
 */
@protocol VMELocationTrackingModeListener <NSObject>

/**
* Notifies the listener that the tracking mode has been updated.
*
* @param mapView The originator of the notification
* @param locationTrackingMode The new tracking mode
*
* @version 1.19
*/
@optional
-(void) map:(VMEMapView*)mapView didUpdateLocationTrackingMode:(VMELocationTrackingMode)locationTrackingMode;

@end
