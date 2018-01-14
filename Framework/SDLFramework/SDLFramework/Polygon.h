#pragma once

#include "FWApplication.h"
#include "Colors.h"

#include <vector>

class Matrix;
class Polygon {

public:

	Polygon(int A, int B, int C, Color color = Colors::white()) : A(A), B(B), C(C), color(color) {};
	
	void setVisibilityAB(bool visibility) { visibleAB = visibility; };
	void setVisibilityAC(bool visibility) { visibleAC = visibility; };
	void setVisibilityBC(bool visibility) { visibleBC = visibility; };

	void draw(Matrix* object);
	void drawLine(vector<float> pointA, vector<float> pointB);

	Color color;

	int A;
	int B;
	int C;

	bool visibleAB = true;
	bool visibleAC = true;
	bool visibleBC = true;

};
