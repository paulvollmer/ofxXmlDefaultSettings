/*
 *  ofxXmlDefaultSettings.cpp
 *  Created by Paul Vollmer, http://www.wng.cc
 *  
 *  Copyright (c) 2012 openFrameworks. All rights reserved.
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
 *  @modified           2012.05.02
 *  @version            0.1.0b
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
	// Set our default filename.
	// if init(string filename) will be called, 
	// the string set to new name.
	filename = "ofCoreSettings.xml";
}
	
	
	
/**
 * init
 * check if a default xml file exist.
 * if not, generate one.
 *
 * @param filename
 *        Name of our default xml file.
 */
void ofxXmlDefaultSettings::init(string filename){
	this->filename = filename;
	if(load()){
		#ifdef OFXXMLDEFAULTSETTINGS_LOG
			ofLog() << "[ofxXmlDefaultSettings] Default XML loaded!";
		#endif
	} else {
		#ifdef OFXXMLDEFAULTSETTINGS_LOG
			ofLog() << "[ofxXmlDefaultSettings] Unable to load Default XML. create a default XML file!";
		#endif
		createDefaultXml();
		load();
	}
}

void ofxXmlDefaultSettings::init(){
	init(filename);
}



/**
 * L	oad the default xml file.
 */
bool ofxXmlDefaultSettings::load(){
	return loadFile(ofFilePath::getCurrentWorkingDirectory()+"/"+filename);
}


/**
 * save
 */
bool ofxXmlDefaultSettings::save(){
	return saveFile(ofFilePath::getCurrentWorkingDirectory()+"/"+filename);
}


/**
 * setSettings
 * set the openFrameworks core settings from xml content.
 */
void ofxXmlDefaultSettings::setSettings(){
	//ofSetLogger
	//ofSetVerticalSync(<#bool bSync#>)
	ofSetFrameRate(getValue("ofFrameRate", 60, 0));
	//ofSetWindowShape(getValue("ofWidth", 1024, 0), getValue("ofHeight", 768, 0));
	ofSetWindowPosition(getValue("ofWindowPositionX", 30, 0), getValue("ofWindowPositionY", 30, 0));
	ofSetWindowTitle(getValue("ofWindowTitle", "wng_openFrameworks", 0));
	/*ofShowCursor() ofHideCursor()
	ofSetFullscreen(<#bool fullscreen#>)
	ofSetEscapeQuitsApp(<#bool bQuitOnEsc#>)*/
	
	ofLog() << "[ofxXmlDefaultSettings] Set Settings from default Xml file.";
}


/**
 * getSettings
 * get the openFrameworks core settings.
 * save to xml.
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
	ofLog() << "[ofxXmlDefaultSettings] Get Settings to Default Xml file.";
}


/**
 * private method
 * createDefaultXml
 *
 * we create tags to store the ofCore Settings there.
 * the tags i named like the ofGet... methods 
 * i think this looks good to use. OF syntax as xml tag :) 
 */
void ofxXmlDefaultSettings::createDefaultXml(){
	ofxXmlSettings xml;
	xml.addValue("ofFrameRate", 60);
	xml.addTag("ofWindowShape");
	xml.addAttribute("ofWindowShape", "width", 1024, 0);
	xml.addAttribute("ofWindowShape", "height", 1024, 0);
	xml.addTag("ofWindowPosition");
	xml.addAttribute("ofWindowPosition", "x", 30, 0);
	xml.addAttribute("ofWindowPosition", "y", 30, 0);
	xml.addValue("ofWindowTitle", "wng_openFrameworks");
	xml.addValue("ofFullscreen", false);
	xml.addValue("ofCursor", false);
	
	xml.saveFile(ofFilePath::getCurrentWorkingDirectory()+"/"+filename);
	ofLog() << "[ofxXmlDefaultSettings] Default content generated and Xml file saved!";
}
