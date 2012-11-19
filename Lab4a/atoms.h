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


static atom Atoms[83] ={atom(1,0,"Protium"),
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
						atom(8,10),
						atom(9,9),
						atom(9,10),
						atom(10,10),
						atom(10,11),
						atom(10,12),
						atom(11,11),
						atom(11,12),
						atom(12,12),
						atom(12,13),
						atom(12,14),
						atom(13,13),
						atom(13,14),
						atom(14,14),
						atom(14,15),
						atom(14,16),
						atom(14,18),
						atom(15,16),
						atom(15,17),
						atom(15,18),
						atom(16,16),
						atom(16,17),
						atom(16,18),
						atom(16,19),
						atom(16,20),
						atom(17,18),
						atom(17,19),
						atom(17,20),
						atom(18,18),
						atom(18,19),
						atom(18,20),
						atom(18,21),
						atom(18,22),
						atom(18,23),
						atom(18,24),
						atom(19,20),
						atom(19,21),
						atom(19,22),
						atom(20,20),
						atom(20,21),
						atom(20,22),
						atom(20,23),
						atom(20,24),
						atom(20,25),
						atom(20,26),
						atom(20,27),
						atom(20,28),
						atom(21,23),
						atom(21,24),
						atom(21,25),
						atom(21,26),
						atom(21,27),
						atom(22,22),
						atom(22,24),
						atom(22,25),
						atom(22,26),
						atom(22,27),
						atom(22,28),
						atom(23,25),
						atom(23,26),
						atom(23,27),
						atom(23,28)};