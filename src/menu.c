#include "menu.h"

void drawMenu()
{
	char text_score[40];
	char text_press[40];
	char text_author[40];
	
	/* Blank the screen */
	
	SDL_FillRect(game.screen, NULL, 0);

	drawImage(getSprite(LOGO_SPRITE), 160, 80);	

	sprintf(text_score, "SCORE: %lu", game.score);

	drawString(text_score, 500, 10, game.font, 200, 0);
	
	sprintf(text_press, "PRESS SPACE TO CONTINUE.");
	
	drawString(text_press, 110, 600, game.message, 200, 0);
	
	sprintf(text_author, "Kurako Anton (2015-2016)");
	
	drawString("Kurako Anton (2015-2016)", 410, 740, game.font, 200, 0);

	/* Update the buffer */

	SDL_Flip(game.screen);
	
	/* Sleep briefly */
	
	SDL_Delay(1);
}

void initMenu()
{
	drawMenu();

	menuInput.fire = 1;

	while(menuInput.fire)
	{
	
		getMenuInput();

		SDL_Delay(1);
	}

}
