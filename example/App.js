import React from 'react';
import {SafeAreaView, useWindowDimensions} from 'react-native';
import {VMEMapView} from './react-native-visio-globe';

const App = () => {
  const {height, width} = useWindowDimensions();
  console.log(height);
  return (
    <SafeAreaView>
      <VMEMapView style={{height, width}} />
    </SafeAreaView>
  );
};
export default App;
