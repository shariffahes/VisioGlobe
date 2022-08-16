/*
 * Copyright (c) Visioglobe SAS. All rights reserved.
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE.txt', which is part of this source code package.
 */

/**
 * @ingroup enums
 * @brief This enum defines the possible anchor modes.
 * An anchor mode determines how an place object is
 * anchored to a given position.
 *
 * @version 1.1
 */
typedef NS_ENUM(NSInteger, VMEPlaceAnchorMode) {
    /**
     * Anchor to the top left.
     *
     * @version 1.1
     */
    VMEPlaceAnchorModeTopLeft,
    /**
     * Anchor to the top center
     *
     * @version 1.1
     */
    VMEPlaceAnchorModeTopCenter,
    /**
     * Anchor to the top right
     *
     * @version 1.1
     */
    VMEPlaceAnchorModeTopRight,
    /**
     * Anchor to the center left
     *
     * @version 1.1
     */
    VMEPlaceAnchorModeCenterLeft,
    /**
     * Anchor to the center
     *
     * @version 1.1
     */
    VMEPlaceAnchorModeCenter,
    /**
     * Anchor to the center right
     *
     * @version 1.1
     */
    VMEPlaceAnchorModeCenterRight,
    /**
     * Anchor to the bottom left
     *
     * @version 1.1
     */
    VMEPlaceAnchorModeBottomLeft,
    /**
     * Anchor to the bottom center
     *
     * @version 1.1
     */
    VMEPlaceAnchorModeBottomCenter,
    /**
     * Anchor to the bottom right
     *
     * @version 1.1
     */
    VMEPlaceAnchorModeBottomRight

};
