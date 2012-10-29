#include "input.h"
#include "mouse.h"
#include <string.h>
#ifndef _WINDOWS_H_DEFINED_
#define _WINDOWS_H_DEFINED_
#include <windows.h>
#endif


Input::Input(void)
{
	for (int i = 255; i >= 0; i--)
	{
		oldkey[i] = false;
		keys[i] = false;
	}
}


Input::~Input(void)
{
}

void Input::Message(UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		case WM_KEYDOWN:
			KeyDown(wParam);
			break;

		case WM_KEYUP:
			KeyUp(wParam);
			break;

		case WM_MOUSEMOVE:
		case WM_LBUTTONDOWN:
		case WM_LBUTTONUP:
		case WM_RBUTTONDOWN:
		case WM_RBUTTONUP:
			mouse.Message(message, lParam);
			break;
	}

}

void Input::KeyDown(UINT wParam)
{
	oldkey[wParam] = keys[wParam];
	keys[wParam]=true;
}

void Input::KeyUp(UINT wParam)
{
	oldkey[wParam] = keys[wParam];
	keys[wParam]=false;	
}

void Input::Update()
{
	for (int i = 256; i > 0; i--)
	{
		if (keys[i-1] == true && oldkey[i-1] == false)
			pressed[i-1] = true;
		else
			pressed[i-1] = false;
	}

	memcpy(oldkey, keys, sizeof(keys));
	mouse.Update();
}