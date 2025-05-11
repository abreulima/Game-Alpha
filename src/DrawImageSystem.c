#include <SDL2/SDL.h>

#include "Game.h"
#include "Entity.h"

int	DrawImageSystem(Game *game, Entity *entity)
{
	if (!entity->components.component_sprite)
		return (0);

	SDL_Rect rect;
	rect.x = (int)entity->components.component_position->x;
	rect.y = (int)entity->components.component_position->y;
	rect.w = entity->components.component_box->size;
	rect.h = entity->components.component_box->size;

	SDL_RenderCopy(game->renderer, entity->components.component_sprite->texture, NULL, &rect);

	return (1);
}