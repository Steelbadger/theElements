//Windows Example Code
//Paul Robertson 2012

#include <windows.h>
#include <stdio.h>
#include <mmsystem.h>
#include <math.h>
#include "theElements.h"

theElements Application;


LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM);

void RegisterMyWindow(HINSTANCE hInstance)
{
    WNDCLASSEX  wcex;									

    wcex.cbSize        = sizeof (wcex);				
    wcex.style         = CS_HREDRAW | CS_VREDRAW;		
    wcex.lpfnWndProc   = WndProc;						
    wcex.cbClsExtra    = 0;								
    wcex.cbWndExtra    = 0;								
    wcex.hInstance     = hInstance;						
    wcex.hIcon         = 0; 
    wcex.hCursor       = LoadCursor (NULL, IDC_ARROW);	
															
    wcex.hbrBackground = (HBRUSH) (COLOR_WINDOW+1);
    wcex.lpszMenuName  = NULL;							
    wcex.lpszClassName = "FirstWindowClass";				
    wcex.hIconSm       = 0; 

	RegisterClassEx (&wcex);							
}


BOOL InitialiseMyWindow(HINSTANCE hInstance, int nCmdShow)
{
	HWND        hwnd;
	hwnd = CreateWindow ("FirstWindowClass",					
						 "Elements",		  	
						 WS_OVERLAPPEDWINDOW,	
						 CW_USEDEFAULT,			
						 CW_USEDEFAULT,			
						 840,			
						 620,			
						 NULL,					
						 NULL,					
						 hInstance,				
						 NULL);								
	if (!hwnd)
	{
		return FALSE;
	}

    ShowWindow (hwnd, nCmdShow);						
    UpdateWindow (hwnd);	
	Application.ghwnd = hwnd;
	return TRUE;

}
			
LRESULT CALLBACK WndProc (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)											
    {														
		case WM_CREATE:	
			Application.OnCreate();
			break;

		case WM_SIZE:
			Application.OnSize(lParam);
			break;	

		case WM_KEYDOWN:
		case WM_KEYUP:
		case WM_MOUSEMOVE:
		case WM_LBUTTONDOWN:
		case WM_LBUTTONUP:
		case WM_RBUTTONDOWN:
		case WM_RBUTTONUP:
			Application.Message(message, wParam, lParam);
			break;

		case WM_PAINT:	
		    break;		

		case WM_DESTROY:	
			
			PostQuitMessage(0);	
								
			break;				
	}													

	return DefWindowProc (hwnd, message, wParam, lParam);		
															
}

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    PSTR szCmdLine, int nCmdShow)			
{									
    MSG       msg;	
	HDC	hdcWindow;

	RegisterMyWindow(hInstance);

   	if (!InitialiseMyWindow(hInstance, nCmdShow))
		return FALSE;

	hdcWindow = GetWindowDC (Application.ghwnd);
	Application.setBuffers();

	while (Application.Running())					
    {							
		if (PeekMessage(&msg,NULL,0,0,PM_REMOVE))
		{
		    if (msg.message==WM_QUIT)
				break;
			TranslateMessage (&msg);							
			DispatchMessage (&msg);
		}

		else
		{	
			Application.MainLoop();
		}
    }

    Application.releaseResources();
	return msg.wParam ;										
}


