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
	return !spaces[i];
}

void particle_controller::Update(int x, int y)
{
	mouseX = x;
	mouseY = y;
	SimulateParticles();

}

void particle_controller::SetScreenSize(int x, int y)
{
	xSize = x;
	ySize = y;
}

void particle_controller::SimulateParticles()
{

	float xdist, ydist = 0;

	for (int i = 0; i < maxParticles; i++)
	{
		if (!spaces[i]) {

			if (particles[i]->IsSelected() == false){
/*
				if (particles[i]->GetX() > xSize/2 - particles[i]->GetWidth()/2) {
					particles[i]->Move(sprite::LEFT);
				} else {
					particles[i]->Move(sprite::RIGHT);
				}
				if (particles[i]->GetY() > ySize/2- particles[i]->GetHeight()/2) {
					particles[i]->Move(sprite::UP);
				} else {
					particles[i]->Move(sprite::DOWN);
				}
*/
				xdist = particles[i]->GetX() - xSize/2;
				ydist = particles[i]->GetY() - ySize/2;
				particles[i]->SetForce(0,0);
				if (xdist > 0)
					particles[i]->AddForce(-G * xdist, 0);
				if (xdist < 0)
					particles[i]->AddForce(G * xdist, 0);
				if (ydist > 0)
					particles[i]->AddForce(0, -G * ydist);
				if (ydist < 0)
					particles[i]->AddForce(0, G*ydist);

				for (int j = 0; j < maxParticles; j++) {
					if (!spaces[j]) {
						xdist = particles[i]->GetX() - particles[j]->GetX();
						ydist = particles[i]->GetY() - particles[j]->GetY();
						if (xdist > 0)
							particles[i]->AddForce(G/(xdist*xdist), 0);
						if (xdist < 0)
							particles[i]->AddForce(-G/(xdist*xdist), 0);
						if (ydist > 0)
							particles[i]->AddForce(0, G/(ydist*ydist));
						if (ydist < 0)
							particles[i]->AddForce(0, -G/(ydist*ydist));
					}
				}

				particles[i]->Update(mouseX, mouseY);
			}
		}
	}	
}