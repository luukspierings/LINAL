#include "stdafx.h"

#include "Matrix.h"


//void Matrix::draw(FWApplication* app) {
//
//	app->SetColor(color);
//
//	for (auto e : edges)
//	{
//		if ((values[e.first].size() > 3 && values[e.first][3] < 0.f) || (values[e.second].size() > 3 && values[e.second][3] < 0.f)) {
//			continue;
//		}
//		app->DrawLine(values[e.first][0], values[e.first][1], values[e.second][0], values[e.second][1]);
//	}
//
//}

void Matrix::addValue(vector<float> value) {
	values.push_back(value);
}

void Matrix::addRow(float v)
{
	for (int Vcolumn = 0; Vcolumn < values.size(); Vcolumn++) {
		values[Vcolumn].push_back(v);
	}
}

void Matrix::addRow(Vector v)
{
	for (int Vcolumn = 0; Vcolumn < v.values.size(); Vcolumn++) {
		values[Vcolumn].push_back(v.values[Vcolumn]);
	}
}

void Matrix::removeRow()
{
	for (int Vcolumn = 0; Vcolumn < values.size(); Vcolumn++) {
		values[Vcolumn].pop_back();
	}
}

void Matrix::fitToDimension(int d)
{
	while (dimension() < d) addRow();
	while (dimension() > d) removeRow();
}

Matrix Matrix::operator*(const Matrix & m)
{
	if (dimension() != m.amount()) return Matrix{ *this };

	Matrix matrix{ *this };
	matrix.values.clear();

	for (int Vcolumn = 0; Vcolumn < values.size(); Vcolumn++)
	{
		vector<float> vector{};
		for (int Trow = 0; Trow < m.values[0].size(); Trow++)
		{
			float newV = 0;
			for (int cal = 0; cal < m.values[0].size(); cal++) {
				float v1 = values[Vcolumn][cal];
				float v2 = m.values[cal][Trow];
				if ((v1 + 0.0) != 0.f && (v2 + 0.0) != 0.f) newV += (v1 * v2);
			}
			vector.push_back(newV);
		}
		matrix.values.push_back(vector);
	}
	return matrix;
}

void Matrix::draw()
{
	for (auto & polygon : polygons) {
		polygon.draw(this);
	}
}

bool Matrix::collidesWith(Vector point, Vector direction)
{
	for (auto & polygon : polygons) {
		if (polygon.collidesWith(this, point, direction)) { return true; };
	}
	return false;
}

Vector Matrix::middlePoint() {

	vector<float> middle;

	for (int r = 0; r < values[0].size(); r++) {
		float avg = 0;
		for (int c = 0; c < values.size(); c++) {
			avg += values[c][r];
		}
		avg /= values.size();
		middle.push_back(avg);
	}

	return Vector(middle);
}







