#include "theElements.h"


theElements::theElements(void):
	particles(MAXSIZE),
	currentState(SplashScreen),
	running(true),
	HUD(840, 620),
	current(7),
	background("wmap.bmp", 0,0)
{
}


theElements::~theElements(void)
{
}

void theElements::HandleInstantInput()
{
			input.Update();
			HUD.SetMouseLoc(input.GetMouseX(), input.GetMouseY());

			if (input.ReportLMousePress() && particles.SpaceRemaining() && HUD.ReturnParticleCreation() != particle::NONE)
			{
				current = particles.CreateNew(HUD.ReturnParticleCreation());
				particles.SetSelected(current);
			} else if (input.ReportLMouseRelease()) {
				particles.OnRelease();
				if (current != MAXSIZE && HUD.MouseOver()) {
					if (HUD.OnMouseRelease(particles.SelectedParticle(current))){
						particles.DeleteParticle(current);
						current = MAXSIZE;
					}

				}
			} else if (input.ReportLMousePress() && HUD.OnTableClick()) {
				currentState = Table;
			} else if (input.ReportLMousePress()) {
				current = particles.OnClick(input.GetMouseX(), input.GetMouseY());
			}

			if (input.ReportRMouseRelease()) {
				particles.DestroyFirstParticleAtMouse();
			}
			if (input.ReportKeyPress('P')) {
				currentState = Pause;
			}

			if (particles.ReportAtomCreation() >= 0) {
				table.UnlockAtom(particles.ReportAtomCreation()-1);
			}
}

void theElements::HandleDelayedInput(unsigned long x)
{
	if (WaitFor(x))
	{	
		HUD.Update(input.GetMouseX(), input.GetMouseY());
		particles.Update(input.GetMouseX(), input.GetMouseY());
	}
	
}

bool theElements::WaitFor(unsigned long delay)
{
	static unsigned long clockStart = 0;
	unsigned long timePassed;
	unsigned long now = timeGetTime();

	timePassed = now - clockStart;
	if (timePassed >  delay)
	{
		clockStart = now;
		return TRUE;
	}
	else
		return FALSE;
}

void theElements::releaseResources()
{
	SelectObject(backHDC,theOldBackBitMap);
	DeleteDC(backHDC);
	ReleaseDC(ghwnd,frontHDC);
}
void theElements::displayFrame()
{
		BitBlt(frontHDC, screenRect.left,screenRect.top, screenRect.right, 
		screenRect.bottom, backHDC, 0, 0, SRCCOPY);
		FillRect(backHDC, &screenRect, (HBRUSH)GetStockObject(0));	
}

void theElements::setBuffers()
{
	GetClientRect(ghwnd, &screenRect);	//creates rect based on window client area
	frontHDC = GetDC(ghwnd);			// Initialises front buffer device context (window)
	backHDC = CreateCompatibleDC(frontHDC);// sets up Back DC to be compatible with the front
	bitmapHDC=CreateCompatibleDC(backHDC);
	theOldFrontBitMap = CreateCompatibleBitmap(frontHDC, screenRect.right, 
		screenRect.bottom);		//creates bitmap compatible with the front buffer
    theOldBackBitMap = (HBITMAP)SelectObject(backHDC, theOldFrontBitMap);
								//creates bitmap compatible with the back buffer
	FillRect(backHDC, &screenRect, (HBRUSH)GetStockObject(0));	
}

void theElements::OnCreate()
{
	cxSource = GetSystemMetrics (SM_CXSIZEFRAME) + GetSystemMetrics (SM_CXSIZE);
	cySource = GetSystemMetrics (SM_CYSIZEFRAME) + GetSystemMetrics (SM_CYCAPTION);
}

void theElements::OnSize(LPARAM lParam)
{
	cxClient = LOWORD (lParam);
	cyClient = HIWORD (lParam);
	GetClientRect(ghwnd, &screenRect);	//creates rect based on window client area
	setBuffers();
	menu.SetMenuLocation(cxClient/2, cyClient/2);
	HUD.SetDisplaySize(cxClient, cyClient);
	particles.SetScreenSize(cxClient, cyClient);

}

void theElements::MainLoop()
{
	switch (currentState) {
		case SplashScreen:
			DisplaySplashScreen();
			break;
		case Menu:
			DisplayMenuScreen();
			break;
		case Game:
			RunGame();
			break;
		case Table:
			DisplayTable();
			break;
		case Pause:
			DisplayPause();
			break;
		case Quit:
			QuitGame();
			break;
	}
}

void theElements::DisplaySplashScreen()
{
	input.Update();
	
	if (input.ReportKeyPress(VK_RETURN))
	{
		currentState = Menu;
	}

	if (WaitFor(10))
	{	
		menu.DisplaySplash(bitmapHDC,backHDC);
		displayFrame();
	}
}

void theElements::OnPaint()
{
}

void theElements::DisplayMenuScreen()
{
	input.Update();
	if (input.ReportLMousePress()) {
		menu.OnClick(input.ReportMouseLocation(Mouse::X), input.ReportMouseLocation(Mouse::Y));
	}
	menu.Update(input.GetMouseX(), input.GetMouseY());
	if (menu.ReturnButtonClicked() == menu::NewGame) {
		currentState = Game;
	} else if (menu.ReturnButtonClicked() == menu::Quit) {
		currentState = Quit;
	}
	if (WaitFor(10)) {	
		menu.DisplayMenu(bitmapHDC,backHDC);
		displayFrame();
	}
}

void theElements::RunGame()
{
		HandleInstantInput();
		HandleDelayedInput(5);
		background.Draw(bitmapHDC, backHDC);
	//	particles.Update(input.GetMouseX(), input.GetMouseY());
		particles.DrawAll(bitmapHDC, backHDC);
		HUD.Display(bitmapHDC, backHDC);
		displayFrame();
}

void theElements::DisplayTable()
{
	input.Update();
	if (input.GetMouseX() < 20 && table.GetX() < 0) {
		table.Move(1.0f, 0.0f);
	}
	if (input.GetMouseX() > cxClient - 20 && table.GetX() + table.GetWidth() > cxClient) {
		table.Move(-1.0f, 0.0f);
	}
	if (input.GetMouseY() < 20 && table.GetY() > 0) {
		table.Move(0.0f, -1.0f);
	}
	if (input.GetMouseY() > cyClient - 20 && table.GetY() + table.GetHeight() > cyClient) {
		table.Move(0.0f, 1.0f);
	}
	if (input.ReportLMousePress() && HUD.OnTableClick()) {
		currentState = Game;
	}
	table.Draw(bitmapHDC, backHDC);
	displayFrame();


}

void theElements::DisplayPause()
{
	input.Update();
	if (input.ReportLMousePress()) {
		menu.OnClickPaused(input.GetMouseX(), input.GetMouseY());
	}
	menu.UpdatePaused(input.GetMouseX(), input.GetMouseY());
	if (menu.ReturnButtonClicked() == menu::Continue) {
		currentState = Game;
	} else if (menu.ReturnButtonClicked() == menu::Quit) {
		currentState = Quit;
	}
	if (WaitFor(10)) {	
		menu.DisplayPaused(bitmapHDC,backHDC);
		displayFrame();
	}
	menu.ResetButtonClicked();
}

void theElements::QuitGame()
{
	running = false;
}

