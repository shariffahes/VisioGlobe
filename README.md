
# react-native-visio-globe

## Getting started

`$ npm install react-native-visio-globe --save`

### Mostly automatic installation

`$ react-native link react-native-visio-globe`

### Manual installation


#### iOS

1. In XCode, in the project navigator, right click `Libraries` ➜ `Add Files to [your project's name]`
2. Go to `node_modules` ➜ `react-native-visio-globe` and add `RNVisioGlobe.xcodeproj`
3. In XCode, in the project navigator, select your project. Add `libRNVisioGlobe.a` to your project's `Build Phases` ➜ `Link Binary With Libraries`
4. Run your project (`Cmd+R`)<

#### Android

1. Open up `android/app/src/main/java/[...]/MainApplication.java`
  - Add `import com.reactlibrary.RNVisioGlobePackage;` to the imports at the top of the file
  - Add `new RNVisioGlobePackage()` to the list returned by the `getPackages()` method
2. Append the following lines to `android/settings.gradle`:
  	```
	include ':app', ':react-native-visio-globe'
	project(':react-native-visio-globe').projectDir = new File(rootProject.projectDir, 	'../react-native-visio-globe/android')
  	```
3. Insert the following lines inside the dependencies block in `android/app/build.gradle`:
  	```
      implementation project(':react-native-visio-globe')
  	```

## Usage
```javascript
import {VMEMapView} from 'react-native-visio-globe';

// TODO: What to do with the module?
VMEMapView;
```
  