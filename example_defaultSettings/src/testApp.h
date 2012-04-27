#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"
#include "ofxXmlDefaultSettings.h"


class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void exit();

		ofxXmlDefaultSettings defaultXml;
	
};

#endif
