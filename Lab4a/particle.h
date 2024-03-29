#pragma once
#include <string>
#include "sprite.h"
#include <windows.h>

class particle
{
public:
	enum type {NONE, UP_QUARK, DOWN_QUARK, TOP_QUARK, BOTTOM_QUARK, STRANGE_QUARK, CHARM_QUARK, GLUON, ELECTRON, PROTON, NEUTRON};
	particle(type particleType);
	~particle(void);	
	void Draw(HDC bitmapHDC, HDC backHDC, int ParticleNumber);
	void Move(sprite::direction dir) {image->Move(dir);}
	void Move(float deltaX, float deltaY);
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
	int GetPrimID() {return primID;}
	type GetType() {return particleType;}
	bool IsMoving();
	bool OnClick(int xClick, int yClick);
	void OnRelease(){SetSelected(false); image->OnRelease();}
	void OrbitAt(int radius, int xCentre, int yCentre);

	void AnimatedCreation();
	void SetScreenSize(int x, int y);
	
private:
	float mass;
	int charge[2];
	int spin[2];
	int primID;
	std::string name;
	sprite *image;
	bool selected;
	float xForce, yForce;
	float xVelocity, yVelocity;
	unsigned long time;
	type particleType;
	int screenX, screenY;
	float orbit;

};

