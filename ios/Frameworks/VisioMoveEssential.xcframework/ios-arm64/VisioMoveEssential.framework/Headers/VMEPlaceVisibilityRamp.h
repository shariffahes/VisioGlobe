/*
 * Copyright (c) Visioglobe SAS. All rights reserved.
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE.txt', which is part of this source code package.
 */

/**
 * @ingroup models
 * @brief An object that controls the place's visibility as a function of the camera's
 * altitude.
 *
 * @version 1.1
 */
@interface VMEPlaceVisibilityRamp : NSObject
/**
 * Creates a visibility ramp object with some default values.
 *
 * @note When using this method, the other properties of the object are initialized
 * to appropriate values. See the property default values for more info.
 *
 * @version 1.1
 */
-(instancetype)init;
/**
 * Creates a visibility ramp object with a user defined ramp.
 *
 * @param startVisible Distance in meters at which it starts becoming visible.
 * @param fullyVisible Distance in meters at which it is fully visible.
 * @param startInvisible Distance in meters at which it starts to become invisible.
 * @param fullyInVisible Distance in meters at which it is fully invisible.
 *
 * @version 1.1
 */
-(instancetype)initWithStartVisible:(double)startVisible
                       fullyVisible:(double)fullyVisible
                     startInvisible:(double)startInvisible
                     fullyInVisible:(double)fullyInVisible;

/**
 * Distance in meters at which it starts becoming visible. If set to 0.0, it is
 * always visble no matter how close you are.
 *
 * The default value of this property is 2.0.
 *
 * @version 1.1
 */
@property (nonatomic, readonly) double startVisible;
/**
 * Distance in meters at which it is fully visible. If set to 0.0, it is always
 * visible when you are close.
 *
 * The default value of this property is 5.0.
 *
 * @version 1.1
 */
@property (nonatomic, readonly) double fullyVisible;
/**
 * Distance in meters at which it starts to become invisible.
 *
 * The default value of this property is 3000.
 *
 * @version 1.1
 */
@property (nonatomic, readonly) double startInvisible;
/**
 * Distance in meters at which it is fully invisible. If set to a very large
 * value, it will never fade out.
 *
 * The default value of this property is 5000.
 *
 * @version 1.1
 */
@property (nonatomic, readonly) double fullyInvisible;
@end
