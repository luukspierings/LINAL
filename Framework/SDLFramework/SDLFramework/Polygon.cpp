#include "Polygon.h"

#include "Matrix.h"

void Polygon::draw(Matrix* object)
{
	FWApplication* app = FWApplication::GetInstance();
	app->SetColor(color);

	if (visibleAB) drawLine(object->values[A], object->values[B]);
	if (visibleAC) drawLine(object->values[A], object->values[C]);
	if (visibleBC) drawLine(object->values[B], object->values[C]);
}

void Polygon::drawLine(vector<float> pointA, vector<float> pointB)
{
	FWApplication* app = FWApplication::GetInstance();

	if ((pointA.size() > 3 && pointA[3] < 0.f) ||
		(pointB.size() > 3 && pointB[3] < 0.f)) {

		app->DrawLine(pointA[0], pointA[1], pointB[0], pointB[1]);
	}
}
