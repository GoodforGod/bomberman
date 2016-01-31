#include "structs.h"

extern Control input;
extern Animation bombermanFront, bombermanBack, bombermanLeft, bombermanRight, bombermanDead, bombermanCool;
extern Entity player;
Game game;

extern void drawPlayer(void);
extern void drawEntities(void);
extern void drawLevel(void);
extern void drawAnimation(Animation *, int, int);
extern void drawString(char *, int, int, TTF_Font *, int, int);
extern void doSpeedAnimation(Animation *, int);
