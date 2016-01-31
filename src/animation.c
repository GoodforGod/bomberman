#include "animation.h"

void loadAnimation(char *name, Animation *anim)
{
	/* Load up the data file that describes the animation */
	
	int i;
	FILE *fp = fopen(name, "rb");

	/* Lenght of the string from .dat file */
	
	char frameName[42];
	
	if (fp == NULL)
	{
		printf("Failed to load animation file %s\n", name);
		
		exit(1);
	}
	
	/* Read the frame count */
	
	fscanf(fp, "%d", &anim->frameCount);
	
	/* Allocate space for the animation */
	
	anim->frame = (SDL_Surface **)malloc(anim->frameCount * sizeof(SDL_Surface *));
	
	if (anim->frame == NULL)
	{
		printf("Ran out of memory when creating the animation for %s\n", name);
		
		exit(1);
	}
	
	/* Now load up each frame */
	
	for (i=0;i<anim->frameCount;i++)
	{
		fscanf(fp, "%s", frameName);
		
		anim->frame[i] = loadImage(frameName);
		
		if (anim->frame[i] == NULL)
		{
			printf("Failed to load animation frame %s\n", frameName);
			
			exit(1);
		}
	}
	
	/* Set the initial frame index to 0 */
	
	anim->frameIndex = 0;
	
	/* Set the animation counter */
	
	anim->counter = ANIM_SPEED;
}

void freeAnimation(Animation *anim)
{
	int i;
	
	/* Loop through each of the frames and free it */

	if (anim->frame != NULL)
	{
		for (i=0;i<anim->frameCount;i++)
			if (anim->frame[i] != NULL)
				SDL_FreeSurface(anim->frame[i]);
		
		free(anim->frame);
	}
}

/* The same as doAnimation, but can draw with the specific speed, to not use more extern variables */

void doSpeedAnimation(Animation *anim, int animSpeed)
{
	anim->counter--;
	
	if (anim->counter <= 0)
	{
		anim->frameIndex++;
		
		if (anim->frameIndex == anim->frameCount)
			anim->frameIndex = 0;
		
		anim->counter = animSpeed;
	}
}

/* The same as doSpeedAnimation, but draw animation based on extern variable only */

void doAnimation(Animation *anim)
{
	anim->counter--;
	
	if (anim->counter <= 0)
	{
		anim->frameIndex++;
		
		if (anim->frameIndex == anim->frameCount)
			anim->frameIndex = 0;
		
		anim->counter = ANIM_SPEED;
	}
}

/* Load all animation, used in game */

void loadAllAnimation()
{	
	char dest_enemy_up[40], dest_enemy_down[40], dest_enemy_left[40], dest_enemy_right[40], dest_bomb[40];

	sprintf(dest_enemy_up, "data/enemy_%d_up.dat", enemy_type);
	sprintf(dest_enemy_left, "data/enemy_%d_left.dat", enemy_type);
	sprintf(dest_enemy_right, "data/enemy_%d_right.dat", enemy_type);
	sprintf(dest_enemy_down, "data/enemy_%d_down.dat", enemy_type);
	sprintf(dest_bomb, "data/bomb_%d.dat", rand() % 5);

	loadAnimation("data/bomberman_front.dat", &bombermanFront);
	loadAnimation("data/bomberman_back.dat", &bombermanBack);
	loadAnimation("data/bomberman_left.dat", &bombermanLeft);
	loadAnimation("data/bomberman_right.dat", &bombermanRight);
	loadAnimation("data/bomberman_dead.dat", &bombermanDead);
	loadAnimation("data/bomberman_cool.dat", &bombermanCool);
	loadAnimation(dest_enemy_up, &enemyUp);
	loadAnimation(dest_enemy_down, &enemyDown);
	loadAnimation(dest_enemy_left, &enemyLeft);
	loadAnimation(dest_enemy_right, &enemyRight);
	loadAnimation(dest_bomb, &bombAnimation);
	loadAnimation("data/fire_center.dat", &fireCenterAnimation);
	loadAnimation("data/fire_front.dat", &fireFrontAnimation);
	loadAnimation("data/fire_left.dat", &fireLeftAnimation);
	loadAnimation("data/fire_right.dat", &fireRightAnimation);
	loadAnimation("data/fire_back.dat", &fireBackAnimation);
	loadAnimation("data/wall_dead.dat", &wallAnimation);
}

void drawAnimation(Animation *anim, int x, int y)
{
	drawImage(anim->frame[anim->frameIndex], x, y);
}
