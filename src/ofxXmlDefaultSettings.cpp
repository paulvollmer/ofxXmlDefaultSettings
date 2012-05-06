/**
 *  ofxXmlDefaultSettings.cpp
 *
 *  
 *  The MIT License
 *
 *  Copyright (c) 2012 Paul Vollmer, http://www.wng.cc
 *  
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *  
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 *  
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 *  THE SOFTWARE.
 *
 *  
 *  @testet_oF          0.07
 *  @testet_plattform   MacOs 10.6
 *                      ??? Win
 *                      ??? Linux
 *  @dependencies       ofxXmlSettings
 *  @modified           2012.05.06
 *  @version            0.1.0d
 */

#include "ofxXmlDefaultSettings.h"



ofxXmlDefaultSettings::ofxXmlDefaultSettings(){
	// Setting default filepath. if load() is called, 
	// the filepath will be used to save the xml file.
	filepath = ofFilePath::getCurrentWorkingDirectory()+"/ofSettings.xml";
}	
	
	
/**
 * load checks if a default xml file exist.
 * if no file is found, the method createDefaultXml()
 * creats a xml file automaticly.
 *
 * @param filepath
 *        Path to default xml file.
 */
void ofxXmlDefaultSettings::load(string filepath){
	this->filepath = filepath;
	if(loadFile(filepath)){
		#ifdef OFXXMLDEFAULTSETTINGS_LOG
			ofLog() << "[ofxXmlDefaultSettings] Default xml loaded!";
		#endif
	} else {
		#ifdef OFXXMLDEFAULTSETTINGS_LOG
			ofLog() << "[ofxXmlDefaultSettings] Unable to load default xml!";
			//ofLog() << "                        Filepath = " << filepath;
		#endif
		createDefaultXml();
		loadFile(filepath);
	}
}

/**
 * Same as load(string filepath) but we use the default filepath.
 */
void ofxXmlDefaultSettings::load(){
	load(filepath);
}


/**
 * Get the openFrameworks core settings and save values into xml.
 *
 * @param return
 *        Set boolean true, if file is saved.
 */
bool ofxXmlDefaultSettings::saveSettings(){
	if(ofGetWindowMode() == 0){
		setAttribute("ofCore:ofWindowShape", "width", ofGetWidth(), 0);
		setAttribute("ofCore:ofWindowShape", "height", ofGetHeight(), 0);
		setAttribute("ofCore:ofWindowPosition", "x", ofGetWindowPositionX(), 0);
		setAttribute("ofCore:ofWindowPosition", "y", ofGetWindowPositionY(), 0);
	}
	setValue("ofCore:ofFullscreen", ofGetWindowMode(), 0);
	saveFile(filepath);
	#ifdef OFXXMLDEFAULTSETTINGS_LOG
		ofLog() << "[ofxXmlDefaultSettings] Save settings to default xml file.";
		//ofLog() << "                        Filepath = " << filepath;
	#endif
}


/**
 * Set the openFrameworks core settings from xml file.
 */
void ofxXmlDefaultSettings::setSettings(){
	setFrameRate();
	setFullscreen();
	setWindowShape();
	setWindowPosition();
	setWindowTitle();
	setCursor();
	setEscapeQuitsApp();
	setLogToFile();
	#ifdef OFXXMLDEFAULTSETTINGS_LOG
		ofLog() << "[ofxXmlDefaultSettings] Set Settings from default xml file.";
	#endif
}

/**
 * Set the framerate from xml file.
 */
void ofxXmlDefaultSettings::setFrameRate(){
	 ofSetFrameRate(getValue("ofCore:ofFrameRate", 60, 0));
}

/**
 * Set the window size from xml file.
 */
void ofxXmlDefaultSettings::setWindowShape(){
	ofSetWindowShape(getAttribute("ofCore:ofWindowShape", "width", 1024, 0),
					 getAttribute("ofCore:ofWindowShape", "height", 768, 0));
}

/**
 * Set the window position from xml file.
 */
