#include "bomb.h"

extern int getFreeEntity(void);
extern SDL_Surface *getSprite(int);
extern void playSound(int);
extern void drawAnimationEntity(void);
extern void addFire(int, int, int);
extern int collision(int, int, int, int, int, int, int, int);
static void moveStandardBomb(void);

/* The same ass addWall, addBrick, add Fire, just for bombs, FOR BOMBS ONLY I SAID! */

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
	/* Kill the bomb if it moves off the screen or time is out and play sound and add fire */
	
	if(SDL_GetTicks() - self->timer >= 2800)
	{
		self->active = 0;
		player.bomb++;
		addFire(self->x, self->y, TYPE_FIRE_CENTER);
		addFire(self->x, self->y-64, TYPE_FIRE_FRONT);
		addFire(self->x+64, self->y, TYPE_FIRE_RIGHT);
		addFire(self->x, self->y+64, TYPE_FIRE_BACK);
		addFire(self->x-64, self->y, TYPE_FIRE_LEFT); 
		playSound(BOMB_SOUND);
	}
	
	if (self->x >= SCREEN_WIDTH)
	{
		self->active = 0;
		player.bomb++;
		playSound(BOMB_SOUND);
	}
}
