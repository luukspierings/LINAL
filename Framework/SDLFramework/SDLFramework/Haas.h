#pragma once

class Haas {

public:

	Vertex* vertex;

	void draw(FWApplication* app) {

		app->DrawTexture(app->LoadTexture("rabbit.png"), vertex->getX(), vertex->getY(), 25, 25);

	}

private:



};