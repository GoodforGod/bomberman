#include "entity.h"

extern void drawImage(SDL_Surface *, int, int);
extern void drawAnimation(Animation *, int, int);
extern void doSpeedAnimation(Animation *, int);

void clearEntities()
{
	int i;
	
	/* Clear the list */

	for (i=0;i<MAX_ENTITIES;i++)
	{
		memset(&entity[i], 0, sizeof(Entity));
	}
}

int getFreeEntity()
{
	int i;
	
	/* Loop through all the entities and find a free slot */
	
	for (i=0;i<MAX_ENTITIES;i++)
	{
		if (entity[i].active == 0)
		{
			memset(&entity[i], 0, sizeof(Entity));
			
			entity[i].active = 1;
			
			return i;
		}
	}
	
	/* Return -1 if you couldn't any free slots */
	
	return -1;
}

void doEntities()
{
	int i;
	
	/* Loop through the entities and perform their action */
	
	for (i=0;i<MAX_ENTITIES;i++)
	{
		self = &entity[i];
		
		if (self->active == 1)
		{
			self->action();
		}
	}
}

void cycleAllAnimations()
{
	int speed = 15;
	
	/* cycle to synhronize all animations to draw next ones except wall */

	doSpeedAnimation(&fireFrontAnimation, speed);
	doSpeedAnimation(&fireRightAnimation, speed);
	doSpeedAnimation(&fireBackAnimation, speed);
	doSpeedAnimation(&fireLeftAnimation, speed);
	doSpeedAnimation(&fireCenterAnimation, speed);
	doSpeedAnimation(&enemyBlueLeft, 9);
	doSpeedAnimation(&enemyBlueRight, 9);
	doSpeedAnimation(&bombAnimation, 10);	
}

void drawEntities()
{
	int i;
	
	/* Loop through the entities and perform their action */
	
	for (i=0;i<MAX_ENTITIES;i++)
	{
		self = &entity[i];
		
		if (self->active == 1)
		{
			self->draw();
		}
	}
	cycleAllAnimations();
}

void drawAnimationEntity()
{
	/* Use switch to choose animation for specific TYPE */ 

	switch(self->type)
	{
		case TYPE_ENEMY:
			if(self->x < self->prev_x)
				drawAnimation(&enemyBlueLeft, self->x, self->y);
			else
				drawAnimation(&enemyBlueRight, self->x, self->y);
			break;
		case TYPE_BOMB:
			drawAnimation(&bombAnimation, self->x, self->y);
			break;
		case TYPE_FIRE_FRONT:
			drawAnimation(&fireFrontAnimation, self->x, self->y);
			break;
		case TYPE_FIRE_RIGHT:
			drawAnimation(&fireRightAnimation, self->x, self->y);
			break;
		case TYPE_FIRE_BACK:
			drawAnimation(&fireBackAnimation, self->x, self->y);
			break;
		case TYPE_FIRE_LEFT:
			drawAnimation(&fireLeftAnimation, self->x, self->y);
			break;
		case TYPE_FIRE_CENTER:
			drawAnimation(&fireCenterAnimation, self->x, self->y);
			break;
		case TYPE_WALL:
			doSpeedAnimation(&wallAnimation, 15);
			drawAnimation(&wallAnimation, self->x, self->y);
	}
}

void drawStandardEntity()
{
	drawImage(self->sprite, self->x, self->y);
}
