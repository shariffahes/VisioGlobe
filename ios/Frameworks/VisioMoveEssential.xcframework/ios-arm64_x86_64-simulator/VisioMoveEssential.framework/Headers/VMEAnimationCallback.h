/*
 * Copyright (c) Visioglobe SAS. All rights reserved.
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE.txt', which is part of this source code package.
 */

#import <Foundation/Foundation.h>

/**
 * @ingroup callbacks
 * @brief Callback protocol to be notified of animation events
 *
 * @version 1.7
 */
@protocol VMEAnimationCallback <NSObject>
/**
 * Notify the callback that the animation did finish.
 *
 * @version 1.7
 */
@optional
-(void) didFinish;
@end
