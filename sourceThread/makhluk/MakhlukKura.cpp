#include "MakhlukKura.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
/* Makhluk Anti Air bentuknya '*' */

MakhlukKura::MakhlukKura(){
	/*! \var MakhlukKura()
	\brief Constructor Kelas MakhlukKura menginisialisasi atribut
	*/
	age = 90;
	powerlevel = 100;
	deltaT = 12; 
	type = 12;
	agenow = 0;

}

MakhlukKura::MakhlukKura(int a,int b){
	/* ! \var MakhlukKura(int a,int b)
	\brief Constructor Parameter Kelas MakhlukKura
	\param a input posisi untuk x 
	\param b input posisi untuk y
	*/
	age = 90;
	powerlevel = 100;
	deltaT = 12; 
	type = 12;
	agenow = 0;
	x = a;
	y = b;
}

MakhlukKura::MakhlukKura(const MakhlukKura& M){
	/* ! \var MakhlukKura(const MakhlukKura& M)
	\brief Copy constructor Kelas MakhlukKura
	\param M Semua atribut MakhlukKura akan diisi dengan atribut M yang juga merupakan MakhlukKura
	*/
	//cout <<"cctor MakhlukKura" <<endl;
	age = M.age ;
	powerlevel = M.powerlevel ;
	deltaT = M.deltaT ;
	type = M.type;
	agenow = M.agenow;
}

MakhlukKura::~MakhlukKura(){
	/* ! \var ~MakhlukKura()
	\brief Destructor Kelas MakhlukKura
	*/
	//cout <<"dtor MakhlukKura" <<endl;
}

MakhlukKura& MakhlukKura::operator= (const MakhlukKura& M ){
	/* ! \var MakhlukKura& operator=(const MakhlukKura& M)
	\brief Operator= Kelas MakhlukKura
	\param M Semua atribut MakhlukKura akan diisi dengan atribut M yang juga MakhlukKura
	*/
	age = M.age;
	powerlevel = M.powerlevel;
	deltaT = M.deltaT;
	type = M.type;
	agenow = M.agenow;
	return *this;
}

void MakhlukKura::move(){
	/* ! \var void move()
	\brief Melakukan Perpindahan pada MakhlukKura, gerakan terbatas hanya diagonal namun dapat mantul 
	\param x Panjang maksimum dari matriks
	\param y Lebar maksimum dari matriks
	*/
	if (deltaT == 0)
	{
		int r1 = 0;
		r1 = rand() % 2;
		y = y + r1;
		agenow++;
		deltaT = 12;
	}
	else
		deltaT--;
}

void MakhlukKura::dead(){
	/* ! \var void dead()
	\brief Prosedur berisi MakhlukKura mati
	*/
	//cout <<"dead MakhlukKura" <<endl;
}
