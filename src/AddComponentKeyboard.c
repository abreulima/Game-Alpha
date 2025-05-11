#include <stdlib.h>

#include "Entity.h"
#include "components/KeyboardComponent.h"

void AddComponentKeyboard(
	struct Game *game,
	Entity *entity,
	SDL_Scancode left, SDL_Scancode right,
	SDL_Scancode up, SDL_Scancode down,
	SDL_Scancode attack)
{
	entity->components.component_keyboard = malloc(sizeof(KeyboardComponent));
	entity->components.component_keyboard->left = left;
	entity->components.component_keyboard->right = right;
	entity->components.component_keyboard->up = up;
	entity->components.component_keyboard->down = down;

}