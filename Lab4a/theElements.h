#pragma once

#include <windows.h>
#include <stdio.h>
#include <mmsystem.h>
#include <math.h>
#include "input.h"
#include "particle.h"
#include "particle_controller.h"
#include "menu.h"
#include "gameUI.h"
#include <stack>
#include "hint.h"
#include "periodicTable.h"

#define MAXSIZE 80



class theElements
{
public:
	theElements(void);
	~theElements(void);
	void Display();
	void HandleInstantInput();
	void HandleDelayedInput(unsigned long delay);
	void Message(UINT message, WPARAM wParam, LPARAM lParam){input.Message(message, wParam, lParam);}
	void OnCreate();
	void OnSize(LPARAM lParam);
	void MainLoop();
	void setBuffers();
	void releaseResources();
	HWND        ghwnd;
	bool Running(){return running;}
	void OnPaint();
private:

	enum GameState {SplashScreen, Menu, Guide, Game, Table, Pause, Quit};
	GameState currentState;
	Input input;
	particle_controller particles;
	menu menu;
	gameUI HUD;
	periodicTable table;
	int current;
	sprite background;

	bool WaitFor(unsigned long delay);
	HBITMAP		theOldFrontBitMap, theOldBackBitMap;
	RECT		screenRect;
	HDC			backHDC, frontHDC, bitmapHDC;	//Hardware device contexts for the Buffers
	int			cxClient, cyClient, cxSource, cySource;
	void displayFrame();
	void DisplaySplashScreen();
	void DisplayMenuScreen();
	void DisplayGuide();
	void RunGame();
	void DisplayTable();
	void DisplayPause();
	void QuitGame();
	bool running;



};

