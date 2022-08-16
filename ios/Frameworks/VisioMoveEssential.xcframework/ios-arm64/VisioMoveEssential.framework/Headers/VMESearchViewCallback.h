/*
 * Copyright (c) Visioglobe SAS. All rights reserved.
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE.txt', which is part of this source code package.
 */

@class VMEMapView;
/**
 * @ingroup callbacks
 * @brief Callback protocol for receiving search view results.
 *
 * @see VMEMapView::showSearchViewWithTitle: for displaying the search view.
 *
 * @version 1.0
 */
@protocol VMESearchViewCallback <NSObject>

/**
 * Notified when a place was selected from the search view
 * @param mapView The map view who received the original request
 * @param placeID The id of the place selected.
 *
 * @version 1.0
 */
-(void) searchView:(VMEMapView*)mapView didSelectPlaceID:(NSString*)placeID;

/**
 * Notified when the search view was cancelled
 * @param mapView The map view who received the original request.
 *
 * @version 1.0
 */
-(void) searchViewDidCancel:(VMEMapView*)mapView;

@end
