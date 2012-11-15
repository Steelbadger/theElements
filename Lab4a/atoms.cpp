#include "atoms.h"


atom::atom(void)
{
}

atom::atom(int AtomicNumber, int Neutrons)
{
	Set(AtomicNumber, Neutrons);
}
atom::atom(int AtomicNumber, int Neutrons, std::string IsotopeName)
{
	Set(AtomicNumber, Neutrons, IsotopeName);
}

atom::~atom(void)
{
}

void atom::Set(int AtomicNumber, int Neutrons)
{
	atomicNumber = AtomicNumber;
	neutrons = Neutrons;
	switch(AtomicNumber) {
		case 1:
			name = "Hydrogen";
			break;
		case 2:
			name = "Helium";
			break;
		case 3:
			name = "Lithium";
			break;
		case 4:
			name = "Beryllium";
			break;
		case 5:
			name = "Boron";
			break;
		case 6:
			name = "Carbon";
			break;
		case 7:
			name = "Nitrogen";
			break;
		case 8:
			name = "Oxygen";
			break;

	}
}

void atom::Set(int AtomicNumber, int Neutrons, std::string IsotopeName)
{
	Set(AtomicNumber, Neutrons);
	isotopeName = IsotopeName;
}
