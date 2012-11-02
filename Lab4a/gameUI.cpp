#include "gameUI.h"


gameUI::gameUI(int w, int h):
	bottomMenu("UIBottom.bmp")
{
	width = w;
	height = h;
	bottomMenu.SetLocation((w-bottomMenu.GetWidth())/2, h - 20);
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
	if (bottomMenu.MouseOver(mouseX, mouseY)){
		if (bottomMenu.GetY() > (height - 100)){
			bottomMenu.Move(sprite::UP);
		}
	} else if (bottomMenu.GetY() < (height - 20)){
		bottomMenu.Move(sprite::DOWN);
	}
		
}
void gameUI::SetDisplaySize(int w, int h)
{
	width = w;
	height = h;
	bottomMenu.SetLocation((w-bottomMenu.GetWidth())/2, h - 20);
}