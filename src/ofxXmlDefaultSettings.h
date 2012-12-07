//
// ofxXmlDefaultSettings.h
// ofxXmlDefaultSettings is released under the MIT License.
//
// Copyright (c) 2012, Paul Vollmer http://www.wrong-entertainment.com
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

#ifndef INCLUDED_OFXXMLDEFAULTSETTINGS_H
#define INCLUDED_OFXXMLDEFAULTSETTINGS_H

/**
 * The current version of the ofxXmlDefaultSettings addon.
 */
#define OFXXMLDEFAULTSETTINGS_VERSION "0.2.0b"

#include "ofxXmlSettings.h"

/**
 * @mainpage
 * @tableofcontents
 * @author      Paul Vollmer <paul.vollmer@fh-potsdam.de><br>
 *              wrong-entertainment.com
 * @date        2012.12.07
 * @version     0.2.0b
 * @copyright   <a href="http://opensource.org/licenses/MIT">MIT License</a>
 * 
 * @section GeneralInformation General Information
 * <div><table>
 *   <tr><td>tested openFrameworks version</td><td>0073</td></tr>
 *   <tr><td>tested plattform MacOs</td><td>10.6, 10.7</td></tr>
 *   <tr><td>tested plattform Win</td><td>?</td></tr>
 *   <tr><td>tested plattform Linux</td><td>?</td></tr>
 *   <tr><td>dependencies</td><td>ofxXmlSettings</td></tr>
 * </table></div>
 * <br>
 * This openFrameworks addon create a default xml file to store openFrameworks
 * settings like of ofSetFrameRate, ofSetWindowShape etc. The addon check, if a
 * xml file exist to decide whether a file should be created or imported.
 * If no file is found, the addon generate a default file and loads this one. You
 * can found more information about the default parameter at the @ref ofxXmlDefaultSettings
 * constructor and the @ref xmlfile.
 *
 * @section xmlfile XML file
 * A sample of the generated XML file.
 * <pre>
 * <ofxXmlDefaultSettings version="0.2.0b" url="https://github.com/wrongentertainment/ofxxmldefaultsettings">
 *   <ofCore>
 *     <frameRate>60</frameRate>
 *     <fullscreen>0</fullscreen>
 *     <window x="0" y="44" width="1024" height="768">openFrameworks Application</window>
 *     <cursor>1</cursor>
 *     <escapeQuitsApp>1</escapeQuitsApp>
 *     <logToFile filepath="NULL" filename="logs.txt">1</logToFile>
 *   </ofCore>
 * </ofxXmlDefaultSettings> 
 * </pre>
 *
 * @section license License
 * <b>MIT License</b>
 * <pre>
 * Copyright (c) 2012, Paul Vollmer http://www.wrong-entertainment.com
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 * </pre>
 */
class ofxXmlDefaultSettings : public ofxXmlSettings {	
public:
	/**
	 * The default constructor set different attributes like the filepath,
	 * xml syntax and the DefaultSettings.
	 * The default filepath:
	 *  <table>
	 *   <tr><td>filepath mac</td><td>.app/Contents/MacOS/ofSettings.xml</td></tr>
	 *   <tr><td>filepath win</td><td>???</td></tr>
	 *   <tr><td>filepath linux</td><td>???</td></tr>
	 * </table>
	 * The default xml syntax:
	 * <table>
	 *   <tr><td>ROOT</td><td>&lt;ofxXmlDefaultSettings&gt;</td></tr>
	 *   <tr><td>ROOT_VERSION</td><td>0.2.0b</td></tr>
	 *   <tr><td>ROOT_URL</td><td>https://github.com/wrongentertainment/ofxxmldefaultsettings</td></tr>
	 *   <tr><td>CORE</td><td>&lt;ofCore&gt;</td></tr>
	 * </table>
	 * The DefaultSettings parameter:
	 * <table>
	 *   <tr><td>windowWidth</td><td>1024</td></tr>
	 *   <tr><td>windowHeight</td><td>768</td></tr>
	 *   <tr><td>windowX</td><td>0</td></tr>
	 *   <tr><td>windowY</td><td>44</td></tr>
	 *   <tr><td>windowTitle</td><td>openFrameworks Application</td></tr>
	 *   <tr><td>frameRate</td><td>60</td></tr>
	 *   <tr><td>fullscreen</td><td>false</td></tr>
	 *   <tr><td>cursor</td><td>true</td></tr>
	 *   <tr><td>escapeQuitsApp</td><td>true</td></tr>
	 *   <tr><td>log</td><td>true</td></tr>
	 * </table>
	 */
	ofxXmlDefaultSettings();
	
