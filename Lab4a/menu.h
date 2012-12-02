#pragma once

#include "sprite.h"
#include "button.h"
#include <windows.h>

class menu
{
public:
	enum MenuOption {None, NewGame, Guide, GuideContinue, Continue, Quit};
	menu(void);
	~menu(void);
	void DisplayMenu(HDC bitmapHDC, HDC backHDC);
	void DisplaySplash(HDC bitmapHDC, HDC backHDC);
	void DisplayPaused(HDC bitmapHDC, HDC backHDC);
	void DisplayGuide(HDC bitmapHDC, HDC backHDC);
	void Update(int MouseX, int MouseY);
	void UpdatePaused(int MouseX, int MouseY);
	void UpdateGuide(int MouseX, int MouseY);
	void SetMenuLocation(int xMiddle, int yMiddle);
	MenuOption ReturnButtonClicked(){return ButtonClicked;}
	void OnClick(int xClick, int yClick);
	void OnClickPaused(int xClick, int yClick);
	void OnClickGuide(int xClic, int yClick);
	void ResetButtonClicked(){ButtonClicked = None;}

private:
	enum MenuState {Entry};
	MenuState menuState;
	sprite background;
	button newGame;
	button cont;
	button quit;
	button guideCont;
	button guideB;
	sprite guide;
	sprite title;
	MenuOption ButtonClicked;
};

