#include "gameUI.h"


gameUI::gameUI(int w, int h):
	bottomMenu("UIBottom.bmp"),
		bottomMenuLock(false)
{
	width = w;
	height = h;
	bottomMenu.SetLocation((w-bottomMenu.GetWidth())/2, h - 60);
}


gameUI::~gameUI(void)
{
}

void gameUI::Display(HDC bitmapHDC, HDC backHDC)
{
	bottomMenu.Draw(bitmapHDC, backHDC);
}

void gameUI::Update(int x, int y)
{
	SetMouseLoc(x, y);
	if (mouseY > (height-60) && bottomMenu.GetY() > (height - 120) && !bottomMenuLock)
	{
		bottomMenu.Move(sprite::UP);
	} else if (bottomMenu.GetY() < (height - 60) && !(bottomMenu.GetY() > (height - 60)) && !bottomMenuLock)
	{
		bottomMenu.Move(sprite::DOWN);
	}

	if (bottomMenu.GetY() == (height - 120) && mouseY < (height - 120))
		bottomMenuLock = true;
	else
		bottomMenuLock = false;
		
}