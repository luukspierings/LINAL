#pragma once

#include "FWApplication.h"
#include "Vector.h"

#include <math.h>  
#include <vector>

#define RAD_TO_DEGREE (180.0f / 3.14159265358979323846264338327950288f)
#define DEGREE_TO_RAD (3.14159265358979323846264338327950288f / 180.0f)

using namespace std;

class Matrix {

public:

	vector<pair<int,int>> edges;

	vector<vector<float>> values;
	//       (n) v1  v2  v3 
	//  n.1(x)  [ 1 
	//  n.2(y)  [ 2
	//  1.2(z)  [ 4


	Color color;

	Matrix(vector<vector<float>> v = {}, Color color = { 0,0,250,255 }, vector<pair<int, int>> edges = {}) :
		color(color), 
		values(v),
		edges(edges)
	{}

	void draw(FWApplication* app);

	void addValue(vector<float> value);
	void addEdge(int v1, int v2);


	Matrix x(const Matrix & trans);
	Matrix translate(Matrix t = Matrix());


	Vector middlePoint();
	Vector middleTranslation();


	Matrix rotate(float degrees, Vector rotationAxis, Vector rotationPoint = Vector({0,0,0}));

	Matrix Matrix::operator*(const Matrix & trans);


private:





};