#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>

#include "Entity.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

typedef struct Game {
	SDL_Event events;
	SDL_Window *window;
	SDL_Renderer *renderer;
	Entity *entities; // Plenty of entities, I believe
	const Uint8 *key_state;
	int is_running;
	float deltaTime;
	unsigned int entities_id;
} Game;

/* Yes, it is a global var */

void setup(Game *game);
void start(Game *game);
void update_events(Game *game);
void update_render(Game *game);
void load_level(Game *game);

#endif //GAME_H
