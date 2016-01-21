#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"

#define SCREEN_WIDTH 840
#define SCREEN_HEIGHT 640 

#define MAX_ENTITIES 20
#define MAX_RELOAD_TIME 20

#define PLAYER_SPEED 3
#define BOMB_SPEED 10

enum
{
	PLAYER_SPRITE,
 	BOMB_SPRITE,
  	ENEMY_SPRITE,
	MAX_SPRITES
};

enum
{
	BOMB_SOUND,
	DEAD_SOUND,
 	MAX_SOUNDS
};

enum
{
	TYPE_BOMB,
 	TYPE_ENEMY
};
