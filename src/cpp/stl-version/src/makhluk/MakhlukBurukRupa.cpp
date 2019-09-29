#include "MakhlukBurukRupa.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
//PIC Unit Test : Joshua Salimin 13514001
//Dibuat oleh : Joshua Salimin

MakhlukBurukRupa::MakhlukBurukRupa()
{
	/*! \var MakhlukBurukRupa()
	*\brief Constructor Kelas MakhlukBurukRupa menginisialisasi atribut
	*/
	age = 80;				 // lambat mati
	powerlevel = 80; //normal
	deltaT = 7;			 //cukup lambat
	type = 2;
	agenow = 0;
}

MakhlukBurukRupa::MakhlukBurukRupa(int a, int b)
{
	/*! \var MakhlukBurukRupa(int a,int b)
	*\brief Constructor Parameter Kelas MakhlukBurukRupa
	*\param a input posisi untuk x 
	*\param b input posisi untuk y
	*/
	age = 80;				 // lambat mati
	powerlevel = 80; //normal
	deltaT = 7;			 //cukup lambat
	type = 2;
	agenow = 0;
	x = a;
	y = b;
}

MakhlukBurukRupa::MakhlukBurukRupa(const MakhlukBurukRupa &M)
{
	/*! \var MakhlukBurukRupa(const MakhlukBurukRupa& M)
	*\brief Copy constructor Kelas MakhlukBurukRupa
	*\param M Semua atribut MakhlukBurukRupa akan diisi dengan atribut M yang juga merupakan MakhlukBurukRupa
	*/
	age = M.age;
	powerlevel = M.powerlevel;
	deltaT = M.deltaT;
	type = M.type;
	agenow = M.agenow;
}

MakhlukBurukRupa::~MakhlukBurukRupa()
{
	/*! \var ~MakhlukBurukRupa()
	*\brief Destructor Kelas MakhlukBurukRupa
	*/
}

MakhlukBurukRupa &MakhlukBurukRupa::operator=(const MakhlukBurukRupa &M)
{
	/*! \var MakhlukBurukRupa& operator=(const MakhlukBurukRupa& M)
	*\brief Operator= Kelas MakhlukBurukRupa
	*\param M Semua atribut MakhlukBurukRupa akan diisi dengan atribut M yang juga MakhlukBurukRupa
	*/
	age = M.age;
	powerlevel = M.powerlevel;
	deltaT = M.deltaT;
	type = M.type;
	agenow = M.agenow;
	return *this;
}

void MakhlukBurukRupa::move()
{
	/*! \var void move()
	*\brief Melakukan Perpindahan pada MakhlukBurukRupa, gerakannya terbatas hanya atas bawah namun dapat menembus layar 
	*\param x Panjang maksimum dari matriks
	*\param y Lebar maksimum dari matriks
	*/
	if (deltaT == 0)
	{
		int r1;
		srand(time(NULL));
		r1 = rand() % 3 - 1;
		y = y + r1;
		agenow++;
		deltaT = 7;
	}
	else
		deltaT--;
}

void MakhlukBurukRupa::dead()
{
	/*! \var void dead()
	*\brief Prosedur berisi MakhlukBurukRupa mati
	*/
}
