#include "structs.h"

extern Game game;
extern Animation enemyLeft, enemyRight, enemyUp, enemyDown, bombAnimation, fireFrontAnimation, fireRightAnimation, fireBackAnimation, fireLeftAnimation, fireCenterAnimation, bombermanFront, bombermanBack, bombermanLeft, bombermanRight, bombermanDead, bombermanCool;

extern void freeSprites(void);
extern void freeSounds(void);
extern void freeAnimation(Animation *);
extern void closeFont(TTF_Font *);