	/**
	 * The enum is used to select a syntax string. All syntax strings will be
	 * stored at a string array. To change or get a syntax object, you can use the
	 * changeSyntax and getSyntax methods.<br>
	 * The ROOT, ROOT_VERSION and ROOT_URL syntax looks like
	 * @code
	 * <ROOT version"ROOT_VERSION" url"ROOT_URL">
	 * @endcode
	 * The CORE syntax looks like:
	 * @code
	 * <CORE>
	 *   (...)
	 * </CORE>
	 * @endcode
	 *
	 * @see changeSyntax
	 * @see getSyntax
	 */
	enum XmlSyntax{
		ROOT = 0, /**<The enum value to change the ROOT xml tag */
		ROOT_VERSION = 1, /**<The enum value to change the ROOT_VERSION xml attribute */
		ROOT_URL = 2, /**<The enum value to change the ROOT_URL xml attribute */
		CORE = 3 /**<The enum value to change the CORE xml tag */
	};
	
	/**
	 * Same as load(string src) but we use the default filepath.
	 */
	void load();
	/**
	 * This method checks if a default xml file exist.\n
	 * If no file is found, a default xml settings file will be created.
	 *
	 * @param src Path to default xml file.
	 */
	void load(string src);
	
	/**
	 * Get the openFrameworks core settings and save values into xml.
	 *
	 * @return Set boolean true, if file is saved.
	 */
	bool save();
	
	/**
	 * Set the openFrameworks core settings from xml file.
	 */
	void setSettings();
	/**
	 * Set the window size from xml file.
	 */
	void setWindowShape();
	/**
	 * Set the window position from xml file.
	 */
	void setWindowPosition();
	/**
	 * Set the window title from xml file.
	 */
	void setWindowTitle();
	/**
	 * Set the framerate from xml file.
	 */
	void setFrameRate();
	/**
	 * Set the fullscreen mode from xml file.
	 */
	void setFullscreen();
	/**
	 * Set the cursor mode from xml file.
	 */
	void setCursor();
	/**
	 * Set the ofSetEscapeQuitsApp from xml file.
	 */
	void setEscapeQuitsApp();
	/**
	 * Set the ofLogToFile from xml file.
	 */
	void setLog();
	
	/**
	 * Get the xml filepath.
	 * 
	 * @return Get the path of the xml file as a string.
	 */
	string getFilepath();
	/**
	 * Set the xml filepath.
	 * 
	 * @param src The path of the xml file.
	 */
	void setFilepath(string src);
	
	/**
	 * Change the default xml syntax to customize the xml file.
	 *
	 * @param xmlSyntax The syntax array item.
	 * @param name The new name of the syntax array item.
	 */
	void changeSyntax(int xmlSyntax, string name);
	/**
	 * Get the current xml syntax.
	 *
	 * @param xmlSyntax The syntax array item.
	 * @return The selected syntax element as string.
	 */
	string getSyntax(int xmlSyntax);
	
	/**
	 * Push to ROOT tag.
	 *
	 * @see popRoot()
	 */
	void pushRoot();
	/**
	 * Pop ROOT tag.
	 *
	 * @see pushRoot()
	 */
	void popRoot();
	
	/**
	 * Return a message set by the last method that was used.
	 *
	 * @return The last status message as a string.
	 */
	string getStatusMessage();
	
	/**
	 * The DefaultSettings struct is used to store the setting parameter.\n
	 * The attributes will be set by the ofxXmlDefaultSettings constructor.
	 *
	 * @param windowWidth The default window width as an integer.
	 * @param windowHeight The default window height as an integer.
	 * @param windowX The default window x-position as an integer.
	 * @param windowY The default window y-position as an integer.
	 * @param windowTitle The default window title as a string.
	 * @param frameRate The default framerate of the application as an integer.
	 * @param fullscreen The default fullscreen settings as a boolean.
	 * @param cursor The default cursor settings as a boolean.
	 * @param escapeQuitsApp The default settings if escape quits the application. Set as a boolean.
	 * @param log The default log settings as a boolean.
	 * @param logFilepath The path where the log txt files should be saved.
	 * @param logFilename The name of the log files
	 */
	struct DefaultSettings {
		int windowWidth;
		int windowHeight;
		int windowX;
		int windowY;
		string windowTitle;
		int frameRate;
		bool fullscreen;
		bool cursor;
		bool escapeQuitsApp;
		bool log;
		string logFilepath;
		string logFilename;
	};
	DefaultSettings defaultSettings;
	
	/**
	 * True if a default xml file exist at the application launch.
	 * If a default xml file was generated, the fileExist parameter is also false.
	 * This can be used for advanced thinks like adding more tags to the xml file.
	 */
	bool fileExist;
	
	
private:
	void createDefaultXml();
	string filepath;
	
	string statusMessage;
	
	/*
	 * The total size of xml syntax elements. This value will be used by the syntay array.
	 */
	static const int XML_SYNTAX_SIZE = 4;
	string syntax[XML_SYNTAX_SIZE];
};
#endif // INCLUDED_OFXXMLDEFAULTSETTINGS_H
