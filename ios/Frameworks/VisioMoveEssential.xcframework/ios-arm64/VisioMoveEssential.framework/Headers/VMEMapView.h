/*
 * Copyright (c) Visioglobe SAS. All rights reserved.
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE.txt', which is part of this source code package.
 */

#import <VisioMoveEssential/VMEAnimationCallback.h>
#import <VisioMoveEssential/VMEAnchorMode.h>
#import <VisioMoveEssential/VMEBuildingListener.h>
#import <VisioMoveEssential/VMEComputeRouteCallback.h>
#import <VisioMoveEssential/VMECameraUpdate.h>
#import <VisioMoveEssential/VMELifeCycleListener.h>
#import <VisioMoveEssential/VMELocationTrackingMode.h>
#import <VisioMoveEssential/VMEMapListener.h>
#import <VisioMoveEssential/VMEPlaceAltitudeMode.h>
#import <VisioMoveEssential/VMEPlaceAnchorMode.h>
#import <VisioMoveEssential/VMEPlaceDisplayMode.h>
#import <VisioMoveEssential/VMEPlaceListener.h>
#import <VisioMoveEssential/VMELocation.h>
#import <VisioMoveEssential/VMESearchViewCallback.h>
#import <VisioMoveEssential/VMEPlaceAnchorMode.h>
#import <VisioMoveEssential/VMEPlaceAltitudeMode.h>
#import <VisioMoveEssential/VMEPlaceDisplayMode.h>
#import <VisioMoveEssential/VMEPlaceOrientation.h>
#import <VisioMoveEssential/VMEPlaceVisibilityRamp.h>
#import <VisioMoveEssential/VMEPlaceFilter.h>
#import <VisioMoveEssential/VMEPlaceFilterCallback.h>
#import <VisioMoveEssential/VMEPlaceSize.h>
#import <VisioMoveEssential/VMECategory.h>
#import <VisioMoveEssential/VMEPlace.h>
#import <VisioMoveEssential/VMESceneUpdate.h>
#import <VisioMoveEssential/VMELocationTrackingModeListener.h>
#import <VisioMoveEssential/VMEMapDescriptor.h>
#import <VisioMoveEssential/VMECameraContext.h>
#import <VisioMoveEssential/VMECameraListener.h>
#import <VisioMoveEssential/VMECameraMoveReason.h>

#import <CoreLocation/CoreLocation.h>
/**
 * @defgroup mapView VMEMapView
 * @brief This is the main class of VisioMove Essential for iOS and is the entry point
 * for all methods related to the map.
 *
 * The map view can be created either with the initWithFrame: method or within
 * a nib.
 *
 * VMEMapView can only be read and modified from the main thread, similar
 * to all UIKit objects. Calling these methods from another thread will result in
 * an exception or undefined behavior.
 *
 * @version 1.0
 */

/**
 * @version 1.0
 */
IB_DESIGNABLE @interface VMEMapView: UIView <NSCoding>


#pragma mark - Constructors
/**
 * @defgroup constructors Create Map View
 * @brief Methods to create a map view.
 * @ingroup mapView
 * @{
 */

/**
 * Use this constructor to create the VMEMapView programatically
 *
 * @version 1.0
 */
-(instancetype _Nonnull) initWithFrame:(CGRect)frame;

/**
 * @version 1.0
 */
- (instancetype _Nullable) initWithCoder:(NSCoder* _Nonnull)coder;

/**
 * @}
 */


#pragma mark - VMEBundleInterface
/**
 * @defgroup bundleInterface Configure Map Bundle
 * Define the map bundle to be displayed within the map view.
 * @ingroup mapView
 * @{
 */

/**
 * The directory path, relative to the main bundle, where the embedded map bundle will be loaded from.
 *
 * @version 1.0
 */
@property (nonatomic) IBInspectable NSString * _Nonnull mapPath;

/**
 * The embedded map's secret code.
 *
 * @note The secret code is used to salt the map's license.  Before authorizing
 * the loading of the map, the secret code is validated with the map's license.
 *
 * @version 1.0
 * @version 1.9 Parameter type changed from NSString* to int
 */
@property (nonatomic) IBInspectable int mapSecretCode;
/**
 * The target hash of the online map.
 *
 * The hash is used for retrieving the map from a map server.
 *
 * @version 1.0
 */
@property (nonatomic) IBInspectable NSString * _Nonnull mapHash;

/**
 * The map server url.
 *
 * If nil, the default map server path will be used.
 * By default the map server URL is "https://mapserver.visioglobe.com"
 *
 * @version 1.0
 */
@property (nonatomic) IBInspectable NSString * _Nonnull mapServerURL;
/**
 * Determines whether to prompt the user before downloading an online map.
 *
 * If YES, the user will be prompted.  Otherwise the online map will be
 * downloaded automatically.
 *
 * By default this is set to YES (i.e. the user will be prompted).
 *
 * @version 1.9
 */
@property (nonatomic) BOOL promptUserToDownloadMap;

/**
 * Get cached Map descriptor
 *
 * @param identifier The map hash who's map descriptor is to be retrieved.
 * @returns The map bundle descriptor that has been downloaded by the SDK. Will return
 * nil if the map hash doesn't have a corresponding downloaded map within the phone.
 *
 * @note This method will not return the map descriptor of the application's embedded map.
 *
 * @version 1.21
 * @example
 * @code
 VMEMapDescriptor* mapCachedFromOnline = [self.mapView getCachedMapDescriptorWithIdentifier:@"mc8f3fec89d2b7283d15cfcf4eb28a0517428f054"];
 * @endcode
 */
-(VMEMapDescriptor* _Nullable) getCachedMapDescriptorWithIdentifier:(NSString* _Nonnull)identifier;

/**
 * Deletes a map from the application that has been cached by the SDK.
 *
 * @param identifier The map hash associated with the cached map that is to be deleted.
 * @param error Any information about an error condition that may have occured.
 * @returns Returns YES if the map was successfully deleted, otherwise NO.
 *
 * @version 1.21
 * @example
 * @code
 NSError* lError;
 if(![self.mapView deleteCachedMapWithIdentifier:@"mc8f3fec89d2b7283d15cfcf4eb28a0517428f054" error:&lError]) {
     NSLog(@"Error: %@", lError.description);
 }
 * @endcode
 *
 */
- (BOOL)deleteCachedMapWithIdentifier:(NSString *_Nullable)identifier error:(NSError *_Nullable*_Nullable)error;
/**
 * @}
 */

#pragma mark - Listeners
/**
 * @defgroup listenersGroup Listeners
 * @brief Set listeners before loading map in order to receive events.
 * The delegate should implement the methods of the appropriate listener protocol.
 *
 * @ingroup mapView
 * @{
 */

/**
 * The delegate to receive map related notifications.
 * To unset the listener, use nil.
 *
 * @version 1.0
 */
@property (nonatomic, weak) IBOutlet id<VMEMapListener> _Nullable mapListener;
/**
 * The delegate to receive life cycle related notifications.
 * To unset the listener, use nil.
 *
 * @version 1.12
 */
