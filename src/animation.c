#include "animation.h"

extern SDL_Surface *loadImage(char *);
extern void drawImage(SDL_Surface *, int, int);

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
		{
			if (anim->frame[i] != NULL)
			{
				SDL_FreeSurface(anim->frame[i]);
			}
		}
		
		free(anim->frame);
	}
}

void doAnimation(Animation *anim)
{
	anim->counter--;
	
	if (anim->counter <= 0)
	{
		anim->frameIndex++;
		
		if (anim->frameIndex == anim->frameCount)
		{
			anim->frameIndex = 0;
		}
		
		anim->counter = ANIM_SPEED;
	}
}

void loadAllAnimation()
{
	loadAnimation("data/bomberman_front.dat", &bombermanFront);
	loadAnimation("data/bomberman_back.dat", &bombermanBack);
	loadAnimation("data/bomberman_left.dat", &bombermanLeft);
	loadAnimation("data/bomberman_right.dat", &bombermanRight);
	loadAnimation("data/bomberman_dead.dat", &bombermanDead);
}

void drawAnimation(Animation *anim, int x, int y)
{
	drawImage(anim->frame[anim->frameIndex], x, y);
}
