/**
 *  ofxXmlDefaultSettings
 *
 *  
 *  The MIT License
 *
 *  Copyright (c) 2012 Paul Vollmer, http://www.wng.cc
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
 *  @testet_oF          0071
 *  @testet_plattform   MacOs 10.6+
 *                      ??? Win
 *                      ??? Linux
 *  @dependencies       ofxXmlSettings
 *  @modified           2012.07.02
 *  @version            0.1.2
 */

#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	// See "example_default"
	defXML.load();
	defXML.setSettings();
	
	
	// Initialize osc sender addon settings.
	defXMLosc.initSender(defXML);
	// or initialize with host and port variables
	//defXMLosc.initSender(defXML, "127.0.0.101", 9000);
	
	sender.setup(defXMLosc.getSenderHost(defXML),
				 defXMLosc.getSenderPort(defXML));
	
	// change the osc sender settings variable.
	/*defXMLosc.setSenderHost(defXML, "90.60.90.0");
	defXMLosc.setSenderPort(defXML, 12345);
	cout << "Sender Host = " << defXMLosc.getSenderHost(defXML) << endl;
	cout << "Sender Port = " << defXMLosc.getSenderPort(defXML) << endl;*/
	
	
	
	// Initialize osc sender addon settings.
	defXMLosc.initReceiver(defXML);
	
	receiver.setup(defXMLosc.getReceiverPort(defXML));
	
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
	
	// See "example_default"
	defXML.saveSettings();
	
}
