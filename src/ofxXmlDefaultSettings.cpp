/**
 *  ofxXmlDefaultSettings.cpp is part of ofxXmlDefaultSettings.
 *
 *  Copyright (c) 2012, Paul Vollmer http://www.wrong-entertainment.com
 *  All rights reserved.
 *
 *  
 *  The MIT License
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy of this software
 *  and  associated documentation files  (the "Software"), to deal in the Software without
 *  restriction, including without limitation the rights to use, copy, modify, merge, publish,
 *  distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the
 *  Software is furnished to do so, subject to the following conditions:
 *  
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 *  
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
 *  BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 *  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 *  DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 *  
 *  @testet_oF          0071
 *  @testet_plattform   MacOs 10.6+
 *                      ??? Win
 *                      ??? Linux
 *  @dependencies       ofxXmlSettings
 *  @contributor(s)     Paul Vollmer <paul.vollmer@fh-potsdam.de>
 *  @modified           2012.09.20
 *  @version            0.1.2b
 */

#include "ofxXmlDefaultSettings.h"


/**
 * Constructor
 */
ofxXmlDefaultSettings::ofxXmlDefaultSettings(){
	// Setting default filepath. if load() is called, 
	// the filepath will be used to save the xml file.
	filepath = ofFilePath::getCurrentWorkingDirectory()+"/ofSettings.xml";
	
	// Set default xml settings version.
	XML_VERSION = "0.2.0";
	
	// Set default names of xml tags.
	XML_TAG_MAIN = "ofxXmlDefaultSettings";
	XML_TAG_OFCORE = "ofCore";
	XML_TAG_OFADDONS = "ofAddons";
	XML_TAG_CUSTOM = "custom";
	XML_TAG_DEFAULT = "item";
}


/**
 * Same as load(string filepath) but we use the default filepath.
 */
void ofxXmlDefaultSettings::load(){
	load(filepath);
}

/**
 * This method checks if a default xml file exist.
 * if no file is found, the method "createDefaultXml()"
 * creats a xml file automaticly.
 *
 * @param filepath
 *        Path to default xml file.
 */
void ofxXmlDefaultSettings::load(string filepath){
	this->filepath = filepath;
	
	if(loadFile(filepath)){
		statusMessage = "Default xml loaded!";
	}
	else {
		statusMessage = "Unable to load default xml!";
		createDefaultXml();
		loadFile(filepath);
	}
	
	#ifdef OFXXMLDEFAULTSETTINGS_LOG
		ofLog() << "[ofxXmlDefaultSettings] " + statusMessage;
	#endif
}


/**
 * Get the openFrameworks core settings and save values into xml.
 *
 * @param return
 *        Set boolean true, if file is saved.
 */
bool ofxXmlDefaultSettings::saveSettings(){
	if(ofGetWindowMode() == 0){
		setAttribute(XML_TAG_OFCORE+":ofWindowShape", "width", ofGetWidth(), 0);
		setAttribute(XML_TAG_OFCORE+":ofWindowShape", "height", ofGetHeight(), 0);
		setAttribute(XML_TAG_OFCORE+":ofWindowPosition", "x", ofGetWindowPositionX(), 0);
		setAttribute(XML_TAG_OFCORE+":ofWindowPosition", "y", ofGetWindowPositionY(), 0);
	}
	setValue(XML_TAG_OFCORE+":ofFullscreen", ofGetWindowMode(), 0);
	saveFile(filepath);
	
	statusMessage = "Save settings to default xml file.";
	
	#ifdef OFXXMLDEFAULTSETTINGS_LOG
		ofLog() << "[ofxXmlDefaultSettings] " << statusMessage;
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
	
	statusMessage = "Set Settings from default xml file.";
	
	#ifdef OFXXMLDEFAULTSETTINGS_LOG
		ofLog() << "[ofxXmlDefaultSettings] " << statusMessage;
	#endif
}

/**
 * Set the framerate from xml file.
 */
void ofxXmlDefaultSettings::setFrameRate(){
	 ofSetFrameRate(getValue(XML_TAG_OFCORE+":ofFrameRate", 60, 0));
}

/**
 * Set the window size from xml file.
 */
void ofxXmlDefaultSettings::setWindowShape(){
	ofSetWindowShape(getAttribute(XML_TAG_OFCORE+":ofWindowShape", "width", 1024, 0),
					 getAttribute(XML_TAG_OFCORE+":ofWindowShape", "height", 768, 0));
}

/**
 * Set the window position from xml file.
 */
void ofxXmlDefaultSettings::setWindowPosition(){
	ofSetWindowPosition(getAttribute(XML_TAG_OFCORE+":ofWindowPosition", "x", 30, 0),
						getAttribute(XML_TAG_OFCORE+":ofWindowPosition", "y", 30, 0));
}

/**
 * Set the window title from xml file.
 */
void ofxXmlDefaultSettings::setWindowTitle(){
	ofSetWindowTitle(getValue(XML_TAG_OFCORE+":ofWindowTitle", "openFrameworks Application", 0));
}

/**
 * Set the cursor mode from xml file.
 */
void ofxXmlDefaultSettings::setCursor(){
	int temp = getValue(XML_TAG_OFCORE+":ofCursor", false, 0);
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
	int temp = getValue(XML_TAG_OFCORE+":ofFullscreen", false, 0);
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
	int temp = getValue(XML_TAG_OFCORE+":ofEscapeQuitsApp", false, 0);
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
	int temp = getValue(XML_TAG_OFCORE+":ofLogToFile", true, 0);
	string tempPath = getAttribute(XML_TAG_OFCORE+":ofLogToFile", "filepath", "NULL", 0);
	string tempName = getAttribute(XML_TAG_OFCORE+":ofLogToFile", "filename", "logs.txt", 0);
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
			ofLogToFile(ofFilePath::getCurrentWorkingDirectory()+"/logs"+"/"+ofGetTimestampString()+"_"+tempName, 1);
			
		} else {
			ofLogToFile(tempPath+"/"+ofGetTimestampString()+"_"+tempName, 1);
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
	xml.addTag(XML_TAG_MAIN);
	xml.addAttribute(XML_TAG_MAIN, "version", XML_VERSION, 0);
	xml.pushTag(XML_TAG_MAIN, 0);
	xml.addValue("test1", 123);
	xml.popTag();
	
	xml.addTag(XML_TAG_OFCORE);
	xml.pushTag(XML_TAG_OFCORE, 0);
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
	xml.popTag(); // pop XML_TAG_OFCORE
	
	xml.saveFile(filepath);
	
	statusMessage = "Default xml file generated and saved!";
	
	#ifdef OFXXMLDEFAULTSETTINGS_LOG
		ofLog() << "[ofxXmlDefaultSettings] " << statusMessage;
	#endif
}
