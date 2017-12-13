#pragma once
#include "FWApplication.h"
#include <map>

using namespace std;

class Vertex {

public:
	Vertex(int x, int y):x(x),y(y) {
		w = 10;
		h = 10;
	}

	int x;
	int y;

	float getX() {
		return x*offsetXMultiplier;
	}
	float getY() {
		return y*offsetYMultiplier;
	}

	float offsetXMultiplier = 1.5f;
	float offsetYMultiplier = 1.5f;

	int w;
	int h;

	void draw(FWApplication* app) {
		app->SetColor(Color(255, 255, 255, 255));
		app->DrawRect(getX(), getY(), w, h, true);
	}

	float getMiddleX() {
		return getX() + (w / 2);
	}
	float getMiddleY() {
		return getY() + (h / 2);
	}


private:





};