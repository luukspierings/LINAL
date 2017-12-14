#pragma once


using namespace std;

#include "Matrix.h"
#include "Square.h"
#include "Vector.h"
#include "InputManager.h"

class Spaceship {

public:
	Spaceship(Vector position = Vector({ 0,0,0 }), int size = 20);

	void accelerate();
	
	void rollLeft();
	void rollRight();

	void moveLeft();
	void moveRight();

	void moveUp();
	void moveDown();

	void shoot();

	void input(InputManager& inputM);

	void update();

	Matrix getDrawable() const;
	Vector getDrawableDirection() const;

	bool isCrosshairVisible() const;

private:

	Matrix model;
	Square aabb;

	float turnDegrees = 2.f;
	float velocity = 2.f;
	float minVelocity = 2.f;
	float maxVelocity = 5.f;

	Vector direction;
	bool crosshairVisible = true;


};