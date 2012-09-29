//
// ball.h
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

#ifndef BALL_H
#define BALL_H

#include "ofMain.h"
#include "ofxXmlSettings.h"

/**
 * For this little Example we use a xml structure like:
 *
 *   <balls>
 *     <ball x="100" y="100" size="100">
 *       <color r="255" g="0" b="0" a="255"></color>
 *     </ball>
 *   </balls>
 */
class Ball {
public:
	Ball();
	
	void init(int posX, int posY, int s, int colorR, int colorG, int colorB, int colorAlpha);
	void draw();
	void createXml(ofxXmlSettings xml, int which);
	void readXml(ofxXmlSettings xml, int which);
	ofxXmlSettings updateXml(int which);
	
	ofVec2f pos;
	int size;
	ofColor color;
};
#endif
