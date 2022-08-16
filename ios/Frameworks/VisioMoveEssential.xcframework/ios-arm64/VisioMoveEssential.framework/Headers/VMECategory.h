/*
 * Copyright (c) Visioglobe SAS. All rights reserved.
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE.txt', which is part of this source code package.
 */

extern NSString *const VMECategoryNameKey;
extern NSString *const VMECategoryIconKey;

/**
 * @ingroup models
 * @brief Represents a category that can be associated with a place.
 *
 * A category encapsulates information category, including its name and icon and any other
 * information we might have about it.
 *
 * A category object is immutable.  If you wish to change a category's attributes, then please see interfaces::VMEPlaceInterface.
 *
 * @version 1.10
 */
@interface VMECategory : NSObject
/**
 * Instantiates a VMECategory object.
 * @version 1.10
 */
-(instancetype)initWithID:(NSString*)pKey andData:(NSDictionary*)pData;
/**
 * The category's unique ID
 * @version 1.10
 */
@property (nonatomic, readonly) NSString* ID;
/**
 * The category name
 * @version 1.10
 */
@property (nonatomic, readonly) NSString* name;
/**
 * The icon associated with the category
 * @version 1.10
 */
@property (nonatomic, readonly) NSString* icon;
@end

