#include "player.h"

extern int loadSprite(char *);
extern void drawImage(SDL_Surface *, int, int);
extern void addBomb(int, int);
extern SDL_Surface *getSprite(int);
extern void drawAnimation(Animation *, int, int);

void initPlayer()
{
	player.sprite = getSprite(PLAYER_SPRITE);
	player.active = 1;	
	player.x = SCREEN_WIDTH / 2;
	player.y = SCREEN_HEIGHT / 2;
}

void doPlayer()
{
	/* Only if player not dead then act */

	if(player.active == 1)
	{
		player.thinkTime--;
	
		if (player.thinkTime <= 0)
			player.thinkTime = 0;
	
		if (input.up == 1)
		{
			player.y -= PLAYER_SPEED;
			
			/* Don't allow the player to move off the screen */
		
			if (player.y < 0)
				player.y = 0;
		}
	
		if (input.down == 1)
		{
			player.y += PLAYER_SPEED;
			
			/* Don't allow the player to move off the screen */
		
			if (player.y + player.sprite->h >= SCREEN_HEIGHT)
				player.y = SCREEN_HEIGHT - (player.sprite->h + 1);
		}
	
		if (input.left == 1)
		{
			player.x -= PLAYER_SPEED;
			
			/* Don't allow the player to move off the screen */
			
			if (player.x < 0)
				player.x = 0;
		}
	
		if (input.right == 1)
		{
			player.x += PLAYER_SPEED;
			
			/* Don't allow the player to move off the screen */
			
			if (player.x + player.sprite->w >= SCREEN_WIDTH)
				player.x = SCREEN_WIDTH - (player.sprite->w + 1);
		}
	
		if (input.fire == 1)
		{
			/* You can only place bomb  when the thinkTime is 0 or less */
		
			if (player.thinkTime <= 0)
			{
				/* addBomb(player.x + player.sprite->w, player.y + (player.sprite->h / 2)); */
				
				addBomb(player.x, player.y);

				player.thinkTime = MAX_RELOAD_TIME;
			}
		}
	}
}

void drawPlayer()
{
	/* static indicator of death, to play death animation only once */

	static int dead = 0;
	
	/* Draw the image in the player structure if alive or play death animation */

	if(player.active == 1)
		drawImage(player.sprite, player.x, player.y);
	else 
	{
		/* Draw animation of death only once and them draw grave */ 

		if(bombermanDead.frameIndex < 0)  
			dead = 1;

		if(dead == 1)
			drawImage(getSprite(PLAYER_DEAD_SPRITE), player.x, player.y);
		else drawAnimation(&bombermanDead, player.x, player.y);
	}
}
