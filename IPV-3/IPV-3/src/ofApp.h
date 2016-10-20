#pragma once

#include "ofMain.h"
#include "objetoX.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();


		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);


		
		ofImage gImAzulTop;
		ofImage gImAzulCenter;
		ofImage gImAzulBottom;
		ofImage gImVerdeTop;
		ofImage gImVerdeCenter;
		ofImage gImVerdeBottom;

//		vector<objetoX> particles;
		ofxPanel gui;
		ofxGuiGroup particular;
		ofxGuiGroup grupo;
		ofxGuiGroup verde;
		ofxGuiGroup azul;
		ofxGuiGroup global;
		ofxFloatSlider globalScale;
		ofxFloatSlider globalX;
		ofxFloatSlider globalY;

		ofxFloatSlider objW;
		ofxFloatSlider objH;
		ofxFloatSlider objHMedio;
		ofxFloatSlider objSeparacionX;
		ofxFloatSlider objSeparacionY;
		ofxIntSlider objCantidadX;
		ofxIntSlider objCantidadY;

		ofxFloatSlider objX1;
		ofxFloatSlider objY1;
		ofxIntSlider objCurva1;
		ofxFloatSlider objX2;
		ofxFloatSlider objY2;
		ofxIntSlider objCurva2;

		ofxToggle verFondo;

		void exit();
		//int mCantidadDeObjetos;
};

