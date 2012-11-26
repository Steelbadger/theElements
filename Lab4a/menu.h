#pragma once

#include "sprite.h"
#include "button.h"

#ifndef _WINDOWS_H_DEFINED_
#define _WINDOWS_H_DEFINED_
#include <windows.h>
#endif

class menu
{
public:
	enum MenuOption {None, NewGame, Continue, Quit};
	menu(void);
	~menu(void);
	void DisplayMenu(HDC bitmapHDC, HDC backHDC);
	void DisplaySplash(HDC bitmapHDC, HDC backHDC);
	void DisplayPaused(HDC bitmapHDC, HDC backHDC);
	void Update(int MouseX, int MouseY);
	void UpdatePaused(int MouseX, int MouseY);
	void SetMenuLocation(int xMiddle, int yMiddle);
	MenuOption ReturnButtonClicked(){return ButtonClicked;}
	void OnClick(int xClick, int yClick);
	void OnClickPaused(int xClick, int yClick);
	void ResetButtonClicked(){ButtonClicked = None;}

private:
	enum MenuState {Entry};
	MenuState menuState;
	sprite background;
	button newGame;
	button cont;
	button quit;
	sprite title;
	MenuOption ButtonClicked;
};

