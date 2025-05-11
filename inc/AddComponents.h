#ifndef ADD_COMPONENTS_H
#define ADD_COMPONENTS_H

#include "Entity.h"

void AddComponentPosition(struct Game *game, Entity *entity, float x, float y);
void AddComponentVelocity(struct Game *game, Entity *entity, float vel_x, float vel_y, float speed);
void AddComponentBox(struct Game *game, Entity *entity, const int size, SDL_Color color);
void AddComponentRectangle(struct Game *game, Entity *entity, const int width, const int height, SDL_Color color);
void AddComponentSprite(struct Game *game, Entity *entity, char *path);
void AddComponentKeyboard(
	struct Game *game, 
	Entity *entity,
	SDL_Scancode left,
	SDL_Scancode right,
	SDL_Scancode up,
	SDL_Scancode down,
	SDL_Scancode attack);

#endif //ADD_COMPONENTS_H
