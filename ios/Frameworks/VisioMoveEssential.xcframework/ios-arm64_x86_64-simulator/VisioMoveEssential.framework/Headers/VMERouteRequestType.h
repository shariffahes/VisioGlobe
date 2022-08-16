/*
 * Copyright (c) Visioglobe SAS. All rights reserved.
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE.txt', which is part of this source code package.
 */

/**
 * @ingroup enums
 * @brief The route request type determines the parameter to use when calculating the route
 *
 * @version 1.2
 */
typedef NS_ENUM(NSInteger, VMERouteRequestType)
{
    /**
     * Indicates a request for a route that optimizes distance.
     *
     * @version 1.2
     */
    VMERouteRequestTypeShortest,
    /**
     * Indicates a request for a route that optimizes time.
     *
     * @version 1.2
     */
    VMERouteRequestTypeFastest
};
