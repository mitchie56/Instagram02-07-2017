#pragma once
#include"ofMain.h"

class Metaball {

public:
	Metaball();
	~Metaball();

	void update();
	ofVec2f attract(Metaball* ball);
	void applyForce(ofVec2f force);
	
	ofVec2f position;
	ofVec2f velocity;
	ofVec2f acceleration;
	float radius;
	float mass;

private:
	void edges();
};