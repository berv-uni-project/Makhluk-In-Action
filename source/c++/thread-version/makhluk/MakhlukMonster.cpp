#include "MakhlukMonster.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
//PIC Unit Test : Joshua Salimin 13514001
//Dibuat oleh : Joshua Salimin

MakhlukMonster::MakhlukMonster(){
	/*! \var MakhlukMonster()
	*\brief Constructor Kelas MakhlukMonster menginisialisasi atribut
	*/
	age = 60; // lambat mati
	powerlevel = 100; //paling kuat
	deltaT = 10; //lambat
	type = 4;
	agenow = 0;
}

MakhlukMonster::MakhlukMonster(int a,int b){
	/*! \var MakhlukMonster(int a,int b)
	*\brief Constructor Parameter Kelas MakhlukMonster
	*\param a input posisi untuk x 
	*\param b input posisi untuk y
	*/
	age = 60; // lambat mati
	powerlevel = 100; //paling kuat
	deltaT = 10; //lambat
	type = 4;
	agenow = 0;
	x = a;
	y = b;
}

MakhlukMonster::MakhlukMonster(const MakhlukMonster& M){
	/*! \var MakhlukMonster(const MakhlukMonster& M)
	*\brief Copy constructor Kelas MakhlukMonster
	*\param M Semua atribut MakhlukMonster akan diisi dengan atribut M yang juga merupakan MakhlukMonster
	*/
	age = M.age ;
	powerlevel = M.powerlevel ;
	deltaT = M.deltaT ;
	type = M.type;
	agenow = M.agenow;
}

MakhlukMonster::~MakhlukMonster(){
	/*! \var ~MakhlukMonster()
	*\brief Destructor Kelas MakhlukMonster
	*/
}

MakhlukMonster& MakhlukMonster::operator= (const MakhlukMonster& M ){
	/*! \var MakhlukMonster& operator= (const MakhlukMonster& M)
	*\brief operator = dari kelas MakhlukMonster
	*\param M Semua atribut MakhlukMonster akan diisi dengan atribut M yang juga MakhlukMonster
	*/
	age = M.age;
	powerlevel = M.powerlevel;
	deltaT = M.deltaT;
	type = M.type;
	agenow = M.agenow;
	return *this;
}

void MakhlukMonster::move(){
	/*! \var void move()
	*\brief Melakukan Perpindahan pada MakhlukMonster dibatasi hanya bisa kanan dan kiri namun dapat mantul
	*\param x Panjang maksimum dari matriks
	*\param y Lebar maksimum dari matriks
	*/
	if (deltaT == 0)
	{
		int r1, r2;
		srand(time(NULL));
		r1 = rand() % 3 - 1;
		x = x + r1;
		agenow++;
		deltaT = 10;
	}
	else
		deltaT--;
}

void MakhlukMonster::dead(){
	/*! \var void dead()
	*\brief Prosedur berisi MakhlukMonster mati
	*/
}
