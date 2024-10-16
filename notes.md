# UI

UI uses SDL2 to handle windows and events. We declare SDL-pointers to:
- SDL_Window
- SDL_Renderer
- SDL_Texture
- SDL_Surface

The init() function will initialize these pointers with SDL functions, explained in a bit more detail below.


### SDL_CreateWindow(title, x, y, width, height, flags)

Creates a window. Lets you choose the title, position and size of the window. You can set one or more of the available flags to further customize your window.

The position of the window can be manually set with an integer, or automatically set with:
- SDL_WINDOWPOS_UNDEFINED (usually 0)
- SDL_WINDOWPOS_CENTERED (center on the screen)

Some of the available flags:
- SDL_WINDOW_SHOWN (default)
- SDL_WINDOW_HIDDEN
- SDL_WINDOW_FULLSCREEN
- SDL_WINDOW_FULLSCREEN_DESKTOP
- SDL_WINDOW_BORDERLESS
- SDL_WINDOW_RESIZABLE
- SDL_WINDOW_MINIMIZED
- SDL_WINDOW_MAXIMIZED
- SDL_WINDOW_INPUT_GRABBED
- SDL_WINDOW_MOUSE_FOCUS
- SDL_WINDOW_INPUT_FOCUS
- SDL_WINDOW_ALLOW_HIGHDPI
- SDL_WINDOW_ALWAYS_ON_TOP


### SDL_CreateWindowAndRenderer(width, height, flags, &window, &renderer)

Automatically sets up both the window and the renderer. Allows for less customization than SDL_CreateWindow combined with SDL_CreateRenderer, but you can still use the same flags as in CreateWindow.