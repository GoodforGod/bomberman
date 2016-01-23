#include "draw.h"

extern void drawPlayer(void);
extern void drawEntities(void);
extern void drawLevel(void);

void draw()
{
	/* Blank the screen */
	
	SDL_FillRect(game.screen, NULL, 0);
	
	/* Draw terrain */

	drawLevel();
	
	/* Draw the player */

	drawPlayer();
	
	/* Draw the entities */
	
	drawEntities();
	
	/* Update the buffer */

	SDL_Flip(game.screen);
	
	/* Sleep briefly */
	
	SDL_Delay(1);
}

void delay(unsigned int frameLimit)
{
	unsigned int ticks = SDL_GetTicks();

	if (frameLimit < ticks)
	{
		return;
	}
	
	if (frameLimit > ticks + 16)
	{
		SDL_Delay(16);
	}
	
	else
	{
		SDL_Delay(frameLimit - ticks);
	}
}
