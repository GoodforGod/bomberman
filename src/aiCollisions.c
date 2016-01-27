#include "aiCollisions.h"

extern int collision(int, int, int, int, int, int, int, int);

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
					puts("DEF STOP RIGHT");
					entity[i].timer = 0;
				}
		}
		else
		{
			if((entity[i].x + speed + entity[i].sprite->w) < SCREEN_WIDTH - 28)
			{
				if(entity[i].timer == 0)
				{
					entity[i].right = 1;
					puts("DEF RIGHT");
				}
				else entity[i].right = 0;
			}	
		}
		
		/* Left directin */

		if(collision(entity[i].x - block, entity[i].y, entity[i].sprite->w - offset, entity[i].sprite->h - offset, entity[j].x, entity[j].y, entity[j].sprite->w, entity[j].sprite->h - high) == 1)
		{
			entity[i].left = 0;
			if(entity[i].timer == 4)
			{
				puts("DEF STOP LEFT");
				entity[i].timer = 0;
			}
		}
		else
		{
			if(entity[i].x - speed  > 20)
			{
				puts("DEF LEFT");
				if(entity[i].timer == 0)
				{
					entity[i].left = 1;
					puts("DEF LEFT");
				}
				else entity[i].left = 0;
			}
		}
		
		/* Down direction */

		if(collision(entity[i].x, entity[i].y + block, entity[i].sprite->w - offset, entity[i].sprite->h - offset, entity[j].x, entity[j].y, entity[j].sprite->w, entity[j].sprite->h - high) == 1)
		{
			entity[i].down = 0;
			if(entity[i].timer == 2)
			{
				entity[i].timer = 0;
				puts("DEF STOP DOWN");
			}
		}
		else
		{
			if((entity[i].y + speed + entity[i].sprite->h) < SCREEN_HEIGHT- 28)
			{
				if(entity[i].timer == 0)
				{
					entity[i].down = 1;
					puts("DEF DOWN");
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
				puts("DEF STOP UP");
			}
		}
		else
		{
			if(entity[i].y - speed > 32)
			{
			    if(entity[i].timer == 0)
				{
					entity[i].up = 1;
					puts("DEF UP");
				}
				else entity[i].up = 0;
			}
		}
	}
}

/* Check prosedure, used to check next chunk when the Vector is set */

void checkAiCollision(int got_i, int got_j, int movement)
{
	/* entity.timer = movement Vector */

	int i = got_i, j = got_j, block = 64, offset = 6, high = 4, speed = 2;

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
								puts("STOP RIGHT");
							}
						}
						else
						{
							if((entity[i].x + entity[i].sprite->w + speed) < SCREEN_WIDTH - 28)
							{
								puts("RIGHT");
								entity[i].timer = 3;
								return;
							}
						}
						break;
					case 4:
						if(collision(entity[i].x - block, entity[i].y, entity[i].sprite->w - offset, entity[i].sprite->h - offset, entity[j].x, entity[j].y, entity[j].sprite->w, entity[j].sprite->h - high) == 1)
						{
							entity[i].left = 0;
							if(entity[i].timer == 4)
							{
								entity[i].timer = 0;
								puts("LEFT STOP");
							}
						}
						else
						{
							if(entity[i].x + speed > 20)
							{
								entity[i].timer = 4;
								puts("LEFT");
								return;
							}
						}
						break;
					case 2:
						if(collision(entity[i].x, entity[i].y + block, entity[i].sprite->w - offset, entity[i].sprite->h - offset, entity[j].x, entity[j].y, entity[j].sprite->w, entity[j].sprite->h - high) == 1)
						{
							entity[i].down = 0;
							if(entity[i].timer == 2)
							{
								entity[i].timer = 0;
								puts("STOP DOWN");
							}
						}
						else
						{
							if((entity[i].y + entity[i].sprite->h + speed) < SCREEN_HEIGHT - 28)
							{
								entity[i].timer = 2;
								puts("DOWN");
								return;
							}
						}
						break;
					case 1:
						if(collision(entity[i].x, entity[i].y - block, entity[i].sprite->w - offset, entity[i].sprite->h - offset, entity[j].x, entity[j].y, entity[j].sprite->w, entity[j].sprite->h - high) == 1)
						{
							entity[i].up = 0;
							if(entity[i].timer == 1)
							{
								entity[i].timer = 0;
								puts("STOP UP");
							}
						}
						else
						{
							if(entity[i].y + speed > 32)
							{
								entity[i].timer = 1;
								puts("UP");
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
