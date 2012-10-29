#pragma once
#ifndef _SPRITE_DEFINED_
#define _SPRITE_DEFINED_
#include "sprite.h"
#endif

#ifndef _WINDOWS_H_DEFINED_
#define _WINDOWS_H_DEFINED_
#include <windows.h>
#endif

class gameUI
{
public:
	gameUI(int width, int height);
	~gameUI(void);
	void Update(int mouseX, int mouseY);
	void Display(HDC bitmapHDC, HDC backHDC);
	void SetMouseLoc(int x, int y){mouseX = x; mouseY = y;}
	void SetDisplaySize(int w, int h) {width = w; height = h;}

private:
	int width, height;
	int offset;
	int mouseX, mouseY;
	sprite bottomMenu;
	bool bottomMenuLock;

};

