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
	enum MenuOption {None, NewGame, Quit};
	menu(void);
	~menu(void);
	void DisplayMenu(HDC bitmapHDC, HDC backHDC);
	void DisplaySplash(HDC bitmapHDC, HDC backHDC);
	void Update(int MouseX, int MouseY);
	void SetMenuLocation(int xMiddle, int yMiddle);
	MenuOption ReturnButtonClicked(){return ButtonClicked;}
	void OnClick(int xClick, int yClick);

private:
	enum MenuState {Entry};
	MenuState menuState;
	sprite background;
	button newGame;
	button quit;
	sprite title;
	MenuOption ButtonClicked;
};

