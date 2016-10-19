#include "objetoX.h"

void objetoX::setup() {
	vel.x = 2 * ofRandomf();
	vel.y = 2 * ofRandomf();
	angle = ofRandomf()*TWO_PI;
	age = 0;
}

void objetoX::draw() {
	ofSetColor(color, ofMap(age, 0, 20, 255, 0, true));
	ofLine(oldpos, pos);
}

void objetoX::update() {
	angle += ofSignedNoise(pos.x, pos.y)*TWO_PI;
	vel.rotate(angle);
	oldpos = pos;
	pos += vel;
	age++;
}
