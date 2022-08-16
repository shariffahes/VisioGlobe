/*
 * Copyright (c) Visioglobe SAS. All rights reserved.
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE.txt', which is part of this source code package.
 */

/**
 * @ingroup enums
 * @brief Maneuver type indications.
 *
 * @version 1.17
 */
typedef NS_ENUM(NSInteger, VMEManeuverType) {
    /**
     * Go straight
     * @version 1.17
     */
    VMEManeuverTypeGoStraight,
    /**
     * Turn gentle right
     * @version 1.17
     */
    VMEManeuverTypeTurnGentleRight,
    /**
     * Turn gentle left
     * @version 1.17
     */
    VMEManeuverTypeTurnGentleLeft,
    /**
     * Turn right
     * @version 1.17
     */
    VMEManeuverTypeTurnRight,
    /**
     * Turn left
     * @version 1.17
     */
    VMEManeuverTypeTurnLeft,
    /**
     * Turn sharp right
     * @version 1.17
     */
    VMEManeuverTypeTurnSharpRight,
    /**
     * Turn sharp left
     * @version 1.17
     */
    VMEManeuverTypeTurnSharpLeft,
    /**
     * U-turn right
     * @version 1.17
     */
    VMEManeuverTypeUTurnRight,
    /**
     * U-turn left
     * @version 1.17
     */
    VMEManeuverTypeUTurnLeft,
    /**
     * Start
     * @version 1.17
     */
    VMEManeuverTypeStart,
    /**
     * End
     * @version 1.17
     */
    VMEManeuverTypeEnd,
    /**
     * Go up
     * @version 1.17
     */
    VMEManeuverTypeGoUp,
    /**
     * Go down
     * @version 1.17
     */
    VMEManeuverTypeGoDown,
    /**
     * Change modality
     * @version 1.17
     */
    VMEManeuverTypeChangeModality,
    /**
     * Change layer
     * @version 1.17
     */
    VMEManeuverTypeChangeLayer,
    /**
     * Waypoint
     * @version 1.17
     */
    VMEManeuverTypeWaypoint
};

