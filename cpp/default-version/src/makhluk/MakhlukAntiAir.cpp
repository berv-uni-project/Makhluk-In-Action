//PIC Unit Test : Joshua Salimin 13514001
//Dibuat oleh : Joshua Salimin

#include "MakhlukAntiAir.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
/* Makhluk Anti Air bentuknya '*' */

MakhlukAntiAir::MakhlukAntiAir()
{
	/*! \var MakhlukAntiAir()
	*\brief Constructor Kelas MakhlukAntiAir menginisialisasi atribut
	*/
	age = 90;				 //lambat mati
	powerlevel = 60; //cukup lemah
	deltaT = 8;			 //cukup lambat
	type = 1;
	agenow = 0;
}

MakhlukAntiAir::MakhlukAntiAir(int a, int b)
{
	/*! \var MakhlukAntiAir(int a,int b)
	*\brief Constructor Parameter Kelas MakhlukAntiAir
	*\param a input posisi untuk x 
	*\param b input posisi untuk y
	*/
	age = 90;				 //lambat mati
	powerlevel = 60; //cukup lemah
	deltaT = 8;			 //cukup lambat
	type = 1;
	agenow = 0;
	x = a;
	y = b;
}

MakhlukAntiAir::MakhlukAntiAir(const MakhlukAntiAir &M)
{
	/*! \var MakhlukAntiAir(const MakhlukAntiAir& M)
	*\brief Copy constructor Kelas MakhlukAntiAir
	*\param M Semua atribut MakhlukAntiAir akan diisi dengan atribut M yang juga merupakan MakhlukAntiAir
	*/
	age = M.age;
	powerlevel = M.powerlevel;
	deltaT = M.deltaT;
	type = M.type;
	agenow = M.agenow;
}

MakhlukAntiAir::~MakhlukAntiAir()
{
	/*! \var ~MakhlukAntiAir()
	*\brief Destructor Kelas MakhlukAntiAir
	*/
}

MakhlukAntiAir &MakhlukAntiAir::operator=(const MakhlukAntiAir &M)
{
	/*! \var MakhlukAntiAir& operator=(const MakhlukAntiAir& M)
	*\brief Operator= Kelas MakhlukAntiAir
	*\param M Semua atribut MakhlukAntiAir akan diisi dengan atribut M yang juga MakhlukAntiAir
	*/
	age = M.age;
	powerlevel = M.powerlevel;
	deltaT = M.deltaT;
	type = M.type;
	agenow = M.agenow;
	return *this;
}

void MakhlukAntiAir::move()
{
	/*! \var void move()
	*\brief Melakukan Perpindahan pada MakhlukAntiAir, gerakan terbatas hanya diagonal namun dapat mantul 
	*\param x Panjang maksimum dari matriks
	*\param y Lebar maksimum dari matriks
	*/
	if (deltaT == 0)
	{
		int r1 = 0, r2 = 0;
		srand(time(NULL));
		while (r1 == 0 || r2 == 0)
		{
			r1 = rand() % 3 - 1;
			r2 = rand() % 3 - 1;
		}
		x = x + r1;
		y = y + r2;
		agenow++;
		deltaT = 8;
	}
	else
		deltaT--;
}

void MakhlukAntiAir::dead()
{
	/*! \var void dead()
	*\brief Prosedur berisi MakhlukAntiAir mati
	*/
}
