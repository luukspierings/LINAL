#include "stdafx.h"

#include "RotationMatrix.h"

RotationMatrix::RotationMatrix(float degrees, Vector rotationAxis, Vector rotationPoint)
{
	degrees *= DEGREE_TO_RAD;

	float rX = rotationAxis.values[0];
	float rY = rotationAxis.values[1];
	float rZ = rotationAxis.values[2];

	float T1 = atan2(rZ, rX);
	float T2 = atan2(rY, sqrt((rX * rX) + (rZ * rZ)));

	m7 = Matrix({ { 1,0,0,0 },{ 0,1,0,0 },{ 0,0,1,0 },{ rotationPoint.values[0], rotationPoint.values[1], rotationPoint.values[2], 1 } });
	m6 = Matrix({ { cos(T1),0,sin(T1),0 },{ 0,1,0,0 },{ -sin(T1),0,cos(T1),0 },{ 0,0,0,1 } });
	m5 = Matrix({ { cos(T2), sin(T2),0,0 },{ -sin(T2),cos(T2),0,0 },{ 0,0,1,0 },{ 0,0,0,1 } });
	m4 = Matrix({ { 1,0,0,0 },{ 0,cos(degrees),sin(degrees),0 },{ 0,-sin(degrees),cos(degrees),0 },{ 0,0,0,1 } });
	m3 = Matrix({ { cos(T2),-sin(T2),0,0 },{ sin(T2),cos(T2),0,0 },{ 0,0,1,0 },{ 0,0,0,1 } });
	m2 = Matrix({ { cos(T1),0,-sin(T1),0 },{ 0,1,0,0 },{ sin(T1),0,cos(T1),0 },{ 0,0,0,1 } });
	m1 = Matrix({ { 1,0,0,0 },{ 0,1,0,0 },{ 0,0,1,0 },{ 0 - rotationPoint.values[0], 0 - rotationPoint.values[1], 0 - rotationPoint.values[2], 1 } });

}

Matrix RotationMatrix::operator*(const Matrix & m)
{
	Matrix newM{ m };
	newM.fitToDimension(m1.amount());
	newM = newM * m1 * m2 * m3 * m4 * m5 * m6 * m7;
	newM.fitToDimension(m.dimension());
	return newM;
}
