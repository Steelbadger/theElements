#include "particle.h"
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

#include <time.h>


particle::particle(type type) :
	xForce(0),
	yForce(0),
	xVelocity(0),
	yVelocity(0),
	particleType(type)
{
	switch (type)
	{
		case UP_QUARK:
			mass = 2.4*1000000;
			charge[0] = 2;
			charge[1] = 3;
			spin[0] = 1;
			spin[1] = 2;
			name = "Up Quark";
			image = new sprite("UpQuark.bmp");
			primID = 2;
			break;
		case DOWN_QUARK:
			mass = 4.8*1000000;
			charge[0] = -1;
			charge[1] = 2;
			spin[0] = 1;
			spin[1] = 2;
			name = "Down Quark";
			image = new sprite("DownQuark.bmp");
			primID = 3;
			break;
		case TOP_QUARK:
			mass = 171.2*1000000000;
			charge[0] = 2;
			charge[2] = 3;
			spin[0] = 1;
			spin[1] = 2;
			name = "Top Quark";
			image = new sprite("TopQuark.bmp");
			primID = 0;
			break;
		case BOTTOM_QUARK:
			mass = 4.2*1000000000;
			charge[0] = -1;
			charge[1] = 3;
			spin[0] = 1;
			spin[1] = 2;
			name = "Bottom Quark";
			image = new sprite("BottomQuark.bmp");
			primID = 0;
			break;
		case STRANGE_QUARK:
			mass = 104*1000000;
			charge[0] = -1;
			charge[1] = 3;
			spin[0] = 1;
			spin[1] = 2;
			name = "Strange Quark";
			image = new sprite("StrangeQuark.bmp");
			primID = 0;
			break;
		case CHARM_QUARK:
			mass = 1.27*1000000000;
			charge[0] = 2;
			charge[1] = 3;
			spin[0] = 1;
			spin[1] = 2;
			name = "Charm Quark";
			image = new sprite("CharmQuark.bmp");
			primID = 0;
			break;
		case GLUON:
			mass = 0;
			charge[0] = 0;
			charge[1] = 0;
			spin[0] = 1;
			spin[1] = 1;
			name = "Gluon";
			image = new sprite("gluon.bmp");
			primID = 5;
			break;
		case ELECTRON:
			mass = 0.511 * 1000000;
			charge[0] = -1;
			charge[1] = 1;
			spin[0] = 1;
			spin[1] = 2;
			name = "Electron";
			image = new sprite("gluon.bmp");
			primID = 7;
			break;
		case PROTON:
			mass = 938 * 1000000;
			charge[0] = 1;
			charge[1] = 1;
			spin[0] = 1;
			spin[1] = 2;
			name = "Proton";
			image = new sprite("Proton.bmp");
			primID = 11;
			break;
		case NEUTRON:
			mass = 939 * 1000000;
			charge[0] = 0;
			charge[1] = 1;
			spin[0] = 1;
			spin[1] = 2;
			name = "Neutron";
			image = new sprite("Neutron.bmp");
			primID = 13;
			break;
	}
}

particle::~particle(void)
{
}

void particle::Update(int x, int y)
{
	if (IsSelected() == true)
	{
		time = clock();
		SetLocation(x-image->GetWidth()/2, y - image->GetHeight()/2);
	} else {
		MoveUnderForce();
	}
}

void particle::Drag(int x, int y)
{

}

void particle::MoveUnderForce()
{
	float deltaT = ((float)(clock() - time))/CLOCKS_PER_SEC;
	time = clock();
	if (deltaT > 1) {
		deltaT = 1;
	} else if (deltaT == 0) {
		deltaT = 1;
	}


	float xMov = (xVelocity * deltaT) + (0.5 * xForce * deltaT * deltaT);
	float yMov = (yVelocity * deltaT) + (0.5 * yForce * deltaT * deltaT);

	xVelocity = xMov*deltaT;
	yVelocity = yMov*deltaT;

	Move(xMov,yMov);

}

void particle::Move(float deltaX, float deltaY)
{
	image->Move(deltaX, deltaY);
}

bool particle::IsMoving()
{
	if (abs(xVelocity) > 0.0000001 || abs(yVelocity) > 0.0000001)
		return true;
	else
		return false;
}