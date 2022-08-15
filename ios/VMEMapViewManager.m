//
//  VMEMapViewManager.m
//  example
//
//  Created by Sharif Fahes on 11/08/2022.
//
#import "React/RCTViewManager.h"
@interface RCT_EXTERN_MODULE(VMEMapViewManager, RCTViewManager)
RCT_EXPORT_VIEW_PROPERTY(showOverlay, BOOL)
RCT_EXPORT_VIEW_PROPERTY(displayPromptToDownloadMap, BOOL)
RCT_EXPORT_VIEW_PROPERTY(mapHash, NSString)
@end
