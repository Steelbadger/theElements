#include "sprite.h"
#ifndef _WINDOWS_H_DEFINED_
#define _WINDOWS_H_DEFINED_
#include <windows.h>
#endif

sprite::sprite()
{
	x = 0;
	y = 0;
}

sprite::sprite(LPSTR szFileName)
{
	BITMAP bmap;
	x = 0;
	y = 0;
	bitmap = (HBITMAP)LoadImage(NULL, szFileName, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	GetObject(bitmap,sizeof(bmap), &bmap);
	w = bmap.bmWidth;
	h = bmap.bmHeight;
	transparencyMask = CreateBitmapMask(bitmap, RGB(255,255,255));
	frame = 400;
}

sprite::sprite(LPSTR szFileName, int i, int j)
{
	BITMAP bmap;
	x = i;
	y = j;
	bitmap = (HBITMAP)LoadImage(NULL, szFileName, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	GetObject(bitmap,sizeof(bmap), &bmap);
	w = bmap.bmWidth;
	h = bmap.bmHeight;
	transparencyMask = CreateBitmapMask(bitmap, RGB(255,255,255));
	frame = 400;
}


sprite::sprite(LPSTR szFileName, LPSTR szMaskName, int i, int j)
{
	BITMAP bmap;
	x = i;
	y = j;
	bitmap = (HBITMAP)LoadImage(NULL, szFileName, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	GetObject(bitmap,sizeof(bmap), &bmap);
	w = bmap.bmWidth;
	h = bmap.bmHeight;
	transparencyMask = (HBITMAP)LoadImage(NULL, szMaskName, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	frame = 400;
}

void sprite::SetSprite(LPSTR szFileName)
{
	BITMAP bmap;
	bitmap = (HBITMAP)LoadImage(NULL, szFileName, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	GetObject(bitmap,sizeof(bmap), &bmap);
	w = bmap.bmWidth;
	h = bmap.bmHeight;
	transparencyMask = CreateBitmapMask(bitmap, RGB(255,255,255));
	frame = 400;

}

sprite::~sprite(void)
{
}

void sprite::Draw(HDC bitmapHDC, HDC backHDC)
{
	HBITMAP originalBitMap;
	originalBitMap = (HBITMAP)SelectObject(bitmapHDC,bitmap);

	if (frame < 400) {
		float i = 600.0/ (200.0 + frame);
		SelectObject(bitmapHDC, transparencyMask);
		StretchBlt(backHDC, x+((w-(w*i))/2), y+((h-(h*i))/2), w*i, h*i, bitmapHDC, 0, 0, w, h, SRCAND);
		SelectObject(bitmapHDC, bitmap);
		StretchBlt(backHDC, x+((w-(w*i))/2), y+((h-(h*i))/2), w*i, h*i, bitmapHDC, 0, 0, w, h, SRCPAINT);
		frame++;
	} else {
		SelectObject(bitmapHDC, transparencyMask);
		BitBlt(backHDC, x, y, x+w, y+h, bitmapHDC, 0, 0, SRCAND);
		SelectObject(bitmapHDC, bitmap);
		BitBlt(backHDC, x, y, x+w, y+h, bitmapHDC, 0, 0, SRCPAINT);
	}

	SelectObject(bitmapHDC,originalBitMap);
}

void sprite::Move(sprite::direction dir)
{
	switch (dir) {
		case LEFT:
			x--;
			break;
		case RIGHT:
			x++;
			break;
		case UP:
			y--;
			break;
		case DOWN:
			y++;
			break;
	}
}

void sprite::SetSelected(bool i)
{
	selected = i;
}

bool sprite::OnClick(int xClick, int yClick)
{
	if (MouseOver(xClick, yClick))
	{
		SetSelected(true);
		return true;
	} else {
		SetSelected(false);
		return false;
	}
}

void sprite::OnRelease()
{
	SetSelected(false);
}

bool sprite::MouseOver(int xMouse, int yMouse)
{
	if (xMouse > x && xMouse < (x+w) && yMouse > y && yMouse < (y+h))
	{
		return true;
	} else {
		return false;
	}

}

HBITMAP sprite::CreateBitmapMask(HBITMAP hbmColour, COLORREF crTransparent)
{
    HDC hdcMem, hdcMem2;
    HBITMAP hbmMask;
    BITMAP bm;

    // Create monochrome (1 bit) mask bitmap.  

    GetObject(hbmColour, sizeof(BITMAP), &bm);
    hbmMask = CreateBitmap(bm.bmWidth, bm.bmHeight, 1, 1, NULL);

    // Get some HDCs that are compatible with the display driver

    hdcMem = CreateCompatibleDC(0);
    hdcMem2 = CreateCompatibleDC(0);

    SelectObject(hdcMem, hbmColour);
    SelectObject(hdcMem2, hbmMask);

    // Set the background colour of the colour image to the colour
    // you want to be transparent.
    SetBkColor(hdcMem, crTransparent);

    // Copy the bits from the colour image to the B+W mask... everything
    // with the background colour ends up white while everythig else ends up
    // black...Just what we wanted.

    BitBlt(hdcMem2, 0, 0, bm.bmWidth, bm.bmHeight, hdcMem, 0, 0, SRCCOPY);

    // Take our new mask and use it to turn the transparent colour in our
    // original colour image to black so the transparency effect will
    // work right.
    BitBlt(hdcMem, 0, 0, bm.bmWidth, bm.bmHeight, hdcMem2, 0, 0, SRCINVERT);

    // Clean up.

    DeleteDC(hdcMem);
    DeleteDC(hdcMem2);

    return hbmMask;
}

void sprite::ScaleDraw(float i, HDC bitmapHDC, HDC backHDC)
{
	HBITMAP originalBitMap;
	originalBitMap = (HBITMAP)SelectObject(bitmapHDC,bitmap);

	SelectObject(bitmapHDC, transparencyMask);
	StretchBlt(backHDC, x-(w*i/2), y-(h*i/2), w*i, h*i, bitmapHDC, 0, 0, w, h, SRCAND);
	SelectObject(bitmapHDC, bitmap);
	StretchBlt(backHDC, x-(w*i/2), y-(h*i/2), x + w*i/2, x + h*i/2, bitmapHDC, 0, 0, w, h, SRCPAINT);

	SelectObject(bitmapHDC,originalBitMap); 
}
