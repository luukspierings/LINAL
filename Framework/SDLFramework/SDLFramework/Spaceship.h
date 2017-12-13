#pragma once


using namespace std;

#include "Matrix.h"
#include "Square.h"
#include "Vector.h"
#include "InputManager.h"

class Spaceship {

public:
	Spaceship(Vector position = Vector({ 0,0,0 }), int size = 200);

	void accelerate();
	
	void rollLeft();
	void rollRight();

	void moveLeft();
	void moveRight();

	void moveUp();
	void moveDown();


	void shoot();

	void input(InputManager& inputM);

	Matrix getDrawable() const;

private:

	Matrix model;
	Square aabb;

	float turnDegrees = 2.f;
	float velocity;



};