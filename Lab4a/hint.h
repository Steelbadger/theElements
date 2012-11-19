#pragma once
#include <string>
#include <windows.h>

class hint
{
public:
	hint(void);
	~hint(void);
	void SetRectangle(int x, int y, int width, int height);
	void SetTitleString(std::string Title);
	void SetBodyString(std::string Body);

	void OnPaint(HDC backHDC, HWND hwnd);
	void Draw(HDC bitmapHDC, HDC backHDC);

private:
	PAINTSTRUCT paintstruct;
	std::string title;
	std::string body;
	RECT rectangle;
	HBITMAP border;

};

