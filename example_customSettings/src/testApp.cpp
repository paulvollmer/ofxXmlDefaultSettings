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
 *  @version            0.1.2c
 */

#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){
	/* Set the xml tag names and version, url root attributes.
	 */
	XML.setXmlSyntax(ROOT, "myApp");
	XML.setXmlSyntax(ROOT_VERSION, "1.0alpha");
	XML.setXmlSyntax(ROOT_URL, "http://www.wng.cc");
	XML.setXmlSyntax(CORE, "myCore");
	XML.setXmlSyntax(CUSTOM, "myCustom");
	/* Return the current syntax. with getXmlSyntax(tag_id);
	 */
	cout << "ROOT         = " << XML.getXmlSyntax(ROOT) << endl;
	cout << "ROOT_VERSION = " << XML.getXmlSyntax(ROOT_VERSION) << endl;
	cout << "ROOT_URL     = " << XML.getXmlSyntax(ROOT_URL) << endl;
	cout << "CORE         = " << XML.getXmlSyntax(CORE) << endl;
	cout << "CUSTOM       = " << XML.getXmlSyntax(CUSTOM) << endl;
	
	/* Load the xml file from our custom path.
	 */
	XML.load("test.xml");
	
	/* Set the openFrameworks app settings.
	 */
	XML.setSettings(WINDOW_SHAPE);
	XML.setSettings(WINDOW_POSITION);
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
	
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
