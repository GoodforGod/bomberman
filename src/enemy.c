#include "enemy.h"

extern int getFreeEntity(void);
extern void drawStandardEntity(void);
extern SDL_Surface *getSprite(int);

static void moveEnemy(void);

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
	entity[i].action = &moveEnemy;
	entity[i].draw = &drawStandardEntity;
	entity[i].sprite = getSprite(ENEMY_SPRITE);
	entity[i].type = TYPE_ENEMY;
}

static void moveEnemy(void)
{
	/* Do nothing, just sit there */
}
