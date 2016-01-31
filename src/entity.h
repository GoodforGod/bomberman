#include "structs.h"

extern Animation wallAnimation, enemyLeft, enemyRight, enemyUp, enemyDown, bombAnimation, fireFrontAnimation, fireRightAnimation, fireBackAnimation, fireLeftAnimation, fireCenterAnimation;
extern Entity *self, entity[MAX_ENTITIES];

extern void drawImage(SDL_Surface *, int, int);
extern void drawAnimation(Animation *, int, int);
extern void doSpeedAnimation(Animation *, int);
