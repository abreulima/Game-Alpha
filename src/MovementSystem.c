#include "Game.h"
#include "Entity.h"

int MovementSystem(Game *game, Entity *entity)
{

	if (!entity->components.component_position || !entity->components.component_velocity)
		return (0);

	entity->components.component_position->x += entity->components.component_velocity->vel_x * game->deltaTime;
	entity->components.component_position->y += entity->components.component_velocity->vel_y * game->deltaTime;

	return (1);
}