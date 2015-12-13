#include "ofApp.h"

int generation = 0;
int frame = 0;
int maxGeneration = 8;
ofMesh mesh;

//--------------------------------------------------------------
void ofApp::setup(){
    mesh.addVertex(ofPoint(-400, 0));
    mesh.addVertex(ofPoint(400, 0));
    mesh.addVertex(ofPoint(0, 400 * sqrt(3.0)));
    mesh.setMode(OF_PRIMITIVE_TRIANGLES);
    mesh.addColor(ofColor::fromHsb(ofRandom(255), 255, 255));
    mesh.addColor(ofColor::fromHsb(ofRandom(255), 255, 255));
    mesh.addColor(ofColor::fromHsb(ofRandom(255), 255, 255));

    ofBackground(0);
}

//--------------------------------------------------------------
void ofApp::update(){
    frame++;
    if(frame % 30 == 0){
        generation++;
        if(generation < maxGeneration){
            ofMesh * newMesh = &mesh;
            for(int i = mesh.vertices.size() / 3 - 1; i >= 0 ; i--){
                ofPoint p1 = (mesh.vertices.at(i * 3) + mesh.vertices.at(i * 3 + 1))/ 2.0;
                ofPoint p2 = (mesh.vertices.at(i * 3) + mesh.vertices.at(i * 3 + 2))/ 2.0;
                ofPoint p3 = (mesh.vertices.at(i * 3 + 1) + mesh.vertices.at(i * 3 + 2))/ 2.0;
                
                newMesh->vertices.insert(mesh.vertices.begin() + i * 3 + 2, p2);
                newMesh->vertices.insert(mesh.vertices.begin() + i * 3 + 2, p3);
                
                newMesh->vertices.insert(mesh.vertices.begin() + i * 3 + 1, p1);
                newMesh->vertices.insert(mesh.vertices.begin() + i * 3 + 1, p3);
                
                newMesh->vertices.insert(mesh.vertices.begin() + i * 3 + 1, p1);
                newMesh->vertices.insert(mesh.vertices.begin() + i * 3 + 1, p2);
                
                for(int i = 0; i < 6; i++){
                    newMesh->addColor(ofColor::fromHsb(ofRandom(255), 255, 255));
                }
            }
            mesh = *newMesh;
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, 100);
    mesh.draw();
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
