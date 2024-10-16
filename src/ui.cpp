#include "../include/ui.hpp"

UI::UI()
{
	gameWindow = NULL;
	gameRenderer = NULL;
	gameTexture = NULL;
	gameScreen = NULL;

	// spriteWindow = NULL;
	// spriteRenderer = NULL;
	
	debugWindow = NULL;
	debugRenderer = NULL;
	debugTexture = NULL;
	debugScreen = NULL;

	running = true;
}

UI::~UI() {}

bool UI::init()
{
	/* Initialize SDL */
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
		return false;
	}
	TTF_Init();

	/* Create game window */
	SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, &gameWindow, &gameRenderer);
	if (gameWindow == NULL || gameRenderer == NULL)
	{
		printf("Error creating game window and renderer! SDL_Error: %s\n", SDL_GetError());
		return false;
	}
	SDL_SetWindowTitle(gameWindow, "BeeBoy");

	/* Create debug window */
	SDL_CreateWindowAndRenderer(16 * 8 * SCALE, 16 * 8 * SCALE, 0, &debugWindow, &debugRenderer);
	if (debugWindow == NULL || debugRenderer == NULL)
	{
		printf("Error creating debug window and renderer! SDL_Error: %s\n", SDL_GetError());
		return false;
	}
	SDL_SetWindowTitle(debugWindow, "Debug");
	debugTexture = SDL_CreateTexture(
		debugRenderer,
		SDL_PIXELFORMAT_ARGB8888,
		SDL_TEXTUREACCESS_TARGET,
		16 * 8 * SCALE,
		16 * 8 * SCALE
	);

	/* Position windows */
	int gameX, gameY, debugX, debugY;
	SDL_GetWindowPosition(gameWindow, &gameX, &gameY);
    SDL_SetWindowPosition(debugWindow, gameX + SCREEN_WIDTH + WINDOW_GAP, gameY);
    SDL_GetWindowPosition(debugWindow, &debugX, &debugY);

	return true;
}

bool UI::isRunning()
{
	return running;
}

void UI::checkEvents()
{
    while (SDL_PollEvent(&event) > 0)
    {
        if (event.type == SDL_QUIT)
        {
            // Handle global quit event (this usually triggers when all windows should be closed)
			printf("Quit event detected.\n");
            running = false;
        }
        else if (event.type == SDL_WINDOWEVENT)
        {
            if (event.window.event == SDL_WINDOWEVENT_CLOSE)
            {
                // Check which window is being closed
                if (event.window.windowID == SDL_GetWindowID(gameWindow))
                {
                    printf("Game window closed.\n");
                    running = false; // Stop the main loop, or handle this differently
                }
                else if (event.window.windowID == SDL_GetWindowID(debugWindow))
                {
                    printf("Debug window closed.\n");
                    running = false; // Same here or set up a different condition
                }
            }
        }
    }
}

void UI::quit()
{
	SDL_DestroyWindow(gameWindow);
	gameWindow = NULL;
	SDL_DestroyRenderer(gameRenderer);
	gameRenderer = NULL;
	SDL_DestroyWindow(debugWindow);
	debugWindow = NULL;
	SDL_DestroyRenderer(debugRenderer);
	debugRenderer = NULL;
	SDL_Quit();
}

