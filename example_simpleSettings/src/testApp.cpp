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
 *  @modified           2012.09.20
 *  @version            0.1.2b
 */

#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){
	/* Load the xml file from default path.
	 */
	XML.load();
	
	/* Get a status message from last method.
	 */
	cout << "STATUS: " << XML.getStatusMessage() << endl;
	
	/* Set the openFrameworks app settings.
	 */
	XML.setSettings();
	cout << "STATUS: " << XML.getStatusMessage() << endl;
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
	/* Draw a gray ground and a white rectangle.
	 */
	ofBackground(ofColor::gray);
	ofFill();
	ofSetColor(ofColor::white);
	ofRect(20, 20, ofGetWidth()-40, ofGetHeight()-40);
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
