#include "ofApp.h"
#include "misFunciones.h"
float mAnchoPantalla;
float mAltoPantalla;


#define CANTIDADDEOBJETOS 100
objetoX obj[CANTIDADDEOBJETOS];
//#define mCantidadDeObjetos 3
//objetoX obj[mCantidadDeObjetos];
int mCantidadDeObjetos;
//--------------------------------------------------------------
void ofApp::setup() {
	//GENERAL
	ofBackground(0);
	ofSetFrameRate(30);
	gImAzulTop.load("azul-t.png");
	gImAzulCenter.load("azul-m.png");
	gImAzulBottom.load("azul-b.png");
	mAltoPantalla = ofGetScreenHeight();
	mAnchoPantalla = ofGetScreenWidth();
	//ofSetBackgroundAuto(false);
	//ofEnableAlphaBlending();


	//GUI
	
	gui.setup();
	
	gui.add(objX.setup("posX", 0, 0, mAnchoPantalla));
	gui.add(objY.setup("posY", 0, 0, mAltoPantalla));
	gui.add(objW.setup("objW", 0, 0, 100));
	gui.add(objH.setup("objH", 0, 0, 100));
	gui.add(objHMedio.setup("objHMedio", 0, 0, mAltoPantalla));
	gui.add(objSeparacionX.setup("objSeparacionX", 0, 0, 100));
	gui.add(objSeparacionY.setup("objSeparacionY", 0, 0, 100));
	gui.add(objCantidad.setup("objCantidad", 0, 1, 300));
	gui.loadFromFile("settings.xml");

	//OBJETOS
	//mCantidadDeObjetos = 3;
	//int mCantidadDeObjetos
	//for (int i = 0; i < mCantidadDeObjetos; i++) {
	//for (int i = 0; i < CANTIDADDEOBJETOS; i++) {
	//	obj[i].setup(gImAzulTop, gImAzulCenter, gImAzulBottom, 200, 200, 100, 100, 100);
	//}
}

//--------------------------------------------------------------
void ofApp::update() {
	ofSetWindowTitle(ofToString(ofGetFrameRate(), 0));

	//OBJETOS
	mCantidadDeObjetos = objCantidad;
	int tmpDistanciaX = objSeparacionX;
	for (int i = 0; i < mCantidadDeObjetos; i++) {
		//obj[i].update(objX + (i*tmpDistanciaX), objY, objW, objH, objHMedio);
		obj[i].setup(gImAzulTop, gImAzulCenter, gImAzulBottom, objX + (i*tmpDistanciaX), objY, objW, objH, objHMedio);
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofBackground(0);
	for (int i = 0; i < mCantidadDeObjetos; i++) {
		obj[i].draw();
	}
	//dibujar100(gImAzulBottom);
	gui.draw();
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
void ofApp::exit() {
	gui.saveToFile("settings.xml");
}
