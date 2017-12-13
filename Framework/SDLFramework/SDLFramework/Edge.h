#pragma once

#include "Vertex.h"

class Edge {



public:

	Edge(Vertex* vertex1, Vertex* vertex2, int w){
		vertexA = vertex1;
		vertexB = vertex2;
		weight = w;
		visited = false;
	};


	Vertex* vertexA;
	Vertex* vertexB;
	int weight;
	bool visited;

	void draw(FWApplication* app) {

		if (visited) app->SetColor(Color(200, 0, 0, 255));
		else if (weight == 1) app->SetColor(Color(105, 105, 105, 255));
		else if (weight == 2) app->SetColor(Color(64, 164, 223, 255));
		else if (weight == 3) app->SetColor(Color(120, 72, 0, 255));

		app->DrawLine(vertexA->getMiddleX()-2, vertexA->getMiddleY()-2, vertexB->getMiddleX()-2, vertexB->getMiddleY()-2);
		app->DrawLine(vertexA->getMiddleX()+2, vertexA->getMiddleY()+2, vertexB->getMiddleX()+2, vertexB->getMiddleY()+2);

	}


private:




};