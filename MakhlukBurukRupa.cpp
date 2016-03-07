#include "MakhlukBurukRupa.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

MakhlukBurukRupa::MakhlukBurukRupa(){
	/*! \var MakhlukMaling()
	\brief Constructor Kelas MakhlukMaling menginisialisasi atribut
	*/
	cout <<"ctor MakhlukBurukRupa" <<endl;
	age = 50;
	powerlevel = 100;
	deltaT = 10.0; 
}

MakhlukBurukRupa::MakhlukBurukRupa(int a,int b){
	/* ! \var MakhlukMaling(int a,int b)
	\brief Constructor Parameter Kelas MakhlukMaling
	\param a input posisi untuk x 
	\param b input posisi untuk y
	*/
	cout <<"ctor MakhlukBurukRupa" <<endl;
	age = 50;
	powerlevel = 100;
	deltaT = 10.0; 
	x = a;
	y = b;
}

MakhlukBurukRupa::MakhlukBurukRupa(const MakhlukBurukRupa& M){
	/* ! \var MakhlukMaling(const MakhlukMaling& M)
	\brief Copy constructor Kelas MakhlukMaling
	\param M Semua atribut MakhlukMaling akan diisi dengan atribut M yang juga merupakan MakhlukMaling
	*/
	cout <<"cctor MakhlukBurukRupa" <<endl;
	age = M.age ;
	powerlevel = M.powerlevel ;
	deltaT = M.deltaT ;
}

MakhlukBurukRupa::~MakhlukBurukRupa(){
	/* ! \var ~MakhlukMaling()
	\brief Destructor Kelas MakhlukMaling
	*/
	cout <<"dtor MakhlukBurukRupa" <<endl;
}

MakhlukBurukRupa& MakhlukBurukRupa::operator= (const MakhlukBurukRupa& M ){
	/* ! \var void spawn(int a,int b)
	\brief spawn mengisi nilai x dan y dimana nilai a dan b berasal dari petak yang di random
	\param a merupakan angka random dari kelas petak untuk x
	\param b merupakan angka random dari kelas petak untuk y
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
	/* ! \var void move()
	\brief Melakukan Perpindahan pada MakhlukMaling 
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
	/* ! \var void dead()
	\brief Prosedur berisi MakhlukMaling mati
	*/
	cout <<"dead MakhlukBurukRupa" <<endl;
}
