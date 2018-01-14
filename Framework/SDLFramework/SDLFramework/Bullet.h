#pragma once


using namespace std;

#include "Matrix.h"
#include "Square.h"
#include "Vector.h"
#include "InputManager.h"
#include "TranslationMatrix.h"

class Bullet: public Square {

private:



public:
	Bullet(Vector position = Vector({ 0,0,0 }), Vector direction = Vector({ 0,0,0 }), float relativeVelocity = 0.f, float size = 0.1f) : 
		size(size), 
		direction(direction), 
		relativeVelocity(relativeVelocity), 
		Square(position, size) 
	{};

	void update();
	
	bool alive() {
		return (lifetime > 0.f);
	}

	Vector direction;


private:

	float lifetime = 500.f;

	float size = 0.1f;

	float velocity = 10.f;
	float relativeVelocity = 0.f;


};








