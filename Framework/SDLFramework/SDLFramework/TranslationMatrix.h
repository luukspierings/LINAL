#pragma once

#include "Matrix.h"
#include "Vector.h"

class TranslationMatrix {


public:

	TranslationMatrix(int size = 3, float translation = 0);
	TranslationMatrix(vector<float> scales);
	TranslationMatrix(Vector vector) : TranslationMatrix(vector.values) {};

	Matrix TranslationMatrix::operator*(const Matrix & m);

private:

	Matrix translationM;



};

