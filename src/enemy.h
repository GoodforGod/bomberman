#include "structs.h"

extern Entity *self, entity[MAX_ENTITIES];
extern Animation enemyLeft, enemyRight, enemyUp, enemyDown;

extern int getFreeEntity(void);
extern void drawAnimationEntity(void);
extern SDL_Surface *getSprite(int);
