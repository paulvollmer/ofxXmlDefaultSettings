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
 *  @modified           2012.09.24
 *  @version            0.1.3a
 */

#include "ofxXmlDefaultSettings.h"


/**
 * Constructor
 */
ofxXmlDefaultSettings::ofxXmlDefaultSettings(){
	// Setting default filepath. if load() is called, 
	// the filepath will be used to save the xml file.
	this->filepath = ofFilePath::getCurrentWorkingDirectory()+"/ofSettings.xml";
	
 	// Set default xml syntax (names of xml tags, version and url).
	syntax[ROOT] = "ofxXmlDefaultSettings";
	syntax[ROOT_VERSION] = "0.2.0";
	syntax[ROOT_URL] = "https://github.com/wrongentertainment/ofxxmldefaultsettings";
	syntax[CORE] = "ofCore";
	
	// Set default settings values.
	defaultSettings.windowWidth = 1024;
	defaultSettings.windowHeight = 768;
	defaultSettings.windowX = 0;
	defaultSettings.windowY = 44;
	defaultSettings.windowTitle = "wng openFrameworks Application";
	defaultSettings.frameRate = 30;
	defaultSettings.fullscreen = false;
	defaultSettings.cursor = true;
	defaultSettings.escapeQuitsApp = true;
	defaultSettings.log = true;
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
 * @param src
 *        Path to default xml file.
 */
void ofxXmlDefaultSettings::load(string src){
	this->filepath = src;
	// Check if file exist
	if(loadFile(src)){
		if(getAttribute(syntax[ROOT], "version", "0", 0) == syntax[ROOT_VERSION]){
			statusMessage = "Default xml loaded!";
		} else {
			statusMessage = "Default xml loaded! Not correct file version!";
		}
	}
	else {
		statusMessage = "Unable to load xml file! Generate and save file.";;
		createDefaultXml();
		loadFile(src);
	}
}


/**
 * Get the openFrameworks core settings and save values into xml.
 *
 * @param return
 *        Set boolean true, if file is saved.
 */
bool ofxXmlDefaultSettings::save(){
	if(ofGetWindowMode() == 0){
		setAttribute(syntax[ROOT]+":"+syntax[CORE]+":window", "width", ofGetWidth(), 0);
		setAttribute(syntax[ROOT]+":"+syntax[CORE]+":window", "height", ofGetHeight(), 0);
		setAttribute(syntax[ROOT]+":"+syntax[CORE]+":window", "x", ofGetWindowPositionX(), 0);
		setAttribute(syntax[ROOT]+":"+syntax[CORE]+":window", "y", ofGetWindowPositionY(), 0);
	}
	setValue(syntax[ROOT]+":"+syntax[CORE]+":fullscreen", ofGetWindowMode(), 0);
	saveFile(filepath);
	statusMessage = "Save settings to default xml file.";
}


/**
 * Set the openFrameworks core settings from xml file.
 */
void ofxXmlDefaultSettings::setSettings(){
	setFrameRate();
	setWindowShape();
	setWindowPosition();
	setWindowTitle();
	setCursor();
	setFullscreen();
	setEscapeQuitsApp();
	setLog();
	statusMessage = "Set Settings from default xml file.";
}

/**
 * Set the window size from xml file.
 */
void ofxXmlDefaultSettings::setWindowShape(){
	ofSetWindowShape(getAttribute(syntax[ROOT]+":"+syntax[CORE]+":window", "width", defaultSettings.windowWidth, 0),
					 getAttribute(syntax[ROOT]+":"+syntax[CORE]+":window", "height", defaultSettings.windowHeight, 0));
}

/**
 * Set the window position from xml file.
 */
void ofxXmlDefaultSettings::setWindowPosition(){
	ofSetWindowPosition(getAttribute(syntax[ROOT]+":"+syntax[CORE]+":window", "x", defaultSettings.windowX, 0),
						getAttribute(syntax[ROOT]+":"+syntax[CORE]+":window", "y", defaultSettings.windowY, 0));
}

/**
 * Set the window title from xml file.
 */
void ofxXmlDefaultSettings::setWindowTitle(){
	ofSetWindowTitle(getValue(syntax[ROOT]+":"+syntax[CORE]+":window", defaultSettings.windowTitle, 0));
}

/**
 * Set the framerate from xml file.
 */
void ofxXmlDefaultSettings::setFrameRate(){
	ofSetFrameRate(getValue(syntax[ROOT]+":"+syntax[CORE]+":frameRate", defaultSettings.frameRate, 0));
}

/**
 * Set the fullscreen mode from xml file.
 */
void ofxXmlDefaultSettings::setFullscreen(){
	if(getValue(syntax[ROOT]+":"+syntax[CORE]+":fullscreen", defaultSettings.fullscreen, 0) == 0){
		ofSetFullscreen(false);
	} else {
		ofSetFullscreen(true);
	}
}

/**
 * Set the cursor mode from xml file.
 */
void ofxXmlDefaultSettings::setCursor(){
	if(getValue(syntax[ROOT]+":"+syntax[CORE]+":cursor", defaultSettings.cursor, 0) == 1){
		ofHideCursor();
	} else {
		ofShowCursor();
	}
}

/**
 * Set the ofSetEscapeQuitsApp from xml file.
 */
void ofxXmlDefaultSettings::setEscapeQuitsApp(){
	if(getValue(syntax[ROOT]+":"+syntax[CORE]+":escapeQuitsApp", defaultSettings.escapeQuitsApp, 0) == 0){
		ofSetEscapeQuitsApp(false);
	} else {
		ofSetEscapeQuitsApp(true);
	}
}

/**
 * Set the ofLogToFile from xml file.
 */
void ofxXmlDefaultSettings::setLog(){
	static string tempPath = getAttribute(syntax[ROOT]+":"+syntax[CORE]+":logToFile", "filepath", "NULL", 0);
	static string tempName = getAttribute(syntax[ROOT]+":"+syntax[CORE]+":logToFile", "filename", "logs.txt", 0);
	if(getValue(syntax[ROOT]+":"+syntax[CORE]+":logToFile", true, 0) == 1){
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
 * Get the xml filepath.
 */
string ofxXmlDefaultSettings::getFilepath(){
	return this->filepath;
}

/**
 * Set the xml filepath.
 */
void ofxXmlDefaultSettings::setFilepath(string src){
	this->filepath = src;
}


/**
 * @param int ident
 *        The syntax array item.
 * @param string name
 *        The new name of the syntax array item.
 */
void ofxXmlDefaultSettings::changeSyntax(int xmlSyntax, string name){
	this->syntax[xmlSyntax] = name;
}
/**
 * @param int ident
 *        The syntax array item.
 */
string ofxXmlDefaultSettings::getSyntax(int xmlSyntax){
	if(xmlSyntax < XML_SYNTAX_SIZE){
		return syntax[xmlSyntax];
	} else {
		return "";
	}
}

/*void ofxXmlDefaultSettings::changeDefaultSettings(int ident, int val){
	
}

void ofxXmlDefaultSettings::changeDefaultSettings(int ident, int val1, int val2){
	
}

void ofxXmlDefaultSettings::changeDefaultSettings(int ident, bool val){
	
}

void ofxXmlDefaultSettings::changeDefaultSettings(int ident, string val){
	
}*/










/**
 * Push to ROOT tag.
 */
void ofxXmlDefaultSettings::pushRoot(){
	pushTag(syntax[ROOT], 0);
}

/**
 * Pop ROOT tag.
 */
void ofxXmlDefaultSettings::popRoot(){
	popTag();
}


/**
 * Return a message set by the last method that was used.
 */
string ofxXmlDefaultSettings::getStatusMessage(){
	return this->statusMessage;
}


/**
 * Private method
 * createDefaultXml
 *
 * Creating tags to store openFrameworks core settings.
 * The tags are named like the ofGet... methods. OF syntax as xml tag :)
 */
void ofxXmlDefaultSettings::createDefaultXml(){
	ofxXmlSettings xml;
	
	// Add the root tag and a version, url attribute to xml file.
	xml.addTag(syntax[ROOT]);
	xml.addAttribute(syntax[ROOT], "version", syntax[ROOT_VERSION], 0);
	xml.addAttribute(syntax[ROOT], "url", syntax[ROOT_URL], 0);
	xml.pushTag(syntax[ROOT], 0);
	
	// Core stuff
	xml.addTag(syntax[CORE]);
	xml.pushTag(syntax[CORE], 0);
	xml.addValue("window", defaultSettings.windowTitle);
	xml.addAttribute("window", "x", defaultSettings.windowX, 0);
	xml.addAttribute("window", "y", defaultSettings.windowY, 0);
	xml.addAttribute("window", "width", defaultSettings.windowWidth, 0);
	xml.addAttribute("window", "height", defaultSettings.windowHeight, 0);
	xml.addValue("frameRate", defaultSettings.frameRate);
	xml.addValue("fullscreen", defaultSettings.fullscreen);
	xml.addValue("cursor", defaultSettings.cursor);
	xml.addValue("escapeQuitsApp", defaultSettings.escapeQuitsApp);
	xml.addValue("logToFile", defaultSettings.log);
	xml.addAttribute("logToFile", "filepath", "NULL", 0);
	xml.addAttribute("logToFile", "filename", "logs.txt", 0);
	xml.popTag(); // End CORE
	
	xml.popTag(); // End ROOT
	
	xml.saveFile(filepath);
}
