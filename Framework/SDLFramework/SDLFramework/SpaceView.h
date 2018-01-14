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
#include "RandomGenerator.h"

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
	Planet planet{ Vector({0, 0, 110}) };

	Camera camera{ wW, wH };
	CameraModes currentMode = CameraModes::FIRST_PERSON;
	vector<CameraModes> availableCameraModes{
		CameraModes::FIRST_PERSON,
		CameraModes::ARCBALL,
		CameraModes::BIRDS_EYE
	};

	int collisionTimer = 0;
	int collisionTimerMax = 20;

	SpaceView(int wW, int wH) : wW(wW), wH(wH) {


		Vector p({ 0,1,1 });
		Vector lP({ 1,0,0 });

		Vector A({ 1,1,1 });
		Vector B({ 2,2,1 });
		Vector C({ 1,2,2 });

		Vector intersection = lP.intersection(A, B, C, p);
		bool inplane = intersection.inPlane(A, B, C);

		float sW = 5.f;
		for (int i = 0; i < 20; i++)
		{
			float randomNumberX = static_cast<float>(RandomGenerator::getInstance().generate(-40, 40));
			float randomNumberY = static_cast<float>(RandomGenerator::getInstance().generate(-40, 40));
			float randomNumberZ = static_cast<float>(RandomGenerator::getInstance().generate(0, 100));
			matrixes.push_back(Square(Vector({randomNumberX, randomNumberY, randomNumberZ}), sW, Color{255,0,0,255}));
		}

		
		/*matrixes.push_back(Square(Vector({ sW,sW,0 }), sW));
		matrixes.push_back(Square(Vector({ sW,-2*sW,sW }), sW));
		matrixes.push_back(Square(Vector({ -2*sW,-2*sW,0 }), sW));*/

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
			if (collisionTimer == collisionTimerMax) {
				for (auto mat = matrixes.begin(); mat != matrixes.end();) {
					if (mat->collidesWith(it->middlePoint(), it->direction)) {
						mat = matrixes.erase(mat);
					}
					else ++mat;
				}
			}

			if (!it->alive()) it = bullets.erase(it);
			else ++it;
		}
		if (collisionTimer == collisionTimerMax) collisionTimer = 0;
		else collisionTimer++;

	}

	void addBullet(float relativeVelocity = 0.f) {
		Vector pos = spaceship.frontMiddle();
		Vector dir = spaceship.getDirection().normalize();

		bullets.push_back(Bullet{pos, dir, relativeVelocity});
	}

	void draw()
	{
		// Background
		FWApplication::GetInstance()->SetColor(Colors::black());
		FWApplication::GetInstance()->DrawRect(0, 0, wW, wH, true);

		Matrix m = camera.toDraw(planet);
			m.draw();

		for each(Matrix m in matrixes) {
			camera.toDraw(m).draw();
		}
		for (auto& b : bullets) {
			camera.toDraw(b).draw();
		}

		Matrix sp = camera.toDraw(spaceship.getDrawable());
			sp.draw();

		if (spaceship.isCrosshairVisible()) camera.toDraw(spaceship.getDrawableCrosshair()).draw();
		
	}


private:




};