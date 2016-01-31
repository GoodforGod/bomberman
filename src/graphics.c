#include "graphics.h"

SDL_Surface *loadImage(char *name)
{
	/* Load the image using SDL Image */
	
	SDL_Surface *temp = IMG_Load(name);
	SDL_Surface *image;
	
	if (temp == NULL)
	{
		printf("Failed to load image %s\n", name);
		
		return NULL;
	}
	
	/* Make the background transparent */
	
	SDL_SetColorKey(temp, (SDL_SRCCOLORKEY|SDL_RLEACCEL), SDL_MapRGB(temp->format, 31, 139, 0));
	
	/* Convert the image to the screen's native format */
	
	image = SDL_DisplayFormat(temp);
	
	SDL_FreeSurface(temp);
	
	if (image == NULL)
	{
		printf("Failed to convert image %s to native format\n", name);
		
		return NULL;
	}
	
	/* Return the processed image */
	
	return image;
}

void drawImage(SDL_Surface *image, int x, int y)
{
	SDL_Rect dest;
	
	/* Set the blitting rectangle to the size of the src image */
	
	dest.x = x;
	dest.y = y;
	dest.w = image->w;
	dest.h = image->h;
	
	/* Blit the entire image onto the screen at coordinates x and y */
	
	SDL_BlitSurface(image, NULL, game.screen, &dest);
}

void loadSprite(int index, char *name)
{
	/* Load the image into the next slot in the sprite bank */
	
	if (index >= MAX_SPRITES || index < 0)
	{
		printf("Invalid index for sprite! Index: %d Maximum: %d\n", index, MAX_SPRITES);
		
		exit(1);
	}
	
	sprite[index].image = loadImage(name);
	
	if (sprite[index].image == NULL)
	{
		exit(1);
	}
}

SDL_Surface *getSprite(int index)
{
	if (index >= MAX_SPRITES || index < 0)
	{
		printf("Invalid index for sprite! Index: %d Maximum: %d\n", index, MAX_SPRITES);
		
		exit(1);
	}
	
	return sprite[index].image;
}

void freeSprites()
{
	int i;
	
	/* Loop through the sprite bank and clear the images */
	
	for (i=0;i<MAX_SPRITES;i++)
	{
		if (sprite[i].image != NULL)
		{
			SDL_FreeSurface(sprite[i].image);
		}
	}
}

/* Again, load all sprites, not only to render, but for collision, for collision, BUDDY! */

void loadAllSprites()
{
	char dest_brick[40], dest_terrain[40], dest_bonus[40], dest_enemy[40];
	sprintf(dest_brick, "gfx/brick/brick_idle_%d.png", rand() % 24);
	sprintf(dest_terrain, "gfx/terrain/terrain_%d.png", rand() % 7);
	sprintf(dest_bonus, "gfx/bonus_ammo_%d.png", rand() % 2);
	sprintf(dest_enemy, "gfx/enemy/enemy_%d_down_1.png", enemy_type);
	
	loadSprite(PLAYER_SPRITE, "gfx/bomberman_idle.png");
	loadSprite(BOMB_SPRITE, "gfx/bomb/bomb_1_idle_1.png");
	loadSprite(ENEMY_IDLE_SPRITE, dest_enemy);
	loadSprite(TERRAIN_SPRITE, dest_terrain);
	loadSprite(PLAYER_DEAD_SPRITE, "gfx/bomberman_grave.png");
	loadSprite(WALL_IDLE_SPRITE, "gfx/wall/wall_idle.png");
	loadSprite(BRICK_IDLE_SPRITE, dest_brick);
	loadSprite(FIRE_SPRITE, "gfx/fire_collision.png");
	loadSprite(BONUS_AMMO_SPRITE, dest_bonus);
}
