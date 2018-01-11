#pragma once


using namespace std;

#include "Matrix.h"
#include "Square.h"
#include "Vector.h"
#include "InputManager.h"
#include "Camera.h"

class Space;
class Spaceship {

public:
	Spaceship(Vector position = Vector({ 0,0,-30 }), float size = 5.f);

	void accelerate();
	
	void rollLeft();
	void rollRight();

	void moveLeft();
	void moveRight();

	void moveUp();
	void moveDown();

	void input(InputManager& inputM, Space& space);

	void update();

	void setCameraPerspective(Camera & camera);

	Matrix getDrawable() const;
	Vector getDirection() const;

	bool isCrosshairVisible() const;
	Matrix getDrawableCrosshair();

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
	float velocityStep = 0.5f;
	float velocityDecrease = 0.1f;
	float minVelocity = 2.f;
	float maxVelocity = 20.f;
	float velocityScaleDown = 1500.f;

	Vector direction;
	bool crosshairVisible = true;

	int bulletTimer = 0;
	int bulletCooldown = 20;

};