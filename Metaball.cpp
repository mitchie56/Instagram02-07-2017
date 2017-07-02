#include "Metaball.h"

Metaball::Metaball() {
	this->position = ofVec2f(ofRandom(640), ofRandom(640));
	this->velocity = ofVec2f(ofRandom(-3.6,3.6), ofRandom(-3.6, 3.6));
	this->acceleration = ofVec2f(0.0, 0.0);
	this->radius = ofRandom(3,18);
	this->mass = radius/10;
	//Dont't want velocity of 0
	if (velocity.x == 0.0) {
		velocity.x = 0.3;
	}
	if (velocity.y == 0.0) {
		velocity.y = 0.3;
	}
}

Metaball::~Metaball() {
	
}

void Metaball::update() {
	this->edges();
	this->velocity += this->acceleration;
	//Limit velocity to stop chaos 
	this->velocity.limit(6.3);
	this->position += this->velocity;
	this->acceleration *= 0.0;
}

/*
	Metaballs will have mutual attraction 
 */
ofVec2f Metaball::attract(Metaball* ball) {
	float g = 0.0015;//abstract constant
	//Get the direction of the force
	ofVec2f force = this->position - ball->position;
	float distance = force.length(); //get magnitude of vector
	distance = ofClamp(distance, 5.0, 35.0); 

	force.normalize(); //set magnitude to 1
	float strength = (g * this->mass * ball->mass) / distance * distance;
	force *= strength;

	return force;
}

void Metaball::applyForce(ofVec2f f) {
	ofVec2f force = f / mass;
	this->acceleration += force;
}


/*
 * Stop the metaballs going off the screen 
 */
void Metaball::edges() {
	if (this->position.x + this->radius > ofGetWidth()) {
		this->position.x = ofGetWidth() - this->radius;
		this->velocity.x *= -1;
	}

	if (this->position.x - this->radius < 0) {
		this->position.x = this->radius;
		this->velocity.x *= -1;
	}

	if (this->position.y + this->radius > ofGetHeight()) {
		this->position.y = ofGetHeight() - this->radius;
		this->velocity.y *= -1;
	}

	if (this->position.y - this->radius < 0) {
		this->position.y = this->radius;
		this->velocity.y *= -1;
	}
}
