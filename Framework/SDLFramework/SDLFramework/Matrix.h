#pragma once

#include "FWApplication.h"
#include "Vector.h"
#include "Colors.h"
#include "Polygon.h"

#include <math.h>  
#include <vector>

#define RAD_TO_DEGREE (180.0f / 3.14159265358979323846264338327950288f)
#define DEGREE_TO_RAD (3.14159265358979323846264338327950288f / 180.0f)

using namespace std;

class Matrix {

public:

	vector<vector<float>> values;
	//       (n) v1  v2  v3 
	//     (x)  [ 1 
	//     (y)  [ 2
	//     (z)  [ 4

	Matrix(vector<vector<float>> v = {}) :
		values(v)
	{}

	void addValue(vector<float> value);
	void addRow(float v = 1.f);
	void addRow(Vector v);
	void removeRow();

	int dimension() const { return (values.size() > 0) ? values[0].size() : 0; }
	int amount() const { return values.size(); }

	void fitToDimension(int d);

	Vector middlePoint();

	Matrix Matrix::operator*(const Matrix & m);


	void draw();

	bool collidesWith(Vector point, Vector direction);

	vector<Polygon> polygons{};


private:


};