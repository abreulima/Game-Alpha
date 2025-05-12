/* This function is called once */
#include <SDL2/SDL.h>


#include "Entity.h"
#include "Game.h"

#include "Components.h"
#include "AddComponents.h"
#include "Systems.h"

void setup(Game *game)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("ERROR");
		exit(EXIT_FAILURE);
	}

	game->window = SDL_CreateWindow(
		"Title",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		SCREEN_WIDTH, SCREEN_HEIGHT,
		SDL_WINDOW_SHOWN);

	if (!game->window)
	{
		printf("ERROR");
		exit(EXIT_FAILURE);
	}
	game->renderer = SDL_CreateRenderer(
		game->window,
		-1,
		SDL_RENDERER_ACCELERATED);

	game->entities = malloc(sizeof(Entity) * 1024);
}

void start(Game *game)
{
	/* It will start every component/entity and a few Game related things */
	setup(game);
	game->is_running = 1;
	game->entities_id = 0;
	load_level(game);
}

void update_events(Game *game)
{	
	game->key_state = SDL_GetKeyboardState(NULL);

	while (SDL_PollEvent(&game->events))
	{
		if (game->events.type == SDL_QUIT || game->events.key.keysym.sym == SDLK_ESCAPE)
		{
			game->is_running = 0;
			break ;
		}
	}
}

void update_render(Game *game)
{
	SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, 255);
	SDL_RenderClear(game->renderer);
	for (int i = 0; i < game->entities_id; i++)
	{
		KeyboardSystem(game, &game->entities[i]);
		MovementSystem(game, &game->entities[i]);
		GravitySystem(game,&game->entities[i]);
		DrawImageSystem(game, &game->entities[i]);
		DrawSystem(game, &game->entities[i]);
	}

	game->deltaTime = 1/60.f;
	SDL_Delay(1/60.f);

	SDL_RenderPresent(game->renderer);
}

void load_level(Game *game)
{
	Entity player;
	memset(&player, 0, sizeof(Entity));
	AddComponentGravity(game, &player);
	AddComponentPosition(game, &player, 120, 120);
	AddComponentBox(game, &player, 32, (SDL_Color){255, 0, 255});
	AddComponentKeyboard(
		game,
		&player,
		SDL_SCANCODE_LEFT,
		SDL_SCANCODE_RIGHT,
		SDL_SCANCODE_UP,
		SDL_SCANCODE_DOWN,
		SDL_SCANCODE_SPACE
	);
	AddComponentVelocity(game, &player, 0, 0, 5);
	AddNamedEntity(game, player, "PLAYER");
	
	
	Entity player_two;
	//player_two.components.component_keyboard = NULL;
	memset(&player_two, 0, sizeof(Entity));
	AddComponentGravity(game, &player_two);
	AddComponentPosition(game, &player_two, 240, 240);
	AddComponentBox(game, &player_two, 32, (SDL_Color){0, 255, 255});
	AddComponentVelocity(game, &player_two, 0, 0, 5);
	AddComponentKeyboard(
		game, 
		&player_two,
		SDL_SCANCODE_A,
		SDL_SCANCODE_D,
		SDL_SCANCODE_W,
		SDL_SCANCODE_S,
		SDL_SCANCODE_K
	);
	

	// Add Gravity
	// Add Keyboard
	AddComponentSprite(game, &player_two, "image.bmp");
	AddEntity(game, player_two);


	/* Platform */
	Entity platform_1 = {0};
	AddComponentPosition(game, &platform_1, 5, 450);
	AddComponentRectangle(game, &platform_1, 600, 100, (SDL_Color){255, 0, 255});
	AddEntity(game, platform_1);

}
