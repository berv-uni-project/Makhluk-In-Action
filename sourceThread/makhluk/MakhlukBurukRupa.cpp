#include "MakhlukBurukRupa.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

MakhlukBurukRupa::MakhlukBurukRupa(){
	/*! \var MakhlukBurukRupa()
	\brief Constructor Kelas MakhlukBurukRupa menginisialisasi atribut
	*/
	//cout <<"ctor MakhlukBurukRupa" <<endl;
	age = 80; // lambat mati 
	powerlevel = 80; //normal
	deltaT = 7; //cukup lambat
	type = 2;
	agenow = 0;
}

MakhlukBurukRupa::MakhlukBurukRupa(int a,int b){
	/* ! \var MakhlukBurukRupa(int a,int b)
	\brief Constructor Parameter Kelas MakhlukBurukRupa
	\param a input posisi untuk x 
	\param b input posisi untuk y
	*/
	//cout <<"ctor MakhlukBurukRupa" <<endl;
	age = 80; // lambat mati 
	powerlevel = 80; //normal
	deltaT = 7; //cukup lambat
	type = 2;
	agenow = 0;
	x = a;
	y = b;
}

MakhlukBurukRupa::MakhlukBurukRupa(const MakhlukBurukRupa& M){
	/* ! \var MakhlukBurukRupa(const MakhlukBurukRupa& M)
	\brief Copy constructor Kelas MakhlukBurukRupa
	\param M Semua atribut MakhlukBurukRupa akan diisi dengan atribut M yang juga merupakan MakhlukBurukRupa
	*/
	//cout <<"cctor MakhlukBurukRupa" <<endl;
	age = M.age ;
	powerlevel = M.powerlevel ;
	deltaT = M.deltaT ;
	type = M.type;
	agenow = M.agenow;
}

MakhlukBurukRupa::~MakhlukBurukRupa(){
	/* ! \var ~MakhlukBurukRupa()
	\brief Destructor Kelas MakhlukBurukRupa
	*/
	//cout <<"dtor MakhlukBurukRupa" <<endl;
}

MakhlukBurukRupa& MakhlukBurukRupa::operator= (const MakhlukBurukRupa& M ){
	/* ! \var MakhlukBurukRupa& operator=(const MakhlukBurukRupa& M)
	\brief Operator= Kelas MakhlukBurukRupa
	\param M Semua atribut MakhlukBurukRupa akan diisi dengan atribut M yang juga MakhlukBurukRupa
	*/
	//cout <<"operator =  MakhlukBurukRupa" <<endl;
	age = M.age;
	powerlevel = M.powerlevel;
	deltaT = M.deltaT;
	type = M.type;
	agenow = M.agenow;
	return *this;
}

void MakhlukBurukRupa::move(){
	/* ! \var void move()
	\brief Melakukan Perpindahan pada MakhlukBurukRupa, gerakannya terbatas hanya atas bawah namun dapat menembus layar 
	\param x Panjang maksimum dari matriks
	\param y Lebar maksimum dari matriks
	*/
	if (deltaT == 0)
	{
		//cout <<"move MakhlukBurukRupa" <<endl;
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

void MakhlukBurukRupa::dead(){
	/* ! \var void dead()
	\brief Prosedur berisi MakhlukBurukRupa mati
	*/
	//cout <<"dead MakhlukBurukRupa" <<endl;
}
