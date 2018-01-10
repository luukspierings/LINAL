#pragma once


using namespace std;

#include "Matrix.h"
#include "Square.h"
#include "Vector.h"
#include "InputManager.h"

class Bullet {

public:
	Bullet(Vector position = Vector({ 0,0,0 }), Vector direction = Vector({ 0,0,0 }));

	void update();

	Matrix getDrawable() const;
	
	bool alive() {
		return (lifetime > 0);
	}

private:

	int lifetime = 200;

	Matrix model;
	float size = 0.3f;

	Square aabb;

	float velocity = 200.f;

	Vector direction;

};








