#include "collisions.h"

extern void playSound(int);

int collision(int, int, int, int, int, int, int, int);
extern void checkAiCollision(int, int);

void doCollisions()
{
	int i, j;

	/* Check each entity against the rest and inactive player, skipping over inactive ones */

	if(player.active == 0)
		 return;

	for (i=0;i<MAX_ENTITIES;i++)
	{
		if (entity[i].active == 0)
			continue;
	
		/* Test player collision with enemy */
	
		if (entity[i].type == TYPE_ENEMY && (collision(entity[i].x, entity[i].y, entity[i].sprite->w, entity[i].sprite->h, player.x, player.y, player.sprite->w, player.sprite->h) == 1))
		{
			player.active = 0;
			playSound(DEAD_SOUND);
			break;
		}	
		
		/* Test player collision with wall and brick */

		if ((entity[i].type == TYPE_WALL || entity[i].type == TYPE_BRICK || entity[i].type == TYPE_BONUS_AMMO) && (collision(entity[i].x, entity[i].y, entity[i].sprite->w-12, entity[i].sprite->h-5, player.x, player.y, player.sprite->w-12, player.sprite->h-5) == 1))
		{
			if(entity[i].type == TYPE_BONUS_AMMO)
			{
				player.bomb++;
				entity[i].active = 0;
			}
			player.x = player.prev_x;
			player.y = player.prev_y;
			break;
		}

		/* Test player collision with fire, kill if occued */
		
		if ((entity[i].type == TYPE_FIRE_CENTER || entity[i].type == TYPE_FIRE_FRONT || entity[i].type == TYPE_FIRE_RIGHT || entity[i].type == TYPE_FIRE_LEFT || entity[i].type == TYPE_FIRE_BACK) && (collision(entity[i].x, entity[i].y, entity[i].sprite->w, entity[i].sprite->h, player.x, player.y, player.sprite->w-4, player.sprite->h-4) == 1))
			{
				entity[i].active = 0;
				player.active = 0;
				playSound(DEAD_SOUND);
				break;
			}

		for (j=0;j<MAX_ENTITIES;j++)
		{
			/* Don't collide with yourself, inactive entities or entities of the same type */

			if (i == j || entity[j].active == 0 || entity[j].type == entity[i].type)
				continue;
			
			/* Collision test for AI */

			checkAiCollision(i, j);	

			/* If a collision occured with fire and enemy, remove enemy */
		
			if((entity[i].type == TYPE_FIRE_BACK || entity[i].type == TYPE_FIRE_LEFT || entity[i].type == TYPE_FIRE_FRONT || entity[i].type == TYPE_FIRE_RIGHT || entity[i].type == TYPE_FIRE_CENTER ) && entity[j].type == TYPE_ENEMY)
			{
				
				if (collision(entity[i].x, entity[i].y, entity[i].sprite->w, entity[i].sprite->h, entity[j].x, entity[j].y, entity[j].sprite->w, entity[j].sprite->h) == 1)
				{	
					entity[j].active = 0;
					break;
				}
			}
			
			/* Test collision for bomb, to not place it in wrong place */
			
			if(entity[i].type == TYPE_BOMB && (entity[j].type == TYPE_WALL || entity[j].type == TYPE_BRICK || entity[j].type == TYPE_BOMB))
			{	
				if (collision(entity[i].x, entity[i].y, entity[i].sprite->w, entity[i].sprite->h, entity[j].x, entity[j].y, entity[j].sprite->w, entity[j].sprite->h) == 1)
				{
					entity[i].active = 0;
					player.bomb++;
					break;
				}
			}
		
			/* Test collision with fire and wall, start wall destraction if occured */

				if ((entity[i].type == TYPE_FIRE_CENTER || entity[i].type == TYPE_FIRE_FRONT || entity[i].type == TYPE_FIRE_RIGHT || entity[i].type == TYPE_FIRE_LEFT || entity[i].type == TYPE_FIRE_BACK) && (entity[j].type == TYPE_WALL || entity[j].type == TYPE_BRICK) && (collision(entity[i].x, entity[i].y, entity[i].sprite->w, entity[i].sprite->h, entity[j].x, entity[j].y, entity[j].sprite->w, entity[j].sprite->h) == 1))
			{
				entity[i].active = 0;
				if(entity[j].type == TYPE_WALL)
					entity[j].bomb = 1;
				break;
			}
		}
	}
}

/* Very standard 2D collision detection routine */

int collision(int x0, int y0, int w0, int h0, int x2, int y2, int w1, int h1)
{
	int x1 = x0 + w0;
	int y1 = y0 + h0;

	int x3 = x2 + w1;
	int y3 = y2 + h1;

	return !(x1<x2 || x3<x0 || y1<y2 || y3<y0);
}
