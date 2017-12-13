#pragma once
#include "Graph.h"

#include "Koe.h"
#include "Haas.h"


class Weiland {

public:

	FWApplication* app;

	Graph graph;

	Koe koe;
	Haas haas;


	Weiland(FWApplication* pApp);


	void input() {


	}

	void update() {

	}

	void draw() {
		app->SetColor(Color(44, 176, 55, 255));
		app->DrawRect(0, 0, app->getW(), app->getH(), true);

		app->SetColor(Color(0, 0, 0, 255));
		app->DrawText("Grey (normal): Fast", 70, 10);
		app->DrawText("Blue (water):  Medium", 70, 30);
		app->DrawText("Brown (lane):  Slow", 70, 50);

		graph.draw(app);

		koe.draw(app);
		haas.draw(app);

	}


private:




};