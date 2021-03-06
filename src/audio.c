#include "audio.h"

void loadSound(int index, char *name)
{
	/* Load the sound specified by the filename */
	
	if (index < 0 || index >= MAX_SOUNDS)
	{
		printf("Invalid index for sound! Index: %d Maximum: %d\n", index, MAX_SOUNDS);
		
		exit(1);
	}
	
	sound[index].effect = Mix_LoadWAV(name);

	if (sound[index].effect == NULL)
	{
		printf("Failed to load sound %s\n", name);
		
		exit(1);
	}
}

void playSound(index)
{
	/* Play the sound on the first free channel and only play it once */
	
	if (index < 0 || index >= MAX_SOUNDS)
	{
		printf("Invalid index for sound! Index: %d Maximum: %d\n", index, MAX_SOUNDS);
		
		exit(1);
	}
	
	Mix_PlayChannel(-1, sound[index].effect, 0);
}

void playSoundTimes(int index, int repeatTimes)
{
	/* Play the sound on the first free channel and only play it once */
	
	if (index < 0 || index >= MAX_SOUNDS)
	{
		printf("Invalid index for sound! Index: %d Maximum: %d\n", index, MAX_SOUNDS);
		
		exit(1);
	}
	
	Mix_PlayChannel(-1, sound[index].effect, repeatTimes);
}

/* Load all sound used in game */

void loadAllSounds()
{
	loadSound(BOMB_SOUND, "sound/bomb_small_explode.ogg");
	loadSound(DEAD_SOUND, "sound/player_gameover.ogg");
	loadSound(PLAYER_WALK_SOUND, "sound/player_walk.ogg");
	loadSound(ENEMY_JUMP_SOUND, "sound/enemy_jump.ogg");
	loadSound(BACKGROUND_NORMAL_SOUND, "sound/game_background.ogg");
	loadSound(PLAYER_START_SOUND, "sound/player_start.ogg");
	loadSound(BOMB_PLACE_SOUND, "sound/bomb_place.ogg");
	loadSound(BONUS, "sound/player_special.ogg");
}

/* Free all sound after close application */

void freeSounds()
{
	int i;
	
	for (i=0;i<MAX_SOUNDS;i++)
	{
		if (sound[i].effect != NULL)
		{
			Mix_FreeChunk(sound[i].effect);
		}
	}
}
