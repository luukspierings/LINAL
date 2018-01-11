#pragma once


using namespace std;

#include "Vector.h"
#include <vector>
#include <string>

class InputManager {

public:
	InputManager();

	void update();
	bool isKeyDown(const char* key) const;
	bool isKeyPressed(char* key);

	Vector getMouseLocation() const;
	bool isLeftMouseDown() const;
	bool isRightMouseDown() const;
	bool isMiddleMouseDown() const;



private:
	const unsigned char* keyStates;
	vector<char*> keysPressed;

};