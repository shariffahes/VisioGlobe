/*
 * Copyright (c) Visioglobe SAS. All rights reserved.
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE.txt', which is part of this source code package.
 */

/**
 * @ingroup enums
 * @brief The view mode controls certain elements of the scene and possibly the camera's viewpoint.
 *
 * @version 1.0
 */
typedef NS_ENUM(NSInteger, VMEViewMode)
{
    /**
     * In global mode, the following occurs:
     * - The camera focuses on the footprint "outside".
     * - If present, all building models are made visible and building icons will
     * appear.  
     * - All floors from all buildings will be hidden.
     *
     * @version 1.0
     */
    VMEViewModeGlobal,
    /**
     * In floor mode, the following occurs:
     * - If present, the focused building's model will animate and disappear.
     * - The focused building's floors will appear in lego mode.
     * - The camera will focus on the focused floor's footprint.
     *
     * @version 1.0
     */
    VMEViewModeFloor,
    /**
     * The view mode is undefined.  If this value is passed in an camera update,
     * then the most appropriate view mode will be chosen.
     *
     * @version 1.0
     */
    VMEViewModeUnknown
};

