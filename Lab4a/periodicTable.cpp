#include "periodicTable.h"


periodicTable::periodicTable(void)
{
	BITMAP bmap;
	xBase = 0;
	yBase = 0;
	lockedTable = (HBITMAP)LoadImage(NULL, "table_locked.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	unlockedTable = (HBITMAP)LoadImage(NULL, "table_unlocked.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	GetObject(lockedTable,sizeof(bmap), &bmap);
	width = bmap.bmWidth;
	height = bmap.bmHeight;
}


periodicTable::~periodicTable(void)
{
}


void periodicTable::InitPositions()
{
	positions[0][0] = 24;
	positions[0][1] = 46;
	positions[1][0] = 24+78*17;
	positions[1][1] = 46;

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 8; j++) {
			positions[2+j+i*8][0] = j*78+24+(j > 1? 780 : 0);
			positions[2+j+i*8][1] = 46+i*78;
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 18; j++) {
			positions[18+j+i*18][0] = i*78+24;
			positions[18+j+i*18][1] = 46+j*78;
		}
	}

	for (int i = 0; i < 118; i++) {
		unlocked[i] = false;
	}

}

void periodicTable::Draw(HDC bitmapHDC, HDC backHDC)
{
	HBITMAP originalBitMap;
	originalBitMap = (HBITMAP)SelectObject(bitmapHDC,lockedTable);

	SelectObject(bitmapHDC, lockedTable);
	BitBlt(backHDC, xBase, yBase, xBase+width, yBase+height, bitmapHDC, 0, 0, SRCCOPY);

	SelectObject(bitmapHDC, unlockedTable);
	for (int i = 0; i< 118; i++) {
		if (unlocked[i] = true)
			BitBlt(backHDC, xBase+positions[i][0], yBase+positions[i][1], xBase+width+positions[i][0], yBase+positions[i][1]+height, bitmapHDC, positions[i][0], positions[i][1], SRCCOPY);
	}

	SelectObject(bitmapHDC,originalBitMap);
}