#pragma once

#include <math.h>  
#include "Matrix.h"

using namespace std;


class Vector {

public:


	vector<float> values;

	Vector(vector<float> v = {0,0}): values(v) {
		
	}

	float length() {
		float l;
		for (float &f : values) {
			l += (f*f);
		}
		return sqrt(l);
	}

	Matrix getMatrix() {
		return Matrix({ values }, { 250,0,0,255 });
	}

	Matrix getDrawableMatrix() {
		vector<vector<float>> v;
		v.push_back({});
		v.push_back({});
		for (auto z : values) {
			v[0].push_back(0);
			v[1].push_back(z);
		}
		return Matrix(v, { 250,0,0,255 });
	}

	Matrix getTranslatableMatrix() {

		vector<vector<float>> v;
		for (float c = 0; c <= values.size(); c++) {
			v.push_back({});
			for (float r = 0; r <= values.size(); r++) {
				v[c].push_back((c == values.size() && r < values.size())? values[r] : (r == c)? 1 : 0 );
			}
		}
		
		return Matrix(v, { 250,0,0,255 });
	}
	
	
	void scale(float scalair) {
		for (float v = 0; v < values.size(); v++) {
			values[v] *= scalair;
		}
	}

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

	float in(Vector vec) {
		float v;
		for (float i = 0; i < values.size() || i < vec.values.size(); i++) {
			v += values[i] * vec.values[i];
		}
		return v;
	}
	Vector out(Vector vec) {
		vector<float> v;
		if (values.size() == 3) {
			v.push_back((values[1] * vec.values[2]) - (values[2] * vec.values[1]));
			v.push_back((values[2] * vec.values[0]) - (values[0] * vec.values[2]));
			v.push_back((values[0] * vec.values[1]) - (values[1] * vec.values[0]));
		}
		return Vector{v};
	}


private:





};