#pragma once

#include <math.h>  
#include "Matrix.h"

using namespace std;

#define RAD_TO_DEGREE (180.0f / 3.14159265358979323846264338327950288f)
#define DEGREE_TO_RAD (3.14159265358979323846264338327950288f / 180.0f)

class Vector {

public:


	vector<float> values;

	Vector(vector<float> v = {0,0}): values(v) {
		
	}

	Matrix getMatrix();
	Matrix getDrawableMatrix(Vector startPos = Vector({ 0,0,0 }));
	Matrix getTranslatableMatrix();
	
	void scale(float scalair);
	Vector negative();

	float in(Vector vec);
	Vector out(Vector vec);

	float length();
	float angle(Vector vec);

	bool independent(Vector vec);


	Vector Vector::operator+(const Vector & vec)
	{
		vector<float> v;
		for (float i = 0; i < values.size() || i < vec.values.size(); i++) {
			v.push_back(values[i] + vec.values[i]);
		}
		return Vector(v);
	}
	Vector Vector::operator-(const Vector & vec)
	{
		vector<float> v;
		for (float i = 0; i < values.size() || i < vec.values.size(); i++) {
			v.push_back(values[i] - vec.values[i]);
		}
		return Vector(v);
	}

private:





};