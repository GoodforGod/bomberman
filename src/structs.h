#include "defs.h"

typedef struct Game
{
	TTF_Font *font;
	SDL_Surface *screen;
	unsigned long timer;
	unsigned int score;
} Game;

typedef struct Sprite
{
	SDL_Surface *image;
} Sprite;

typedef struct Animation
{
	int frameCount, frameIndex, counter;
	SDL_Surface **frame;
} Animation;

typedef struct Sound
{
	Mix_Chunk *effect;
} Sound;

typedef struct Entity
{
	int active, type, bomb;
	unsigned long timer;
	int x, y, thinkTime, prev_x, prev_y;
	SDL_Surface *sprite;
	void (*action)(void);
	void (*draw)(void);
} Entity;

typedef struct Control
{
	int up, down, left, right, fire;
} Control;
