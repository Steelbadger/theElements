#pragma once
#include <string>

class atom
{
public:
	atom(void);
	atom(int AtomicNumber, int Neutrons);
	atom(int AtomicNumber, int Neutrons, std::string IsotopeName);
	~atom(void);
	void Set(int AtomicNumber, int Neutrons);
	void Set(int AtomicNumber, int Neutrons, std::string IsotopeName);
	int AtomicNumber(){return atomicNumber;}
	int Neutrons(){return neutrons;}
	std::string Name(){return name;}
	std::string IsotopeName(){return isotopeName;}

private:
	int atomicNumber;
	int neutrons;
	std::string name;
	std::string isotopeName;



};


static atom Atoms[22] ={atom(1,0,"Protium"),
						atom(1,1,"Deuterium"),
						atom(1,2,"Tritium"),
						atom(2,2,"Tralphium"),
						atom(2,3),
						atom(3,3),
						atom(3,4),
						atom(4,3),
						atom(4,5),
						atom(4,6),
						atom(5,5),
						atom(5,6),
						atom(6,5),
						atom(6,6),
						atom(6,7),
						atom(6,8),
						atom(7,6),
						atom(7,7),
						atom(7,8),
						atom(8,8),
						atom(8,9),
						atom(8,10)};