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

	float pointW = 3.f;

	for (auto v : values) {

		if (v[0] < 0.f || v[1] < 0.f) continue;

		/*app->DrawLine(v[0], v[1], v[0] + pointW, v[1]);
		app->DrawLine(v[0], v[1], v[0], v[1] + pointW);
		app->DrawLine(v[0] + pointW, v[1] + pointW, v[0] + pointW, v[1]);
		app->DrawLine(v[0] + pointW, v[1] + pointW, v[0], v[1] + pointW);*/

	}


	for (auto e : edges)
	{
		if (values[e.first][0] < 0.f || values[e.first][1] < 0.f || values[e.second][0] < 0.f || values[e.second][1] < 0.f) continue;

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

Matrix Matrix::x(const Matrix & trans) {
	vector<vector<float>> matrix = values;
	if (matrix[0].size() > trans.values.size()) {
		for (int Vcolumn = 0; Vcolumn < matrix.size(); Vcolumn++) {
			matrix[Vcolumn].push_back(1.f);
		}

		matrix = Matrix(matrix).translate(trans).values;

		/*for (int Vcolumn = 0; Vcolumn < matrix.size(); Vcolumn++) {
			matrix[Vcolumn].pop_back();
			values[Vcolumn].pop_back();
		}*/

	}
	else if (matrix[0].size() < trans.values.size()) {
		for (int Vcolumn = 0; Vcolumn < matrix.size(); Vcolumn++) {
			matrix[Vcolumn].push_back(1.f);
		}

		matrix = Matrix(matrix).translate(trans).values;
	}
	else {
		matrix = Matrix(matrix).translate(trans).values;
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
				float v1 = values[Vcolumn][cal];
				float v2 = t.values[cal][Trow];
				if((v1+0.0) != 0.f && (v2+0.0) != 0.f) newV += (v1 * v2);
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







