#pragma once


using namespace std;

#include "Matrix.h"
#include "Square.h"
#include "Vector.h"
#include "InputManager.h"
#include "Camera.h"
#include "RotationMatrix.h"
#include "TranslationMatrix.h"


class Space;
class Spaceship {

public:
	Spaceship(Vector position = Vector({ 0,0,-10 }), float size = 5.f);

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

	float velocity = 0.f;
	float velocityStep = 20.0f;
	float velocityDecrease = 20.f;
	float minVelocity = 0.f;
	float maxVelocity = 40.f;

	Vector direction;
	bool crosshairVisible = true;

	int bulletTimer = 0;
	int bulletCooldown = 20;

};