//
//  VMEMapView.swift
//  example
//
//  Created by Sharif Fahes on 11/08/2022.
//

import Foundation
import UIKit
import VisioMoveEssential

class VMEMapViewFrame: UIView {
  var mMapView: VMEMapView!
  @objc var showOverlay: Bool = false
  @objc var displayPromptToDownloadMap: Bool = true
  @objc var mapHash: NSString!
  override init(frame: CGRect) {
    super.init(frame: frame)
    mMapView = VMEMapView.init()
    mMapView.frame = frame
    //mMapView.mapHash = "dev-m89829873811956459f67b0c3c007b0f517cfd224"
    self.addSubview(mMapView)
  }
  
  func getVMEMapView () -> VMEMapView {
    return mMapView
  }
  
  override func didMoveToWindow() {
    mMapView.translatesAutoresizingMaskIntoConstraints = false
    mMapView.widthAnchor.constraint(equalTo: self.widthAnchor, multiplier: 1.0).isActive = true
    mMapView.heightAnchor.constraint(equalTo: self.heightAnchor, multiplier: 1.0).isActive = true
    mMapView.loadMap()
  }
  
  override func didSetProps(_ changedProps: [String]!) {
      mMapView.setSelectorViewVisible(self.showOverlay)
      mMapView.promptUserToDownloadMap = self.displayPromptToDownloadMap
      mMapView.mapHash = self.mapHash as String
      mMapView.loadMap()
  }
  
  required init?(coder: NSCoder) {
    fatalError("init(coder:) has not been implemented")
  }
}
