#include "structs.h"

extern Game game;
extern Animation bombAnimation;
extern Entity player, *self, entity[MAX_ENTITIES];

extern int getFreeEntity(void);
extern SDL_Surface *getSprite(int);
extern void playSound(int);
extern void drawAnimationEntity(void);
extern void addFire(int, int, int);
extern int collision(int, int, int, int, int, int, int, int);
