#include "Entity.h"
#include "components/GravityComponent.h"

void AddComponentGravity(struct Game *game, Entity *entity)
{
	entity->components.component_gravity = malloc(sizeof(GravityComponent));
	entity->components.component_gravity->is_on_floor = 0;
}