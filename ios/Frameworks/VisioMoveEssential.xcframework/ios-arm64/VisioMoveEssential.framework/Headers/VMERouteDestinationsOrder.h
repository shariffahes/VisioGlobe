/*
 * Copyright (c) Visioglobe SAS. All rights reserved.
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE.txt', which is part of this source code package.
 */

/**
 * @ingroup enums
 * @brief The different ways to interpret multiple destinations, these options
 * do not change the behavior if there is only one destination.
 *
 * For optimal routes there is a practical limit on 5-6 destinations.
 *
 * @version 1.2
 */
typedef NS_ENUM(NSInteger, VMERouteDestinationsOrder)
{
    /**
     * Indicates that the destinations should be traversed in order
     *
     * @version 1.2
     */
    VMERouteDestinationsOrderInOrder,
    /**
     * Indicates that the destinations should be traversed in the order
     * that minimizes the overall distance or time: e.g. travelling salesman order
     *
     * @version 1.2
     */
    VMERouteDestinationsOrderOptimal,
    /**
     * Indicates that the destinations should be traversed in the order
     * that minimizes the overall distance or time: e.g. travelling salesman order,
     * but always finish on the last routing node of mDestinations.  For example,
     * you enter a shop, you visit the different stands and you finish at the exit.
     *
     * @version 1.2
     */
    VMERouteDestinationsOrderOptimalFinishOnLast,
    /**
     * Indicates that one destination should be returned, the one that is closest (be fastest or shortest).
     *
     * @version 1.2
     */
    VMERouteDestinationsOrderClosest
};