@property (nonatomic, weak) IBOutlet id<VMELifeCycleListener> _Nullable lifeCycleListener;
/**
 * The delegate to receive place related notifications.
 * To unset the listener, use nil.
 *
 * @version 1.12
 */
@property (nonatomic, weak) IBOutlet id<VMEPlaceListener> _Nullable placeListener;

/**
 * The delegate to receive building related notifications.
 * To unset the listener, use nil.
 *
 * @version 1.17
 */
@property (nonatomic, weak) IBOutlet id<VMEBuildingListener> _Nullable buildingListener;

/**
 * The delegate to receive camera related notifications.
 * To unset the listener, use nil.
 *
 * @version 1.17
 */
@property (nonatomic, weak) IBOutlet id<VMECameraListener> _Nullable cameraListener;

/**
 * The delegate to receive location tracking mode related notifications.
 * To unset the listener, use nil.
 *
 * @version 1.19
 */
@property (nonatomic, weak) IBOutlet id<VMELocationTrackingModeListener> _Nullable locationTrackingModeListener;

/**
 * @}
 */

#pragma mark - Load and unload

/**
 * @defgroup loadunload Display Map
 * Load / unload map content or set focus on map.
 *
 * @ingroup mapView
 * @{
 */

/**
 * Loads the map using the current map configuration.  If the map is already loaded,
 * this will reload the map.
 * This method must be called at least once in order for the map to be loaded.
 *
 * @note If the map is already loaded, then VMEMapView::unloadMap should be called before calling
 * this method again.
 *
 * @version 1.0
 */
-(void) loadMap;

/**
 * Unloads the current map.
 *
 * Unloading the map will undo any API calls made since the creation of the map.
 * @note Only call once the previous map has finished loading.
 *
 * @version 1.9
 */
-(void) unloadMap;

/**
 * Set focus on map - map state
 *
 * @note calling setFocusOnMap() close other view components such as the navigation, the search view or the place info view... The map is clean from other views.
 *
 * @example
 * @code
 - (IBAction)discardNavigationAction:(id)sender
 {
     [self.mapView setFocusOnMap];
 }
 * @endcode
 * @version 1.19
 */
-(void) setFocusOnMap;
/**
 * @}
 */

#pragma mark - VMEMapInterface
/**
 * @defgroup mapInterface1 Camera
 * Update the camera to focus on specific targets
 * @ingroup mapView
 * @{
 */

/**
 * Repositions the camera according to the instructions defined in the update.
 * The update is instantaneous.
 *
 * @see VMECameraUpdate for the available update constructors.
 *
 * @param update The update to apply.
 *
 * @example
 * @code
 VMECameraUpdate* lUpdate = [VMECameraUpdate cameraUpdateWithBuilderBlock:^(VMECameraUpdateBuilder *builder) {
    builder.targets = [NSArray arrayWithObject:@"B2-UL00"];
    builder.heading = [VMECameraHeading cameraHeadingCurrent];
    builder.viewMode = VMEViewModeFloor;
    builder.distanceRange = [VMECameraDistanceRange cameraDistanceRangeMinRadius:40 andMaxRadius:200];
    builder.pitch = [VMECameraPitch cameraPitchWithPitch:-30] ;
 }];
 [self.mapView updateCamera:lUpdate];
 * @endcode
 * @version 1.2
 */
-(void) updateCamera:(VMECameraUpdate* _Nonnull)update;

/**
 * Animates the movement of the camera from the current position to the position
 * defined in the update.
 *
 * @see VMECameraUpdate for the available update constructors.
 *
 * @param update The update to apply.
 *
 * @example
 * @code
 VMECameraUpdate* lUpdate = [VMECameraUpdate cameraUpdateWithBuilderBlock:^(VMECameraUpdateBuilder *builder) {
    builder.targets = [NSArray arrayWithObject:@"B2-UL00"];
    builder.heading = [VMECameraHeading cameraHeadingForPlaceID:@"B2"];
    builder.viewMode = VMEViewModeFloor;
    builder.distanceRange = [VMECameraDistanceRange cameraDistanceRangeMinRadius:40 andMaxRadius:200];
    builder.pitch = [VMECameraPitch cameraPitchWithPitch:-30] ;
 }];
 [self.mapView animateCamera:lUpdate];
 * @endcode
 * @version 1.2
 */
-(void) animateCamera:(VMECameraUpdate* _Nonnull)update;

/**
 * Animates the movement of the camera from the current position to the position
 * defined in the update.
 *
 * @see VMECameraUpdate for the available update constructors.
 *
 * @param update The update to apply.
 * @param duration The duration (in seconds) of the camera animation.
 * @param callback The callback to be notified of any animation events.  Can pass
 * nil if indifferent to animation events.
 *
 * @example
 * @code
 VMECameraUpdate* lUpdate = [VMECameraUpdate cameraUpdateWithBuilderBlock:^(VMECameraUpdateBuilder *builder) {
    builder.targets = [NSArray arrayWithObject:@"B2-UL00"];
    builder.heading = [VMECameraHeading cameraHeadingForPlaceID:@"B2"];
    builder.distanceRange = [VMECameraDistanceRange cameraDistanceRangeMinRadius:40 andMaxRadius:200];
    builder.pitch = [VMECameraPitch cameraPitchWithPitch:-30] ;
    builder.viewMode = VMEViewModeFloor;
 }];
 [self.mapView animateCamera:lUpdate duration:1.5 listener:self];
 * @endcode
 * @version 1.7
 */
-(void) animateCamera:(VMECameraUpdate* _Nonnull)update duration:(float)duration callback:(id<VMEAnimationCallback> _Nullable)callback;

/**
 * Gets the current context of the camera.
 * The VMECameraContext returned is a snapshot of the current context, and will not automatically
 * update when the camera moves.
 *
 * @return The current camera context
 *
 * @version 1.24
 */
-(VMECameraContext* _Nonnull) getCameraContext;


/**
 * Gets the last move reason of the camera.
 *
 * @return The last camera move reason
 *
 * @version 1.25
 */
-(VMECameraMoveReason) getCameraMoveReason;

/**
 * @}
 */

/**
 * @defgroup mapInterface2 Scene
 * Update the scene to control what is visible within the map.
 * @ingroup mapView
 * @{
 */

/**
 * Updates the change of scene from the current scene to the scene
 * defined in the update.  The update is instantaneous.
 *
 * @see VMESceneUpdate for the available update constructors.
 *
 * @param update The update to apply.
 *
 * @example
 * @code
 VMESceneUpdate* lUpdate = [VMESceneUpdate sceneUpdateForViewMode:VMEViewModeFloor
                                                          floorID:@"B2-UL00"];
 [self.mapView updateScene:lUpdate];
 * @endcode
 * @version 1.2
 */
-(void) updateScene:(VMESceneUpdate* _Nonnull)update;

