#pragma once


using namespace std;

#include "Matrix.h"
#include "Square.h"
#include "Vector.h"
#include "InputManager.h"

class Space;
class Spaceship {

public:
	Spaceship(Vector position = Vector({ 0,0,-30 }), int size = 5);

	void accelerate();
	
	void rollLeft();
	void rollRight();

	void moveLeft();
	void moveRight();

	void moveUp();
	void moveDown();

	void input(InputManager& inputM, Space& space);

	void update();

	Matrix getDrawable() const;
	Vector getDrawableDirection() const;

	bool isCrosshairVisible() const;

	Vector backMiddle();
	Vector backRight();
	Vector backLeft();
	Vector backDown();
	Vector backUp();

	Vector rightMiddle();

	Vector leftMiddle();

	Vector upMiddle();

	Vector downMiddle();

	Vector frontMiddle();

private:

	Matrix model;
	int size;


	Square aabb;

	float turnDegrees = 2.f;
	float velocity = 2.f;
	float minVelocity = 2.f;
	float maxVelocity = 20.f;

	Vector direction;
	bool crosshairVisible = true;

	int bulletTimer = 0;
	int bulletCooldown = 20;

};