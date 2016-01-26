#include "fire.h"

extern int getFreeEntity(void);
extern SDL_Surface *getSprite(int);
extern void drawAnimationEntity(void);

static void doFire(void);

/* Add fire and use switch to choose the right angle of animation */
/* Work like bomb module */

void addFire(int x, int y, int fire_direction_type)
{
	int i = getFreeEntity();
	
	if (i == -1)
	{
		printf("Couldn't get a free slot for a fire!\n");
		return;
	}
	
	entity[i].x = x;
	entity[i].y = y;
	entity[i].action = &doFire;
	entity[i].draw = &drawAnimationEntity;
	entity[i].sprite = getSprite(FIRE_SPRITE);
	
	/* Choose correct fire type */
	
	switch(fire_direction_type)
	{
		case TYPE_FIRE_FRONT:
			entity[i].type = TYPE_FIRE_FRONT;
			break;
		case TYPE_FIRE_RIGHT:
			entity[i].type = TYPE_FIRE_RIGHT;
			break;
		case TYPE_FIRE_BACK:
			entity[i].type = TYPE_FIRE_BACK;
			break;
		case TYPE_FIRE_LEFT:
			entity[i].type = TYPE_FIRE_LEFT;
			break;
		case TYPE_FIRE_CENTER: 
			entity[i].type = TYPE_FIRE_CENTER;
			break;
		default:
			entity[i].type = TYPE_FIRE_FRONT;
			break;
	}

	entity[i].timer = SDL_GetTicks();	
}

void resetAnimation(int fire_direction_type)
{
	switch(fire_direction_type)
	{
		case TYPE_FIRE_FRONT:
			fireFrontAnimation.frameIndex = 0;
			break;
		case TYPE_FIRE_RIGHT:
			fireRightAnimation.frameIndex = 0;
			break;
		case TYPE_FIRE_BACK:
			fireBackAnimation.frameIndex = 0;
			break;
		case TYPE_FIRE_LEFT:
			fireLeftAnimation.frameIndex = 0;
			break;
		case TYPE_FIRE_CENTER: 
			fireCenterAnimation.frameIndex = 0;
			break;
		default:
			fireFrontAnimation.frameIndex = 0;
			break;
	}
}

static void doFire()
{
	/* Kill the fire if it moves off the screen or time is out */
	
	if(SDL_GetTicks() - self->timer >= 800)
	{
		self->active = 0;
		resetAnimation(self->type);	
	}
	if (self->x >= SCREEN_WIDTH)
	{
		self->active = 0;
		resetAnimation(self->type);	
	}
}
