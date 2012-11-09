#ifndef _PARTICLE_H_DEFINED_
#define _PARTICLE_H_DEFINED_

#ifndef _STRING_DEFINED_
#define _STRING_DEFINED_
#include <string>
#endif

#ifndef _SPRITE_DEFINED_
#define _SPRITE_DEFINED_
#include "sprite.h"
#endif

#ifndef _WINDOWS_H_DEFINED_
#define _WINDOWS_H_DEFINED_
#include <windows.h>
#endif

class particle
{
public:
	enum type {NONE, UP_QUARK, DOWN_QUARK, TOP_QUARK, BOTTOM_QUARK, STRANGE_QUARK, CHARM_QUARK, GLUON};
	particle(type particleType);
	~particle(void);
	void Draw(HDC bitmapHDC, HDC backHDC) {image->Draw(bitmapHDC, backHDC);}
	void Move(sprite::direction dir) {image->Move(dir);}
	void Move(float deltaX, float deltaY) {image->Move(deltaX, deltaY);}
	void AddForce(float x, float y) {xForce += x; yForce += y;}
	void SetForce(float x, float y) {xForce = x; yForce = y;}
	void MoveUnderForce();
	void SetLocation(int x, int y){image->SetLocation(x,y);}
	void Update(int x, int y);
	void Drag(int x, int y);
	void SetSelected(bool s){selected = s;}
	bool IsSelected(){return selected;}
	float GetX() {return image->GetX();}
	float GetY() {return image->GetY();}
	int GetWidth() {return image->GetWidth();}
	int GetHeight() {return image->GetHeight();}

private:
	float mass;
	int charge[2];
	int spin[2];
	std::string name;
	sprite *image;
	bool selected;
	float xForce, yForce;
	float xVelocity, yVelocity;
	unsigned long time;

};

#endif

