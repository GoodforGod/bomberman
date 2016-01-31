#include "structs.h"

extern Animation wallAnimation;
extern Entity *self, entity[MAX_ENTITIES];

extern int getFreeEntity(void);
extern void drawStandardEntity(void);
extern SDL_Surface *getSprite(int);
extern void drawAnimationEntity(void);
