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
 *  @modified           2012.09.22
 *  @version            0.1.2b
 */

#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	/* Load the xml file from default path.
	 */
	XML.load("mySettings.xml");
	
	/* Set the openFrameworks app settings.
	 */
	XML.setSettings(FRAMERATE);
	XML.setSettings(FULLSCREEN);
	XML.setSettings(WINDOW_SHAPE);
	XML.setSettings(WINDOW_POSITION);
	ofSetWindowTitle("an other title, not from default xml file.");
	
	
	/* Add custom settings to the xml default file.
	 */
	int tempVar1, tempVar2, tempVar3;
	/* Push into root xml tag.
	 */
	XML.pushRoot();
	if(XML.tagExists("wng", 0)) {
		tempVar1 = XML.getValue("wng:myVar1", 0, 0);
		tempVar2 = XML.getValue("wng:myVar2", 0, 0);
		tempVar3 = XML.getValue("wng:myVar3", 0, 0);
	} else {
		/* if no default parameter exist, let create some.
		 */
		tempVar1 = 100;
		tempVar2 = 200;
		tempVar3 = 300;
		XML.addTag("wng");
		XML.pushTag("wng", 0);
		XML.addValue("myVar1", tempVar1);
		XML.addValue("myVar2", tempVar2);
		XML.addValue("myVar3", tempVar3);
		XML.popTag();
		XML.popRoot();
	}
	/* Pop root xml tag.
	 */
	XML.popRoot();
	
	ofLog() << "tempVar1 = " << tempVar1;
	ofLog() << "tempVar2 = " << tempVar2;
	ofLog() << "tempVar3 = " << tempVar3;
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	switch (key) {
		/* If key 'f' is pressed, toggle fullscreen mode.
		 */
		case 'f':
			ofToggleFullscreen();
			break;
	}
}

//--------------------------------------------------------------
void testApp::exit(){
	/* Save the current settings to xml file.
	 */
	XML.save();
	cout << "STATUS: " << XML.getStatusMessage() << endl;
}
