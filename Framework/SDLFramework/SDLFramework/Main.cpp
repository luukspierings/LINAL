#include <vector>
#include <iostream>
#include "Config.h"
#include "FWApplication.h"
#include <SDL_events.h>
#include "SDL_timer.h"
#include <time.h>
#include "Space.h"

using namespace std;

int main(int args[])
{
	//auto window = Window::CreateSDLWindow();
	auto application = new FWApplication(50,50,900,900);
	if (!application->GetWindow())
	{
		LOG("Couldn't create window...");
		return EXIT_FAILURE;
	}
	
	application->SetTargetFPS(60);
	application->SetColor(Color(255, 10, 40, 255));


	InputManager inputManager;

	Space space{ application->getW(), application->getH() };


	while (application->IsRunning())
	{
		application->StartTick();

		SDL_Event event;
		SDL_PumpEvents();
		const unsigned char* keyStates = SDL_GetKeyboardState(nullptr);


		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
				case SDL_QUIT:
					application->Quit();
					break;
			}
		}
		
		
		space.input(inputManager);
		space.update();
		space.draw(application);

		application->EndTick();
	}
		
	return EXIT_SUCCESS;
}