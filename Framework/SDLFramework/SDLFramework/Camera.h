#pragma once

#include <vector>

using namespace std;

#include "Matrix.h"
#include "Vector.h"


class Camera {

public:
	Camera(float wW, float wH);


	Matrix toDraw(Matrix m);


	void setLookat(Vector v);
	void setEye(Vector v);
	void setUp(Vector v);

	void calculate();


private:

	float wW;
	float wH;

	Vector eye;
	Vector lookAt;

	Vector up;

	Vector z;
	Vector y;
	Vector x;

	float near;
	float fov;
	float far;


	Matrix camera;
	Matrix projection;

};