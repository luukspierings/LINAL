#include "stdafx.h"

#include "Square.h"

Square::Square(Vector position, float size, Color color)
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

	// back middle
	addValue({ x + (size / 2),y+(size/2),z });


	// 2 polygons for each side
	//// front
	//polygons.push_back(Polygon{ make_shared<Matrix>(*this), 0, 1, 2, color });
	//polygons.push_back(Polygon{ make_shared<Matrix>(*this), 0, 2, 3, color });

	//// left side
	//polygons.push_back(Polygon{ make_shared<Matrix>(*this), 0, 1, 5, color });
	//polygons.push_back(Polygon{ make_shared<Matrix>(*this), 0, 4, 5, color });

	//// right side
	//polygons.push_back(Polygon{ make_shared<Matrix>(*this), 3, 2, 6, color });
	//polygons.push_back(Polygon{ make_shared<Matrix>(*this), 3, 7, 6, color });

	//// back side
	//polygons.push_back(Polygon{ make_shared<Matrix>(*this), 4, 5, 7, color });
	//polygons.push_back(Polygon{ make_shared<Matrix>(*this), 5, 6, 7, color });

	//// up side
	//polygons.push_back(Polygon{ make_shared<Matrix>(*this), 1, 2, 5, color });
	//polygons.push_back(Polygon{ make_shared<Matrix>(*this), 2, 5, 6, color });

	//// down side
	//polygons.push_back(Polygon{ make_shared<Matrix>(*this), 0, 3, 4, color });
	//polygons.push_back(Polygon{ make_shared<Matrix>(*this), 3, 4, 7, color });

	// front
	polygons.push_back(Polygon{ 0, 1, 2, color });
	polygons.push_back(Polygon{ 0, 2, 3, color });

	// left side
	polygons.push_back(Polygon{ 0, 1, 5, color });
	polygons.push_back(Polygon{ 0, 4, 5, color });

	// right side
	polygons.push_back(Polygon{ 3, 2, 6, color });
	polygons.push_back(Polygon{ 3, 7, 6, color });

	// back side
	polygons.push_back(Polygon{ 4, 5, 7, color });
	polygons.push_back(Polygon{ 5, 6, 7, color });

	// up side
	polygons.push_back(Polygon{ 1, 2, 5, color });
	polygons.push_back(Polygon{ 2, 5, 6, color });

	// down side
	polygons.push_back(Polygon{ 0, 3, 4, color });
	polygons.push_back(Polygon{ 3, 4, 7, color });


	//// front lines
	//addEdge(0, 1);
	//addEdge(1, 2);
	//addEdge(2, 3);
	//addEdge(3, 0);

	//// back lines
	//addEdge(4, 5);
	//addEdge(5, 6);
	//addEdge(6, 7);
	//addEdge(7, 4);

	//// lines between front and back
	//addEdge(0, 4);
	//addEdge(1, 5);
	//addEdge(2, 6);
	//addEdge(3, 7);

}
