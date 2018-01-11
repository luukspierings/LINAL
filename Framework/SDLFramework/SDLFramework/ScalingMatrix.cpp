#include "stdafx.h"

#include "ScalingMatrix.h"

ScalingMatrix::ScalingMatrix(int size, float scaling)
{
	for (int dimensionX = 1; dimensionX <= size; dimensionX++) {
		vector<float> c{};
		for (int dimensionY = 1; dimensionY <= size; dimensionY++) {
			if (dimensionX == dimensionY) c.push_back(scaling);
			else c.push_back(0);
		}
		scalingM.addValue(c);
	}
}

ScalingMatrix::ScalingMatrix(vector<float> scales)
{
	for (int dimensionX = 1; dimensionX <= scales.size(); dimensionX++) {
		vector<float> c{};
		for (int dimensionY = 1; dimensionY <= scales.size(); dimensionY++) {
			if (dimensionX == dimensionY) c.push_back(scales[dimensionX-1]);
			else c.push_back(0);
		}
		scalingM.addValue(c);
	}
}

Matrix ScalingMatrix::operator*(const Matrix & m)
{
	Matrix newM{ m };
	newM = newM * scalingM;
	return newM;
}
