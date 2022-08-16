/*
 * Copyright (c) Visioglobe SAS. All rights reserved.
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE.txt', which is part of this source code package.
 */


@class VMEMapView;
@class VMEPosition;

/**
 * @ingroup listeners
 * @brief Interface definition of methods that are invoked when camera has moved
 *
 * @example
 * @code
 @interface SampleViewController : UIViewController <VMECameraListener>
 @end

 - (void)viewDidLoad {
    // ...
    [self.mapView setCameraListener:self];
    [self.mapView loadMap];
 }

 -(void) mapCameraDidMove:(VMEMapView*)mapView {
    // ...
    return void;
 }
 * @endcode
 *
 * @version 1.24
 */
@protocol VMECameraListener <NSObject>
/**
 * Notifies the listener that the camera has moved.
 * Called repeatedly as the camera continues to move.
 * This may be called as often as once every frame and should not perform expensive operations.
 *
 * @param mapView The originator of the notification
 *
 * @version 1.24
 */
@optional
-(void) mapCameraDidMove:(VMEMapView*)mapView;
@end
