#include "level.h" 

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

	int i, j, theX = SCREEN_WIDTH-128-LEVEL_X_OFFSET, theY = SCREEN_HEIGHT-128-LEVEL_X_OFFSET;
	i = theX, j = theY;

	/* Fill level depending on SCREEN_WIDTH ,SCREEN_HEIGHT and offsets */

	/* Amount of enemies at the begining */

	game.enemies = ENEMY_INIT_COUNT;
	
	for(;i>0;i-=128)
	{
		for(;j>0;j-=128)
		{
			/* Fill level with bricks */

			addBrick(i, j, TYPE_BRICK);  
		}
		j = theY;
	}
	
	i = theX;
	j = theY;
	
	for(;i>0;i-=256)
	{
		for(;j>0;j-=448)
		{
			/* Fill level with walls randomly */

			addWall(i - 64, j - 64);
		}
		j = theY;
	}

	for(;i>0;i-=128)
	{
		for(;j>0;j-=128)
		{
			/* Fill level with enemys randomly */

			addEnemy(i - 64, j - 64);
		}
		j = theY;
	}

	addBrick(SCREEN_WIDTH - LEVEL_X_OFFSET - 128, SCREEN_HEIGHT - LEVEL_X_OFFSET - 64 - 128, TYPE_BONUS_AMMO);
	spawnEnemy((size_t)game.enemies);	
}

void drawLevel()
{
	drawImage(terrainImage, 0, 24);	
}
