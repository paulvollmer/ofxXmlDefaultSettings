/**
 *  testApp.h is part of ofxXmlDefaultSettings.
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

#include "ofMain.h"
#include "ofxXmlDefaultSettings.h"


class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void keyPressed(int key);
		void exit();

		ofxXmlDefaultSettings XML;
	
};
