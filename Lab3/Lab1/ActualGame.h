#pragma once

#include <SDL\SDL.h>
#include <GL\glew.h>
#include "ScreenDisplay.h"

enum class StateOfGame { START, FINISH };

class ActualGame
{
public:
	ActualGame();
	~ActualGame();

	void play();

private:

	void InitialisedSystems();
	void workInput();
	void GameRepeat();
	void createGame();

	ScreenDisplay displayOfGame;
	StateOfGame _stateOfGame;
};

