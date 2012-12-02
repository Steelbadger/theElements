#include "sprite.h"
#include <windows.h>

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
		BitBlt(backHDC, x, y, w, h, bitmapHDC, 0, 0, SRCAND);
		SelectObject(bitmapHDC, bitmap);
		BitBlt(backHDC, x, y, w, h, bitmapHDC, 0, 0, SRCPAINT);
	}

	SelectObject(bitmapHDC,originalBitMap);
}

void sprite::Draw(HDC bitmapHDC, HDC backHDC, float scalefactor)
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
		float i = scalefactor;
		SelectObject(bitmapHDC, transparencyMask);
		StretchBlt(backHDC, x+((w-(w*i))/2), y+((h-(h*i))/2), w*i, h*i, bitmapHDC, 0, 0, w, h, SRCAND);
		SelectObject(bitmapHDC, bitmap);
		StretchBlt(backHDC, x+((w-(w*i))/2), y+((h-(h*i))/2), w*i, h*i, bitmapHDC, 0, 0, w, h, SRCPAINT);
	}

	SelectObject(bitmapHDC,originalBitMap);
}

void sprite::DrawFade(HDC bitmapHDC, HDC backHDC, int frame)
{
	HBITMAP fadeMask = (HBITMAP)LoadImage(NULL, "fademask.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	HBITMAP originalBitMap;
	originalBitMap = (HBITMAP)SelectObject(bitmapHDC,bitmap);
	for (int i = 0; i < frame; i++) {
		SelectObject(bitmapHDC, fadeMask);
		BitBlt(backHDC, x, y, w, h, bitmapHDC, 0, 0, SRCAND);
	}
	SelectObject(bitmapHDC, bitmap);
	BitBlt(backHDC, x, y, w, h, bitmapHDC, 0, 0, SRCPAINT);

}

void sprite::Move(sprite::direction dir)
{
	switch (dir) {
		case LEFT:
			x-=3;
			break;
		case RIGHT:
			x+=3;
			break;
		case UP:
			y-=3;
			break;
		case DOWN:
			y+=3;
			break;
	}
}

void sprite::SetSelected(bool i)
{
	selected = i;
}

bool sprite::OnClick(int xClick, int yClick)
{
	if (MouseOver(xClick, yClick)) {
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
	if (xMouse > x && xMouse < (x+w) && yMouse > y && yMouse < (y+h)) {
		return true;
	} else {
		return false;
	}

}

HBITMAP sprite::CreateBitmapMask(HBITMAP baseBitmap, COLORREF crTransparent)
{
    HDC hdcTemp, hdcTemp2;
    HBITMAP hbmMask;
    BITMAP bm;

    // Create monochrome mask bitmap.  

    GetObject(baseBitmap, sizeof(BITMAP), &bm);
    hbmMask = CreateBitmap(bm.bmWidth, bm.bmHeight, 1, 1, NULL);

    // Create some HDCs that are compatible with the display driver

    hdcTemp = CreateCompatibleDC(0);
    hdcTemp2 = CreateCompatibleDC(0);

    SelectObject(hdcTemp, baseBitmap);
    SelectObject(hdcTemp2, hbmMask);

    // Set the background colour of the colour image to the colour
    // to be transparent.
    SetBkColor(hdcTemp, crTransparent);

    // Copy the bits from the colour image to the mask. Everything
    // with the background colour ends up white while everythig else ends up
    // black.

    BitBlt(hdcTemp2, 0, 0, bm.bmWidth, bm.bmHeight, hdcTemp, 0, 0, SRCCOPY);

    // Take our new mask and use it to turn the transparent colour in the
    // original colour image to black so the transparency effect will
    // work right.
    BitBlt(hdcTemp, 0, 0, bm.bmWidth, bm.bmHeight, hdcTemp2, 0, 0, SRCINVERT);

    // Tidy up.

    DeleteDC(hdcTemp);
    DeleteDC(hdcTemp2);

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
