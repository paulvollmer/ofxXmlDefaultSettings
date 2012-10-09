//
// ofxXmlDefaultSettings.cpp
// ofxXmlDefaultSettings is released under the MIT License.
//
// Copyright (c) 2012, Paul Vollmer http://www.wrong-entertainment.com
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//

#include "ofxXmlDefaultSettings.h"


ofxXmlDefaultSettings::ofxXmlDefaultSettings() {
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
	defaultSettings.windowTitle = "openFrameworks Application";
	defaultSettings.frameRate = 60;
	defaultSettings.fullscreen = false;
	defaultSettings.cursor = true;
	defaultSettings.escapeQuitsApp = true;
	defaultSettings.log = true;
	defaultSettings.logFilepath = "default";
	defaultSettings.logFilename = "logs.txt";
}


void ofxXmlDefaultSettings::load() {
	load(filepath);
}


void ofxXmlDefaultSettings::load(string src) {
	this->filepath = src;
	// Check if file exist
	if (loadFile(src)) {
		if (getAttribute(syntax[ROOT], "version", "0", 0) == syntax[ROOT_VERSION]) {
			fileExist = true;
			statusMessage = "Default xml loaded!";
		} else {
			fileExist = false;
			statusMessage = "Default xml loaded! Not correct file version!";
		}
	}
	else {
		fileExist = false;
		statusMessage = "Unable to load xml file! Generate and save file.";;
		createDefaultXml();
		loadFile(src);
	}
}


bool ofxXmlDefaultSettings::save() {
	if(ofGetWindowMode() == 0) {
		setAttribute(syntax[ROOT]+":"+syntax[CORE]+":window", "width", ofGetWidth(), 0);
		setAttribute(syntax[ROOT]+":"+syntax[CORE]+":window", "height", ofGetHeight(), 0);
		setAttribute(syntax[ROOT]+":"+syntax[CORE]+":window", "x", ofGetWindowPositionX(), 0);
		setAttribute(syntax[ROOT]+":"+syntax[CORE]+":window", "y", ofGetWindowPositionY(), 0);
	}
	setValue(syntax[ROOT]+":"+syntax[CORE]+":fullscreen", ofGetWindowMode(), 0);
	saveFile(filepath);
	statusMessage = "Save settings to default xml file.";
}


void ofxXmlDefaultSettings::setSettings() {
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


void ofxXmlDefaultSettings::setWindowShape() {
	ofSetWindowShape(getAttribute(syntax[ROOT]+":"+syntax[CORE]+":window", "width", defaultSettings.windowWidth, 0),
					 getAttribute(syntax[ROOT]+":"+syntax[CORE]+":window", "height", defaultSettings.windowHeight, 0));
}


void ofxXmlDefaultSettings::setWindowPosition() {
	ofSetWindowPosition(getAttribute(syntax[ROOT]+":"+syntax[CORE]+":window", "x", defaultSettings.windowX, 0),
						getAttribute(syntax[ROOT]+":"+syntax[CORE]+":window", "y", defaultSettings.windowY, 0));
}


void ofxXmlDefaultSettings::setWindowTitle() {
	ofSetWindowTitle(getValue(syntax[ROOT]+":"+syntax[CORE]+":window", defaultSettings.windowTitle, 0));
}


void ofxXmlDefaultSettings::setFrameRate() {
	ofSetFrameRate(getValue(syntax[ROOT]+":"+syntax[CORE]+":frameRate", defaultSettings.frameRate, 0));
}


void ofxXmlDefaultSettings::setFullscreen() {
	if (getValue(syntax[ROOT]+":"+syntax[CORE]+":fullscreen", defaultSettings.fullscreen, 0) == 0) {
		ofSetFullscreen(false);
	} else {
		ofSetFullscreen(true);
	}
}


void ofxXmlDefaultSettings::setCursor() {
	if (getValue(syntax[ROOT]+":"+syntax[CORE]+":cursor", defaultSettings.cursor, 0) == 1) {
		ofHideCursor();
	} else {
		ofShowCursor();
	}
}


void ofxXmlDefaultSettings::setEscapeQuitsApp() {
	if (getValue(syntax[ROOT]+":"+syntax[CORE]+":escapeQuitsApp", defaultSettings.escapeQuitsApp, 0) == 0) {
		ofSetEscapeQuitsApp(false);
	} else {
		ofSetEscapeQuitsApp(true);
	}
}


void ofxXmlDefaultSettings::setLog() {
	static string tempPath = getAttribute(syntax[ROOT]+":"+syntax[CORE]+":logToFile", "filepath",defaultSettings.logFilepath, 0);
	static string tempName = getAttribute(syntax[ROOT]+":"+syntax[CORE]+":logToFile", "filename", defaultSettings.logFilename, 0);
	if (getValue(syntax[ROOT]+":"+syntax[CORE]+":logToFile", true, 0) == 1) {
		// If the filepath attribute is "default", 
		// we run the default method and save the log file to current working directory.
		if (tempPath == "default") {
			// check if a logs folder exist.
			// if no folder found, create one.
			ofDirectory dir(ofFilePath::getCurrentWorkingDirectory()+"/logs");
			if (!dir.exists()) {
				dir.create(true);
			}
			ofLogToFile(ofFilePath::getCurrentWorkingDirectory()+"/logs/"+ofGetTimestampString()+"_"+tempName, 1);
		} else {
			ofLogToFile(tempPath+"/"+tempName, 1);
		}
	}
}


string ofxXmlDefaultSettings::getFilepath() {
	return this->filepath;
}


void ofxXmlDefaultSettings::setFilepath(string src) {
	this->filepath = src;
}


void ofxXmlDefaultSettings::changeSyntax(int xmlSyntax, string name) {
	this->syntax[xmlSyntax] = name;
}


string ofxXmlDefaultSettings::getSyntax(int xmlSyntax) {
	if (xmlSyntax < XML_SYNTAX_SIZE) {
		return syntax[xmlSyntax];
	} else {
		return "";
	}
}


void ofxXmlDefaultSettings::pushRoot() {
	pushTag(syntax[ROOT], 0);
}


void ofxXmlDefaultSettings::popRoot() {
	popTag();
}


string ofxXmlDefaultSettings::getStatusMessage() {
	return this->statusMessage;
}


// Private method -- createDefaultXml
// Creating tags to store openFrameworks core settings.
void ofxXmlDefaultSettings::createDefaultXml() {
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
	xml.addAttribute("logToFile", "filepath", defaultSettings.logFilepath, 0);
	xml.addAttribute("logToFile", "filename", defaultSettings.logFilename, 0);
	xml.popTag(); // End CORE
	
	xml.popTag(); // End ROOT
	
	xml.saveFile(filepath);
}