/**
 * Animates the change of scene from the current scene to the scene
 * defined in the update.
 *
 * @see VMESceneUpdate for the available update constructors.
 *
 * @param update The update to apply.
 *
 *
 * @example
 * @code
 VMESceneUpdate* lUpdate = [VMESceneUpdate sceneUpdateForViewMode:VMEViewModeFloor
                                                          floorID:@"B2-UL00"];
 [self.mapView animateScene:lUpdate];
 * @endcode
 * @version 1.2
 */
-(void) animateScene:(VMESceneUpdate* _Nonnull)update;

/**
 * @}
 */

#pragma mark - VMEComputeRouteInterface
/**
 * @defgroup computeRouteInterface Navigation
 * Compute routes and display them within the map.
 * @ingroup mapView
 * @{
 */

/**
 * Requests that a route be computed.
 * @param routeRequest The route request
 * @param callback The callback to invoke with the result.
 *
 * @example
 * @code
 VMERouteRequest* lRouteRequest = [[VMERouteRequest alloc] initWithRequestType:VMERouteRequestTypeFastest
                                                             destinationsOrder:VMERouteDestinationsOrderOptimal];
 [lRouteRequest setOriginWithPlaceID:@"B1-UL00-ID0039"];
 [lRouteRequest addDestinations:@[@"B4-UL04-ID0005", @"B3-LL01-ID0004"]];

 [self.mMapView computeRoute:lRouteRequest callback:self];
 * @endcode
 *
 * @version 1.0
 * @version 1.2 The callback parameter is now required by this method in order
 * to handle the result.
 */
-(void) computeRoute:(VMERouteRequest* _Nonnull)routeRequest callback:(id<VMEComputeRouteCallback> _Nonnull)callback;

/**
 * @returns An array of all modality names that are present
 * within the map’s routing network.
 *
 * @example
 * @code
 NSArray<NSString*>* lModalities = [self.mMapView getModalities];
 * @endcode
 *
 * @version 1.6
 */
-(NSArray<NSString*>* _Nonnull) getModalities;

/**
 * @returns An array of all attribute names that are present
 * within the map’s routing network.
 *
 * @example
 * @code
 NSArray<NSString*>* lAttributes = [self.mMapView getAttributes];
 * @endcode
 *
 * @version 1.6
 */
-(NSArray<NSString*>* _Nonnull) getAttributes;

/**
 * Sets the modalities that will be excluded from the routing
 * network when a route is computed.
 *
 * @param modalities An array of modality names to be
 * excluded.  If nil or empty, then any previously excluded
 * modalities will be removed.
 *
 * @note The set excluded modalities will be used in addition
 * to the accessible excluded modalities if the user chooses an
 * accessible route.
 *
 * @example
 * @code
 NSArray<NSString*> *lModalities = [[NSArray alloc] initWithObjects:@"UserProfile1", @"UserProfile2", nil];
 [self.mMapView setExcludedModalities:lModalities];
 * @endcode
 *
 * @version 1.6
 */
-(void) setExcludedModalities:(NSArray<NSString*>* _Nonnull)modalities;

/**
 * Sets the attributes that will be excluded from the routing
 * network when a route is computed.
 *
 * @param attributes An array of attribute names to be
 * excluded.  If nil or empty, then any previously excluded
 * attributes will be removed.
 *
 * @note The set excluded attributes will be used in addition
 * to the accessible excluded attributes if the user chooses an
 * accessible route.
 *
 * @example
 * @code
 NSArray<NSString*> *lAttributes = [[NSArray alloc] initWithObjects:@"UserProfile1", @"UserProfile2", nil];
 [self.mMapView setExcludedAttributes:lAttributes];
 * @endcode
 *
 * @version 1.6
 */
-(void) setExcludedAttributes:(NSArray<NSString*>* _Nonnull)attributes;

/**
 * @}
 */

#pragma mark - VMELocationInterface
/**
 * @defgroup locationInterface User's Location
 * Inject the user's location into the map and set it's tracking mode.
 * @ingroup mapView
 * @{
 */

/**
 * Updates the uses current physical location within the map.
 *
 * @param update The location update to apply.  If nil is passed, then the current
 * location will be removed from the map.
 *
 * @note Calls to this method before VMELifeCycleListener::mapDidLoad: is called
 * will be ignored.
 *
 * @note This method filters unnecessary location updates.  A location update is filtered if:
 * - it's received less than a second since the previous update
 * - it's the same as the previous update
 * - it falls outside of the map's limits
 *
 * @example
 * @code
 #pragma mark - CLLocationManagerDelegate
 - (void)locationManager:(CLLocationManager *)manager didUpdateLocations:(NSArray *)locations
 {
     CLLocation* lCLLocation = locations.lastObject;
     VMELocation* lVMELocation = [self.mapView createLocationFromLocation:lCLLocation];
     [self.mapView updateLocation:lVMELocation];
 }
 * @endcode
 * @version 1.0
 * @version 1.2 Change update parameter from CLLocation to VMELocation.
 */
-(void) updateLocation:(VMELocation* _Nullable)update;


/**
 * Takes a native location object and converts it to a VisioMove Essential object
 * Uses the geo-fences within the map bundle to determine if the location falls
 * within a building and if so, what floor.
 *
 * @note The CLLocation's floor property is currently ignored.  Please use the
 * altitude property to determine the physical floor.
 *
 * @note By setting the CLLocation's verticalAccuracy to -1, the VMELocation
 * will be forced to the outside (independent of whether it falls within a
 * building's geo-fence).
 *
 * @note This method will return nil if called prior to VMELifeCycleListener::mapDidLoad:.
 *
 * @param location A location object.  The 'altitude' attribute will be used to
 * determine the correct floor.
 *
 * @return A VMELocation indicating the location within the venue, or nil if the
 * location is invalid or does exist not within the venue.
 *
 * @version 1.2
 */
-(VMELocation* _Nullable) createLocationFromLocation:(CLLocation* _Nonnull) location;

/**
 * Takes a native location object and converts it to a VisioMove Essential object
 * Uses the geo-fences within the map bundle to determine if the location falls
 * within a builing and if so, what floor.
 *
 * @note By setting the CLLocation's verticalAccuracy to -1, the VMEPosition
 * will be forced to the outside (independent of whether it falls within a
 * building's geo-fence).
 *
 * @note This method will return nil if called prior to VMELifeCycleListener::mapDidLoad:.
 *
 * @param location A location object.  The 'altitude' attribute will be used to
 * determine the correct floor.
 *
 * @return A VMEPosition indicating the location within the venue, or nil if the
 * location is invalid or does not exist within the venue.
 *
 * @version 1.2
 */
-(VMEPosition* _Nullable) createPositionFromLocation:(CLLocation* _Nonnull) location;

#pragma mark - VMELocationTrackingModeInterface

/**
 * Change the value of the location tracking mode
 *
 * @param trackingMode A tracking mode that will be applied immediately
 * @note This method will do nothing if there is no location provided to the mapView
 * @version 1.19
 * @see VMELocationTrackingMode
 */
