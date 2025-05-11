#include <stdlib.h>

#include "Game.h"
#include "Entity.h"
#include "components/VelocityComponent.h"

void AddComponentVelocity(struct Game *game, Entity *entity, float vel_x, float vel_y, float speed)
{
	entity->components.component_velocity = malloc(sizeof(VelocityComponent));
	entity->components.component_velocity->vel_x = vel_x;
	entity->components.component_velocity->vel_y = vel_y;
	entity->components.component_velocity->speed = speed;
}
