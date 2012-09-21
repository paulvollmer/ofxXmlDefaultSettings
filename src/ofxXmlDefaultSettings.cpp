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
	
 	// Set default xml syntax (names of xml tags, version and url).
	syntax[XML_ROOT_TAG] = "ofxXmlDefaultSettings";
	syntax[XML_ROOT_VERSION] = "0.2.0";
	syntax[XML_ROOT_URL] = "https://github.com/wrongentertainment/ofxxmldefaultsettings";
	syntax[XML_CORE_TAG] = "ofCore";
	syntax[XML_ADDONS_TAG] = "ofAddons";
	syntax[XML_CUSTOM_TAG] = "custom";
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
		if(getAttribute(syntax[XML_ROOT_TAG], "version", "0", 0) == syntax[XML_ROOT_VERSION]){
			statusMessage = "Default xml loaded!";
		} else {
			statusMessage = "Default xml loaded! Not correct file version!";
		}
	}
	else {
		statusMessage = "Unable to load xml file! Generate and save file.";;
		createDefaultXml();
		loadFile(filepath);
	}
}


/**
 * Get the openFrameworks core settings and save values into xml.
 *
 * @param return
 *        Set boolean true, if file is saved.
 */
bool ofxXmlDefaultSettings::saveSettings(){
	if(ofGetWindowMode() == 0){
		setAttribute(syntax[XML_ROOT_TAG]+":"+syntax[XML_CORE_TAG]+":windowShape", "width", ofGetWidth(), 0);
		setAttribute(syntax[XML_ROOT_TAG]+":"+syntax[XML_CORE_TAG]+":windowShape", "height", ofGetHeight(), 0);
		setAttribute(syntax[XML_ROOT_TAG]+":"+syntax[XML_CORE_TAG]+":windowPosition", "x", ofGetWindowPositionX(), 0);
		setAttribute(syntax[XML_ROOT_TAG]+":"+syntax[XML_CORE_TAG]+":windowPosition", "y", ofGetWindowPositionY(), 0);
	}
	setValue(syntax[XML_ROOT_TAG]+":"+syntax[XML_CORE_TAG]+":fullscreen", ofGetWindowMode(), 0);
	saveFile(filepath);
	
	statusMessage = "Save settings to default xml file.";
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
}

/**
 * Set the framerate from xml file.
 */
void ofxXmlDefaultSettings::setFrameRate(){
	 ofSetFrameRate(getValue(syntax[XML_ROOT_TAG]+":"+syntax[XML_CORE_TAG]+":frameRate", 60, 0));
}

/**
 * Set the window size from xml file.
 */
void ofxXmlDefaultSettings::setWindowShape(){
	ofSetWindowShape(getAttribute(syntax[XML_ROOT_TAG]+":"+syntax[XML_CORE_TAG]+":windowShape", "width", 1024, 0),
					 getAttribute(syntax[XML_ROOT_TAG]+":"+syntax[XML_CORE_TAG]+":windowShape", "height", 768, 0));
}

/**
 * Set the window position from xml file.
 */
void ofxXmlDefaultSettings::setWindowPosition(){
	ofSetWindowPosition(getAttribute(syntax[XML_ROOT_TAG]+":"+syntax[XML_CORE_TAG]+":windowPosition", "x", 30, 0),
						getAttribute(syntax[XML_ROOT_TAG]+":"+syntax[XML_CORE_TAG]+":windowPosition", "y", 30, 0));
}

/**
 * Set the window title from xml file.
 */
void ofxXmlDefaultSettings::setWindowTitle(){
	ofSetWindowTitle(getValue(syntax[XML_ROOT_TAG]+":"+syntax[XML_CORE_TAG]+":windowTitle", "openFrameworks Application", 0));
}

/**
 * Set the cursor mode from xml file.
 */
void ofxXmlDefaultSettings::setCursor(){
	int temp = getValue(syntax[XML_ROOT_TAG]+":"+syntax[XML_CORE_TAG]+":cursor", false, 0);
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
	int temp = getValue(syntax[XML_ROOT_TAG]+":"+syntax[XML_CORE_TAG]+":fullscreen", false, 0);
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
	int temp = getValue(syntax[XML_ROOT_TAG]+":"+syntax[XML_CORE_TAG]+":escapeQuitsApp", false, 0);
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
	int temp = getValue(syntax[XML_ROOT_TAG]+":"+syntax[XML_CORE_TAG]+":logToFile", true, 0);
	string tempPath = getAttribute(syntax[XML_ROOT_TAG]+":"+syntax[XML_CORE_TAG]+":logToFile", "filepath", "NULL", 0);
	string tempName = getAttribute(syntax[XML_ROOT_TAG]+":"+syntax[XML_CORE_TAG]+":logToFile", "filename", "logs.txt", 0);
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
 * @param int ident
 *        The syntax array item.
 */
string ofxXmlDefaultSettings::getXmlSyntax(int ident){
	if(ident < XML_SYNTAX_SIZE){
		return syntax[ident];
	} else {
		return "";
	}
}
/**
 * @param int ident
 *        The syntax array item.
 * @param string name
 *        The new name of the syntax array item.
 */
void ofxXmlDefaultSettings::setXmlSyntax(int ident, string name){
	this->syntax[ident] = name;
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
	
	// Add the main tag and a version attribute to xml file.
	xml.addTag(syntax[XML_ROOT_TAG]);
	xml.addAttribute(syntax[XML_ROOT_TAG], "version", syntax[XML_ROOT_VERSION], 0);
	xml.addAttribute(syntax[XML_ROOT_TAG], "url", syntax[XML_ROOT_URL], 0);
	xml.pushTag(syntax[XML_ROOT_TAG], 0);
	
	// Core stuff
	xml.addTag(syntax[XML_CORE_TAG]);
	xml.pushTag(syntax[XML_CORE_TAG], 0);
	xml.addValue("frameRate", 60);
	xml.addValue("fullscreen", false);
	xml.addTag("windowShape");
	xml.addAttribute("windowShape", "width", 1024, 0);
	xml.addAttribute("windowShape", "height", 768, 0);
	xml.addTag("windowPosition");
	xml.addAttribute("windowPosition", "x", 0, 0);
	xml.addAttribute("windowPosition", "y", 44, 0);
	xml.addValue("windowTitle", "openFrameworks Application");
	xml.addValue("cursor", false);
	xml.addValue("escapeQuitsApp", false);
	xml.addValue("logToFile", true);
	xml.addAttribute("logToFile", "filepath", "NULL", 0);
	xml.addAttribute("logToFile", "filename", "logs.txt", 0);
	xml.popTag(); // End XML_TAG_OFCORE
	
	// Addons stuff
	xml.addTag(syntax[XML_ADDONS_TAG]);
	xml.pushTag(syntax[XML_ADDONS_TAG], 0);
	xml.addValue("addon", 60);
	xml.popTag(); // End XML_TAG_OFADDONS
	
	// Addons stuff
	xml.addTag(syntax[XML_CUSTOM_TAG]);
	xml.pushTag(syntax[XML_CUSTOM_TAG], 0);
	xml.addValue("custom", 60);
	xml.popTag(); // End XML_TAG_CUSTOM
	
	xml.popTag(); // End XML_TAG_MAIN
	
	xml.saveFile(filepath);
}
