#include "stdafx.h"
#include "Polygon.h"

#include "Matrix.h"

void Polygon::draw(Matrix* object)
{
	FWApplication::GetInstance()->SetColor(color);

	if (visibleAB) drawLine(object->values[A], object->values[B]);
	if (visibleAC) drawLine(object->values[A], object->values[C]);
	if (visibleBC) drawLine(object->values[B], object->values[C]);
}

void Polygon::drawLine(vector<float> pointA, vector<float> pointB)
{

	if ((pointA.size() > 3 && pointA[3] < 0.f) ||
		(pointB.size() > 3 && pointB[3] < 0.f)) {
		return;
	}
	FWApplication::GetInstance()->DrawLine(pointA[0], pointA[1], pointB[0], pointB[1]);
}

bool Polygon::collidesWith(Matrix* object, Vector point, Vector direction)
{
	Vector a(object->values[A]);
	Vector b(object->values[B]);
	Vector c(object->values[C]);

	return direction.intersection(a, b, c, point).inPlane(a, b, c);
}

Vector Polygon::collisionIntersection(Matrix * object, Vector point, Vector direction)
{
	Vector a(object->values[A]);
	Vector b(object->values[B]);
	Vector c(object->values[C]);

	return direction.intersection(a, b, c, point);
}
