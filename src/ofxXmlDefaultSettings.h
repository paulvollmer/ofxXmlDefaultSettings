/**
 *  ofxXmlDefaultSettings.h is part of ofxXmlDefaultSettings.
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

#ifndef _OFXXMLDEFAULTSETTINGS_H
#define _OFXXMLDEFAULTSETTINGS_H

#include "ofxXmlSettings.h"


// The total size of xml syntax elements. This value will be used by the syntay array.
#define XML_SYNTAX_SIZE 6

/**
 * The XML_SYNTAX enum is used to navigate the syntax string array.
 */
enum XML_SYNTAX {
	XML_MAIN_TAG = 0,
	XML_MAIN_VERSION = 1,
	XML_MAIN_URL = 2,
	XML_CORE_TAG = 3,
	XML_ADDONS_TAG = 4,
	XML_CUSTOM_TAG = 5
};


/**
 * This is our base class.
 * with this class we create a default xml file with default content.
 * From this defaul file we grab our setting values.
 */
class ofxXmlDefaultSettings : public ofxXmlSettings {
	
	public:
		ofxXmlDefaultSettings();
		
		void load();
		void load(string filepath);
		bool saveSettings();
	
		void setSettings();
		void setFrameRate();
		void setWindowShape();
		void setWindowPosition();
		void setWindowTitle();
		void setCursor();
		void setFullscreen();
		void setEscapeQuitsApp();
		void setLogToFile();
	
		string getXmlSyntax(int ident);
		void setXmlSyntax(int tag, string name);
	
		string statusMessage;
		string filepath;
	
	
	private:
		void createDefaultXml();
		string syntax[XML_SYNTAX_SIZE];
	
};
#endif
