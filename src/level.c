#include "level.h" 

extern int loadSprite(char *);
extern void drawImage(SDL_Surface *, int, int);
extern SDL_Surface *getSprite(int);

int initLevel()
{
	terrainImage = getSprite(TERRAIN_SPRITE);

	if(terrainImage == NULL)
		return 1;
	return 0;
}

void drawLevel()
{
	drawImage(terrainImage, 0, 0);	
}
