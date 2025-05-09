#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

void start();
void update();
void update_events();
void update_render();
void load_level();

/* This code is implementing an ECS (Entity Component System)
 * It creates some mess, but after the backbone is done is highly logical
*/

/* Every System should be its own file,
 * Every component should be its own file
 *
 *
 */

// https://prdeving.wordpress.com/2018/06/27/videogames-programming-ecs-system-in-plain-c/

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

typedef struct {
	SDL_Texture *texture;
} ComponentSprite;

typedef struct {
	int size;
	SDL_Color color;
} ComponentBox;

typedef struct {
	float x;
	float y;
} ComponentPosition;

typedef struct {
	float vel_x;
	float vel_y;
	float speed;
} ComponentVelocity;

typedef struct {
	Uint8 *key_state;
	SDL_Scancode left;
	SDL_Scancode right;
	SDL_Scancode up;
	SDL_Scancode down;
	SDL_Scancode attack;
} ComponentKeyboard;

typedef struct {
	ComponentPosition *component_position;
	ComponentVelocity *component_velocity;
	ComponentBox *component_box;
	ComponentKeyboard *component_keyboard;
	ComponentSprite *component_sprite;
} Components;

typedef struct {
	unsigned int id;
	Components components;
} Entity;

typedef struct {
	SDL_Event events;
	SDL_Window *window;
	SDL_Renderer *renderer;
	Entity entities[1024]; // Plenty of entities, I believe
	const Uint8 *key_state;
	int is_running;
	float deltaTime;
} Game;

/* Yes, it is a global var */
Game game;
static int entities_id = 0;

void AddComponentSprite(Entity *entity, char *path)
{
	SDL_Surface * image = SDL_LoadBMP(path);
	entity->components.component_sprite->texture = SDL_CreateTextureFromSurface(game.renderer, image);
}
void AddComponentPosition(Entity *entity, float x, float y)
{
	entity->components.component_position = malloc(sizeof(ComponentPosition));
	entity->components.component_position->x = x;
	entity->components.component_position->y = y;
}

void AddComponentVelocity(Entity *entity, float vel_x, float vel_y, float speed)
{
	entity->components.component_velocity = malloc(sizeof(ComponentVelocity));
	entity->components.component_velocity->vel_x = vel_x;
	entity->components.component_velocity->vel_y = vel_y;
	entity->components.component_velocity->speed = speed;
}

void AddComponentKeyboard(
	Entity *entity,
	SDL_Scancode left, SDL_Scancode right,
	SDL_Scancode up, SDL_Scancode down,
	SDL_Scancode attack)
{
	entity->components.component_keyboard = malloc(sizeof(ComponentPosition));
	entity->components.component_keyboard->left = left;
	entity->components.component_keyboard->right = right;
	entity->components.component_keyboard->up = up;
	entity->components.component_keyboard->down = down;

}

void AddComponentBox(Entity *entity, const int size, SDL_Color color)
{
	entity->components.component_box = malloc(sizeof(ComponentBox));
	entity->components.component_box->color = color; // 255, 0, 0 0
	entity->components.component_box->size = size;
}

int DrawSystem(Entity *entity)
{

	// It is necessary to check if the entity has the necessary componentes;

	SDL_Rect rect;
	rect.x = (int)entity->components.component_position->x;
	rect.y = (int)entity->components.component_position->y;
	rect.w = entity->components.component_box->size;
	rect.h = entity->components.component_box->size;

	SDL_SetRenderDrawColor(
		game.renderer,
		entity->components.component_box->color.r,
		entity->components.component_box->color.g,
		entity->components.component_box->color.b,
		entity->components.component_box->color.a
		);
	SDL_RenderFillRect(game.renderer, &rect);

	return (1);
}

//int MovementSystem(Entity )

