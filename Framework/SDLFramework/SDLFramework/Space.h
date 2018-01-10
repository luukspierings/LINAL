#pragma once

#include "Vector.h"
#include "Matrix.h"
#include "Square.h"
#include "Line.h"
#include "Triangle.h"
#include "Spaceship.h"
#include "Camera.h"
#include "Bullet.h"

#include <math.h>  
#include <vector>

#define RAD_TO_DEGREE (180.0f / 3.14159265358979323846264338327950288f)
#define DEGREE_TO_RAD (3.14159265358979323846264338327950288f / 180.0f)

using namespace std;

class Space {

public:

	float gridW = 1;
	float gridH = 1;


	vector<Matrix> matrixes;

	vector<Bullet> bullets;

	Spaceship spaceship;


	Camera camera{ 900,900 };


	Space() {

		Vector v1({ 0,0,10 });
		Vector v2({ 10,0,0 });
		Vector vOut = v1.out(v2);

		Vector vNegative({ -10,0,0 });

		//vectors.push_back(v1);
		//vectors.push_back(v2);
		//vectors.push_back(vOut);
		//vectors.push_back(vNegative);

		float a1 = vOut.angle(v1);
		float a2 = vOut.angle(v2);
		float a = v1.angle(v2);

		bool independantV1V2 = v1.independent(v2);
		bool independantV2VNegative = v2.independent(vNegative);


		float sW = 5.f;

		matrixes.push_back(Square(Vector({ -2 * sW,sW,sW }), sW));
		matrixes.push_back(Square(Vector({ sW,sW,0 }), sW));
		matrixes.push_back(Square(Vector({ sW,-2*sW,sW }), sW));
		matrixes.push_back(Square(Vector({ -2*sW,-2*sW,0 }), sW));


		matrixes.push_back(Square(Vector({ 0,0,0 }), sW));
		//matrixes.push_back(Square(Vector({ 200,200,0 })));
		//matrixes.push_back(Square(Vector({ -200,200,0 })));

		matrixes.push_back(Line(Vector({ -gridW,0,0 }), Vector({ gridW,0,0 })));
		matrixes.push_back(Line(Vector({ 0,-gridH,0 }), Vector({ 0,gridH,0 })));


	}


	void input(InputManager& inputM) {

		spaceship.input(inputM, *this);

	}

	void update() {

		spaceship.update();

		for (auto& b : bullets) {
			b.update();
		}

		for (auto it = bullets.begin(); it != bullets.end();)
		{
			if (!it->alive()) it = bullets.erase(it);
			else ++it;
		}

	}

	void addBullet() {

		Vector pos{};
		Vector dir{};

		pos = spaceship.frontMiddle();
		dir = spaceship.getDrawableDirection().normalize();

		bullets.push_back(Bullet{pos,dir});

	}

	void draw(FWApplication* app)
	{
		app->SetColor({ 255,255,255,255 });
		app->DrawRect(0, 0, app->getW(), app->getH(), true);


		Vector back = spaceship.backMiddle();
		//back = back + Vector({ 0.7f,0,0 });

		Vector front = spaceship.frontMiddle();
		Vector left = spaceship.backLeft();
		Vector right = spaceship.backRight();
		Vector down = spaceship.backDown();


		Vector up = (back - front).out(left - right);
		up = up.normalize();
		camera.setUp(up);


		Vector birdsEye = (down - back).out((back - right));
		birdsEye.scale(1.f/2.f);
		
		up = (left - right).out(back - front);

		up.scale(1.f/5.f);

		birdsEye = back + (birdsEye + up);

		camera.setLookat(back);
		camera.setEye(birdsEye);



		float wW = app->getW();
		float wH = app->getH();

		for each(Matrix m in matrixes) {
			camera.toDraw(m).draw(app);
		}
		for (auto& b : bullets) {
			camera.toDraw(b.getDrawable()).draw(app);
		}


		camera.toDraw(spaceship.getDrawable()).draw(app);

		if (spaceship.isCrosshairVisible()) {

			Vector direction = spaceship.getDrawableDirection();
			Vector frontV = spaceship.frontMiddle();
			Matrix directionM = direction.getDrawableMatrix(frontV);

			camera.toDraw(directionM).draw(app);

		}

	}

	void scrollDown(FWApplication* app) {
		
	}
	void scrollUp(FWApplication* app) {
	
	}



private:




};