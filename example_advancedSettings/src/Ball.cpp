//
// Ball.cpp
// ofxXmlDefaultSettings is released under the MIT License.
//
// Copyright (c) 2012-2013, Paul Vollmer http://www.wrong-entertainment.com
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

#include "Ball.h"

Ball::Ball(){
	// Set default values
	pos[0] = 100;
	pos[1] = 100;
	size = 50;
	color.set(127, 127);
}


void Ball::init(int pX, int pY, int s, ofColor c){
	pos[0] = pX;
	pos[1] = pY;
	size = s;
	color = c;
}


void Ball::draw(){
	ofFill();
	ofSetColor(color);
	ofEllipse(pos[0], pos[1], size, size);
}


void Ball::createXml(ofxXmlSettings xml, int which){
	cout << "writeXml which=" << which << endl;
	
	xml.addTag("ball");
	xml.addAttribute("ball", "x", pos[0], which);
	xml.addAttribute("ball", "y", pos[1], which);
	xml.addAttribute("ball", "size", size, which);
	
	xml.pushTag("ball", which);
	xml.addTag("color");
	xml.addAttribute("color", "r", color[0], 0);
	xml.addAttribute("color", "g", color[1], 0);
	xml.addAttribute("color", "b", color[2], 0);
	xml.addAttribute("color", "a", color[3], 0);
	xml.popTag(); // pop ball
}


void Ball::readXml(ofxXmlSettings xml, int which){
	cout << "readXml which=" << which << endl;
	
	pos[0] = xml.getAttribute("ball", "x", 0, which);
	pos[1] = xml.getAttribute("ball", "y", 0, which);
	size = xml.getAttribute("ball", "size", 50, which);
	color.set(xml.getAttribute("ball:color", "r", 255, which),
			  xml.getAttribute("ball:color", "g", 255, which),
			  xml.getAttribute("ball:color", "b", 255, which),
			  xml.getAttribute("ball:color", "a", 255, which));
	//color[0] = xml.getAttribute("ball:color", "r", 255, which);
	
	cout << "x" << pos[0] << endl;
	cout << "y" << pos[1] << endl;
	cout << "size" << size << endl;
	cout << "color" << color << endl;	
}
