//
//  ofxDraggerGroup.h
//  ofApp
//
//  Created by X006819_nishimura on 2015/04/28.
//
//

#ifndef __ofApp__ofxDraggerGroup__
#define __ofApp__ofxDraggerGroup__
#include "ofMain.h"
#include "ofxDraggableMarker.h"

class ofxDraggableMarkerGroup:public vector<ofxDraggableMarker *> {
private:
    ofVec2f defaultPosition = ofVec2f(0, 0);
    ofColor defaultColor = ofColor(255, 0, 0);
    
public:
    ofxDraggableMarkerGroup();
    ~ofxDraggableMarkerGroup();
    
    void draw();
    
    void addMarker();
    void addMarker(ofxDraggableMarker *marker);
    ofxDraggableMarker* removeMarker();
    
    void setDefaultPosition(ofVec2f pos);
    void setDefaultColor(ofColor col);
    
    ofVec2f getDefaultPosition();
    ofColor getDefaultColor();
};

#endif
