#include <stdio.h>
#include <SDL2/SDL.h>


/* This code is implementing an ECS (Entity Component System)
 * It creates some mess, but after the backbone is done is highly logical
*/

/* Every System should be its own file,
 * Every component should be its own file
 *
 *
 */

// https://prdeving.wordpress.com/2018/06/27/videogames-programming-ecs-system-in-plain-c/


#include "Game.h"

int main(void)
{
	Game game;

	start(&game);
	while (game.is_running)
	{
		update_events(&game);
		update_render(&game);
	}
	free(game.entities); 
	SDL_DestroyRenderer(game.renderer);
	SDL_DestroyWindow(game.window);
	SDL_Quit();
	return 0;
}