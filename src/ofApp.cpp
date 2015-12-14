#include "ofApp.h"
#include <complex>
#include "SierpinskiGasket.h"

//set0
/*complex<double> A = complex<double>(0.5, sqrt(3.0) / 6.0);
complex<double> D = complex<double>(0.5, - sqrt(3.0) / 6.0);
complex<double> B = complex<double>(0,0);
complex<double> C = complex<double>(0,0);*/

//set1
/*complex<double> A = complex<double>(0, 0);
complex<double> B = complex<double>(0.4, 0.5);
complex<double> C = complex<double>(0, 0);
complex<double> D = complex<double>(0.4, -0.5);*/


//set2
/*complex<double> A = complex<double>(0.5, 0.5);
complex<double> B = complex<double>(0, 0);
complex<double> C = complex<double>(0.5, -0.5);
complex<double> D = complex<double>(0, 0);*/

//set3
/*complex<double> A = complex<double>(0.4614, 0.4614);
complex<double> B = complex<double>(0, 0);
complex<double> C = complex<double>(0.622, -0.196);
complex<double> D = complex<double>(0, 0);*/

//set4
/*complex<double> A = complex<double>(0, 0.707);
complex<double> B = complex<double>(0, 0);
complex<double> C = complex<double>(0.5, 0);
complex<double> D = complex<double>(0, 0);*/

//set5
complex<double> A = complex<double>(0.4614, 0.4614);
complex<double> B = complex<double>(0, 0);
complex<double> C = complex<double>(0, 0);
complex<double> D = complex<double>(0.2896, 0.585);

complex<double> getComplexConjugate(complex<double> z){
    return complex<double>(z.real(), - z.imag());
}

complex<double> f0(complex<double> z){
    return A * z + B * getComplexConjugate(z);
}

complex<double> f1(complex<double> z){
    return C * (z - 1.0) + D * (getComplexConjugate(z) - 1.0) + 1.0;
}

vector< complex<double> > CSpace;
ofMesh mesh;

SierpinskiGasket sierpinskiGasket;
//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    sierpinskiGasket.setup();


    complex<double> z0 = complex<double>(0, 0);
    CSpace.push_back(z0);
    
    for(int i = 0; i < 15; i++){
        vector< complex< double> > newCSapce = vector< complex<double> >(0);
        for(int k = 0; k < CSpace.size(); k++){
            newCSapce.push_back(f0(CSpace.at(k)));
            newCSapce.push_back(f1(CSpace.at(k)));
        }
        CSpace = newCSapce;
    }
    for(int i = 0; i < CSpace.size(); i++){
        mesh.addVertex(ofPoint(CSpace.at(i).real() * 400,CSpace.at(i).imag() * 400));
    }
    mesh.setMode(OF_PRIMITIVE_POINTS);
}

void ofApp::update(){
    sierpinskiGasket.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    //ofSetColor(0, 255, 0);
    sierpinskiGasket.draw();
    
    /*ofPushMatrix();
    ofSetColor(0,255,0);
    ofTranslate(ofGetWidth()/2 - 300, ofGetHeight()/2 );
    mesh.draw();
    ofPopMatrix();*/
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
