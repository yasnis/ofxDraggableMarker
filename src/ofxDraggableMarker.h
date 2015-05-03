//
//  ofxDraggableMarker.h
//  ofApp
//
//  Created by X006819_nishimura on 2015/04/28.
//
//

#ifndef __ofApp__ofxDraggableMarker__
#define __ofApp__ofxDraggableMarker__

#include "ofMain.h"

class ofxDraggableMarker: public ofVec2f {
private:
    ofVec2f offset;
    bool dragging;
    ofRectangle rect;
    float radius = 14.0;
    ofColor color;

    bool isPress = false;
    bool isHover = false;
    
    int id;
    
public:
    ofxDraggableMarker();
    ofxDraggableMarker(ofVec2f pos, int i, ofColor c = ofColor(255, 0, 0));
    
    void draw();
    
    void setID(int _id);
    int getID();
    
    
    bool mouseReleased(ofMouseEventArgs & args);
    bool mouseMoved(ofMouseEventArgs & args);
    bool mousePressed(ofMouseEventArgs & args);
    bool mouseDragged(ofMouseEventArgs & args);
    
    
    void setColor(ofColor col);
    ofColor getColor();
    
};

#endif /* defined(__ofApp__ofxDragMarker__) */
