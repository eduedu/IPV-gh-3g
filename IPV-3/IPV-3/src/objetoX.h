#pragma once
#include "ofMain.h"

class objetoX {
public:

	void setup(ofImage _imT, ofImage _imM, ofImage _imB, float _x, float _y, float _w, float _h, float _hMedio);
	void draw();
	void update(float  _x, float _y, float _w, float _h, float _hMedio);

	ofImage imT;
	ofImage imM;
	ofImage imB;
	float x;
	float y;
	float w;
	float h;
	float hMedio;
	float ajuste;
};