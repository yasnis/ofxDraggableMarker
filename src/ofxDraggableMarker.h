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
protected:
    bool isPress = false;
    bool isHover = false;
    
private:
    ofVec2f offset;
    ofVec2f dist;
    bool dragging;
    ofRectangle rect;
    ofColor color;
    
    void drawCircle(const ofPoint &p, float r);
    
protected:
    float radius = 14.0;
    int id;
    string label = "";
    
public:
    ofxDraggableMarker();
    ofxDraggableMarker(ofVec2f pos, int i, ofColor c = ofColor(255, 0, 0));
    ofxDraggableMarker(ofVec2f pos, string label, ofColor c = ofColor(255, 0, 0));
    
    virtual void draw();
    virtual void draw(float x, float y);
    
    virtual void setID(int _id);
    virtual int getID();
    
    virtual void setLabel(string _label);
    virtual string getLabel();
    
    virtual void setRadius(float _radius);
    virtual float getRadius();
    
    
    virtual bool mouseReleased(ofMouseEventArgs & args);
    virtual bool mouseMoved(ofMouseEventArgs & args);
    virtual bool mousePressed(ofMouseEventArgs & args);
    virtual bool mouseDragged(ofMouseEventArgs & args);
    
    
    virtual void setColor(ofColor col);
    virtual ofColor getColor();
    
    void setOffset(ofVec2f v);
    ofVec2f getOffset();
    
};

#endif /* defined(__ofApp__ofxDragMarker__) */
