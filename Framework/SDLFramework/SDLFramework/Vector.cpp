#include "stdafx.h"
#include "Vector.h"
#include "Matrix.h"

float Vector::length() {
	float l = 0.f;
	for (float &f : values) {
		l += (f*f);
	}
	return sqrt(l);
}

Matrix Vector::getDrawableMatrix(Vector startPos) {
	vector<vector<float>> v;
	v.push_back({});
	v.push_back({});
	for (int n = 0; n < values.size(); n++) {
		v[0].push_back(startPos.values[n]);
		v[1].push_back(startPos.values[n] + values[n]);
	}
	Matrix m(v, Colors::orange());
	m.addEdge(0, 1);
	return m;
}

void Vector::scale(float scalair) {
	for (float v = 0; v < values.size(); v++) {
		values[v] *= scalair;
	}
}

Vector Vector::negative() {
	scale(-1);
	return *this;
}

Vector Vector::normalize()
{
	vector<float> v;
	float l = length();
	for (auto n : values) {
		if(l != 0.f) v.push_back(n/l);
		else v.push_back(0.f);
	}
	return Vector(v);
}

float Vector::in(Vector vec) {
	float v = 0.f;
	for (float i = 0; i < values.size() && i < vec.values.size(); i++) {
		v += values[i] * vec.values[i];
	}
	return v;
}
Vector Vector::out(Vector vec) {
	vector<float> v;
	if (values.size() >= 3) {
		v.push_back((values[1] * vec.values[2]) - (values[2] * vec.values[1]));
		v.push_back((values[2] * vec.values[0]) - (values[0] * vec.values[2]));
		v.push_back((values[0] * vec.values[1]) - (values[1] * vec.values[0]));
	}
	return Vector{ v };
}

float Vector::angle(Vector vec) {

	float lengthAB = length() * vec.length();

	float cosFormula = (lengthAB == 0.f) ? 0.f : in(vec) / lengthAB;

	return RAD_TO_DEGREE * acos(cosFormula);
}

bool Vector::independent(Vector vec) {
	float a = angle(vec);
	return (a != 0.f && a != 180.f);
}



