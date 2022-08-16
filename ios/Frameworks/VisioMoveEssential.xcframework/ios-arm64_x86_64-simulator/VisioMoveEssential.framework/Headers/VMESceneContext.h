/*
 * Copyright (c) Visioglobe SAS. All rights reserved.
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE.txt', which is part of this source code package.
 */

/**
 * @ingroup models
 * @brief A VMESceneContext object represents a physical location within the map.
 * The scene context may be either outside or within a building.
 *
 * @version 1.9
 */
@interface VMESceneContext : NSObject <NSCopying>

/**
 * Create a scene context for the outside.
 *
 * @version 1.9
 */
-(instancetype) initOutside;

/**
 * Create a scene context for a given building and floor
 *
 * @param buildingID The id of the building
 * @param floorID The id of the floor
 *
 * @version 1.9
 */
-(instancetype) initWithBuildingID:(NSString*)buildingID floorID:(NSString*)floorID;

/**
 * @return YES if the scene context is located outside, otherwise NO.
 *
 * @version 1.9
 */
-(BOOL) isOutside;


/**
 * Compares two scene context objects to determine whether they are equal.
 *
 * @param sceneContext The scene context object to compare against.
 * @return YES if this scene context object is equal.
 *
 * @version 1.9
 */
-(BOOL) isEqualToSceneContext:(VMESceneContext*) sceneContext;

/**
 * The id of the building.
 * @note If isOutside returns YES, then this value is undefined.
 *
 * @version 1.9
 */
@property (atomic, strong, readonly) NSString* buildingID;

/**
 * The id of the floor.
 * @note If isOutside returns YES, then this value is undefined
 *
 * @version 1.9
 */
@property (atomic, strong, readonly) NSString* floorID;

@end

