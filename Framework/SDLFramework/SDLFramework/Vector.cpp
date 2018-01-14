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

Vector Vector::intersection(Vector A, Vector B, Vector C, Vector linePoint)
{
	Vector steun = A;
	Vector richting1 = B - A;
	Vector richting2 = C - A;

	Vector crossABC = richting1.out(richting2);
	float inABC = crossABC.in(A);

	float ABCx = crossABC.values[0];
	float ABCy = crossABC.values[1];
	float ABCz = crossABC.values[2];

	Vector steunL = linePoint;
	Vector richtingL = this->normalize();

	// How much lambda's are in each dimension
	float xLamount = ABCx * richtingL.values[0];
	float yLamount = ABCy * richtingL.values[1];
	float zLamount = ABCz * richtingL.values[2];

	// What value is minus or plus the lambda in each dimension
	float xLvalue = ABCx * steunL.values[0];
	float yLvalue = ABCy * steunL.values[1];
	float zLvalue = ABCz * steunL.values[2];

	// What is the total value of the lambda's
	float lambdaValue = -(xLvalue + yLvalue + zLvalue - inABC);

	// How much lambda's are there
	float lambdaAmount = xLamount + yLamount + zLamount;

	// Calculate the value per lambda
	if(lambdaAmount != 0.f) lambdaValue /= lambdaAmount;
	else lambdaValue = 0.f;

	// Fill in the formula with the value of the lambda
	Vector intersection = steunL + Vector({ lambdaValue * richtingL.values[0], lambdaValue * richtingL.values[1], lambdaValue * richtingL.values[2] });

	return intersection;
}



