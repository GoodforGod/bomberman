#include "structs.h"

Entity *self, entity[MAX_ENTITIES];
SDL_Surface *terrainImage;
extern Game game;

extern void spawnEnemy(size_t);
extern void drawImage(SDL_Surface *, int, int);
extern SDL_Surface *getSprite(int);
extern void addEnemy(int, int);
extern void addBrick(int, int, int);
extern void addWall(int, int);
