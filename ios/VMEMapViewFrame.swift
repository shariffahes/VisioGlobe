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
  
  override init(frame: CGRect) {
    super.init(frame: frame)
    mMapView = VMEMapView.init()
    mMapView.frame = frame
    mMapView.mapHash = "dev-m89829873811956459f67b0c3c007b0f517cfd224"
    self.addSubview(mMapView)
  }
  
  func getVMEMapView () -> VMEMapView {
    return mMapView
  }
  //A function that is triggered when the view is added or removed from its superview
  override func didMoveToWindow() {
    mMapView.translatesAutoresizingMaskIntoConstraints = false
    mMapView.centerXAnchor.constraint(equalTo: self.centerXAnchor).isActive = true
    mMapView.centerYAnchor.constraint(equalTo: self.centerYAnchor).isActive = true
    let screenSize: CGRect = UIScreen.main.bounds
    mMapView.widthAnchor.constraint(equalToConstant: screenSize.width).isActive = true
    mMapView.heightAnchor.constraint(equalToConstant: screenSize.height*0.8).isActive = true
    mMapView.loadMap()
  }
  
  required init?(coder: NSCoder) {
    fatalError("init(coder:) has not been implemented")
  }
}
