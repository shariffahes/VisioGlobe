/*
 * Copyright (c) Visioglobe SAS. All rights reserved.
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE.txt', which is part of this source code package.
 */

/**
 * @ingroup enums
 *
 * @brief The tracking mode controls the location tracking
 *
 * @version 1.19
 */
typedef NS_ENUM(NSInteger, VMELocationTrackingMode)
{
    /**
     * In none mode, the following occurs:
     * - There is no location tracking
     *
     * @version 1.19
     */
    VMELocationTrackingModeNone,
    /**
     * In custom mode, the following occurs:
     * - Use a custom location tracker provided by the integrators
     *
     * @version 1.19
     */
    VMELocationTrackingModeCustom,
    /**
     * In follow mode , the following occurs:
     * - Use the location tracker provided by the SDK
     *
     * @version 1.19
     */
    VMELocationTrackingModeFollow
};

/**
 * @version 1.19
 */
@interface VMELocationTrackingModeObject : NSObject

/**
 * Constructor
 * @param locationTrackingMode The enum to represent.
 * @returns An object that represents a ::VMELocationTrackingMode enum
 * @version 1.19
 */
-(instancetype) initWithEnum:(VMELocationTrackingMode) locationTrackingMode;

/**
 * The ::VMELocationTrackingMode enum the object represents
 * @version 1.19
 */
@property (nonatomic, readonly) VMELocationTrackingMode locationTrackingMode;

- (NSComparisonResult)compare:(VMELocationTrackingModeObject*)object;
@end


