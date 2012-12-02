#include "menu.h"
#include <windows.h>


menu::menu(void):
	background("BG.bmp"),
	newGame("button1.bmp", "button2.bmp", "newgame1.bmp"),
	cont("button1.bmp", "button2.bmp", "continue.bmp"),
	quit("button1.bmp", "button2.bmp", "quit1.bmp"),
	guideCont("button1.bmp", "button2.bmp", "return.bmp"),
	guide("guide.bmp"),
	guideB("button1.bmp", "button2.bmp", "guidebutton.bmp"),
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
	guideB.Draw(bitmapHDC, backHDC);
	quit.Draw(bitmapHDC, backHDC);
}

void menu::DisplayPaused(HDC bitmapHDC, HDC backHDC)
{
	background.Draw(bitmapHDC, backHDC);
	cont.Draw(bitmapHDC, backHDC);
	quit.Draw(bitmapHDC, backHDC);
}

void menu::DisplayGuide(HDC bitmapHDC, HDC backHDC)
{
	background.Draw(bitmapHDC, backHDC);
	guide.Draw(bitmapHDC, backHDC);
	guideCont.Draw(bitmapHDC, backHDC);
}

void menu::UpdateGuide(int MouseX, int MouseY)
{
	guideCont.Update(MouseX, MouseY);
}

void menu::DisplaySplash(HDC bitmapHDC, HDC backHDC)
{
	background.Draw(bitmapHDC, backHDC);
	title.Draw(bitmapHDC, backHDC);
}

void menu::SetMenuLocation(int x, int y)
{
	newGame.SetLocation(x-60, y-120);
	guideB.SetLocation(x-60, y-40);
	cont.SetLocation(x-60, y-40);
	quit.SetLocation(x-60, y+40);
	title.SetLocation(x-150, y-100);
	guideCont.SetLocation(x+200, y-350);
}

void menu::Update(int MouseX, int MouseY)
{
	newGame.Update(MouseX, MouseY);
	guideB.Update(MouseX, MouseY);
	quit.Update(MouseX, MouseY);
}

void menu::UpdatePaused(int MouseX, int MouseY)
{
	cont.Update(MouseX, MouseY);
	quit.Update(MouseX, MouseY);
}

void menu::OnClick(int x, int y)
{
	if (guideB.OnClick(x, y)) {
		ButtonClicked = Guide;
	}
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

void menu::OnClickGuide(int x, int y)
{
	if (guideCont.OnClick(x, y)) {
		ButtonClicked = GuideContinue;
	}

}