-(void) setLocationTrackingMode:(VMELocationTrackingMode)trackingMode;

/**
 * Set the all the location tracking modes handled by the VME location tracker button
 *
 * @see VMELocationTrackingMode for the available tracking modes.
 *
 * @param trackingModes The list of the tracking modes that will be handled by the location tracker button
 *
 * @note This method allows to switch between tracking modes with the VME location tracker button. 2 modes at least are needed in the list, with no duplicate.
 *
 * @note Default values are <::VMELocationTrackingModeNone,::VMELocationTrackingModeFollow>
 *
 * @example
 * @code
 NSArray <VMELocationTrackingModeObject*>* trackingModes = @[
     [[VMELocationTrackingModeObject alloc] initWithEnum:VMELocationTrackingModeNone],
     [[VMELocationTrackingModeObject alloc] initWithEnum:VMELocationTrackingModeCustom],
     [[VMELocationTrackingModeObject alloc] initWithEnum:VMELocationTrackingModeFollow]
 ];
 [mapView setLocationTrackingButtonToggleModes:trackingModes];
 * @endcode
 * @version 1.19
 */
-(void) setLocationTrackingButtonToggleModes:(NSArray<VMELocationTrackingModeObject*> * _Nonnull) trackingModes;

/**
 * Get the current location tracking mode
 *
 * @see VMELocationTrackingMode
 *
 * @return The current tracking mode, default is ::VMELocationTrackingModeNone
 *
 * @version 1.19
 */
-(VMELocationTrackingMode) getLocationTrackingMode;

/**
 * Get the current location tracking modes handled by the VME location tracker button
 *
 * @see ::VMELocationTrackingMode
 *
 * @return The current location tracking modes handled by the VME location tracker button,
 * default values are <::VMELocationTrackingModeNone, ::VMELocationTrackingModeFollow>
 *
 * @version 1.19
 */
-(NSArray<VMELocationTrackingModeObject*>* _Nonnull) getLocationTrackingButtonToggleModes;

/**
 * @}
 */

#pragma mark - VMEViewControlInterface
/**
 * @defgroup viewControlnterface View Customization
 * Customize the appearance of the map view.
 * @ingroup mapView
 * @{
 */

/**
 * Control whether the selector view is visible.  If the selector view is not visible, it will
 * be the integrator's responsibility to provide a floor change mechanism.
 *
 * @param visible If YES, then the selector view will be visible.  Otherwise, the selector
 * view will be hidden.
 * @version 1.9
 */
-(void) setSelectorViewVisible:(BOOL)visible;

/**
 * @return A BOOL indicating whether the selector view is visible or not.
 * @see For more info VMEMapView::setSelectorViewVisible:
 * @version 1.9
 */
-(BOOL) getSelectorViewVisible;

/**
 * Control whether the navigation header view is visible.  If the navigation header view is not visible, it will
 * be the integrator's responsibility to provide a mechanism for the end user to close the
 * navigation in progress.
 *
 * @note to close the navigation in progress without the navigation header, use the method mapView.setFocusOnMap()
 * @see VMEMapInterface::setFocusOnMap();
 * @param visible If true, then the navigation header view will be visible when a navigation is in
 *                 progress.  Otherwise, the navigation header iew will be hidden.
 * @version 1.19
 */
-(void) setNavigationHeaderViewVisible:(BOOL) visible;

/**
 * @return A boolean indicating whether the navigation view will be visible when a
 * a navigation is in progress.
 *
 * @version 1.19
 */
-(BOOL) getNavigationHeaderViewVisible;

/**
 * Overrides the map's default font (currently DejaVuSans.ttf).
 *
 * @note Should be called within the VMELifeCycleListener::mapDidInitializeEngine: notification.
 *
 * @param filePath The TrueType Font file (*.ttf) to load. The font will be searched locally in the map bundle's "config" directory otherwise use an absolute path.
 * @returns YES if the font file was set successfully, otherwise NO.
 *
 * @version 1.13
 * @example
 * @code
#pragma - VMELifeCycleListener
-(void) mapDidInitializeEngine:(VMEMapView *)mapView {
    NSString* lFontFile = [[NSBundle mainBundle] pathForResource:@"font.name.here" ofType:@"ttf"];
    [self.mapView setMapFont:lFontFile];
}
 * @endcode
 */
-(BOOL) setMapFont:(NSString* _Nonnull)filePath;

/**
 * @}
 */

#pragma mark - VMELocationOverlayInterface
/**
 * @defgroup locationOverlaylnterface Location Overlay
 * Customize the appearance of the user's location overlay.
 * @ingroup mapView
 * @{
 */

/**
 * Control the visibility of the compass heading marker.
 * The compass heading marker is associated with the location overlay and indicates the orientation of the device.
 * @param visible If YES, then the compass heading marker is visible.  Otherwise, it will be hidden.
 * @version 1.23
 */
-(void) setCompassHeadingMarkerVisible:(BOOL)visible;

/**
 * Retrieve the visibility of the compass heading marker.
 * @return A BOOL indicating whether the compass heading is visible or not.
 * @see For more info VMEMapView::setCompassHeadingMarkerVisible:
 * @version 1.23
 */
-(BOOL) getCompassHeadingMarkerVisible;

/**
 * @}
 */

#pragma mark - VMESearchViewInterface
/**
 * @defgroup searchViewInterface Search
 * Display the search view containing a list of places within the map.
 * @ingroup mapView
 * @{
 */

/**
 * Request to show the search view.
 * @param title The title to display within the seach view.
 * @param callback The callback to invoke with the result.  Pass nil if you do
 * not need to be informed of the result.
 *
 *
 * @example
 * @code
[self.mapView showSearchViewWithTitle:@"My Title" callback:nil];
 * @endcode
 * @version 1.0
 */
-(void) showSearchViewWithTitle:(NSString* _Nonnull) title callback:(id<VMESearchViewCallback> _Nonnull) callback;

/**
 * @}
 */

/**
 * @defgroup placeInfoInteface Places
 * Annotate, create, update, and query places within the map.
 * @ingroup mapView
 * @{
 */

#pragma mark - VMEPlaceInfoInterface
/**
 * Displays info related to the place:
 *  - Focus the camera on the place
 *  - Open the place info view.
 *
 * @param placeID The place whos information will be displayed.
 *
 * @version 1.19
 *
 * @example
 * @code
 [self.mMapView showPlaceInfo:@"B1-UL00-ID0039"];
 * @endcode
 */
-(void) showPlaceInfo:(NSString* _Nonnull)placeID;

