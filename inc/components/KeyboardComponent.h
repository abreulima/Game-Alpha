#ifndef KEYBOARD_COMPONENT_H
#define KEYBOARD_COMPONENT_H

#include <SDL2/SDL.h>

typedef struct {
	Uint8 *key_state;
	SDL_Scancode left;
	SDL_Scancode right;
	SDL_Scancode up;
	SDL_Scancode down;
	SDL_Scancode attack;
} KeyboardComponent;

#endif //KEYBOARD_COMPONENT_H
