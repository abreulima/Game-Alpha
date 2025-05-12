#include "Game.h"
#include "Entity.h"

int KeyboardSystem(Game *game, Entity *entity)
{
	if (!entity->components.component_keyboard || !entity->components.component_velocity)
		return (0);

	float speed = entity->components.component_velocity->speed;
	entity->components.component_velocity->vel_x = 0;
	entity->components.component_velocity->vel_y = 0;

	if (game->key_state[entity->components.component_keyboard->left] ) {
		entity->components.component_velocity->vel_x -= speed;
	}
	if (game->key_state[entity->components.component_keyboard->right] ) {
		entity->components.component_velocity->vel_x += speed;
	}
	if (game->key_state[entity->components.component_keyboard->up] ) {
		entity->components.component_velocity->vel_y -= speed;
	}
	if (game->key_state[entity->components.component_keyboard->down] ) {
		entity->components.component_velocity->vel_y += speed;
	}
	if (game->key_state[entity->components.component_keyboard->up] ) {
		//entity->components.component_velocity->vel_y -= 20;
	}
	return (1);
}