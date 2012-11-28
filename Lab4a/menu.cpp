#include "menu.h"

#ifndef _WINDOWS_H_DEFINED_
#define _WINDOWS_H_DEFINED_
#include <windows.h>
#endif


menu::menu(void):
	background("BG.bmp"),
	newGame("button1.bmp", "button2.bmp", "newgame1.bmp"),
	cont("button1.bmp", "button2.bmp", "continue.bmp"),
	quit("button1.bmp", "button2.bmp", "quit1.bmp"),
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

void menu::DisplayPaused(HDC bitmapHDC, HDC backHDC)
{
	background.Draw(bitmapHDC, backHDC);
	cont.Draw(bitmapHDC, backHDC);
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
	cont.SetLocation(x-60, y-40);
	quit.SetLocation(x-60, y+40);
	title.SetLocation(x-150, y-100);
}

void menu::Update(int MouseX, int MouseY)
{
	newGame.Update(MouseX, MouseY);
	quit.Update(MouseX, MouseY);
}

void menu::UpdatePaused(int MouseX, int MouseY)
{
	cont.Update(MouseX, MouseY);
	quit.Update(MouseX, MouseY);
}

void menu::OnClick(int x, int y)
{
	if (newGame.OnClick(x, y)) {
		ButtonClicked = NewGame;
	}
	if (quit.OnClick(x, y)) {
		ButtonClicked = Quit;
	}
}

void menu::OnClickPaused(int x, int y)
{
	if (quit.OnClick(x, y)) {
		ButtonClicked = Quit;
	}
	
	if (cont.OnClick(x, y)) {
		ButtonClicked = Continue;
	}
}