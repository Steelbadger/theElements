#ifndef _WINDOWS_H_DEFINED_
#define _WINDOWS_H_DEFINED_
#include <windows.h>
#endif
#include "mouse.h"
#include <math.h>
#include <stdio.h>

Mouse::Mouse(void)
{
	x = 0;
	y = 0;
	oldx = 0;
	oldy = 0;
}


Mouse::~Mouse(void)
{
}

void Mouse::UpdatePosition(LPARAM lParam)
{
	oldx = x;
	oldy = y;
	x = LOWORD (lParam);
	y = HIWORD (lParam);
}

void Mouse::Message(UINT message, LPARAM lParam)
{
	switch (message)
	{
		case WM_MOUSEMOVE:
			UpdatePosition(lParam);
			break;

		case WM_LBUTTONDOWN:
			lmouse = true;
			break;	
		case WM_LBUTTONUP:
			lmouse = false;
			break;
		case WM_RBUTTONDOWN:
			rmouse = true;
			break;
		case WM_RBUTTONUP:
			rmouse = false;
			break;
	}
}

void Mouse::Update()
{
	lmouseclick = false;
	rmouseclick = false;
	lrelease = false;
	rrelease = false;
	if (lmouse == true && lastlmouse == false)
	{
		lmouseclick = true;
	}
	if (rmouse == true && lastrmouse == false)
	{
		rmouseclick = true;
	}
	if (lmouse == false && lastlmouse == true)
	{
		lrelease = true;
	}
	if (rmouse == false && lastrmouse == true)
	{
		rrelease = true;
	}
	lastlmouse = lmouse;
	lastrmouse = rmouse;
}

int Mouse::Location(axis Axis)
{
	if (Axis == X)
		return x;
	else
		return y;
}