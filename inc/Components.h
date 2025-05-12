#ifndef COMPONENTS_H
#define COMPONENTS_H

#include "components/PositionComponent.h"
#include "components/BoxComponent.h"
#include "components/RectangleComponent.h"
#include "components/KeyboardComponent.h"
#include "components/SpriteComponent.h"
#include "components/VelocityComponent.h"
#include "components/GravityComponent.h"

typedef struct {
	GravityComponent *component_gravity;
	PositionComponent *component_position;
	VelocityComponent *component_velocity;
	BoxComponent *component_box;
	RectangleComponent *component_rectangle;
	KeyboardComponent *component_keyboard;
	SpriteComponent *component_sprite;
} Components;


#endif //COMPONENTS_H
