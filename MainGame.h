#pragma once

#include "PixelList.h"

#include <GL/glew.h>

enum class GameState
{
	PLAY, EXIT
};

class SDL_Window;

class MainGame
{
public:
	MainGame();
	~MainGame();

	void run();
private:
	void initSystems();
	void processInput();
	void gameLoop();
	void drawGame();

	SDL_Window* _window;
	GameState _gameState;

	PixelList _pixelList;
};
