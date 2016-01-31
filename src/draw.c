#include "draw.h"

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

	char text_timer[40];
	char text_score[40];
	char text_bomb[40];
	char text_enemy[40];
	/* Blank the screen */
	
	SDL_FillRect(game.screen, NULL, 0);
	
	/* Draw terrain */

	drawLevel();
	
	/* Draw the text */
	if(player.bomb < 0)
		sprintf(text_bomb, "BOMB: %d", 0);
	else sprintf(text_bomb, "BOMB: %d", player.bomb);

	drawString(text_bomb, 800, 0, game.font, 200, 0);
	
	sprintf(text_enemy, "ENEMY LEFT: %lu", game.enemies);
	
	drawString(text_enemy, 550, 0, game.font, 200, 0);

	sprintf(text_score, "SCORE: %lu", game.score);
	
	drawString(text_score, 300, 0, game.font, 200, 0);
	
	sprintf(text_timer, "TIME: %lu", game.timer);
	
	drawString(text_timer, 50, 0, game.font, 100, 0);

	/* Draw player animation */

	chooseAnimation();

	/* Draw the entities */
	
	drawEntities();
	
	/* Update the buffer */

	SDL_Flip(game.screen);
	
	/* Sleep briefly */
	
	SDL_Delay(1);
}

/* Delay to get aroud 60FPS */

void delay(unsigned int frameLimit)
{
	unsigned int ticks = SDL_GetTicks();

	if (frameLimit < ticks)
		return;
	
	if (frameLimit > ticks + 16)
		SDL_Delay(16);
	
	else
		SDL_Delay(frameLimit - ticks);
}
