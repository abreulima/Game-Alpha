#include "Game.h"
#include "Entity.h"

void AddNamedEntity(Game *game, Entity entity, const char *name)
{
	entity.is_active = 1;
	entity.name = strdup(name);
	game->entities[game->entities_id] = entity;
	game->entities_id++;
}

void AddEntity(Game *game, Entity entity)
{
	entity.is_active = 1;
	entity.name = NULL;
	game->entities[game->entities_id] = entity;
	entity.id = game->entities_id;
	game->entities_id++;
}
int EntityReturnId(Entity entity)
{
	return entity.id;
}


