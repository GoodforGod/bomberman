#include "wall.h"

extern int getFreeEntity(void);
extern void drawStandardEntity(void);
extern SDL_Surface *getSprite(int);

static void doWall(void);

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
}

static void doWall(void)
{

}
