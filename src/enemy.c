#include "enemy.h"

extern int getFreeEntity(void);
extern void drawAnimationEntity(void);
extern SDL_Surface *getSprite(int);
extern int collision(int, int, int, int, int, int, int, int);

void moveEnemy(void);

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
	entity[i].up = 0;
	entity[i].down = 0;
	entity[i].left = 0;
	entity[i].right = 0;
	entity[i].center = 0;
	entity[i].action = &moveEnemy;
	entity[i].draw = &drawAnimationEntity;
	entity[i].sprite = getSprite(ENEMY_BLUE_IDLE_SPRITE);
	entity[i].type = TYPE_ENEMY;
}

void moveEnemy(void)
{
	int speed = 2;
	while(1)
	{
		if((self->up = 1) && (self->center >= 0) && (self->y > 32))
		{
			self->y -= speed;
			self->center--;
			break;
		}

		if((self->down = 1) && (self->center >= 0) && ((self->y + self->sprite->h + 1) <= SCREEN_HEIGHT - 28))
		{
			self->y += speed;
			self->center--;
			break;
		}

		if((self->right = 1) && (self->center >= 0) && ((self->x + self->sprite->w + 1) <= SCREEN_WIDTH - 28))
		{
			self->x += speed;
			self->center--;
			break;
		}

		if((self->left = 1) && (self->center > 0) && (self->x> 20))
		{
			self->x -= speed;
			self->center--;
		}

		break;
	}

	if(self->center <= 0)
	{
		self->up = 0;
		self->down = 0;
		self->right = 0;
		self->left = 0;
	}

	if (self->x >= SCREEN_WIDTH || self->x <= 0)
		self->active = 0;

	if(self->y >= SCREEN_HEIGHT || self->y <= 0)
		self->active = 0;
}
