#include "MakhlukTerbang.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

MakhlukTerbang::MakhlukTerbang(){
	/*! \var MakhlukTerbang()
	\brief Constructor Kelas MakhlukTerbang menginisialisasi atribut
	*/
	//cout <<"ctor MakhlukTerbang" <<endl;
	age = 30; // cepat mati
	powerlevel = 70; //agak lemah
	deltaT = 3; //cepat
	type = 5;
	agenow = 0;
}

MakhlukTerbang::MakhlukTerbang(int a,int b){
	/* ! \var MakhlukTerbang(int a,int b)
	\brief Constructor Parameter Kelas MakhlukTerbang
	\param a input posisi untuk x 
	\param b input posisi untuk y
	*/
	//cout <<"ctor MakhlukTerbang" <<endl;
	age = 30; // cepat mati
	powerlevel = 70; //agak lemah
	deltaT = 3; //cepat
	x = a;
	y = b;
	type = 5;
	agenow = 0;
}

MakhlukTerbang::MakhlukTerbang(const MakhlukTerbang& M){
	/* ! \var MakhlukTerbang(const MakhlukTerbang& M)
	\brief Copy constructor Kelas MakhlukTerbang
	\param M Semua atribut MakhlukTerbang akan diisi dengan atribut M yang juga merupakan MakhlukTerbang
	*/
	//cout <<"cctor MakhlukTerbang" <<endl;
	age = M.age ;
	powerlevel = M.powerlevel ;
	deltaT = M.deltaT ;
	type = M.type;
	agenow = M.agenow;
}

MakhlukTerbang::~MakhlukTerbang(){
	/* ! \var ~MakhlukTerbang()
	\brief Destructor Kelas MakhlukTerbang
	*/
	//cout <<"dtor MakhlukTerbang" <<endl;
}

MakhlukTerbang& MakhlukTerbang::operator= (const MakhlukTerbang& M ){
	/*! \var MakhlukTerbang& operator= (const MakhlukTerbang& M)
	\brief operator = dari kelas MakhlukTerbang
	\param M Semua atribut MakhlukTerbang akan diisi dengan atribut M yang juga MakhlukTerbang
	*/
	//cout <<"operator =  MakhlukTerbang" <<endl;
	age = M.age;
	powerlevel = M.powerlevel;
	deltaT = M.deltaT;
	type = M.type;
	agenow = M.agenow;
	return *this;
}

void MakhlukTerbang::move(){
	/* ! \var void move()
	\brief Melakukan Perpindahan pada MakhlukTerbang tidak dibatasi namun jika keluar layar mati 
	\param x Panjang maksimum dari matriks
	\param y Lebar maksimum dari matriks
	*/
	if (deltaT == 0)
	{
		//cout <<"move MakhlukTerbang" <<endl;
		int r1, r2;
		srand(time(NULL));
		r1 = rand() % 3 - 1;
		r2 = rand() % 3 - 1;
		x = x + r1;
		y = y + r2;
		agenow++;
		deltaT = 3;
	}
	else
		deltaT--;
}

void MakhlukTerbang::dead(){
	/* ! \var void dead()
	\brief Prosedur berisi MakhlukTerbang mati
	*/
	//cout <<"dead MakhlukTerbang" <<endl;
}
