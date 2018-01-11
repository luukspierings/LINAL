#include "stdafx.h"

#include "Triangle.h"

Triangle::Triangle(Vector position, int size)
{
	if (position.values.size() < 3) return;

	float x = position.values[0];
	float y = position.values[1];
	float z = position.values[2];
	float xS = x + size;
	float yS = y + size;
	float zS = z + size;

	addValue({ x,y,z });
	addValue({ xS,y,z });
	addValue({ xS,y,zS });
	addValue({ x,y,zS });

	addValue({ x + (size / 2), yS, z + (size / 2) });

	addEdge(0, 1);
	addEdge(1, 2);
	addEdge(2, 3);
	addEdge(3, 0);

	addEdge(0, 4);
	addEdge(1, 4);
	addEdge(2, 4);
	addEdge(3, 4);

}
