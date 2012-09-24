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
 *  @modified           2012.09.24
 *  @version            0.1.3a
 */

#ifndef _OFXXMLDEFAULTSETTINGS_H
#define _OFXXMLDEFAULTSETTINGS_H

#include "ofxXmlSettings.h"


/**
 * The XML_SYNTAX enum is used to navigate the syntax string array.
 */
enum XML_SYNTAX {
	ROOT = 0,
	ROOT_VERSION = 1,
	ROOT_URL = 2,
	CORE = 3
};
// The total size of xml syntax elements. This value will be used by the syntay array.
#define XML_SYNTAX_SIZE 4

/**
 * The DefaultSettings struct is used to change the setting parameter.
 */
struct DefaultSettings {
	int frameRate;
	int windowWidth;
	int windowHeight;
	int windowX;
	int windowY;
	string windowTitle;
	bool cursor;
	bool fullscreen;
	bool escapeQuitsApp;
	bool log;
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
		void setFrameRate();
		void setWindowShape();
		void setWindowPosition();
		void setWindowTitle();
		void setCursor();
		void setFullscreen();
		void setEscapeQuitsApp();
		void setLog();
	
		string getFilepath();
		void setFilepath(string src);
		
		void changeSyntax(int xmlSyntax, string name);
		string getSyntax(int xmlSyntax);
	
		/*void changeDefaultSettings(int ident, int val);
		void changeDefaultSettings(int ident, int val1, int val2);
		void changeDefaultSettings(int ident, bool val);
		void changeDefaultSettings(int ident, string val);*/
		DefaultSettings defaultSettings;
	
	
	
		void pushRoot();
		void popRoot();
		
		string getStatusMessage();
	
		//void ofxXmlDefaultSettings::setSettingsActive(int ident, bool state){
		//settingsActive[ident] = state;
	
	
	private:
		void createDefaultXml();
		string filepath;
		string statusMessage;
		string syntax[XML_SYNTAX_SIZE];
		
};
#endif
