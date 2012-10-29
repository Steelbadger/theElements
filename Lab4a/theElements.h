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

#define MAXSIZE 20



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
private:

	enum GameState {SplashScreen, Menu, Game, GameOver, Quit};
	GameState currentState;
	Input input;
	particle_controller particles;
	menu menu;
	gameUI HUD;

	bool WaitFor(unsigned long delay);
	HBITMAP		theOldFrontBitMap, theOldBackBitMap;
	RECT		screenRect;
	HDC			backHDC, frontHDC, bitmapHDC;	//Hardware device contexts for the Buffers
	int			cxClient, cyClient, cxSource, cySource;
	void displayFrame();
	void DisplaySplashScreen();
	void DisplayMenuScreen();
	void RunGame();
	void DisplayGameOver();
	void QuitGame();
	bool running;



};

