#ifndef _SPRITE_H_INCLUDED_
#define _SPRITE_H_INCLUDED_

#ifndef _WINDOWS_H_DEFINED_
#define _WINDOWS_H_DEFINED_
#include <windows.h>
#endif


class sprite
{
public:
	enum direction {UP, DOWN, LEFT, RIGHT};
	sprite();
	sprite(LPSTR szFileName);
	sprite(LPSTR szFileName, int x, int y);
	sprite(LPSTR szFileName, LPSTR szMaskName, int x, int y);
	void SetSprite(LPSTR szFileName);
	~sprite(void);
	void Draw(HDC bitmapHDC, HDC backHDC);
	void Draw(HDC bitmapHDC, HDC bacHDC, float scalefactor);
	void DrawFade(HDC bitmapHDC, HDC bacHDC, int frame);
	void Move(direction dir);
	void Move(float deltaX, float deltaY) {x+=deltaX; y+=deltaY;}
	void SetLocation(int xpos, int ypos) {x = xpos; y = ypos;}
	void SetSelected(bool s);
	bool IsSelected(){return currentSelection;}
	bool OnClick(int xClick, int yClick);
	void OnRelease();
	bool MouseOver(int xMouse, int yMouse);
	int GetWidth() {return w;}
	int GetHeight() {return h;}
	float GetX() {return x;}
	float GetY() {return y;}
	void SetAnimated(){frame = 0;}

	void ScaleDraw(float ScalingFactor, HDC bitmapHDC, HDC backHDC);
private:
	float x, y;
	int w, h;
	HBITMAP bitmap;
	HBITMAP transparencyMask;
	HBITMAP CreateBitmapMask(HBITMAP hbmColour, COLORREF crTransparent);
	bool selected;
	bool currentSelection;
	int frame;
};

#endif

