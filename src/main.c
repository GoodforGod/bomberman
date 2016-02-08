#include "main.h"

/* All in one place... Main CYCLE! Thats it! */

int main(int argc, char *argv[])
{
	unsigned int frameLimit = SDL_GetTicks() + 16;
	int go, terr;
	unsigned long timer, playerDeadTimer = 0;
	
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
	game.message = loadFont("font/MunroNarrow.ttf", 96);
	
	/* Intialise the player and terrain */
	
	initPlayer();
	
	terr = initLevel();
	
	if(terr == 1)
		exit(0);

	/* Fill the level with enemies and other stuff */

	fillLevel();

	/* Start up with menu */
	
	initMenu();

	/* Plays background music */

	playSoundTimes(BACKGROUND_NORMAL_SOUND, -1);

	/* Play start sound */

	playSound(PLAYER_START_SOUND);

	/* Start up game timer */
	
	timer = SDL_GetTicks();

	/* Loop indefinitely for messages */
	
	while (go == 1)
	{
		/* Get the input */
		
		getInput(); 
		
		/* if player dead, stop a lot of main functions in 4 seconds, cause not nessesery any more */
		
		if(player.active == 0 && playerDeadTimer == 0)
			playerDeadTimer = SDL_GetTicks();
		if(playerDeadTimer == 0 || SDL_GetTicks() - playerDeadTimer < 4000)
		{
			/* Update the player's position and animation frames */
		
			doPlayer();
		
			/* Update the entities */
		
			doEntities(); 
		
			/* Do the collisions */
		
			doCollisions();
		
			/* Draw everything */
		
			draw(); 

			/* Check if all enemies dead, then spawn next wave */

			checkGameEnemy();

			/* Update dame timer */

			game.timer = (SDL_GetTicks() - timer) / 1000;
		}
	
		/* Sleep briefly to stop sucking up all the CPU time */
		
		delay(frameLimit);
		
		frameLimit = SDL_GetTicks() + 16;
	}
	
	/* Exit the program */
	
	exit(0);
}
