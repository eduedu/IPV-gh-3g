#include "objetoX.h"

void objetoX::setup(ofImage _imT, ofImage _imM, ofImage _imB, float  _x, float _y, float _w, float _h, float _hMedio) {
	x = _x;
	y = _y;
	w = _w;
	h = _h;
	imT = _imT;
	imM = _imM;
	imB = _imB;
	hMedio = _hMedio;
	ajuste =(h* 0.02);
}

void objetoX::draw() {
	//imB.draw(x, y + h / 2 + hMedio-ajuste, w, h / 2);
	//imM.draw(x, y + h / 2 - ajuste, w, hMedio);
	//imT.draw(x, y, w, h);
	
	imB.draw(x, y + h / 2 - ajuste, w, h / 2);
	imM.draw(x, y + h / 2-hMedio - ajuste, w, hMedio);
	imT.draw(x, y-hMedio, w, h);

	//ofDrawBitmapString(texto, x, y);
	//ofDrawBitmapString(ofToString(y), x, y);
	//cout << x << "-" << y << endl;
}

void objetoX::update(float  _x, float _y, float _w, float _h, float _hMedio) {
	x = _x;
	y = _y;
	w = _w;
	h = _h;
	hMedio = _hMedio;
}
