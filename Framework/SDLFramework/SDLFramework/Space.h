#pragma once

#include "Vector.h"
#include "Matrix.h"
#include "Square.h"
#include "Line.h"
#include "Triangle.h"
#include "Spaceship.h"
#include "Camera.h"
#include "Bullet.h"
#include "Colors.h"

#include <math.h>  
#include <vector>

#define RAD_TO_DEGREE (180.0f / 3.14159265358979323846264338327950288f)
#define DEGREE_TO_RAD (3.14159265358979323846264338327950288f / 180.0f)

using namespace std;


class Space {

public:

	int wW;
	int wH;

	float originSize = 1.f;

	vector<Matrix> matrixes;
	vector<Bullet> bullets;
	Spaceship spaceship;

	Camera camera{ wW, wH };
	bool birdsEyeView = false;


	Space(int wW, int wH) : wW(wW), wH(wH) {

		float sW = 5.f;

		matrixes.push_back(Square(Vector({ -2 * sW,sW,sW }), sW));
		matrixes.push_back(Square(Vector({ sW,sW,0 }), sW));
		matrixes.push_back(Square(Vector({ sW,-2*sW,sW }), sW));
		matrixes.push_back(Square(Vector({ -2*sW,-2*sW,0 }), sW));
		matrixes.push_back(Square(Vector({ 0,0,0 }), sW));
		matrixes.push_back(Square(Vector({ 0,0,-5*sW }), sW));

		// helping point for finding origin
		matrixes.push_back(Line(Vector({ -originSize,0,0 }), Vector({ originSize,0,0 })));
		matrixes.push_back(Line(Vector({ 0,-originSize,0 }), Vector({ 0,originSize,0 })));
		matrixes.push_back(Line(Vector({ 0,0,-originSize }), Vector({ 0,0,originSize })));
	}
	

	void input(InputManager& inputM) {

		if (inputM.isKeyPressed("Tab")) birdsEyeView = !birdsEyeView;

		// Setting birdseye view or first/third person view
		if (birdsEyeView)	camera.input(inputM);
		else				spaceship.setCameraPerspective(camera);

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
		Vector pos = spaceship.frontMiddle();
		Vector dir = spaceship.getDirection().normalize();

		bullets.push_back(Bullet{pos,dir});
	}

	void draw(FWApplication* app)
	{
		// Background
		app->SetColor(Colors::black());
		app->DrawRect(0, 0, app->getW(), app->getH(), true);


		for each(Matrix m in matrixes) {
			camera.toDraw(m).draw(app);
		}
		for (auto& b : bullets) {
			camera.toDraw(b).draw(app);
		}

		camera.toDraw(spaceship.getDrawable()).draw(app);

		if (spaceship.isCrosshairVisible()) camera.toDraw(spaceship.getDrawableCrosshair()).draw(app);
		
	}


private:




};