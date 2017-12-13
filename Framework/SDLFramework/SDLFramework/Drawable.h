#pragma once

#include "FWApplication.h"

class Drawable {


public:

	virtual void draw(FWApplication* app) = 0;
	virtual void scrollUp(FWApplication* app) = 0;
	virtual void scrollDown(FWApplication* app) = 0;
	virtual void keyLeft() = 0;
	virtual void keyRight() = 0;


private:


};