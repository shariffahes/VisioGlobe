/*
 * Copyright (c) Visioglobe SAS. All rights reserved.
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE.txt', which is part of this source code package.
 */
#import "VMEMacros.h"
#import "VMESceneContext.h"

/**
 * @ingroup models
 * @brief A VMEPosition object represents a position incorporating the geographical
 * coordinates, altitude and associated building and floor.
 *
 * Typically, you can use a VMEPosition object when moving the camera, anchoring overlays to the map,
 * creating a route from a position, etc.
 *
 * @version 1.1
 */
@interface VMEPosition : NSObject <NSCopying>

/**
 * Constructor for creating a position object inside
 *
 * @param latitude The position's latitude
 * @param longitude The position's longitude
 * @param altitude The position's altitude, relative to the floor.  For example
 * if the altitude is 10m, then the position will be 10m above the floor.
 * @param scene The scene context to associated with the position.
 *
 * @version 1.9
 */
-(instancetype) initWithLatitude:(double)latitude
                       longitude:(double)longitude
                        altitude:(double)altitude
                           scene:(VMESceneContext*)scene;

/**
 * Constructor for creating a position object outside
 *
 * @param latitude The position's latitude
 * @param longitude The position's longitude
 * @param altitude The position's altitude, relative to the outside.  For example
 * if the altitude is 10m, then the position will be 10m above the ground.
 *
 * @version 1.1
 */
-(instancetype) initWithLatitude:(double)latitude
                       longitude:(double)longitude
                        altitude:(double)altitude;

/**
 * Determines if this object is equal to another VMEPosition object.
 *
 * @param position The object to compare self to.
 * @returns YES if the objects are equal, otherwise NO.
 *
 * @version 1.2
 */
-(BOOL) isEqualToPosition:(VMEPosition*)position;

/**
 * The latitude of the position.
 *
 * @version 1.1
 */
@property (nonatomic, readonly) double latitude;
/**
 * The longitude of the position.
 *
 * @version 1.1
 */
@property (nonatomic, readonly) double longitude;
/**
 * The altitude of the position.
 *
 * @version 1.1
 */
@property (nonatomic) double altitude;

/**
 * The position's scene context.
 *
 * @version 1.9
 */
@property (nonatomic, strong, readonly) VMESceneContext* scene;

@end
