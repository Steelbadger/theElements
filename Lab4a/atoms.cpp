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
		case 9:
			name = "Flourine";
			break;
		case 10:
			name = "Neon";
			break;
		case 11:
			name = "Sodium";
			break;
		case 12:
			name = "Magnesium";
			break;
		case 13:
			name = "Aluminium";
			break;
		case 14:
			name = "Silicon";
			break;
		case 15:
			name = "Phosphorus";
			break;
		case 16:
			name = "Sulfur";
			break;
		case 17:
			name = "Chlorine";
			break;
		case 18:
			name = "Argon";
			break;
		case 19:
			name = "Potassium";
			break;
		case 20:
			name = "Calcium";
			break;
		case 21:
			name = "Scandium";
			break;
		case 22:
			name = "Titanium";
			break;
		case 23:
			name = "Vanadium";
			break;


	}
}

void atom::Set(int AtomicNumber, int Neutrons, std::string IsotopeName)
{
	Set(AtomicNumber, Neutrons);
	isotopeName = IsotopeName;
}
