#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	defaultXml.init();
	//defaultXml.init("wngTest_1.xml");
	
	defaultXml.setSettings();
	
	//ofSetFrameRate(defaultXml.getValue("ofGetFrameRate", 60, 0));
	//ofSetWindowShape(defaultXml.getValue("ofGetWidth", 600, 0), defaultXml.getValue("ofGetHeight", 480, 0) );
	
	
	
	// add custom tags
	
	/*if(!defaultXml.tagExists("ofAppSettings", 0)){
		cout << "### No\n";
	} else {
	defaultXml.addTag("ofAppSettings");
	defaultXml.pushTag("ofAppSettings", 0);
	defaultXml.addValue("counterRuns", 0);
	defaultXml.addValue("lastRun", 0);
	defaultXml.addValue("counter", 0);
	}
	
	/*if(defaultXml.load()){
		cout << "load\n";
		defaultXml.addTag("wng");
		defaultXml.pushTag("wng", 0);
		defaultXml.addValue("myVar", 100);
		defaultXml.popTag();
		defaultXml.saveFile();
	}else{
		cout << "no load\n";
	}*/
	
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
	
}

//--------------------------------------------------------------
void testApp::exit(){
	
	defaultXml.getSettings();
	
}
