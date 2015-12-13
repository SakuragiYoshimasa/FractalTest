#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    sierpinskiGasket.setup();
    ofBackground(0);
}

void ofApp::update(){
    sierpinskiGasket.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0, 255, 0);
    sierpinskiGasket.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == ' ') sierpinskiGasket.reset();
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
