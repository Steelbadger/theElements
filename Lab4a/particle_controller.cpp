#include "particle_controller.h"
#ifndef _PARTICLE_H_
#define _PARTICLE_H_
#include "particle.h"
#endif


particle_controller::particle_controller(int max)
{
	maxParticles = max;
	particles = new particle* [maxParticles];
	spaces = new bool[maxParticles];
	for (int i = maxParticles; i > 0; i--)
	{
		spaces[i-1] = true;
	}
}


particle_controller::~particle_controller(void)
{
}

int particle_controller::CreateNew(particle::type type)
{
	for (int i = 0; i < maxParticles; i++)
	{
		if (spaces[i] == true)
		{
			particles[i] = new particle(type);
			spaces[i] = false;
			return i;
		}
	}
	return maxParticles;
}

bool particle_controller::DeleteParticle(int ID)
{
	if (spaces[ID] == false && (ID < maxParticles))
	{
		delete particles[ID];
		particles[ID] = NULL;
		spaces[ID] = true;
		return true;
	} else {
		return false;
	}
}

void particle_controller::DeleteParticles()
{
	for (int i = 0; i < maxParticles; i++)
	{
		DeleteParticle(i);
	}
}

bool particle_controller::DrawParticle(int ID, HDC bitmapHDC, HDC backHDC)
{
	if (particles[ID] != NULL && (ID < maxParticles))
	{
		particles[ID]->Draw(bitmapHDC, backHDC);
		return true;
	} else {
		return false;
	}
}

bool particle_controller::MoveParticle(int ID, sprite::direction dir)
{
	if (spaces[ID] == false && (ID < maxParticles))
	{
		particles[ID]->Move(dir);
		return true;
	} else {
		return false;
	}

}

void particle_controller::DrawAll(HDC bitmapHDC, HDC backHDC)
{
	for (int i = 0; i < maxParticles; i++)
	{
		if (!spaces[i])
			particles[i]->Draw(bitmapHDC, backHDC);
	}

}

void particle_controller::SetLocation(int ID, int x, int y)
{
	particles[ID]->SetLocation(x,y);
}

bool particle_controller::SpaceRemaining()
{
	for (int i = 0; i < maxParticles; i++)
	{
		if (spaces[i])
			return true;
	}
	return false;
}

bool particle_controller::IsEmpty()
{
	for (int i = 0; i < maxParticles; i++)
	{
		if (spaces[i])
			return false;
	}
	return true;
}

bool particle_controller::IsParticle(int i)
{
	return spaces[i];
}