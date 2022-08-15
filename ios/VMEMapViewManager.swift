//
//  VMEMapViewManager.swift
//  example
//
//  Created by Sharif Fahes on 11/08/2022.
//

import Foundation
import VisioMoveEssential
import React

@objc(VMEMapViewManager)
class VMEMapViewManager: RCTViewManager {
  var mapViewFrame: VMEMapViewFrame!
  var mapView: VMEMapView!
  
  override static func requiresMainQueueSetup() -> Bool {
    return true
  }
  
  override func view() -> UIView! {
    mapViewFrame = VMEMapViewFrame.init()
    mapView = mapViewFrame.getVMEMapView()
    return mapViewFrame
  }
  
  
  
}
