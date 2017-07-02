#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);
	ofSetWindowTitle("Instagram");
	//Create metaballs
	for (int i = 0; i < NUM_METABALLS; i++) {
		metaballs.push_back(new Metaball());
	}
	//Load frag shader from bin/data
	frag.load("", "metaballs.glsl");
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	//Pointer used to traverse toGPU array 
	float* index = toGPU;

	for (int i = 0; i < metaballs.size(); i++) {
		Metaball* ball = metaballs.at(i);

		for (int j = 0; j < metaballs.size(); j++) {
			if (i != j) {
				ofVec2f force = metaballs.at(j)->attract(ball);
				ball->applyForce(force);
			}
		}

		ball->update();
		//Send position and radius to GPU
		*index = ball->position.x;
		*++index = ball->position.y;
		*++index = ball->radius;
		index++;
	}

	//Start frag shader
	frag.begin();
	//Send uniforms
	frag.setUniform1fv("metaballs", toGPU, 360);
	frag.setUniform1f("u_time", ofGetElapsedTimef());
	frag.setUniform2f("u_res", (float)640, (float)640);
	//draw screen 
	ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
	//End shader
	frag.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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