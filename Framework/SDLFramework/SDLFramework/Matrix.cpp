#include "Matrix.h"

#include "Vector.h"


void Matrix::draw(FWApplication* app) {

	app->SetColor(color);

	/*float lastX = values.back()[0];
	float lastY = values.back()[1];

	for (auto v : values)
	{
		app->DrawLine(lastX, lastY, v[0], v[1]);

		lastX = v[0];
		lastY = v[1];
	}*/

	for (auto e : edges)
	{
		app->DrawLine(values[e.first][0], values[e.first][1], values[e.second][0], values[e.second][1]);
	}


}

void Matrix::addValue(vector<float> value) {
	values.push_back(value);
}

void Matrix::addEdge(int v1, int v2)
{
	edges.push_back(pair<int, int>(v1, v2));
}

Matrix Matrix::operator*(const Matrix & trans)
{
	vector<vector<float>> matrix;
	if (values[0].size() != trans.values.size()) {
		for (int Vcolumn = 0; Vcolumn < values.size(); Vcolumn++) {
			values[Vcolumn].push_back(1);
		}

		matrix = Matrix(values).translate(trans).values;

		for (int Vcolumn = 0; Vcolumn < matrix.size(); Vcolumn++) {
			matrix[Vcolumn].pop_back();
			values[Vcolumn].pop_back();
		}

	}
	else {
		matrix = Matrix(values).translate(trans).values;
	}

	return Matrix(matrix, color, edges);
}

Matrix Matrix::translate(Matrix t) {

	vector<vector<float>> matrix;

	for (int Vcolumn = 0; Vcolumn < values.size(); Vcolumn++)
	{
		matrix.push_back(vector<float>());
		for (int Trow = 0; Trow < t.values[0].size(); Trow++)
		{
			float newV = 0;

			for (int cal = 0; cal < t.values[0].size(); cal++) {
				newV += (values[Vcolumn][cal] * t.values[cal][Trow]);
			}

			matrix[Vcolumn].push_back(newV);
		}
	}
	return Matrix{ matrix, color, edges };
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

Vector Matrix::middleTranslation() {

	vector<float> midP = middlePoint().values;
	for (int r = 0; r < values[0].size(); r++) {
		midP[r] -= values[0][r];
	}
	return Vector(midP);
}


Matrix Matrix::rotate(float degrees, char direction) {

	Vector middle = middlePoint();

	degrees *= DEGREE_TO_RAD;

	Matrix m(*this);

	middle.scale(-1.f);
	m = m * middle.getTranslatableMatrix();

	Matrix r;
	switch (direction) {
	case 'z':
		r = Matrix({ { cos(degrees),sin(degrees),0 },{ -sin(degrees),cos(degrees),0 },{ 0,0,1 } });
		break;
	case 'x':
		r = Matrix({ { 1,0,0 },{ 0,cos(degrees),sin(degrees) },{ 0,-sin(degrees), cos(degrees) } });
		break;
	case 'y':
		r = Matrix({ { cos(degrees),0,sin(degrees) },{ 0,1,0 },{ -sin(degrees),0,cos(degrees) } });
		break;
	}
	
	m = m * r;

	middle.scale(-1.f);
	m = m * middle.getTranslatableMatrix();

	return m;
}







