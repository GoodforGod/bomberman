#include "structs.h"

Game game;
Control input;
Entity player, *self, entity[MAX_ENTITIES];
Sprite sprite[MAX_SPRITES];
Sound sound[MAX_SOUNDS];
Animation wallAnimation, fireFrontAnimation, fireRightAnimation, fireBackAnimation, fireLeftAnimation, fireCenterAnimation, bombermanFront, bombermanBack, bombermanLeft, bombermanRight, bombermanDead, bombermanCool, enemyBlueLeft, enemyBlueRight, bombAnimation;
