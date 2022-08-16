import { requireNativeComponent, UIManager } from "react-native";
 
export const MapViewManager = UIManager.getViewManagerConfig("VMEMapView") != null
    && requireNativeComponent("VMEMapView");
