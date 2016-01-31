#include "main.h"

/* All in one place... Main CYCLE! Thats it! */

int main(int argc, char *argv[])
{
	unsigned int frameLimit = SDL_GetTicks() + 16;
	int go, terr;
	unsigned long timer;
	
	/* Make rand based on time */
	
	srand( (unsigned)time( NULL ) );
	
	enemy_type = rand() % 10;
	
	/* Start up SDL */
	
	init("(☞ﾟヮﾟ)☞  Bomberman  ☜(ﾟヮﾟ☜)           (ಠ_ರ)");
	
	/* Call the cleanup function when the program exits */
	
	atexit(cleanup);
	
	go = 1;
	
	/* Load all Animation */

	loadAllAnimation(); 
	
	/* Load all the sprites */
	
	loadAllSprites();

	/* Load all the sounds */
	
	loadAllSounds();
	
	/* Load fonts */

	game.font = loadFont("font/MunroNarrow.ttf", 24);
	game.message = loadFont("font/MunroNarrow.ttf", 76);
	
	/* Intialise the player and terrain */
	
	initPlayer();
	
	terr = initLevel();
	
	if(terr == 1)
		exit(0);

	/* Play start sound */

	playSound(PLAYER_START_SOUND);

	/* Fill the level with enemies and other stuff */

	fillLevel();
	
	/* Plays background music */

	playSoundTimes(BACKGROUND_NORMAL_SOUND, -1);

	/* Loop indefinitely for messages */
	
	timer = SDL_GetTicks();

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

		/* Update the entities */
		
		doEntities(); 
		
		/* Do the collisions */
		
		doCollisions();
		
		/* Draw everything */
		
		draw(); 

		checkGameEnemy();

		/* Sleep briefly to stop sucking up all the CPU time */
		
		game.timer = (SDL_GetTicks() - timer) / 1000;

		delay(frameLimit);
		
		frameLimit = SDL_GetTicks() + 16;
	}
	
	/* Exit the program */
	
	exit(0);
}
