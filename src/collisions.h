#include "structs.h"

extern Entity entity[MAX_ENTITIES];
extern Entity player;
extern Control input;
extern Game game;
extern Animation bombermanCool;
extern Entity *self;

extern void playSound(int);
extern void checkAiCollision(int, int, int);
