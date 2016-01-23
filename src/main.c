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
	
	/* Load all the sounds */
	
	loadAllSounds();
	
	/* Intialise the player and terrain */
	
	initPlayer();
			
	terr = initLevel();
	
	if(terr == 1)
		exit(0);

	/* A a bunch of Enemies and Walls*/

	addEnemy(840, 50);
	addEnemy(840, 150);
	addEnemy(840, 250);
	addEnemy(840, 350);
	addEnemy(840, 450);
	addEnemy(740, 450);
	addBrick(0, 0);
	addBrick(64,64);
	addWall(832,512);
	addWall(896,576);
	/* Loop indefinitely for messages */
	
	while (go == 1)
	{
		/* Get the input */
		
		getInput(); 
		
		/* Update the player's position */
		
		doPlayer();
		
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
