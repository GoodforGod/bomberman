#include "brick.h"

extern int getFreeEntity(void);
extern void drawStandardEntity(void);
extern SDL_Surface *getSprite(int);

static void doBrick(void);

void addBrick(int x, int y, int setType)
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
	switch(setType)
	{
		case TYPE_BRICK:
			entity[i].sprite = getSprite(BRICK_IDLE_SPRITE);
			break;
		case TYPE_BONUS_AMMO:
			entity[i].sprite = getSprite(BONUS_AMMO_SPRITE);
			break;
	}
	entity[i].type = setType;
}

static void doBrick(void)
{

}
