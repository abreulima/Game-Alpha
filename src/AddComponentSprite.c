#include <stdlib.h>
#include <SDL2/SDL.h>

#include "Game.h"
#include "Entity.h"
#include "components/SpriteComponent.h"


void AddComponentSprite(struct Game *game, Entity *entity, char *path)
{
	entity->components.component_sprite = malloc(sizeof(SpriteComponent));
	SDL_Surface *image = SDL_LoadBMP(path);
	entity->components.component_sprite->texture = SDL_CreateTextureFromSurface(game->renderer, image);
}
