#include "menu.h"

#ifndef _WINDOWS_H_DEFINED_
#define _WINDOWS_H_DEFINED_
#include <windows.h>
#endif


menu::menu(void):
	background("BG.bmp"),
	newGame("NewGame.bmp"),
	quit("Quit.bmp"),
	title("SplashTitle.bmp"),
	ButtonClicked(None)
{
}


menu::~menu(void)
{
}

void menu::DisplayMenu(HDC bitmapHDC, HDC backHDC)
{
	background.Draw(bitmapHDC, backHDC);
	newGame.Draw(bitmapHDC, backHDC);
	quit.Draw(bitmapHDC, backHDC);
}

void menu::DisplaySplash(HDC bitmapHDC, HDC backHDC)
{
	background.Draw(bitmapHDC, backHDC);
	title.Draw(bitmapHDC, backHDC);
}

void menu::SetMenuLocation(int x, int y)
{
	newGame.SetLocation(x-60, y-40);
	quit.SetLocation(x-60, y+40);
	title.SetLocation(x-150, y-100);
}

void menu::Update()
{
	if (newGame.IsSelected())
		ButtonClicked = NewGame;
	if (quit.IsSelected())
		ButtonClicked = Quit;
}

void menu::OnClick(int x, int y)
{
	if (newGame.OnClick(x, y))
	{
		ButtonClicked = NewGame;
	}
	if (quit.OnClick(x, y))
	{
		ButtonClicked = Quit;
	}
}