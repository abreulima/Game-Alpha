#include <stdlib.h>

#include "Entity.h"
#include "components/PositionComponent.h"

void AddComponentPosition(struct Game *game, Entity *entity, float x, float y)
{
	entity->components.component_position = malloc(sizeof(PositionComponent));
	entity->components.component_position->x = x;
	entity->components.component_position->y = y;
}