const fs_extra = require('fs-extra');
const path = require('path');

const libraryFolder = path.join(__dirname, '../react-native-visio-globe');
const exampleFolder = path.join(__dirname, '/react-native-visio-globe');

fs_extra.copy(libraryFolder, exampleFolder, err => {
  if (err) {
    console.log(err);
  } else {
    console.log('moving library successful');
  }
});
