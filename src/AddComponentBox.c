#include <stdlib.h>

#include "Entity.h"
#include "components/BoxComponent.h"

void AddComponentBox(struct Game *game, Entity *entity, const int size, SDL_Color color)
{
	entity->components.component_box = malloc(sizeof(BoxComponent));
	entity->components.component_box->color = color; // 255, 0, 0 0
	entity->components.component_box->size = size;
}
