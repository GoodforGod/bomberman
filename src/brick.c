#include "brick.h"

extern int getFreeEntity(void);
extern void drawStandardEntity(void);
extern SDL_Surface *getSprite(int);

static void doBrick(void);

void addBrick(int x, int y)
{
	int i = getFreeEntity();
	
	if (i == -1)
	{
		printf("Couldn't get a free slot for a brick!\n");
		
		return;
	}
	
	entity[i].x = x;
	entity[i].y = y;
	entity[i].action = &doBrick;
	entity[i].draw = &drawStandardEntity;
	entity[i].sprite = getSprite(BRICK_IDLE_SPRITE);
	entity[i].type = TYPE_BRICK;
}

static void doBrick(void)
{

}
