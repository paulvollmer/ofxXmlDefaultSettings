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
void ofxXmlOscSettings::initSender(ofxXmlSettings XML, string host, int port){
	if(!XML.tagExists("ofxOscSender", 0)){
		XML.addTag("ofxOscSender");
		XML.pushTag("ofxOscSender", 0);
		XML.addValue("host", host);
		XML.addValue("port", port);
		XML.popTag();
		//XML.saveFile(XML.filepath);
	
		#ifdef OFXXMLOSCSETTINGS_LOG
			ofLog() << "[ofxXmlOscSettings] No XML tags found. Create ofxOscSender XML content";
		#endif
	} else {
		setSenderHost(XML, host);
		setSenderPort(XML, port);
		
		#ifdef OFXXMLOSCSETTINGS_LOG
			ofLog() << "[ofxXmlOscSettings] XML tags ok";
		#endif
	}
	
	#ifdef OFXXMLOSCSETTINGS_LOG
		ofLog() << "[ofxXmlOscSettings] Host = " << host;
		ofLog() << "[ofxXmlOscSettings] Port = " << port;
	#endif
}

/**
 * init with default values.
 * Host: 127.0.0.1
 * Port: 1234
 * @see initSender(ofxXmlDefaultSettings XML, string host, int port)
 */
void ofxXmlOscSettings::initSender(ofxXmlSettings XML){
	initSender(XML, DEFAULT_HOST, DEFAULT_PORT);
}


/**
 * Get the Host name or ip
 *
 * @param XML
 *        A xml file.
 * @return Host string
 */
string ofxXmlOscSettings::getSenderHost(ofxXmlSettings XML){
	return XML.getValue("ofxOscSender:host", DEFAULT_HOST, 0);
}

/**
 * Get the Port number
 *
 * @param XML
 *        A xml file.
 * @return Port number
 */
int ofxXmlOscSettings::getSenderPort(ofxXmlSettings XML){
	return XML.getValue("ofxOscSender:port", DEFAULT_PORT, 0);
}


/**
 * Set the Host name.
 *
 * @param XML
 *        A xml file.
 * @param host
 *        Host name or ip
 */
void ofxXmlOscSettings::setSenderHost(ofxXmlSettings XML, string host){
	XML.setValue("ofxOscSender:host", host, 0);
}

/**
 * Set the Port number
 *
 * @param XML
 *        A xml file.
 * @param port
 *        Port number
 */
void ofxXmlOscSettings::setSenderPort(ofxXmlSettings XML, int port){
	XML.setValue("ofxOscSender:port", port, 0);
}









/**
 *
 */
void ofxXmlOscSettings::initReceiver(ofxXmlSettings XML, int port){
	if(!XML.tagExists("ofxOscReceiver", 0)){
		XML.addTag("ofxOscReceiver");
		XML.pushTag("ofxOscReceiver", 0);
		XML.addValue("port", port);
		XML.popTag();
		
		#ifdef OFXXMLOSCSETTINGS_LOG
			cout << "[ofxXmlOscSettings] No XML tags found. Create ofxOscReceiver XML content" << endl;
		#endif
	} else {
		setReceiverPort(XML, port);
		#ifdef OFXXMLOSCSETTINGS_LOG
			cout << "[ofxXmlOscSettings] XML tags ok" << endl;
		#endif
	}
}

void ofxXmlOscSettings::initReceiver(ofxXmlSettings XML){
	initReceiver(XML, 1234);
}


/**
 *
 */
int ofxXmlOscSettings::getReceiverPort(ofxXmlSettings XML){
	return XML.getValue("ofxOscReceiver:port", DEFAULT_PORT, 0);
}


/**
 *
 */
void ofxXmlOscSettings::setReceiverPort(ofxXmlSettings XML, int port){
	XML.setValue("ofxOscReceiver:port", port, 0);
}
