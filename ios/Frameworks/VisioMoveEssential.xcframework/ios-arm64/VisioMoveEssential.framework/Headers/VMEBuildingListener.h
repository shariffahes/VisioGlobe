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
 * @brief Interface definition of methods that are invoked when building related event occurs within the map.
 *
 * @example
 * @code
 @interface SampleViewController : UIViewController <VMEBuildingListener>
 @end

 - (void)viewDidLoad {
    // ...
    [self.mapView setBuildingListener:self];
    [self.mapView loadMap];
 }

 -(BOOL) map:(VMEMapView*)mapView didSelectBuilding:(NSString*)buildingID withPosition:(VMEPosition*)position {
    // ...
    return YES;
 }
 * @endcode
 *
 * @version 1.17
 */
@protocol VMEBuildingListener <NSObject>
/**
 * Notifies the listener that a place has been selected.
 *
 * @param mapView The originator of the notification
 * @param buildingID The ID of the building selected
 * @param position The physical position where the select event took place 
 * within the map.
 * @return YES if the listener consumes the event, NO otherwise.
 *
 * @version 1.17
 */
@optional
-(BOOL) map:(VMEMapView*)mapView didSelectBuilding:(NSString*)buildingID withPosition:(VMEPosition*)position;
@end
