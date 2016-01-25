#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"

#define SCREEN_WIDTH 1014 
#define SCREEN_HEIGHT 762 

#define MAX_ENTITIES 60
#define MAX_RELOAD_TIME 25

#define PLAYER_SPEED 3 
#define BOMB_SPEED 8 

#define ANIM_SPEED 7 

enum
{
	PLAYER_SPRITE,
	PLAYER_DEAD_SPRITE,
	WALL_IDLE_SPRITE,
	BRICK_IDLE_SPRITE,
 	BOMB_SPRITE,
  	ENEMY_BLUE_IDLE_SPRITE,
	TERRAIN_SPRITE,
	FIRE_SPRITE,
	BONUS_AMMO_SPRITE,
	MAX_SPRITES
};

enum
{
	BOMB_SOUND,
	DEAD_SOUND,
	PLAYER_WALK_SOUND,
	PLAYER_START_SOUND,
	ENEMY_JUMP_SOUND,
	BACKGROUND_NORMAL_SOUND,
 	MAX_SOUNDS
};

enum
{
	TYPE_BONUS_AMMO,
	TYPE_BOMB,
 	TYPE_ENEMY,
	TYPE_WALL,
	TYPE_BRICK,
	TYPE_FIRE_FRONT,
	TYPE_FIRE_RIGHT,
	TYPE_FIRE_BACK,
	TYPE_FIRE_LEFT,
	TYPE_FIRE_CENTER
};
