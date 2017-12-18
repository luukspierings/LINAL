#include "Square.h"

Square::Square(Vector position, float size)
{

	if (position.values.size() < 3) return;

	float x = position.values[0];
	float y = position.values[1];
	float z = position.values[2];
	float xS = x + size;
	float yS = y + size;
	float zS = z + size;

	addValue({ x,y,z });
	addValue({ x,yS,z });
	addValue({ xS,yS,z });
	addValue({ xS,y,z });

	// back coords
	addValue({ x,y,zS });
	addValue({ x,yS,zS });
	addValue({ xS,yS,zS });
	addValue({ xS,y,zS });

	// front lines
	addEdge(0, 1);
	addEdge(1, 2);
	addEdge(2, 3);
	addEdge(3, 0);

	// back lines
	addEdge(4, 5);
	addEdge(5, 6);
	addEdge(6, 7);
	addEdge(7, 4);

	// lines between front and back
	addEdge(0, 4);
	addEdge(1, 5);
	addEdge(2, 6);
	addEdge(3, 7);


	//test
	//addEdge(0, 6);

}
