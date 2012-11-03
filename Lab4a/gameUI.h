#pragma once
#ifndef _SPRITE_DEFINED_
#define _SPRITE_DEFINED_
#include "sprite.h"
#endif
#include "button.h"
#include "particle.h"

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
	void SetDisplaySize(int w, int h);
	particle::type ReturnParticleCreation();

private:
	int width, height;
	int offset;
	int mouseX, mouseY;
	sprite bottomMenu;
	button upQuark;
	button downQuark;
	button topQuark;
	button bottomQuark;
	button charmQuark;
	button strangeQuark;
	button gluon;
};

