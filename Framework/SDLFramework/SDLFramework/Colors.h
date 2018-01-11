#pragma once

#include "FWApplication.h"


class Colors
{

public:

	static Color white() { return Color{ 255,255,255,255 }; };
	static Color black() { return Color{ 0,0,0,255 }; };

	static Color red() { return Color{ 255,0,0,255 }; };
	static Color green() { return Color{ 0,255,0,255 }; };
	static Color blue() { return Color{ 0,0,255,255 }; };

	static Color yellow() { return Color{ 255,255,0,255 }; };
	static Color magenta() { return Color{ 255,0,255,255 }; };
	static Color cyan() { return Color{ 0,255,255,255 }; };

	static Color orange() { return Color{ 255,128,0,255 }; };
	static Color purple() { return Color{ 128,0,255,255 }; };

};
