
/*
 * Copyright (c) Visioglobe SAS. All rights reserved.
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE.txt', which is part of this source code package.
 */

/**
 * @ingroup models
 * @brief VMECameraPitch represents a pitch element that may be associated
 * with a VMECameraUpdate object.
 *
 * It encapsulates some logic for controlling the camera's pitch. It should only
 * be constructed using the factory helper methods below.
 *
 * The VMECameraPitch object is immutable.
 *
 * @version 1.18
 */
@interface VMECameraPitch : NSObject <NSCopying>

/**
 * Keep the camera's current pitch.
 *
 * @version 1.18
 */
+(instancetype)cameraPitchCurrent;

/**
 * Uses the default pitch.
 * The default pitch is determined by the vg_app_params.json created by VisioMapEditor.
 *
 * @version 1.18
 */
+(instancetype)cameraPitchDefault;

/**
 * Provide a specific pitch.
 *
 * @param pitch  The pitch value to be applied to the camera, accepted values are between [-1...-89].
 *
 * @version 1.18
 */
+(instancetype)cameraPitchWithPitch:(double)pitch;

-(BOOL) isEqualToPitch:(VMECameraPitch*) pPitch;
@end
