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
#include "Planet.h"
#include "CameraModes.h"

#include <math.h>  
#include <vector>

#define RAD_TO_DEGREE (180.0f / 3.14159265358979323846264338327950288f)
#define DEGREE_TO_RAD (3.14159265358979323846264338327950288f / 180.0f)

using namespace std;


class SpaceView {

public:

	int wW;
	int wH;

	float originSize = 1.f;

	vector<Matrix> matrixes;
	vector<Bullet> bullets;
	Spaceship spaceship;
	Planet planet{ Vector({0,0,0}) };

	Camera camera{ wW, wH };
	CameraModes currentMode = CameraModes::FIRST_PERSON;
	vector<CameraModes> availableCameraModes{
		CameraModes::FIRST_PERSON,
		CameraModes::ARCBALL,
		CameraModes::BIRDS_EYE
	};


	SpaceView(int wW, int wH) : wW(wW), wH(wH) {


		Vector p({ 0,1,1 });
		Vector lP({ 1,0,0 });

		Vector A({ 1,1,1 });
		Vector B({ 2,2,1 });
		Vector C({ 1,2,2 });

		Vector intersection = lP.intersection(A, B, C, p);
		bool inplane = intersection.inPlane(A, B, C);




		float sW = 5.f;

		matrixes.push_back(Square(Vector({ -2 * sW,sW,sW }), sW));
		matrixes.push_back(Square(Vector({ sW,sW,0 }), sW));
		matrixes.push_back(Square(Vector({ sW,-2*sW,sW }), sW));
		matrixes.push_back(Square(Vector({ -2*sW,-2*sW,0 }), sW));

		// helping point for finding origin
		matrixes.push_back(Line(Vector({ -originSize,0,0 }), Vector({ originSize,0,0 })));
		matrixes.push_back(Line(Vector({ 0,-originSize,0 }), Vector({ 0,originSize,0 })));
		matrixes.push_back(Line(Vector({ 0,0,-originSize }), Vector({ 0,0,originSize })));
	}
	

	void input(InputManager& inputM) {

		if (inputM.isKeyPressed("Tab")) {
			auto f = find(availableCameraModes.begin(), availableCameraModes.end(), currentMode);
			f++;
			if (f == availableCameraModes.end()) f = availableCameraModes.begin();
			currentMode = *f;
		}

		switch (currentMode)
		{
		case CameraModes::FIRST_PERSON: 
			spaceship.setCameraPerspective(camera);
			break;
		case CameraModes::ARCBALL:
			camera.inputArcBall(inputM);
			camera.calculateArcBall(spaceship.middle());
			break;
		case CameraModes::BIRDS_EYE:
			camera.inputBirdsEye(inputM);
			camera.calculateBirdsEye();
			break;
		}

		spaceship.input(inputM, *this);
	}

	void update() {

		planet.update();
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

	void addBullet(float relativeVelocity = 0.f) {
		Vector pos = spaceship.frontMiddle();
		Vector dir = spaceship.getDirection().normalize();

		bullets.push_back(Bullet{pos, dir, relativeVelocity});
	}

	void draw(FWApplication* app)
	{
		// Background
		app->SetColor(Colors::black());
		app->DrawRect(0, 0, app->getW(), app->getH(), true);

		camera.toDraw(planet).draw();

		for each(Matrix m in matrixes) {
			camera.toDraw(m).draw();
		}
		for (auto& b : bullets) {
			camera.toDraw(b).draw();
		}

		camera.toDraw(spaceship.getDrawable()).draw();

		if (spaceship.isCrosshairVisible()) camera.toDraw(spaceship.getDrawableCrosshair()).draw();
		
	}


private:




};