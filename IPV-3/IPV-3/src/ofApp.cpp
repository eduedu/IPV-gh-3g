#include "ofApp.h"
#include "misFunciones.h"
float mAnchoPantalla;
float mAltoPantalla;


#define CANTIDADDEOBJETOS 100
objetoX objV[CANTIDADDEOBJETOS];
objetoX objA[CANTIDADDEOBJETOS];
//#define mCantidadDeObjetos 3
//objetoX obj[mCantidadDeObjetos];
//int mCantidadDeObjetos;
int mCantidadDeObjetosX;
int mCantidadDeObjetosY;

ofImage fondo;
//--------------------------------------------------------------
void ofApp::setup() {
	//GENERAL
	ofBackground(0);
	fondo.load("fondo1.png");
	//ofSetFrameRate(30);
	gImAzulTop.load("azul-t.png");
	gImAzulCenter.load("azul-m.png");
	gImAzulBottom.load("azul-b.png");
	gImVerdeTop.load("verde-t.png");
	gImVerdeCenter.load("verde-m.png");
	gImVerdeBottom.load("verde-b.png");
	mAltoPantalla = ofGetScreenHeight();
	mAnchoPantalla = ofGetScreenWidth();
	//ofSetBackgroundAuto(false);
	//ofEnableAlphaBlending();


	//GUI

	gui.setup();
	global.setup("Global");
	global.add(objHMedio.setup("objHMedio", 0, 0, 200));
	global.add(verFondo.setup("Ver Fondo", true));
	global.add(globalScale.setup("scale", 1, 0, 2));
	global.add(globalX.setup("X", 0, -500, 500));
	global.add(globalY.setup("Y", 0, -500, 500));

	grupo.setup("Grupo");
	grupo.add(objSeparacionX.setup("objSeparacionX", 0, 0, 100));
	grupo.add(objSeparacionY.setup("objSeparacionY", 0, 0, 100));
	grupo.add(objCantidadX.setup("objCantidadX", 0, 1, 10));
	grupo.add(objCantidadY.setup("objCantidadY", 0, 1, 10));

	particular.setup("Particular");
	particular.add(objW.setup("objW", 0, 0, 50));
	particular.add(objH.setup("objH", 0, 0, 50));

	verde.setup("Azul");
	verde.add(objX1.setup("posX", 0, 0, 500));
	verde.add(objY1.setup("posY", 0, 0, 500));
	verde.add(objCurva1.setup("objCurva", 0, -40, 40));

	azul.setup("Verde");
	azul.add(objX2.setup("posX", 0, 0, mAnchoPantalla));
	azul.add(objY2.setup("posY", 0, 0, mAltoPantalla));
	azul.add(objCurva2.setup("objCurva", 0, -40, 40));

	gui.add(&global);
	gui.add(&grupo);
	gui.add(&particular);
	gui.add(&verde);
	gui.add(&azul);
	gui.loadFromFile("settings.xml");

	//OBJETOS
	//mCantidadDeObjetos = 3;
	//int mCantidadDeObjetos
	//for (int i = 0; i < mCantidadDeObjetos; i++) {
	//for (int i = 0; i < CANTIDADDEOBJETOS; i++) {
	//	obj[i].setup(gImAzulTop, gImAzulCenter, gImAzulBottom, 200, 200, 100, 100, 100);
	//}
	//for (int j = 0; j < objCantidadY; j++) {
	//	for (int i = 0; i < objCantidadX; i++) {
	for (int i = 0; i < CANTIDADDEOBJETOS; i++) {
		//obj[i].update(objX + (i*tmpDistanciaX), objY, objW, objH, objHMedio);
		//obj[i].setup(gImAzulTop, gImAzulCenter, gImAzulBottom, objX + (i*objSeparacionX), objY, objW, objH, objHMedio);
		//obj[i].update(objX + (i*objSeparacionX), objY, objW, objH, objHMedio);
		//obj[i + (objCantidadX*(j))].setup(gImAzulTop, gImAzulCenter, gImAzulBottom, 200, 200, 100, 100, 100);
		objV[i].setup(gImAzulTop, gImAzulCenter, gImAzulBottom, 200, 200, 100, 100, 100);
		objA[i].setup(gImVerdeTop, gImVerdeCenter, gImVerdeBottom, 200, 200, 100, 100, 100);
	}
}



//--------------------------------------------------------------
void ofApp::update() {
	ofSetWindowTitle(ofToString(ofGetFrameRate(), 0));

	//OBJETOS
	//mCantidadDeObjetosX = objCantidadX;
	//mCantidadDeObjetosY = objCantidadY;
	int tmpSeparacionX = objSeparacionX;
	int tmpSeparacionY = objSeparacionY;


	float tmpCurva1;
	float tmpCurva2;
	for (int j = 0; j < objCantidadY; j++) {
		for (int i = 0; i < objCantidadX; i++) {
			tmpCurva1 = objCurva1*(i - (objCantidadX / 2));
			objV[i + (objCantidadX*j)].update(objX1 + (i*objSeparacionX),
				objY1 + (j*objSeparacionY) + (tmpCurva1), objW, objH, objHMedio);

			tmpCurva2 = objCurva2*(i - (objCantidadX / 2));
			objA[i + (objCantidadX*(j))].update(objX2 + (i*objSeparacionX),
				objY2 + (j*objSeparacionY) + (tmpCurva2), objW, objH, objHMedio);

		}
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofBackground(0);
	//ofScale(1, 1, 1);
	
	if (verFondo) {
		//ofScale(1, 1, 1);
		ofSetColor(255, 100);
		fondo.draw(0, 0);
	}
	ofPushMatrix();
	ofScale(globalScale, globalScale, 1);
	ofTranslate(globalX, globalY);
	ofSetColor(255, 255);
	int tmpTotal = objCantidadX* objCantidadY;
	for (int i = 0; i < (tmpTotal); i++) {
		//for (int j = 0; j < objCantidadY; j++) {
		//	for (int i = 0; i < objCantidadX; i++) {
		objA[i].draw();
		objV[i].draw();
		//	}
	}
	//dibujar100(gImAzulBottom);
	ofPopMatrix();
	gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == 'q') ofEnableSmoothing();
	if (key == 'Q') ofDisableSmoothing();
	if (key == 'f') ofToggleFullscreen();
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
