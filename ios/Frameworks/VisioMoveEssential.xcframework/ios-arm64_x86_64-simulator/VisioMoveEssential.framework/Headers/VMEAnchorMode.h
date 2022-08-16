/*
 * Copyright (c) Visioglobe SAS. All rights reserved.
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE.txt', which is part of this source code package.
 */

/**
 * @ingroup enums
 * @brief This enum defines the possible anchor modes.
 * An anchor mode determines how an object is anchored to a given position within the map
 *
 * @version 1.14
 */
typedef NS_ENUM(NSInteger, VMEAnchorMode) {
    /**
     * Anchor to the top left.
     *
     * @version 1.14
     */
    VMEAnchorModeTopLeft,
    /**
     * Anchor to the top center
     *
     * @version 1.14
     */
    VMEAnchorModeTopCenter,
    /**
     * Anchor to the top right
     *
     * @version 1.14
     */
    VMEAnchorModeTopRight,
    /**
     * Anchor to the center left
     *
     * @version 1.14
     */
    VMEAnchorModeCenterLeft,
    /**
     * Anchor to the center
     *
     * @version 1.14
     */
    VMEAnchorModeCenter,
    /**
     * Anchor to the center right
     *
     * @version 1.14
     */
    VMEAnchorModeCenterRight,
    /**
     * Anchor to the bottom left
     *
     * @version 1.14
     */
    VMEAnchorModeBottomLeft,
    /**
     * Anchor to the bottom center
     *
     * @version 1.14
     */
    VMEAnchorModeBottomCenter,
    /**
     * Anchor to the bottom right
     *
     * @version 1.14
     */
    VMEAnchorModeBottomRight
};
