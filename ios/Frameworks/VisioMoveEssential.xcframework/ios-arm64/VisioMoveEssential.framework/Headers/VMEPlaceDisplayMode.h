/*
 * Copyright (c) Visioglobe SAS. All rights reserved.
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE.txt', which is part of this source code package.
 */

/**
 * @ingroup enums
 * @brief This enum defines the possible display modes. A display mode determines
 * how the point is displayed within the map.
 *
 * @version 1.1
 */
typedef NS_ENUM(NSInteger, VMEPlaceDisplayMode) {
    /**
     * The place will obscured when located behind map surfaces.
     *
     * @version 1.1
     */
    VMEPlaceDisplayModeInlay,
    /**
     * The place is displayed on top of all map surfaces, regardless of whether
     * they are physical infront of the place.
     *
     * @version 1.1
     */
    VMEPlaceDisplayModeOverlay
};
