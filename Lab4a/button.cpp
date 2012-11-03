#include "button.h"


button::button(LPSTR szBGFileName, LPSTR szMOFileName, LPSTR szImgFileName, int x, int y):
	background(szBGFileName, x, y),
	mouseover(szMOFileName, x, y),
	image(szImgFileName, x, y)
{
}

button::button(LPSTR szBGFileName, LPSTR szMOFileName, LPSTR szImgFileName):
	background(szBGFileName),
	mouseover(szMOFileName),
	image(szImgFileName),
	mOver(false)
{
}


button::~button(void)
{
}

void button::Update(int x, int y)
{
	if (background.MouseOver(x, y) || mouseover.MouseOver(x, y))
		mOver = true;
	else
		mOver = false;
}

bool button::OnClick(int x, int y)
{
	if (background.OnClick(x, y) || mouseover.OnClick(x, y)){
		selected = true;
		return (true);
	} else {
		selected = false;
		return (false);
	}
}

void button::Draw(HDC bitmapHDC, HDC backHDC)
{
	if(mOver)
		mouseover.Draw(bitmapHDC, backHDC);
	else
		background.Draw(bitmapHDC, backHDC);

	image.Draw(bitmapHDC, backHDC);
}