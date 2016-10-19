#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	img.load("ja.jpg");
	//ofSetBackgroundAuto(false);
	ofSetFrameRate(30);
	//ofEnableAlphaBlending();

}

//--------------------------------------------------------------
void ofApp::update() {
	ofSetWindowTitle(ofToString(ofGetFrameRate(), 0));
	for (int i = 0; i < particles.size(); i++) {
		particles[i].update();
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	/*
	ofBackground(255, 100, 0);
	ofSetColor(255, 255, 0);
	ofDrawRectangle(0, 0, 100, 100);
	ofDrawRectangle(300, 0, 100, 100);
	*/
	ofSetColor(255);

	if (ofGetMousePressed()) {
		img.draw(0, 0);
	}

	
	for (int i = 0; i < particles.size(); i++) {
		objetoX &p = particles[i];
		//p.color = img.getColor((int) p.pos.x,(int)p.pos.y);
		//p.color = img.getColor(1, 1);
		p.draw();
	}
	
	for (int i = 0; i < 50; i++) {
		createParticle();
	}

	while (particles.size() > 1000) {
		particles.erase(particles.begin());
	}
	
}
void ofApp::createParticle() {
	objetoX p;
	p.setup();
	p.pos.set(ofRandomWidth(), ofRandomHeight());
	//p.color = img.getColor(p.pos.x, p.pos.y);
	
	particles.push_back(p);
	//particles.
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == 'q') ofEnableSmoothing();
	if (key == 'Q') ofDisableSmoothing();
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
