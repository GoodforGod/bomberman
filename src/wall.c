#include "wall.h"

static void doWall(void);

/* Oh... Come on.... */

void addWall(int x, int y)
{
	int i = getFreeEntity();
	
	if (i == -1)
	{
		printf("Couldn't get a free slot for a wall!\n");
		
		return;
	}
	
	entity[i].x = x;
	entity[i].y = y;
	entity[i].action = &doWall; 
	entity[i].draw = &drawStandardEntity;
	entity[i].sprite = getSprite(WALL_IDLE_SPRITE);
	entity[i].type = TYPE_WALL;
	entity[i].bomb = 0;
}

static void doWall(void)
{
	/* If wall was hit by fire then start its destruction */

	if(self->bomb == 1)
		self->draw = &drawAnimationEntity;
	
	/* If animation done, then free wall */

	if(wallAnimation.frameIndex == 6 && self->bomb == 1)
	{
		self->active = 0;
		wallAnimation.frameIndex = 0;
	}
}
