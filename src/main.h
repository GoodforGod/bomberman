#include "structs.h"
#include <time.h>

int enemy_type;

Game game;
Control input, menuInput;
Entity player, *self, entity[MAX_ENTITIES];
Sprite sprite[MAX_SPRITES];
Sound sound[MAX_SOUNDS];
Animation wallAnimation, fireFrontAnimation, fireRightAnimation, fireBackAnimation, fireLeftAnimation, fireCenterAnimation, bombermanFront, bombermanBack, bombermanLeft, bombermanRight, bombermanDead, bombermanCool, enemyUp, enemyDown, enemyLeft, enemyRight, bombAnimation;

extern void initMenu(void);
extern void checkGameEnemy(void);
extern void init(char *);
extern void cleanup(void);
extern void getInput(void);
extern void draw(void);
extern void initPlayer(void);
extern void doPlayer(void);
extern void doEntities(void);
extern void loadAllSprites(void);
extern void loadAllSounds(void);
extern void addEnemy(int, int);
extern void doCollisions(void);
extern void delay(unsigned int);
extern void drawLevel(void);
extern int initLevel(void);
extern void addBrick(int, int);
extern void addWall(int, int);
extern void loadAllAnimation(void);
extern void doAnimation(Animation *);
extern void fillLevel(void);
extern TTF_Font *loadFont(char *, int);
extern void playSoundTimes(int, int);
extern void playSound(int);
