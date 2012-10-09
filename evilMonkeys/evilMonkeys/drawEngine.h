#ifndef DRAWENGINE_H
#define DRAWENGINE_H

class DrawEngine
{
public:
	DrawEngine ( int xSize = 30, int ySize = 20);
	~DrawEngine();

	int createSprite(int index, char c);
	void deleteSprite(int index);

	void eraseSprite(int posx, int posy);
	void drawSprite(int index, int pos, int posy);

protected:
	int screenWidth, screenHeight;
	char spriteImage[16];

private:
	void gotoxy(int x, int y);
	void cursorVisibility(bool visibility);

};

#endif