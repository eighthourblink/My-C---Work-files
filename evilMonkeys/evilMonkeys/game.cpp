#include "game.h"
#include <conio.h>
#include <iostream>
#include <windows.h>


using namespace std;

//this is goings to give us 30 fps
#define GAME_SPEED 33.33


bool Game::run(void)
{
	drawArea.createSprite(0, '$');
	
	
	char key = ' ';
	
	startTime = timeGetTime();
	frameCount = 0;
	lastTime = 0;

	posx = 0; 

	while (key != 'q')
	{
		while (!getInput(&key))
		{
			timerUpdate();
			
		}

		
		

		
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

	drawArea.eraseSprite(posx, 5);
	posx = (posx + 1) % 80;
	drawArea.drawSprite(0, posx, 5);

	frameCount++;

	lastTime = timeGetTime();

	
}
