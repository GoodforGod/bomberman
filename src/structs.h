#include "defs.h"

typedef struct Game
{
	SDL_Surface *screen;
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
	int active, type;
	int x, y, thinkTime;
	SDL_Surface *sprite;
	void (*action)(void);
	void (*draw)(void);
} Entity;

typedef struct Control
{
	int up, down, left, right, fire;
} Control;