int KeyboardSystem(Entity *entity)
{
	if (!entity->components.component_keyboard || !entity->components.component_velocity)
		return (0);
	float speed = entity->components.component_velocity->speed;
	entity->components.component_velocity->vel_x = 0;
	entity->components.component_velocity->vel_y = 0;

	if (game.key_state[entity->components.component_keyboard->left] ) {
		entity->components.component_velocity->vel_x -= speed;
	}
	if (game.key_state[entity->components.component_keyboard->right] ) {
		entity->components.component_velocity->vel_x += speed;
	}
	if (game.key_state[entity->components.component_keyboard->up] ) {
		entity->components.component_velocity->vel_y -= speed;
	}
	if (game.key_state[entity->components.component_keyboard->down] ) {
		entity->components.component_velocity->vel_y += speed;
	}

	return (1);
}

int MovementSystem(Entity *entity)
{

	if (!entity->components.component_position || !entity->components.component_velocity)
		return (0);

	entity->components.component_position->x += entity->components.component_velocity->vel_x * game.deltaTime;
	entity->components.component_position->y += entity->components.component_velocity->vel_y * game.deltaTime;

	return (1);
}
int	DrawImageSystem(Entity *entity)
{
	if (!entity->components.component_sprite)
		return (0);
	SDL_RenderCopy(game.renderer, entity->components.component_sprite->texture, NULL,NULL);
}

void AddEntity(Entity entity)
{
	game.entities[entities_id] = entity;
	entities_id++;
}

int main(void)
{

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("ERROR");
		return (1);
	}

	game.window = SDL_CreateWindow(
		"Title",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		SCREEN_WIDTH, SCREEN_HEIGHT,
		SDL_WINDOW_SHOWN);
	if (!game.window)
	{
		printf("ERROR");
		return (1);
	}
	game.renderer = SDL_CreateRenderer(
		game.window,
		-1,
		SDL_RENDERER_ACCELERATED);

	/* The FAMOUS Game Loop */
	start();
	while (game.is_running)
	{
		update_events();
		update_render();
		game.deltaTime = (float)1/60;
		SDL_Delay(1/60);
	}

	// We need to free everything

	/* The end */
	return 0;
}


/* This function is called once */
void start()
{
	/* It will start every component/entity and a few Game related things */
	game.is_running = 1;
	entities_id = 0;
	load_level();
}

/* This function is called every frame */
void update()
{
	/* It will update every component/entity */

	/*  We divide this function in two sections */
	/*  Events and Render */


}

void update_events()
{
	while (SDL_PollEvent(&game.events))
	{
		if (game.events.type == SDL_QUIT || game.events.key.keysym.sym == SDLK_ESCAPE)
		{
			game.is_running = 0;
			break ;
		}
		game.key_state = SDL_GetKeyboardState(NULL);
	}
}

void update_render()
{
	SDL_SetRenderDrawColor(game.renderer, 0, 0, 0, 255);
	SDL_RenderClear(game.renderer);
	for (int i = 0; i < entities_id; i++)
	{
		KeyboardSystem(&game.entities[i]);
		MovementSystem(&game.entities[i]);
		DrawSystem(&game.entities[i]);
		DrawImageSystem(&game.entities[i]);
	}
	SDL_RenderPresent(game.renderer);
}

void load_level()
{
	Entity player;
	memset(&player, 0, sizeof(Entity));
	AddComponentPosition(&player, 120, 120);
	AddComponentBox(&player, 32, (SDL_Color){255, 0, 255});
	AddComponentKeyboard(
		&player,
		SDL_SCANCODE_LEFT,
		SDL_SCANCODE_RIGHT,
		SDL_SCANCODE_UP,
		SDL_SCANCODE_DOWN,
		SDL_SCANCODE_SPACE
		);
	AddComponentVelocity(&player, 0, 0, 60);
	AddEntity(player);


	Entity player_two;
	//player_two.components.component_keyboard = NULL;
	memset(&player_two, 0, sizeof(Entity));
	AddComponentPosition(&player_two, 300, 100);
	AddComponentBox(&player_two, 32, (SDL_Color){255, 255, 255});
	AddComponentKeyboard(
	&player_two,
	SDL_SCANCODE_A,
	SDL_SCANCODE_D,
	SDL_SCANCODE_W,
	SDL_SCANCODE_S,
	SDL_SCANCODE_K
	);
	AddComponentVelocity(&player_two, 0, 0, 60);

	// Add Gravity
	// Add Keyboard
	AddComponentSprite(&player_two, "image.bmp");
	AddEntity(player_two);
}
