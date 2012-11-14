#pragma once
#include "sprite.h"
#include "particle.h"

class button
{
public:
	button(LPSTR szBGFileName, LPSTR szMOFileName, LPSTR szImgFileName, int x, int y);
	button(LPSTR szBGFileName, LPSTR szMOFileName, LPSTR szImgFileName);
	button(particle::type ParticleType);
	~button(void);
	void Update(int x, int y);
	bool OnClick(int x, int y);
	void OnRelease(particle::type ParticleType);
	void SetLocation(int x, int y){background.SetLocation(x, y); mouseover.SetLocation(x, y); image.SetLocation(x, y);}
	void Draw(HDC bitmapHDC, HDC backHDC);
	void Move(sprite::direction dir){background.Move(dir); mouseover.Move(dir); image.Move(dir);}
	bool IsSelected() {return selected;}
	bool MouseOver(int mouseX, int mouseY){return mouseover.MouseOver(mouseX, mouseY);}

	particle::type CreateParticle(){return particleType;}
	void SetNew(particle::type ParticleType);
private:
	sprite background;
	sprite mouseover;
	sprite image;
	bool mOver;
	bool selected;
	particle::type particleType;
};

