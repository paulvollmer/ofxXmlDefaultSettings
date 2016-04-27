# ofxXmlDefaultSettings


**General Information**  
ofxXmlDefaultSettings is an extension for [openFrameworks](http://www.openframeworks.cc/) to create default xml file. Load, set and save core settings. Also you can use the xml to store other variables.  
  
Docs can be found at http://paulvollmer.github.com/ofxXmlDefaultSettings  
  
openFrameworks core variables:  
- window position  
- window size  
- window title  
- framerate  
- fullscreen  
- cursor  
- escape quits app  
- log to file  
  
**Current Version:**  
0.2.2 (stable and versioned using [semantic versioning](http://semver.org/))   
  
**Tested Platform:**  
MacOS 10.6+   
Win ???  
Linux ???  
**openFrameworks version:**  
0.7.4  
**Dependencies**  
ofxXmlSettings  

**Issues and Bugs**  
You can find a list of all known bugs at [GitHub](https://github.com/paulvollmer/ofxXmlDefaulSettings/issues). Please report if you find an unknown bug.  


## Changelog  
A detailed changelog, intended for programmers.  
  
**0.2.2**  
- Fixed ``load()``` methods (changes from ofxXmlSettings addon)
- Update Xcode Example Projects

**0.2.1**  
- Fixed cursor bug.  
- Added Doxygen file.  
- Set logging default parameter to false.  
  
**0.2.0**  
- Redesign of logging support. Testing.  

**0.1.3b**  
- Lot of changes at the whole implementation.  
 - Added XmlSyntax enum  
 - Added DefaultSettings struct  
 - Added statusMessage and delete #ifdef DEBUG stuff  
 - Added doxygen support  
 - Delete ofxXmlOscSettings class  
  
**0.1.2**  
- Added missing #ifndef  
  
**0.1.1**  
- Added ofxOsc settings  
  
**0.1.0d**  
- Added ofLogToFile, changes at ofFullscreen support.  
  
**0.1.0c**  
- Changes at method wording, clear up code, final test  
  
**0.1.0**  
- Starting addon at ofxXmlDefaultSettings Repository  
  
  
## Contributors
- [Paul Vollmer](http://www.github.com/paulvollmer)


## License 
ofxXmlDefaultSettings is Licensed under MIT Public License: http://www.opensource.org/licenses/MIT  
See also, LICENSE.txt in this distribution.
