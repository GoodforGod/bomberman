#include "player.h"

/* init the player and fill params */

void initPlayer()
{
	player.sprite = getSprite(PLAYER_SPRITE);
	player.active = 1;	
	player.x = 30 + 128;
	player.y = SCREEN_HEIGHT/2 - 24;
	player.bomb = 1;
	player.thinkTime = MAX_RELOAD_TIME;
}

/* JUST DO IT! */

void doPlayer()
{
	int bomb_x, bomb_y;
	/* Only if player not dead then act */

	if(player.active == 1)
	{
		/* Remember prev coordinates, to go back if hit wall or brick */

		player.thinkTime--;
		player.prev_x = player.x;
		player.prev_y = player.y;
		
		if (input.fire == 1 && player.bomb > 0 && player.thinkTime <= 0)
		{
			/* You can only place bomb when the bomb flag is 1 or more */
			
			/* Trying to place bomb in the nearest possition */

			bomb_x = player.x % 64 - 32;
			bomb_y = player.y % 64 - 30;
			
			if(bomb_x < 32)
			{
				if(bomb_y < 32)
					addBomb(player.x - bomb_x, player.y - bomb_y);
				else 
					addBomb(player.x - bomb_x, player.y + (64 - bomb_y));
			}
			else 
			{
				if(bomb_y < 32)
					addBomb(player.x + (64 - bomb_x), player.y - bomb_y);
				else 
					addBomb(player.x + (64 - bomb_x), player.y + (64 - bomb_y));
			}
				
			/* Place bomb and MAKE YOUR DREAMES COME TRUE! */
				
			player.thinkTime = MAX_RELOAD_TIME;
			playSound(BOMB_PLACE_SOUND);
			player.bomb--;
		}
		
		if (input.up == 1)
		{
			player.y -= PLAYER_SPEED;
			/* Don't allow the player to move off the screen */
		
			if (player.y < 26)
				player.y = player.prev_y;
			return;
		}
	
		if (input.down == 1)
		{
			player.y += PLAYER_SPEED;
			/* Don't allow the player to move off the screen */
		
			if (player.y + player.sprite->h >= SCREEN_HEIGHT-22)
				player.y = player.prev_y;
			/*	player.y = SCREEN_HEIGHT - (player.sprite->h + 1); */
			return;
		}
	
		if (input.left == 1)
		{
			player.x -= PLAYER_SPEED;
			/* Don't allow the player to move off the screen */
			
			if (player.x < 20)
				player.x = player.prev_x;
			return;
		}
	
		if (input.right == 1)
		{
			player.x += PLAYER_SPEED;
			/* Don't allow the player to move off the screen */
			
			if (player.x + player.sprite->w >= SCREEN_WIDTH-20)
				player.x = player.prev_x;
				/* player.x = SCREEN_WIDTH - (player.sprite->w + 1); */
			return;
		}
	}
}

void drawPlayer()
{
	/* Draw the image in the player structure if alive or play death animation */

	if(player.active == 1)
		drawImage(player.sprite, player.x, player.y);
	else 
	{
		/* Draw animation of death only once and them draw grave */ 
		
		if(bombermanDead.frameIndex != 5)
		{
			doSpeedAnimation(&bombermanDead, 9);
			drawAnimation(&bombermanDead, player.x, player.y);
		}
		else drawImage(getSprite(PLAYER_DEAD_SPRITE), player.x, player.y);
	}
}
