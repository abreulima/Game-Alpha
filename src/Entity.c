#include "Game.h"
#include "Entity.h"

void AddNamedEntity(Game *game, Entity entity, const char *name)
{
	entity.name = strdup(name);
	game->entities[game->entities_id] = entity;
	game->entities_id++;
}

void AddEntity(Game *game, Entity entity)
{
	game->entities[game->entities_id] = entity;
	game->entities_id++;
}
