#include "level.h" 

extern int loadSprite(char *);
extern void drawImage(SDL_Surface *, int, int);
extern SDL_Surface *getSprite(int);
extern void addEnemy(int, int);
extern void addBrick(int, int, int);
extern void addWall(int, int);

/* Terrain sprite initializing */

int initLevel()
{
	terrainImage = getSprite(TERRAIN_SPRITE);

	if(terrainImage == NULL)
		return 1;
	return 0;
}

void fillLevel()
{
	/* Position with indent to build correct bricks on level, 
	 * basic structure on the level, 
	 * all other structures placed based on  bricks
	 * function addBrick is also used to add Bonuses over the level
	 * Cause it can accept the TYPE of structure */

	int i = SCREEN_WIDTH-154, j = SCREEN_HEIGHT-148, y_offset = 152, x_offset = 154;
	
	/* Fill level depending on SCREEN_WIDTH ,SCREEN_HEIGHT and offsets */

	for(;i>0;i-=128)
	{
		for(;j>0;j-=128)
		{
			/* Fill level with bricks */

			addBrick(i, j, TYPE_BRICK);  
		}
		j = SCREEN_HEIGHT-148;
	}
	
	i = SCREEN_WIDTH-154;
	j = SCREEN_HEIGHT-148;
	
	for(;i>0;i-=256)
	{
		for(;j>0;j-=448)
		{
			/* Fill level with walls randomly */

			addWall(i - 64, j - 64);
		}
		j = SCREEN_HEIGHT-148;
	}

	for(;i>0;i-=128)
	{
		for(;j>0;j-=128)
		{
			/* Fill level with enemys randomly */

			addEnemy(i - 64, j - 64);
		}
		j = SCREEN_HEIGHT-148;
	}

	addEnemy(SCREEN_WIDTH - x_offset + 64, SCREEN_HEIGHT - y_offset);
	addBrick(SCREEN_WIDTH - x_offset - 64, SCREEN_HEIGHT - y_offset - 4, TYPE_BONUS_AMMO);
	addEnemy(SCREEN_WIDTH - x_offset + 64, SCREEN_HEIGHT - y_offset - 256 - 64);
}

void drawLevel()
{
	drawImage(terrainImage, 0, 24);	
}
