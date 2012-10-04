/**
 *  testApp.cpp is part of ofxXmlDefaultSettings.
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

#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){
	/* Set the xml tag names and root-version, -url attributes.
	 */
	XML.changeSyntax(XML.ROOT, "myApp");
	XML.changeSyntax(XML.ROOT_VERSION, "1.0alpha");
	XML.changeSyntax(XML.ROOT_URL, "http://www.wng.cc");
	XML.changeSyntax(XML.CORE, "myCore");
	
	/* Set the default Settings parameter.
	 */
	XML.defaultSettings.frameRate = 60;
	XML.defaultSettings.windowX = 200;
	XML.defaultSettings.windowY = 200;
	XML.defaultSettings.windowWidth = 600;
	XML.defaultSettings.windowHeight = 400;
	XML.defaultSettings.windowTitle = "Hello Window";
	XML.defaultSettings.cursor = false;
	XML.defaultSettings.fullscreen = false;
	XML.defaultSettings.escapeQuitsApp = true;
	XML.defaultSettings.log = true;
	
	/* Load the xml file from our custom path.
	 */
	XML.load("mySettings.xml");
	
	/* Set the openFrameworks app settings.
	 */
	XML.setWindowShape();
	XML.setWindowPosition();
	XML.setWindowTitle();
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
	/* Draw a gray background and a white rectangle above.
	 * This is not used by the ofxXmlDefaultSettings addon.
	 */
	ofBackground(ofColor::gray);
	ofFill();
	ofSetColor(ofColor::white);
	ofRect(10, 10, ofGetWidth()-20, ofGetHeight()-20);
	
	/* A small description about the example.
	 */
	ofSetColor(ofColor::black);
	ofDrawBitmapString("At this example , we want to change the root and core xml syntax.\n"
					   "Also we wil change the default settings to customize the core settings.", 20, 30);
	/* Display some information about the default xml file.
	 */
	ofDrawBitmapStringHighlight("general information", 20, 70, ofColor::gray, ofColor::white);
	ofSetColor(ofColor::black);
	ofDrawBitmapString("status message   = "+XML.getStatusMessage(), 20, 90);
	ofDrawBitmapString("filepath         = "+XML.getFilepath(), 20, 105);
	/* Return the current xml syntax with the getXmlSyntax(tag_id) method;
	 */
	ofDrawBitmapStringHighlight("xml syntax information", 20, 130, ofColor::gray, ofColor::white);
	ofSetColor(ofColor::black);
	ofDrawBitmapString("ROOT             = "+XML.getSyntax(XML.ROOT), 20, 150);
	ofDrawBitmapString("ROOT version     = "+XML.getSyntax(XML.ROOT_VERSION), 20, 165);
	ofDrawBitmapString("ROOT url         = "+XML.getSyntax(XML.ROOT_URL), 20, 180);
	ofDrawBitmapString("CORE             = "+XML.getSyntax(XML.CORE), 20, 195);
	/* Return information about the default settings paramter.
	 */
	ofDrawBitmapStringHighlight("default settings information", 20, 220, ofColor::gray, ofColor::white);
	ofSetColor(ofColor::black);
	ofDrawBitmapString("frameRate        = "+ofToString(XML.defaultSettings.frameRate), 20, 240);
	ofDrawBitmapString("window width     = "+ofToString(XML.defaultSettings.windowWidth), 20, 255);
	ofDrawBitmapString("window height    = "+ofToString(XML.defaultSettings.windowHeight), 20, 270);
	ofDrawBitmapString("window x         = "+ofToString(XML.defaultSettings.windowX), 20, 285);
	ofDrawBitmapString("window y         = "+ofToString(XML.defaultSettings.windowY), 20, 300);
	ofDrawBitmapString("window title     = "+ofToString(XML.defaultSettings.windowTitle), 20, 315);
	ofDrawBitmapString("cursor           = "+ofToString(XML.defaultSettings.cursor), 20, 330);
	ofDrawBitmapString("fullscreen       = "+ofToString(XML.defaultSettings.fullscreen), 20, 345);
	ofDrawBitmapString("log              = "+ofToString(XML.defaultSettings.log), 20, 360);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	
}

//--------------------------------------------------------------
void testApp::exit(){
	/* Save the current settings to xml file.
	 */
	XML.save();
	cout << "STATUS: " << XML.getStatusMessage() << endl;
}
