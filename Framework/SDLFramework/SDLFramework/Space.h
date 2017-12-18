#pragma once

#include "Vector.h"
#include "Matrix.h"
#include "Square.h"
#include "Line.h"
#include "Triangle.h"
#include "Spaceship.h"
#include "Camera.h"

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

	float gridW = 1;
	float gridH = 1;
	float gridSize = 10;

	Spaceship spaceship;


	Camera camera{ 900,900 };


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


		float sW = 1.f;

		matrixes.push_back(Square(Vector({ -2 * sW,sW,0 }), sW));
		matrixes.push_back(Square(Vector({ sW,sW,0 }), sW));
		matrixes.push_back(Square(Vector({ sW,-2*sW,0 }), sW));
		matrixes.push_back(Square(Vector({ -2*sW,-2*sW,0 }), sW));
		

		//matrixes.push_back(Square(Vector({ 200,-200,0 })));
		//matrixes.push_back(Square(Vector({ 200,200,0 })));
		//matrixes.push_back(Square(Vector({ -200,200,0 })));

		matrixes.push_back(Line(Vector({ -gridW,0,0 }), Vector({ gridW,0,0 })));
		matrixes.push_back(Line(Vector({ 0,-gridH,0 }), Vector({ 0,gridH,0 })));

		
	}


	void input(InputManager& inputM) {

		spaceship.input(inputM);

		if (inputM.isKeyDown("A")) matrixes[0] = matrixes[0].rotate(2.f, 'y');
		if (inputM.isKeyDown("D")) matrixes[0] = matrixes[0].rotate(-2.f, 'y');
		if (inputM.isKeyDown("S")) matrixes[0] = matrixes[0].rotate(-2.f, 'x');
		if (inputM.isKeyDown("W")) matrixes[0] = matrixes[0].rotate(2.f, 'x');

		if (inputM.isKeyDown("Up")) camera.moveCamera(Vector({ 0,0,0.1f,0 }));
		if (inputM.isKeyDown("Down")) camera.moveCamera(Vector({ 0,0,-0.1f,0 }));
		if (inputM.isKeyDown("Left")) camera.moveCamera(Vector({ -0.1f,0,0,0 }));
		if (inputM.isKeyDown("Right")) camera.moveCamera(Vector({ 0.1f,0,0,0 }));


	}

	void update() {

		//spaceship.update();

	}


	void draw(FWApplication* app) 
	{
		app->SetColor({ 255,255,255,255 });
		app->DrawRect(0,0,app->getW(),app->getH(),true);


		//Vector back(spaceship.getDrawable().values[6]);
		//Vector front(spaceship.getDrawable().values[5]);


		//Vector eye({back.values[0],back.values[1], back.values[2] ,1});
		//Vector lookAt({ front.values[0],front.values[1], front.values[2] ,1 });

		

		float wW = app->getW();
		float wH = app->getH();
		float offsetX = static_cast<float>(app->getW() / 2);
		float offsetY = static_cast<float>(app->getH() / 2);



		/*Matrix zoomM({ 
			{ zoom,0,0,1 },
			{ 0,-zoom,0,1 },
			{ 0, 0,1,1 },
			{ offsetX,offsetY,0,1 } 
		});*/


		for each(Vector v in vectors){

			/*Matrix newM((v.getDrawableMatrix()).x(camera));

			newM.draw(app);*/
		}

		for each(Matrix m in matrixes) {
			camera.toDraw(m).draw(app);
		}

/*
		(spaceship.getDrawable().x(camera) ).draw(app);
		if (spaceship.isCrosshairVisible()) {

			Vector direction = spaceship.getDrawableDirection();
			Vector frontV = spaceship.getDrawable().values[5];
			Matrix directionM = direction.getDrawableMatrix(frontV);

			Matrix directionZoomed = directionM.x( camera) ;

			directionZoomed.draw(app);

		}*/

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