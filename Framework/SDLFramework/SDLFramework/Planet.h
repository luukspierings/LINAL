#pragma once

using namespace std;

#include "Matrix.h"
#include "Square.h"
#include "Vector.h"
#include "ScalingMatrix.h"
#include "TranslationMatrix.h"
#include "Colors.h"

class Planet: public Square {

public:
	Planet(Vector position = Vector({ 0,0,0 }), float size = 10.f) : originalSize(size), size(size), Square(position, size, Colors::green()) {};

	void update();

private:

	float originalSize;
	float size;
	float expansionStep = 0.005f;
	float minExpansion = originalSize;
	float maxExpansion = originalSize + 1.f;
	bool expanding = true;


};








