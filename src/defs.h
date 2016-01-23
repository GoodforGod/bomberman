#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"

#define SCREEN_WIDTH 960 
#define SCREEN_HEIGHT 640 

#define MAX_ENTITIES 50
#define MAX_RELOAD_TIME 25

#define PLAYER_SPEED 3 
#define BOMB_SPEED 8 

#define ANIM_SPEED 7 

enum
{
	PLAYER_SPRITE,
	PLAYER_DEAD_SPRITE,
	PLAYER_RIGHT_SPRITE,
	PLAYER_LEFT_SPRITE,
	PLAYER_BACK_SPRITE,
	WALL_IDLE_SPRITE,
	BRICK_IDLE_SPRITE,
 	BOMB_SPRITE,
  	ENEMY_SPRITE,
	TERRAIN_SPRITE,
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
 	TYPE_ENEMY,
	TYPE_WALL,
	TYPE_BRICK
};
