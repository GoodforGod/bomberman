#include "bomb.h"

extern int getFreeEntity(void);
extern void drawStandardEntity(void);
extern SDL_Surface *getSprite(int);
extern void playSound(int);
extern void drawAnimationEntity(void);

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
	entity[i].draw = &drawAnimationEntity;
	entity[i].sprite = getSprite(BOMB_SPRITE);
	entity[i].type = TYPE_BOMB;
	entity[i].timer = SDL_GetTicks();	
}

static void moveStandardBomb()
{
	/* Kill the bomb if it moves off the screen or time is out and play sound */
	
	if(SDL_GetTicks() - self->timer >= 2800)
	{
		self->active = 0;
		player.bomb = 0;
		playSound(BOMB_SOUND);
}
	if (self->x >= SCREEN_WIDTH)
	{
		self->active = 0;
		player.bomb = 0;
		playSound(BOMB_SOUND);
	}
}
