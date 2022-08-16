/*
 * Copyright (c) Visioglobe SAS. All rights reserved.
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE.txt', which is part of this source code package.
 */

/**
 * @ingroup enums
 * @brief This enum defines the possible floor transition type.
 * A transition type determines how the route will change floor
 *
 * @version 1.22
 */
typedef NS_ENUM(NSInteger, VMEFloorTransitionType) {
    /**
     * Floor transition will occur by stairway
     *
     * @version 1.22
     */
    VMEFloorTransitionTypeStairWay,
    /**
     * Floor transition will occur by elevator
     *
     * @version 1.22
     */
    VMEFloorTransitionTypeElevator,
    /**
     * Floor transition will occur by escalator
     *
     * @version 1.22
     */
    VMEFloorTransitionTypeEscalator,
    /**
     * Floor transition will occur by an unknown mean
     *
     * @version 1.22
     */
    VMEFloorTransitionTypeUnknown,
    /**
     * There is no floor transition
     *
     * @version 1.22
     */
    VMEFloorTransitionTypeNone,
};

