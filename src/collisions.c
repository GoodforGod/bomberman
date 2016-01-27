#include "collisions.h"

extern void playSound(int);

int collision(int, int, int, int, int, int, int, int);
extern void checkAiCollision(int, int, int);

void doCollisions()
{
	int i, j, movement = 64, rand_left, rand_right, rand_down, rand_up, digit;
	static int prev_vector = 0;
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
		
		/* Test player collision with wall and brick or bonus */

		if ((entity[i].type == TYPE_WALL || entity[i].type == TYPE_BRICK || entity[i].type == TYPE_BONUS_AMMO) && (collision(entity[i].x, entity[i].y, entity[i].sprite->w-12, entity[i].sprite->h-4, player.x, player.y, player.sprite->w-12, player.sprite->h-4) == 1))
		{
			if(entity[i].type == TYPE_BONUS_AMMO)
			{
				player.bomb++;
				entity[i].active = 0;
				playSound(BONUS);
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
		
		/* Set all direction parameters for TYPE_ENEMY to max, to check AI */

		if(entity[i].type == TYPE_ENEMY && entity[i].center == 0)
		{
			entity[i].up = 1;
			entity[i].down = 1;
			entity[i].right = 1;
			entity[i].left = 1;
		}

		for (j=0;j<MAX_ENTITIES;j++)
		{
			/* Don't collide with yourself, inactive entities or entities of the same type */
			
			if (i == j || entity[j].active == 0 || entity[j].type == entity[i].type)
				continue;
			
			/* Collision test for AI */

			checkAiCollision(i, j, movement);	
			
			/* If a collision occured with fire and enemy, remove enemy */
		
			if((entity[i].type == TYPE_FIRE_BACK || entity[i].type == TYPE_FIRE_LEFT || entity[i].type == TYPE_FIRE_FRONT || entity[i].type == TYPE_FIRE_RIGHT || entity[i].type == TYPE_FIRE_CENTER ) && entity[j].type == TYPE_ENEMY)
			{
				
				if (collision(entity[i].x, entity[i].y, entity[i].sprite->w, entity[i].sprite->h, entity[j].x, entity[j].y, entity[j].sprite->w, entity[j].sprite->h) == 1)
				{
					game.score+=100;
					entity[j].active = 0;
					bombermanCool.frameIndex = 0;
					break;
				}
			}
			
			/* Test collision for bomb, to not place it in wrong place */
			
			if(entity[i].type == TYPE_BOMB && (entity[j].type == TYPE_WALL || entity[j].type == TYPE_BRICK || entity[j].type == TYPE_ENEMY))
			{	
				if (collision(entity[i].x, entity[i].y, entity[i].sprite->w-6, entity[i].sprite->h-6, entity[j].x, entity[j].y, entity[j].sprite->w-4, entity[j].sprite->h-4) == 1)
				{
					if(entity[j].type == TYPE_ENEMY && entity[j].timer == 1)
						entity[j].timer = 2;
					if(entity[j].type == TYPE_ENEMY && entity[j].timer == 2)
						entity[j].timer = 1;
					if(entity[j].type == TYPE_ENEMY && entity[j].timer == 3)
						entity[j].timer = 4;
					if(entity[j].type == TYPE_ENEMY && entity[j].timer == 4)
						entity[j].timer = 3;	
					if(entity[j].type != TYPE_ENEMY)
					{
						entity[i].active = 0;
						player.bomb++;
					}
					break;
				}
			}
			
			/* Test collision with fire and wall, start wall destraction if occured */

				if ((entity[i].type == TYPE_FIRE_CENTER || entity[i].type == TYPE_FIRE_FRONT || entity[i].type == TYPE_FIRE_RIGHT || entity[i].type == TYPE_FIRE_LEFT || entity[i].type == TYPE_FIRE_BACK) && (entity[j].type == TYPE_WALL || entity[j].type == TYPE_BRICK) && (collision(entity[i].x, entity[i].y, entity[i].sprite->w-4, entity[i].sprite->h-4, entity[j].x, entity[j].y, entity[j].sprite->w, entity[j].sprite->h) == 1))
			{
				entity[i].active = 0;
				if(entity[j].type == TYPE_WALL)
					entity[j].bomb = 1;
				break;
			}
		}

		/* When data collision of enemy recieved, fill the Vector of the direction 'timer' to move enemy */

		if(entity[i].type == TYPE_ENEMY && entity[i].center <= 0)
		{
			/* if enemy have no points to move, then fill Vector or check previose */


			/* Only if no vector or previos, was reset */

			entity[i].center = movement;
			if(entity[i].timer == 0)
			{
				puts("ZERO");
				if(entity[i].up == 1)
				{
					if(entity[i].y >= 36)
					{
						entity[i].timer++;
					}
				}
				if(entity[i].down == 1)
				{
					if((entity[i].y + entity[i].sprite->h) <= SCREEN_HEIGHT - 28)
					{
						entity[i].timer += 10;
					}
				}
				if(entity[i].right == 1)
				{
					if((entity[i].x + entity[i].sprite->w) <= SCREEN_WIDTH - 28)
					{
						entity[i].timer += 100;
					}
				}
				if(entity[i].left == 1)
				{
					if(entity[i].x >= 20)
					{
						entity[i].timer += 1000;
					}
				}

				/* Vector is random, due to make enemy more random, up = 1, down = 2, etc. */

				digit = (int)entity[i].timer;
				
				if(digit/1000 >= 1)
				{
					rand_up = digit % 10;
					digit /= 10;
				}
				if(digit/100 >= 1)
				{
					rand_down = digit % 10;
					digit /= 10;
				}
				if(digit/10 >= 1)
				{
					rand_right = digit % 10;
					digit /= 10;
				}
				
				rand_left = digit % 10;

				/* Get random vector between 1 and 4 */
				
				entity[i].timer = (unsigned long) rand() % (10) + 2;
					if(entity[i].timer > 4)
						entity[i].timer -= 3;
					if(entity[i].timer > 4)
						entity[i].timer -= 3;
					if(entity[i].timer > 4)
						entity[i].timer -= 3;
					puts("NEW VECTOR");
						if((entity[i].y > (SCREEN_HEIGHT / 2) + 200) && (rand_up == 1))
						{
							entity[i].timer = 1;
							break;
						}
						if((entity[i].y < (SCREEN_HEIGHT/2) - 200 ) && rand_down == 1)
						{
							entity[i].timer = 2;
							break;
						}
						if((entity[i].x > (SCREEN_WIDTH / 2) + 350) &&  rand_left == 1)
						{
							entity[i].timer = 4;
							break;
						}
						if((entity[i].x < (SCREEN_WIDTH / 2) - 350) && rand_right == 1)
						{
							entity[i].timer = 3;
							break;
						}
					}
					prev_vector--;
					switch(entity[i].timer)
					{
						case 1:
							prev_vector = 2;
							break;
						case 2:
							prev_vector = 1;
							break;
						case 3:
							prev_vector = 4;
							break;
						case 4:
							prev_vector = 3;
							break;
						default:
							prev_vector = 0;
							break;
					}
					prev_vector++;
					/*
					if(entity[i].timer == 1 && rand_up == 1)
						break;
					if(entity[i].timer == 2 && rand_down == 1)
						break;
					if(entity[i].timer == 3 && rand_right == 1)
						break;
					if(entity[i].timer == 4 && rand_left == 1)
						break;
					*/
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
