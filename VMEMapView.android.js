import React, { useEffect, useRef } from 'react';
import { UIManager, findNodeHandle, PixelRatio, View } from 'react-native';
import { MapViewManager } from './MapViewManager';

const createFragment = viewId =>
  UIManager.dispatchViewManagerCommand(
    viewId,
    UIManager.MapViewManager.Commands.create.toString(),
    [viewId],
  );
export const VMEMapView = (props) => {
  const ref = useRef(null);
  const { width, height } = props.style;
  useEffect(() => {
    const viewId = findNodeHandle(ref.current);
    createFragment(viewId);
  }, []);

  if (!width || !height) throw new Error("Width and height are required style properties");
  if (!props.mapHash) throw new Error("mapHash property is undefined");
  return (
    <View style={{ height: height, width: width }}>
      <MapViewManager
        showOverlay={props.showOverlay ?? null}
        displayPromptToDownloadMap={props.displayPromptToDownloadMap ?? null}
        mapHash={props.mapHash}
        style={{
          height: PixelRatio.getPixelSizeForLayoutSize(height),
          width: PixelRatio.getPixelSizeForLayoutSize(width),
        }}
        ref={ref}
      />
    </View>
  );
};
