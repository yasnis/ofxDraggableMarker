#include "ofMain.h"
#include "ofxDraggableMarker.h"
#include "ofxDraggableMarkerGroup.h"

class ofApp : public ofBaseApp{
    
    vector<ofxDraggableMarker *> draggers;
    ofxDraggableMarker *dragger;

    ofxDraggableMarkerGroup group0;
    ofxDraggableMarkerGroup group1;
    
    //--------------------------------------------------------------
    void setup(){
        ofBackground(0);
        ofSetFrameRate(60);
        ofSetVerticalSync(true);
        
        group0.setDefaultPosition(ofVec2f(ofGetWidth()/2, ofGetHeight()/2));
        group1.setDefaultPosition(ofVec2f(ofGetWidth()/2, ofGetHeight()/2));
        group0.setDefaultColor(ofColor(255, 32, 32));
        group1.setDefaultColor(ofColor(32, 32, 255));
        
        for (int i = 0; i<5; i++) {
            group0.addMarker(new ofxDraggableMarker(ofVec2f(ofRandom(ofGetWidth()), ofRandom(ofGetHeight())),i));
            group1.addMarker(new ofxDraggableMarker(ofVec2f(ofRandom(ofGetWidth()), ofRandom(ofGetHeight())),i));
        }
    }
    
    //--------------------------------------------------------------
    void update(){
    }
    
    //--------------------------------------------------------------
    void draw(){
        group0.draw();
        group1.draw();
    }
    
    void keyPressed(int key){
        if(key == 'f'){
            ofToggleFullscreen();
        }
    }
};

//========================================================================
int main( ){
	ofSetupOpenGL(960,540, OF_WINDOW);
	ofRunApp( new ofApp());
}
