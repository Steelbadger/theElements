#include "particle_controller.h"
#include <math.h>
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
	return !spaces[i];
}

void particle_controller::Update(int x, int y)
{
	mouseX = x;
	mouseY = y;
	SimulateParticles();
	UpdateAllParticles();

}

void particle_controller::SetScreenSize(int x, int y)
{
	xSize = x;
	ySize = y;
}

void particle_controller::SimulateParticles()
{

	float xdist, ydist, res = 0;
	float G = 3.5;

	for (int i = 0; i < maxParticles; i++)
	{
		if (!spaces[i]) {

			if (particles[i]->IsSelected() == false){
				xdist = (particles[i]->GetX()+particles[i]->GetWidth()/2) - xSize/2;
				ydist = (particles[i]->GetY()+particles[i]->GetHeight()/2) - ySize/2;
				particles[i]->SetForce(0,0);
				particles[i]->AddForce(-xdist/1000, -ydist/1000);
				for (int j = 0; j < maxParticles; j++)
				{
					if (!spaces[j] && j != i) {
						xdist = (particles[i]->GetX()+particles[i]->GetWidth()/2) - (particles[j]->GetX()+particles[j]->GetWidth()/2);
						ydist = (particles[i]->GetY()+particles[i]->GetHeight()/2) - (particles[j]->GetY()+particles[j]->GetHeight()/2);
						res = xdist*xdist + ydist*ydist;
						particles[i]->AddForce((xdist/res)*G, (ydist/res)*G);
						
					}
				}	

			}
		}
	}	
}

void particle_controller::UpdateAllParticles()
{

	for (int i = 0; i < maxParticles; i++) {
		if (!spaces[i]) {
			particles[i]->Update(mouseX, mouseY);
		}
	}	
}