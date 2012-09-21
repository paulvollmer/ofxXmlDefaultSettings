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
	
	/* Set the xml tag names and version, url root attributes.
	 */
	defXML.setXmlSyntax(XML_ROOT_VERSION, "1.0alpha");
	defXML.setXmlSyntax(XML_ROOT_URL, "http://www.wng.cc");
	defXML.setXmlSyntax(XML_ROOT_TAG, "myApp");
	defXML.setXmlSyntax(XML_CORE_TAG, "myCore");
	defXML.setXmlSyntax(XML_ADDONS_TAG, "myAddons");
	defXML.setXmlSyntax(XML_CUSTOM_TAG, "myCustom");
	
	/* Return the current syntax. with getXmlSyntax(tag_id);
	 */
	cout << "XML_ROOT_VERSION     = " << defXML.getXmlSyntax(XML_ROOT_VERSION) << endl;
	cout << "XML_ROOT_URL         = " << defXML.getXmlSyntax(XML_ROOT_URL) << endl;
	cout << "XML_ROOT_TAG    = " << defXML.getXmlSyntax(XML_ROOT_TAG) << endl;
	cout << "XML_CORE_TAG    = " << defXML.getXmlSyntax(XML_CORE_TAG) << endl;
	cout << "XML_ADDONS_TAG  = " << defXML.getXmlSyntax(XML_ADDONS_TAG) << endl;
	cout << "XML_CUSTOM_TAG  = " << defXML.getXmlSyntax(XML_CUSTOM_TAG) << endl;
	
	
	/* Load our default xml file.
	 */
	defXML.load();
	
	/* Get a status message
	 */
	cout << "STATUS: " << defXML.statusMessage << endl;
	
	/* and set the openFrameworks core settings from it.
	 */
	defXML.setSettings();
	cout << "STATUS: " << defXML.statusMessage << endl;
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
		case 'f':
			ofToggleFullscreen();
			break;
		default:
			break;
	}
}

//--------------------------------------------------------------
void testApp::exit(){
	/* Save the current settings to xml.
	 */
	defXML.saveSettings();
	cout << "STATUS: " << defXML.statusMessage << endl;
}
