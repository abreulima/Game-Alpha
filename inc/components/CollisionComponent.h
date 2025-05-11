#ifndef COLLISION_COMPONENT_H
#define COLLISION_COMPONENT_H

typedef struct {
	int is_colliding;
	int is_solid; // If both are solid, we can't transpass
} CollisionComponent;

#endif //COLLISION_COMPONENT_H
