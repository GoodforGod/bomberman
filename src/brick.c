#include "brick.h"

extern int getFreeEntity(void);
extern void drawStandardEntity(void);
extern SDL_Surface *getSprite(int);

static void doBrick(void);

/* Similar to addWall and addEnemy 
 * But this function can accept TYPE of structure
 * and is also used to add Bonuses */

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
	entity[i].type = setType;
	
	switch(setType)
	{
		case TYPE_BRICK:
			entity[i].sprite = getSprite(BRICK_IDLE_SPRITE);
			break;
		case TYPE_BONUS_AMMO:
			entity[i].sprite = getSprite(BONUS_AMMO_SPRITE);
			break;
	}
}

static void doBrick(void)
{
	/* Come on, bricks do nothing, buddy! */
}
