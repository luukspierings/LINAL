#include "stdafx.h"

#include "InputManager.h"

#include <SDL.h>


InputManager::InputManager()
{
	update();
}

void InputManager::update()
{
	SDL_PumpEvents();
	keyStates = SDL_GetKeyboardState(nullptr);
}

bool InputManager::isKeyDown(const char * key) const
{
	return keyStates[SDL_GetScancodeFromName(key)];
}

bool InputManager::isKeyPressed(char * key)
{
	auto f = find(keysPressed.begin(), keysPressed.end(), key);
	if (isKeyDown(key)) {
		if (f == keysPressed.end()) {
			keysPressed.push_back(key);
			return true;
		}
	}
	else {
		if (f != keysPressed.end()) {
			keysPressed.erase(f);
		}
	}
	return false;
}

Vector InputManager::getMouseLocation() const
{
	int x = 0, y = 0;

	SDL_GetMouseState(&x, &y);

	return Vector({static_cast<float>(x), static_cast<float>(y)});
}

bool InputManager::isLeftMouseDown() const
{
	return (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)) == 1;
}

bool InputManager::isRightMouseDown() const
{
	return (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_RIGHT)) == 1;
}

bool InputManager::isMiddleMouseDown() const
{
	return (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_MIDDLE)) == 1;
}