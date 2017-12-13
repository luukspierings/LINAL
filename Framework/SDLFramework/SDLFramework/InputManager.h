#pragma once


using namespace std;

#include "Vector.h"

class InputManager {

public:
	InputManager();

	void update();
	bool isKeyDown(const char* key) const;
	Vector getMouseLocation() const;
	bool isLeftMouseDown() const;
	bool isRightMouseDown() const;
	bool isMiddleMouseDown() const;
private:
	const unsigned char* keyStates;

};