/*
 * Copyright (c) Visioglobe SAS. All rights reserved.
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE.txt', which is part of this source code package.
 */
#import "VMEPosition.h"
#import "VMEManeuverType.h"
#import "VMEFloorTransitionType.h"

/**
 * @ingroup models
 * @brief A segment describes a part of a computed route.
 *
 * @version 1.17
 */
@interface VMESegment : NSObject <NSCopying>

/**
 * Instantiates a segment object.
 *
 * @param maneuverType The maneuver that describes the end of the segment.
 * @param floorTransitionType The floor transition type when a floor transition occurs.
 * @param floorTransitionId The id of the floor transition.
 * @param duration The duration (seconds) of the segment.
 * @param length The length (metres) of the segment.
 * @param path An array of positions that make up the segment
 *
 * @version 1.17
 * @version 1.22
 */
-(instancetype)initWithManeuver:(VMEManeuverType)maneuverType
            floorTransitionType:(VMEFloorTransitionType)floorTransitionType
              floorTransitionId:(NSString*)floorTransitionId
                       duration:(double)duration
                         length:(double)length
                           path:(NSArray<VMEPosition*>*)path;

/**
 * The path of the segment.
 *
 * @version 1.17
 */
@property (readonly) NSArray<VMEPosition*>* path;
/**
 * The duration (seconds) of the segment.
 *
 * @version 1.17
 */
@property (readonly) double duration;
/**
 * The length (metres) of the segment.
 *
 * @version 1.17
 */
@property (readonly) double length;
/**
 * The maneuver type of the segment.
 *
 * @version 1.17
 */
@property (readonly) VMEManeuverType maneuverType;

/**
 * The floor transition type of the segment.
 * If the segment doesn't change floors, then will be set to ::VMEFloorTransitionTypeNone.
 *
 * @version 1.22
 */
@property (readonly) VMEFloorTransitionType floorTransitionType;

/**
 * The floor transition id of the segment.
 * If there is no floor transition then value is "".
 *
 * @version 1.22
 */
@property (readonly) NSString* floorTransitionId;
@end