#pragma mark - VMEPlacelInterface
/**
 * Update the place data content within the map.
 *
 * @note Should be called within the VMELifeCycleListener::mapDidInitializeEngine: notification.
 *
 * @param data An NSDictionary object that contains the updated place data.  For
 * the expected format, please see @ref placeDataFormat.
 *
 * @note Applies to:
 * - static places
 *
 * @version 1.0
 *
 * @example
 * @code
-(void) mapDidInitializeEngine:(VMEMapView *)mapView
{
    NSString *path = [[NSBundle mainBundle] pathForResource:@"visio_island_cms_update" ofType:@"json"];
    NSData *returnedData = [[NSFileManager defaultManager] contentsAtPath:path];

    if(NSClassFromString(@"NSJSONSerialization"))
    {
        NSError *error = nil;
        id object = [NSJSONSerialization
                     JSONObjectWithData:returnedData
                     options:0@
                     error:&error];

        if(error == nil
           && [object isKindOfClass:[NSDictionary class]])
        {
            NSDictionary *results = object;
            [mapView updatePlaceData:[results valueForKeyPath:@"locale.en"]];
        }
    }
}
 * @endcode
 */
-(void) updatePlaceData:(NSDictionary* _Nonnull) data;

/**
 * Updates the place data associated with a place ID.
 *
 * @param placeID The place ID who's data is to change
 * @param data The data that will be used to update the place.  For the expected
 * format, please see @ref placeDataFormat.  Pass nil to remove the data from map.
 *
 * @note For best performance, use updatePlaceData to populate the initial place
 * data.
 *
 * @return YES if the places data was updated, otherwise NO.
 *
 * @note Applies to:
 * - dynamic places
 * - static places
 *
 * @version 1.1
 */
-(BOOL) setPlaceID:(NSString* _Nonnull)placeID data:(NSDictionary* _Nullable)data;

/**
 * Update the place's color.
 *
 * @param placeID The place ID
 * @param color The color to apply to the place.
 *
 * @return YES if the places color was updated, otherwise NO.
 *
 * @note Applies to:
 * - static places
 * - dynamic places
 *
 * @version 1.1
 * @version 1.7 Now also applies to static place icons and dynamic places.
 */
-(BOOL) setPlaceID:(NSString* _Nonnull)placeID color:(UIColor * _Nonnull)color;

/**
 * Reset the place's color back to it's initial value.
 *
 * @param placeID The place ID
 *
 * @return YES if the places color was reset, otherwise NO.
 *
 * @note Applies to:
 * - static places
 * - dynamic places
 *
 * @version 1.1
 * @version 1.8 Now also applies to icons and dynamic places.
 */
-(BOOL) resetPlaceIDColor:(NSString* _Nonnull)placeID;

/**
 * Set a group of place colors in one call.
 *
 * The color update is batched.  The map will be non-responsive while the surface
 * colors are being set.
 *
 * @param placeIDToColor A dictionary of placeID to color.
 * @return YES if all place colors were updated, otherwise NO.
 *
 * @note Applies to:
 * - static places
 * - dynamic places
 *
 * @example
 * @code
 NSMutableDictionary<NSString*, UIColor*>* lPlaceToColor = [[NSMutableDictionary alloc] init];
 [lPlaceToColor setObject:[UIColor redColor] forKey:@"B1-UL-001"];
 [lPlaceToColor setObject:[UIColor redColor] forKey:@"B1-UL-002"];
 [self.mapView setPlaceIDColors:lPlaceToColor];
 * @endcode
 *
 * @version 1.15
 */
-(BOOL) setPlaceColor:(NSDictionary<NSString*, UIColor*>* _Nonnull)placeIDToColor;

/**
 * Reset a group of places to their original colors in one call.
 *
 * The color reset is batched.  The map will be non-responsive while the surface
 * colors are being reset.
 *
 * @param placeIDs An array of placeIDs to be reset.
 * @return YES if all places were reset, otherwise NO.
 *
 * @note Applies to:
 * - static places
 * - dynamic places
 *
 * @version 1.15
 */
-(BOOL) resetPlaceColor:(NSArray<NSString*>* _Nonnull)placeIDs;


/**
 * Adds a dynamic place to the map.
 *
 * @param placeID The ID of the place.  If the ID corresponds to an existing dynamic
 * place, then it will be replaced.  If the ID corresponds with a static place ID,
 * then this call will fail.
 * @param imageURL A URL that references an image that will be used to represent
 * the place within the map.  Secure http (i.e. https) is not currently supported.
 * @param data A data object for populating the place information. For the expected
 * format, please see @ref placeDataFormat.
 * @param position The place's position within the map
 * @param size Controls the place's size
 * @param anchorMode Determines how the place will be anchored to the map.
 * @param altitudeMode Determines how to interpret the altitude attribute of the
 * position parameter.
 * @param displayMode Determines how the place is displayed
 * @param orientation Controls the place's orientation
 * @param visibilityRamp Controls the place's visibility
 *
 * @return YES if the place was successfully added to the map, otherwise NO.
 *
 * @note Will only work if called during or after the
 * VMELifeCycleListener::mapDidLoad: method.  It will not work if called within the
 * VMELifeCycleListener::mapDidInitializeEngine:.
 *
 * @note Applies to:
 * - dynamic places
 *
 * @example
 * @code

 VMEPosition* lPos = [[VMEPosition alloc] initWithLatitude:45.74131
                                                 longitude:4.88216
                                                  altitude:0.0
                                                buildingID:nil
                                                   floorID:nil];

 NSDictionary *placeData = [NSDictionary dictionaryWithObjectsAndKeys:
                            @"Cat tracker", @"name",
                            @"https://en.wikipedia.org/wiki/Cat", @"description",
                            @"http://www.clipartbest.com/cliparts/aTe/K4e/aTeK4en8c.png", @"icon",
                            @[@"2", @"3", @"99"], @"categories",
                            nil];

 NSURL* lIconUrl = [NSURL URLWithString:@"http://www.clipartbest.com/cliparts/aTe/K4e/aTeK4en8c.png"];

 [self.mapView addPlaceID:@"cat_tracker_id"
                 imageURL:lIconUrl
                     data:placeData
                 position:lPos
                     size:[[VMEPlaceSize alloc] initWithScale:50.0]
               anchorMode:VMEPlaceAnchorModeBottomCenter
             altitudeMode:VMEPlaceAltitudeModeRelative
              displayMode:VMEPlaceDisplayModeOverlay
              orientation:[VMEPlaceOrientation placeOrientationFacing]
           visibilityRamp:[[VMEPlaceVisibilityRamp alloc] init]
  ];
 * @endcode
 *
 * @version 1.1
 */
-(BOOL) addPlaceID:(NSString* _Nonnull)placeID
          imageURL:(NSURL* _Nullable)imageURL
              data:(NSDictionary* _Nullable)data
          position:(VMEPosition* _Nonnull)position
              size:(VMEPlaceSize* _Nullable)size
        anchorMode:(VMEPlaceAnchorMode)anchorMode
      altitudeMode:(VMEPlaceAltitudeMode)altitudeMode
       displayMode:(VMEPlaceDisplayMode)displayMode
       orientation:(VMEPlaceOrientation* _Nullable)orientation
    visibilityRamp:(VMEPlaceVisibilityRamp* _Nullable)visibilityRamp;

