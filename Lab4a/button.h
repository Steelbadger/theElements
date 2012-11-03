#pragma once
#include "sprite.h"

class button
{
public:
	button(LPSTR szBGFileName, LPSTR szMOFileName, LPSTR szImgFileName, int x, int y);
	button(LPSTR szBGFileName, LPSTR szMOFileName, LPSTR szImgFileName);
	~button(void);
	void Update(int x, int y);
	bool OnClick(int x, int y);
	void SetLocation(int x, int y){background.SetLocation(x, y); mouseover.SetLocation(x, y); image.SetLocation(x, y);}
	void Draw(HDC bitmapHDC, HDC backHDC);
	void Move(sprite::direction dir){background.Move(dir); mouseover.Move(dir); image.Move(dir);}
	bool IsSelected() {return selected;}
private:
	sprite background;
	sprite mouseover;
	sprite image;
	bool mOver;
	bool selected;
};

