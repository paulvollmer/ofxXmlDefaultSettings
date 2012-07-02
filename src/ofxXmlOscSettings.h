/**
 *  ofxXmlDefaultSettings.h
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

#ifndef _OFXXMLOSCSETTINGS
#define _OFXXMLOSCSETTINGS

#include "ofxXmlSettings.h"

// If "OFXXMLOSCSETTINGS_LOG" is defined, the addon prints out ofLog messages.
#define OFXXMLOSCSETTINGS_LOG

#define DEFAULT_HOST "localhost"
#define DEFAULT_PORT 12345





/**
 * This is our ofxOsc addon settigs class.
 * We can init, get and set values.
 */
class ofxXmlOscSettings : public ofxXmlSettings {
	
	public:
		ofxXmlOscSettings();
	
	
		// Sender
		void initSender(ofxXmlSettings XML, string host, int port);
		void initSender(ofxXmlSettings XML);
	
		string getSenderHost(ofxXmlSettings XML);
		int getSenderPort(ofxXmlSettings XML);
	
		void setSenderHost(ofxXmlSettings XML, string h);
		void setSenderPort(ofxXmlSettings XML, int p);
	
	
		// Receiver
		void initReceiver(ofxXmlSettings XML, int port);
		void initReceiver(ofxXmlSettings XML);
	
		int getReceiverPort(ofxXmlSettings XML);
	
		void setReceiverPort(ofxXmlSettings XML, int port);
	
	
};

#endif
