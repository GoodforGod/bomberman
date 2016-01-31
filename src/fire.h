#include "structs.h"

extern Game game;
extern Animation fireFrontAnimation, fireRightAnimation, fireBackAnimation, fireLeftAnimation, fireCenterAnimation;
extern Entity player, *self, entity[MAX_ENTITIES];

extern int getFreeEntity(void);
extern SDL_Surface *getSprite(int);
extern void drawAnimationEntity(void);
