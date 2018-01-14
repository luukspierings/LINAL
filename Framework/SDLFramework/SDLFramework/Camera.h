#pragma once

#include <vector>

using namespace std;

#include "Matrix.h"
#include "Vector.h"
#include "InputManager.h"
#include "RotationMatrix.h"


class Camera {

public:
	Camera(float wW, float wH);


	Matrix toDraw(Matrix m);


	void setLookat(Vector v);
	void setEye(Vector v);
	void setUp(Vector v);

	void calculate();

	void calculateArcBall(Vector lookat);
	void inputArcBall(InputManager & inputM);

private:

	float wW;
	float wH;

	Vector eye;
	Vector lookAt;
	Vector up;

	float near;
	float fov;
	float far;

	Matrix camera;
	Matrix projection;

	// Arcball
	float turnSpeed = 1;
	float pitchDegrees = 0;
	float yawDegrees = 0;
	float rollDegrees = 0;
	float zoom = 20;


};