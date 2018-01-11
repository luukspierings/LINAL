#pragma once


using namespace std;

#include "Matrix.h"
#include "Square.h"
#include "Vector.h"
#include "InputManager.h"

class Bullet: public Square {

public:

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








