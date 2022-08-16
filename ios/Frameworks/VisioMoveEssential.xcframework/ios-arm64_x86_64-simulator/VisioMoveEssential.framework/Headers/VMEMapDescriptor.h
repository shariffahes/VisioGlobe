/*
 * Copyright (c) Visioglobe SAS. All rights reserved.
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE.txt', which is part of this source code package.
 */

/**
 * The map descriptor object contains information related to it's associated map bundle.
 *
 * @version v1.21
 */
@interface VMEMapDescriptor : NSObject

/**
 * Creates a VMEMapDescriptor object
 * @param data
 * @version v1.21
 */
-(instancetype) initWithData:(NSDictionary*)data;

/**
 * Identifier of map (can be used within a filename).
 * @version v1.21
 */
@property (readonly) NSString* ID;

/**
 * The name of the map bundle, including it's domain.
 * @version v1.21
 */
@property (readonly) NSString* name;

/**
 * A timestamp indicating when the map was built (UTC + 0).
 * @note The format of the timestamp is: YYYYMMDDHHMMSS
 * @version v1.21
 */
@property (readonly) long long timestamp;

/**
 * A secret code that is required in order to load the map.
 * @version v1.21
 */
@property (readonly) int secretCode;

/**
 * The expiry date of the map bundle. The format of the date is [string YYYY/MM/DD, ISO
 * short format, UTC].  If the string is empty, then it indicates the map doesn't have an expiry
 * date.
 *
 * @version v1.21
 */
@property (readonly) NSString* expiryDate;

/**
 * The SDK type that this map descriptor represents.
 * @note VisioMoveEssential expects the type to be "move"
 * @version v1.21
 */
@property (readonly) NSString* SDKType;
/**
 * The SDK version that the map bundle was built for.
 *
 * @note For the map to be valid, this must be less than or equal to
 * VMEMapView.getMinDataSDKVersion().  Otherwise the SDK has dropped support for this version of
 * map bundle.
 * @version v1.21
 */
@property (readonly) NSString* SDKVersion;

/**
 * The minimum version of SDK that can load the map which this map descriptor represents.
 * @note For the map to be valid, this must be greater than or equal to
 * VMEMapView.getDataSDKVersion().  Otherwise the map bundle is too recent for the SDK.
 * @version v1.21
 */
@property (readonly) NSString* SDKMinVersion;

/**
 * The filename of the map bundle as stored on the map server.
 * @version v1.21
 */
@property (readonly) NSString* zipFile;

/**
 * The filename of the map bundle as stored on the map server.
 * @version v1.27
 */
@property (readonly) NSString* path;

/**
 * The target of the map bundle.
 * @version v1.24
 */
@property (readonly) NSString* target;

/**
 * The target of the map bundle.
 * @version v1.27
 */
@property (readonly) NSString* customDataHash;


/**
 * @return YES if this map descriptor represents a map bundle that can loaded by this SDK,
 * otherwise NO.
 * @version v1.21
 */
-(BOOL) isValid;

/**
 * Compare current VMEMapDescriptor with another.
 *
 * @param mapDescriptor The VMEMapDescriptor to compare with.
 * @returns YES if this object is the same as other, otherwise NO.
 * @version 1.21
 */
-(BOOL) isEqualToMapDescriptor:(VMEMapDescriptor*) mapDescriptor;

@end