/**
 * Adds a dynamic place to the map.
 *
 * @param placeID The ID of the place.  If the ID corresponds to an existing dynamic
 * place, then it will be replaced.  If the ID corresponds with a static place ID,
 * then this call will fail.
 * @param imageURL A URL that references an image that will be used to represent
 * the place within the map. Secure http (i.e. https) is not currently supported.
 * @param data A data object for populating the place information. For the expected
 * format, please see @ref placeDataFormat.
 * @param position The place's position within the map
 *
 * @return YES if the place was successfully added to the map, otherwise NO.
 *
 * @note When using this method, the other properties of the object are initialized
 * to appropriate values:
 * - size is set to 20.0
 * - anchorMode is set to ::VMEPlaceAnchorModeBottomCenter
 * - altitudeMode is set to ::VMEPlaceAltitudeModeAbsolute
 * - displayMode is set to VMEPlaceDisplayModeOverlay
 * - orientation is set using @c [VMEPlaceOrientation placeOrientationFacing]
 * - visibilityRamp is set using @c [[VMEPlaceVisibilityRamp alloc] init]]
 *
 * @see VMEMapView::addPlaceID:imageURL:data:position:size:anchorMode:altitudeMode:displayMode:orientation:visibilityRamp:
 *
 * @note Applies to:
 * - dynamic places
 *
 * @example
 * @code

 VMEPosition* lPos = [[VMEPosition alloc] initWithLatitude:45.74131
                                                 longitude:4.88216
                                                  altitude:0.0
                                                buildingID:nil
                                                   floorID:nil];

 NSDictionary *placeData = [NSDictionary dictionaryWithObjectsAndKeys:
                            @"Cat tracker", @"name",
                            @"https://en.wikipedia.org/wiki/Cat", @"description",
                            @"http://www.clipartbest.com/cliparts/aTe/K4e/aTeK4en8c.png", @"icon",
                            @[@"2", @"3", @"99"], @"categories",
                            nil];

 NSURL* lIconUrl = [NSURL URLWithString:@"http://www.clipartbest.com/cliparts/aTe/K4e/aTeK4en8c.png"];

 [self.mapView addPlaceID:@"cat_tracker_id"
                 imageURL:lIconUrl
                     data:placeData
                 position:lPos];
  ];
 * @endcode
 *
 * @version 1.1
 */
-(BOOL) addPlaceID:(NSString* _Nonnull)placeID
          imageURL:(NSURL* _Nullable)imageURL
              data:(NSDictionary* _Nullable)data
          position:(VMEPosition* _Nonnull)position;


/**
 * Update the place's position.
 *
 * @param placeID The place ID
 * @param position The place's new position
 * @param animated Determines whether the change should be animated.
 *
 * @return YES if the place's position was updated, otherwise NO.
 *
 * @note Applies to:
 * - dynamic places
 *
 * @version 1.1
 */
-(BOOL) setPlaceID:(NSString* _Nonnull)placeID position:(VMEPosition* _Nonnull)position animated:(BOOL)animated;

/**
 * Update the place's size.
 *
 * @param placeID The place ID
 * @param size The place's new size
 * @param animated Determines whether the change should be animated.
 *
 * @return YES if the place's size was updated, otherwise NO.
 *
 * @note Applies to:
 * - dynamic places
 *
 * @version 1.1
 */
-(BOOL) setPlaceID:(NSString* _Nonnull)placeID size:(VMEPlaceSize* _Nonnull)size animated:(BOOL)animated;

/**
 * Remove the place from the map.
 *
 * @param placeID The ID of the place to be removed.
 *
 * @return YES if the place was removed, otherwise NO.
 *
 * @note Applies to:
 * - dynamic places
 *
 * @version 1.1
 */
-(BOOL) removePlaceID:(NSString* _Nonnull)placeID;

/**
 * Queries all place IDs within the map.
 *
 * @note Can be called during or after the
 * VMELifeCycleListener::mapDidInitializeEngine: notification
 *
 * @return An array of place IDs within the map.  Will return an empty array if
 * called before the map has correctly loaded.
 *
 * @note Applies to:
 * - static places
 * - dynamic places
 *
 * @version 1.4
 */
-(NSArray<NSString*>* _Nonnull) queryAllPlaceIDs;

/**
 * Queries the map for places matching the filter.
 *
 * @param filter The place filter to be applied to the map.
 * @param callback The callback object to be notified of the results
 *
 * @note Applies to:
 * - static places
 * - dynamic places
 *
 * @example
 * @code
 -(void) queryPlacesExample
 {
    VMEPlaceFilter* lFilter = [[VMEPlaceFilter alloc] initWithPlaceID:@"404"];
    lFilter.restrictToTargetLayer = false;
    lFilter.restrictToPlaceIDs = NSArray arrayWithObjects:@"411", @"413", @"206", nil];
    [self.mapView queryPlacesWithFilter:lFilter callback:self];
 }

 -(void)placeFilterDidFinish:(VMEMapView*)mapView
                  parameters:(VMEPlaceFilter*)filter
                     results:(NSArray<VMERouteResult*>*)results
 {
    for (VMERouteResult* lResult in results) {
        NSLog(@"%fm from %@", lResult.length, lResult.destinations.firstObject);
    }
 }

 * @endcode
 * @version 1.8
 */
-(void) queryPlacesWithFilter:(VMEPlaceFilter* _Nonnull)filter
                     callback:(id<VMEPlaceFilterCallback> _Nonnull)callback;

/**
 * Returns a requested place.
 *
 * @param placeID The ID of the place to return.
 * @return A place object that corresponds to the place ID, or null if ID doesn't exist.
 *
 * @note Can be called during or after the
 * VMELifeCycleListener::mapDidLoad: notification.
 *
 * @note Applies to:
 * - static places
 * - dynamic places
 *
 * @version 1.10
 */
-(VMEPlace* _Nullable) getPlace:(NSString* _Nonnull)placeID;

/**
 * Queries all category IDs within the map.
 *
 * @note Can be called during or after the
 * VMELifeCycleListener::mapDidLoad: notification
 *
 * @return An array of category IDs within the map.  Will return an empty array if
 * called before the map has correctly loaded.
 *
 * @version 1.10
 */
-(NSArray<NSString*>* _Nonnull) queryAllCategoryIDs;

/**
 * Returns a requested category.
 *
 * @param categoryID The ID of the category to return.
 * @return A category object that corresponds to the category ID, or null if ID doesn't exist.
 *
 * @note Can be called during or after the
 * VMELifeCycleListener::mapDidLoad: notification.
 *
 * @version 1.10
 */
-(VMECategory* _Nullable) getCategory:(NSString* _Nonnull)categoryID;

/**
 * Returns a place's center position.
 *
 * @param placeID The ID of the place in question
 * @return The place's center position.
 *
 * @note Can be called during or after the
 * VMELifeCycleListener::mapDidLoad: notification.
 *
 * @version 1.16
 */
