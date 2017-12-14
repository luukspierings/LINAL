#pragma once

#include "Vector.h"
#include "Matrix.h"
#include "Square.h"
#include "Triangle.h"
#include "Spaceship.h"

#include <math.h>  
#include <vector>

#define RAD_TO_DEGREE (180.0f / 3.14159265358979323846264338327950288f)
#define DEGREE_TO_RAD (3.14159265358979323846264338327950288f / 180.0f)

using namespace std;

class Space {

public:


	vector<Vector> vectors;

	vector<Matrix> matrixes;

	float zoom = 1;
	float zoomrate = 1.1f;

	float rotationrate = 5.f;

	float gridW = 1000;
	float gridH = 1000;
	float gridSize = 10;

	Spaceship spaceship;


	Space() {

		Vector v1({ 0,0,10 });
		Vector v2({ 10,0,0 });
		Vector vOut = v1.out(v2);

		Vector vNegative({-10,0,0});

		//vectors.push_back(v1);
		//vectors.push_back(v2);
		//vectors.push_back(vOut);
		//vectors.push_back(vNegative);

		float a1 = vOut.angle(v1);
		float a2 = vOut.angle(v2);
		float a = v1.angle(v2);

		bool independantV1V2 = v1.independent(v2);
		bool independantV2VNegative = v2.independent(vNegative);


	}


	void input(InputManager& inputM) {

		spaceship.input(inputM);

	}

	void update() {

		spaceship.update();

	}


	void draw(FWApplication* app) 
	{

		app->SetColor({ 255,255,255,255 });
		app->DrawRect(0,0,app->getW(),app->getH(),true);

		float offsetX = static_cast<float>(app->getW() / 2);
		float offsetY = static_cast<float>(app->getH() / 2);

		Matrix zoomM({ 
			{ zoom,0,0,1 },
			{ 0,-zoom,0,1 },
			{ 0, 0,1,1 },
			{ offsetX,offsetY,0,1 } 
		});

		for each(Vector v in vectors){
			((v.getDrawableMatrix())*zoomM).draw(app);
		}

		(spaceship.getDrawable() * zoomM).draw(app);
		if(spaceship.isCrosshairVisible())((spaceship.getDrawableDirection().getDrawableMatrix(spaceship.getDrawable().values[5]))*zoomM).draw(app);

	}

	void scrollDown(FWApplication* app) {
		if (app->getW() / (zoom/zoomrate) < 2*gridW) {
			zoom /= zoomrate;
		}
	}
	void scrollUp(FWApplication* app) {
		zoom *= zoomrate;
	}
	


private:




};