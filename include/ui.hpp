#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

class UI
{
	public:
		UI();
		~UI();
		bool init();
		bool loadMedia();
		bool isRunning();
		void checkEvents();
		void quit();
	private:
		SDL_Window *window;
		SDL_Texture *texture;
		SDL_Surface *screen;
		SDL_Surface *testBMP;
		SDL_Event event;
		bool running;
};