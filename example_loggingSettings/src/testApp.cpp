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
	/* Set the logging parameter.
	 */
	XML.defaultSettings.log = true;
	/* The filepath to save the log file.
	 */
	XML.defaultSettings.logFilepath = "myLogDirectory";
	/* The filename of the log file.
	 */
	XML.defaultSettings.logFilename = "myLogs.txt";
	
	/* Load the xml file from our custom path.
	 */
	XML.load("mySettings.xml");
	
	/* Set the openFrameworks app settings.
	 */
	XML.setSettings();
	/* Log the XML status message.
	 */
	ofLog() << "XML STATUS: " << XML.getStatusMessage() << "\n---------------------------------------";
	
	/* Small example of the other log levels.
	 */
	ofLog(OF_LOG_VERBOSE) << "Log Level 'OF_LOG_VERBOSE'";
	ofLog(OF_LOG_NOTICE) << "Log Level 'OF_LOG_NOTICE'";
	ofLog(OF_LOG_WARNING) << "Log Level 'OF_LOG_WARNING'";
	ofLog(OF_LOG_ERROR) << "Log Level 'OF_LOG_WARNING'";
	ofLog(OF_LOG_FATAL_ERROR) << "Log Level 'OF_LOG_FATAL_ERROR'";
	ofLog(OF_LOG_SILENT) << "Log Level 'OF_LOG_SILENT'";
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
}
