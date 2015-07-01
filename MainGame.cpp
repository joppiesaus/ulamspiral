#include "MainGame.h"
#include "Variables.h"
#include "Curve.h"

#ifdef _WIN32
#include <SDL/SDL.h>
#else
#include <SDL2/SDL.h>
#endif
#include <iostream>
#include <string>

void fatalError(std::string errorString)
{
	std::cout << "Fatal error(probably due to a LOLCAT):" << std::endl;
	std::cout << errorString << std::endl;
	std::cout << "\nPress any key to quit...";
	int a;
	std::cin >> a;
}

MainGame::MainGame()
{
	_window = nullptr; // muhahhahaha!
	_gameState = GameState::PLAY;
}

MainGame::~MainGame()
{

}

void MainGame::run()
{
	initSystems();

	// Generate the curve!
	std::cout << "Generating primes in a Ulam spiral, stopping at " << GRAPHLIMIT << "..." << std::endl;
	Curve curve;
	curve.generate(&_pixelList);
	std::cout << "Done!" << std::endl;
	_pixelList.build();

	gameLoop();
}

void MainGame::initSystems()
{
	// init SDL
	SDL_Init(SDL_INIT_EVERYTHING);

	_window = SDL_CreateWindow("Ulam Spiral", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_SIZE, SCREEN_SIZE, SDL_WINDOW_OPENGL);

	// holy! We've got a null window!
	if (_window == nullptr)
	{
		fatalError("NullPointerException: SDL Window could not be opened created!");
	}

	SDL_GLContext glContext = SDL_GL_CreateContext(_window);
	if (glContext == nullptr)
	{
		fatalError("NullPointerException: SDL_GL context could not be created!");
	}

	GLenum error = glewInit();
	if (error != GLEW_OK) // not okay, gimme a error!
	{
		std::string msg = "Could not initialize GLEW: ";

		// did this for fun :3
		switch (error)
		{
			case GLEW_ERROR_NO_GL_VERSION:
				msg += "No OpenGL detected!";
				break;
			case GLEW_ERROR_GL_VERSION_10_ONLY:
				msg += "At least OpenGL 1.1 is required!";
				break;
			case GLEW_ERROR_GLX_VERSION_11_ONLY:
				msg += "At least GLX 1.2 is required!";
				break;
			default:
				msg += "Unkown fatal error! Call the police!";
				break;
		}
		fatalError(msg);
	}

	// we want to doublebuffer
	// draw on one window while the other is being cleared
	// no flicker!
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	// set the color you want to clear every draw!
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // white
}

void MainGame::gameLoop()
{
	drawGame();
	while (_gameState != GameState::EXIT)
	{
		processInput();
		SDL_Delay(1); // I'm sorry, but I don't like to fry your CPU.
	}
}

void MainGame::processInput()
{
	SDL_Event evnt;

	// poll for the event(pointer to event)
	while (SDL_PollEvent(&evnt))
	{
		switch (evnt.type)
		{
			case SDL_QUIT:
				_gameState = GameState::EXIT;
				break;
		}
	}
}

void MainGame::drawGame()
{
	glClearDepth(1.0);

	// OR operator, we want both!
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// we want to be enabled, to color it!
	glEnableClientState(GL_COLOR_ARRAY);
	glColor3f(0.0f, 0.0f, 0.0f);


	_pixelList.drawAll();


	// swap the window you want to clear and you want to draw
	SDL_GL_SwapWindow(_window);
}
