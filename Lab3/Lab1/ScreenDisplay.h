#pragma once
#include <SDL/SDL.h>
#include <GL\glew.h>
#include <iostream>
#include <string>
using namespace std;

class ScreenDisplay
{
public:
	ScreenDisplay();
	~ScreenDisplay();

	void intialisedDisplay();
	void transferBuffer();

private:

	void errorMessage(std::string errorInfo);

	SDL_Window* windowPointer;
	int widthOfScreen;
	int heightOfScreen;
};

