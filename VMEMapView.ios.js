import React from 'react';
import { View } from 'react-native';
import { MapViewManager } from './MapViewManager';

export const VMEMapView = (props) => {
  const { width, height } = props.style;

  if (!width || !height) throw new Error("Width and height are required style properties");
  if (!props.mapHash) throw new Error("mapHash property is undefined");
  return (
    <View style={{ height: height, width: width }}>
      <MapViewManager
        showOverlay={props.showOverlay ?? null}
        displayPromptToDownloadMap={props.displayPromptToDownloadMap ?? null}
        mapHash={props.mapHash}
        style={{
          height: height,
          width: width,
        }}
      />
    </View>
  );
};
