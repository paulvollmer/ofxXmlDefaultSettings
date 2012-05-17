/**
 *  ofxXmlDefaultSettings.cpp
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
 *  @testet_oF          0.07
 *  @testet_plattform   MacOs 10.6
 *                      ??? Win
 *                      ??? Linux
 *  @dependencies       ofxXmlSettings
 *  @modified           2012.05.17
 *  @version            0.1.1
 */

#include "ofxXmlOscSettings.h"



/**
 * Constructor
 */
ofxXmlOscSettings::ofxXmlOscSettings(){}


/**
 * Check if a ofxOscSender tag exist.
 * If no tag found, create a default xml structure.
 *
 * @param XML
 *        A xml file.
 * @param host
 *        Host name or ip
 * @param port
 *        Port number
 */
void ofxXmlOscSettings::initSender(ofxXmlDefaultSettings XML, string host, int port){
	if(!XML.tagExists("ofxOsc", 0)){
		XML.addTag("ofxOsc");
		XML.pushTag("ofxOsc", 0);
		XML.addValue("host", host);
		XML.addValue("port", port);
		XML.popTag();
		XML.saveFile(XML.filepath);
	
		#ifdef OFXXMLDEFAULTSETTINGS_LOG
			cout << "Create osc tags" << endl;
		#endif
	} else {
		#ifdef OFXXMLDEFAULTSETTINGS_LOG
			cout << "OK" << endl;
		#endif
	}
}

/**
 * init with default values.
 * Host: 127.0.0.1
 * Port: 1234
 * @see initSender(ofxXmlDefaultSettings XML, string host, int port)
 */
void ofxXmlOscSettings::initSender(ofxXmlDefaultSettings XML){
	initSender(XML, "127.0.0.1", 1234);
}


/**
 * Get the Host name or ip
 *
 * @param XML
 *        A xml file.
 * @return Host string
 */
string ofxXmlOscSettings::getSenderHost(ofxXmlDefaultSettings XML){
	return XML.getValue("ofxOsc:host", "127.0.0.1", 0);
}

/**
 * Get the Port number
 *
 * @param XML
 *        A xml file.
 * @return Port number
 */
int ofxXmlOscSettings::getSenderPort(ofxXmlDefaultSettings XML){
	return XML.getValue("ofxOsc:port", 8000, 0);
}


/**
 * Set the Host name.
 *
 * @param XML
 *        A xml file.
 * @param host
 *        Host name or ip
 */
void ofxXmlOscSettings::setSenderHost(ofxXmlDefaultSettings XML, string host){
	XML.setValue("ofxOsc::host", host, 0);
}

/**
 * Set the Port number
 *
 * @param XML
 *        A xml file.
 * @param port
 *        Port number
 */
void ofxXmlOscSettings::setSenderPort(ofxXmlDefaultSettings XML, int port){
	XML.setValue("ofxOsc::port", port, 0);
}
