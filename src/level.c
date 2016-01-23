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
	addEnemy(840, 50);
	addEnemy(840, 150);
	addEnemy(840, 250);
	addEnemy(840, 350);
	addEnemy(840, 450);
	addEnemy(740, 450);
	addBrick(0, 0);
	addBrick(64,64);
	addWall(832,512);
	addWall(896,576);

}

void drawLevel()
{
	drawImage(terrainImage, 0, 0);	
}
