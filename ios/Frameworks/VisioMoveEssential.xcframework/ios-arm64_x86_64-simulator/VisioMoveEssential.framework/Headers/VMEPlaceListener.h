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
 * @brief Interface definition of methods that are invoked when place related events occur.
 *
 * @example
 * @code
 @interface SampleViewController : UIViewController <VMEPlaceListener>
 @end

 - (void)viewDidLoad {
    // ...
    [self.mapView setPlaceListener:self];
    [self.mapView loadMap];
 }

 -(BOOL) map:(VMEMapView*)mapView didSelectPlace:(NSString*)placeID withPosition:(VMEPosition*)position {
    // ...
    return YES;
 }
 * @endcode
 *
 * @version 1.12
 */
@protocol VMEPlaceListener <NSObject>
/**
 * Notifies the listener that a place has been selected.
 *
 * @param mapView The originator of the notification
 * @param placeID The ID of the place selected
 * @param position The physical position where the select event took place 
 * within the map.
 * @return YES if the listener consumes the event, NO otherwise.
 *
 * @note Applies to:
 * - static places
 * - dynaimic places
 *
 * @version 1.1
 */
@optional
-(BOOL) map:(VMEMapView*)mapView didSelectPlace:(NSString*)placeID withPosition:(VMEPosition*)position;
@end
