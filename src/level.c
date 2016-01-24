#include "level.h" 

extern int loadSprite(char *);
extern void drawImage(SDL_Surface *, int, int);
extern SDL_Surface *getSprite(int);
extern void addEnemy(int, int);
extern void addBrick(int, int);
extern void addWall(int, int);

int initLevel()
{
	terrainImage = getSprite(TERRAIN_SPRITE);

	if(terrainImage == NULL)
		return 1;
	return 0;
}

void fillLevel()
{
	/* posicion with indent to build bricks on level */

	int i = SCREEN_WIDTH-154, j = SCREEN_HEIGHT-148;
	
	/* Fill level depending on SCREEN_WIDTH ,SCREEN_HEIGHT */

	for(;i>0;i-=128)
	{
		for(;j>0;j-=128)
			addBrick(i,j);
		
		j = SCREEN_HEIGHT-148;
	}

	addEnemy(SCREEN_WIDTH-104, SCREEN_HEIGHT-94);
}

void drawLevel()
{
	drawImage(terrainImage, 0, 24);	
}
