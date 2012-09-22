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
 *  @modified           2012.09.22
 *  @version            0.1.2c
 */

#ifndef _OFXXMLDEFAULTSETTINGS_H
#define _OFXXMLDEFAULTSETTINGS_H

#include "ofxXmlSettings.h"


// The total size of xml syntax elements. This value will be used by the syntay array.
#define XML_SYNTAX_SIZE 5

/**
 * The XML_SYNTAX enum is used to navigate the syntax string array.
 */
enum XML_SYNTAX {
	CORE = 0,
	CUSTOM = 1,
	ROOT = 2,
	ROOT_VERSION = 3,
	ROOT_URL = 4
};

/**
 * The CORE_SETTINGS enum is used to select a setting parameter.
 */
enum CORE_SETTINGS {
	FRAMERATE = 0,
	WINDOW_SHAPE = 1,
	WINDOW_POSITION = 2,
	WINDOW_TITLE = 3,
	CURSOR = 4,
	FULLSCREEN = 5,
	ESCAPE_QUITS_APP = 6,
	LOG = 7
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
		void load(string src);
		bool save();
		
		void setSettings();
		void setSettings(int ident);
		
		string getFilepath();
		void setFilepath(string src);
		
		string getXmlSyntax(int ident);
		void setXmlSyntax(int tag, string name);
		
		void pushRoot();
		void popRoot();
		
		string getStatusMessage();
		
		//void setSettingsActive(int ident, bool state);
	
	
	private:
		void createDefaultXml();
		string filepath;
		string statusMessage;
		string syntax[XML_SYNTAX_SIZE];
		//bool settingsActive[2];
	
};
#endif
