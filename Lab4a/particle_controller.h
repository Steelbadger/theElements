#ifndef _PARTICLE_CONTROLLER_INCLUDED_
#define _PARTICLE_CONTROLLER_INCLUDED_

#ifndef _PARTICLE_H_
#define _PARTICLE_H_
#include "particle.h"
#endif

#ifndef _WINDOWS_H_DEFINED_
#define _WINDOWS_H_DEFINED_
#include <windows.h>
#endif




class particle_controller
{
public:
	particle_controller(int maxParticles);
	~particle_controller(void);
	int CreateNew(particle::type);
	bool DeleteParticle(int ID);
	void DeleteParticles();
	bool DrawParticle(int ID, HDC bitmapHDC, HDC backHDC);
	bool MoveParticle(int ID, sprite::direction dir);
	void DrawAll(HDC bitmapHDC, HDC backHDC);
	void SetLocation(int ID, int x, int y);
	bool SpaceRemaining();
	bool IsEmpty();
	bool IsParticle(int ID);

private:
	int maxParticles;
	particle **particles;
	bool *spaces;

};

#endif