-(VMEPosition* _Nullable) getPlacePosition:(NSString* _Nonnull)placeID;

/**
 * Returns The place's bounding box.
 *
 * @param placeID The ID of the place in question
 * @return An array of positions that represent the places bounding box
 *
 * @note Can be called during or after the
 * VMELifeCycleListener::mapDidLoad: notification.
 *
 * @version 1.16
 */
-(NSArray<VMEPosition*>* _Nonnull) getPlaceBoundingPositions:(NSString* _Nonnull)placeID;
/**
 * @}
 */


#pragma mark - VMECustomDataInterface
/**
 * @defgroup customDataInterface CustomData
 * Custom Data management.
 * @ingroup mapView
 * @{
 */

/**
 * Fetch the custom data from server
 *
 * @param successBlock custom data has been fetched
 * @param errorBlock if there was an error fetching custom data.
 *
 * @example
 * @code
 [self.mMapView refreshCustomDataWithSuccessBlock:^ {
 // success - do something with data
 *     NSMutableDictionary* lDict = [self.mMapView getCustomDatafromCache];
 } andErrorBlock:^(NSError * lError) {
 // error
 }];
 * @endcode
 *
 * @version 1.27
 */


-(void)fetchCustomDataWithSuccessBlock:(void (^_Nonnull)(void))successBlock andErrorBlock:(void (^_Nonnull)(NSError*_Nullable))errorBlock;

/**
 * Returns all places custom data.
 *
 * @return NSDictionary containing all custom data values
 * @version 1.27
 */
-(NSDictionary*_Nonnull)getCustomData;

/**
 * @}
 */


#pragma mark - VMEOverlayViewInterface
/**
 * @defgroup overlayViewInterface Overlay Views
 * Add custom content above the map surface. Overlays are anchored to a specific map coordinate.
 * @ingroup mapView
 * @{
 */

/**
 * Adds a native overlay view above the map that's associated with a position.
 *
 * @param overlayViewID The id to given to overlay view.  Must be unique.
 * @param view The native view to added to the map.
 * @param position The position to which the overlay view will be anchored.
 * @return YES if the overlay was added to the map, otherwise NO.
 *
 * @note By default the anchor mode will be set to ::VMEAnchorModeBottomCenter.
 *
 * @example
 * @code
 View* lView = [[UIView alloc] initWithFrame:CGRectMake(0, 0, 200, 100)];
 VMEPosition* lPos = [[VMEPosition alloc] initWithLatitude:45.740876918853147
 longitude:4.8805385544669795
 altitude:3
 buildingID:@"B3"
 floorID:@"B3-UL01"];
 [self.mapView addOverlayViewID:@"info_overlay_id" view:lView position:lPos];
 * @endcode
 *
 * @see addOverlayViewID:view:position:anchorMode:
 * @version 1.1
 */
-(BOOL) addOverlayViewID:(NSString* _Nonnull)overlayViewID view:(UIView* _Nonnull)view position:(VMEPosition* _Nonnull)position;

/**
 * Adds a native overlay view above the map that's associated with a position.
 *
 * @param overlayViewID The id to given to overlay view.  Must be unique.
 * @param view The native view to added to the map.
 * @param position The position to which the overlay view will be anchored.  The
 * bottom center of the view will be tied to the position.
 * @param anchorMode The part of the view to be anchored to the map.
 * @return YES if the overlay was added to the map, otherwise NO.
 *
 * @example
 * @code
 View* lView = [[UIView alloc] initWithFrame:CGRectMake(0, 0, 200, 100)];
 VMEPosition* lPos = [[VMEPosition alloc] initWithLatitude:45.740876918853147
 longitude:4.8805385544669795
 altitude:3
 buildingID:@"B3"
 floorID:@"B3-UL01"];
 [self.mapView addOverlayViewID:@"info_overlay_id" view:lView position:lPos anchorMode:VMEAnchorModeCenterLeft];
 * @endcode
 * @version 1.14
 */
-(BOOL) addOverlayViewID:(NSString* _Nonnull)overlayViewID view:(UIView* _Nonnull)view position:(VMEPosition* _Nonnull)position anchorMode:(VMEAnchorMode)anchorMode;

/**
 * Adds a native overlay view above the map that's associated with a place.
 *
 * @param overlayViewID The id to given to overlay view.  Must be unique.
 * @param view The native view to added to the map.
 * @param placeID The view will be anchored to the center point of the place
 * with this ID.  The bottom center of the view will be tied to the place.
 * @return YES if the overlay was added to the map, otherwise NO.
 *
 * @note By default the anchor mode will be set to ::VMEAnchorModeBottomCenter.
 *
 * @example
 * @code
 View* lView = [[UIView alloc] initWithFrame:CGRectMake(0, 0, 200, 100)];
 [self.mapView addOverlayViewID:@"info_overlay_id" view:lView placeID:@"B2-LL01-ID0008"];
 * @endcode
 * @version 1.1
 */
-(BOOL) addOverlayViewID:(NSString* _Nonnull)overlayViewID view:(UIView* _Nonnull)view placeID:(NSString* _Nonnull)placeID;

/**
 * Adds a native overlay view above the map that's associated with a place.
 *
 * @param overlayViewID The id to given to overlay view.  Must be unique.
 * @param view The native view to added to the map.
 * @param placeID The view will be anchored to the center point of the place
 * with this ID.
 * @param anchorMode The part of the view to be anchored to the map.
 * @return YES if the overlay was added to the map, otherwise NO.
 *
 * @example
 * @code
 View* lView = [[UIView alloc] initWithFrame:CGRectMake(0, 0, 200, 100)];
 [self.mapView addOverlayViewID:@"info_overlay_id" view:lView placeID:@"B2-LL01-ID0008" anchorMode:VMEAnchorModeCenterLeft];
 * @endcode
 * @version 1.14
 */
-(BOOL) addOverlayViewID:(NSString* _Nonnull)overlayViewID view:(UIView* _Nonnull)view placeID:(NSString* _Nonnull)placeID anchorMode:(VMEAnchorMode)anchorMode;

/**
 * Sets the position of the overlay view
 *
 * @param overlayViewID The id of the overlay view
 * @param position The position to update
 *
 * @version 1.1
 */
-(BOOL) setOverlayViewID:(NSString* _Nonnull)overlayViewID position:(VMEPosition* _Nonnull)position;

/**
 * Sets the place of the overlay view
 *
 * @param overlayViewID The id of the overlay view
 * @param placeID The place id to update
 *
 * @version 1.1
 */
-(BOOL) setOverlayViewID:(NSString* _Nonnull)overlayViewID placeID:(NSString* _Nonnull)placeID;

/**
 * Removes the overlay view from the map.
 *
 * @param overlayViewID The id of the overlay view to remove.
 *
 * @version 1.1
 */
-(BOOL) removeOverlayViewID:(NSString* _Nonnull)overlayViewID;

/**
 * @}
 */


