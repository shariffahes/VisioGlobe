import React, {useEffect, useRef} from 'react';
import {UIManager, findNodeHandle} from 'react-native';

import {MapViewManager} from './MapViewManager';
import {VMEMapView} from './VMEMapView';

const createFragment = viewId =>
  UIManager.dispatchViewManagerCommand(
    viewId,
    UIManager.MapViewManager.Commands.create.toString(),
    [viewId],
  );

export const VMEMapView = (props) => {
  const ref = useRef(null);
  const {width, height} = props;
  useEffect(() => {
    const viewId = findNodeHandle(ref.current);
    createFragment(viewId);
  }, []);

  return (
    <MapViewManager
      style={{
        height: height ?? 400,
        width: width ?? 300,
      }}
      ref={ref}
    />
  );
};
