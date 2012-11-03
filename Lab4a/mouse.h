#ifndef _MOUSE_INCLUDED_
#define _MOUSE_INCLUDED_

#ifndef _WINDOWS_H_DEFINED_
#define _WINDOWS_H_DEFINED_
#include <windows.h>
#endif

class Mouse
{
public:

	enum axis {X, Y};

	Mouse(void);
	~Mouse(void);

	int GetX() {return x;}
	int GetY() {return y;}
	void Message(UINT, LPARAM);
	void Update();
	bool RButton() {return rmouse;}
	bool LButton() {return lmouse;}
	bool OldRButton() {return lastrmouse;}
	bool OldLButton() {return lastlmouse;}
	bool rClick() {return rmouseclick;}
	bool lClick() {return lmouseclick;}
	bool rRelease() {return rrelease;}
	bool lRelease() {return lrelease;}
	int Location(axis);

private:
	int x, y;
	int oldx, oldy;
	bool lmouse, rmouse;
	bool lastlmouse, lastrmouse;
	bool lmouseclick, rmouseclick;
	bool lrelease, rrelease;


	void UpdatePosition(LPARAM);
};

#endif