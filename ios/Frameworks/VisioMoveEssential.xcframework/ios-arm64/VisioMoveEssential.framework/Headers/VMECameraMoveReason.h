/*
 * Copyright (c) Visioglobe SAS. All rights reserved.
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE.txt', which is part of this source code package.
 */

/**
 * @ingroup enums
 * @brief This enum defines the possible reasons that might invoke the camera to move.
 *
 * @version 1.25
 */
typedef NS_ENUM(NSInteger, VMECameraMoveReason) {
    /**
     * Non-gesture animation initiated in response to user actions. For example: place selected, location tracker, or next instruction.
     * @version 1.25
     */
    VMECameraMoveReasonAnimation,
    /**
     * Developer initiated animation.
     * @version 1.25
     */
    VMECameraMoveReasonDeveloperAnimation,
    /**
     * Camera motion initiated in response to user gestures on the map. For example: drag, pinch to zoom, or rotate.
     * @version 1.25
     */
    VMECameraMoveReasonGesture
};