void ofxXmlDefaultSettings::setWindowPosition(){
	ofSetWindowPosition(getAttribute("ofCore:ofWindowPosition", "x", 30, 0),
						getAttribute("ofCore:ofWindowPosition", "y", 30, 0));
}

/**
 * Set the window title from xml file.
 */
void ofxXmlDefaultSettings::setWindowTitle(){
	ofSetWindowTitle(getValue("ofCore:ofWindowTitle", "openFrameworks Application", 0));
}

/**
 * Set the cursor mode from xml file.
 */
void ofxXmlDefaultSettings::setCursor(){
	int temp = getValue("ofCore:ofCursor", false, 0);
	if(temp == 1){
		ofHideCursor();
	} else {
		ofShowCursor();
	}
}

/**
 * Set the fullscreen mode from xml file.
 */
void ofxXmlDefaultSettings::setFullscreen(){
	int temp = getValue("ofCore:ofFullscreen", false, 0);
	if(temp == 0){
		ofSetFullscreen(false);
	} else {
		ofSetFullscreen(true);
	}
}

/**
 * Set the ofSetEscapeQuitsApp from xml file.
 */
void ofxXmlDefaultSettings::setEscapeQuitsApp(){
	int temp = getValue("ofCore:ofEscapeQuitsApp", false, 0);
	if(temp == 0){
		ofSetEscapeQuitsApp(false);
	} else {
		ofSetEscapeQuitsApp(true);
	}
}

/**
 * Set the ofLogToFile from xml file.
 */
void ofxXmlDefaultSettings::setLogToFile(){
	int temp = getValue("ofCore:ofLogToFile", true, 0);
	string tempPath = getAttribute("ofCore:ofLogToFile", "filepath", "NULL", 0);
	string tempName = getAttribute("ofCore:ofLogToFile", "filename", "logs.txt", 0);
	if(temp == 1){
		
		// If the filepath attribute is NULL, 
		// we run the default method and save the log file to current working directory.
		if(tempPath == "NULL"){
			// check if a logs folder exist.
			// if no folder found, create one.
			ofDirectory dir(ofFilePath::getCurrentWorkingDirectory()+"/logs");
			if(!dir.exists()){
				dir.create(true);
			}
			ofLogToFile(ofFilePath::getCurrentWorkingDirectory()+"/logs"+"/"+tempName, 1);
			
		} else {
			ofLogToFile(tempPath+"/"+tempName, 1);
		}

	}
}



/**
 * private method
 * createDefaultXml
 *
 * Creating tags to store openFrameworks core settings.
 * The tags are named like the ofGet... methods. OF syntax as xml tag :)
 */
void ofxXmlDefaultSettings::createDefaultXml(){
	ofxXmlSettings xml;
	xml.addTag("ofCore");
	xml.pushTag("ofCore", 0);
		xml.addValue("ofFrameRate", 60);
		xml.addValue("ofFullscreen", false);
		xml.addTag("ofWindowShape");
		xml.addAttribute("ofWindowShape", "width", 1024, 0);
		xml.addAttribute("ofWindowShape", "height", 768, 0);
		xml.addTag("ofWindowPosition");
		xml.addAttribute("ofWindowPosition", "x", 0, 0);
		xml.addAttribute("ofWindowPosition", "y", 44, 0);
		xml.addValue("ofWindowTitle", "openFrameworks Application");
		xml.addValue("ofCursor", false);
		xml.addValue("ofEscapeQuitsApp", false);
		xml.addValue("ofLogToFile", true);
		xml.addAttribute("ofLogToFile", "filepath", "NULL", 0);
		xml.addAttribute("ofLogToFile", "filename", "logs.txt", 0);
	xml.popTag();
	xml.saveFile(filepath);
	#ifdef OFXXMLDEFAULTSETTINGS_LOG
		ofLog() << "[ofxXmlDefaultSettings] Default xml file generated and saved!";
		//ofLog() << "                        Filepath = " << filepath;
	#endif
}
