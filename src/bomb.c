#include "bomb.h"

extern int getFreeEntity(void);
extern void drawStandardEntity(void);
extern SDL_Surface *getSprite(int);
extern void playSound(int);

static void moveStandardBomb(void);

void addBomb(int x, int y)
{
	int i = getFreeEntity();
	
	if (i == -1)
	{
		printf("Couldn't get a free slot for a bomb!\n");
		
		return;
	}
	
	entity[i].x = x;
	entity[i].y = y;
	entity[i].action = &moveStandardBomb;
	entity[i].draw = &drawStandardEntity;
	entity[i].sprite = getSprite(BOMB_SPRITE);
	entity[i].type = TYPE_BOMB;
	
	/* Play a sound when the bomb is placed */
	
	playSound(BOMB_SOUND);
}

static void moveStandardBomb()
{
	/* Move the bomb across the screen for test reasons*/
	
	self->x += BOMB_SPEED;
	
	/* Kill the bomb if it moves off the screen */
	
	if (self->x >= SCREEN_WIDTH)
	{
		self->active = 0;
	}
}
