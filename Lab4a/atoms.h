#pragma once
#include <string>
#include "sprite.h"

class atom
{
public:
	atom(void);
	atom(int AtomicNumber, int Neutrons);
	atom(int AtomicNumber, int Neutrons, LPSTR szFileName);
	atom(int AtomicNumber, int Neutrons, std::string IsotopeName);
	atom(int AtomicNumber, int Neutrons, std::string IsotopeName, LPSTR szFileName);
	~atom(void);
	int AtomicNumber(){return atomicNumber;}
	int Neutrons(){return neutrons;}
	std::string Name(){return name;}
	std::string IsotopeName(){return isotopeName;}
	void Centre(int width);
	void Draw(HDC bitmapHDC, HDC backHDC);

private:
	void Set(int AtomicNumber, int Neutrons);
	void Set(int AtomicNumber, int Neutrons, std::string IsotopeName);
	void SetImage(LPSTR szFileName);

	int frame;

	int atomicNumber;
	int neutrons;
	sprite *image;
	std::string name;
	std::string isotopeName;



};


static atom Atoms[83] ={atom(1,0,"Protium", "hydrogen1.bmp"),
						atom(1,1,"Deuterium", "hydrogen2.bmp"),
						atom(1,2,"Tritium", "hydrogen3.bmp"),
						atom(2,2,"Tralphium", "helium3.bmp"),
						atom(2,3, "helium4.bmp"),
						atom(3,3, "lithium6.bmp"),
						atom(3,4, "lithium7.bmp"),
						atom(4,3, "beryllium7.bmp"),
						atom(4,5, "beryllium9.bmp"),
						atom(4,6, "beryllium10.bmp"),
						atom(5,5, "boron10.bmp"),
						atom(5,6, "boron11.bmp"),
						atom(6,5, "carbon11.bmp"),
						atom(6,6, "carbon12.bmp"),
						atom(6,7, "carbon13.bmp"),
						atom(6,8, "carbon14.bmp"),
						atom(7,6, "nitrogen13.bmp"),
						atom(7,7, "nitrogen14.bmp"),
						atom(7,8, "nitrogen15.bmp"),
						atom(8,8, "oxygen16.bmp"),
						atom(8,9, "oxygen17.bmp"),
						atom(8,10, "oxygen18.bmp"),
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