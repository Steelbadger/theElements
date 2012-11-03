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


particle::particle(type particleType)
{
	switch (particleType)
	{
		case UP_QUARK:
			mass = 2.4*1000000;
			charge[0] = 2;
			charge[1] = 3;
			spin[0] = 1;
			spin[1] = 2;
			name = "Up Quark";
			image = new sprite("UpQuark.bmp");
			break;
		case DOWN_QUARK:
			mass = 4.8*1000000;
			charge[0] = -1;
			charge[1] = 2;
			spin[0] = 1;
			spin[1] = 2;
			name = "Down Quark";
			image = new sprite("DownQuark.bmp");
			break;
		case TOP_QUARK:
			mass = 171.2*1000000000;
			charge[0] = 2;
			charge[2] = 3;
			spin[0] = 1;
			spin[1] = 2;
			name = "Top Quark";
			image = new sprite("TopQuark.bmp");
			break;
		case BOTTOM_QUARK:
			mass = 4.2*1000000000;
			charge[0] = -1;
			charge[1] = 3;
			spin[0] = 1;
			spin[1] = 2;
			name = "Bottom Quark";
			image = new sprite("BottomQuark.bmp");
			break;
		case STRANGE_QUARK:
			mass = 104*1000000;
			charge[0] = -1;
			charge[1] = 3;
			spin[0] = 1;
			spin[1] = 2;
			name = "Strange Quark";
			image = new sprite("StrangeQuark.bmp");
			break;
		case CHARM_QUARK:
			mass = 1.27*1000000000;
			charge[0] = 2;
			charge[1] = 3;
			spin[0] = 1;
			spin[1] = 2;
			name = "Charm Quark";
			image = new sprite("CharmQuark.bmp");
			break;
		case GLUON:
			mass = 0;
			charge[0] = 0;
			charge[1] = 0;
			spin[0] = 1;
			spin[1] = 1;
			name = "Gluon";
			image = new sprite("gluon.bmp");
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
		SetLocation(x, y);
	} else {

	}
}

void particle::Drag(int x, int y)
{

}