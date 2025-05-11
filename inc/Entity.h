#ifndef ENTITY_H
#define ENTITY_H

#include "Components.h"

struct Game; // Forward declaration

typedef struct Entity{
	unsigned int id;
	char *name;
	Components components;
} Entity;

void AddNamedEntity(struct Game *game, Entity entity, const char *name);
void AddEntity(struct Game *game, Entity entity);

#endif //ENTITY_H
