#include "../include/ui.hpp"


UI::UI()
{
	window = NULL;
	texture = NULL;
	screen = NULL;
	running = true;
}

UI::~UI() {}

bool UI::init()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
		return false;
	}
	else
	{
		window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
			return false;
		}
		else
		{
			screen = SDL_GetWindowSurface(window);
		}
	}
	return true;
}

bool UI::loadMedia()
{
	testBMP = SDL_LoadBMP("../test.bmp");
	if (testBMP == NULL)
	{
		printf("Unable to load image %s!\n SDL Error: %s\n", "../test.bmp", SDL_GetError());
		return false;
	}

	return true;
}

bool UI::isRunning()
{
	return running;
}

void UI::checkEvents()
{
	if (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
		{
			running = false;
		}
	}
}

void UI::quit()
{
	SDL_FreeSurface(testBMP);
	testBMP = NULL;
	SDL_DestroyWindow(window);
	window = NULL;
	SDL_Quit();
}

