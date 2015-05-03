//
//  ofxDraggableMarker.cpp
//  ofApp
//
//  Created by X006819_nishimura on 2015/04/28.
//
//

#include "ofxDraggableMarker.h"

ofxDraggableMarker::ofxDraggableMarker() {
    ofRegisterMouseEvents(this);
}

ofxDraggableMarker::ofxDraggableMarker(ofVec2f pos, int i, ofColor c) {
    ofRegisterMouseEvents(this);
    
    set(pos);
    setID(i);
    
}

void ofxDraggableMarker::draw() {
    string str = ofToString(id);
    ofSetColor(color);
    if(isPress){
        ofSetLineWidth(3.0);
        ofNoFill();
        ofCircle(x, y, radius/2);
        ofFill();
        ofCircle(x, y, radius/2);
        
        ofSetColor(255);
    }else if(isHover){
        ofFill();
        ofCircle(x, y, radius/2);
        ofSetColor(255);
    }else{
        ofNoFill();
        ofCircle(x, y, radius/2);
    }
    
    ofDrawBitmapString(str, ofVec2f(x,y)+ofVec2f(-4.0*str.length(), 4));
    
    ofSetLineWidth(1.0);
    ofSetColor(255);
}

void ofxDraggableMarker::setID(int _id) {
    id = _id;
}

int ofxDraggableMarker::getID() {
    return id;
}




bool ofxDraggableMarker::mouseReleased(ofMouseEventArgs & args){
    isPress = false;
    return false;
}

bool ofxDraggableMarker::mouseMoved(ofMouseEventArgs & args){
    offset = ofVec2f(x,y)-args;
    isHover = offset.length() < radius;
    return false;
}

bool ofxDraggableMarker::mousePressed(ofMouseEventArgs & args){
    isPress = isHover;
    return isPress;
}

bool ofxDraggableMarker::mouseDragged(ofMouseEventArgs & args){
    if(isPress) set(args+offset);
    return isPress;
}

void ofxDraggableMarker::setColor(ofColor col) {
    color.set(col);
}

ofColor ofxDraggableMarker::getColor() {
    return color;
}
