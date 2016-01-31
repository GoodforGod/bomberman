#include "enemy.h"

void moveEnemy(void);

/* The same as addWall, addFire, addBomb.. But thats enemies, ENEMIES DUDE! */

void addEnemy(int x, int y)
{
	int i = getFreeEntity();
	
	if (i == -1)
	{
		printf("Couldn't get a free slot for an enemy !\n");
		
		return;
	}
	
	entity[i].x = x;
	entity[i].y = y;
	entity[i].up = 0;
	entity[i].down = 0;
	entity[i].left = 0;
	entity[i].right = 0;
	entity[i].center = 0;
	entity[i].timer = 0;
	entity[i].action = &moveEnemy;
	entity[i].draw = &drawAnimationEntity;
	entity[i].sprite = getSprite(ENEMY_IDLE_SPRITE);
	entity[i].type = TYPE_ENEMY;
}

void moveEnemy(void)
{
	/* Remember prev coordinates, to backup from them if moved off screen */

	int speed = 2;
	self->prev_x = self->x;
	self->prev_y = self->y;

	/* Switch for Vector to move 
	* Case 1 - Up
	* Case 2 - Down
	* Case 3 - Right
	* Case 4 - Left
	*/

	/* Use 1 gas, due to 1 action performed */
	
	switch(self->timer)
	{
		case 1:
			self->y -= speed;
			break;
		case 2:
			self->y += speed;
			break;
		case 3:
			self->x += speed;
			break;
		case 4:
			self->x -= speed;
			break;
		default:
			break;
	}

	self->center--;
	/* Check to not move off protected area screen */

	if(self->y < 32)
	{
		self->y = self->prev_y;
		self->timer = 0;
	}
	if((self->y + self->sprite->h) > SCREEN_HEIGHT - 28)
	{
		self->y = self->prev_y;
		self->timer = 0;
	}
	if((self->x + self->sprite->w) > SCREEN_WIDTH - 28)
	{
		self->x = self->prev_x;
		self->timer = 0;
	}
	if(self->x < 20)
	{
		self->x = self->prev_x;
		self->timer = 0;
	}

	/* Check to not move off screen */
	if (self->x >= SCREEN_WIDTH || self->x <= 0)
		self->active = 0;

	if(self->y >= SCREEN_HEIGHT || self->y <= 0)
		self->active = 0;
}
