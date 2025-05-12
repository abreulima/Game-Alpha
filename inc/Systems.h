#ifndef SYSTEMS_H
#define SYSTEMS_H

int DrawSystem(struct Game *game, Entity *entity);
int KeyboardSystem(struct Game *game, Entity *entity);
int MovementSystem(struct Game *game, Entity *entity);
int	DrawImageSystem(struct Game *game, Entity *entity);
int	GravitySystem(struct Game *game, Entity *entity);
#endif //SYSTEMS_H
