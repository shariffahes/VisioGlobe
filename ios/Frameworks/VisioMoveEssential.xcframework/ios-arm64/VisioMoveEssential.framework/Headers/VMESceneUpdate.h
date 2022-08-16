/*
 * Copyright (c) Visioglobe SAS. All rights reserved.
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE.txt', which is part of this source code package.
 */

#import "VMEViewMode.h"

/**
 * @ingroup models
 * @brief Represents a scene update that can be applied to the VMEMapView.
 *
 * Use the provided constructors to instantiate different types of scene updates.
 * A scene update can be used to change the following:
 *  - view mode
 *  - focused building
 *  - focused floor
 *
 * Updating the scene will not update the camera.
 *
 * @note Due to the "zoom storyboard", if the camera is focused on a different
 * building to that in the requested scene update, then the next time the user
 * interacts with the map, the focused building will change automatically.
 *
 * @version 1.2
 */
@interface VMESceneUpdate : NSObject


/**
 * Update the scene's view mode.  The current focused building and floor will
 * remain unchanged.
 *
 * @param viewMode The view mode to change to.  Pass ::VMEViewModeUnknown to leave
 * the current view mode.
 *
 * @version 1.2
 */
+(instancetype) sceneUpdateForViewMode:(VMEViewMode)viewMode;


/**
 * Update the scene.
 *
 * @param viewMode The view mode to change to.  Pass ::VMEViewModeUnknown to leave
 * the current view mode.
 * @param buildingID The building id to apply focus.  The focused floor will be
 * determined by the first of the following:
 *  - the current floor if it is associated with the building
 *  - the building's default floor, if it has one.
 *  - otherwise the ground floor will be given focus.
 *
 * @version 1.2
 */
+(instancetype) sceneUpdateForViewMode:(VMEViewMode)viewMode
                            buildingID:(NSString*)buildingID;

/**
 * Update the scene
 *
 * @param viewMode The view mode to change to.  Pass ::VMEViewModeUnknown to leave
 * the current view mode.
 * @param floorID The floor id to apply focus.  The building id associated with
 * the floorID will be deduced.
 *
 * @version 1.2
 */
+(instancetype) sceneUpdateForViewMode:(VMEViewMode)viewMode
                               floorID:(NSString*)floorID;
@end
