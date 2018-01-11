#pragma once

#include "Matrix.h"

class RotationMatrix {

public:

	RotationMatrix(float degrees, Vector rotationAxis, Vector rotationPoint = Vector({ 0,0,0 }));

	Matrix RotationMatrix::operator*(const Matrix & m);

private:

	Matrix m7;
	Matrix m6;
	Matrix m5;
	Matrix m4;
	Matrix m3;
	Matrix m2;
	Matrix m1;

};