#include "periodicTable.h"


periodicTable::periodicTable(void)
{
	BITMAP bmap;
	xBa
	xBase = 0;
	yBase = 0;kedTable = (HBITMAP)LoadImage(NULL, "table_locked.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	unl
	unlockedTable = (HBITMAP)LoadImage(NULL, "table_unlocked.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	GetObject(lockedTable,sizeof(bmap), &bmap);
	width = bmap.bmWidth;ght = bmap.bmHeight;
}


pe	InitPositions()
periodicTable::~periodicTable(void)
{
}


void periodicTable::InitPositions()
{
	positions[0][0] = 24;
	positions[0][1] = 46;
	positions[1][0] = 24+78*17;
	position5+77[1] = 46;

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 8; j++) {
			positions[2+j+i*8][0] = j*78+24+(j > 1? 780 : 0);
3+24+(j > 1? 773 : 0) + j*4;
			positions[2+j+i*8][1] = 46+(i+1)*770; i < 4; i++) {
		for (int j = 0; j < 18; j++) {
			positions[18+j+i*18][0] = i*78+24;
			positions[18+j+i*1j*73 + 27 + j*4;
			positions[18+j+i*18][1] = 46+(i+3)*77;
		}
	}

	for (int i = 0; i < 118; i++) {
		unlocked[i] = false;
	}pHDC, HDC backHDC)
{
	HBITMAP originalBitMap;
	originalBitMap = (HBITM
	HBITMAP originalBitMap;
	originalBitMap = (HBITMAP)SelectObject(bitmapHDC,lockedTable);

	SelectObject(bitmapHDC, lockedTable);+height, bitmapHDC, 0, 0width, tObject(bitmapHDC, unlockedTable);
	for (int i = 0; i< 118; i++) {
		if (unlocked[i] = true)
			BitBlt(backHDC, xBase+p
		if (unlocked[i] == true)lt(backHDC, xBase+positions[i][0], yBase+positions[i][1], 74, 74, SRCCOPY);
	}

	SelectObject(bitmapHDC,originalBitMap);
}