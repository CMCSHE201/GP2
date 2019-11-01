#include "ScreenDisplay.h"


ScreenDisplay::ScreenDisplay()
{
	windowPointer = nullptr;
	widthOfScreen = 1024;
	heightOfScreen = 768;
}

ScreenDisplay::~ScreenDisplay()
{

}

void ScreenDisplay::errorMessage(std::string errorInfo)
{
	std::cout << errorInfo << std::endl;
	std::cout << "press any  key to quit...";
	int en;
	std::cin >> en;
	SDL_Quit();
}

void ScreenDisplay::transferBuffer()
{
	SDL_GL_SwapWindow(windowPointer);
}

void ScreenDisplay::intialisedDisplay()
{
	SDL_Init(SDL_INIT_EVERYTHING); //initalise everything

	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8); //Min no of bits used to diplay colour
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1); // set up double buffer   

	windowPointer = SDL_CreateWindow("Game Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, widthOfScreen, heightOfScreen, SDL_WINDOW_OPENGL); // create window

	if (windowPointer == nullptr)
	{
		errorMessage("window failed to create");
	}

	SDL_GLContext glContext = SDL_GL_CreateContext(windowPointer);

	if (glContext == nullptr)
	{
		errorMessage("SDL_GL context failed to create");
	}

	GLenum error = glewInit();
	if (error != GLEW_OK)
	{
		errorMessage("GLEW failed to initialise");
	}

	glClearColor(0.0f, 1.0f, 1.0f, 1.0f);
}

