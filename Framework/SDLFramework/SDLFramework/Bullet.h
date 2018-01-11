#pragma once


using namespace std;

#include "Matrix.h"
#include "Square.h"
#include "Vector.h"
#include "InputManager.h"
#include "TranslationMatrix.h"

class Bullet: public Square {

public:
	Bullet(Vector position = Vector({ 0,0,0 }), Vector direction = Vector({ 0,0,0 })) : direction(direction), Square(position, 0.3f) {};

	void update();
	
	bool alive() {
		return (lifetime > 0);
	}

private:

	int lifetime = 200;

	float size = 0.3f;

	float velocity = 2.f;

	Vector direction;

};








