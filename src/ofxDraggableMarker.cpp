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
	setColor(c);
}

ofxDraggableMarker::ofxDraggableMarker(ofVec2f pos, string label, ofColor c) {
	ofRegisterMouseEvents(this);

	set(pos);
	setLabel(label);
	setColor(c);
}

void ofxDraggableMarker::draw() {
	draw(offset.x, offset.y);
}

void ofxDraggableMarker::draw(float x, float y) {

	string str = label.length()>0 ? label : ofToString(id);
	ofVec2f p = ofVec2f(this->x + x, this->y + y);
	ofSetColor(color);
	ofFill();
	drawCircle(p, 2);
	if (isPress) {
		ofSetLineWidth(2.0);
		ofNoFill();
		drawCircle(p, radius / 2);

		color.a = 128;
		ofSetColor(color);
		ofFill();
		drawCircle(p, radius / 2);

		ofSetColor(255);
	}
	else if (isHover) {
		ofNoFill();
		drawCircle(p, radius / 2);
		color.a = 64;
		ofSetColor(color);
		ofFill();
		drawCircle(p, radius / 2);
		ofSetColor(255);
	}
	else {
		ofNoFill();
		drawCircle(p, radius / 2);
	}
	ofSetLineWidth(1.0);
	color.a = 255;

	ofDrawBitmapString(str, p + ofVec2f(-4.0*str.length(), 4));

	ofSetLineWidth(1.0);
	ofSetColor(255);

	//    ofPopMatrix();
}

void ofxDraggableMarker::drawCircle(const ofPoint &p, float r) {
#if OF_VERSION_MINOR != 9
	ofCircle(p.x, p.y, r);
#else
	ofDrawCircle(p, r);
#endif
}



void ofxDraggableMarker::setID(int _id) {
	id = _id;
}

int ofxDraggableMarker::getID() {
	return id;
}

void ofxDraggableMarker::setLabel(string _label) {
	label = _label;
}

string ofxDraggableMarker::getLabel() {
	return label;
}


void ofxDraggableMarker::setRadius(float _radius) {
	radius = _radius;

}
float ofxDraggableMarker::getRadius() {
	return radius;
}



void ofxDraggableMarker::mouseReleased(ofMouseEventArgs & args) {
	isPress = false;
}

void ofxDraggableMarker::mouseMoved(ofMouseEventArgs & args) {
	dist = (*this + offset) - args;
	isHover = dist.length() < radius / 2;
}

void ofxDraggableMarker::mousePressed(ofMouseEventArgs & args) {
	isPress = isHover;
}

void ofxDraggableMarker::mouseDragged(ofMouseEventArgs & args) {
	if (isPress) set(args + dist - offset);
}


void ofxDraggableMarker::mouseScrolled(ofMouseEventArgs & args) {};
void ofxDraggableMarker::mouseEntered(ofMouseEventArgs & args) {};
void ofxDraggableMarker::mouseExited(ofMouseEventArgs & args) {};


void ofxDraggableMarker::setColor(ofColor col) {
	color.set(col);
}

ofColor ofxDraggableMarker::getColor() {
	return color;
}


void ofxDraggableMarker::setOffset(ofVec2f v) {
	offset = v;
}

ofVec2f ofxDraggableMarker::getOffset() {
	return offset;
}