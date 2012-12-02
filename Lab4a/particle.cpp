#include "particle.h"
#include <string>
#include "sprite.h"
#include <windows.h>
#include <time.h>


particle::particle(type type) :
	xForce(0),
	yForce(0),
	xVelocity(0),
	yVelocity(0),
	particleType(type),
	orbit(0.0)
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
			primID = 13;
			break;
		case DOWN_QUARK:
			mass = 4.8*1000000;
			charge[0] = -1;
			charge[1] = 2;
			spin[0] = 1;
			spin[1] = 2;
			name = "Down Quark";
			image = new sprite("DownQuark.bmp");
			primID = 11;
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
			primID = 7;
			break;
		case ELECTRON:
			mass = 0.511 * 1000000;
			charge[0] = -1;
			charge[1] = 1;
			spin[0] = 1;
			spin[1] = 2;
			name = "Electron";
			image = new sprite("electron.bmp");
			primID = 5;
			break;
		case PROTON:
			mass = 938 * 1000000;
			charge[0] = 1;
			charge[1] = 1;
			spin[0] = 1;
			spin[1] = 2;
			name = "Proton";
			image = new sprite("Proton.bmp");
			primID = 3;
			break;
		case NEUTRON:
			mass = 939 * 1000000;
			charge[0] = 0;
			charge[1] = 1;
			spin[0] = 1;
			spin[1] = 2;
			name = "Neutron";
			image = new sprite("Neutron.bmp");
			primID = 2;
			break;
	}
}

particle::~particle(void)
{
}

void particle::Update(int x, int y)
{
	if (IsSelected() == true) {
		time = clock();
		SetLocation(x-image->GetWidth()/2, y - image->GetHeight()/2);
	} else {
		MoveUnderForce();
	}
}

void particle::Drag(int x, int y)
{
	if (selected == true) {
		SetLocation(x,y);
	}
}

void particle::MoveUnderForce()
{
	float deltaT;
	if (particleType == ELECTRON) {
		deltaT = 100*((float)(clock() - time))/CLOCKS_PER_SEC;
	} else {
		deltaT = ((float)(clock() - time))/CLOCKS_PER_SEC;
	}
	time = clock();
	if (deltaT > 1) {
		deltaT = 1;
	} else if (deltaT == 0) {
		deltaT = 1;
	}
	float xMov;
	float yMov;




	if (particleType == ELECTRON) {
		xMov = (xVelocity * deltaT) + (0.5 * xForce * deltaT * deltaT);
		yMov = (yVelocity * deltaT) + (0.5 * yForce * deltaT * deltaT);
	} else {
		xMov = (xVelocity * deltaT) + (0.5 * xForce * 100000 * deltaT * deltaT);
		yMov = (yVelocity * deltaT) + (0.5 * yForce * 100000 * deltaT * deltaT);
	}

	xVelocity = xMov*deltaT;
	yVelocity = yMov*deltaT;

	Move(xMov,yMov);

}

void particle::Move(float deltaX, float deltaY)
{
	if (image->GetX() + deltaX > 0 && image->GetX() + deltaX < (screenX-image->GetWidth())) {
		image->Move(deltaX, 0);
	} else if (image->GetX() + deltaX <= 0 && deltaX > 0) {
		image->Move(deltaX, 0);
	} else if (image->GetX() + deltaX >= (screenX-image->GetWidth()) && deltaX < 0) {
		image->Move(deltaX,0);
	}
	if (image->GetY() + deltaY > 0 && image->GetY() + deltaY < (screenY - image->GetHeight())) {
		image->Move(0, deltaY);
	} else if (image->GetY() + deltaY <= 0 && deltaY > 0) {
		image->Move(0, deltaY);
	} else if (image->GetY() + deltaY >= (screenY-image->GetHeight()) && deltaY < 0) {
		image->Move(0,deltaY);
	}
}

void particle::OrbitAt(int radius, int x, int y)
{
	if (orbit > 360)
		orbit = 1.0;

	SetLocation(radius*sin((orbit*(2*3.1415))/360) + x - image->GetWidth()/2, radius*cos((orbit*(2*3.1415))/360) + y - image->GetHeight()/2);
	orbit+= 0.2;

}

void particle::Draw(HDC bitmapHDC, HDC backHDC, int ParticleNumber)
{
	if (ParticleNumber > 10) {
		ParticleNumber = 10;
	}
	float scaleFactor = 4.0/(ParticleNumber + 3.0);

	image->Draw(bitmapHDC, backHDC, scaleFactor);
}

void particle::SetScreenSize(int x, int y)
{
	screenX = x;
	screenY = y;
}

bool particle::IsMoving()
{
	if (abs(xVelocity) > 0.01 || abs(yVelocity) > 0.01)
		return true;
	else
		return false;
}

void particle::AnimatedCreation()
{
	image->SetAnimated();

}

bool particle::OnClick(int x, int y)
{
	if (image->OnClick(x, y)) {
		selected = true;
		return true;
	} else {
		selected = false;
		return false;
	}

}