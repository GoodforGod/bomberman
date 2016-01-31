#include "spawn.h"

void spawnEnemy(size_t);

void checkGameEnemy()
{
	char text_enemy[40], text_next[40];
	unsigned long timer;
	size_t random;

	if(game.enemies == 0)
	{
		timer = SDL_GetTicks();
		
		while(SDL_GetTicks() - timer < 4000)
		{

			sprintf(text_next, "NEXT WAVE COMING...");
				sprintf(text_enemy, "3...");
			if(SDL_GetTicks() - timer > 1500)
				sprintf(text_enemy, "2...");
			if(SDL_GetTicks() - timer > 2500)
				sprintf(text_enemy, "1...");
			if(SDL_GetTicks() - timer > 3400)
				sprintf(text_enemy, "Let the games begin!");
		
			drawString(text_enemy, 400, 350, game.message, 200, 0);
			drawString(text_next, 400, 150, game.message, 200, 0);
			SDL_Flip(game.screen);
	
			/* Sleep briefly */
	
			SDL_Delay(1);
		}
		random = (size_t)rand() % 3 + 1;
		if(game.score > 1000)
			random = (size_t)rand() % 4 + 1;
		if(game.score > 4000)
			random = (size_t)rand() % 6 + 1;
		if(game.score > 8000)
			random = (size_t)rand() % 9 + 1;
		if(game.score > 12000)
			random = (size_t)rand() % 10 + 2;
		spawnEnemy(random);
	}
}

void spawnEnemy(size_t enemy_amount)
{
	int spawnOffsetX = SCREEN_WIDTH - LEVEL_X_OFFSET, spawnOffsetY = SCREEN_HEIGHT - LEVEL_X_OFFSET;
	size_t i;
	int randomOffset;

	for(i = 0; i < enemy_amount; i++)
	{
		randomOffset = rand() % 10;
		addEnemy(spawnOffsetX - 64, spawnOffsetY - 64 - (64 * randomOffset));
	}
	game.enemies = enemy_amount;
}
