#include <stdlib.h>
#include <SDL2/SDL.h>

#include "Entity.h"
#include "components/RectangleComponent.h"

void AddComponentRectangle(struct Game *game, Entity *entity, const int width, const int height, SDL_Color color)
{
	entity->components.component_rectangle = malloc(sizeof(RectangleComponent));
	entity->components.component_rectangle->color = color;
	entity->components.component_rectangle->width = width;
	entity->components.component_rectangle->height = height;
}