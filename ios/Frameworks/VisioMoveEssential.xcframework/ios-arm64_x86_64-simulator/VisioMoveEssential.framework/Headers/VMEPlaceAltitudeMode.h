/*
 * Copyright (c) Visioglobe SAS. All rights reserved.
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE.txt', which is part of this source code package.
 */

/**
 * @ingroup enums
 * @brief This enum defines the possible altitude modes. An altitude mode determines
 * how the altitude is interpreted.
 *
 * @version 1.1
 */
typedef NS_ENUM(NSInteger, VMEPlaceAltitudeMode) {
    /**
     * The altitude is interpreted relative to the terrain.
     *
     * @version 1.1
     */
    VMEPlaceAltitudeModeRelative,
    /**
     * The altitude is interpreted as the height above the WGS84 ellipsoid
     *
     * @version 1.1
     */
    VMEPlaceAltitudeModeAbsolute
};

