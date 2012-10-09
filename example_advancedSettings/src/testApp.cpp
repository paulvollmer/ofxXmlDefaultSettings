//
// testApp.cpp
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

#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	/* Load the xml file from our custom path.
	 */
	XML.load("mySettings.xml");
	
	/* Set the openFrameworks app settings.
	 */
	XML.setFrameRate();
	XML.setFullscreen();
	XML.setWindowShape();
	XML.setWindowPosition();
	ofSetWindowTitle("an other title, not from default xml file.");
	ofHideCursor();
	
	
	/* Add custom settings to the xml default file.
	 * For this all used xml content need variables to store values.
	 *
	 * To read/write content from the XML.ROOT directory, you can use
	 * the pushRoot/popRoot methods.
	 */
	XML.pushRoot();
	
	/* Check if the default xml file exist at app start.
	 */
	if (XML.fileExist) {
		/* Check if <balls> tag exist and push into <balls> tag.
		 * Read the xml content.
		 */
		if (XML.tagExists("balls", 0)) {
			XML.pushTag("balls", 0);
			for (int i=0; i<=2; i++) {
				ball[i].readXml(XML, i);
			}
			XML.popTag(); // pop balls
		}
	}
	/* If no xml file exist, create the <balls> tag and add some parameter.
	 */
	else {
		/* Set the ball properties. The following parameter will be set
		 * x, y, size and the color.
		 */
		ball[0].init(200, 100, 100, ofColor::red);
		ball[1].init(100, 300, 100, ofColor::green);
		ball[2].init(300, 300, 100, ofColor::blue);
		
		XML.addTag("balls");
		XML.pushTag("balls", 0);
		for(int i=0; i<=2; i++){
			ball[i].createXml(XML, i);
		}
		XML.popTag(); // pop balls
	}

	/* Pop root xml tag.
	 */
	XML.popRoot();
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
	/* Set background color to black.
	 */
	ofBackground(ofColor::black);
	
	/* Draw the balls
	 */
	for(int i=0; i<=2; i++){
		ball[i].draw();
	}
	
	/* Draw other stuff. This is also linked to the
	 * xml parameter via Ball class.
	 */
	ofSetColor(ofColor::white);
	ofLine(ball[0].pos[0], ball[0].pos[1], ball[1].pos[0], ball[1].pos[1]);
	ofLine(ball[1].pos[0], ball[1].pos[1], ball[2].pos[0], ball[2].pos[1]);
	ofLine(ball[2].pos[0], ball[2].pos[1], ball[0].pos[0], ball[0].pos[1]);
}


//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){
	
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	/* Set the mouse x, y position to ball 1.
	 */
	ball[0].pos[0] = x;
	ball[0].pos[1] = y;
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::exit(){
	/* Push into the root tag and save the position from
	 * ball 1 to the xml file.
	 */
	XML.pushRoot();
	XML.pushTag("balls", 0);
	XML.setAttribute("ball", "x", ball[0].pos[0], 0);
	XML.setAttribute("ball", "y", ball[0].pos[1], 0);
	XML.popTag(); // pop balls
	XML.popRoot();
	
	/* Save the current settings to xml file.
	 */
	XML.save();
}
