#pragma once

#include "Matrix.h"
#include "Vector.h"

class ScalingMatrix {


public:

	ScalingMatrix(int size = 3, float scaling = 1);
	ScalingMatrix(vector<float> scales);
	ScalingMatrix(Vector vector) : ScalingMatrix(vector.values) { };

	Matrix ScalingMatrix::operator*(const Matrix & m);

private:

	Matrix scalingM;

};

