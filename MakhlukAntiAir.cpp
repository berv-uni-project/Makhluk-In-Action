#include "MakhlukAntiAir.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
/* Makhluk Anti Air bentuknya '*' */

MakhlukAntiAir::MakhlukAntiAir(){
	/*! \var MakhlukAntiAir()
	\brief Constructor Kelas MakhlukAntiAir menginisialisasi atribut
	*/
	cout <<"ctor MakhlukAntiAir" <<endl;
	age = 90; //lambat mati
	powerlevel = 60; //cukup lemah
	deltaT = 0.8;  //cukup lambat
	type = 1;
}

MakhlukAntiAir::MakhlukAntiAir(int a,int b){
	/* ! \var MakhlukAntiAir(int a,int b)
	\brief Constructor Parameter Kelas MakhlukAntiAir
	\param a input posisi untuk x 
	\param b input posisi untuk y
	*/
	cout <<"ctor MakhlukAntiAir" <<endl;
	age = 90; //lambat mati
	powerlevel = 60; //cukup lemah
	deltaT = 0.8;  //cukup lambat
	type = 1;
	x = a;
	y = b;
}

MakhlukAntiAir::MakhlukAntiAir(const MakhlukAntiAir& M){
	/* ! \var MakhlukAntiAir(const MakhlukAntiAir& M)
	\brief Copy constructor Kelas MakhlukAntiAir
	\param M Semua atribut MakhlukAntiAir akan diisi dengan atribut M yang juga merupakan MakhlukAntiAir
	*/
	cout <<"cctor MakhlukAntiAir" <<endl;
	age = M.age ;
	powerlevel = M.powerlevel ;
	deltaT = M.deltaT ;
	type = M.type;
}

MakhlukAntiAir::~MakhlukAntiAir(){
	/* ! \var ~MakhlukAntiAir()
	\brief Destructor Kelas MakhlukAntiAir
	*/
	cout <<"dtor MakhlukAntiAir" <<endl;
}

MakhlukAntiAir& MakhlukAntiAir::operator= (const MakhlukAntiAir& M ){
	/* ! \var MakhlukAntiAir& operator=(const MakhlukAntiAir& M)
	\brief Operator= Kelas MakhlukAntiAir
	\param M Semua atribut MakhlukAntiAir akan diisi dengan atribut M yang juga MakhlukAntiAir
	*/
	cout <<"operator =  MakhlukAntiAir" <<endl;
	age = M.age;
	powerlevel = M.powerlevel;
	deltaT = M.deltaT;
	type = M.type;
	return *this;
}

void MakhlukAntiAir::spawn(int a, int b){
	/* ! \var void spawn(int a,int b)
	\brief spawn mengisi nilai x dan y dimana nilai a dan b berasal dari petak yang di random
	\param a merupakan angka random dari kelas petak untuk x
	\param b merupakan angka random dari kelas petak untuk y
	*/
	cout <<"spawn MakhlukAntiAir" <<endl;
	x = a;
	y = b;
}

void MakhlukAntiAir::move(){
	/* ! \var void move()
	\brief Melakukan Perpindahan pada MakhlukAntiAir 
	*/
	cout <<"move MakhlukAntiAir" <<endl;
	int r1,r2;
	srand(time(NULL));
	r1= rand() % 3 -1  ;
	r2= rand() % 3 -1 ;
	x = x + r1;
	y = y + r2;		
}

void MakhlukAntiAir::dead(){
	/* ! \var void dead()
	\brief Prosedur berisi MakhlukAntiAir mati
	*/
	cout <<"dead MakhlukAntiAir" <<endl;
}
