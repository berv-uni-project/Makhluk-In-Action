#include "MakhlukMaling.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

MakhlukMaling::MakhlukMaling(){
	/*! \var MakhlukMaling()
	\brief Constructor Kelas MakhlukMaling menginisialisasi atribut
	*/
	//cout <<"ctor MakhlukMaling" <<endl;
	age = 40; //normal
	powerlevel = 75; // cukup lemah
	deltaT = 5; // cukup cepat 
	type = 3;
	agenow = 0;
}

MakhlukMaling::MakhlukMaling(int a,int b){
	/* ! \var MakhlukMaling(int a,int b)
	\brief Constructor Parameter Kelas MakhlukMaling
	\param a input posisi untuk x 
	\param b input posisi untuk y
	*/
	//cout <<"ctor MakhlukMaling" <<endl;
	age = 40; //normal
	powerlevel = 75; // cukup lemah
	deltaT = 5; // cukup cepat 
	type = 3;
	x = a;
	y = b;
	agenow = 0;
}

MakhlukMaling::MakhlukMaling(const MakhlukMaling& M){
	/* ! \var MakhlukMaling(const MakhlukMaling& M)
	\brief Copy constructor Kelas MakhlukMaling
	\param M Semua atribut MakhlukMaling akan diisi dengan atribut M yang juga merupakan MakhlukMaling
	*/
	//cout <<"cctor MakhlukMaling" <<endl;
	age = M.age ;
	powerlevel = M.powerlevel ;
	deltaT = M.deltaT ;
	type = M.type;
	agenow = M.agenow;
}

MakhlukMaling::~MakhlukMaling(){
	/* ! \var ~MakhlukMaling()
	\brief Destructor Kelas MakhlukMaling
	*/
	//cout <<"dtor MakhlukMaling" <<endl;
}

MakhlukMaling& MakhlukMaling::operator= (const MakhlukMaling& M ){
	/* ! \var MakhlukMaling& operator=(const MakhlukMaling& M)
	\brief Operator= Kelas MakhlukMaling
	\param M Semua atribut MakhlukMaling akan diisi dengan atribut M yang juga MakhlukMaling
	*/
	//cout <<"operator =  MakhlukMaling" <<endl;
	age = M.age;
	powerlevel = M.powerlevel;
	deltaT = M.deltaT;
	type = M.type;
	agenow = M.agenow;
	return *this;
}

void MakhlukMaling::move(){
	/* ! \var void move()
	\brief Melakukan Perpindahan pada MakhlukMaling dapat semua arah namun pelan delta T besar dan dapat mantul
	\param x Panjang maksimum dari matriks
	\param y Lebar maksimum dari matriks
	*/
	if (deltaT == 0)
	{
		//cout <<"move MakhlukMaling" <<endl;
		int r1, r2;
		srand(time(NULL));
		r1 = rand() % 3 - 1;
		r2 = rand() % 3 - 1;
		x = x + r1;
		y = y + r2;
		agenow++;
		deltaT = 5;
	}
	else
		deltaT--;
}

void MakhlukMaling::dead(){
	/* ! \var void dead()
	\brief Prosedur berisi MakhlukMaling mati
	*/
	//cout <<"dead MakhlukMaling" <<endl;
}
