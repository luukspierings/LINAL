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


	// 2 polygons for each side

	Polygon f1{ 0, 1, 2, color };
	f1.setVisibilityAC(false);

	Polygon f2{ 0, 2, 3, color };
	f2.setVisibilityAB(false);

	Polygon l1{ 0, 1, 5, color };
	l1.setVisibilityAC(false);

	Polygon l2{ 0, 4, 5, color };
	l2.setVisibilityAC(false);

	Polygon r1{ 3, 2, 6, color };
	r1.setVisibilityAC(false);

	Polygon r2{ 3, 7, 6, color };
	r2.setVisibilityAC(false);

	Polygon b1{ 4, 5, 7, color };
	b1.setVisibilityBC(false);

	Polygon b2{ 5, 6, 7, color };
	b2.setVisibilityAC(false);

	Polygon u1{ 1, 2, 5, color };
	u1.setVisibilityBC(false);

	Polygon u2{ 2, 5, 6, color };
	u2.setVisibilityAB(false);

	Polygon d1{ 0, 3, 4, color };
	d1.setVisibilityBC(false);

	Polygon d2{ 3, 4, 7, color };
	d2.setVisibilityAB(false);


	polygons.push_back(f1);
	polygons.push_back(f1);

	polygons.push_back(l1);
	polygons.push_back(l2);
	
	polygons.push_back(r1);
	polygons.push_back(r2);

	polygons.push_back(b1);
	polygons.push_back(b2);

	polygons.push_back(u1);
	polygons.push_back(u2);

	polygons.push_back(d1);
	polygons.push_back(d2);



	//polygons.push_back(Polygon{ 0, 1, 2, color });
	//polygons.push_back(Polygon{ 0, 2, 3, color });

	//// left side
	//polygons.push_back(Polygon{ 0, 1, 5, color });
	//polygons.push_back(Polygon{ 0, 4, 5, color });

	//// right side
	//polygons.push_back(Polygon{ 3, 2, 6, color });
	//polygons.push_back(Polygon{ 3, 7, 6, color });

	//// back side
	//polygons.push_back(Polygon{ 4, 5, 7, color });
	//polygons.push_back(Polygon{ 5, 6, 7, color });

	//// up side
	//polygons.push_back(Polygon{ 1, 2, 5, color });
	//polygons.push_back(Polygon{ 2, 5, 6, color });

	//// down side
	//polygons.push_back(Polygon{ 0, 3, 4, color });
	//polygons.push_back(Polygon{ 3, 4, 7, color });


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
