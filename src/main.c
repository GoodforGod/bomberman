#include "main.h"

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
extern void doAnimation(Animation *anim);
extern void fillLevel(void);
extern TTF_Font *loadFont(char *, int);

int main(int argc, char *argv[])
{
	unsigned int frameLimit = SDL_GetTicks() + 16;
	int go, terr;
	
	/* Start up SDL */
	
	init("Bomberman Init Window");
	
	/* Call the cleanup function when the program exits */
	
	atexit(cleanup);
	
	go = 1;
	
	/* Load all the sprites */
	
	loadAllSprites();

	/* Load all Animation */
	
	loadAllAnimation(); 

	/* Load all the sounds */
	
	loadAllSounds();
	
	/* Load fonts */

	game.font = loadFont("font/blackWolf.ttf", 16);
	
	/* Intialise the player and terrain */
	
	initPlayer();
			
	terr = initLevel();
	
	if(terr == 1)
		exit(0);

	/* Fill the level with enemies and other stuff */

	fillLevel();
	
	/* Loop indefinitely for messages */
	
	while (go == 1)
	{
		/* Get the input */
		
		getInput(); 
		
		/* Update the player's position */
		
		doPlayer();
		
		/* Update animation frames */

		doAnimation(&bombermanBack);
		doAnimation(&bombermanFront);
		doAnimation(&bombermanLeft);
		doAnimation(&bombermanRight);
		doAnimation(&bombermanDead);

		/* Update the entities */
		
		doEntities(); 
		
		/* Do the collisions */
		
		doCollisions();
		
		/* Draw everything */
		
		draw(); 
	
		/* Sleep briefly to stop sucking up all the CPU time */
		
		delay(frameLimit);
		
		frameLimit = SDL_GetTicks() + 16;
	}
	
	/* Exit the program */
	
	exit(0);
}
