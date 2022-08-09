
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

1. Open up `android/app/src/main/java/[...]/MainActivity.java`
  - Add `import com.reactlibrary.RNVisioGlobePackage;` to the imports at the top of the file
  - Add `new RNVisioGlobePackage()` to the list returned by the `getPackages()` method
2. Append the following lines to `android/settings.gradle`:
  	```
  	include ':react-native-visio-globe'
  	project(':react-native-visio-globe').projectDir = new File(rootProject.projectDir, 	'../node_modules/react-native-visio-globe/android')
  	```
3. Insert the following lines inside the dependencies block in `android/app/build.gradle`:
  	```
      compile project(':react-native-visio-globe')
  	```

#### Windows
[Read it! :D](https://github.com/ReactWindows/react-native)

1. In Visual Studio add the `RNVisioGlobe.sln` in `node_modules/react-native-visio-globe/windows/RNVisioGlobe.sln` folder to their solution, reference from their app.
2. Open up your `MainPage.cs` app
  - Add `using Visio.Globe.RNVisioGlobe;` to the usings at the top of the file
  - Add `new RNVisioGlobePackage()` to the `List<IReactPackage>` returned by the `Packages` method


## Usage
```javascript
import RNVisioGlobe from 'react-native-visio-globe';

// TODO: What to do with the module?
RNVisioGlobe;
```
  