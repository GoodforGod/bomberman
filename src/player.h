#include "structs.h"

extern Animation bombermanFront, bombermanBack, bombermanLeft, bombermanRight, bombermanDead;
extern Entity player;
extern Control input;

extern void doAnimation(Animation *);
extern int loadSprite(char *);
extern void drawImage(SDL_Surface *, int, int);
extern void addBomb(int, int);
extern SDL_Surface *getSprite(int);
extern void drawAnimation(Animation *, int, int);
extern void doSpeedAnimation(Animation *, int);
extern void playSound(int);
