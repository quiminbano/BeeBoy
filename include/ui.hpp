#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define SCALE 4
#define WINDOW_GAP 20

class UI
{
	public:
		UI();
		~UI();
		bool init();
		bool isRunning();
		void checkEvents();
		void quit();
	private:
		/* Game */
		SDL_Window *gameWindow;
		SDL_Renderer *gameRenderer;
		SDL_Texture *gameTexture;
		SDL_Surface *gameScreen;
		
		/* Sprite */
		// SDL_Window *spriteWindow;
		// SDL_Renderer *spriteRenderer;
		// SDL_Texture *spriteTexture;
		// SDL_Surface *spriteScreen;
		
		/* Debug */
		SDL_Window *debugWindow;
		SDL_Renderer *debugRenderer;
		SDL_Texture *debugTexture;
		SDL_Surface *debugScreen;

		/* Other SDL stuff */
		SDL_Surface *testBMP;
		SDL_Event event;

		/* Variables */
		bool running;
};