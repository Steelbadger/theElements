#pragma once

#include <windows.h>
#include <stdio.h>

#define MAXSIZE 20

HBITMAP		theOldFrontBitMap, theOldBackBitMap;
HWND        ghwnd;
RECT		screenRect;
HDC			backHDC, frontHDC, bitmapHDC;	//Hardware device contexts for the Buffers

int			cxClient, cyClient, cxSource, cySource;

class myApplication
{
public:
	myApplication(void);
	~myApplication(void);
};

