//
//  ofxDraggableMarkerGroup.cpp
//  ofApp
//
//  Created by X006819_nishimura on 2015/04/28.
//
//

#include "ofxDraggableMarkerGroup.h"


ofxDraggableMarkerGroup::ofxDraggableMarkerGroup() {
    
}

ofxDraggableMarkerGroup::~ofxDraggableMarkerGroup() {
    
}

void ofxDraggableMarkerGroup::draw() {
    vector<ofxDraggableMarker *>::iterator iterator = begin();
    while (iterator!=end()) {
        (*iterator)->draw();
        iterator++;
    }
}

void ofxDraggableMarkerGroup::addMarker() {
    ofxDraggableMarker *marker = new ofxDraggableMarker(defaultPosition,size());
    push_back(marker);
}

void ofxDraggableMarkerGroup::addMarker(ofxDraggableMarker *marker) {
    marker->setColor(defaultColor);
    push_back(marker);
}

ofxDraggableMarker* ofxDraggableMarkerGroup::removeMarker() {
    return *erase(end());
}



void ofxDraggableMarkerGroup::setDefaultPosition(ofVec2f pos) {
    defaultPosition.set(pos);
}

void ofxDraggableMarkerGroup::setDefaultColor(ofColor col) {
    defaultColor.set(col);
}

int ofxDraggableMarkerGroup::size() {
    return this->vector::size();
}

ofVec2f ofxDraggableMarkerGroup::getDefaultPosition() {
    return defaultPosition;
}

ofColor ofxDraggableMarkerGroup::getDefaultColor() {
    return defaultColor;
}


void ofxDraggableMarkerGroup::setOffset(ofVec2f v) {
    offset = v;
    for (int i = 0; i<size(); i++) {
        at(i)->setOffset(v);
    }
}

ofVec2f ofxDraggableMarkerGroup::getOffset() {
    return offset;
}