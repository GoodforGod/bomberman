#include "aiCollisions.h"

extern int collision(int, int, int, int, int, int, int, int);

void defaultTest(int got_i, int got_j)
{
	int i = got_i, j = got_j;
	/* Check all directions for empty 64x64 block to move next and store that data */
	if ((entity[i].type == TYPE_ENEMY) && (entity[i].center <= 0) && (entity[j].type == TYPE_WALL || entity[j].type == TYPE_BRICK || entity[j].type == TYPE_BOMB))
	{

		if(collision(entity[i].x + 60, entity[i].y, entity[i].sprite->w, entity[i].sprite->h, entity[j].x, entity[j].y, entity[j].sprite->w, entity[j].sprite->h) == 1)
		{
			entity[i].right = 0;
		}
		else
		{
			if((entity[i].x + entity[i].sprite->w + 1) <= SCREEN_WIDTH - 28)
			{
				entity[i].timer = 1;
				entity[i].center = 64;
				entity[i].right = 1;
			}	
		}
				
		if(collision(entity[i].x - 60, entity[i].y, entity[i].sprite->w, entity[i].sprite->h, entity[j].x, entity[j].y, entity[j].sprite->w, entity[j].sprite->h) == 1)
		{
			entity[i].left = 0;
		}
		else
		{
			if(entity[i].x + 1> 20)
			{
				entity[i].timer = 2;
				entity[i].center = 64;
				entity[i].left = 1;
			}
		}
				
		if(collision(entity[i].x, entity[i].y + 60, entity[i].sprite->w, entity[i].sprite->h, entity[j].x, entity[j].y, entity[j].sprite->w, entity[j].sprite->h) == 1)
		{
			entity[i].down = 0;
		}
		else
		{
			if((entity[i].y + entity[i].sprite->h + 1) <= SCREEN_HEIGHT - 28)
			{
				entity[i].timer = 3;
				entity[i].center = 64;
				entity[i].down = 1;
			}
		}

		if(collision(entity[i].x, entity[i].y - 60, entity[i].sprite->w, entity[i].sprite->h, entity[j].x, entity[j].y, entity[j].sprite->w, entity[j].sprite->h) == 1)
		{
			entity[i].up = 0;
		}
		else
		{
			if(entity[i].y > 36)
			{
				entity[i].timer = 4;
				entity[i].center = 64;
				entity[i].up = 1;
			}
		}
	}
}

void checkAiCollision(int got_i, int got_j)
{
	int i = got_i, j = got_j;

	if ((entity[i].type == TYPE_ENEMY) && (entity[i].center <= 0) && (entity[j].type == TYPE_WALL || entity[j].type == TYPE_BRICK || entity[j].type == TYPE_BOMB))
			{
				switch(entity[i].timer)
				{
					case 1:
						if(collision(entity[i].x + 60, entity[i].y, entity[i].sprite->w, entity[i].sprite->h, entity[j].x, entity[j].y, entity[j].sprite->w, entity[j].sprite->h) == 1)
						{

							if((entity[i].x + entity[i].sprite->w + 1) <= SCREEN_WIDTH - 28)
							{
								entity[i].timer = 1;
								entity[i].center = 64;
								entity[i].right = 1;
							}	
						}
						return;
					case 2:
						if(collision(entity[i].x - 60, entity[i].y, entity[i].sprite->w, entity[i].sprite->h, entity[j].x, entity[j].y, entity[j].sprite->w, entity[j].sprite->h) == 1)
						{
							if(entity[i].x + 1> 20)
							{
								entity[i].timer = 2;
								entity[i].center = 64;
								entity[i].left = 1;
							}
						}
						return;
					case 3:
						if(collision(entity[i].x, entity[i].y + 60, entity[i].sprite->w, entity[i].sprite->h, entity[j].x, entity[j].y, entity[j].sprite->w, entity[j].sprite->h) == 1)
						{
							if((entity[i].y + entity[i].sprite->h + 1) <= SCREEN_HEIGHT - 28)
							{
								entity[i].timer = 3;
								entity[i].center = 64;
								entity[i].down = 1;
							}
						}
						return;
					case 4:
						if(collision(entity[i].x, entity[i].y - 60, entity[i].sprite->w, entity[i].sprite->h, entity[j].x, entity[j].y, entity[j].sprite->w, entity[j].sprite->h) == 1)
						{
							if(entity[i].y > 36)
							{
								entity[i].timer = 4;
								entity[i].center = 64;
								entity[i].up = 1;
							}
						}
						return;
					default:
						defaultTest(i, j);
						break;
				}
			}
}
