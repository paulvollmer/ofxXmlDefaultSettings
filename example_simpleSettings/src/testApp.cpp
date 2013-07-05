//
// testApp.cpp
// ofxXmlDefaultSettings is released under the MIT License.
//
// Copyright (c) 2012-2013, Paul Vollmer http://www.wrong-entertainment.com
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
	ofDrawBitmapString("This is a simple ofxXmlDefaultSettigs addon example. The simple example\n"
					   "create a default xml file with default openFrameworks settings.", 20, 30);
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