#pragma mark - VMEStatisticsInterface
/**
 * @defgroup statisticsInterface Collect Statistics
 * Anonymously collect data for analysis within VisioStats.
 * @ingroup mapView
 * @{
 */
/**
 * Set the statistics logging.  This attribute is the main switch for logging
 * statistics.
 *
 * If enabled, then the requested statistics will be logged. If disabled, none
 * of the requested statistics will be logged.
 *
 * @param enabled YES to enable, NO to disable it. Default is NO.
 *
 * @note Will be ignored if called before VMEMapView::loadMap.
 *
 * @version 1.5
 *
 * @example
 * @code
 [self.mapView setStatisticsLog:YES];
 * @endcode
 */
-(void) setStatisticsLog:(BOOL) enabled;

/**
 * Set the statistics camera logging.  If enabled, the camera's ground focus
 * position will be logged at regular intervals during the end users interactions
 * with the map.
 *
 * @param enabled YES to enable, NO to disable it.  Default is NO.
 *
 * @note VMEMapView::setStatisticsLog: must be enabled before
 * any logging will occur.
 *
 * @note Will be ignored if called before VMEMapView::loadMap.
 *
 * @version 1.5
 *
 * @example
 * @code
 * [self.mapView setStatisticsLogCamera:YES];
 * @endcode
 */
-(void) setStatisticsLogCamera:(BOOL) enabled;

/**
 * Set the statistics location logging.  If enabled, the location received from
 * VMELocationInterface::updateLocation: will be logged at regular intervals
 * while location updates are received.
 *
 * @param enabled YES to enable, NO to disable it.  Default is YES.
 *
 * @note VMEMapView::setStatisticsLog: must be enabled before
 * any logging will occur.
 *
 * @note Will be ignored if called before VMEMapView::loadMap.
 *
 * @version 1.5
 *
 * @example
 * @code
 * [self.mapView setStatisticsLogLocation:YES];
 * @endcode
 */
-(void) setStatisticsLogLocation:(BOOL) enabled;

/**
 * Set the statistics interest logging.  If enabled, the user's map interests will
 * be logged.  Interests include:
 * - selected places
 * - route information (origin and destinations)
 *
 * @param enabled YES to enable, NO to disable it.  Default is YES.
 *
 * @note VMEMapView::setStatisticsLog: must be enabled before
 * any logging will occur.
 *
 * @note Will be ignored if called before VMEMapView::loadMap.
 *
 * @version 1.5
 *
 * @example
 * @code
 * [self.mapView setStatisticsLogInterest:YES];
 * @endcode
 */
-(void) setStatisticsLogInterest:(BOOL) enabled;

/**
 * Set the statistics place tracked position logging for a list of place IDs.
 * Calling this will override any previous place IDs that where being tracked.
 *
 * @param trackedPlaceIDs An array of place IDs to be tracked.  Pass empty array to stop tracking.
 *
 * @note VMEMapView::setStatisticsLog: must be enabled before
 * any logging will occur.
 *
 * @note Will be ignored if called before VMEMapView::loadMap.
 *
 * @version 1.18
 *
 * @example
 * @code
 * [self.mapView setStatisticsTrackedPlaceIDs:@[@"poiID1",@"poiID2"]];
 * @endcode
 */
-(void) setStatisticsTrackedPlaceIDs:(NSArray<NSString*>* _Nonnull) trackedPlaceIDs;

/**
 * See VMEMapView::setStatisticsLog: for more info on what this returns.
 *
 * @return Whether enabled or not.
 *
 * @note This method should be called within or after VMELifeCycleListener::mapDidLoad:
 * because it can be enabled via the application parameters.
 *
 * @version 1.5
 *
 * @example
 * @code
 * BOOL isEnabled = [self.mapView isStatisticsLog];
 * @endcode
 *
 */
-(BOOL) isStatisticsLog;

/**
 * See VMEMapView::setStatisticsLogCamera: for more info on what this returns.
 *
 * @return Whether enabled or not.
 *
 * @note This method should be called within or after VMELifeCycleListener::mapDidLoad:
 * because it can be enabled via the application parameters.
 *
 * @version 1.5
 *
 * @example
 * @code
 * BOOL isEnabled = [self.mapView isStatisticsLogCamera];
 * @endcode
 */
-(BOOL) isStatisticsLogCamera;

/**
 * See VMEMapView::setStatisticsLogLocation: for more info on what this returns.
 *
 * @return Whether enabled or not.
 *
 * @note This method should be called within or after VMELifeCycleListener::mapDidLoad:
 * because it can be enabled via the application parameters.
 *
 * @version 1.5
 *
 * @example
 * @code
 * BOOL isEnabled = [self.mapView isStatisticsLogLocation];
 * @endcode
 */
-(BOOL) isStatisticsLogLocation;

/**
 * See VMEMapView::setStatisticsLogInterest: for more info on what this returns.
 *
 * @return Whether enabled or not.
 *
 * @note This method should be called within or after VMELifeCycleListener::mapDidLoad:
 * because it can be enabled via the application parameters.
 *
 * @version 1.5
 *
 * @example
 * @code
 * BOOL isEnabled = [self.mapView isStatisticsLogInterest];
 * @endcode
 */
-(BOOL) isStatisticsLogInterest;

/**
 * See VMEMapView::setStatisticsTrackedPlaceIDs: for more info on what this returns.
 *
 * @returns The place ids who are currently being tracked.
 *
 * @note This method should be called within or after VMELifeCycleListener::mapDidLoad:
 * because it can be enabled via the application parameters.
 *
 * @version 1.18
 *
 * @example
 * @code
 * NSArray<NSString*>* trackedPlaceIDs = [self.mapView getStatisticsTrackedPlaceIDs];
 * @endcode
 */
-(NSArray<NSString*>* _Nonnull) getStatisticsTrackedPlaceIDs;

/**
 * @}
 */

#pragma mark - Static methods
/**
 * @defgroup staticMethods Version info
 * @brief Retrieve versioning information related to the SDK.
 *
 * @ingroup mapView
 * @{
 */

/**
 * Retrieve the current version of VisioMove Essential (iOS).
 *
 * @version 1.0
 */
+(NSString* _Nonnull) getVersion;

/**
 * Retrieves the minimum version string major.minor.patch of the data that this
 * SDK can handle.
 *
 * In other words, the map bundle must have been generated with
 * at least this SDK version, otherwise it will not be loaded.  You can find the
 * sdk_version that a map bundle was generated with within its descriptor.json file.
 *
 * @version 1.0
 */
+(NSString* _Nonnull) getMinDataSDKVersion;

/**
 * Retrieves the version string major.minor.patch of the data that this
 * SDK can handle.
 *
 * In other words, the map bundle's minimum supported SDK must be less than or equal to this SDK version,
 * otherwise it will not be loaded.  You can find the sdk_min_version that a map bundle was generated
 * with within its descriptor.json file.
 *
 * @version 1.21
 */
+(NSString* _Nonnull) getDataSDKVersion;

/**
 * @}
 */

@end
