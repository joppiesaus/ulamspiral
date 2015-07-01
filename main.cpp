#include "MainGame.h"

#ifdef _WIN32
#undef main
#endif

int main(int argc, char *argv[])
{
	MainGame game;
	game.run();

	return 0;
}

// STUPID, STUPID COMPILER!
/*#ifdef _WIN32
#undef main
#endif*/
