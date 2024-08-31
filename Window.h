#ifndef WINDOW_H
#define WINDOW_H
#include <SDL2/SDL.h>


/* Sets constants */
#define WIDTH 800
#define HEIGHT 600
#define DELAY 3000

SDL_Window * createWindow (int argc, char **argv);

#endif //WINDOW_H