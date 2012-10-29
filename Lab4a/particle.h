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
	enum type {UP_QUARK, DOWN_QUARK, TOP_QUARK, BOTTOM_QUARK, STRANGE_QUARK, CHARM_QUARK};
	particle(type particleType);
	~particle(void);
	void Draw(HDC bitmapHDC, HDC backHDC) {image->Draw(bitmapHDC, backHDC);}
	void Move(sprite::direction dir) {image->Move(dir);}
	void SetLocation(int x, int y){image->SetLocation(x,y);}
	void Update();
	void SetSelected(bool s){image->SetSelected(s);}
	bool IsSelected(){return image->IsSelected();}
private:
	float mass;
	int charge[2];
	int spin[2];
	std::string name;
	sprite *image;

};

#endif

