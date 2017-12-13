#pragma once

#include "Vertex.h"
#include "Edge.h"
#include "RandomGenerator.h"

class Graph {


public:

	vector<Vertex*> vertexes;
	vector<Edge*> edges;


	void addVertex(Vertex* vertex) {
		vertexes.push_back(vertex);
	};

	void addEdge(Edge* edge) {
		edges.push_back(edge);
	};


	void draw(FWApplication* app) {
		for (auto e : edges) {
			e->draw(app);
		}
		for (auto v : vertexes) {
			v->draw(app);
		}
	}


	Vertex* getRandomVertex() {
		return vertexes[RandomGenerator::getInstance().generate(0, vertexes.size() - 1)];
	}


	void aStarTo(Vertex* start, Vertex* end);



private:


};