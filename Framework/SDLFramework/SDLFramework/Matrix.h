#pragma once

#include "FWApplication.h"
#include "Vector.h"
#include "Colors.h"

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

	Matrix(vector<vector<float>> v = {}, Color color = Colors::white(), vector<pair<int, int>> edges = {}) :
		color(color), 
		values(v),
		edges(edges)
	{}

	void addValue(vector<float> value);

	int dimension() const { return (values.size() > 0) ? values[0].size() : 0; }
	void addRow(float v = 1.f);
	void addRow(Vector v);
	void removeRow();

	Vector middlePoint();

	Matrix Matrix::operator*(const Matrix & trans);
	Matrix x(const Matrix & trans);
	Matrix translate(Matrix t = Matrix());


	// For drawing the matrix
	vector<pair<int, int>> edges;
	Color color;

	void addEdge(int v1, int v2);
	void draw(FWApplication* app);


private:


};