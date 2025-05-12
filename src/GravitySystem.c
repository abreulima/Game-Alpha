#include <SDL2/SDL.h>

#include "Game.h"
#include "Entity.h"

int	GravitySystem(Game *game, Entity *entity)
{
	if (!entity->components.component_gravity || !entity->components.component_position)
		return (0);
	if(entity->components.component_gravity->is_on_floor)
		return (0);
	entity->components.component_position->y+= (7 * game->deltaTime);
	return (1);
}