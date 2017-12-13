#pragma once

class Koe {


public:

	Vertex* vertex;


	void draw(FWApplication* app) {
		app->DrawTexture(app->LoadTexture("/cow.png"), vertex->getX(), vertex->getY(),25,25);
	}


private:


};