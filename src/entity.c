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
}

void drawAnimationEntity()
{
	switch(self->type)
	{
	
		case TYPE_ENEMY:
			doSpeedAnimation(&enemyBlueLeft, 9);
			drawAnimation(&enemyBlueLeft, self->x, self->y);
			break;
		case TYPE_BOMB:
			doSpeedAnimation(&bombAnimation, 9);
			drawAnimation(&bombAnimation, self->x, self->y);

	}
}
void drawStandardEntity()
{
	drawImage(self->sprite, self->x, self->y);
}
