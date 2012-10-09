#include "drawEngine.h"
#include <windows.h>
#include <iostream>

using namespace std;


DrawEngine::DrawEngine(int xSize, int ySize)
{
	screenWidth = xSize;
	screenHeight = ySize;

	//set cursor visiability to false

	cursorVisibility(false);

}

DrawEngine::~DrawEngine()
{
	// set cursor visiability to true
	cursorVisibility(true);
}

int DrawEngine::createSprite(int index, char c)
{
	if ( index >= 0 && index < 16)
	{

	spriteImage[index] = c;
	return index;

	}
	return -1;

}
void DrawEngine::deleteSprite(int index)
{
	// 
}

void DrawEngine::drawSprite(int index, int posx, int posy)
{
	
	// go to the current location
	gotoxy(posx, posy);
	//draw the sprite with cout
	cout << spriteImage[index];
	
	


}
void DrawEngine::eraseSprite(int posx, int posy)
{
	gotoxy(posx, posy);
	cout << ' ';
}


void DrawEngine::gotoxy(int x, int y)
{
	HANDLE output_handle;
	COORD pos;
	
	pos.X = x;
	pos.Y = y;
	output_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	
	SetConsoleCursorPosition(output_handle, pos );
}

void DrawEngine::cursorVisibility(bool visibility)
{
	HANDLE output_handle;
	CONSOLE_CURSOR_INFO cciInfo;

	cciInfo.dwSize = 1;
	cciInfo.bVisible = visibility;

	output_handle = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleCursorInfo(output_handle, & cciInfo);
}

