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
 *  @modified           2012.09.22
 *  @version            0.1.2c
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
	setSettings(FRAMERATE);
	setSettings(WINDOW_SHAPE);
	setSettings(WINDOW_POSITION);
	setSettings(WINDOW_TITLE);
	setSettings(CURSOR);
	setSettings(FULLSCREEN);
	setSettings(ESCAPE_QUITS_APP);
	setSettings(LOG);
	statusMessage = "Set Settings from default xml file.";
}

/**
 * FRAMERATE
 *    Set the framerate from xml file.
 * WINDOW_SHAPE
 *    Set the window size from xml file.
 * WINDOW_POSITION
 *    Set the window position from xml file.
 * WINDOW_TITLE
 *    Set the window title from xml file.
 * CURSOR
 *    Set the cursor mode from xml file.
 * FULLSCREEN
 *    Set the fullscreen mode from xml file.
 * ESCAPE_QUITS_APP
 *    Set the ofSetEscapeQuitsApp from xml file.
 * LOG
 *    Set the ofLogToFile from xml file.
 */
void ofxXmlDefaultSettings::setSettings(int ident){
	switch (ident) {
		case FRAMERATE:
			ofSetFrameRate(getValue(syntax[ROOT]+":"+syntax[CORE]+":frameRate", 60, 0));
			break;
			
		case WINDOW_SHAPE:
			ofSetWindowShape(getAttribute(syntax[ROOT]+":"+syntax[CORE]+":window", "width", 1024, 0),
							 getAttribute(syntax[ROOT]+":"+syntax[CORE]+":window", "height", 768, 0));
			break;
		
		case WINDOW_POSITION:
			ofSetWindowPosition(getAttribute(syntax[ROOT]+":"+syntax[CORE]+":window", "x", 30, 0),
								getAttribute(syntax[ROOT]+":"+syntax[CORE]+":window", "y", 30, 0));
			break;
		
		case WINDOW_TITLE:
			ofSetWindowTitle(getValue(syntax[ROOT]+":"+syntax[CORE]+":window", "openFrameworks Application", 0));
			break;
		
		case CURSOR:
			if(getValue(syntax[ROOT]+":"+syntax[CORE]+":cursor", false, 0) == 1){
				ofHideCursor();
			} else {
				ofShowCursor();
			}
			break;
		
		case FULLSCREEN:
			if(getValue(syntax[ROOT]+":"+syntax[CORE]+":fullscreen", false, 0) == 0){
				ofSetFullscreen(false);
			} else {
				ofSetFullscreen(true);
			}
			break;
		
		case ESCAPE_QUITS_APP:	
			if(getValue(syntax[ROOT]+":"+syntax[CORE]+":escapeQuitsApp", false, 0) == 0){
				ofSetEscapeQuitsApp(false);
			} else {
				ofSetEscapeQuitsApp(true);
			}
			break;
		
		case LOG:
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
			break;
		
		default:
			cout << "failed" << endl;
			break;
	}
}


/**
 *
 */
string ofxXmlDefaultSettings::getFilepath(){
	return this->filepath;
}

/**
 *
 */
void ofxXmlDefaultSettings::setFilepath(string src){
	this->filepath = src;
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

void ofxXmlDefaultSettings::pushRoot(){
	pushTag(syntax[ROOT], 0);
}

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
 * @param int ident
 * @param bool state
 *
 void ofxXmlDefaultSettings::setSettingsActive(int ident, bool state){
 settingsActive[ident] = state;
 }*/



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
	xml.addValue("frameRate", 60);
	xml.addValue("fullscreen", false);
	xml.addValue("window", "openFrameworks Application");
	xml.addAttribute("window", "x", 0, 0);
	xml.addAttribute("window", "y", 44, 0);
	xml.addAttribute("window", "width", 1024, 0);
	xml.addAttribute("window", "height", 768, 0);
	xml.addValue("cursor", false);
	xml.addValue("escapeQuitsApp", false);
	xml.addValue("logToFile", true);
	xml.addAttribute("logToFile", "filepath", "NULL", 0);
	xml.addAttribute("logToFile", "filename", "logs.txt", 0);
	xml.popTag(); // End CORE
	
	xml.popTag(); // End ROOT
	
	xml.saveFile(filepath);
}
