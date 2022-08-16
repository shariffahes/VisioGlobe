/*
 * Copyright (c) Visioglobe SAS. All rights reserved.
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE.txt', which is part of this source code package.
 */

extern NSString *const VMEPlaceIconKey;
extern NSString *const VMEPlaceDescriptionKey;
extern NSString *const VMEPlaceCategoriesKey;
extern NSString *const VMEPlaceNameKey;

/**
 * @ingroup models
 * @brief Represents a physical place within the map
 *
 * A Place encapsulates information about a physical place, including its name, description,
 * categories and any other information we might have about it.
 *
 * @version 1.10
 */
@interface VMEPlace : NSObject

-(instancetype)initWithID:(NSString*)pKey andData:(NSDictionary*)pData;

/**
 * The unique identifier of the place
 */
@property (nonatomic, readonly) NSString* ID;

/**
 * The name associated with the place.
 */
@property (nonatomic, readonly) NSString* name;
/**
 * The icon associated with the place.  This will appear
 */
@property (nonatomic, readonly) NSString* icon;
/**
 * The category id's associated with the place
 */
@property (nonatomic, readonly) NSArray<NSString*>* categories;
/**
 * A description in HTML for the place.  The HTML may contain references to other media
 * types, such as images and video.  These media types may be stored locally
 * within the application or linked to a remote server.
 */
@property (nonatomic, readonly) NSString* htmlDescription;

@end

