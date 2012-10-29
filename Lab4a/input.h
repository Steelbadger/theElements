#ifndef _INPUT_INCLUDED_
#define _INPUT_INCLUDED_

#ifndef _WINDOWS_H_DEFINED_
#define _WINDOWS_H_DEFINED_
#include <windows.h>
#endif
#include "mouse.h"



class Input
{
public:
	Input(void);
	~Input(void);

	void Message(UINT, WPARAM, LPARAM);

	void Update();

	int GetMouseX() {return mouse.GetX();}
	int GetMouseY() {return mouse.GetY();}
	bool GetMouseR() {return mouse.RButton();}
	bool GetMouseL() {return mouse.LButton();}
	bool GetOldMouseR() {return mouse.OldRButton();}
	bool GetOldMouseL() {return mouse.OldLButton();}
	bool ReportKeyState(int key) {return keys[key];}
	bool ReportKeyState(char key) {return keys[key];}
	bool ReportKeyPress(int key) {return pressed[key];}
	bool ReportKeyPress(char key) {return pressed[key];}
	bool ReportLMousePress() {return mouse.lClick();}
	bool ReportRMousePress() {return mouse.rClick();}
	int ReportMouseLocation(Mouse::axis Axis) {return mouse.Location(Axis);}
private:
	bool keys[256];
	bool pressed[256];
	bool oldkey[256];
	Mouse mouse;

	void KeyDown(UINT);
	void KeyUp(UINT);

};
#endif
