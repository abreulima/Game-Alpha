#include <SDL2/SDL.h>

#include "Game.h"
#include "Entity.h"

int DrawSystem(Game *game, Entity *entity)
{
	// It is necessary to check if the entity has the necessary componentes;

	if (!entity->components.component_box && !entity->components.component_rectangle)
		return (0);

	SDL_Rect rect;
	rect.x = (int)entity->components.component_position->x;
	rect.y = (int)entity->components.component_position->y;

	if (entity->components.component_box)
	{
		rect.w = entity->components.component_box->size;
		rect.h = entity->components.component_box->size;

		SDL_SetRenderDrawColor(
			game->renderer,
			entity->components.component_box->color.r,
			entity->components.component_box->color.g,
			entity->components.component_box->color.b,
			entity->components.component_box->color.a
			);
	}
	else
	{
		rect.w = entity->components.component_rectangle->width;
		rect.h = entity->components.component_rectangle->height;

		SDL_SetRenderDrawColor(
			game->renderer,
			entity->components.component_rectangle->color.r,
			entity->components.component_rectangle->color.g,
			entity->components.component_rectangle->color.b,
			entity->components.component_rectangle->color.a
			);
	}



	SDL_RenderFillRect(game->renderer, &rect);

	return (1);
}