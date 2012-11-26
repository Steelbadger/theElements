#pragma once
#include "sprite.h"

class periodicTable
{
public:
	periodicTable(void);
	~periodicTable(void);

	void InitPositions();
	void Move(float deltaX, float deltaY) {xBase+=deltaX; yBase+=deltaY;}

	void Draw(HDC bitmapHDC, HDC backHDC);
	float GetX(){return xBase;}
	float GetY(){return yBase;}
	float GetWidth(){return width;}
	float GetHeight(){return height;}

private:
	HBITMAP lockedTable;
	HBITMAP unlockedTable;

	float xBase, yBase, width, height;

	bool unlocked[118];
	int positions[118][2];
};

