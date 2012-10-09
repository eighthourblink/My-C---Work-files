#include "game.h"
#include <conio.h>
#include <iostream>
#include <windows.h>


using namespace std;

//this is goings to give us 30 fps
#define GAME_SPEED 33.33


bool Game::run(void)
{
	char key = ' ';
	
	startTime = timeGetTime();
	frameCount = 0;
	lastTime = 0;

	while (key != 'q')
	{
		while (!getInput(&key))
		{
		}

		cout << "The key you have pressed is : " << key << endl;
	}

	cout << frameCount / ((timeGetTime() - startTime) / 1000)  << " frames per second" << endl;
	cout << " Game Over" << endl;
	return true;
}

bool Game::getInput(char *c)
{
	if (kbhit())
	{
		*c = getch();
		return true;
	}

	
	return false;
}

void Game::timerUpdate(void)
{
	double currentTime = timeGetTime() - lastTime;

	if (currentTime < GAME_SPEED)
		return;
	frameCount++;

	lastTime = timeGetTime();

	
}
