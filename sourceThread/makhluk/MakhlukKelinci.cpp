#include "MakhlukKelinci.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
/* Makhluk Anti Air bentuknya '*' */

MakhlukKelinci::MakhlukKelinci(){
	/*! \var MakhlukKelinci()
	\brief Constructor Kelas MakhlukKelinci menginisialisasi atribut
	*/
	age = 50;
	powerlevel = 75;
	deltaT = 3; 
	type = 11;
	agenow = 0;

}

MakhlukKelinci::MakhlukKelinci(int a,int b){
	/* ! \var MakhlukKelinci(int a,int b)
	\brief Constructor Parameter Kelas MakhlukKelinci
	\param a input posisi untuk x 
	\param b input posisi untuk y
	*/
	age = 90;
	powerlevel = 75; 
	deltaT = 3;  
	type = 11;
	agenow = 0;
	x = a;
	y = b;
}

MakhlukKelinci::MakhlukKelinci(const MakhlukKelinci& M){
	/* ! \var MakhlukKelinci(const MakhlukKelinci& M)
	\brief Copy constructor Kelas MakhlukKelinci
	\param M Semua atribut MakhlukKelinci akan diisi dengan atribut M yang juga merupakan MakhlukKelinci
	*/
	//cout <<"cctor MakhlukKelinci" <<endl;
	age = M.age ;
	powerlevel = M.powerlevel ;
	deltaT = M.deltaT ;
	type = M.type;
	agenow = M.agenow;
}

MakhlukKelinci::~MakhlukKelinci(){
	/* ! \var ~MakhlukKelinci()
	\brief Destructor Kelas MakhlukKelinci
	*/
	//cout <<"dtor MakhlukKelinci" <<endl;
}

MakhlukKelinci& MakhlukKelinci::operator= (const MakhlukKelinci& M ){
	/* ! \var MakhlukKelinci& operator=(const MakhlukKelinci& M)
	\brief Operator= Kelas MakhlukKelinci
	\param M Semua atribut MakhlukKelinci akan diisi dengan atribut M yang juga MakhlukKelinci
	*/
	age = M.age;
	powerlevel = M.powerlevel;
	deltaT = M.deltaT;
	type = M.type;
	agenow = M.agenow;
	return *this;
}

void MakhlukKelinci::move(){
	/* ! \var void move()
	\brief Melakukan Perpindahan pada MakhlukKelinci, gerakan terbatas hanya diagonal namun dapat mantul 
	\param x Panjang maksimum dari matriks
	\param y Lebar maksimum dari matriks
	*/
	if (deltaT == 0)
	{
		int r1 = 0;
		r1 = rand() % 2;
		y = y + r1;
		agenow++;
		deltaT = 3;
	}
	else
		deltaT--;
}

void MakhlukKelinci::dead(){
	/* ! \var void dead()
	\brief Prosedur berisi MakhlukKelinci mati
	*/
	//cout <<"dead MakhlukKelinci" <<endl;
}
