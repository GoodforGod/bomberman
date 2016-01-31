#include "aiCollisions.h"

/* Default check prosedure, used when no vector (vector = 0) */

void defaultTest(int i, int j, int speed, int block, int offset, int high)
{
	/* Block - offset to check next chunk, speed - offset to correct check due to enemy speed */
	
	/* Check all directions for empty block to move next and store that data into enemy entity */
	
	if ((entity[i].type == TYPE_ENEMY) && (entity[i].center <= 0) && (entity[j].type == TYPE_WALL || entity[j].type == TYPE_BRICK || entity[j].type == TYPE_BOMB))
	{

		/* Right direction */

		if(collision(entity[i].x + block, entity[i].y, entity[i].sprite->w - offset, entity[i].sprite->h - offset, entity[j].x, entity[j].y, entity[j].sprite->w, entity[j].sprite->h - high) == 1)
		{
			entity[i].right = 0;
			if(entity[i].timer == 3)
				{
					entity[i].timer = 0;
				}
		}
		else
		{
			if((entity[i].x + speed + entity[i].sprite->w) < SCREEN_WIDTH - LEVEL_X_OFFSET)
			{
				if(entity[i].timer == 0)
				{
					entity[i].right = 1;
				}
			}	
			else entity[i].right = 0;
		}
		
		/* Left directin */

		if(collision(entity[i].x - block, entity[i].y, entity[i].sprite->w - offset, entity[i].sprite->h - offset, entity[j].x, entity[j].y, entity[j].sprite->w, entity[j].sprite->h - high) == 1)
		{
			entity[i].left = 0;
			if(entity[i].timer == 4)
			{
				entity[i].timer = 0;
			}
		}
		else
		{
			if(entity[i].x - speed  > LEVEL_X_OFFSET)
			{
				if(entity[i].timer == 0)
				{
					entity[i].left = 1;
				}
			}
			else entity[i].left = 0;
		}
		
		/* Down direction */

		if(collision(entity[i].x, entity[i].y + block, entity[i].sprite->w - offset, entity[i].sprite->h - offset, entity[j].x, entity[j].y, entity[j].sprite->w, entity[j].sprite->h - high) == 1)
		{
			entity[i].down = 0;
			if(entity[i].timer == 2)
			{
				entity[i].timer = 0;
			}
		}
		else
		{
			if((entity[i].y + speed + entity[i].sprite->h) < SCREEN_HEIGHT - LEVEL_Y_OFFSET)
			{
				if(entity[i].timer == 0)
				{
					entity[i].down = 1;
				}
			}
			else entity[i].down = 0;
		}

		/* Front direction */

		if(collision(entity[i].x, entity[i].y - block, entity[i].sprite->w - offset, entity[i].sprite->h - offset, entity[j].x, entity[j].y, entity[j].sprite->w, entity[j].sprite->h - high) == 1)
		{
			entity[i].up = 0;
			if(entity[i].timer == 1)
			{	
				entity[i].timer = 0;
			}
		}
		else
		{
			if(entity[i].y - speed > LEVEL_Y_OFFSET)
			{
			    if(entity[i].timer == 0)
				{
					entity[i].up = 1;
				}
			}
			else entity[i].up = 0;
		}
	}
}

/* Check prosedure, used to check next chunk when the Vector is set */

void checkAiCollision(int got_i, int got_j, int movement)
{
	/* entity.timer = movement Vector */

	int i = got_i, j = got_j, block = 64, offset = 2, high = 2, speed = 2;

	if ((entity[i].type == TYPE_ENEMY) && (entity[i].center <= 0) && (entity[j].type == TYPE_WALL || entity[j].type == TYPE_BRICK || entity[j].type == TYPE_BOMB))
			{
				/* Switch for Vector, to choose which is set, 
				 * if next chunk on that vector is free, 
				 * then move next or use default procedure */

				/* Case 1 - Up
				 * Case 2 - Down
				 * Case 3 - Right
				 * Case 4 - Left
				 */

				switch(entity[i].timer)
				{
					case 3:
						if(collision(entity[i].x + block, entity[i].y, entity[i].sprite->w - offset, entity[i].sprite->h - offset, entity[j].x, entity[j].y, entity[j].sprite->w, entity[j].sprite->h - high) == 1)
						{
							entity[i].right = 0;
							if(entity[i].timer == 3)
							{
								entity[i].timer = 0;
							}
						}
						else
						{
							if((entity[i].x + entity[i].sprite->w + speed) < SCREEN_WIDTH - LEVEL_X_OFFSET)
							{
								entity[i].timer = 3;
								return;
							}
							else entity[i].timer = 0;
						}
						break;
					case 4:
						if(collision(entity[i].x - block, entity[i].y, entity[i].sprite->w - offset, entity[i].sprite->h - offset, entity[j].x, entity[j].y, entity[j].sprite->w, entity[j].sprite->h - high) == 1)
						{
							entity[i].left = 0;
							if(entity[i].timer == 4)
							{
								entity[i].timer = 0;
							}
						}
						else
						{
							if(entity[i].x - speed > LEVEL_X_OFFSET)
							{
								entity[i].timer = 4;
								return;
							}
							else entity[i].timer = 0;
						}
						break;
					case 2:
						if(collision(entity[i].x, entity[i].y + block, entity[i].sprite->w - offset, entity[i].sprite->h - offset, entity[j].x, entity[j].y, entity[j].sprite->w, entity[j].sprite->h - high) == 1)
						{
							entity[i].down = 0;
							if(entity[i].timer == 2)
							{
								entity[i].timer = 0;
							}
						}
						else
						{
							if((entity[i].y + entity[i].sprite->h + speed) < SCREEN_HEIGHT - LEVEL_Y_OFFSET)
							{
								entity[i].timer = 2;
								return;
							}
							else entity[i].timer = 0;
						}
						break;
					case 1:
						if(collision(entity[i].x, entity[i].y - block, entity[i].sprite->w - offset, entity[i].sprite->h - offset, entity[j].x, entity[j].y, entity[j].sprite->w, entity[j].sprite->h - high) == 1)
						{
							entity[i].up = 0;
							if(entity[i].timer == 1)
							{
								entity[i].timer = 0;
							}
						}
						else
						{
							if(entity[i].y + speed > LEVEL_Y_OFFSET)
							{
								entity[i].timer = 1;
								return;
							}
							else entity[i].timer = 0;
						}
						break;
				}

				/* If prev Vector had next chunk filled, use default procedure */
				
				if(entity[i].timer == 0)
					defaultTest(i, j, speed, block, offset, high);
		}
}
