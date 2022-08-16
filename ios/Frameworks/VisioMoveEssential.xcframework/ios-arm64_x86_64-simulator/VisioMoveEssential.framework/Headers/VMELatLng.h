/*
 * Copyright (c) Visioglobe SAS. All rights reserved.
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE.txt', which is part of this source code package.
 */

/**
 * @ingroup models
 * @brief An immutable class representing a pair of latitude and longitude coordinates, stored as degrees.
 *
 * @version 1.24
 */
@interface VMELatLng : NSObject

/**
 * The objects latitude
 *
 * @version 1.24
 */
@property (nonatomic, readonly) double latitude;
/**
 * The objects longitude
 *
 * @version 1.24
 */
@property (nonatomic, readonly) double longitude;

/**
 * Constructs a VMELatLng with the given latitude and longitude, measured in degrees.
 *
 * @param latitude The point's latitude.
 * @param longitude The point's longitude.
 *
 * @version 1.24
 */
-(instancetype)initWithLatitude:(double)latitude longitude:(double)longitude;

/**
 * Compares this VMELatLng to the specified object.
 * @param other The VMELatLng to compare this object against.
 * @returns true if this VMELatLng represents the same lat lng as the specified object, false otherwise.
 *
 * @version 1.24
 */
-(BOOL) isEqual:(id)other;
@end

