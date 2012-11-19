#include "hint.h"


hint::hint(void)
{

}


hint::~hint(void)
{
}

void hint::SetRectangle(int x, int y, int width, int height)
{
	SetRect(&rectangle, x, y, x+width, y+height);
}

void hint::SetTitleString(std::string Title)
{

}

void hint::SetBodyString(std::string Body)
{
	body = Body;
}

void hint::OnPaint(HDC hdc, HWND hwnd)
{
	HDC textHDC = BeginPaint(hwnd, &paintstruct);
	char *buff=new char[body.size()+1];
	buff[body.size()]=0;
	memcpy(buff,body.c_str(),body.size());
	DrawText(textHDC,buff,strlen(buff), &rectangle, DT_CENTER);
	EndPaint(hwnd, &paintstruct);
	BitBlt(hdc, 0, 0, 500, 500, textHDC, 0, 0, SRCPAINT);
}

void hint::Draw(HDC bitmapHDC, HDC backHDC)
{

}
