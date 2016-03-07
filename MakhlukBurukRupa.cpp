#include "MakhlukBurukRupa.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

MakhlukBurukRupa::MakhlukBurukRupa(){
	/*! \var MakhlukBurukRupa()
	\brief constructor dari kelas MakhlukBurukRupa
	Belum pasti
	*/
	cout <<"ctor MakhlukBurukRupa" <<endl;
	age = 50;
	powerlevel = 100;
	deltaT = 10.0; 
}

MakhlukBurukRupa::MakhlukBurukRupa(int a,int b){
	/*! \var MakhlukBurukRupa(int a,int b)
	\brief constructor dari kelas MakhlukBurukRupa
	Belum pasti
	\param a ini apa dah
	\param b ini apa dah
	*/
	cout <<"ctor MakhlukBurukRupa" <<endl;
	age = 50;
	powerlevel = 100;
	deltaT = 10.0; 
	x = a;
	y = b;
}

MakhlukBurukRupa::MakhlukBurukRupa(const MakhlukBurukRupa& M){
	/*! \var MakhlukBurukRupa(const MakhlukBurukRupa& M)
	\brief copy constructor dari kelas MakhlukBurukRupa
	\param M Semua atribut MakhlukBurukRupa akan diisi dengan atribut M yang juga MakhlukBurukRupa
	*/
	cout <<"cctor MakhlukBurukRupa" <<endl;
	age = M.age ;
	powerlevel = M.powerlevel ;
	deltaT = M.deltaT ;
}

MakhlukBurukRupa::~MakhlukBurukRupa(){
	/*! \var ~MakhlukBurukRupa()
	\brief destructor dari kelas MakhlukBurukRupa
	*/
	cout <<"dtor MakhlukBurukRupa" <<endl;
}

MakhlukBurukRupa& MakhlukBurukRupa::operator= (const MakhlukBurukRupa& M ){
	/*! \var MakhlukBurukRupa& operator= (const MakhlukBurukRupa& M)
	\brief operator = dari kelas MakhlukBurukRupa
	\param M Semua atribut MakhlukBurukRupa akan diisi dengan atribut M yang juga MakhlukBurukRupa
	*/
	cout <<"operator =  MakhlukBurukRupa" <<endl;
	age = M.age;
	powerlevel = M.powerlevel;
	deltaT = M.deltaT;
	return *this;
}

void MakhlukBurukRupa::spawn(int a, int b){
	/*! \var void spawn(int a,int b)
	\brief spawn mengisi nilai x dan y 
	* dimana nilai a dan b berasal dari petak
	* yang di random
	\param a merupakan angka random dari kelas petak untuk x
	\param b merupakan angka random dari kelas petak untuk y
	*/
	cout <<"spawn MakhlukBurukRupa" <<endl;
	x = a;
	y = b;
}

void MakhlukBurukRupa::move(){
	/*! \var void move()
	\brief Melakukan Perpindahan pada 
	* MakhlukBurukRupa ~ belum pasti
	\param a merupakan angka random dari kelas petak untuk x
	\param b merupakan angka random dari kelas petak untuk y
	*/
	cout <<"move MakhlukBurukRupa" <<endl;
	int r1,r2;
	int x,y = 0;
	srand(time(NULL));
	r1= rand() % 3 -1  ;
	srand(1);
	r2= rand() % 3 -1 ;
	x = x + r1;
	y = y + r2;	
}

void MakhlukBurukRupa::dead(){
	/* \var void dead()
	\brief Berisi Jika Makhluk Mati prosedur
	*/
	cout <<"dead MakhlukBurukRupa" <<endl;
}
