#include "draw.h"

extern void drawPlayer(void);
extern void drawEntities(void);
extern void drawLevel(void);
extern void drawAnimation(Animation *, int, int);
extern void drawString(char *, int, int, TTF_Font *, int, int);
extern void doSpeedAnimation(Animation *, int);

/* Function chooses animation depends on your direction */ 

void chooseAnimation()
{
	/* Choose walking animation or death or idle sprite */

	if(player.active == 0)
	{
		drawPlayer();	
		return;
	}

	if(input.up == 1)
	{
		drawAnimation(&bombermanBack, player.x, player.y);
		return;
	}

	if(input.down == 1)	
	{
		drawAnimation(&bombermanFront, player.x, player.y);
		return;	
	}

	if(input.left == 1)
	{
		drawAnimation(&bombermanLeft, player.x, player.y);	
		return;
	}
	
	if(input.right == 1)	
	{
		drawAnimation(&bombermanRight, player.x, player.y);	
		return;
	}

	/* Draw cool animation once and then idle sprite due to no direction and as default case */

	if(bombermanCool.frameIndex != 8)
	{
		drawAnimation(&bombermanCool, player.x, player.y);
		doSpeedAnimation(&bombermanCool, 8);	
	}	
	else drawPlayer();

	return;	
}


void draw()
{
	/* Store text to render */

	char text[40];
	
	/* Blank the screen */
	
	SDL_FillRect(game.screen, NULL, 0);
	
	/* Draw terrain */

	drawLevel();
	
	/* Draw the text */
	
	sprintf(text, "SCORE: 0");
	
	drawString(text, 0, 0, game.font, 1, 0);

	/* Draw player animation */

	chooseAnimation();

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
