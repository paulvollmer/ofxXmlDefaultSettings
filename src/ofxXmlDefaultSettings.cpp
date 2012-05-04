/*
 *  ofxXmlDefaultSettings.cpp
 *  Developed by Paul Vollmer, http://www.wng.cc
 *  
 *  Copyright (c) 2012 wrong-entertainment. All rights reserved.
 *  
 *  The MIT License
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
 *  @modified           2012.05.04
 *  @version            0.1.0c
 */

#include "ofxXmlDefaultSettings.h"



/**
 * This class is an extension for ofxXmlSettings to create a
 * default settings xml file. At this file we create
 * openFrameworks placeholder to store core variables like:
 * - window position,
 * - window size,
 * - framerate,
 * - fullscreen,
 * - cursor
 * Also you can use this xml to store other variables.
 */
ofxXmlDefaultSettings::ofxXmlDefaultSettings(){
	// Set our default filepath. if init() will be called, 
	// the filepath will be used to save the xml file.
	filepath = ofFilePath::getCurrentWorkingDirectory()+"/ofSettings23.xml";
}	
	
	
/**
 * init check if a default xml file exist.
 * if no file is found, let generate one.
 *
 * @param filepath
 *        Path of our default xml file.
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
			ofLog() << "                        Filepath = " << filepath;
		#endif
		createDefaultXml();
		loadFile(filepath);
	}
}

void ofxXmlDefaultSettings::load(){
	load(filepath);
}


/**
 * Save the default xml file.
 *
 * @param return
 *        Set boolean true, if file is saved.
 */
bool ofxXmlDefaultSettings::save(){
	return saveFile(filepath);
}


/**
 * Set the openFrameworks core settings from xml content.
 */
void ofxXmlDefaultSettings::setSettings(){
	setFrameRate();
	setWindowShape();
	setWindowPosition();
	setWindowTitle();
	setCursor();
	setFullscreen();
	setEscapeQuitsApp();
	//ofSetLogger
	//ofSetVerticalSync(<#bool bSync#>)
	
	#ifdef OFXXMLDEFAULTSETTINGS_LOG
		ofLog() << "[ofxXmlDefaultSettings] Set Settings from default Xml file.";
	#endif
}


void ofxXmlDefaultSettings::setFrameRate(){
	 ofSetFrameRate(getValue("ofFrameRate", 60, 0));
}

void ofxXmlDefaultSettings::setWindowShape(){
	ofSetWindowShape(getAttribute("ofWindowShape", "width", 1024, 0),
					 getAttribute("ofWindowShape", "height", 768, 0));
}

void ofxXmlDefaultSettings::setWindowPosition(){
	ofSetWindowPosition(getAttribute("ofWindowPosition", "x", 30, 0),
						getAttribute("ofWindowPosition", "x", 30, 0));
}

void ofxXmlDefaultSettings::setWindowTitle(){
	ofSetWindowTitle(getValue("ofWindowTitle", "openFrameworks Application", 0));
}

void ofxXmlDefaultSettings::setCursor(){
	int temp = getValue("ofWindowTitle", 0, 0);
	if(temp == 0){
		ofShowCursor();
	} else {
		ofHideCursor();
	}
}

void ofxXmlDefaultSettings::setFullscreen(){
	int temp = getValue("ofFullscreen", 0, 0);
	if(temp == 0){
		ofSetFullscreen(true);
	} else {
		ofSetFullscreen(false);
	}
}

void ofxXmlDefaultSettings::setEscapeQuitsApp(){
	int temp = getValue("ofEscapeQuitsApp", 0, 0);
	if(temp == 0){
		ofSetEscapeQuitsApp(true);
	} else {
		ofSetEscapeQuitsApp(false);
	}
}



/**
 * Get the openFrameworks core settings and save values to xml.
 */
void ofxXmlDefaultSettings::getSettings(){
	setValue("ofFrameRate", ofGetFrameRate(), 0);
	setAttribute("ofWindowShape", "width", ofGetWidth(), 0);
	setAttribute("ofWindowShape", "height", ofGetHeight(), 0);
	setAttribute("ofWindowPosition", "x", ofGetWindowPositionX(), 0);
	setAttribute("ofWindowPosition", "y", ofGetWindowPositionY(), 0);
	setValue("ofWindowTitle", "wng_openFrameworks", 0);
	//setValue("ofGetFullscreen", tempFullscreen, 0);
	//setValue("ofGetCursor", tempCursor, 0);
	save();
	
	#ifdef OFXXMLDEFAULTSETTINGS_LOG
		ofLog() << "[ofxXmlDefaultSettings] Get Settings to Default Xml file.";
	#endif
}


/**
 * private method
 * createDefaultXml
 *
 * we create tags to store the ofCore Settings there.
 * the tags was named like the ofGet... methods 
 * i think this looks good to use. OF syntax as xml tag :)
 */
void ofxXmlDefaultSettings::createDefaultXml(){
	ofxXmlSettings xml;
	xml.addValue("ofFrameRate", 60);
	xml.addTag("ofWindowShape");
	xml.addAttribute("ofWindowShape", "width", 1024, 0);
	xml.addAttribute("ofWindowShape", "height", 768, 0);
	xml.addTag("ofWindowPosition");
	xml.addAttribute("ofWindowPosition", "x", 30, 0);
	xml.addAttribute("ofWindowPosition", "y", 30, 0);
	xml.addValue("ofWindowTitle", "wng_openFrameworks");
	xml.addValue("ofCursor", false);
	xml.addValue("ofFullscreen", false);
	xml.addValue("ofEscapeQuitsApp", false);
	
	xml.saveFile(filepath);
	
	#ifdef OFXXMLDEFAULTSETTINGS_LOG
		ofLog() << "[ofxXmlDefaultSettings] Default xml file generated and saved!";
		ofLog() << "                        Filepath = " << filepath;
	#endif
}
