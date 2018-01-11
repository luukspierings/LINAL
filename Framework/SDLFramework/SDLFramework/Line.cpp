#include "stdafx.h"

#include "Line.h"
#include "Colors.h"

Line::Line(Vector position, Vector positionTo)
{
	if (position.values.size() < 3) return;

	addValue({ position.values[0], position.values[1], position.values[2] });
	addValue({ positionTo.values[0], positionTo.values[1], positionTo.values[2] });

	addEdge(0, 1);

	color = Colors::cyan();

}
