#include "main.h"

extern void init(char *);
extern void cleanup(void);
extern void getInput(void);

int main(int argc, char *argv[])
{
	init("Bomberman Init Window");
	
	atexit(cleanup);
	
	while (1)
	{
		getInput();
		
		SDL_Delay(16);
	}
	
	exit(0);
}
