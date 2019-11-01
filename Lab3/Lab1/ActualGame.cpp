#include "ActualGame.h"
#include <iostream>
#include <string>

ActualGame::ActualGame()
{
	_stateOfGame = StateOfGame::START;
	ScreenDisplay* displayOfGame = new ScreenDisplay();
}

ActualGame::~ActualGame()
{
}

void ActualGame::play()
{
	InitialisedSystems();
	GameRepeat();
}

void ActualGame::InitialisedSystems()
{
	displayOfGame.intialisedDisplay();
}

void ActualGame::GameRepeat()
{
	while (_stateOfGame != StateOfGame::FINISH)
	{
		workInput();
		createGame();
	}
}

void ActualGame::workInput()
{
	SDL_Event events;

	while (SDL_PollEvent(&events)) //get and process events
	{
		switch (events.type)
		{
		case SDL_QUIT:
			_stateOfGame = StateOfGame::FINISH;
			break;
		}
	}
}

void ActualGame::createGame()
{
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// old code for testing only 
	glEnableClientState(GL_COLOR_ARRAY);
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(0, 0);
	glVertex2f(0, 500);
	glVertex2f(500, 500);
	glEnd();

	displayOfGame.transferBuffer();
}

