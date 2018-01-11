#pragma once

using namespace std;

#include "Matrix.h"
#include "Square.h"
#include "Vector.h"

class Planet: public Square {

public:
	Planet(Vector position = Vector({ 0,0,0 }), float size = 10) : Square(position, size) {};

	void update();

private:

	float expansion = 1.f;


};








